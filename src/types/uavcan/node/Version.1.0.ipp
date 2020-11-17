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
Version_1_0<ID>::Version_1_0()
{
  uavcan_node_Version_1_0_initialize_(&data);
}

template <CanardPortID ID>
Version_1_0<ID>::Version_1_0(Version_1_0 const & other)
{
  memcpy(&data, &other.data, sizeof(data));
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <CanardPortID ID>
Version_1_0<ID> Version_1_0<ID>::deserialize(CanardTransfer const & transfer)
{
  Version_1_0<ID> v;
  size_t inout_buffer_size_bytes = transfer.payload_size;
  uavcan_node_Version_1_0_deserialize_(&v.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
  return v;
}

template <CanardPortID ID>
size_t Version_1_0<ID>::encode(uint8_t * payload) const
{
  size_t inout_buffer_size_bytes = Version_1_0<ID>::MAX_PAYLOAD_SIZE;

  if (uavcan_node_Version_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS)
    return 0;
  else
    return inout_buffer_size_bytes;
}
