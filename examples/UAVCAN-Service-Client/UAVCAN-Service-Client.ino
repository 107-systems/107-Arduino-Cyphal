/*
 * This example shows how to use the UAVCAN library to request the performance of a
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
bool    transmitCanFrame(CanardFrame const & frame);
void    onExecuteCommand_1_0_Response_Received(CanardTransfer const &, ArduinoUAVCAN &);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoMCP2515 mcp2515(spi_select,
                       spi_deselect,
                       spi_transfer,
                       micros,
                       nullptr,
                       nullptr);

ArduinoUAVCAN uavcan(13 /* local node id */, micros, transmitCanFrame);

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
  attachInterrupt(digitalPinToInterrupt(MKRCAN_MCP2515_INT_PIN), onExternalEvent, FALLING);

  /* Initialize MCP2515 */
  mcp2515.begin();
  mcp2515.setBitRate(CanBitRate::BR_250kBPS);
  mcp2515.setNormalMode();

  /* Request some coffee. */
  char const cmd_param[] = "I want a double espresso with cream";
  ExecuteCommand_1_0::Request req;
  req.data.command = 0xCAFE;
  req.data.parameter_length = std::min(sizeof(cmd_param), uavcan_node_ExecuteCommand_1_0_Request_parameter_array_capacity());
  std::copy(cmd_param, cmd_param + req.data.parameter_length, req.data.parameter);

  uavcan.request<ExecuteCommand_1_0::Request, ExecuteCommand_1_0::Response>(req, 27 /* remote node id */, onExecuteCommand_1_0_Response_Received);
}

void loop()
{
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

void onExecuteCommand_1_0_Response_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  ExecuteCommand_1_0::Response const rsp = ExecuteCommand_1_0::Response::create(transfer);

  if (rsp.data.status == arduino::_107_::uavcan::to_integer(ExecuteCommand_1_0::Response::Status::SUCCESS))
    Serial.println("Coffee successful retrieved");
  else
    Serial.println("Error when retrieving coffee");
}
