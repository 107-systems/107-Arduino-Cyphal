/*
 * This example creates a OpenCyphal node. The builtin LED can be switched on and off using OpenCyphal.
 * It also shows periodic transmission of a OpenCyphal heartbeat message via CAN.
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

#include <107-Arduino-Cyphal.h>
#include <107-Arduino-MCP2515.h>
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

void onReceiveBufferFull(CanardFrame const &);
void onBit_1_0_Received (CanardRxTransfer const &, Node &);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515([]() { digitalWrite(MKRCAN_MCP2515_CS_PIN, LOW); },
                       []() { digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH); },
                       [](uint8_t const data) { return SPI.transfer(data); },
                       micros,
                       onReceiveBufferFull,
                       nullptr);

Node node_hdl([] (CanardFrame const & frame) { return mcp2515.transmit(frame); });

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
  attachInterrupt(digitalPinToInterrupt(MKRCAN_MCP2515_INT_PIN), []() { mcp2515.onExternalEventHandler(); }, LOW);

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
  node_hdl.subscribe<Bit_1_0<BIT_PORT_ID>>(onBit_1_0_Received);
}

void loop()
{
  /* Process all pending OpenCyphal actions.
   */
  node_hdl.spinSome();

  /* Update the heartbeat object */
  hb.data.uptime = millis() / 1000;
  hb = Heartbeat_1_0<>::Mode::OPERATIONAL;

  /* Publish the heartbeat once/second */
  static unsigned long prev = 0;
  unsigned long const now = millis();
  if(now - prev > 1000) {
    node_hdl.publish(hb);
    prev = now;
  }
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void onReceiveBufferFull(CanardFrame const & frame)
{
  node_hdl.onCanFrameReceived(frame, micros());
}

void onBit_1_0_Received(CanardRxTransfer const & transfer, Node & /* node_hdl */)
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
