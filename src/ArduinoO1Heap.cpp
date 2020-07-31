/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "ArduinoO1Heap.h"

#ifndef HOST
  #include "utility/CritSec.h"
#endif

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ArduinoO1Heap::ArduinoO1Heap()
#ifndef HOST
: _o1heap_ins{o1heapInit(_base, HEAP_SIZE, crit_sec_enter, crit_sec_leave)}
#else
: _o1heap_ins{o1heapInit(_base, HEAP_SIZE, nullptr, nullptr)}
#endif
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void * ArduinoO1Heap::allocate(size_t const amount)
{
  return o1heapAllocate(_o1heap_ins, amount);
}

void ArduinoO1Heap::free(void * const pointer)
{
  o1heapFree(_o1heap_ins, pointer);
}
