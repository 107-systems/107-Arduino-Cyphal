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

#include <memory>

#include <libcanard/canard.h>

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

class PortListPublisherBase
{
public:
  PortListPublisherBase() = default;
  virtual ~PortListPublisherBase() { }
  PortListPublisherBase(PortListPublisherBase const &) = delete;
  PortListPublisherBase(PortListPublisherBase &&) = delete;
  PortListPublisherBase &operator=(PortListPublisherBase const &) = delete;
  PortListPublisherBase &operator=(PortListPublisherBase &&) = delete;

  virtual void update() = 0;
  virtual void add_publisher(CanardPortID const port_id) = 0;
  virtual void add_subscriber(CanardPortID const port_id) = 0;
  virtual void add_service_server(CanardPortID const request_port_id) = 0;
  virtual void add_service_client(CanardPortID const response_port_id) = 0;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

using PortListPublisher = std::shared_ptr<impl::PortListPublisherBase>;

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* cyphal */
