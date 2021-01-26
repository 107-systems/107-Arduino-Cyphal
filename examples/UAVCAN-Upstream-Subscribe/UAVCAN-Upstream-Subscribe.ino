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
void    onReceiveBufferFull    (CanardFrame const &);
void    onBMSStatus_1_0_Received(CanardTransfer const &, ArduinoUAVCAN &);
void    onSourceTs_0_1_Received(CanardTransfer const &, ArduinoUAVCAN &);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515(spi_select,
                       spi_deselect,
                       spi_transfer,
                       micros,
                       onReceiveBufferFull,
                       nullptr);

ArduinoUAVCAN uavcan(13, nullptr);

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
  mcp2515.setBitRate(CanBitRate::BR_500kBPS_8MHZ);
  mcp2515.setNormalMode();

  /* Header for data printed in callback */
  //Serial.println("Voltage, Current, Temp, SOC");
  Serial.println("Timestamp, Energy, Voltage");

  /* Subscribe to the reception of Heartbeat message. */
  //uavcan.subscribe<BMSStatus_1_0>(onBMSStatus_1_0_Received);
  uavcan.subscribe<SourceTs_0_1>(onSourceTs_0_1_Received);
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

void onReceiveBufferFull(CanardFrame const & frame)
{
  uavcan.onCanFrameReceived(frame);
}


void onSourceTs_0_1_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  SourceTs_0_1 const source = SourceTs_0_1::deserialize(transfer);

  // TODO: use this message formatting method: 
  /* char msg[64];
  snprintf(msg, 64,
           "ID %02X, Uptime = %d, Health = %d, Mode = %d, VSSC = %d",
           transfer.remote_node_id, hb.data.uptime, hb.data.health, hb.data.mode, hb.data.vendor_specific_status_code);
  */
  Serial.print((double)source.data.timestamp.microsecond);
  Serial.print("\t");
  Serial.print(source.data.value.energy.joule);
  Serial.print("\t");
  Serial.print(source.data.value.power.voltage.volt);
  /*Serial.print("\t");
  Serial.print(bms.data.state_of_charge);*/
  Serial.print("\n");

  // Serial.println(msg);
}
