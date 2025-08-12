/*
 * This example shows reception of a OpenCyphal heartbeat message via CAN.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <SPI.h>

#include <107-Arduino-Cyphal.h>
#include <107-Arduino-MCP2515.h>
#include <107-Arduino-CriticalSection.h>

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
 * FUNCTION DECLARATION
 **************************************************************************************/

void onReceiveBufferFull    (CanardFrame const &);
void onHeartbeat_1_0_Received(Heartbeat_1_0 const & msg);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515([]() { digitalWrite(MKRCAN_MCP2515_CS_PIN, LOW); },
                       []() { digitalWrite(MKRCAN_MCP2515_CS_PIN, HIGH); },
                       [](uint8_t const data) { return SPI.transfer(data); },
                       micros,
                       millis,
                       onReceiveBufferFull,
                       nullptr,
                       nullptr,
                       nullptr);

cyphal::Node::Heap<cyphal::Node::DEFAULT_O1HEAP_SIZE> node_heap;
cyphal::Node node_hdl(node_heap.data(), node_heap.size(), micros, [] (CanardFrame const & frame) { return mcp2515.transmit(frame); });

cyphal::Subscription heartbeat_subscription = node_hdl.create_subscription<Heartbeat_1_0>(onHeartbeat_1_0_Received);

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(9600);
  while(!Serial) { }
  delay(1000);
  Serial.println("|---- OpenCyphal Heartbeat Subscription Example ----|");

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

  Serial.println("setup finished");
}

void loop()
{
  /* Process all pending OpenCyphal actions.
   */
  {
    CriticalSection crit_sec;
    node_hdl.spinSome();
  }
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void onReceiveBufferFull(CanardFrame const & frame)
{
  node_hdl.onCanFrameReceived(frame);
}

void onHeartbeat_1_0_Received(Heartbeat_1_0 const & msg)
{
  char msg_buf[64];
  snprintf(msg_buf, sizeof(msg_buf),
           "Uptime = %d, Health = %d, Mode = %d, VSSC = %d",
           msg.uptime, msg.health.value, msg.mode.value, msg.vendor_specific_status_code);

  Serial.println(msg_buf);
}
