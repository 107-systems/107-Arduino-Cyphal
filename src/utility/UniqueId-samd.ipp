/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * DEFINES
 **************************************************************************************/

#define ATSAMD21G18_SERIAL_NUMBER_WORD_0  *(volatile uint32_t*)(0x0080A00C)
#define ATSAMD21G18_SERIAL_NUMBER_WORD_1  *(volatile uint32_t*)(0x0080A040)
#define ATSAMD21G18_SERIAL_NUMBER_WORD_2  *(volatile uint32_t*)(0x0080A044)
#define ATSAMD21G18_SERIAL_NUMBER_WORD_3  *(volatile uint32_t*)(0x0080A048)

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template<size_t ID_SIZE>
UniqueId<ID_SIZE>::UniqueId()
{
  union
  {
    struct __attribute__((packed))
    {
      uint32_t w0, w1, w2, w3;
    } word_buf;
    uint8_t byte_buf[16];
  } uid;

  static_assert(ID_SIZE == sizeof(uid.byte_buf), "samd only has a unique ID size of 16 bytes");

  uid.word_buf.w0 = ATSAMD21G18_SERIAL_NUMBER_WORD_0;
  uid.word_buf.w1 = ATSAMD21G18_SERIAL_NUMBER_WORD_1;
  uid.word_buf.w2 = ATSAMD21G18_SERIAL_NUMBER_WORD_2;
  uid.word_buf.w3 = ATSAMD21G18_SERIAL_NUMBER_WORD_3;

  memcpy(_unique_id, uid.byte_buf, sizeof(uid.byte_buf));
}
