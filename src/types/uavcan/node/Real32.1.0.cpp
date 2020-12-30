/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 generationmake.
 * Author: Bernhard Mayer
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "Real32.1.0.h"

#include "../../../utility/convert.hpp"

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr CanardPortID       Real32_1_0::PORT_ID;
constexpr size_t             Real32_1_0::MAX_PAYLOAD_SIZE;
constexpr CanardTransferKind Real32_1_0::TRANSFER_KIND;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Real32_1_0::Real32_1_0()
{
  data=0;
}

Real32_1_0::Real32_1_0(Real32_1_0 const & other)
{
  memcpy(&data, &other.data, sizeof(data));
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Real32_1_0 Real32_1_0::deserialize(CanardTransfer const & transfer)
{
  Real32_1_0 h;
  size_t inout_buffer_size_bytes = transfer.payload_size;
//  uavcan_node_Real32_1_0_deserialize_(&h.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
  return h;
}

size_t Real32_1_0::serialize(uint8_t * payload) const
{
  size_t inout_buffer_size_bytes = Real32_1_0::MAX_PAYLOAD_SIZE;

//  if (uavcan_node_Real32_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS)
//    return 0;
//  else
    payload[0]=0x12;
    payload[1]=0x34;
    payload[2]=0x56;
    payload[3]=0x78;
    return inout_buffer_size_bytes;
}

