/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <test/util/Const.h>
#include <test/util/Types.h>
#include <test/util/micros.h>

#include <ArduinoUAVCAN.h>
#include <types/uavcan/node/ExecuteCommand.1.0.Request.h>
#include <types/uavcan/node/ExecuteCommand.1.0.Response.h>

/**************************************************************************************
 * GLOBAL CONSTANTS
 **************************************************************************************/

static CanardNodeID const REMOTE_NODE_ID = 27;

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

static util::CanFrameVect can_frame_vect;
static ExecuteCommand_1_0_Response::Status response_status = ExecuteCommand_1_0_Response::Status::INTERNAL_ERROR;

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

static bool transmitCanFrame(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  util::CanFrame frame{id, std::vector<uint8_t>(data, data + len)};
  can_frame_vect.push_back(frame);
  return true;
}

void onExecuteCommand_1_0_Response_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  ExecuteCommand_1_0_Response const response = ExecuteCommand_1_0_Response::create(transfer);
  response_status = response.status();
}

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("A '435.ExecuteCommand.1.0' request is sent to a server", "[execute-command-client-01]")
{
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, util::micros, transmitCanFrame);

  std::string const cmd_param = "I want a double espresso with cream";
  ExecuteCommand_1_0_Request req(0xCAFE, reinterpret_cast<uint8_t const *>(cmd_param.c_str()), cmd_param.length());

  REQUIRE(uavcan.request<ExecuteCommand_1_0_Request, ExecuteCommand_1_0_Response>(req, REMOTE_NODE_ID, onExecuteCommand_1_0_Response_Received) != ArduinoUAVCAN::ERROR);
  /* Transmit all the CAN frames. */
  while(uavcan.transmitCanFrame()) { }

  /* Verify the content of the CAN frames. */
  /*
   * pyuavcan call 27 435.uavcan.node.ExecuteCommand.1.0 '{"command": 0xCAFE, "parameter": "I want a double espresso with cream"}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),13)'
   */
  static util::CanFrameVect const EXPECTED_CAN_FRAMES = 
  {
    {0x136CCD8D, {0xFE, 0xCA, 0x23, 0x49, 0x20, 0x77, 0x61, 0xA0}},
    {0x136CCD8D, {0x6E, 0x74, 0x20, 0x61, 0x20, 0x64, 0x6F, 0x00}},
    {0x136CCD8D, {0x75, 0x62, 0x6C, 0x65, 0x20, 0x65, 0x73, 0x20}},
    {0x136CCD8D, {0x70, 0x72, 0x65, 0x73, 0x73, 0x6F, 0x20, 0x00}},
    {0x136CCD8D, {0x77, 0x69, 0x74, 0x68, 0x20, 0x63, 0x72, 0x20}},
    {0x136CCD8D, {0x65, 0x61, 0x6D, 0xC4, 0xC8, 0x40}},
  };
  REQUIRE(can_frame_vect.size() == EXPECTED_CAN_FRAMES.size());

  auto actual = std::begin(can_frame_vect);
  std::for_each(std::begin(EXPECTED_CAN_FRAMES),
                std::end  (EXPECTED_CAN_FRAMES),
                [&actual](util::CanFrame const frame)
                {
                  REQUIRE(actual->id   == frame.id);
                  REQUIRE(actual->data == frame.data);
                  actual++;
                });

  /* Feed back the command response to the uavcan node. In a
   * real system the answer would come back from the remote node.
   */
  /* ... ? ... */
}
