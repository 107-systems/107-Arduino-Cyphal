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
 * FORWARD DECLARATION
 **************************************************************************************/

class Node;

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
           ServiceBase() { }
  virtual ~ServiceBase() { }
           ServiceBase(ServiceBase const &) = delete;
           ServiceBase(ServiceBase &&) = delete;

  ServiceBase & operator = (ServiceBase const &) = delete;
  ServiceBase & operator = (ServiceBase &&) = delete;

  virtual bool onTransferReceived(CanardRxTransfer const & transfer) = 0;
};

template<typename T_REQ, typename T_RSP, typename OnRequestCb>
class Service : public ServiceBase
{
public:
  Service(Node & node_hdl, CanardPortID const port_id, CanardInstance & canard_hdl, CanardTxQueue & canard_tx_queue, CanardMicrosecond const tx_timeout_usec, CyphalMicrosFunc const micros_func, OnRequestCb on_request_cb)
  : _node_hdl{node_hdl}
  , _port_id{port_id}
  , _canard_hdl{canard_hdl}
  , _canard_tx_queue{canard_tx_queue}
  , _tx_timeout_usec{tx_timeout_usec}
  , _micros_func{micros_func}
  , _on_request_cb{on_request_cb}
  { }
  virtual ~Service();


  virtual bool onTransferReceived(CanardRxTransfer const & transfer) override;


  inline CanardRxSubscription & canard_rx_subscription() { return _canard_rx_sub; }


private:
  Node & _node_hdl;
  CanardPortID const _port_id;
  CanardInstance & _canard_hdl;
  CanardTxQueue & _canard_tx_queue;
  CanardMicrosecond const _tx_timeout_usec;
  CyphalMicrosFunc const _micros_func;
  CanardRxSubscription _canard_rx_sub;
  OnRequestCb _on_request_cb;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

template <typename T_REQ, typename T_RSP, typename OnRequestCb>
using Service = std::shared_ptr<impl::Service<T_REQ, T_RSP, OnRequestCb>>;

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "Service.ipp"

#endif /* INC_107_ARDUINO_CYPHAL_SERVICE_HPP */
