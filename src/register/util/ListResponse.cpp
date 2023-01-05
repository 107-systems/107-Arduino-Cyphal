/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "ListResponse.h"

#include <cstring>

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

uavcan::_register::List_1_0::Response<> ListResponse::create(uavcan_register_Name_1_0 const & name)
{
  uavcan::_register::List_1_0::Response<> rsp;
  memcpy(&rsp.data.name.name.elements, name.name.elements, name.name.count);
  rsp.data.name.name.count = name.name.count;
  return rsp;
}
