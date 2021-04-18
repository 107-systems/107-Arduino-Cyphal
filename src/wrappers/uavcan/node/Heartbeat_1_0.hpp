/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_HPP_
#define ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <wrappers/DSDLBaseType.hpp>

#include <types/uavcan/node/Heartbeat_1_0.h>

#include <utility/convert.hpp>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace node {

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef DSDLBaseType<uavcan_node_Heartbeat_1_0, uavcan_node_Heartbeat_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_, CanardTransferKindMessage> Heartbeat_1_0;

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* uavcan */
} /* node */

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_HEARTBEAT_1_0_HPP_ */
