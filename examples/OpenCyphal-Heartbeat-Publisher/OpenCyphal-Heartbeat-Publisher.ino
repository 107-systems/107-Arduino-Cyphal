/*
 * This example shows periodic transmission of a OpenCyphal heartbeat message via CAN.
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

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

using namespace uavcan::node;

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static int const MKRCAN_MCP2515_CS_PIN  = 3;
static int const MKRCAN_MCP2515_INT_PIN = 7;

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515([]() { digitalWrite(MKRCAN_MCP2515_CS_PIN, LOW); },
                       []() { digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH); },
                       [](uint8_t const data) { return SPI.transfer(data); },
                       micros,
                       nullptr,
                       nullptr);

CyphalHeap<Node::DEFAULT_O1HEAP_SIZE> node_heap;
Node node_hdl(node_heap.data(), node_heap.size(), micros);
Publisher<Heartbeat_1_0<>> heartbeat_pub = node_hdl.create_publisher<Heartbeat_1_0<>>(Heartbeat_1_0<>::PORT_ID, CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC);

Heartbeat_1_0<> hb_msg;

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
  attachInterrupt(digitalPinToInterrupt(MKRCAN_MCP2515_INT_PIN), []() { mcp2515.onExternalEventHandler(); }, LOW);

  /* Initialize MCP2515 */
  mcp2515.begin();
  mcp2515.setBitRate(CanBitRate::BR_250kBPS_16MHZ);
  mcp2515.setNormalMode();

  /* Configure initial heartbeat */
  hb_msg.data.uptime = 0;
  hb_msg = Heartbeat_1_0<>::Health::NOMINAL;
  hb_msg = Heartbeat_1_0<>::Mode::INITIALIZATION;
  hb_msg.data.vendor_specific_status_code = 0;
}

void loop()
{
  /* Process all pending OpenCyphal actions.
   */
  node_hdl.spinSome([] (CanardFrame const & frame) { return mcp2515.transmit(frame); });

  /* Update the heartbeat object */
  hb_msg.data.uptime = millis() / 1000;
  hb_msg = Heartbeat_1_0<>::Mode::OPERATIONAL;

  /* Publish the heartbeat once/second */
  static unsigned long prev = 0;
  unsigned long const now = millis();
  if(now - prev > 1000) {
    heartbeat_pub->publish(hb_msg);
    prev = now;
  }
}
