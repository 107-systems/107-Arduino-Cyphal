/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <test/util/Types.h>

#include <algorithm>

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
                  os << std::hex << (int)d << std::dec << " ";
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
