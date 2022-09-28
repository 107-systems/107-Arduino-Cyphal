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
 * CTOR/DTOR
 **************************************************************************************/

template <typename T>
RegisterDerived<T>::RegisterDerived(char const * name,
                                    Register::Access const access,
                                    Register::Persistent const is_persistent,
                                    T const & initial_val,
                                    OnWriteRequestFunc on_write_request_func,
                                    OnReadRequestFunc on_read_request_func,
                                    ValueLimiterFunc value_limiter_func)
: RegisterBase{name,
               Register::toTypeTag(initial_val),
               (access == Register::Access::ReadWrite),
               (is_persistent == Register::Persistent::Yes)}
, _val{initial_val}
, _on_write_request_func{on_write_request_func}
, _on_read_request_func{on_read_request_func}
, _value_limiter_func{value_limiter_func}
{ }

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
void RegisterDerived<T>::set(T const & val)
{
  _val = val;
  setTimestamp(micros());
}

template <typename T>
T RegisterDerived<T>::limitValue(T const & val) const
{
  if (_value_limiter_func)
    return _value_limiter_func(val);
  else
    return val;
}
