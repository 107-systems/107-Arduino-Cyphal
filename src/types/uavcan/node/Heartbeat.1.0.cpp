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
  uavcan_node_Heartbeat_1_0_initialize_(&data);
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
  size_t inout_buffer_size_bytes = transfer.payload_size;
  uavcan_node_Heartbeat_1_0_deserialize_(&h.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
  return h;
}

size_t Heartbeat_1_0::encode(uint8_t * payload) const
{
  size_t inout_buffer_size_bytes = Heartbeat_1_0::MAX_PAYLOAD_SIZE;

  if (uavcan_node_Heartbeat_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS)
    return 0;
  else
    return inout_buffer_size_bytes;
}

void Heartbeat_1_0::operator = (Health const health)
{
  data.health.value = arduino::_107_::uavcan::to_integer(health);
}

void Heartbeat_1_0::operator = (Mode const mode)
{
  data.mode.value = arduino::_107_::uavcan::to_integer(mode);
}
