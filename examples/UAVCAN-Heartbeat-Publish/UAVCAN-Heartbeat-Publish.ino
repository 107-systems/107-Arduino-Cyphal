/*
 * This example shows periodic tranmission of a UAVCAN heartbeat message via CAN.
 * 
 * Hardware:
 *   - Arduino MKR family board, e.g. MKR VIDOR 4000
 *   - Arduino MKR CAN shield
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <SPI.h>

#include <ArduinoUAVCAN.h>
#include <ArduinoMCP2515.h>

#include <types/uavcan/node/Heartbeat.1.0.h>

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static int const MKRCAN_MCP2515_CS_PIN  = 3;
static int const MKRCAN_MCP2515_INT_PIN = 7;

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

void    spi_select      ();
void    spi_deselect    ();
uint8_t spi_transfer    (uint8_t const);
void    onExternalEvent ();
bool    transmitCanFrame(uint32_t const, uint8_t const *, uint8_t const);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515(spi_select,
                       spi_deselect,
                       spi_transfer,
                       nullptr,
                       nullptr);

ArduinoUAVCAN uavcan(13, micros, transmitCanFrame);

Heartbeat_1_0 hb(0, Heartbeat_1_0::Health::NOMINAL, Heartbeat_1_0::Mode::INITIALIZATION, 0);

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(9600);
  while(!Serial) { }

  /* Setup SPI access */
  SPI.begin();
  pinMode(MKRCAN_MCP2515_CS_PIN, OUTPUT);
  digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH);

  /* Attach interrupt handler to register MCP2515 signaled by taking INT low */
  pinMode(MKRCAN_MCP2515_INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(MKRCAN_MCP2515_INT_PIN), onExternalEvent, FALLING);

  /* Initialize MCP2515 */
  mcp2515.begin();
  mcp2515.setBitRate(CanBitRate::BR_250kBPS);
  mcp2515.setNormalMode();
}

void loop()
{
  /* Update the heartbeat object */
  hb.uptime(millis() / 1000);
  hb.mode(Heartbeat_1_0::Mode::OPERATIONAL);

  /* Publish the heartbeat once/second */
  static unsigned long prev = 0;
  unsigned long const now = millis();
  if(now - prev > 1000) {
    hb.publish(uavcan);
    prev = now;
  }

  /* Transmit all enqeued CAN frames */
  while(uavcan.transmitCanFrame()) { }
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void spi_select()
{
  digitalWrite(MKRCAN_MCP2515_CS_PIN, LOW);
}

void spi_deselect()
{
  digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH);
}

uint8_t spi_transfer(uint8_t const data)
{
  return SPI.transfer(data);
}

void onExternalEvent()
{
  mcp2515.onExternalEventHandler();
}

bool transmitCanFrame(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  return mcp2515.transmit(id, data, len);
}
