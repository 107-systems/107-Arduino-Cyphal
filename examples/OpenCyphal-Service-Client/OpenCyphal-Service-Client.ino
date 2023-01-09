/*
 * This example shows how to use the OpenCyphal library to request the performance of a
 * service from a service server.
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

void onReceiveBufferFull(CanardFrame const &);
void onExecuteCommand_1_0_Response_Received(ExecuteCommand_1_0::Response<> const & rsp);

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
CircularBuffer<Node::TReceiveCircularBuffer>::Heap<Node::DEFAULT_RX_QUEUE_SIZE> node_rx_queue;
Node node_hdl(node_heap.data(), node_heap.size(), node_rx_queue.data(), node_rx_queue.size(), micros);

ServiceClient<ExecuteCommand_1_0::Request<>> srv_client = node_hdl.create_service_client<ExecuteCommand_1_0::Request<>, ExecuteCommand_1_0::Response<>>(
  ExecuteCommand_1_0::Request<>::PORT_ID,
  2*1000*1000UL,
  onExecuteCommand_1_0_Response_Received);

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

  /* Request some coffee. */
  char const cmd_param[] = "I want a double espresso with cream!";
  ExecuteCommand_1_0::Request<> req;
  req.data.command = 0xCAFE;
  req.data.parameter.count = std::min(strlen(cmd_param), (size_t)uavcan_node_ExecuteCommand_Request_1_0_parameter_ARRAY_CAPACITY_);
  std::copy(cmd_param,
            cmd_param + req.data.parameter.count,
            req.data.parameter.elements);

  if (!srv_client->request(27 /* remote node id */, req))
    Serial.println("Coffee request failed.");
}

void loop()
{
  /* Process all pending OpenCyphal actions.
   */
  {
    CriticalSection crit_sec;
    node_hdl.spinSome([] (CanardFrame const & frame) { return mcp2515.transmit(frame); });
  }
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void onReceiveBufferFull(CanardFrame const & frame)
{
  node_hdl.onCanFrameReceived(frame);
}

void onExecuteCommand_1_0_Response_Received(ExecuteCommand_1_0::Response<> const & rsp)
{
  if (rsp.data.status == uavcan_node_ExecuteCommand_Response_1_0_STATUS_SUCCESS)
    Serial.println("Coffee successfully retrieved");
  else
    Serial.println("Error when retrieving coffee");
}
