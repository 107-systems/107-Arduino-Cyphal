/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
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
  Heartbeat_1_0<>::Mode mode;
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

void publish_heartbeat(uint32_t const, Heartbeat_1_0<>::Mode const);
void publish_tofDistance(drone::unit::Length const l);

Heartbeat_1_0<>::Mode handle_INITIALIZATION();
Heartbeat_1_0<>::Mode handle_OPERATIONAL();
Heartbeat_1_0<>::Mode handle_MAINTENANCE();
Heartbeat_1_0<>::Mode handle_SOFTWARE_UPDATE();

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static int          const MKRCAN_MCP2515_CS_PIN  = 3;
static int          const TMF8801_INT_PIN        = 6;
static int          const MKRCAN_MCP2515_INT_PIN = 7;
static SPISettings  const MCP2515x_SPI_SETTING{10000000, MSBFIRST, SPI_MODE0};

static CanardNodeID const OPEN_CYPHAL_NODE_ID = 42;
static CanardPortID const OPEN_CYPHAL_ID_DISTANCE_DATA = 1001U;

static OpenCyphalNodeData const OPEN_CYPHAL_NODE_INITIAL_DATA =
{
  Heartbeat_1_0<>::Mode::INITIALIZATION,
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

CyphalHeap<Node::DEFAULT_O1HEAP_SIZE> node_heap;
Node node_hdl(node_heap.data(), node_heap.size(), OPEN_CYPHAL_NODE_ID);
Publisher heartbeat_pub = node_hdl.create_publisher(Heartbeat_1_0<>::PORT_ID);
Publisher tof_pub = node_hdl.create_publisher(OPEN_CYPHAL_ID_DISTANCE_DATA);

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

static RegisterNatural8  reg_rw_uavcan_node_id          ("uavcan.node.id",           Register::Access::ReadWrite, Register::Persistent::No, OPEN_CYPHAL_NODE_ID, [&node_hdl](uint8_t const & val) { node_hdl.setNodeId(val); });
static RegisterString    reg_ro_uavcan_node_description ("uavcan.node.description",  Register::Access::ReadWrite, Register::Persistent::No, "OpenCyphal-ToF-Distance-Sensor-Node");
static RegisterNatural16 reg_ro_uavcan_pub_distance_id  ("uavcan.pub.distance.id",   Register::Access::ReadOnly,  Register::Persistent::No, OPEN_CYPHAL_ID_DISTANCE_DATA);
static RegisterString    reg_ro_uavcan_pub_distance_type("uavcan.pub.distance.type", Register::Access::ReadOnly,  Register::Persistent::No, "uavcan.primitive.scalar.Real32.1.0");
static RegisterList      reg_list;

/* NODE INFO **************************************************************************/

static NodeInfo node_info
(
  /* uavcan.node.Version.1.0 protocol_version */
  1, 0,
  /* uavcan.node.Version.1.0 hardware_version */
  1, 0,
  /* uavcan.node.Version.1.0 software_version */
  0, 1,
  /* saturated uint64 software_vcs_revision_id */
  NULL,
  /* saturated uint8[16] unique_id */
  OpenCyphalUniqueId(),
  /* saturated uint8[<=50] name */
  "107-systems.tof-sensor-node"
);

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  /* USB serial for debug messages.
   */
  Serial.begin(115200);
  while(!Serial) { }

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

  /* Register callbacks for node info and register api.
   */
  node_info.subscribe(node_hdl);

  reg_list.add(reg_rw_uavcan_node_id);
  reg_list.add(reg_ro_uavcan_node_description);
  reg_list.add(reg_ro_uavcan_pub_distance_id);
  reg_list.add(reg_ro_uavcan_pub_distance_type);
  reg_list.subscribe(node_hdl);
}

void loop()
{
  /* Process all pending OpenCyphal actions.
   */
  node_hdl.spinSome([] (CanardFrame const & frame) { return mcp2515.transmit(frame); });

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
  Heartbeat_1_0<>::Mode next_mode = node_data.mode;

  switch(node_data.mode)
  {
  case Heartbeat_1_0<>::Mode::INITIALIZATION:  next_mode = handle_INITIALIZATION();  break;
  case Heartbeat_1_0<>::Mode::OPERATIONAL:     next_mode = handle_OPERATIONAL();     break;
  case Heartbeat_1_0<>::Mode::MAINTENANCE:     next_mode = handle_MAINTENANCE();     break;
  case Heartbeat_1_0<>::Mode::SOFTWARE_UPDATE: next_mode = handle_SOFTWARE_UPDATE(); break;
  }

  node_data.mode = next_mode;
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void mcp2515_onReceiveBufferFull(CanardFrame const & frame)
{
  node_hdl.onCanFrameReceived(frame, micros());
}

void publish_heartbeat(uint32_t const uptime, Heartbeat_1_0<>::Mode const mode)
{
  Heartbeat_1_0<> hb_msg;

  hb_msg.data.uptime = uptime;
  hb_msg = Heartbeat_1_0<>::Health::NOMINAL;
  hb_msg = mode;
  hb_msg.data.vendor_specific_status_code = 0;

  heartbeat_pub.publish(hb_msg);
}

void publish_tofDistance(drone::unit::Length const l)
{
  DBG_INFO("[%05lu] Distance = %.3f m", millis(), l.value());

  typedef uavcan::primitive::scalar::Real32_1_0<OPEN_CYPHAL_ID_DISTANCE_DATA> DistanceMessageType;
  DistanceMessageType tof_distance_msg;
  tof_distance_msg.data.value = l.value();

  tof_pub.publish(tof_distance_msg);
}

Heartbeat_1_0<>::Mode handle_INITIALIZATION()
{
  DBG_VERBOSE("INITIALIZATION");

  return Heartbeat_1_0<>::Mode::OPERATIONAL;
}

Heartbeat_1_0<>::Mode handle_OPERATIONAL()
{
  DBG_VERBOSE("OPERATIONAL");

  return Heartbeat_1_0<>::Mode::OPERATIONAL;
}

Heartbeat_1_0<>::Mode handle_MAINTENANCE()
{
  DBG_VERBOSE("MAINTENANCE");

  return Heartbeat_1_0<>::Mode::INITIALIZATION;
}

Heartbeat_1_0<>::Mode handle_SOFTWARE_UPDATE()
{
  DBG_VERBOSE("SOFTWARE_UPDATE");

  return Heartbeat_1_0<>::Mode::INITIALIZATION;
}
