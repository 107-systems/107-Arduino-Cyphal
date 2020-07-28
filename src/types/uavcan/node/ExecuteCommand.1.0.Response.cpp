/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ExecuteCommand.1.0.Response.h"

#include <libcanard/canard_dsdl.h>

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr CanardPortID ExecuteCommand_1_0_Response::PORT_ID;
constexpr size_t       ExecuteCommand_1_0_Response::MAX_PAYLOAD_SIZE;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ExecuteCommand_1_0_Response::ExecuteCommand_1_0_Response(Status const status)
: _status{status}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

ExecuteCommand_1_0_Response ExecuteCommand_1_0_Response::create(CanardTransfer const & transfer)
{
  Status const status = static_cast<Status>(canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 0, 8));

  return ExecuteCommand_1_0_Response(status);
}
