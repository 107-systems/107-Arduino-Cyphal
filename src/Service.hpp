/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CYPHAL_SERVICE_HPP
#define INC_107_ARDUINO_CYPHAL_SERVICE_HPP

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <memory>

#include "libcanard/canard.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ServiceBase
{
public:
  virtual ~ServiceBase() { }
  virtual bool onTransferReceived(CanardRxTransfer const & transfer) = 0;
};

template<typename T_REQ, typename T_RSP>
class Service : public ServiceBase
{
public:
  Service(CanardInstance & canard_hdl, CanardTxQueue & canard_tx_queue, CanardMicrosecond const tx_timeout_usec, CyphalMicrosFunc const micros_func, std::function<T_RSP(T_REQ const &)> service_cb, std::function<void(void)> on_destruction_cb)
  : _canard_hdl{canard_hdl}
  , _canard_tx_queue{canard_tx_queue}
  , _tx_timeout_usec{tx_timeout_usec}
  , _micros_func{micros_func}
  , _service_cb{service_cb}
  , _on_destruction_cb{on_destruction_cb}
  { }
  virtual ~Service();


  virtual bool onTransferReceived(CanardRxTransfer const & transfer) override;


  inline CanardRxSubscription & canard_rx_subscription() { return _canard_rx_sub; }


private:
  CanardInstance & _canard_hdl;
  CanardTxQueue & _canard_tx_queue;
  CanardMicrosecond const _tx_timeout_usec;
  CyphalMicrosFunc const _micros_func;
  CanardRxSubscription _canard_rx_sub;
  std::function<T_RSP(T_REQ const &)> _service_cb;
  std::function<void(void)> _on_destruction_cb;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

template <typename T_REQ, typename T_RSP>
using Service = std::shared_ptr<impl::Service<T_REQ, T_RSP>>;

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "Service.ipp"

#endif /* INC_107_ARDUINO_CYPHAL_SERVICE_HPP */
