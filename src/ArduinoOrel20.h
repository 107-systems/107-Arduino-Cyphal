/**
 * @brief   Arduino library for controlling the Zubax Orel 20.
 * @author  Alexander Entinger, MSc / LXRobotics GmbH
 * @license LGPL 3.0
 */

#ifndef ARDUINO_OREL_20_H_
#define ARDUINO_OREL_20_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>
#include <stdbool.h>

#include <canard.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoOrel20
{
public:

  ArduinoOrel20();


  static void onTransferReception(CanardInstance* ins, CanardRxTransfer* transfer);
  static bool shouldAcceptTransfer(const CanardInstance* ins, uint64_t* out_data_type_signature, uint16_t data_type_id, CanardTransferType transfer_type, uint8_t source_node_id);


private:

  CanardInstance _canard_inst;

  static size_t const LIBCANARD_MEMORY_POOL_SIZE_BYTES = 1024;
  uint8_t _libcanard_memory_pool[LIBCANARD_MEMORY_POOL_SIZE_BYTES];

};

#endif /* ARDUINO_OREL_20_H_ */
