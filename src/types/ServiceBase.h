/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

#ifndef ARDUINO_TYPES_SERVICE_BASE_H_
#define ARDUINO_TYPES_SERVICE_BASE_H_

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

class ServiceBase
{

public:

  virtual ~ServiceBase() { }

  virtual bool request(ArduinoUAVCAN & uavcan, uint8_t * transfer_id = nullptr) const = 0;

};

#endif /* ARDUINO_TYPES_SERVICE_BASE_H_ */
