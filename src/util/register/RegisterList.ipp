/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

template <typename T>
std::shared_ptr<impl::Register<T>> RegisterList::create(std::string const &name,
                                                        Access const access,
                                                        Persistent const is_persistent,
                                                        T const & val)
{
  auto reg = std::make_shared<impl::Register<T>>(name, access, is_persistent, val, _micros);
  _reg_list.push_back(reg);
  return reg;
}
