/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template <typename T>
CircularBuffer<T>::CircularBuffer(T * heap_ptr, size_t const heap_size)
: _buffer{heap_ptr}
, _size{heap_size}
, _head{0}
, _tail{0}
, _num_elems{0}
{

}

template <typename T>
CircularBuffer<T>::~CircularBuffer()
{
  _size = 0;
  _head = 0;
  _tail = 0;
  _num_elems = 0;
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
void CircularBuffer<T>::enqueue(T const & val)
{
  if (isFull()) return;

  _buffer[_head] = val;
  _head = nextIndex(_head);
  _num_elems++;
}

template <typename T>
T CircularBuffer<T>::dequeue()
{
  if (isEmpty()) return T{};

  T const val = _buffer[_tail];
  _tail = nextIndex(_tail);
  _num_elems--;
  return val;
}
