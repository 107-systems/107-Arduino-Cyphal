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
#include <types/uavcan/node/Heartbeat.1.0.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("The transfer id should be increased after each message of the same type", "[uavcan-01]")
{
  ArduinoUAVCAN uavcan(util::LOCAL_NODE_ID, util::micros);

  Heartbeat_1_0 hb(0, Heartbeat_1_0::Health::NOMINAL, Heartbeat_1_0::Mode::INITIALIZATION, 1);

  WHEN("the first message is sent")
  {
    THEN("the transfer id should be 0")
      REQUIRE(uavcan.publish(hb) == 0);
  }

  WHEN("the two message are sent")
  {
    uavcan.publish(hb);
    THEN("the transfer id should be 1")
      REQUIRE(uavcan.publish(hb) == 1);
  }

}
