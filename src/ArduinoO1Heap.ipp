/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template <size_t HEAP_SIZE>
ArduinoO1Heap<HEAP_SIZE>::ArduinoO1Heap()
: _o1heap_ins{o1heapInit(_base, HEAP_SIZE, nullptr, nullptr)}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <size_t HEAP_SIZE>
void * ArduinoO1Heap<HEAP_SIZE>::allocate(size_t const amount)
{
  return o1heapAllocate(_o1heap_ins, amount);
}

template <size_t HEAP_SIZE>
void ArduinoO1Heap<HEAP_SIZE>::free(void * const pointer)
{
  o1heapFree(_o1heap_ins, pointer);
}
