/*
 * This example creates a UAVCAN node. The builtin LED can be switched on and off using UAVCAN.
 * It also shows periodic transmission of a UAVCAN heartbeat message via CAN.
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

void    spi_select      ();
void    spi_deselect    ();
uint8_t spi_transfer    (uint8_t const);
void    onExternalEvent ();
bool    transmitCanFrame(CanardFrame const &);
void    onReceiveBufferFull    (CanardFrame const &);
void    onBit_1_0_Received(CanardTransfer const &, ArduinoUAVCAN &);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515(spi_select,
                       spi_deselect,
                       spi_transfer,
                       micros,
                       onReceiveBufferFull,
                       nullptr);

ArduinoUAVCAN uavcan(13, transmitCanFrame);

Bit_1_0 uavcan_led_out;
Real32_1_0 r32;
Heartbeat_1_0 hb;

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(9600);
  while(!Serial) { }

  /* Setup LED*/
  pinMode(LED_BUILTIN, OUTPUT);

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

  /* Configure initial real32 */
  r32.data = 1.23;

  /* Configure initial uavcan_led_out */
  uavcan_led_out.data = true;

  /* Configure initial heartbeat */
  hb.data.uptime = 0;
  hb = Heartbeat_1_0::Health::NOMINAL;
  hb = Heartbeat_1_0::Mode::INITIALIZATION;
  hb.data.vendor_specific_status_code = 0;

  /* Subscribe to the reception of Bit message. */
  uavcan.subscribe<Bit_1_0>(onBit_1_0_Received);
  Serial.println("init finished");
}

void loop()
{
  /* Update the heartbeat object */
  hb.data.uptime = millis() / 1000;
  hb = Heartbeat_1_0::Mode::OPERATIONAL;

  /* Publish the heartbeat once/second */
  static unsigned long prev = 0;
  unsigned long const now = millis();
  if(now - prev > 1000) {
    uavcan.publish(hb);
    uavcan.publish(r32);
    uavcan.publish(uavcan_led_out);
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

bool transmitCanFrame(CanardFrame const & frame)
{
  return mcp2515.transmit(frame);
}

void onReceiveBufferFull(CanardFrame const & frame)
{
  uavcan.onCanFrameReceived(frame);
  Serial.println("Received frame");
}

void onBit_1_0_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  Serial.println("Received Bit");
  Bit_1_0 const uavcan_led = Bit_1_0::deserialize(transfer);

  if(uavcan_led.data==true)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Received bit true");
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Received bit false");
  }
}
