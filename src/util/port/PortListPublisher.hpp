/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#pragma once

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "PortListPublisherBase.hpp"

#include "../../Node.hpp"
#include "../../DSDL_Types.h"

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

class PortListPublisher final : public PortListPublisherBase
{
public:
  PortListPublisher(Node &node_hdl, cyphal::Node::MicrosFunc const micros_func)
    : _pub{node_hdl.create_publisher<uavcan::node::port::List_1_0>(1 * 1000 * 1000UL /* = 1 sec in usecs. */)},
      _micros_func{micros_func}, _prev_pub{0}, _list_msg{}
  {
    _list_msg.publishers.set_sparse_list();
    _list_msg.subscribers.set_sparse_list();

    /* This one won't be able automatically, as the object does not exist yet when
     * this objects publisher is created.
     */
    add_publisher(uavcan::node::port::List_1_0::_traits_::FixedPortId);
  }

  virtual ~PortListPublisher()
  {}

  virtual void update() override
  {
    static CanardMicrosecond const MAX_PUBLICATION_PERIOD_us =
      uavcan::node::port::List_1_0::MAX_PUBLICATION_PERIOD * 1000 * 1000UL;
    auto const now = _micros_func();
    if ((now - _prev_pub) > MAX_PUBLICATION_PERIOD_us)
    {
      _prev_pub = now;
      _pub->publish(_list_msg);
    }
  }

  virtual void add_publisher(CanardPortID const port_id) override
  {
    auto sparse_list = _list_msg.publishers.get_sparse_list();
    sparse_list.push_back(uavcan::node::port::SubjectID_1_0{port_id});
    _list_msg.publishers.set_sparse_list(sparse_list);
  }

  virtual void add_subscriber(CanardPortID const port_id) override
  {
    auto sparse_list = _list_msg.subscribers.get_sparse_list();
    sparse_list.push_back(uavcan::node::port::SubjectID_1_0{port_id});
    _list_msg.subscribers.set_sparse_list(sparse_list);
  }

  virtual void add_service_server(CanardPortID const request_port_id) override
  {
    _list_msg.servers.mask.set(request_port_id);
  }

  virtual void add_service_client(CanardPortID const response_port_id) override
  {
    _list_msg.clients.mask.set(response_port_id);
  }

private:
  cyphal::Publisher<uavcan::node::port::List_1_0> _pub;
  cyphal::Node::MicrosFunc const _micros_func;
  CanardMicrosecond _prev_pub;
  uavcan::node::port::List_1_0 _list_msg;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
} /* cyphal */
