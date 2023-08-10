/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace cyphal
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t const heap_size)
: _buffer{new T[heap_size]}
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

  _buffer.get()[_head] = val;
  _head = nextIndex(_head);
  _num_elems++;
}

template <typename T>
T * CircularBuffer<T>::peek()
{
  if (isEmpty()) return nullptr;

  T * val_ptr = &(_buffer.get()[_tail]);
  return val_ptr;
}

template <typename T>
void CircularBuffer<T>::pop()
{
  if (isEmpty()) return;

  _tail = nextIndex(_tail);
  _num_elems--;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* cyphal */
