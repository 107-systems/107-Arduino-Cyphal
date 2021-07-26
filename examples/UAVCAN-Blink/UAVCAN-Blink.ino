/*
 * This example creates a UAVCAN node. The builtin LED can be switched on and off using UAVCAN.
 * It also shows periodic transmission of a UAVCAN heartbeat message via CAN.
 *
 * switch built in LED on with
 *   yakut -i 'CAN(can.media.socketcan.SocketCANMedia("can0",8),59)' pub 1620.uavcan.primitive.scalar.Bit.1.0 'value: true'
 *
 * switch built in LED off with
 *   yakut -i 'CAN(can.media.socketcan.SocketCANMedia("can0",8),59)' pub 1620.uavcan.primitive.scalar.Bit.1.0 'value: false'
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
#if defined(ARDUINO_EDGE_CONTROL)
#  include <Arduino_EdgeControl.h>
#endif

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

using namespace uavcan::node;
using namespace uavcan::primitive::scalar;

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static int const MKRCAN_MCP2515_CS_PIN  = 3;
static int const MKRCAN_MCP2515_INT_PIN = 7;
static CanardPortID const BIT_PORT_ID   = 1620U;

#if defined(ESP32)
static int const LED_BUILTIN = 2;
#endif

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

void    spi_select        ();
void    spi_deselect       ();
uint8_t spi_transfer       (uint8_t const);
void    onExternalEvent    ();
bool    transmitCanFrame   (CanardFrame const &);
void    onReceiveBufferFull(CanardFrame const &);
void    onBit_1_0_Received (CanardTransfer const &, ArduinoUAVCAN &);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515(spi_select,
                       spi_deselect,
                       spi_transfer,
                       micros,
                       onReceiveBufferFull,
                       nullptr);

ArduinoUAVCAN uc(13, transmitCanFrame);

Heartbeat_1_0<> hb;

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(9600);
  while(!Serial) { }

  /* Setup LED and initialize */
#if defined(ARDUINO_EDGE_CONTROL)
  Power.on(PWR_3V3);
  Power.on(PWR_VBAT);
  if (!Expander.begin())
  {
    Serial.println("Arduino Edge Control - Expander.begin() failed");
    for(;;) { }
    Expander.pinMode(EXP_LED1, OUTPUT);
  }
#else
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
#endif

  /* Setup SPI access */
  SPI.begin();
  pinMode(MKRCAN_MCP2515_CS_PIN, OUTPUT);
  digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH);

  /* Attach interrupt handler to register MCP2515 signaled by taking INT low */
  pinMode(MKRCAN_MCP2515_INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(MKRCAN_MCP2515_INT_PIN), onExternalEvent, FALLING);

  /* Initialize MCP2515 */
  mcp2515.begin();
  mcp2515.setBitRate(CanBitRate::BR_250kBPS_16MHZ);
  mcp2515.setNormalMode();

  /* Configure initial heartbeat */
  hb.data.uptime = 0;
  hb = Heartbeat_1_0<>::Health::NOMINAL;
  hb = Heartbeat_1_0<>::Mode::INITIALIZATION;
  hb.data.vendor_specific_status_code = 0;

  /* Subscribe to the reception of Bit message. */
  uc.subscribe<Bit_1_0<BIT_PORT_ID>>(onBit_1_0_Received);
}

void loop()
{
  /* Update the heartbeat object */
  hb.data.uptime = millis() / 1000;
  hb = Heartbeat_1_0<>::Mode::OPERATIONAL;

  /* Publish the heartbeat once/second */
  static unsigned long prev = 0;
  unsigned long const now = millis();
  if(now - prev > 1000) {
    uc.publish(hb);
    prev = now;
  }

  /* Transmit all enqeued CAN frames */
  while(uc.transmitCanFrame()) { }
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
  uc.onCanFrameReceived(frame);
}

void onBit_1_0_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uc */)
{
  Bit_1_0<BIT_PORT_ID> const uavcan_led = Bit_1_0<BIT_PORT_ID>::deserialize(transfer);

  if(uavcan_led.data.value)
  {
#if defined(ARDUINO_EDGE_CONTROL)
    Expander.digitalWrite(EXP_LED1, LOW);
#else
    digitalWrite(LED_BUILTIN, HIGH);
#endif
    Serial.println("Received Bit: true");
  }
  else
  {
#if defined(ARDUINO_EDGE_CONTROL)
    Expander.digitalWrite(EXP_LED1, HIGH);
#else
    digitalWrite(LED_BUILTIN, LOW);
#endif
    Serial.println("Received Bit: false");
  }
}
