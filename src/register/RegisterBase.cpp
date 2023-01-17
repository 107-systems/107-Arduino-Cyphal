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

#include <cstring>

#undef max
#undef min
#include <algorithm>

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

RegisterBase::RegisterBase(char const * name,
                           Register::TypeTag const type_tag,
                           bool const is_mutable,
                           bool const is_persistent)
: _name
{
  [name]() -> uavcan_register_Name_1_0
  {
    uavcan_register_Name_1_0 n;
    n.name.count = std::min(static_cast<size_t>(strlen(name)), static_cast<size_t>(uavcan_register_Name_1_0_name_ARRAY_CAPACITY_));
    memcpy(n.name.elements, name, n.name.count);
    return n;
  } ()
}
, _type_tag{type_tag}
, _is_mutable{is_mutable}
, _is_persistent{is_persistent}
, _timestamp
{
  []() -> uavcan_time_SynchronizedTimestamp_1_0
  {
    uavcan_time_SynchronizedTimestamp_1_0 ts;
    ts.microsecond = 0;
    return ts;
  } ()
}
{

}
