/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_DERIVED_HPP_
#define REGISTER_DERIVED_HPP_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterBase.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template<typename T>
class Register : public RegisterBase
{
public:
  Register(std::string const &name,
           Access const access,
           Persistent const is_persistent,
           T const & val,
           RegisterBase::MicrosFunc const micros)
  : RegisterBase{name, access, is_persistent, micros}
  , _val{val}
  { }


  T get() const
  { return _val; }

  void set(T const &val)
  { _val = val; updateTimestamp(); }

private:
  T _val;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

#endif /* REGISTER_DERIVED_HPP_ */
