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

Heartbeat_1_0::Heartbeat_1_0()
{
  uavcan_node_Heartbeat_1_0_init(&data);
}

Heartbeat_1_0::Heartbeat_1_0(Heartbeat_1_0 const & other)
{
  memcpy(&data, &other.data, sizeof(data));
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Heartbeat_1_0 Heartbeat_1_0::create(CanardTransfer const & transfer)
{
  Heartbeat_1_0 h;
  uavcan_node_Heartbeat_1_0_deserialize(&h.data, 0, (uint8_t *)(transfer.payload), transfer.payload_size);
  return h;
}

size_t Heartbeat_1_0::encode(uint8_t * payload) const
{
  size_t const offset = uavcan_node_Heartbeat_1_0_serialize(&data, 0, payload);
  return (offset / 8);
}

void Heartbeat_1_0::operator = (Health const health)
{
  data.health = to_integer(health);
}

void Heartbeat_1_0::operator = (Mode const mode)
{
  data.mode = to_integer(mode);
}
