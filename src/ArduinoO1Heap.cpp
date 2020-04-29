/**
 * @brief   Arduino library for controlling the Zubax Orel 20.
 * @license MIT
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
