/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ACCESS_REQUEST_HPP_
#define ACCESS_REQUEST_HPP_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "../../Types.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class AccessRequest
{
public:
  AccessRequest() = delete;
  AccessRequest(AccessRequest const & other) = delete;

  template <typename T>
  static T toRegisterValue(uavcan_register_Value_1_0 const & val);
};

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "AccessRequest.ipp"

#endif /* ACCESS_REQUEST_HPP_ */
