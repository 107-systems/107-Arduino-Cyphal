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

#include <algorithm>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

#if !defined(ARDUINO_ARCH_SAMD) && !defined(ARDUINO_ARCH_RP2040) && !defined(ARDUINO_ARCH_ESP32) || defined(ARDUINO_ARCH_MBED)
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

std::array<uint8_t, UniqueId16::MAX_INDEX> UniqueId16::operator()() const
{
  std::array<uint8_t, MAX_INDEX> uid;
  std::copy(std::begin(_unique_id),
            std::end  (_unique_id),
            std::begin(uid));
  return uid;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
