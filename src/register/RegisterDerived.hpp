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
#include "RegisterAccess.h"

#include "util/register_util.hpp"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <typename T>
class RegisterDerived : public RegisterBase
{
public:
  typedef std::function<void(RegisterDerived<T> const &)> OnRegisterValueChangeFunc;

  RegisterDerived(char const * name,
                  Register::Access const access,
                  T const & initial_val,
                  OnRegisterValueChangeFunc func)
  : RegisterBase{name, Register::toTypeTag(initial_val)}
  , _access{access}
  , _val{initial_val}
  , _func{func}
  { }

  T get() const { return _val; }
  void set(uavcan_register_Value_1_0 const & val)
  {
    if (_access == Register::Access::ReadOnly)
      return;
    
    _val = fromRegisterValue<T>(val);
    if (_func)
      _func(*this);
  }

  uavcan::_register::Access_1_0::Response<> toAccessResponse()
  {
    uavcan::_register::Access_1_0::Response<> rsp;

    rsp.data.value = toRegisterValue(_val);
    rsp.data.timestamp.microsecond = micros();
    rsp.data._mutable = (_access == Register::Access::ReadOnly) ? false : true;
    rsp.data.persistent = false;

    return rsp;
  }

private:
  T _val;
  Register::Access const _access;
  OnRegisterValueChangeFunc _func;
};

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef RegisterDerived<uint8_t>     RegisterNatural8;
typedef RegisterDerived<uint16_t>    RegisterNatural16;
typedef RegisterDerived<std::string> RegisterString;

#endif /* REGISTER_READ_ONLY_H_ */
