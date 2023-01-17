/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#undef max
#undef min
#include <algorithm>

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

template <typename T> uavcan_register_Value_1_0 toRegisterValue(T const & val);

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
uavcan::_register::Access_1_0::Response<> AccessResponse::create(RegisterDerived<T> const & reg)
{
  uavcan::_register::Access_1_0::Response<> rsp;

  rsp.data.value = toRegisterValue(reg.get());
  rsp.data.timestamp = reg.timestamp();
  rsp.data._mutable = reg.isMutable();
  rsp.data.persistent = reg.isPersistent();

  return rsp;
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

template<> inline uavcan_register_Value_1_0 toRegisterValue<std::string>(std::string const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val._string.value.count = std::min(static_cast<size_t>(val.length()), static_cast<size_t>(uavcan_register_Name_1_0_name_ARRAY_CAPACITY_));
  memcpy(reg_val._string.value.elements, val.c_str(), reg_val._string.value.count);
  uavcan_register_Value_1_0_select_string_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<bool>(bool const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.bit.value.bitpacked[0] = (uint8_t)val;
  reg_val.bit.value.count = 1;
  uavcan_register_Value_1_0_select_bit_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<int8_t>(int8_t const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.integer8.value.elements[0] = val;
  reg_val.integer8.value.count = 1;
  uavcan_register_Value_1_0_select_integer8_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<int16_t>(int16_t const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.integer16.value.elements[0] = val;
  reg_val.integer16.value.count = 1;
  uavcan_register_Value_1_0_select_integer16_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<int32_t>(int32_t const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.integer32.value.elements[0] = val;
  reg_val.integer32.value.count = 1;
  uavcan_register_Value_1_0_select_integer32_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<int64_t>(int64_t const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.integer64.value.elements[0] = val;
  reg_val.integer64.value.count = 1;
  uavcan_register_Value_1_0_select_integer64_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<uint8_t>(uint8_t const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.natural8.value.elements[0] = val;
  reg_val.natural8.value.count = 1;
  uavcan_register_Value_1_0_select_natural8_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<uint16_t>(uint16_t const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.natural16.value.elements[0] = val;
  reg_val.natural16.value.count = 1;
  uavcan_register_Value_1_0_select_natural16_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<uint32_t>(uint32_t const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.natural32.value.elements[0] = val;
  reg_val.natural32.value.count = 1;
  uavcan_register_Value_1_0_select_natural32_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<uint64_t>(uint64_t const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.natural64.value.elements[0] = val;
  reg_val.natural64.value.count = 1;
  uavcan_register_Value_1_0_select_natural64_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<float>(float const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.real32.value.elements[0] = val;
  reg_val.real32.value.count = 1;
  uavcan_register_Value_1_0_select_real32_(&reg_val);
  return reg_val;
}

template<> inline uavcan_register_Value_1_0 toRegisterValue<double>(double const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val.real64.value.elements[0] = val;
  reg_val.real64.value.count = 1;
  uavcan_register_Value_1_0_select_real64_(&reg_val);
  return reg_val;
}
