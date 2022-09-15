/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_H_
#define REGISTER_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <107-Arduino-Cyphal.h>

/**************************************************************************************
 * DEFINES
 **************************************************************************************/

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static const uavcan_register_List_Response_1_0 register_list1 = {
    {  "uavcan.node.id", strlen("uavcan.node.id")  },
};
static const uavcan_register_List_Response_1_0 register_list2 = {
    {  "uavcan.node.description", strlen("uavcan.node.description")  },
};
static const uavcan_register_List_Response_1_0 register_list_last = {
    {  "", 0  },
};

static const uavcan_register_List_Response_1_0 REGISTER_LIST_ARRAY[] =
{
  register_list1,
  register_list2,
  register_list_last
};
static size_t const REGISTER_LIST_ARRAY_SIZE = sizeof(REGISTER_LIST_ARRAY) / sizeof(REGISTER_LIST_ARRAY[0]);

#endif /* REGISTER_H_ */
