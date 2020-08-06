/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <test/util/Const.h>
#include <test/util/Types.h>
#include <test/util/micros.h>

#include <ArduinoUAVCAN.h>

/**************************************************************************************
 * GLOBAL CONSTANTS
 **************************************************************************************/

static CanardNodeID const REMOTE_NODE_ID = 27;

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

static util::CanFrame       response_can_frame;
static uint16_t             request_command = 0;
static std::vector<uint8_t> request_param = {0};

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

static bool transmitCanFrame(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  util::CanFrame frame{id, std::vector<uint8_t>(data, data + len)};
  response_can_frame = frame;
  return true;
}

void onExecuteCommand_1_0_Request_Received(CanardTransfer const & transfer, ArduinoUAVCAN & uavcan)
{
  ExecuteCommand_1_0::Request request = ExecuteCommand_1_0::Request::create(transfer);

  /* The next 2 lines are just for test purposes, you won't
   * have them in your real application.
   */
  request_command = request.command();
  request_param = std::vector<uint8_t>{request.param(), request.param() + request.param_len()};

  /* Deal with the command ... */

  /* ... and construct and send the response. */
  ExecuteCommand_1_0::Response response(ExecuteCommand_1_0::Response::Status::NOT_AUTHORIZED);

  uavcan.respond(response, transfer.remote_node_id, transfer.transfer_id);
}

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("A '435.ExecuteCommand.1.0' request is received from a client", "[execute-command-server-01]")
{
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, util::micros, transmitCanFrame);

  /* Subscribe to incoming server requests. */
  REQUIRE(uavcan.subscribe<ExecuteCommand_1_0::Request>(onExecuteCommand_1_0_Request_Received) == true);

  /*
   * pyuavcan call 13 435.uavcan.node.ExecuteCommand.1.0 '{"command": 0xCAFE, "parameter": "I want a double espresso with cream"}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),27)'
   */
  static util::CanFrameVect const SERVER_REQUEST_CAN_FRAMES =
  {
    {0x136CC69B, {0xFE, 0xCA, 0x23, 0x49, 0x20, 0x77, 0x61, 0xA0}},
    {0x136CC69B, {0x6E, 0x74, 0x20, 0x61, 0x20, 0x64, 0x6F, 0x00}},
    {0x136CC69B, {0x75, 0x62, 0x6C, 0x65, 0x20, 0x65, 0x73, 0x20}},
    {0x136CC69B, {0x70, 0x72, 0x65, 0x73, 0x73, 0x6F, 0x20, 0x00}},
    {0x136CC69B, {0x77, 0x69, 0x74, 0x68, 0x20, 0x63, 0x72, 0x20}},
    {0x136CC69B, {0x65, 0x61, 0x6D, 0xC4, 0xC8, 0x40}},
  };

  /* Simulate receiving a request from a remote client. */
  std::for_each(std::begin(SERVER_REQUEST_CAN_FRAMES),
                std::end  (SERVER_REQUEST_CAN_FRAMES),
                [&uavcan](util::CanFrame const frame)
                {
                  uavcan.onCanFrameReceived(frame.id, &frame.data.front(), frame.data.size());
                });

  /* Check if the correct request has been received. */
  REQUIRE(request_command == 0xCAFE);
  std::string const EXP_CMD_PARAM_STR = "I want a double espresso with cream";
  std::vector<uint8_t> const EXP_CMD_PARAM_VECT(EXP_CMD_PARAM_STR.begin(), EXP_CMD_PARAM_STR.end());
  REQUIRE(request_param == EXP_CMD_PARAM_VECT);

  /* We should now have one CAN frame in the transmit pipeline */
  REQUIRE(uavcan.transmitCanFrame() == true);

  /* Check if the sent response is identical with what we expect. */
  REQUIRE(response_can_frame.id   == 0x126CCD8D);
  REQUIRE(response_can_frame.data == std::vector<uint8_t>{0x02, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xE0});
}
