/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
int8_t ArduinoUAVCAN::publish(T const & msg)
{
  uint8_t payload_buf[T::MAX_PAYLOAD_SIZE];
  size_t const payload_size = msg.encode(payload_buf);
  return publish(CANARD_NODE_ID_UNSET, CanardTransferKindMessage, T::PORT_ID, payload_size, payload_buf);
}

template <typename T_REQ, typename T_RESP>
int8_t ArduinoUAVCAN::request(T_REQ const & req, CanardNodeID const remote_node_id, std::function<void(CanardTransfer const &)> func)
{
  uint8_t payload_buf[T_REQ::MAX_PAYLOAD_SIZE];
  size_t const payload_size = req.encode(payload_buf);
  int8_t const transfer_id = publish(remote_node_id, CanardTransferKindRequest, T_REQ::PORT_ID, payload_size, payload_buf);

  if (transfer_id == ERROR)
    return ERROR;

  if (!subscribeResponse(T_RESP::PORT_ID, T_RESP::MAX_PAYLOAD_SIZE, transfer_id, func))
    return ERROR;
  else
    return transfer_id;
}
