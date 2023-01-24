/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterBase.h"

#undef max
#undef min
#include <algorithm>

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

RegisterBase::RegisterBase(std::string const & name,
                           Register::TypeTag const type_tag,
                           bool const is_mutable,
                           bool const is_persistent)
: _name
{
  [name]() -> uavcan::_register::Name_1_0
  {
    uavcan::_register::Name_1_0 n;
    std::copy_n(name.begin(),
                std::min(name.length(), n.name.capacity()),
                n.name.begin());
    return n;
  } ()
}
, _type_tag{type_tag}
, _is_mutable{is_mutable}
, _is_persistent{is_persistent}
, _timestamp
{
  []() -> uavcan::time::SynchronizedTimestamp_1_0
  {
    uavcan::time::SynchronizedTimestamp_1_0 ts;
    ts.microsecond = 0;
    return ts;
  } ()
}
{

}
