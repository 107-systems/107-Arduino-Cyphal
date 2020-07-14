/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "Heartbeat.1.0.h"

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Heartbeat_1_0::Heartbeat_1_0(uint32_t const uptime, Health const health, Mode const mode, uint32_t const vssc)
: _uptime{uptime}
, _health{health}
, _mode{mode}
, _vssc{vssc}
, _payload{0}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Heartbeat_1_0 Heartbeat_1_0::create(CanardTransfer const & transfer)
{
  Mode     const mode   = static_cast<Mode>  (canardDSDLGetU8 (reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 34,  3));
  uint32_t const uptime =                     canardDSDLGetU32(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size,  0, 32);
  Health   const health = static_cast<Health>(canardDSDLGetU8 (reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 32,  2));
  uint32_t const vssc   =                     canardDSDLGetU32(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 37, 19);

  return Heartbeat_1_0(uptime, health, mode, vssc);
}

void Heartbeat_1_0::encode(size_t * payload_size, void ** payload)
{
  canardDSDLSetUxx(_payload, 34, static_cast<uint8_t>(_mode),    3);
  canardDSDLSetUxx(_payload,  0,                      _uptime,  32);
  canardDSDLSetUxx(_payload, 37,                      _vssc,    19);
  canardDSDLSetUxx(_payload, 32, static_cast<uint8_t>(_health),  2);

  *payload_size = PAYLOAD_SIZE;
  *payload = &_payload;
}
