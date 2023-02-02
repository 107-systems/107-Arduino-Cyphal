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

enum class Access { ReadWrite, ReadOnly };
enum class Persistent { Yes, No };

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
  typedef std::function<uint64_t(void)> MicrosFunc;

  RegisterBase(std::string const &name,
               Access const access,
               Persistent const is_persistent,
               MicrosFunc const micros)
  : _name{vla::to_Name_1_0(name)}
  , _timestamp{}
  , _is_mutable{access == Access::ReadWrite}
  , _is_persistent{is_persistent == Persistent::Yes}
  , _micros{micros}
  { }


  inline uavcan::_register::Name_1_0 const &name() const
  { return _name; }

  uavcan::time::SynchronizedTimestamp_1_0 const &timestamp() const
  { return _timestamp; }

  inline bool isMutable() const
  { return _is_mutable; }

  inline bool isPersistent() const
  { return _is_persistent; }


protected:
  void updateTimestamp()
  { _timestamp.microsecond = _micros(); }

private:
  uavcan::_register::Name_1_0 _name;
  uavcan::time::SynchronizedTimestamp_1_0 _timestamp;
  bool const _is_mutable;
  bool const _is_persistent;
  MicrosFunc const _micros;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

#endif /* REGISTER_BASE_H_ */
