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
class RegisterReadOnly : RegisterBase
{
public:

  RegisterReadOnly(char const * name,
                   T const & initial_val)
  : RegisterBase{name}
  , _val{initial_val}
  { }
  virtual ~RegisterReadOnly() { }

  inline T get() const { return _val; }

  virtual uavcan::_register::Access_1_0::Response<> toAccessResponse()
  {
    uavcan::_register::Access_1_0::Response<> rsp;

    rsp.data.value = toRegisterValue(_val);
    rsp.data.timestamp.microsecond = micros();
    rsp.data._mutable = false;
    rsp.data.persistent = false;

    return rsp;
  }

protected:
  inline void set(T const & val) { _val = val; }

private:
  T _val;
};

#endif /* REGISTER_READ_ONLY_H_ */
