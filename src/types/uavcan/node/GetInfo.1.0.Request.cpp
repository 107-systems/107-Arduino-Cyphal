/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "GetInfo.1.0.Request.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace GetInfo_1_0
{

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr CanardPortID       Request::PORT_ID;
constexpr size_t             Request::MAX_PAYLOAD_SIZE;
constexpr CanardTransferKind Request::TRANSFER_KIND;

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* GetInfo_1_0 */
