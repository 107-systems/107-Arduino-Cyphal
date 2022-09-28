/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_UNIQUE_ID_HPP_
#define ARDUINO_UNIQUE_ID_HPP_

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static size_t constexpr OPEN_CYPHAL_UNIQUE_ID_SIZE = 16;

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template<size_t ID_SIZE>
class UniqueId
{
public:
  UniqueId(UniqueId const &) = delete;

  static UniqueId const & instance();
  uint8_t operator[](size_t const idx) const;


private:
  UniqueId();
  uint8_t _unique_id[ID_SIZE];
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "UniqueId.ipp"

/**************************************************************************************
 * DEFINE
 **************************************************************************************/

#define UniqueId impl::UniqueId<impl::OPEN_CYPHAL_UNIQUE_ID_SIZE>::instance()

#endif /* ARDUINO_UNIQUE_ID_HPP_ */
