/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CYPHAL_LIST_BASE_HPP
#define INC_107_ARDUINO_CYPHAL_LIST_BASE_HPP

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <memory>

#include <libcanard/canard.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class PortListPublisherBase
{
public:
  virtual ~PortListPublisherBase() { }
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

#endif /* INC_107_ARDUINO_CYPHAL_LIST_BASE_HPP */
