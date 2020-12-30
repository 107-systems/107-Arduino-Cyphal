/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 generationmake.
 * Author: Bernhard Mayer
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "Bit.1.0.h"

#include "../../../utility/convert.hpp"

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr CanardPortID       Bit_1_0::PORT_ID;
constexpr size_t             Bit_1_0::MAX_PAYLOAD_SIZE;
constexpr CanardTransferKind Bit_1_0::TRANSFER_KIND;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Bit_1_0::Bit_1_0()
{
  Bit_1_0::data=false;
}

Bit_1_0::Bit_1_0(Bit_1_0 const & other)
{
  memcpy(&data, &other.data, sizeof(data));
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Bit_1_0 Bit_1_0::deserialize(CanardTransfer const & transfer)
{
  Bit_1_0 h;
  size_t inout_buffer_size_bytes = transfer.payload_size;
  uint8_t * x=(uint8_t *)(transfer.payload);
//  uavcan_node_Real32_1_0_deserialize_(&h.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
//  if((uint8_t &)(transfer.payload)==0x01) h.data=true;
//  if((uint8_t)(transfer.payload)==0x01) h.data=true;
  if(*x==0x01) h.data=true;
  else h.data=false;
  return h;
}

size_t Bit_1_0::serialize(uint8_t * payload) const
{
  size_t inout_buffer_size_bytes = Bit_1_0::MAX_PAYLOAD_SIZE;

//  if (uavcan_node_Real32_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS)
//    return 0;
//  else
    if(data==true) payload[0]=0x01;
    else payload[0]=0x00;
    return inout_buffer_size_bytes;
}

