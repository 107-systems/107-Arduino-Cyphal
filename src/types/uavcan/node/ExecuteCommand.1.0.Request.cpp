/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ExecuteCommand.1.0.Request.h"

#include <libcanard/canard_dsdl.h>

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr CanardPortID ExecuteCommand_1_0_Request::PORT_ID;
constexpr size_t       ExecuteCommand_1_0_Request::MAX_PAYLOAD_SIZE;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ExecuteCommand_1_0_Request::ExecuteCommand_1_0_Request(uint16_t const command)
: _command{command}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

size_t ExecuteCommand_1_0_Request::encode(uint8_t * payload) const
{
  canardDSDLSetUxx(payload, 0, _command, 16);

  return 2;
}
