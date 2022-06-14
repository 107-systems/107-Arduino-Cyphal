/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_REG_DRONE_SERVICE_BATTERY_PARAMETERS_0_3_HPP_
#define ARDUINO_UAVCAN_TYPES_REG_DRONE_SERVICE_BATTERY_PARAMETERS_0_3_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/reg/udral/service/battery/Parameters_0_3.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace reg {
namespace udral {
namespace service {
namespace battery {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Parameters_0_3
{

public:

  reg_udral_service_battery_Parameters_0_3 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = reg_udral_service_battery_Parameters_0_3_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;


  Parameters_0_3()
  {
    reg_udral_service_battery_Parameters_0_3_initialize_(&data);
  }

  Parameters_0_3(Parameters_0_3 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Parameters_0_3 deserialize(CanardTransfer const & transfer)
  {
    Parameters_0_3 b;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    reg_udral_service_battery_Parameters_0_3_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return b;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Parameters_0_3::MAX_PAYLOAD_SIZE;
    return (reg_udral_service_battery_Parameters_0_3_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* reg */
} /* udral */
} /* service */
} /* battery */

#endif /* ARDUINO_UAVCAN_TYPES_REG_DRONE_SERVICE_BATTERY_PARAMETERS_0_3_HPP_ */
