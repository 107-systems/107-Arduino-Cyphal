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
