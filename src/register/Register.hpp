/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_READ_ONLY_H_
#define REGISTER_READ_ONLY_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterBase.h"

#include "util/register_util.hpp"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <typename T>
class Register : RegisterBase
{
public:
  typedef std::function<void(Register<T> const &)> OnRegisterValueChangeFunc;

  Register(char const * name,
           AccessType const access_type,
           T const & initial_val,
           OnRegisterValueChangeFunc func)
  : RegisterBase{name, access_type}
  , _val{initial_val}
  , _func{func}
  { }
  virtual ~Register() { }

  T get() const { return _val; }
  void set(uavcan_register_Value_1_0 const & val)
  {
    if (type() == AccessType::ReadOnly)
      return;
    
    _val = fromRegisterValue<T>(val);
    if (_func)
      _func(*this);
  }

  virtual uavcan::_register::Access_1_0::Response<> toAccessResponse()
  {
    uavcan::_register::Access_1_0::Response<> rsp;

    rsp.data.value = toRegisterValue(_val);
    rsp.data.timestamp.microsecond = micros();
    rsp.data._mutable = (type() == AccessType::ReadOnly) ? false : true;
    rsp.data.persistent = false;

    return rsp;
  }

private:
  T _val;
  OnRegisterValueChangeFunc _func;
};

#endif /* REGISTER_READ_ONLY_H_ */
