/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

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
  T const msg = T::deserialize(transfer);

  if (_on_receive_cb)
    _on_receive_cb(msg);

  return true;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
