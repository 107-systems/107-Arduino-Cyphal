/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <test/util/Const.h>
#include <test/util/micros.h>

#include <ArduinoUAVCAN.h>
#include <types/uavcan/node/ExecuteCommand.1.0.Request.h>

#include <iostream>

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef struct
{
  uint32_t id;
  std::vector<uint8_t> data;
} CanRxFrame;

/**************************************************************************************
 * GLOBAL CONSTANTS
 **************************************************************************************/

static CanardNodeID const REMOTE_NODE_ID = 27;

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

static std::vector<CanRxFrame> can_rx_frame_vect;

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

static bool transmitCanFrame(uint32_t const id, uint8_t const * data, uint8_t const len)
{
  CanRxFrame frame{id, std::vector<uint8_t>(data, data + len)};
  can_rx_frame_vect.push_back(frame);
  return true;
}

void onExecuteCommand_1_0_Response_Received(CanardTransfer const & /*transfer*/)
{

}

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("A '435.ExecuteCommand.1.0' request is sent", "[execute-command-01]")
{
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, util::micros);

  std::string const cmd_param = "I want a double espresso with cream";
  ExecuteCommand_1_0_Request req(0xCAFE, reinterpret_cast<uint8_t const *>(cmd_param.c_str()), cmd_param.length());

  REQUIRE(uavcan.request(req, REMOTE_NODE_ID, onExecuteCommand_1_0_Response_Received) != ArduinoUAVCAN::ERROR);
  /* Transmit all the CAN frames. */
  while(uavcan.transmitCanFrame(transmitCanFrame)) { }
  /* Verify the content of the CAN frames. */
  static std::vector<CanRxFrame> const EXPECTED_CAN_FRAMES = 
  {
    {0x136CCD8D, {0xfe, 0xca, 0x49, 0x20, 0x77, 0x61, 0x6e, 0xa0}},
    {0x136CCD8D, {0x74, 0x20, 0x61, 0x20, 0x64, 0x6f, 0x75, 0x00}},
    {0x136CCD8D, {0x62, 0x6c, 0x65, 0x20, 0x65, 0x73, 0x70, 0x20}},
    {0x136CCD8D, {0x72, 0x65, 0x73, 0x73, 0x6f, 0x20, 0x77, 0x00}},
    {0x136CCD8D, {0x69, 0x74, 0x68, 0x20, 0x63, 0x72, 0x65, 0x20}},
    {0x136CCD8D, {0x61, 0x6d, 0x4d, 0x8, 0x40}}
  };
  REQUIRE(can_rx_frame_vect.size() == EXPECTED_CAN_FRAMES.size());

  auto iter = std::begin(can_rx_frame_vect);
  std::for_each(std::begin(EXPECTED_CAN_FRAMES),
                std::end  (EXPECTED_CAN_FRAMES),
                [&iter](CanRxFrame const frame)
                {
                  REQUIRE(iter->id   == frame.id);
                  REQUIRE(iter->data == frame.data);
                  iter++;
                });
}
