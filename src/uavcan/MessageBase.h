/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

#ifndef ARDUINO_TRANSFER_MESSAGE_BASE_H_
#define ARDUINO_TRANSFER_MESSAGE_BASE_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdlib.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class MessageBase
{

public:

  virtual ~MessageBase() { }

  virtual void encode(size_t * payload_size, void ** payload) = 0;

};

#endif /* ARDUINO_TRANSFER_MESSAGE_BASE_H_ */
