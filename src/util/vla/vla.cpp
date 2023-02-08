/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "vla.h"

#include <cstring>

#include <iterator>
#include <algorithm>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace vla
{

/**************************************************************************************
 * FUNCTION DEFINITIONS
 **************************************************************************************/

uavcan::primitive::String_1_0 to_String_1_0(std::string const & str)
{
  uavcan::primitive::String_1_0 out;
  std::copy_n(str.begin(), std::min(str.length(), out.value.max_size()), std::back_inserter(out.value));
  return out;
}

uavcan::primitive::String_1_0 to_String_1_0(char const * c_str)
{
  uavcan::primitive::String_1_0 out;
  std::copy_n(c_str, std::min(strlen(c_str), out.value.max_size()), std::back_inserter(out.value));
  return out;
}

uavcan::_register::Name_1_0 to_Name_1_0(std::string const & str)
{
  uavcan::_register::Name_1_0 out;
  std::copy_n(str.begin(), std::min(str.length(), out.name.max_size()), std::back_inserter(out.name));
  return out;
}

uavcan::_register::Name_1_0 to_Name_1_0(char const * c_str)
{
  uavcan::_register::Name_1_0 out;
  std::copy_n(c_str, std::min(strlen(c_str), out.name.max_size()), std::back_inserter(out.name));
  return out;
}

std::string toStr(uavcan::primitive::String_1_0 const & str)
{
  char buf[256 + 1] = {0};
  memcpy(buf, str.value.data(), std::min(str.value.size(), sizeof(buf)));
  return std::string(buf);
}

std::string toStr(uavcan::_register::Name_1_0 const & name)
{
  char buf[255 + 1] = {0};
  memcpy(buf, name.name.data(), std::min(name.name.size(), sizeof(buf)));
  return std::string(buf);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* vla */
