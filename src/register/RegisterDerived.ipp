/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * EXTERN DECLARATION
 **************************************************************************************/

extern unsigned long micros(void);

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

template <typename T> uavcan_register_Value_1_0 toRegisterValue(T const & val);
template <typename T> T fromRegisterValue(uavcan_register_Value_1_0 const & val);

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template <typename T>
RegisterDerived<T>::RegisterDerived(char const * name,
                                    Register::Access const access,
                                    T const & initial_val,
                                    OnRegisterValueChangeFunc func)
: RegisterBase{name, Register::toTypeTag(initial_val)}
, _access{access}
, _val{initial_val}
, _func{func}
{ }

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
void RegisterDerived<T>::set(uavcan_register_Value_1_0 const & val)
{
  if (_access == Register::Access::ReadOnly)
    return;

  _val = fromRegisterValue<T>(val);
  if (_func)
    _func(*this);
}

template <typename T>
uavcan::_register::Access_1_0::Response<> RegisterDerived<T>::toAccessResponse()
{
  uavcan::_register::Access_1_0::Response<> rsp;

  rsp.data.value = toRegisterValue(_val);
  rsp.data.timestamp.microsecond = micros();
  rsp.data._mutable = (_access == Register::Access::ReadOnly) ? false : true;
  rsp.data.persistent = false;

  return rsp;
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

template<> inline uavcan_register_Value_1_0 toRegisterValue<std::string>(std::string const & val)
{
  uavcan_register_Value_1_0 reg_val;
  reg_val._string.value.count = std::min(val.length(), uavcan_register_Name_1_0_name_ARRAY_CAPACITY_);
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

template<> inline std::string fromRegisterValue<std::string>(uavcan_register_Value_1_0 const & val)
{
  char str[uavcan_primitive_String_1_0_value_ARRAY_CAPACITY_] = {0};
  memcpy(str, val._string.value.elements, val._string.value.count);
  str[val._string.value.count + 1] = '\0';
  return std::string(str);
}

template<> inline bool fromRegisterValue<bool>(uavcan_register_Value_1_0 const & val)
{
  return val.bit.value.bitpacked[0];
}

template<> inline int8_t fromRegisterValue<int8_t>(uavcan_register_Value_1_0 const & val)
{
  return val.integer8.value.elements[0];
}

template<> inline int16_t fromRegisterValue<int16_t>(uavcan_register_Value_1_0 const & val)
{
  return val.integer16.value.elements[0];
}

template<> inline int32_t fromRegisterValue<int32_t>(uavcan_register_Value_1_0 const & val)
{
  return val.integer32.value.elements[0];
}

template<> inline int64_t fromRegisterValue<int64_t>(uavcan_register_Value_1_0 const & val)
{
  return val.integer64.value.elements[0];
}

template<> inline uint8_t fromRegisterValue<uint8_t>(uavcan_register_Value_1_0 const & val)
{
  return val.natural8.value.elements[0];
}

template<> inline uint16_t fromRegisterValue<uint16_t>(uavcan_register_Value_1_0 const & val)
{
  return val.natural16.value.elements[0];
}

template<> inline uint32_t fromRegisterValue<uint32_t>(uavcan_register_Value_1_0 const & val)
{
  return val.natural32.value.elements[0];
}

template<> inline uint64_t fromRegisterValue<uint64_t>(uavcan_register_Value_1_0 const & val)
{
  return val.natural64.value.elements[0];
}

template<> inline float fromRegisterValue<float>(uavcan_register_Value_1_0 const & val)
{
  return val.real32.value.elements[0];
}

template<> inline double fromRegisterValue<double>(uavcan_register_Value_1_0 const & val)
{
  return val.real64.value.elements[0];
}
