/*
 * This example shows reception of a UAVCAN heartbeat message via CAN.
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

void    spi_select             ();
void    spi_deselect           ();
uint8_t spi_transfer           (uint8_t const);
void    onExternalEvent        ();
void    onReceiveBufferFull    (uint32_t const, uint8_t const *, uint8_t const);
void    onTransmitBufferEmpty  (ArduinoMCP2515 *);
bool    transmitCanFrame       (uint32_t const id, uint8_t const * data, uint8_t const len);
void    onHeatbeat_1_0_Received(CanardTransfer const & transfer);

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef struct
{
  uint32_t id;
  uint8_t  data[8];
  uint8_t  len;
} sCanTestFrame;

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515(spi_select,
                       spi_deselect,
                       spi_transfer,
                       onReceiveBufferFull,
                       onTransmitBufferEmpty);

ArduinoUAVCAN uavcan(13, micros, transmitCanFrame);

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

  /* Subscribe to the reception of Heartbeat message. */
  uavcan.subscribe(Heartbeat_1_0::PORT_ID, Heartbeat_1_0::PAYLOAD_SIZE, onHeatbeat_1_0_Received);
}

void loop()
{

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

void onReceiveBufferFull(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  uavcan.onCanFrameReceived(id, data, len);
}

void onTransmitBufferEmpty(ArduinoMCP2515 * this_ptr)
{
  /* One could use this to load the next frame from a CAN transmit ringbuffer into the MCP2515 CAN controller for transmission */
}

bool transmitCanFrame(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  return mcp2515.transmit(id, data, len);
}

void onHeatbeat_1_0_Received(CanardTransfer const & transfer)
{
  Heartbeat_1_0 const hb = Heartbeat_1_0::create(transfer);

  char msg[64];
  snprintf(msg, 64,
           "ID %02X, Uptime = %d, Health = %d, Mode = %d, VSSC = %d",
           transfer.remote_node_id, hb.uptime(), (int)hb.health(), (int)hb.mode(), hb.vssc());

  Serial.println(msg);
}
