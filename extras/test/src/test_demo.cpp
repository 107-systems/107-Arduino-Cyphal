/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <catch2/catch.hpp>

/**************************************************************************************
 * TEST CODE
 **************************************************************************************/

TEST_CASE("A simple assertion ...", "[test-01]" )
{
  REQUIRE(true == true);
}
