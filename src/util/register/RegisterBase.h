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
               Register::Mutable const is_mutable,
               Register::Persistent const is_persistent)
  : _name{vla::to_Name_1_0(name)}
  , _is_mutable{is_mutable == Register::Mutable::Yes}
  , _is_persistent{is_persistent == Register::Persistent::Yes}
  , _timestamp{}
  , _value{}
  { }


  uavcan::_register::Name_1_0 const &name() const
  { return _name; }

  bool isMutable() const
  { return _is_mutable; }

  bool isPersistent() const
  { return _is_persistent; }

  uavcan::time::SynchronizedTimestamp_1_0 const &timestamp() const
  { return _timestamp; }

  uavcan::_register::Value_1_0 const &value() const
  { return _value; }


  virtual void read() = 0;


private:
  uavcan::_register::Name_1_0 const _name;
  bool const _is_mutable;
  bool const _is_persistent;

protected:
  uavcan::time::SynchronizedTimestamp_1_0 _timestamp;
  uavcan::_register::Value_1_0 _value;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

#endif /* REGISTER_BASE_H_ */
