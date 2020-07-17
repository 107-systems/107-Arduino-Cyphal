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

/**************************************************************************************
 * GLOBAL CONSTANTS
 **************************************************************************************/

static CanardNodeID const REMOTE_NODE_ID = 27;

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

static bool transmitCanFrame(uint32_t const /*id*/, uint8_t const * /*data*/, uint8_t const /*len*/)
{
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

  ExecuteCommand_1_0_Request req(0xCAFE);

  REQUIRE(uavcan.request(req, REMOTE_NODE_ID, onExecuteCommand_1_0_Response_Received) != ArduinoUAVCAN::ERROR);
  REQUIRE(uavcan.transmitCanFrame(transmitCanFrame) == true);
}
