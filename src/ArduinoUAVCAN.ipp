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

template <typename T>
int8_t ArduinoUAVCAN::request(T const & req, CanardNodeID const remote_node_id, std::function<void(CanardTransfer const &)> func)
{
  if (!subscribeResponse(T::PORT_ID, T::MAX_PAYLOAD_SIZE, func))
    return ERROR;

  uint8_t payload_buf[T::MAX_PAYLOAD_SIZE];
  size_t const payload_size = req.encode(payload_buf);
  int8_t const transfer_id = publish(remote_node_id, CanardTransferKindRequest, T::PORT_ID, payload_size, payload_buf);

  if (transfer_id == ERROR) {
    unsubscribe(T::PORT_ID);
    return ERROR;
  }

  _rx_sub_rsp_map[T::PORT_ID].request_transfer_id = transfer_id;
  return transfer_id;
}
