/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Bernhard Mayer <bernard@generationmake.de>, Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_PRIMITVE_SCALAR_BIT_1_0_H_
#define ARDUINO_TRANSFER_UAVCAN_PRIMITVE_SCALAR_BIT_1_0_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include "Bit_1_0.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Bit_1_0
{

public:

  uavcan_primitive_scalar_Bit_1_0 data;

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_primitive_scalar_Bit_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;

  Bit_1_0()
  {
    uavcan_primitive_scalar_Bit_1_0_initialize_(&data);
  }

  Bit_1_0(Bit_1_0 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Bit_1_0 deserialize(CanardTransfer const & transfer)
  {
    Bit_1_0<ID> b;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_primitive_scalar_Bit_1_0_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return b;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Bit_1_0::MAX_PAYLOAD_SIZE;
    return (uavcan_primitive_scalar_Bit_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

template <CanardPortID ID> constexpr CanardPortID       Bit_1_0<ID>::PORT_ID;
template <CanardPortID ID> constexpr size_t             Bit_1_0<ID>::MAX_PAYLOAD_SIZE;
template <CanardPortID ID> constexpr CanardTransferKind Bit_1_0<ID>::TRANSFER_KIND;

#endif /* ARDUINO_TRANSFER_UAVCAN_PRIMITVE_SCALAR_BIT_1_0_H_ */
