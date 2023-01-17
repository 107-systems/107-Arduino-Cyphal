/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CYPHAL_SERVICE_SERVER_BASE_HPP
#define INC_107_ARDUINO_CYPHAL_SERVICE_SERVER_BASE_HPP

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <memory>

#include "SubscriptionBase.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ServiceServerBase : public SubscriptionBase
{
public:
  ServiceServerBase() : SubscriptionBase{CanardTransferKindRequest} { }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

using ServiceServer = std::shared_ptr<impl::ServiceServerBase>;

#endif /* INC_107_ARDUINO_CYPHAL_SERVICE_SERVER_BASE_HPP */
