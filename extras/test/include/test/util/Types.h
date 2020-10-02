/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef TEST_UTIL_TYPES_H_
#define TEST_UTIL_TYPES_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <stdint.h>

#include <vector>
#include <iostream>

#include <libcanard/canard.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace util
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef struct
{
  uint32_t id;
  std::vector<uint8_t> data;
} CanFrame;

typedef std::vector<CanFrame> CanFrameVect;

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

std::ostream & operator << (std::ostream & os, CanFrame const & f);
std::ostream & operator << (std::ostream & os, CanFrameVect const & fv);
CanardFrame toCanardFrame(uint32_t const id, std::vector<uint8_t> const & data);

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* util */

#endif /* TEST_UTIL_TYPES_H_ */
