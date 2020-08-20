/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <test/util/Types.h>

#include <algorithm>

#include <iomanip>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace util
{

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

std::ostream & operator << (std::ostream & os, CanFrame const & f)
{
  os << "[" << std::hex << f.id << std::dec << "] ";
  std::for_each(std::begin(f.data),
                std::end  (f.data),
                [&os](uint8_t const d)
                {
                  os << std::hex << std::setw(2) << std::setfill('0') << (int)d << std::dec << " ";
                });
  return os;
}

std::ostream & operator << (std::ostream & os, CanFrameVect const & fv)
{
  std::for_each(std::begin(fv),
                std::end  (fv),
                [&os](CanFrame const f)
                {
                  os << f << std::endl;
                });
  return os;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* util */
