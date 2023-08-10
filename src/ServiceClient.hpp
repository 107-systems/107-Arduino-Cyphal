/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#pragma once

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ServiceClientBase.hpp"

#include "Node.hpp"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace cyphal
{

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template<typename T_REQ, typename T_RSP, typename OnResponseCb>
class ServiceClient final : public ServiceClientBase<T_REQ>
{
public:
  ServiceClient(Node & node_hdl, CanardPortID const response_port_id, CanardMicrosecond const tx_timeout_usec, OnResponseCb on_response_cb)
  : _node_hdl{node_hdl}
  , _response_port_id{response_port_id}
  , _tx_timeout_usec{tx_timeout_usec}
  , _on_response_cb{on_response_cb}
  , _transfer_id{0}
  { }
  virtual ~ServiceClient();


  bool request(CanardNodeID const remote_node_id, T_REQ const & req) override;
  bool onTransferReceived(CanardRxTransfer const & transfer) override;


private:
  Node & _node_hdl;
  CanardPortID const _response_port_id;
  CanardMicrosecond const _tx_timeout_usec;
  OnResponseCb _on_response_cb;
  CanardTransferID _transfer_id;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
} /* cyphal */

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "ServiceClient.ipp"
