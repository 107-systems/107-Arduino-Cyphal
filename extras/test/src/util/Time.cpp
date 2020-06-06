/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <test/util/Time.h>

#include <chrono>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace util
{

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

MicroSecondFunc Time::micros()
{
  return std::bind(&Time::internal_micros, this);
}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

unsigned long Time::internal_micros()
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
