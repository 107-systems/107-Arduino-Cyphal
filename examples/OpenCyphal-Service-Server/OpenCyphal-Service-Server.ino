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
void onExecuteCommand_1_0_Request_Received(CanardRxTransfer const &, Node &);

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

  /* Subscribe to incoming service requests */
  node_hdl.subscribe<ExecuteCommand_1_0::Request<>>(onExecuteCommand_1_0_Request_Received);
}

void loop()
{
  /* Process all pending OpenCyphal actions.
   */
  node_hdl.spinSome();
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void onReceiveBufferFull(CanardFrame const & frame)
{
  node_hdl.onCanFrameReceived(frame, micros());
}

void onExecuteCommand_1_0_Request_Received(CanardRxTransfer const & transfer, Node & node_hdl)
{
  ExecuteCommand_1_0::Request<> req = ExecuteCommand_1_0::Request<>::deserialize(transfer);

  if (req.data.command == 0xCAFE)
  {
    ExecuteCommand_1_0::Response<> rsp;
    rsp = ExecuteCommand_1_0::Response<>::Status::SUCCESS;
    node_hdl.respond(rsp, transfer.metadata.remote_node_id, transfer.metadata.transfer_id);
  }
  else
  {
    ExecuteCommand_1_0::Response<> rsp;
    rsp = ExecuteCommand_1_0::Response<>::Status::NOT_AUTHORIZED;
    node_hdl.respond(rsp, transfer.metadata.remote_node_id, transfer.metadata.transfer_id);
  }
}
