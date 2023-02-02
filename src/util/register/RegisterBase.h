/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_BASE_H_
#define REGISTER_BASE_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "../../DSDL_Types.h"
#include "../vla/vla.h"

#include <functional>

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

namespace Register
{
  enum class Mutable { Yes, No };
  enum class Persistent { Yes, No };
  typedef std::function<uint64_t(void)> MicrosFunc;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RegisterBase
{
public:
  RegisterBase(std::string const &name,
               Register::MicrosFunc const micros)
  : _name{vla::to_Name_1_0(name)}
  , _timestamp{}
  , _micros{micros}
  { }


  inline uavcan::_register::Name_1_0 const &name() const
  { return _name; }

  uavcan::time::SynchronizedTimestamp_1_0 const &timestamp() const
  { return _timestamp; }


protected:
  void updateTimestamp()
  { _timestamp.microsecond = _micros(); }

private:
  uavcan::_register::Name_1_0 _name;
  uavcan::time::SynchronizedTimestamp_1_0 _timestamp;
  Register::MicrosFunc const _micros;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

#endif /* REGISTER_BASE_H_ */
