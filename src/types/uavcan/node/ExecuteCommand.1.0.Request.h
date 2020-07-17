/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

#ifndef ARDUINO_TRANSFER_UAVCAN_NODE_EXECUTE_COMMAND_1_0_H_
#define ARDUINO_TRANSFER_UAVCAN_NODE_EXECUTE_COMMAND_1_0_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdlib.h>

#include <libcanard/canard.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ExecuteCommand_1_0_Request
{

public:

  static constexpr CanardPortID PORT_ID = 435;
  static constexpr size_t       MAX_PAYLOAD_SIZE = 2;


  ExecuteCommand_1_0_Request(uint16_t const command);


  size_t encode(uint8_t * payload) const;


  inline uint16_t command()                       const { return _command; }
  inline void     command(uint16_t const command)       { _command = command; }


private:

  uint16_t _command;

};

#endif /* ARDUINO_TRANSFER_UAVCAN_NODE_EXECUTE_COMMAND_1_0_H_ */
