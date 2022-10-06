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

#include <Print.h>
#include <Printable.h>

#include <cstdlib>
#include <cstdint>

#include <array>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class UniqueId16 : public arduino::Printable
{
public:
  static size_t constexpr ID_SIZE = 16;

  virtual ~UniqueId16() { }
  UniqueId16(UniqueId16 const &) = delete;

  static UniqueId16 const & instance();

  uint8_t operator[](size_t const idx) const;
  std::array<uint8_t, ID_SIZE> operator()() const;


  virtual size_t printTo(Print & p) const override;


private:
  UniqueId16();
  uint8_t _unique_id[ID_SIZE];
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
