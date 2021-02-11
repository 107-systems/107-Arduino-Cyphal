/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_FILE_PATH_2_0_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_FILE_PATH_2_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/file/Path_2_0.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace file {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Path_2_0
{

public:

  uavcan_file_Path_2_0 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_file_Path_2_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Path_2_0()
  {
    uavcan_file_Path_2_0_initialize_(&data);
  }

  Path_2_0(Path_2_0 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Path_2_0 deserialize(CanardTransfer const & transfer)
  {
    Path_2_0<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_file_Path_2_0_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Path_2_0<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_file_Path_2_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* file */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_FILE_PATH_2_0_HPP_ */
