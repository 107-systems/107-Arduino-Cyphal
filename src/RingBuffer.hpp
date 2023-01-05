/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_CYPHAL_UTILITY_RINGBUFFER_H_
#define ARDUINO_CYPHAL_UTILITY_RINGBUFFER_H_

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace opencyphal
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <class T>
class RingBuffer
{
public:
  RingBuffer(size_t const size)
  : _buffer{new T[size]}
  , _size{size}
  , _head{0}
  , _tail{0}
  , _num_elems{0}
  { }

  ~RingBuffer()
  {
    delete[] _buffer;
    _size = 0;
    _head = 0;
    _tail = 0;
    _num_elems = 0;
  }

  void enqueue(T const & val)
  {
    if (isFull()) return;
    _buffer[_head] = val;
    _head = nextIndex(_head);
    _num_elems++;
  }

  T dequeue()
  {
    if (isEmpty()) return T{};
    T const val = _buffer[_tail];
    _tail = nextIndex(_tail);
    _num_elems--;
    return val;
  }

  size_t available() const
  {
    return _num_elems;
  }

  bool isFull() const
  {
    return (_num_elems == _size);
  }

  bool isEmpty() const
  {
    return (_num_elems == 0);
  }

private:
  T * _buffer;
  size_t _size, _head, _tail, _num_elems;

  size_t nextIndex(size_t const index)
  {
    return ((index + 1) % _size);
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* opencyphal */

#endif /* ARDUINO_CYPHAL_UTILITY_RINGBUFFER_H_ */
