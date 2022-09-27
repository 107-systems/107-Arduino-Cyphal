/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_TYPE_TAG_HPP_
#define REGISTER_TYPE_TAG_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <string>

#include "../../utility/convert.hpp"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace Register
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

enum class TypeTag : size_t
{
  Empty = 0,
  String,
  Bit,
  Integer8,
  Integer16,
  Integer32,
  Integer64,
  Natural8,
  Natural16,
  Natural32,
  Natural64,
  Real32,
  Real64,
};

/**************************************************************************************
 * CONSTANT
 **************************************************************************************/

static size_t constexpr TYPE_TAG_SIZE = arduino::_107_::opencyphal::to_integer(TypeTag::Real64);

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

template <typename T> TypeTag toTypeTag(T const);

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

template<> inline TypeTag toTypeTag(std::string const)
{
  return TypeTag::String;
}

template<> inline TypeTag toTypeTag(bool const)
{
  return TypeTag::Bit;
}

template<> inline TypeTag toTypeTag(int8_t const)
{
  return TypeTag::Integer8;
}

template<> inline TypeTag toTypeTag(int16_t const)
{
  return TypeTag::Integer16;
}

template<> inline TypeTag toTypeTag(int32_t const)
{
  return TypeTag::Integer32;
}

template<> inline TypeTag toTypeTag(int64_t const)
{
  return TypeTag::Integer64;
}

template<> inline TypeTag toTypeTag(uint8_t const)
{
  return TypeTag::Natural8;
}

template<> inline TypeTag toTypeTag(uint16_t const)
{
  return TypeTag::Natural16;
}

template<> inline TypeTag toTypeTag(uint32_t const)
{
  return TypeTag::Natural32;
}

template<> inline TypeTag toTypeTag(uint64_t const)
{
  return TypeTag::Natural64;
}

template<> inline TypeTag toTypeTag(float const)
{
  return TypeTag::Real32;
}

template<> inline TypeTag toTypeTag(double const)
{
  return TypeTag::Real64;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* Register */

#endif /* REGISTER_TYPE_TAG_HPP_ */
