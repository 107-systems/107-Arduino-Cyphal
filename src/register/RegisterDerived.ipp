/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * EXTERN DECLARATION
 **************************************************************************************/

extern "C" unsigned long micros(void);

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

template <typename T> T fromRegisterValue(uavcan_register_Value_1_0 const & val);

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template <typename T>
RegisterDerived<T>::RegisterDerived(char const * name,
                                    Register::Access const access,
                                    bool const is_persistent,
                                    T const & initial_val,
                                    OnRegisterValueChangeFunc func)
: RegisterBase{name,
               Register::toTypeTag(initial_val),
               (access == Register::Access::ReadOnly),
               is_persistent}
, _val{initial_val}
, _func{func}
{ }

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
void RegisterDerived<T>::set(uavcan_register_Value_1_0 const & val)
{
  if (!isMutable())
    return;

  _val = fromRegisterValue<T>(val);
  if (_func)
    _func(*this);
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

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
