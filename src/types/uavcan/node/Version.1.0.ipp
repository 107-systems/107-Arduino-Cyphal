/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

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
: data{major, minor}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <CanardPortID ID>
Version_1_0<ID> Version_1_0<ID>::create(CanardTransfer const & transfer)
{
  uavcan_node_Version_1_0 d;
  uavcan_node_Version_1_0_init(&d);
  uavcan_node_Version_1_0_deserialize(&d, 0, (uint8_t *)(transfer.payload), transfer.payload_size);
  return Version_1_0<ID>(d.major, d.minor);
}

template <CanardPortID ID>
size_t Version_1_0<ID>::encode(uint8_t * payload) const
{
  size_t const offset = uavcan_node_Version_1_0_serialize(&data, 0, payload);
  return (offset / 8);
}
