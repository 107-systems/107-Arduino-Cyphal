/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "UniqueId16.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

#if !defined(ARDUINO_ARCH_SAMD)
# warning "No Unique ID support for your platform, defaulting to hard-coded ID"
UniqueId16::UniqueId16()
: _unique_id{0}
{ }
#endif

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

UniqueId16 const & UniqueId16::instance()
{
  static UniqueId16 instance;
  return instance;
}

uint8_t UniqueId16::operator[](size_t const idx) const
{
  if (idx < MAX_INDEX)
    return _unique_id[idx];
  else
    return 0;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
