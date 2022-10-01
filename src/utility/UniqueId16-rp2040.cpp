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

#ifdef ARDUINO_ARCH_RP2040

#include <cstring>
#include <pico/unique_id.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * DEFINES
 **************************************************************************************/

#define IDSIZE 8

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

UniqueId16::UniqueId16()
{
  union
  {
    struct __attribute__((packed))
    {
      uint32_t w0, w1, w2, w3;
    } word_buf;
    uint8_t byte_buf[16];
  } uid;

  pico_unique_board_id_t pico;
  pico_get_unique_board_id(&pico);
  for (int i = 0; i < IDSIZE; i++) {
    uid.byte_buf[i] = pico.id[i];
  }

  memcpy(_unique_id, uid.byte_buf, sizeof(_unique_id));
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

#endif /* ARDUINO_ARCH_RP2040 */
