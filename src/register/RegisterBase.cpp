/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterBase.h"

#include <algorithm>

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

RegisterBase::RegisterBase(char const * name, Register::TypeTag const type_tag)
: _name
{
  [name]() -> uavcan_register_Name_1_0
  {
    uavcan_register_Name_1_0 n;
    n.name.count = std::min(strlen(name), uavcan_register_Name_1_0_name_ARRAY_CAPACITY_);
    memcpy(n.name.elements, name, n.name.count);
    return n;
  } ()
}
, _type_tag{type_tag}
{ }
