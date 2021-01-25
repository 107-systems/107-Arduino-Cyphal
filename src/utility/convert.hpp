/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_UTILITY_COVERT_HPP_
#define ARDUINO_UAVCAN_UTILITY_COVERT_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <type_traits>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace arduino
{
namespace _107_
{
namespace uavcan
{

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

template <typename Enumeration>
constexpr auto to_integer(Enumeration const value) -> typename std::underlying_type<Enumeration>::type
{
  return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* uavcan */
} /* _107_ */
} /* arduino */

#endif /* ARDUINO_UAVCAN_UTILITY_COVERT_HPP_ */
