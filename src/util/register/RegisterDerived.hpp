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
class RegisterDerivedReadOnly : public RegisterBase
{
public:
  RegisterDerivedReadOnly(std::string const &name,
                          std::function<T()> const read_func,
                          Register::MicrosFunc const micros)
  : RegisterBase{name, Register::Mutable::No, Register::Persistent::No}
  , _read_func{read_func}
  , _micros{micros}
  { }
  virtual ~RegisterDerivedReadOnly() { }

  void read() override
  {
    _value.set(_read_func());
    _timestamp.microsecond = _micros();
  }

  [[nodiscard]] std::optional<T> get() const
  {
    return _value.get<T>();
  }

private:
  std::function<T()> const _read_func;
  Register::MicrosFunc const _micros;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

#endif /* REGISTER_DERIVED_HPP_ */
