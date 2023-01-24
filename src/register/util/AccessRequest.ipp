/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

template <typename T>
T priv_toValue(uavcan::_register::Value_1_0 const & val);

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
T AccessRequest::toValue(uavcan::_register::Value_1_0 const & val)
{
  return priv_toValue<T>(val);
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

template<> inline std::string priv_toValue<std::string>(uavcan::_register::Value_1_0 const & val)
{
  char str[uavcan_primitive_String_1_0_value_ARRAY_CAPACITY_] = {0};
  memcpy(str, val._string.value.elements, val._string.value.count);
  str[val._string.value.count + 1] = '\0';
  return std::string(str);
}

template<> inline bool priv_toValue<bool>(uavcan::_register::Value_1_0 const & val)
{
  return val.bit.value.bitpacked[0];
}

template<> inline int8_t priv_toValue<int8_t>(uavcan::_register::Value_1_0 const & val)
{
  return val.integer8.value.elements[0];
}

template<> inline int16_t priv_toValue<int16_t>(uavcan::_register::Value_1_0 const & val)
{
  return val.integer16.value.elements[0];
}

template<> inline int32_t priv_toValue<int32_t>(uavcan::_register::Value_1_0 const & val)
{
  return val.integer32.value.elements[0];
}

template<> inline int64_t priv_toValue<int64_t>(uavcan::_register::Value_1_0 const & val)
{
  return val.integer64.value.elements[0];
}

template<> inline uint8_t priv_toValue<uint8_t>(uavcan::_register::Value_1_0 const & val)
{
  return val.natural8.value.elements[0];
}

template<> inline uint16_t priv_toValue<uint16_t>(uavcan::_register::Value_1_0 const & val)
{
  return val.natural16.value.elements[0];
}

template<> inline uint32_t priv_toValue<uint32_t>(uavcan::_register::Value_1_0 const & val)
{
  return val.natural32.value.elements[0];
}

template<> inline uint64_t priv_toValue<uint64_t>(uavcan::_register::Value_1_0 const & val)
{
  return val.natural64.value.elements[0];
}

template<> inline float priv_toValue<float>(uavcan::_register::Value_1_0 const & val)
{
  return val.real32.value.elements[0];
}

template<> inline double priv_toValue<double>(uavcan::_register::Value_1_0 const & val)
{
  return val.real64.value.elements[0];
}
