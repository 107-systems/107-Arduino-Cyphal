/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <types/uavcan/node/Heartbeat_1_0.h>

/**************************************************************************************
 * PARTIAL TEMPLATE SPECIALISATION
 **************************************************************************************/

template<> inline void   func_initialize <uavcan_node_Heartbeat_1_0>(uavcan_node_Heartbeat_1_0 * const obj) { uavcan_node_Heartbeat_1_0_initialize_(obj); }
template<> inline int8_t func_serialize  <uavcan_node_Heartbeat_1_0>(const uavcan_node_Heartbeat_1_0 * const obj, uint8_t * const buffer, size_t * const inout_buffer_size_bytes) { return uavcan_node_Heartbeat_1_0_serialize_(obj, buffer, inout_buffer_size_bytes); }
template<> inline int8_t func_deserialize<uavcan_node_Heartbeat_1_0>(uavcan_node_Heartbeat_1_0 * const obj, const uint8_t * const buffer, size_t * const inout_buffer_size_bytes) { return uavcan_node_Heartbeat_1_0_deserialize_(obj, buffer, inout_buffer_size_bytes); }
