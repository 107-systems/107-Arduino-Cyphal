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
#include <Wire.h>

#include <ArduinoUAVCAN.h>
#include <ArduinoMCP2515.h>
#include <107-Arduino-TMF8801.h>
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
  uavcan::node::Heartbeat_1_0<>::Mode mode;
} UavcanNodeData;

#warning "Run 'TMF8801-FactoryCalib' once in order to obtain sensor calibration data for node configuration 'calib_data'"

typedef struct
{
  uint32_t heartbeat_period_ms;
  TMF8801::CalibData calib_data;
  TMF8801::AlgoState algo_state;
  uint8_t measurement_period_ms;
} UavcanNodeConfiguration;

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static int            const MKRCAN_MCP2515_CS_PIN    = 3;
static int            const MKRCAN_MCP2515_INT_PIN   = 7;
static uint8_t        const UAVCAN_NODE_ID           = 14;
static UavcanNodeData const UAVCAN_NODE_INITIAL_DATA =
{
  uavcan::node::Heartbeat_1_0<>::Mode::INITIALIZATION,
};
static UavcanNodeConfiguration const UAVCAN_NODE_INITIAL_CONFIGURATION =
{
  1000,
  {0x31, 0x9E, 0x0, 0xB6, 0x9, 0xE0, 0xFB, 0xF7, 0xF8, 0xF1, 0xE3, 0xC7, 0x7, 0xFC},
  {0xB1, 0xA9, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  100
};

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

uint8_t spi_transfer     (uint8_t const);
void    i2c_generic_write(uint8_t const i2c_slave_addr, uint8_t const reg_addr, uint8_t const * buf, uint8_t const num_bytes);
void    i2c_generic_read (uint8_t const i2c_slave_addr, uint8_t const reg_addr, uint8_t       * buf, uint8_t const num_bytes);

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
uavcan::node::Heartbeat_1_0<>::Mode handle_INITIALIZATION();
uavcan::node::Heartbeat_1_0<>::Mode handle_OPERATIONAL();
uavcan::node::Heartbeat_1_0<>::Mode handle_MAINTENANCE();
uavcan::node::Heartbeat_1_0<>::Mode handle_SOFTWARE_UPDATE();
}

namespace heartbeat
{
void publish(ArduinoUAVCAN &, uint32_t const, uavcan::node::Heartbeat_1_0<>::Mode const);
}

namespace tof
{
void onTofDistanceUpdate(drone::unit::Length const l);
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

ArduinoUAVCAN uavcan_hdl(UAVCAN_NODE_ID, MCP2515::transmit);

UavcanNodeData node_data = UAVCAN_NODE_INITIAL_DATA;
UavcanNodeConfiguration node_config = UAVCAN_NODE_INITIAL_CONFIGURATION;

drone::ArduinoTMF8801 tmf8801(i2c_generic_write,
                              i2c_generic_read,
                              delay,
                              TMF8801::DEFAULT_I2C_ADDR,
                              node_config.calib_data,
                              node_config.algo_state,
                              tof::onTofDistanceUpdate);

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

  /* I2C to which the TMF8801 is connected.
   */
  Wire.begin();

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

  /* Configure MCP2515
   */
  mcp2515.begin();
  mcp2515.setBitRate(CanBitRate::BR_250kBPS_16MHZ);
  mcp2515.setListenOnlyMode();

  /* Configure TMF8801
   */
  if (!tmf8801.begin(node_config.measurement_period_ms)) {
    DBG_ERROR("ArduinoTMF8801::begin(...) failed, error code %d", (int)tmf8801.error());
    for(;;) { }
  }

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
    heartbeat::publish(uavcan_hdl, now / 1000, node_data.mode);
    prev_heartbeat = now;
  }


  /* Handle state transitions and state specific action.
   */
  uavcan::node::Heartbeat_1_0<>::Mode next_mode = node_data.mode;

  switch(node_data.mode)
  {
  case uavcan::node::Heartbeat_1_0<>::Mode::INITIALIZATION:  next_mode = node::handle_INITIALIZATION();  break;
  case uavcan::node::Heartbeat_1_0<>::Mode::OPERATIONAL:     next_mode = node::handle_OPERATIONAL();     break;
  case uavcan::node::Heartbeat_1_0<>::Mode::MAINTENANCE:     next_mode = node::handle_MAINTENANCE();     break;
  case uavcan::node::Heartbeat_1_0<>::Mode::SOFTWARE_UPDATE: next_mode = node::handle_SOFTWARE_UPDATE(); break;
  }

  node_data.mode = next_mode;

  /* Transmit all enqeued CAN frames */
  while(uavcan_hdl.transmitCanFrame()) { }
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

uint8_t spi_transfer(uint8_t const data)
{
  return SPI.transfer(data);
}


void i2c_generic_write(uint8_t const i2c_slave_addr, uint8_t const reg_addr, uint8_t const * buf, uint8_t const num_bytes)
{
  Wire.beginTransmission(i2c_slave_addr);
  Wire.write(reg_addr);
  for(uint8_t bytes_written = 0; bytes_written < num_bytes; bytes_written++) {
    Wire.write(buf[bytes_written]);
  }
  Wire.endTransmission();
}

void i2c_generic_read(uint8_t const i2c_slave_addr, uint8_t const reg_addr, uint8_t * buf, uint8_t const num_bytes)
{
  Wire.beginTransmission(i2c_slave_addr);
  Wire.write(reg_addr);
  Wire.endTransmission();

  Wire.requestFrom(i2c_slave_addr, num_bytes);
  for(uint8_t bytes_read = 0; (bytes_read < num_bytes) && Wire.available(); bytes_read++) {
    buf[bytes_read] = Wire.read();
  }
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
  uavcan_hdl.onCanFrameReceived(frame);
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

uavcan::node::Heartbeat_1_0<>::Mode handle_INITIALIZATION()
{
  DBG_VERBOSE("INITIALIZATION");

  return uavcan::node::Heartbeat_1_0<>::Mode::OPERATIONAL;
}

uavcan::node::Heartbeat_1_0<>::Mode handle_OPERATIONAL()
{
  DBG_VERBOSE("OPERATIONAL");

  return uavcan::node::Heartbeat_1_0<>::Mode::OPERATIONAL;
}

uavcan::node::Heartbeat_1_0<>::Mode handle_MAINTENANCE()
{
  DBG_VERBOSE("MAINTENANCE");

  return uavcan::node::Heartbeat_1_0<>::Mode::INITIALIZATION;
}

uavcan::node::Heartbeat_1_0<>::Mode handle_SOFTWARE_UPDATE()
{
  DBG_VERBOSE("SOFTWARE_UPDATE");

  return uavcan::node::Heartbeat_1_0<>::Mode::INITIALIZATION;
}

} /* node */

namespace heartbeat
{

void publish(ArduinoUAVCAN & u, uint32_t const uptime, uavcan::node::Heartbeat_1_0<>::Mode const mode)
{
  uavcan::node::Heartbeat_1_0<> hb;

  hb.data.uptime = uptime;
  hb = uavcan::node::Heartbeat_1_0<>::Health::NOMINAL;
  hb = mode;
  hb.data.vendor_specific_status_code = 0;

  u.publish(hb);
}

} /* heartbeat */

namespace tof
{

void onTofDistanceUpdate(drone::unit::Length const l)
{
  DBG_INFO("[%05lu] Distance = %.3f m", millis(), l.value());
}

}
