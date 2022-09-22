/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_TAG_H_
#define REGISTER_TAG_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <string>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace Register
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

enum class TypeTag
{
  Empty,
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
  Real16,
  Real32,
  Real64,
};

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

template<> inline TypeTag toTypeTag(uint8_t const)
{
  return TypeTag::Natural8;
}

template<> inline TypeTag toTypeTag(uint16_t const)
{
  return TypeTag::Natural16;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* Register */

#endif /* REGISTER_TAG_H_ */
