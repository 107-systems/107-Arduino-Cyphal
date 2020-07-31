/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <test/util/micros.h>

#include <chrono>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace util
{

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

unsigned long micros()
{
  using namespace std::chrono;
  auto const now    = system_clock::now();
  auto const now_ms = time_point_cast<milliseconds>(now);
  auto const epoch  = now_ms.time_since_epoch();
  return duration_cast<milliseconds>(epoch).count();
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* util */
