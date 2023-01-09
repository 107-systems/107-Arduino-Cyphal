/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/* Recommended hardware setup:
 *  MKR Zero <-> MKR CAN Shield <-> MKR GPS Shield
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <SPI.h>

#include <107-Arduino-Cyphal.h>
#include <107-Arduino-MCP2515.h>
#include <107-Arduino-CriticalSection.h>
#include <ArduinoNmeaParser.h>
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
 * TYPEDEF
 **************************************************************************************/

typedef struct
{
  uavcan_node_Mode_1_0 mode;
} OpenCyphalNodeData;

typedef struct
{
  uint32_t heartbeat_period_ms;
} OpenCyphalNodeConfiguration;

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static int const MKRCAN_MCP2515_CS_PIN  = 3;
static int const MKRCAN_MCP2515_INT_PIN = 7;

static OpenCyphalNodeData const OPEN_CYPHAL_NODE_INITIAL_DATA =
{
  uavcan_node_Mode_1_0_INITIALIZATION,
};

static OpenCyphalNodeConfiguration const OPEN_CYPHAL_NODE_INITIAL_CONFIGURATION =
{
  1000,
};

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

namespace MCP2515
{
void onReceive(CanardFrame const &);
}

namespace node
{
uint8_t handle_INITIALIZATION();
uint8_t handle_OPERATIONAL();
uint8_t handle_MAINTENANCE();
uint8_t handle_SOFTWARE_UPDATE();
}

namespace heartbeat
{
void publish(uint32_t const, uavcan_node_Mode_1_0 const);
}

namespace gnss
{
void onRmcUpdate(nmea::RmcData const);
void onGgaUpdate(nmea::GgaData const);
}

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515([]() { digitalWrite(MKRCAN_MCP2515_CS_PIN, LOW); },
                       []() { digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH); },
                       [](uint8_t const data) { return SPI.transfer(data); },
                       micros,
                       MCP2515::onReceive,
                       nullptr);

Node::Heap<Node::DEFAULT_O1HEAP_SIZE> node_heap;
CircularBuffer<Node::TReceiveCircularBuffer>::Heap<Node::DEFAULT_RX_QUEUE_SIZE> node_rx_queue;
Node node_hdl(node_heap.data(), node_heap.size(), node_rx_queue.data(), node_rx_queue.size(), micros);

Publisher<uavcan::node::Heartbeat_1_0<>> heartbeat_pub = node_hdl.create_publisher<uavcan::node::Heartbeat_1_0<>>(uavcan::node::Heartbeat_1_0<>::PORT_ID, 1*1000*1000UL /* = 1 sec in usecs. */);

ArduinoNmeaParser nmea_parser(gnss::onRmcUpdate, gnss::onGgaUpdate);

OpenCyphalNodeData node_data = OPEN_CYPHAL_NODE_INITIAL_DATA;
OpenCyphalNodeConfiguration node_config = OPEN_CYPHAL_NODE_INITIAL_CONFIGURATION;

DEBUG_INSTANCE(120, Serial);

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  /* USB serial for debug messages.
   */
  Serial.begin(115200);
  while(!Serial) { }

  /* Serial connected to MKR GPS board.
   */
  Serial1.begin(9600);

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

  /* Configure MCP2515 */
  mcp2515.begin();
  mcp2515.setBitRate(CanBitRate::BR_250kBPS_16MHZ);
  mcp2515.setListenOnlyMode();
}

void loop()
{
  /* Process all pending OpenCyphal actions.
   */
  {
    CriticalSection crit_sec;
    node_hdl.spinSome([] (CanardFrame const & frame) { return mcp2515.transmit(frame); });
  }

  /* Handle actions common to all states.
   */
  unsigned long const now = millis();

  /* Publish the node heartbeat.
   */
  static unsigned long prev_heartbeat = 0;
  if ((now - prev_heartbeat) > node_config.heartbeat_period_ms) {
    heartbeat::publish(now / 1000, node_data.mode);
    prev_heartbeat = now;
  }


  /* Handle state transitions and state specific action.
   */
  uavcan_node_Mode_1_0 next_mode = node_data.mode;

  switch(node_data.mode.value)
  {
  case uavcan_node_Mode_1_0_INITIALIZATION:  next_mode.value = node::handle_INITIALIZATION();  break;
  case uavcan_node_Mode_1_0_OPERATIONAL:     next_mode.value = node::handle_OPERATIONAL();     break;
  case uavcan_node_Mode_1_0_MAINTENANCE:     next_mode.value = node::handle_MAINTENANCE();     break;
  case uavcan_node_Mode_1_0_SOFTWARE_UPDATE: next_mode.value = node::handle_SOFTWARE_UPDATE(); break;
  }

  node_data.mode = next_mode;
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

namespace MCP2515
{

void onReceive(CanardFrame const & frame) {
  node_hdl.onCanFrameReceived(frame);
}

} /* MCP2515 */

namespace node
{

uint8_t handle_INITIALIZATION()
{
  DBG_VERBOSE("INITIALIZATION");

  return uavcan_node_Mode_1_0_OPERATIONAL;
}

uint8_t handle_OPERATIONAL()
{
  DBG_VERBOSE("OPERATIONAL");

  /* Parse incoming NMEA messages from the
   * MKG GPS module.
   */
  while (Serial1.available())
  {
    nmea_parser.encode((char)Serial1.read());
  }

  return uavcan_node_Mode_1_0_OPERATIONAL;
}

uint8_t handle_MAINTENANCE()
{
  DBG_VERBOSE("MAINTENANCE");

  return uavcan_node_Mode_1_0_INITIALIZATION;
}

uint8_t handle_SOFTWARE_UPDATE()
{
  DBG_VERBOSE("SOFTWARE_UPDATE");

  return uavcan_node_Mode_1_0_INITIALIZATION;
}

} /* node */

namespace heartbeat
{

void publish(uint32_t const uptime, uavcan_node_Mode_1_0 const mode)
{
  uavcan::node::Heartbeat_1_0<> hb_msg;

  hb_msg.data.uptime = uptime;
  hb_msg.data.health.value = uavcan_node_Health_1_0_NOMINAL;
  hb_msg.data.mode.value = mode.value;
  hb_msg.data.vendor_specific_status_code = 0;

  heartbeat_pub->publish(hb_msg);
}

} /* heartbeat */

namespace gnss
{

void onRmcUpdate(nmea::RmcData const rmc)
{
  DBG_DEBUG("RMC: %d:%d:%d.%d : LON %.4f° | LAT %.4f° | %.1f m/s | %.1f°", rmc.time_utc.hour, rmc.time_utc.minute, rmc.time_utc.second, rmc.time_utc.microsecond, rmc.longitude, rmc.latitude, rmc.speed, rmc.course);
}

void onGgaUpdate(nmea::GgaData const gga)
{
  DBG_DEBUG("GGA: %d:%d:%d.%d : LON %.4f° | LAT %.4f° | Num. Sat. %d | HDOP = %.1f m | Altitude %.1f m | Geoidal Separation %.1f m", gga.time_utc.hour, gga.time_utc.minute, gga.time_utc.second, gga.time_utc.microsecond, gga.longitude, gga.latitude, gga.num_satellites, gga.hdop, gga.altitude, gga.geoidal_separation);
}

} /* gnss */
