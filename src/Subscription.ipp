/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#undef max
#undef min
#include <nunavut/support/serialization.hpp>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl {

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template<typename T, typename OnReceiveCb>
Subscription<T, OnReceiveCb>::~Subscription()
{
  _node_hdl.unsubscribe(_port_id, SubscriptionBase::canard_transfer_kind());
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template<typename T, typename OnReceiveCb>
bool Subscription<T, OnReceiveCb>::onTransferReceived(CanardRxTransfer const & transfer)
{
  T msg;
  nunavut::support::const_bitspan msg_bitspan(static_cast<uint8_t *>(transfer.payload), transfer.payload_size);
  auto const rc = deserialize(msg, msg_bitspan);
  if (!rc) return false;

  if constexpr (std::is_invocable_v<OnReceiveCb, T, TransferMetadata>)
  {
    _on_receive_cb(msg, fillMetadata(transfer));
  }
  else
  {
    _on_receive_cb(msg);
  }


  return true;
}

template<typename T, typename OnReceiveCb>
TransferMetadata Subscription<T, OnReceiveCb>::fillMetadata(CanardRxTransfer const & transfer)
{
  TransferMetadata transfer_metadata;
  transfer_metadata.node_id = static_cast<uint16_t>(transfer.metadata.remote_node_id);

  return transfer_metadata;
}
/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
