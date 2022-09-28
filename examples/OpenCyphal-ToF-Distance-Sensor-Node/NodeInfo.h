/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef NODE_INFO_H_
#define NODE_INFO_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <107-Arduino-Cyphal.h>

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static const uavcan_node_GetInfo_Response_1_0 NODE_INFO = {
    /* uavcan.node.Version.1.0 protocol_version */
    {1, 0},
    /* uavcan.node.Version.1.0 hardware_version */
    {1, 0},
    /* uavcan.node.Version.1.0 software_version */
    {0, 1},
    /* saturated uint64 software_vcs_revision_id */
    NULL,
    /* saturated uint8[16] unique_id */
    {
      UniqueId[ 0], UniqueId[ 1], UniqueId[ 2], UniqueId[ 3],
      UniqueId[ 4], UniqueId[ 5], UniqueId[ 6], UniqueId[ 7],
      UniqueId[ 8], UniqueId[ 9], UniqueId[10], UniqueId[11],
      UniqueId[12], UniqueId[13], UniqueId[14], UniqueId[15]
    },
    /* saturated uint8[<=50] name */
    {
        "107-systems.tof-sensor-node",
        strlen("107-systems.tof-sensor-node")
    },
};

#endif /* NODE_INFO_H_ */
