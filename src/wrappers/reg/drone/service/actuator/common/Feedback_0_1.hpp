/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_REG_DRONE_SERVICE_ACTUATOR_COMMON_FEEDBACK_0_1_HPP_
#define ARDUINO_UAVCAN_TYPES_REG_DRONE_SERVICE_ACTUATOR_COMMON_FEEDBACK_0_1_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/reg/drone/service/actuator/common/Feedback_0_1.h>

#include <utility/convert.hpp>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace reg {
namespace drone {
namespace service {
namespace actuator {
namespace common {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Feedback_0_1
{

public:

  enum class Health : uint8_t
  {
    NOMINAL  = uavcan_node_Health_1_0_NOMINAL,
    ADVISORY = uavcan_node_Health_1_0_ADVISORY,
    CAUTION  = uavcan_node_Health_1_0_CAUTION,
    WARNING  = uavcan_node_Health_1_0_WARNING,
  };

  enum class Readiness : uint8_t
  {
    SLEEP      = reg_drone_service_common_Readiness_0_1_SLEEP,
    STANDBY    = reg_drone_service_common_Readiness_0_1_STANDBY,
    ENGAGED    = reg_drone_service_common_Readiness_0_1_ENGAGED,
  };

  reg_drone_service_actuator_common_Feedback_0_1 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = reg_drone_service_actuator_common_Feedback_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;


  Feedback_0_1()
  {
    reg_drone_service_actuator_common_Feedback_0_1_initialize_(&data);
  }

  Feedback_0_1(Feedback_0_1 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Feedback_0_1 deserialize(CanardTransfer const & transfer)
  {
    Feedback_0_1 b;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    reg_drone_service_actuator_common_Feedback_0_1_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return b;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Feedback_0_1::MAX_PAYLOAD_SIZE;
    return (reg_drone_service_actuator_common_Feedback_0_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }

  void operator = (Health const health)
  {
    data.heartbeat.health.value = arduino::_107_::uavcan::to_integer(health);
  }

  void operator = (Readiness const readiness)
  {
    data.heartbeat.readiness.value = arduino::_107_::uavcan::to_integer(readiness);
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* common */
} /* actuator */
} /* service */
} /* drone */
} /* reg */

#endif /* ARDUINO_UAVCAN_TYPES_REG_DRONE_SERVICE_ACTUATOR_COMMON_FEEDBACK_0_1_HPP_ */
