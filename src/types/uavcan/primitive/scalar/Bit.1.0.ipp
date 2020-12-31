/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 generationmake.
 * Author: Bernhard Mayer
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * STATIC CONSTEXPR DEFINITION
 **************************************************************************************/

template <CanardPortID ID> constexpr CanardPortID       Bit_1_0<ID>::PORT_ID;
template <CanardPortID ID> constexpr size_t             Bit_1_0<ID>::MAX_PAYLOAD_SIZE;
template <CanardPortID ID> constexpr CanardTransferKind Bit_1_0<ID>::TRANSFER_KIND;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template <CanardPortID ID>
Bit_1_0<ID>::Bit_1_0()
{
  uavcan_primitive_scalar_Bit_1_0_initialize_(&data);
}

template <CanardPortID ID>
Bit_1_0<ID>::Bit_1_0(Bit_1_0 const & other)
{
  memcpy(&data, &other.data, sizeof(data));
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <CanardPortID ID>
Bit_1_0<ID> Bit_1_0<ID>::deserialize(CanardTransfer const & transfer)
{
  Bit_1_0<ID> b;
  size_t inout_buffer_size_bytes = transfer.payload_size;
  uavcan_primitive_scalar_Bit_1_0_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
  return b;
}

template <CanardPortID ID>
size_t Bit_1_0<ID>::serialize(uint8_t * payload) const
{
  size_t inout_buffer_size_bytes = Bit_1_0::MAX_PAYLOAD_SIZE;

  if (uavcan_primitive_scalar_Bit_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS)
    return 0;
  else
    return inout_buffer_size_bytes;
}
