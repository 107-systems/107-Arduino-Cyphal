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

#include "wrappers/reg/drone/physics/kinematics/cartesian/Point_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/PointStateVar_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/PointVar_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/PoseVar_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/State_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/StateVarTs_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/TwistVar_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/PointState_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/PointStateVarTs_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/Pose_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/PoseVarTs_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/StateVar_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/Twist_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/cartesian/TwistVarTs_0_1.hpp"

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

#include "wrappers/reg/drone/physics/kinematics/rotation/Planar_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/rotation/PlanarTs_0_1.hpp"

#include "wrappers/reg/drone/physics/kinematics/translation/Linear_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/translation/LinearTs_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/translation/LinearVarTs_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/translation/Velocity1VarTs_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/translation/Velocity3Var_0_1.hpp"

#include "wrappers/reg/drone/service/battery/Parameters_0_1.hpp"
#include "wrappers/reg/drone/service/battery/Status_0_1.hpp"

#include "wrappers/reg/drone/service/gnss/DilutionOfPrecision_0_1.hpp"
#include "wrappers/reg/drone/service/gnss/Heartbeat_0_1.hpp"
#include "wrappers/reg/drone/service/gnss/Sources_0_1.hpp"
#include "wrappers/reg/drone/service/gnss/Time_0_1.hpp"

#include "wrappers/reg/drone/service/sensor/Status_0_1.hpp"

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
