/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard_dsdl.h>

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

template <CanardPortID ID> constexpr CanardPortID       Version_1_0<ID>::PORT_ID;
template <CanardPortID ID> constexpr size_t             Version_1_0<ID>::MAX_PAYLOAD_SIZE;
template <CanardPortID ID> constexpr CanardTransferKind Version_1_0<ID>::TRANSFER_KIND;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template <CanardPortID ID>
Version_1_0<ID>::Version_1_0(uint8_t const major, uint8_t const minor)
: _major(major)
, _minor(minor)
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <CanardPortID ID>
Version_1_0<ID> Version_1_0<ID>::create(CanardTransfer const & transfer)
{
  uint8_t const major = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 0, 8);
  uint8_t const minor = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 8, 8);
  return Version_1_0<ID>(major, minor);
}

template <CanardPortID ID>
size_t Version_1_0<ID>::encode(uint8_t * payload) const
{
  canardDSDLSetUxx(payload, 0, _major, 8);
  canardDSDLSetUxx(payload, 8, _minor, 8);
  return MAX_PAYLOAD_SIZE;
}
