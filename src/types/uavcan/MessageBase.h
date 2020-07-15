/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

#ifndef ARDUINO_TRANSFER_MESSAGE_BASE_H_
#define ARDUINO_TRANSFER_MESSAGE_BASE_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

/**************************************************************************************
 * FORWARD DECLARATION
 **************************************************************************************/

class ArduinoUAVCAN;

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class MessageBase
{

public:

  virtual ~MessageBase() { }

  virtual bool publish(ArduinoUAVCAN & uavcan, uint8_t * transfer_id = nullptr) const = 0;

};

#endif /* ARDUINO_TRANSFER_MESSAGE_BASE_H_ */
