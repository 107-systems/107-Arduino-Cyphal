/**
 * @brief   Arduino library for controlling the Zubax Orel 20.
 * @author  Alexander Entinger, MSc / LXRobotics GmbH
 * @license MIT
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ArduinoCanard.h"

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ArduinoCanard::ArduinoCanard(uint8_t const node_id, CanardMemoryAllocate const memory_allocate, CanardMemoryFree const memory_free)
: _canard_ins{canardInit(memory_allocate, memory_free)}
{
  _canard_ins.node_id = node_id;
  _canard_ins.mtu_bytes = CANARD_MTU_CAN_CLASSIC;
}
