/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

namespace impl
{
template <typename T> T toRegisterValue(uavcan_register_Value_1_0 const & val);
} /* impl */

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
T AccessRequest::toRegisterValue(uavcan_register_Value_1_0 const & val)
{
  return impl::toRegisterValue<T>(val);
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

namespace impl
{

template<> inline std::string toRegisterValue<std::string>(uavcan_register_Value_1_0 const & val)
{
  char str[uavcan_primitive_String_1_0_value_ARRAY_CAPACITY_] = {0};
  memcpy(str, val._string.value.elements, val._string.value.count);
  str[val._string.value.count + 1] = '\0';
  return std::string(str);
}

template<> inline bool toRegisterValue<bool>(uavcan_register_Value_1_0 const & val)
{
  return val.bit.value.bitpacked[0];
}

template<> inline int8_t toRegisterValue<int8_t>(uavcan_register_Value_1_0 const & val)
{
  return val.integer8.value.elements[0];
}

template<> inline int16_t toRegisterValue<int16_t>(uavcan_register_Value_1_0 const & val)
{
  return val.integer16.value.elements[0];
}

template<> inline int32_t toRegisterValue<int32_t>(uavcan_register_Value_1_0 const & val)
{
  return val.integer32.value.elements[0];
}

template<> inline int64_t toRegisterValue<int64_t>(uavcan_register_Value_1_0 const & val)
{
  return val.integer64.value.elements[0];
}

template<> inline uint8_t toRegisterValue<uint8_t>(uavcan_register_Value_1_0 const & val)
{
  return val.natural8.value.elements[0];
}

template<> inline uint16_t toRegisterValue<uint16_t>(uavcan_register_Value_1_0 const & val)
{
  return val.natural16.value.elements[0];
}

template<> inline uint32_t toRegisterValue<uint32_t>(uavcan_register_Value_1_0 const & val)
{
  return val.natural32.value.elements[0];
}

template<> inline uint64_t toRegisterValue<uint64_t>(uavcan_register_Value_1_0 const & val)
{
  return val.natural64.value.elements[0];
}

template<> inline float toRegisterValue<float>(uavcan_register_Value_1_0 const & val)
{
  return val.real32.value.elements[0];
}

template<> inline double toRegisterValue<double>(uavcan_register_Value_1_0 const & val)
{
  return val.real64.value.elements[0];
}

} /* impl */
