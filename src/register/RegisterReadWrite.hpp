/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_READ_WRITE_H_
#define REGISTER_READ_WRITE_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterReadOnly.hpp"

#include "util/register_util.hpp"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template<typename T>
class RegisterReadWrite : public RegisterReadOnly<T>
{
public:
  typedef std::function<void(RegisterReadWrite<T> const &)> OnRegisterValueChangeFunc;

  RegisterReadWrite(char const * name,
                    T const & initial_val,
                    OnRegisterValueChangeFunc func)
  : RegisterReadOnly<T>{name, initial_val}
  , _func{func}
  { }
  virtual ~RegisterReadWrite() { }

  virtual uavcan::_register::Access_1_0::Response<> toAccessResponse()
  {
    uavcan::_register::Access_1_0::Response<> rsp = RegisterReadOnly<T>::toAccessResponse();
    rsp.data._mutable = true;
    return rsp;
  }

  inline void set(uavcan_register_Value_1_0 const & val)
  {
    RegisterReadOnly<T>::set(fromRegisterValue<T>(val));
    if (_func)
      _func(*this);
  }

private:
  OnRegisterValueChangeFunc _func;
};

#endif /* REGISTER_READ_WRITE_H_ */

