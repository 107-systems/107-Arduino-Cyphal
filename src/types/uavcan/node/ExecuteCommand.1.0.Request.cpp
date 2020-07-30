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
 * NAMESPACE
 **************************************************************************************/

namespace ExecuteCommand_1_0
{

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

constexpr CanardPortID       Request::PORT_ID;
constexpr size_t             Request::MAX_PAYLOAD_SIZE;
constexpr CanardTransferKind Request::TRANSFER_KIND;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Request::Request(uint16_t const command, uint8_t const * param, size_t const param_len)
: _command{command}
, _param{0}
, _param_len{std::min(param_len, 112UL)}
{
  std::copy(param, param + param_len, _param);
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Request Request::create(CanardTransfer const & transfer)
{
  uint16_t const command   = canardDSDLGetU16(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size,  0, 16);
  uint8_t  const param_len = canardDSDLGetU8 (reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 16,  8);
  
  uint8_t param[112];
  for(uint8_t b = 0; b < param_len; b++)
    param[b] = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 16 + 8 + (b*8),  8);

  return Request(command, param, param_len);
}

size_t Request::encode(uint8_t * payload) const
{
  /* Encode command */
  canardDSDLSetUxx(payload, 0, _command, 16);

  /* Encode payload length */
  canardDSDLSetUxx(payload, 16, _param_len, 8);

  /* Encode parameter */
  size_t off_bit_cnt = 0;
  std::for_each(_param,
                _param + _param_len,
                [&payload, &off_bit_cnt](uint8_t const elem)
                {
                  size_t const off_bit = 16 /* _command */ + 8 /* _param_len */ + off_bit_cnt;
                  canardDSDLSetUxx(payload, off_bit, elem, 8);
                  off_bit_cnt += 8;
                });

  return (2 + 1 + (off_bit_cnt / 8));
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* ExecuteCommand_1_0 */
