/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ACCESS_RESPONSE_H_
#define ACCESS_RESPONSE_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "../RegisterDerived.hpp"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class AccessResponse
{
public:
  AccessResponse() = delete;
  AccessResponse(AccessResponse const & other) = delete;

  template <typename T>
  static uavcan::_register::Access::Response_1_0 create(RegisterDerived<T> const & reg);
};

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "AccessResponse.ipp"

#endif /* ACCESS_RESPONSE_H_ */
