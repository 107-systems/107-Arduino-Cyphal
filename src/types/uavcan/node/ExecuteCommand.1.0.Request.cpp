/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ExecuteCommand.1.0.Request.h"

#include <libcanard/canard_dsdl.h>

#undef max
#undef min
#include <algorithm>

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr CanardPortID ExecuteCommand_1_0_Request::PORT_ID;
constexpr size_t       ExecuteCommand_1_0_Request::MAX_PAYLOAD_SIZE;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ExecuteCommand_1_0_Request::ExecuteCommand_1_0_Request(uint16_t const command, uint8_t const * param, size_t const param_len)
: _command{command}
, _param{0}
, _param_len{std::min(param_len, 112UL)}
{
  std::copy(param, param + param_len, _param);
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

size_t ExecuteCommand_1_0_Request::encode(uint8_t * payload) const
{
  /* Encode command */
  canardDSDLSetUxx(payload, 0, _command, 16);

  /* Encode payload. */
  size_t off_bit_cnt = 0;
  std::for_each(_param,
                _param + _param_len,
                [&payload, &off_bit_cnt](uint8_t const elem)
                {
                  size_t const off_bit = 16 /* _command */ + off_bit_cnt;
                  canardDSDLSetUxx(payload, off_bit, elem, 8);
                  off_bit_cnt += 8;
                });

  return (2 + (off_bit_cnt / 8));
}
