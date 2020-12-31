/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 generationmake.
 * Author: Bernhard Mayer
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_PRIMITVE_SCALAR_BIT_1_0_H_
#define ARDUINO_TRANSFER_UAVCAN_PRIMITVE_SCALAR_BIT_1_0_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include "Bit_1_0.nnvg.h"

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

  Bit_1_0();
  Bit_1_0(Bit_1_0 const & other);

  static Bit_1_0 deserialize(CanardTransfer const & transfer);
  size_t serialize(uint8_t * payload) const;

};

/**************************************************************************************
 * TEMPLATE SOURCE FILE
 **************************************************************************************/

#include "Bit.1.0.ipp"

#endif /* ARDUINO_TRANSFER_UAVCAN_PRIMITVE_SCALAR_BIT_1_0_H_ */
