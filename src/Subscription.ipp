/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
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

template<typename T, typename OnReceiveCb, typename OnDestructionCb>
Subscription<T, OnReceiveCb, OnDestructionCb>::~Subscription()
{
  _on_destruction_cb();
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template<typename T, typename OnReceiveCb, typename OnDestructionCb>
void Subscription<T, OnReceiveCb, OnDestructionCb>::onTransferReceived(CanardRxTransfer const & transfer)
{
  T const msg = T::deserialize(transfer);

  if (_on_receive_cb)
    _on_receive_cb(msg);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
