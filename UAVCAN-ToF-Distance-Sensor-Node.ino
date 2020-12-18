/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/UAVCAN-ToF-Distance-Sensor-Node/graphs/contributors
 */

/* Recommended hardware setup:
 *  TMF8801Breakout <-> MKR Zero <-> MKR CAN Shield
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <SPI.h>

#include <ArduinoUAVCAN.h>
#include <ArduinoMCP2515.h>
#define DBG_ENABLE_ERROR
#define DBG_ENABLE_WARNING
#define DBG_ENABLE_INFO
#define DBG_ENABLE_DEBUG
//#define DBG_ENABLE_VERBOSE
#include <ArduinoDebug.hpp>

#undef max
#undef min
#include <algorithm>

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef struct
{
  Heartbeat_1_0::Mode mode;
} UavcanNodeData;

typedef struct
{
  uint32_t heartbeat_period_ms;
} UavcanNodeConfiguration;

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static int            const MKRCAN_MCP2515_CS_PIN    = 3;
static int            const MKRCAN_MCP2515_INT_PIN   = 7;
static uint8_t        const UAVCAN_NODE_ID           = 14;
static UavcanNodeData const UAVCAN_NODE_INITIAL_DATA =
{
  Heartbeat_1_0::Mode::INITIALIZATION,
};
static UavcanNodeConfiguration const UAVCAN_NODE_INITIAL_CONFIGURATION =
{
  1000,
};

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/
 
uint8_t spi_transfer(uint8_t const);

namespace MCP2515
{
void select();
void deselect();
void onExternalEvent();
void onReceive(CanardFrame const &);
bool transmit(CanardFrame const &);
}

namespace node
{
Heartbeat_1_0::Mode handle_INITIALIZATION();
Heartbeat_1_0::Mode handle_OPERATIONAL();
Heartbeat_1_0::Mode handle_MAINTENANCE();
Heartbeat_1_0::Mode handle_SOFTWARE_UPDATE();
}

namespace heartbeat
{
void publish(ArduinoUAVCAN &, uint32_t const, Heartbeat_1_0::Mode const);
}

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515(MCP2515::select,
                       MCP2515::deselect,
                       spi_transfer,
                       micros,
                       MCP2515::onReceive,
                       nullptr);

ArduinoUAVCAN uavcan(UAVCAN_NODE_ID, MCP2515::transmit);

UavcanNodeData node_data = UAVCAN_NODE_INITIAL_DATA;
UavcanNodeConfiguration node_config = UAVCAN_NODE_INITIAL_CONFIGURATION;

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
  attachInterrupt(digitalPinToInterrupt(MKRCAN_MCP2515_INT_PIN), MCP2515::onExternalEvent, FALLING);

  /* Configure MCP2515 */
  mcp2515.begin();
  mcp2515.setBitRate(CanBitRate::BR_250kBPS);
  mcp2515.setListenOnlyMode();
}

void loop()
{
  /* Handle actions common to all states.
   */
  unsigned long const now = millis();

  /* Publish the node heartbeat.
   */
  static unsigned long prev_heartbeat = 0;
  if ((now - prev_heartbeat) > node_config.heartbeat_period_ms) {
    heartbeat::publish(uavcan, now / 1000, node_data.mode);
    prev_heartbeat = now;
  }

  
  /* Handle state transitions and state specific action.
   */
  Heartbeat_1_0::Mode next_mode = node_data.mode;

  switch(node_data.mode)
  {
  case Heartbeat_1_0::Mode::INITIALIZATION:  next_mode = node::handle_INITIALIZATION();  break;
  case Heartbeat_1_0::Mode::OPERATIONAL:     next_mode = node::handle_OPERATIONAL();     break;
  case Heartbeat_1_0::Mode::MAINTENANCE:     next_mode = node::handle_MAINTENANCE();     break;
  case Heartbeat_1_0::Mode::SOFTWARE_UPDATE: next_mode = node::handle_SOFTWARE_UPDATE(); break;
  }

  node_data.mode = next_mode;

  /* Transmit all enqeued CAN frames */
  while(uavcan.transmitCanFrame()) { }
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

uint8_t spi_transfer(uint8_t const data)
{
  return SPI.transfer(data);
}

/**************************************************************************************
 * FUNCTION DEFINITION MCP2515
 **************************************************************************************/

namespace MCP2515
{

void select() {
  digitalWrite(MKRCAN_MCP2515_CS_PIN, LOW);
}

void deselect() {
  digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH);
}

void onExternalEvent() {
  mcp2515.onExternalEventHandler();
}

void onReceive(CanardFrame const & frame) {
  uavcan.onCanFrameReceived(frame);
}

bool transmit(CanardFrame const & frame) {
  return mcp2515.transmit(frame);
}

} /* MCP2515 */

/**************************************************************************************
 * FUNCTION DEFINITION node
 **************************************************************************************/

namespace node
{
  
Heartbeat_1_0::Mode handle_INITIALIZATION()
{
  DBG_VERBOSE("INITIALIZATION");

  return Heartbeat_1_0::Mode::OPERATIONAL;
}

Heartbeat_1_0::Mode handle_OPERATIONAL()
{
  DBG_VERBOSE("OPERATIONAL");

  return Heartbeat_1_0::Mode::OPERATIONAL;
}

Heartbeat_1_0::Mode handle_MAINTENANCE()
{
  DBG_VERBOSE("MAINTENANCE");

  return Heartbeat_1_0::Mode::INITIALIZATION;
}

Heartbeat_1_0::Mode handle_SOFTWARE_UPDATE()
{
  DBG_VERBOSE("SOFTWARE_UPDATE");

  return Heartbeat_1_0::Mode::INITIALIZATION;
}

} /* node */

namespace heartbeat
{

void publish(ArduinoUAVCAN & u, uint32_t const uptime, Heartbeat_1_0::Mode const mode)
{
  Heartbeat_1_0 hb;

  hb.data.uptime = uptime;
  hb = Heartbeat_1_0::Health::NOMINAL;
  hb = mode;
  hb.data.vendor_specific_status_code = 0;

  u.publish(hb);
}

} /* heartbeat */
