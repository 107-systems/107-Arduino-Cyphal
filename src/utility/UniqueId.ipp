/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

#ifdef ARDUINO_ARCH_SAMD
# include "UniqueId-samd.ipp"
#else
# warning "No Unique ID support for your platform, defaulting to hard-coded ID"
template<size_t ID_SIZE>
UniqueId<ID_SIZE>::UniqueId()
: _unique_id{0}
{ }
#endif

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template<size_t ID_SIZE>
UniqueId<ID_SIZE> const & UniqueId<ID_SIZE>::instance()
{
  static UniqueId<ID_SIZE> instance;
  return instance;
}

template<size_t ID_SIZE>
uint8_t UniqueId<ID_SIZE>::operator[](size_t const idx) const
{
  if (idx < ID_SIZE)
    return _unique_id[idx];
  else
    return 0;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
