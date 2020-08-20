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

static util::CanFrameVect can_frame_vect;
static uint8_t protocol_version_major, protocol_version_minor;

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

static bool transmitCanFrame(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  util::CanFrame frame{id, std::vector<uint8_t>(data, data + len)};
  can_frame_vect.push_back(frame);
  return true;
}

void onGetInfo_1_0_Response_Received(CanardTransfer const & transfer, ArduinoUAVCAN & /* uavcan */)
{
  GetInfo_1_0::Response rsp = GetInfo_1_0::Response::create(transfer);

  protocol_version_major = rsp.protocol_version().get_major();
  protocol_version_minor = rsp.protocol_version().get_minor();
}

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("A '430.GetInfo.1.0' request is sent to a server", "[GetInfo.1.0-client-01]")
{
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, util::micros, transmitCanFrame);

  GetInfo_1_0::Request req;

  REQUIRE(uavcan.request<GetInfo_1_0::Request, GetInfo_1_0::Response>(req, REMOTE_NODE_ID, onGetInfo_1_0_Response_Received) == true);
  /* Transmit all the CAN frames. */
  while(uavcan.transmitCanFrame()) { }

  /* Verify the content of the CAN frames. */
  /*
   * pyuavcan call 27 430.uavcan.node.GetInfo.1.0 '{}' --tr='CAN(can.media.socketcan.SocketCANMedia("vcan0",8),13)'
   */
  static util::CanFrame const EXPECTED_CAN_FRAME_REQUEST{0x136B8D8D, {0xE0}};
  REQUIRE(can_frame_vect.size()  == 1);
  REQUIRE(can_frame_vect[0].id   == EXPECTED_CAN_FRAME_REQUEST.id);
  REQUIRE(can_frame_vect[0].data == EXPECTED_CAN_FRAME_REQUEST.data);


  /* Feed back the command response to the uavcan node. In a
   * real system the answer would come back from the remote node.
   */
/*
  GetInfo_1_0::Response resp(1,
           0,
           2,
           1,
           1,
           5,
           0xDEADBEEFCAFECAFE,
           {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});

  can_frame_vect.clear();
  uavcan.respond(resp, util::LOCAL_NODE_ID, 0);
  while(uavcan.transmitCanFrame()) { }

  std::cout << "RESPONSE = " << std::endl;
  std::cout << can_frame_vect << std::endl;
*/
  static util::CanFrameVect const RESPONSE_CAN_FRAMES =
  {
    {0x126B868D, {0x01, 0x00, 0x02, 0x01, 0x01, 0x05, 0xfe, 0xa0}},
    {0x126B868D, {0xca, 0xfe, 0xca, 0xef, 0xbe, 0xad, 0xde, 0x00}},
    {0x126B868D, {0x10, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x20}},
    {0x126B868D, {0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x00}},
    {0x126B868D, {0x0d, 0x0e, 0x0f, 0x70, 0x56, 0x60}},
  };
  std::for_each(std::begin(RESPONSE_CAN_FRAMES),
                std::end  (RESPONSE_CAN_FRAMES),
                [&uavcan](util::CanFrame const & frame)
                {
                  uavcan.onCanFrameReceived(frame.id, frame.data.data(), frame.data.size());
                });
  /*
  REQUIRE(protocol_version_major == 1);
  REQUIRE(protocol_version_minor == 0);
  */
}
