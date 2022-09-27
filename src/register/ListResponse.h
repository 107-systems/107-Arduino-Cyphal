/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef LIST_RESPONSE_H_
#define LIST_RESPONSE_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "../Types.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ListResponse
{
public:
  ListResponse() = delete;
  ListResponse(ListResponse const & other) = delete;

  static uavcan::_register::List_1_0::Response<> create(uavcan_register_Name_1_0 const & name);
};

#endif /* LIST_RESPONSE_H_ */
