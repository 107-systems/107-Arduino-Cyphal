/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <array>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template<typename T>
bool Publisher<T>::publish(T const & msg)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
  CanardTransferMetadata const transfer_metadata =
  {
    .priority       = CanardPriorityNominal,
    .transfer_kind  = CanardTransferKindMessage,
    .port_id        = _port_id,
    .remote_node_id = CANARD_NODE_ID_UNSET,
    .transfer_id    = _transfer_id++,
  };
#pragma GCC diagnostic pop

  /* Serialize message into payload buffer. */
  std::array<uint8_t, T::MAX_PAYLOAD_SIZE> payload_buf{};
  size_t const payload_buf_size = msg.serialize(payload_buf.data());

  /* Serialize transfer into a series of CAN frames */
  return _node_hdl.enqueue_transfer(_tx_timeout_usec,
                                    &transfer_metadata,
                                    payload_buf_size,
                                    payload_buf.data());
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
