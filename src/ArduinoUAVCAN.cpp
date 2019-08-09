/**
 * @brief ArduinoUAVCAN is a Arduino library wrapper for libcanard.
 * @author Alexander Entinger, MSc / LXRobotics GmbH
 * @license MIT
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <ArduinoUAVCAN.h>

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ArduinoUAVCAN::ArduinoUAVCAN()
{
  canardInit(&_canard_inst,
            reinterpret_cast<void *>(&_libcanard_memory_pool),
            LIBCANARD_MEMORY_POOL_SIZE_BYTES,
            ArduinoUAVCAN::onTransferReception,
            ArduinoUAVCAN::shouldAcceptTransfer,
            reinterpret_cast<void *>(this));
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void ArduinoUAVCAN::onTransferReception(CanardInstance* ins, CanardRxTransfer* transfer)
{
  ArduinoUAVCAN * this_ptr = reinterpret_cast<ArduinoUAVCAN *>(ins->user_reference);

  /* TODO */
}

bool ArduinoUAVCAN::shouldAcceptTransfer(const CanardInstance* ins, uint64_t* out_data_type_signature, uint16_t data_type_id, CanardTransferType transfer_type, uint8_t source_node_id)
{
  ArduinoUAVCAN const * this_ptr = reinterpret_cast<ArduinoUAVCAN const *>(ins->user_reference);

  /* TODO */
}
