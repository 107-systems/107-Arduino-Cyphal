/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_REG_DRONE_SERVICE_ACTUATOR_COMMON_SP_VECTOR3_0_1_HPP_
#define ARDUINO_UAVCAN_TYPES_REG_DRONE_SERVICE_ACTUATOR_COMMON_SP_VECTOR3_0_1_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/reg/drone/service/actuator/common/sp/Vector3_0_1.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace reg {
namespace drone {
namespace service {
namespace actuator {
namespace common {
namespace sp {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Vector3_0_1
{

public:

  reg_drone_service_actuator_common_sp_Vector3_0_1 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = reg_drone_service_actuator_common_sp_Vector3_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;


  Vector3_0_1()
  {
    reg_drone_service_actuator_common_sp_Vector3_0_1_initialize_(&data);
  }

  Vector3_0_1(Vector3_0_1 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Vector3_0_1 deserialize(CanardTransfer const & transfer)
  {
    Vector3_0_1 b;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    reg_drone_service_actuator_common_sp_Vector3_0_1_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return b;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Vector3_0_1::MAX_PAYLOAD_SIZE;
    return (reg_drone_service_actuator_common_sp_Vector3_0_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* sp */
} /* common */
} /* actuator */
} /* service */
} /* drone */
} /* reg */

#endif /* ARDUINO_UAVCAN_TYPES_REG_DRONE_SERVICE_ACTUATOR_COMMON_SP_VECTOR3_0_1_HPP_ */
