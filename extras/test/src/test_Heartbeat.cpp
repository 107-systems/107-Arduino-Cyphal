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

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("")
{
  ArduinoUAVCAN uavcan(13, util::micros, nullptr);
  REQUIRE(true);
}