/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_WRAPPERS_H_
#define ARDUINO_UAVCAN_WRAPPERS_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "wrappers/reg/drone/physics/electricity/Power_0_1.hpp"
#include "wrappers/reg/drone/physics/electricity/PowerTs_0_1.hpp"
#include "wrappers/reg/drone/physics/electricity/Source_0_1.hpp"
#include "wrappers/reg/drone/physics/electricity/SourceTs_0_1.hpp"

#include "wrappers/reg/drone/physics/kinematics/geodetic/Point_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/geodetic/PointStateVar_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/geodetic/PointVar_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/geodetic/PoseVar_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/geodetic/StateVar_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/geodetic/PointState_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/geodetic/PointStateVarTs_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/geodetic/Pose_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/geodetic/State_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/geodetic/StateVarTs_0_1.hpp"

#include "wrappers/reg/drone/service/battery/Parameters_0_1.hpp"
#include "wrappers/reg/drone/service/battery/Status_0_1.hpp"

#include "wrappers/uavcan/node/ExecuteCommand_1_0.hpp"
#include "wrappers/uavcan/node/Heartbeat_1_0.hpp"
#include "wrappers/uavcan/node/ID_1_0.hpp"
#include "wrappers/uavcan/node/Version_1_0.hpp"

#include "wrappers/uavcan/primitive/scalar/Bit_1_0.hpp"
#include "wrappers/uavcan/primitive/scalar/Integer8_1_0.hpp"
#include "wrappers/uavcan/primitive/scalar/Integer16_1_0.hpp"
#include "wrappers/uavcan/primitive/scalar/Integer32_1_0.hpp"
#include "wrappers/uavcan/primitive/scalar/Integer64_1_0.hpp"
#include "wrappers/uavcan/primitive/scalar/Natural8_1_0.hpp"
#include "wrappers/uavcan/primitive/scalar/Natural16_1_0.hpp"
#include "wrappers/uavcan/primitive/scalar/Natural32_1_0.hpp"
#include "wrappers/uavcan/primitive/scalar/Natural64_1_0.hpp"
#include "wrappers/uavcan/primitive/scalar/Real16_1_0.hpp"
#include "wrappers/uavcan/primitive/scalar/Real32_1_0.hpp"
#include "wrappers/uavcan/primitive/scalar/Real64_1_0.hpp"

#endif /* ARDUINO_UAVCAN_WRAPPERS_H_ */
