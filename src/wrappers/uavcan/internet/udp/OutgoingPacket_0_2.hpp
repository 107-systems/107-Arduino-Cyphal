/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_INTERNET_UDP_HANDLEINCOMINGPACKET_0_2_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_INTERNET_UDP_HANDLEINCOMINGPACKET_0_2_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/internet/udp/OutgoingPacket_0_2.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace internet {
namespace udp {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID = uavcan_internet_udp_OutgoingPacket_0_2_FIXED_PORT_ID_>
class OutgoingPacket_0_2
{

public:

  uavcan_internet_udp_OutgoingPacket_0_2 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_internet_udp_OutgoingPacket_0_2_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  OutgoingPacket_0_2()
  {
    uavcan_internet_udp_OutgoingPacket_0_2_initialize_(&data);
  }

  OutgoingPacket_0_2(OutgoingPacket_0_2 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static OutgoingPacket_0_2 deserialize(CanardTransfer const & transfer)
  {
    OutgoingPacket_0_2<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_internet_udp_OutgoingPacket_0_2_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = OutgoingPacket_0_2<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_internet_udp_OutgoingPacket_0_2_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* udp */
} /* internet */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_INTERNET_UDP_HANDLEINCOMINGPACKET_0_2_HPP_ */
