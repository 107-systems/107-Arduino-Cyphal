/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
bool ArduinoUAVCAN::publish(T const & msg, uint8_t * transfer_id)
{
  uint8_t payload_buf[T::PAYLOAD_SIZE];

  msg.encode(payload_buf);

  return publish(CanardTransferKindMessage, T::PORT_ID, T::PAYLOAD_SIZE, payload_buf, transfer_id);
}
