/*
 * This example shows how to use the OpenCyphal library to request the performance of a
 * service from a service server.
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
void onExecuteCommand_1_1_Response_Received(ExecuteCommand::Response_1_1 const & rsp);

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
Node node_hdl(node_heap.data(), node_heap.size(), micros, [] (CanardFrame const & frame) { return mcp2515.transmit(frame); }, 28);

ServiceClient<ExecuteCommand::Request_1_1> srv_client = node_hdl.create_service_client<ExecuteCommand::Request_1_1, ExecuteCommand::Response_1_1>(
  2*1000*1000UL,
  onExecuteCommand_1_1_Response_Received);

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(9600);
  while(!Serial) { }
  delay(1000);
  Serial.println("|---- OpenCyphal Service Client Example ----|");

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

  /* Publish the request once/second */
  static unsigned long prev = 0;
  unsigned long const now = millis();
  if(now - prev > 1000)
  {
    prev = now;

    /* Request some coffee. */
    Serial.println("Requesting some coffee");
    std::string const cmd_param("I want a double espresso with cream!");
    ExecuteCommand::Request_1_1 req;
    req.command = 0xCAFE;
    std::copy(cmd_param.begin(), cmd_param.end(), std::back_inserter(req.parameter));


    if (!srv_client->request(27 /* remote node id */, req)) {
      Serial.println("Coffee request failed.");
    }
  }
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void onReceiveBufferFull(CanardFrame const & frame)
{
  node_hdl.onCanFrameReceived(frame);
}

void onExecuteCommand_1_1_Response_Received(ExecuteCommand::Response_1_1 const & rsp)
{
  if (rsp.status == ExecuteCommand::Response_1_1::STATUS_SUCCESS)
    Serial.println("Coffee successfully retrieved");
  else
    Serial.println("Error when retrieving coffee");
}
