/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "Heartbeat.1.0.h"

#include "../../../utility/convert.hpp"

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr CanardPortID       Heartbeat_1_0::PORT_ID;
constexpr size_t             Heartbeat_1_0::MAX_PAYLOAD_SIZE;
constexpr CanardTransferKind Heartbeat_1_0::TRANSFER_KIND;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Heartbeat_1_0::Heartbeat_1_0(uint32_t const uptime, uint8_t const health, uint8_t const mode, uint32_t const vssc)
: data{uptime, health, mode, vssc}
{

}

Heartbeat_1_0::Heartbeat_1_0(uint32_t const uptime, Health const health, Mode const mode, uint32_t const vssc)
: Heartbeat_1_0{uptime, to_integer(health), to_integer(mode), vssc}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Heartbeat_1_0 Heartbeat_1_0::create(CanardTransfer const & transfer)
{
  uavcan_node_Heartbeat_1_0 d;
  uavcan_node_Heartbeat_1_0_init(&d);
  uavcan_node_Heartbeat_1_0_deserialize(&d, 0, (uint8_t *)(transfer.payload), transfer.payload_size);
  return Heartbeat_1_0(d.uptime, d.health, d.mode, d.vendor_specific_status_code);
}

size_t Heartbeat_1_0::encode(uint8_t * payload) const
{
  size_t const offset = uavcan_node_Heartbeat_1_0_serialize(&data, 0, payload);
  return (offset / 8);
}
