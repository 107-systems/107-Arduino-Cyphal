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

#include <memory>

#include "SubscriptionBase.h"

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

template <typename T_REQ>
class ServiceClientBase : public SubscriptionBase
{
public:
  ServiceClientBase() : SubscriptionBase{CanardTransferKindResponse} { }
  virtual ~ServiceClientBase() { }
  virtual bool request(CanardNodeID const remote_node_id, T_REQ const & req) = 0;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

template <typename T_REQ>
using ServiceClient = std::shared_ptr<impl::ServiceClientBase<T_REQ>>;

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* cyphal */
