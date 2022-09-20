/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_UTIL_HPP_
#define REGISTER_UTIL_HPP_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "../../Types.h"

#include <string>
#include <algorithm>

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

template <typename T> uavcan_register_Value_1_0 toRegisterValue(T const & val);
template <typename T> T fromRegisterValue(uavcan_register_Value_1_0 const & val);

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

template<> inline uavcan_register_Value_1_0 toRegisterValue<uint8_t>(uint8_t const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.natural8.value.elements[0] = val;
  reg_val.natural8.value.count = 1;
  uavcan_register_Value_1_0_select_natural8_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<std::string>(std::string const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val._string.value.count = std::min(val.length(), uavcan_register_Name_1_0_name_ARRAY_CAPACITY_);
  memcpy(reg_val._string.value.elements, val.c_str(), reg_val._string.value.count);
  uavcan_register_Value_1_0_select_string_(&reg_val);
  return reg_val;
}

template<> inline uint8_t fromRegisterValue<uint8_t>(uavcan_register_Value_1_0 const & val)
{
  return val.natural8.value.elements[0];
}

template<> inline std::string fromRegisterValue<std::string>(uavcan_register_Value_1_0 const & val)
{
  char str[uavcan_primitive_String_1_0_value_ARRAY_CAPACITY_] = {0};
  memcpy(str, val._string.value.elements, val._string.value.count);
  str[val._string.value.count + 1] = '\0';
  return std::string(str);
}

#endif /* REGISTER_UTIL_HPP_ */
