/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_DIAGNOSTIC_RECORD_1_1_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_DIAGNOSTIC_RECORD_1_1_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/diagnostic/Record_1_1.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace diagnostic {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID = uavcan_diagnostic_Record_1_1_FIXED_PORT_ID_>
class Record_1_1
{

public:

  uavcan_diagnostic_Record_1_1 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_diagnostic_Record_1_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Record_1_1()
  {
    uavcan_diagnostic_Record_1_1_initialize_(&data);
  }

  Record_1_1(Record_1_1 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Record_1_1 deserialize(CanardTransfer const & transfer)
  {
    Record_1_1<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_diagnostic_Record_1_1_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Record_1_1<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_diagnostic_Record_1_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* diagnostic */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_DIAGNOSTIC_RECORD_1_1_HPP_ */
