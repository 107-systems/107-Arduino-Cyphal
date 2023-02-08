/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

template <typename T>
std::shared_ptr<impl::RegisterDerivedReadOnly<T>> RegisterList::create_ro(std::string const &name,
                                                                          std::function<T()> const read_func)
{
  auto reg = std::make_shared<impl::RegisterDerivedReadOnly<T>>(name, read_func, _micros);

  _reg_list.push_back(reg);
  _reg_map.emplace(name, reg);

  return reg;
}
