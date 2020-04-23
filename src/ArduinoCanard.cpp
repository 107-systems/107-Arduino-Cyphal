/**
 * @brief   Arduino library for controlling the Zubax Orel 20.
 * @license MIT
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ArduinoCanard.h"

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ArduinoCanard::ArduinoCanard(uint8_t const node_id)
: _canard_ins{canardInit(ArduinoCanard::o1heap_allocate, ArduinoCanard::o1heap_free)}
{
  _canard_ins.node_id = node_id;
  _canard_ins.mtu_bytes = CANARD_MTU_CAN_CLASSIC;
  _canard_ins.user_reference = reinterpret_cast<void *>(&_o1heap);
}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

void * ArduinoCanard::o1heap_allocate(CanardInstance * const ins, size_t const amount)
{
  ArduinoO1Heap * o1heap = reinterpret_cast<ArduinoO1Heap *>(ins->user_reference);
  return o1heap->allocate(amount);
}

void ArduinoCanard::o1heap_free(CanardInstance * const ins, void * const pointer)
{
  ArduinoO1Heap * o1heap = reinterpret_cast<ArduinoO1Heap *>(ins->user_reference);
  o1heap->free(pointer);
}
