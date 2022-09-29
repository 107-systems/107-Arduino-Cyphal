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
      OpenCyphalUniqueId[ 0], OpenCyphalUniqueId[ 1], OpenCyphalUniqueId[ 2], OpenCyphalUniqueId[ 3],
      OpenCyphalUniqueId[ 4], OpenCyphalUniqueId[ 5], OpenCyphalUniqueId[ 6], OpenCyphalUniqueId[ 7],
      OpenCyphalUniqueId[ 8], OpenCyphalUniqueId[ 9], OpenCyphalUniqueId[10], OpenCyphalUniqueId[11],
      OpenCyphalUniqueId[12], OpenCyphalUniqueId[13], OpenCyphalUniqueId[14], OpenCyphalUniqueId[15]
    },
    /* saturated uint8[<=50] name */
    {
        "107-systems.tof-sensor-node",
        strlen("107-systems.tof-sensor-node")
    },
};

#endif /* NODE_INFO_H_ */
