/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch.hpp>

#include <test/util/Time.h>
#include <test/util/Transfer.h>

#include <ArduinoUAVCAN.h>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("")
{
  util::Time time_util;
  util::Transfer transfer_util;
  
  ArduinoUAVCAN uavcan(13, time_util.micros(), transfer_util.onTransferReceived());
  
  REQUIRE(transfer_util.received());
}