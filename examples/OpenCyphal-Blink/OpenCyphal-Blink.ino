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
#include <107-Arduino-CriticalSection.h>
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
void onBit_1_0_Received (Bit_1_0<BIT_PORT_ID> const & msg);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515([]() { digitalWrite(MKRCAN_MCP2515_CS_PIN, LOW); },
                       []() { digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH); },
                       [](uint8_t const data) { return SPI.transfer(data); },
                       micros,
                       onReceiveBufferFull,
                       nullptr);

Node::Heap<Node::DEFAULT_O1HEAP_SIZE> node_heap;
Node node_hdl(node_heap.data(), node_heap.size(), micros);
Publisher<Heartbeat_1_0<>> heartbeat_pub = node_hdl.create_publisher<Heartbeat_1_0<>>(
  Heartbeat_1_0<>::PORT_ID, 1*1000*1000UL /* = 1 sec in usecs. */);
auto heartbeat_subscription = node_hdl.create_subscription<Bit_1_0<BIT_PORT_ID>>(
  Bit_1_0<BIT_PORT_ID>::PORT_ID, CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC, onBit_1_0_Received);

Heartbeat_1_0<> hb_msg;

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
  hb_msg.data.uptime = 0;
  hb_msg.data.health.value = uavcan_node_Health_1_0_NOMINAL;
  hb_msg.data.mode.value = uavcan_node_Mode_1_0_INITIALIZATION;
  hb_msg.data.vendor_specific_status_code = 0;
}

void loop()
{
  /* Process all pending OpenCyphal actions.
   */
  {
    CriticalSection crit_sec;
    node_hdl.spinSome([] (CanardFrame const & frame) { return mcp2515.transmit(frame); });
  }

  /* Update the heartbeat object */
  hb_msg.data.uptime = millis() / 1000;
  hb_msg.data.mode.value = uavcan_node_Mode_1_0_OPERATIONAL;

  /* Publish the heartbeat once/second */
  static unsigned long prev = 0;
  unsigned long const now = millis();
  if(now - prev > 1000) {
    heartbeat_pub->publish(hb_msg);
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

void onBit_1_0_Received(Bit_1_0<BIT_PORT_ID> const & msg)
{
  if(msg.data.value)
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
