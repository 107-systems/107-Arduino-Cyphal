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

template <CanardPortID ID> constexpr CanardPortID       ID_1_0<ID>::PORT_ID;
template <CanardPortID ID> constexpr size_t             ID_1_0<ID>::MAX_PAYLOAD_SIZE;
template <CanardPortID ID> constexpr CanardTransferKind ID_1_0<ID>::TRANSFER_KIND;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template <CanardPortID ID>
ID_1_0<ID>::ID_1_0(uint16_t const id)
: _id{id}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <CanardPortID ID>
ID_1_0<ID> ID_1_0<ID>::create(CanardTransfer const & transfer)
{
  uint16_t const id = canardDSDLGetU16(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, 0, 16);
  return ID_1_0<ID>(id);
}

template <CanardPortID ID>
size_t ID_1_0<ID>::encode(uint8_t * payload) const
{
  canardDSDLSetUxx(payload, 0, _id, 16);
  return MAX_PAYLOAD_SIZE;
}
