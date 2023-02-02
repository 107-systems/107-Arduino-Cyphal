/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

template <typename T, Register::Mutable IsMutable, Register::Persistent IsPersistent>
std::shared_ptr<impl::RegisterDerived<T, IsMutable, IsPersistent>> RegisterList::create(std::string const &name, T const & val)
{
  auto reg = std::make_shared<impl::RegisterDerived<T, IsMutable, IsPersistent>>(name, val, _micros);
  _reg_list.push_back(reg);
  return reg;
}
