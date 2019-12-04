/**
 * @brief   Arduino library for controlling the Zubax Orel 20.
 * @author  Alexander Entinger, MSc / LXRobotics GmbH
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <ArduinoOrel20.h>

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ArduinoOrel20::ArduinoOrel20()
{
  canardInit(&_canard_inst,
             reinterpret_cast<void *>(&_libcanard_memory_pool),
             LIBCANARD_MEMORY_POOL_SIZE_BYTES,
             ArduinoOrel20::onTransferReception,
             ArduinoOrel20::shouldAcceptTransfer,
             reinterpret_cast<void *>(this));
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void ArduinoOrel20::onTransferReception(CanardInstance * ins, CanardRxTransfer * transfer)
{
  ArduinoOrel20 * this_ptr = reinterpret_cast<ArduinoOrel20 *>(ins->user_reference);

  /* TODO */
}

bool ArduinoOrel20::shouldAcceptTransfer(const CanardInstance * ins, uint64_t * out_data_type_signature, uint16_t data_type_id, CanardTransferType transfer_type, uint8_t source_node_id)
{
  ArduinoOrel20 const * this_ptr = reinterpret_cast<ArduinoOrel20 const *>(ins->user_reference);

  /* TODO */
}
