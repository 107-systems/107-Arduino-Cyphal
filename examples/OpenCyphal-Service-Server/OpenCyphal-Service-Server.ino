/*
 * This example shows how to use the OpenCyphal library to set up a service server
 * responding to requests from service clients.
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
 * FUNCTION DECLARATION
 **************************************************************************************/

void onReceiveBufferFull(CanardFrame const &);
ExecuteCommand_1_0::Response<> onExecuteCommand_1_0_Request_Received(ExecuteCommand_1_0::Request<> const &);

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
Service execute_command_srv = node_hdl.create_service<ExecuteCommand_1_0::Request<>, ExecuteCommand_1_0::Response<>>(
  ExecuteCommand_1_0::Request<>::PORT_ID,
  2*1000*1000UL,
  onExecuteCommand_1_0_Request_Received);

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
}

void loop()
{
  /* Process all pending OpenCyphal actions.
   */
  node_hdl.spinSome([] (CanardFrame const & frame) { return mcp2515.transmit(frame); });
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void onReceiveBufferFull(CanardFrame const & frame)
{
  node_hdl.onCanFrameReceived(frame, micros());
}

ExecuteCommand_1_0::Response<> onExecuteCommand_1_0_Request_Received(ExecuteCommand_1_0::Request<> const & req)
{
  ExecuteCommand_1_0::Response<> rsp;

  if (req.data.command == 0xCAFE)
    rsp.data.status = uavcan_node_ExecuteCommand_Response_1_0_STATUS_SUCCESS;
  else
    rsp.data.status = uavcan_node_ExecuteCommand_Response_1_0_STATUS_NOT_AUTHORIZED;

  return rsp;
}
