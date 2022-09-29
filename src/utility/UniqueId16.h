/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_UNIQUE_ID_H_
#define ARDUINO_UNIQUE_ID_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <cstdlib>
#include <cstdint>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class UniqueId16
{
public:
  UniqueId16(UniqueId16 const &) = delete;

  static UniqueId16 const & instance();

  static size_t constexpr MAX_INDEX = 16;
  uint8_t operator[](size_t const idx) const;


private:
  UniqueId16();
  uint8_t _unique_id[MAX_INDEX];
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * DEFINE
 **************************************************************************************/

#define OpenCyphalUniqueId impl::UniqueId16::instance()

#endif /* ARDUINO_UNIQUE_ID_H_ */
