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

/* /reg/drone/physics/acoustics *******************************************************/
#include "wrappers/reg/drone/physics/acoustics/Note_0_1.hpp"

/* /reg/drone/physics/dynamics/rotation ***********************************************/
#include "wrappers/reg/drone/physics/dynamics/rotation/Planar_0_1.hpp"
#include "wrappers/reg/drone/physics/dynamics/rotation/PlanarTs_0_1.hpp"

/* /reg/drone/physics/dynamics/translation ********************************************/
#include "wrappers/reg/drone/physics/dynamics/translation/Linear_0_1.hpp"
#include "wrappers/reg/drone/physics/dynamics/translation/LinearTs_0_1.hpp"

/* /reg/drone/physics/electricity *****************************************************/
#include "wrappers/reg/drone/physics/electricity/Power_0_1.hpp"
#include "wrappers/reg/drone/physics/electricity/PowerTs_0_1.hpp"
#include "wrappers/reg/drone/physics/electricity/Source_0_1.hpp"
#include "wrappers/reg/drone/physics/electricity/SourceTs_0_1.hpp"

/* /reg/drone/physics/kinematics/cartesian ********************************************/
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

/* /reg/drone/physics/kinematics/geodetic *********************************************/
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

/* /reg/drone/physics/kinematics/rotation *********************************************/
#include "wrappers/reg/drone/physics/kinematics/rotation/Planar_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/rotation/PlanarTs_0_1.hpp"

/* /reg/drone/physics/kinematics/translation ******************************************/
#include "wrappers/reg/drone/physics/kinematics/translation/Linear_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/translation/LinearTs_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/translation/LinearVarTs_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/translation/Velocity1VarTs_0_1.hpp"
#include "wrappers/reg/drone/physics/kinematics/translation/Velocity3Var_0_1.hpp"

/* /reg/drone/physics/optics **********************************************************/
#include "wrappers/reg/drone/physics/optics/HighColor_0_1.hpp"

/* /reg/drone/physics/thermodynamics **************************************************/
#include "wrappers/reg/drone/physics/thermodynamics/PressureTempVarTs_0_1.hpp"

/* /reg/drone/physics/time ************************************************************/
#include "wrappers/reg/drone/physics/time/TAI64_0_1.hpp"
#include "wrappers/reg/drone/physics/time/TAI64Var_0_1.hpp"
#include "wrappers/reg/drone/physics/time/TAI64VarTs_0_1.hpp"

/* /reg/drone/service/actuator/common/sp **********************************************/
#include "wrappers/reg/drone/service/actuator/common/sp/Scalar_0_1.hpp"
#include "wrappers/reg/drone/service/actuator/common/sp/Vector2_0_1.hpp"
#include "wrappers/reg/drone/service/actuator/common/sp/Vector3_0_1.hpp"
#include "wrappers/reg/drone/service/actuator/common/sp/Vector31_0_1.hpp"
#include "wrappers/reg/drone/service/actuator/common/sp/Vector4_0_1.hpp"
#include "wrappers/reg/drone/service/actuator/common/sp/Vector6_0_1.hpp"
#include "wrappers/reg/drone/service/actuator/common/sp/Vector8_0_1.hpp"

/* /reg/drone/service/actuator/common *************************************************/
#include "wrappers/reg/drone/service/actuator/common/FaultFlags_0_1.hpp"
#include "wrappers/reg/drone/service/actuator/common/Feedback_0_1.hpp"
#include "wrappers/reg/drone/service/actuator/common/Status_0_1.hpp"

/* /reg/drone/service/common *************************************************/
#include "wrappers/reg/drone/service/common/Heartbeat_0_1.hpp"
#include "wrappers/reg/drone/service/common/Readiness_0_1.hpp"

/* /reg/drone/service/battery *********************************************************/
#include "wrappers/reg/drone/service/battery/Parameters_0_1.hpp"
#include "wrappers/reg/drone/service/battery/Parameters_0_2.hpp"
#include "wrappers/reg/drone/service/battery/Status_0_1.hpp"
#include "wrappers/reg/drone/service/battery/Status_0_2.hpp"

/* /reg/drone/service/gnss ************************************************************/
#include "wrappers/reg/drone/service/gnss/DilutionOfPrecision_0_1.hpp"
#include "wrappers/reg/drone/service/gnss/Heartbeat_0_1.hpp"
#include "wrappers/reg/drone/service/gnss/Sources_0_1.hpp"
#include "wrappers/reg/drone/service/gnss/Time_0_1.hpp"

/* /reg/drone/service/sensor **********************************************************/
#include "wrappers/reg/drone/service/sensor/Status_0_1.hpp"

/* uavcan/diagnostic ******************************************************************/
#include "wrappers/uavcan/diagnostic/Record_1_0.hpp"
#include "wrappers/uavcan/diagnostic/Record_1_1.hpp"
#include "wrappers/uavcan/diagnostic/Severity_1_0.hpp"

/* uavcan/file ************************************************************************/
#include "wrappers/uavcan/file/Error_1_0.hpp"
#include "wrappers/uavcan/file/GetInfo_0_1.hpp"
#include "wrappers/uavcan/file/GetInfo_0_2.hpp"
#include "wrappers/uavcan/file/List_0_1.hpp"
#include "wrappers/uavcan/file/List_0_2.hpp"
#include "wrappers/uavcan/file/Modify_1_0.hpp"
#include "wrappers/uavcan/file/Modify_1_1.hpp"
#include "wrappers/uavcan/file/Path_1_0.hpp"
#include "wrappers/uavcan/file/Path_2_0.hpp"
#include "wrappers/uavcan/file/Read_1_0.hpp"
#include "wrappers/uavcan/file/Read_1_1.hpp"
#include "wrappers/uavcan/file/Write_1_0.hpp"
#include "wrappers/uavcan/file/Write_1_1.hpp"

/* uavcan/internet/udp ****************************************************************/
#include "wrappers/uavcan/internet/udp/HandleIncomingPacket_0_1.hpp"
#include "wrappers/uavcan/internet/udp/HandleIncomingPacket_0_2.hpp"
#include "wrappers/uavcan/internet/udp/OutgoingPacket_0_1.hpp"
#include "wrappers/uavcan/internet/udp/OutgoingPacket_0_2.hpp"

/* uavcan/node ************************************************************************/
#include "wrappers/uavcan/node/ExecuteCommand_1_0.hpp"
#include "wrappers/uavcan/node/ExecuteCommand_1_1.hpp"
#include "wrappers/uavcan/node/GetInfo_1_0.hpp"
#include "wrappers/uavcan/node/GetTransportStatistics_0_1.hpp"
#include "wrappers/uavcan/node/Health_1_0.hpp"
#include "wrappers/uavcan/node/Heartbeat_1_0.hpp"
#include "wrappers/uavcan/node/ID_1_0.hpp"
#include "wrappers/uavcan/node/IOStatistics_0_1.hpp"
#include "wrappers/uavcan/node/Mode_1_0.hpp"
#include "wrappers/uavcan/node/Version_1_0.hpp"

/* uavcan/node/port *******************************************************************/
#include "wrappers/uavcan/node/port/List_0_1.hpp"
#include "wrappers/uavcan/node/port/ServiceID_1_0.hpp"
#include "wrappers/uavcan/node/port/ServiceIDList_0_1.hpp"
#include "wrappers/uavcan/node/port/SubjectID_1_0.hpp"
#include "wrappers/uavcan/node/port/SubjectIDList_0_1.hpp"

/* uavcan/pnp *************************************************************************/
#include "wrappers/uavcan/pnp/NodeIDAllocationData_1_0.hpp"
#include "wrappers/uavcan/pnp/NodeIDAllocationData_2_0.hpp"
#include "wrappers/uavcan/pnp/cluster/AppendEntries_1_0.hpp"
#include "wrappers/uavcan/pnp/cluster/Discovery_1_0.hpp"
#include "wrappers/uavcan/pnp/cluster/Entry_1_0.hpp"
#include "wrappers/uavcan/pnp/cluster/RequestVote_1_0.hpp"

/* /uavcan/primitive/array ************************************************************/
#include "wrappers/uavcan/primitive/array/Bit_1_0.hpp"
#include "wrappers/uavcan/primitive/array/Integer8_1_0.hpp"
#include "wrappers/uavcan/primitive/array/Integer16_1_0.hpp"
#include "wrappers/uavcan/primitive/array/Integer32_1_0.hpp"
#include "wrappers/uavcan/primitive/array/Integer64_1_0.hpp"
#include "wrappers/uavcan/primitive/array/Natural8_1_0.hpp"
#include "wrappers/uavcan/primitive/array/Natural16_1_0.hpp"
#include "wrappers/uavcan/primitive/array/Natural32_1_0.hpp"
#include "wrappers/uavcan/primitive/array/Natural64_1_0.hpp"
#include "wrappers/uavcan/primitive/array/Real16_1_0.hpp"
#include "wrappers/uavcan/primitive/array/Real32_1_0.hpp"
#include "wrappers/uavcan/primitive/array/Real64_1_0.hpp"

/* /uavcan/primitive/scalar ***********************************************************/
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

/* /uavcan/register *******************************************************************/
#include "wrappers/uavcan/register/Access_1_0.hpp"
#include "wrappers/uavcan/register/List_1_0.hpp"
#include "wrappers/uavcan/register/Name_1_0.hpp"
#include "wrappers/uavcan/register/Value_1_0.hpp"

/* /uavcan/si *******************************************************************/
#include "wrappers/uavcan/si/sample/acceleration/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/acceleration/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/sample/angle/Quaternion_1_0.hpp"
#include "wrappers/uavcan/si/sample/angle/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/angular_acceleration/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/angular_acceleration/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/sample/angular_velocity/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/angular_velocity/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/sample/duration/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/duration/WideScalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/electric_charge/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/electric_current/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/energy/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/force/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/force/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/sample/frequency/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/length/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/length/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/sample/length/WideScalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/length/WideVector3_1_0.hpp"
#include "wrappers/uavcan/si/sample/magnetic_field_strength/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/magnetic_field_strength/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/sample/mass/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/power/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/pressure/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/temperature/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/torque/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/torque/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/sample/velocity/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/velocity/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/sample/voltage/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/volume/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/sample/volumetric_flow_rate/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/acceleration/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/acceleration/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/unit/angle/Quaternion_1_0.hpp"
#include "wrappers/uavcan/si/unit/angle/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/angular_acceleration/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/angular_acceleration/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/unit/angular_velocity/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/angular_velocity/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/unit/duration/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/duration/WideScalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/electric_charge/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/electric_current/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/energy/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/force/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/force/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/unit/frequency/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/length/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/length/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/unit/length/WideScalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/length/WideVector3_1_0.hpp"
#include "wrappers/uavcan/si/unit/magnetic_field_strength/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/magnetic_field_strength/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/unit/mass/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/power/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/pressure/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/temperature/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/torque/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/torque/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/unit/velocity/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/velocity/Vector3_1_0.hpp"
#include "wrappers/uavcan/si/unit/voltage/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/volume/Scalar_1_0.hpp"
#include "wrappers/uavcan/si/unit/volumetric_flow_rate/Scalar_1_0.hpp"


/* /uavcan/time ***********************************************************************/
#include "wrappers/uavcan/time/GetSynchronizationMasterInfo_0_1.hpp"
#include "wrappers/uavcan/time/Synchronization_1_0.hpp"
#include "wrappers/uavcan/time/SynchronizedTimestamp_1_0.hpp"
#include "wrappers/uavcan/time/TAIInfo_0_1.hpp"
#include "wrappers/uavcan/time/TimeSystem_0_1.hpp"

#endif /* ARDUINO_UAVCAN_WRAPPERS_H_ */
