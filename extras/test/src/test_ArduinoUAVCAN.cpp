/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <test/util/micros.h>

#include <ArduinoUAVCAN.h>
#include <transfer/uavcan/node/Heartbeat.1.0.h>

/**************************************************************************************
 * PRIVATE FUNCTION DEFINITION
 **************************************************************************************/

static bool transmitCanFrame(uint32_t const /* id */, uint8_t const * /* data */, uint8_t const /* len */)
{
  return true;
}

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("The transfer id should be increased after each message of the same type", "[uavcan-01]")
{
  ArduinoUAVCAN uavcan(13, util::micros, transmitCanFrame);

  Heartbeat_1_0 hb(0, Heartbeat_1_0::Health::NOMINAL, Heartbeat_1_0::Mode::INITIALIZATION, 1);
  uint8_t hb_transfer_id;

  WHEN("the first message is sent")
  {
    uavcan.publish(Heartbeat_1_0::PORT_ID, hb, &hb_transfer_id);
    THEN("the transfer id should be 0")
      REQUIRE(hb_transfer_id == 0);
  }

  WHEN("the two message are sent")
  {
    uavcan.publish(Heartbeat_1_0::PORT_ID, hb, &hb_transfer_id);
    uavcan.publish(Heartbeat_1_0::PORT_ID, hb, &hb_transfer_id);
    THEN("the transfer id should be 1")
      REQUIRE(hb_transfer_id == 1);
  }

}
