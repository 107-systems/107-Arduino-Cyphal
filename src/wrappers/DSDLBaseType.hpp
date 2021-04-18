/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_DSDL_BASE_TYPE_HPP_
#define ARDUINO_UAVCAN_DSDL_BASE_TYPE_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

template<typename T> void   func_initialize (T * const obj);
template<typename T> int8_t func_serialize  (const T * const obj, uint8_t * const buffer, size_t * const inout_buffer_size_bytes);
template<typename T> int8_t func_deserialize(T * const obj, const uint8_t * const buffer, size_t * const inout_buffer_size_bytes);

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template<typename T, size_t MAX_PAYLOAD_SIZE_, CanardTransferKind TRANSFER_KIND_>
class DSDLBaseType
{

public:

  T data;


  static constexpr size_t             MAX_PAYLOAD_SIZE = MAX_PAYLOAD_SIZE_;
  static constexpr CanardTransferKind TRANSFER_KIND    = TRANSFER_KIND_;


  DSDLBaseType(CanardPortID const port_id) : _port_id{port_id}
  {
    func_initialize(&data);
  }

  DSDLBaseType(DSDLBaseType const & other)
  {
    _port_id = other.port_id();
    memcpy(&data, &other.data, sizeof(data));
  }


  static DSDLBaseType<T, MAX_PAYLOAD_SIZE_, TRANSFER_KIND_> deserialize(CanardTransfer const & transfer)
  {
    DSDLBaseType<T, MAX_PAYLOAD_SIZE_, TRANSFER_KIND_> dsdl_type(transfer.port_id);
    size_t inout_buffer_size_bytes = transfer.payload_size;
    func_deserialize((T * const)&dsdl_type.data, (uint8_t * const)transfer.payload, (size_t * const)&inout_buffer_size_bytes);
    return dsdl_type;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = MAX_PAYLOAD_SIZE;
    return (func_serialize((const T * const)&data, (uint8_t * const)payload, (size_t * const)&inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }

  CanardPortID port_id() const
  {
    return _port_id;
  }


private:

  CanardPortID _port_id;

};

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "DSDLBaseType.ipp"

#endif /* ARDUINO_UAVCAN_DSDL_BASE_TYPE_HPP_ */
