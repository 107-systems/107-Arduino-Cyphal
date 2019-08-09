/**
 * @brief ArduinoUAVCAN is a Arduino library wrapper for libcanard.
 * @author Alexander Entinger, MSc / LXRobotics GmbH
 * @license MIT
 */

#ifndef ARDUINO_UAVCAN_H_
#define ARDUINO_UAVCAN_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>
#include <stdbool.h>

#include <canard.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoUAVCAN
{
public:

  ArduinoUAVCAN();


  static size_t const LIBCANARD_MEMORY_POOL_SIZE_BYTES = 1024;


  static void onTransferReception(CanardInstance* ins, CanardRxTransfer* transfer);
  static bool shouldAcceptTransfer(const CanardInstance* ins, uint64_t* out_data_type_signature, uint16_t data_type_id, CanardTransferType transfer_type, uint8_t source_node_id);


private:

  CanardInstance _canard_inst;

  uint8_t _libcanard_memory_pool[LIBCANARD_MEMORY_POOL_SIZE_BYTES];

};

#endif /* ARDUINO_UAVCAN_H_ */