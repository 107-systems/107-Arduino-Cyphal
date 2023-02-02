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

template<typename T, Register::Mutable IsMutable, Register::Persistent IsPersistent>
class RegisterDerived : public RegisterBase
{
public:
  static bool constexpr is_mutable    = (IsMutable == Register::Mutable::Yes);
  static bool constexpr is_persistent = (IsPersistent == Register::Persistent::Yes);


  RegisterDerived(std::string const &name,
                  T const & val,
                  Register::MicrosFunc const micros)
  : RegisterBase{name, micros}
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
