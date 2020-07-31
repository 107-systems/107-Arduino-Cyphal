/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ExecuteCommand.1.0.Response.h"

#include <libcanard/canard_dsdl.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace ExecuteCommand_1_0
{

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr CanardPortID       Response::PORT_ID;
constexpr size_t             Response::MAX_PAYLOAD_SIZE;
constexpr CanardTransferKind Response::TRANSFER_KIND;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Response::Response(Status const status)
: _status{status}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Response Response::create(CanardTransfer const & transfer)
{
  Status const status = static_cast<Status>(canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 0, 8));

  return Response(status);
}

size_t Response::encode(uint8_t * payload) const
{
  /* Encode status */
  canardDSDLSetUxx(payload, 0, static_cast<uint8_t>(_status), 8);

  /* The rest of the payload is empty ... */
  canardDSDLSetUxx(payload, 8, 0, 48);

  return MAX_PAYLOAD_SIZE;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ExecuteCommand_1_0 */
