/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/* Recommended hardware setup:
 *  TMF8801Breakout <-> MKR Zero <-> MKR CAN Shield
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <SPI.h>
#include <Wire.h>

#include <107-Arduino-Cyphal.h>
#include <107-Arduino-MCP2515.h>
#include <107-Arduino-TMF8801.h>
#include <107-Arduino-UniqueId.h>
#include <107-Arduino-CriticalSection.h>
#define DBG_ENABLE_ERROR
#define DBG_ENABLE_WARNING
#define DBG_ENABLE_INFO
#define DBG_ENABLE_DEBUG
//#define DBG_ENABLE_VERBOSE
#include <107-Arduino-Debug.hpp>

#undef max
#undef min
#include <algorithm>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

using namespace uavcan::node;
using namespace uavcan::_register;

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef struct
{
  uavcan::node::Mode_1_0 mode;
} OpenCyphalNodeData;

#warning "Run 'TMF8801-FactoryCalib' once in order to obtain sensor calibration data for node configuration 'calib_data'"

typedef struct
{
  uint32_t heartbeat_period_ms;
  TMF8801::CalibData calib_data;
  TMF8801::AlgoState algo_state;
  uint8_t measurement_period_ms;
} OpenCyphalNodeConfiguration;

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

void mcp2515_onReceiveBufferFull(CanardFrame const &);
void onGetInfo_1_0_Request_Received(CanardRxTransfer const &, Node &);

void publish_heartbeat(uint32_t const, uavcan::node::Mode_1_0 const mode);
void publish_tofDistance(drone::unit::Length const l);

uint8_t handle_INITIALIZATION();
uint8_t handle_OPERATIONAL();
uint8_t handle_MAINTENANCE();
uint8_t handle_SOFTWARE_UPDATE();

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static int          const MKRCAN_MCP2515_CS_PIN  = 3;
static int          const TMF8801_INT_PIN        = 6;
static int          const MKRCAN_MCP2515_INT_PIN = 7;
static SPISettings  const MCP2515x_SPI_SETTING{10000000, MSBFIRST, SPI_MODE0};

static CanardNodeID const DEFAULT_OPEN_CYPHAL_NODE_ID = 42;
static CanardPortID const DEFAULT_OPEN_CYPHAL_ID_DISTANCE_DATA = 1001U;

typedef uavcan::primitive::scalar::Real32_1_0 DistanceMessageType;

static OpenCyphalNodeData const OPEN_CYPHAL_NODE_INITIAL_DATA =
{
  uavcan::node::Mode_1_0::INITIALIZATION,
};
static OpenCyphalNodeConfiguration const OPEN_CYPHAL_NODE_INITIAL_CONFIGURATION =
{
  1000,
  {0x31, 0x9E, 0x0, 0xB6, 0x9, 0xE0, 0xFB, 0xF7, 0xF8, 0xF1, 0xE3, 0xC7, 0x7, 0xFC},
  {0xB1, 0xA9, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  100
};

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

/* DRIVER *****************************************************************************/

ArduinoMCP2515 mcp2515([]()
                       {
                         noInterrupts();
                         SPI.beginTransaction(MCP2515x_SPI_SETTING);
                         digitalWrite(MKRCAN_MCP2515_CS_PIN, LOW);
                       },
                       []()
                       {
                         digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH);
                         SPI.endTransaction();
                         interrupts();
                       },
                       [](uint8_t const d) { return SPI.transfer(d); },
                       micros,
                       mcp2515_onReceiveBufferFull,
                       nullptr);

Node::Heap<Node::DEFAULT_O1HEAP_SIZE> node_heap;
Node node_hdl(node_heap.data(), node_heap.size(), micros, [] (CanardFrame const & frame) { return mcp2515.transmit(frame); });

Publisher<Heartbeat_1_0> heartbeat_pub = node_hdl.create_publisher<Heartbeat_1_0>
  (Heartbeat_1_0::_traits_::FixedPortId, 1*1000*1000UL /* = 1 sec in usecs. */);
Publisher<DistanceMessageType> tof_pub = node_hdl.create_publisher<DistanceMessageType>
  (DEFAULT_OPEN_CYPHAL_ID_DISTANCE_DATA, 1*1000*1000UL /* = 1 sec in usecs. */);

OpenCyphalNodeData node_data = OPEN_CYPHAL_NODE_INITIAL_DATA;
OpenCyphalNodeConfiguration node_config = OPEN_CYPHAL_NODE_INITIAL_CONFIGURATION;

drone::ArduinoTMF8801 tmf8801([](uint8_t const i2c_slave_addr, uint8_t const reg_addr, uint8_t const * buf, uint8_t const num_bytes)
                              {
                                Wire.beginTransmission(i2c_slave_addr);
                                Wire.write(reg_addr);
                                for(uint8_t bytes_written = 0; bytes_written < num_bytes; bytes_written++) {
                                  Wire.write(buf[bytes_written]);
                                }
                                Wire.endTransmission();
                              },
                              [](uint8_t const i2c_slave_addr, uint8_t const reg_addr, uint8_t * buf, uint8_t const num_bytes)
                              {
                                Wire.beginTransmission(i2c_slave_addr);
                                Wire.write(reg_addr);
                                Wire.endTransmission();

                                Wire.requestFrom(i2c_slave_addr, num_bytes);
                                for(uint8_t bytes_read = 0; (bytes_read < num_bytes) && Wire.available(); bytes_read++) {
                                  buf[bytes_read] = Wire.read();
                                }
                              },
                              delay,
                              TMF8801::DEFAULT_I2C_ADDR,
                              node_config.calib_data,
                              node_config.algo_state,
                              publish_tofDistance);

DEBUG_INSTANCE(120, Serial);

/* REGISTER ***************************************************************************/

static CanardNodeID node_id = DEFAULT_OPEN_CYPHAL_NODE_ID;
static CanardPortID distance_data_port_id = DEFAULT_OPEN_CYPHAL_ID_DISTANCE_DATA;

#if __GNUC__ >= 11

const auto node_registry = node_hdl.create_registry();

const auto reg_rw_cyphal_node_id           = node_registry->expose("cyphal.node.id", {}, node_id);
const auto reg_ro_cyphal_node_description  = node_registry->route ("cyphal.node.description", {true}, []() { return "OpenCyphal-ToF-Distance-Sensor-Node"; });
const auto reg_rw_cyphal_pub_distance_id   = node_registry->expose("cyphal.pub.distance.id", {true}, distance_data_port_id);
const auto reg_ro_cyphal_pub_distance_type = node_registry->route ("cyphal.pub.distance.type", {true}, []() { return "cyphal.primitive.scalar.Real32.1.0"; });

#endif /* __GNUC__ >= 11 */

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  /* USB serial for debug messages.
   */
  Serial.begin(115200);
  while(!Serial) { }

  /* NODE INFO ************************************************************************/
  static auto node_info = node_hdl.create_node_info
  (
    /* uavcan.node.Version.1.0 protocol_version */
    1, 0,
    /* uavcan.node.Version.1.0 hardware_version */
    1, 0,
    /* uavcan.node.Version.1.0 software_version */
    0, 1,
    /* saturated uint64 software_vcs_revision_id */
#ifdef CYPHAL_NODE_INFO_GIT_VERSION
    CYPHAL_NODE_INFO_GIT_VERSION,
#else
    0,
#endif
    /* saturated uint8[16] unique_id */
    OpenCyphalUniqueId(),
    /* saturated uint8[<=50] name */
    "107-systems.tof-sensor-node"
  );

  /* I2C to which the TMF8801 is connected.
   */
  Wire.begin();

  /* Attach interrupt handler to obtain events
   * signalled by the TMF8801.
   */
  pinMode(TMF8801_INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(TMF8801_INT_PIN), [](){ tmf8801.onExternalEventHandler(); }, FALLING);

  /* Setup SPI access
   */
  SPI.begin();
  pinMode(MKRCAN_MCP2515_CS_PIN, OUTPUT);
  digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH);

  /* Attach interrupt handler to register
   * MCP2515 signaled by taking INT low.
   */
  pinMode(MKRCAN_MCP2515_INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(MKRCAN_MCP2515_INT_PIN), []() { mcp2515.onExternalEventHandler(); }, LOW);

  /* Configure MCP2515
   */
  mcp2515.begin();
  mcp2515.setBitRate(CanBitRate::BR_250kBPS_16MHZ);
  mcp2515.setNormalMode();

  /* Configure TMF8801
   */
  if (!tmf8801.begin(node_config.measurement_period_ms)) {
    DBG_ERROR("ArduinoTMF8801::begin(...) failed, error code %d", (int)tmf8801.error());
    for(;;) { }
  }
}

void loop()
{
  /* Process all pending OpenCyphal actions.
   */
  {
    CriticalSection crit_sec;
    node_hdl.spinSome();
  }

  /* Handle actions common to all states.
   */
  unsigned long const now = millis();

  /* Publish the node heartbeat.
   */
  static unsigned long prev_heartbeat = 0;
  if ((now - prev_heartbeat) > node_config.heartbeat_period_ms) {
    publish_heartbeat(now / 1000, node_data.mode);
    prev_heartbeat = now;
  }


  /* Handle state transitions and state specific action.
   */
  uavcan::node::Mode_1_0 next_mode = node_data.mode;

  switch(node_data.mode.value)
  {
    case uavcan::node::Mode_1_0::INITIALIZATION:  next_mode.value = handle_INITIALIZATION();  break;
    case uavcan::node::Mode_1_0::OPERATIONAL:     next_mode.value = handle_OPERATIONAL();     break;
    case uavcan::node::Mode_1_0::MAINTENANCE:     next_mode.value = handle_MAINTENANCE();     break;
    case uavcan::node::Mode_1_0::SOFTWARE_UPDATE: next_mode.value = handle_SOFTWARE_UPDATE(); break;
  }

  node_data.mode = next_mode;
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void mcp2515_onReceiveBufferFull(CanardFrame const & frame)
{
  node_hdl.onCanFrameReceived(frame);
}

void publish_heartbeat(uint32_t const uptime, uavcan::node::Mode_1_0 const mode)
{
  Heartbeat_1_0 msg;

  msg.uptime = uptime;
  msg.health.value = uavcan::node::Health_1_0::NOMINAL;
  msg.mode = mode;
  msg.vendor_specific_status_code = 0;

  heartbeat_pub->publish(msg);
}

void publish_tofDistance(drone::unit::Length const l)
{
  DBG_INFO("[%05lu] Distance = %.3f m", millis(), l.value());

  DistanceMessageType tof_distance_msg;
  tof_distance_msg.value = l.value();

  tof_pub->publish(tof_distance_msg);
}

uint8_t handle_INITIALIZATION()
{
  DBG_VERBOSE("INITIALIZATION");

  return uavcan::node::Mode_1_0::OPERATIONAL;
}

uint8_t handle_OPERATIONAL()
{
  DBG_VERBOSE("OPERATIONAL");

  return uavcan::node::Mode_1_0::OPERATIONAL;
}

uint8_t handle_MAINTENANCE()
{
  DBG_VERBOSE("MAINTENANCE");

  return uavcan::node::Mode_1_0::INITIALIZATION;
}

uint8_t handle_SOFTWARE_UPDATE()
{
  DBG_VERBOSE("SOFTWARE_UPDATE");

  return uavcan::node::Mode_1_0::INITIALIZATION;
}
