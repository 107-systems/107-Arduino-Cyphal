/**
 * @brief   Arduino library for providing a convenient C++ interface for accessing UAVCAN.
 * @license MIT
 */

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T_MSG>
bool ArduinoUAVCAN::publish(T_MSG const & msg)
{
  uint8_t payload_buf[T_MSG::MAX_PAYLOAD_SIZE];
  size_t const payload_size = msg.encode(payload_buf);
  
  return publish(CANARD_NODE_ID_UNSET, CanardTransferKindMessage, T_MSG::PORT_ID, payload_size, payload_buf, nullptr);
}

template <typename T_REQ>
bool ArduinoUAVCAN::subscribe(OnTransferReceivedFunc func)
{
  return subscribeRequest(T_REQ::PORT_ID, T_REQ::MAX_PAYLOAD_SIZE, func);
}

template <typename T_RSP>
bool ArduinoUAVCAN::respond(T_RSP const & rsp, CanardNodeID const remote_node_id, CanardTransferID const transfer_id)
{
  uint8_t payload_buf[T_RSP::MAX_PAYLOAD_SIZE];
  size_t const payload_size = rsp.encode(payload_buf);

  return publish(remote_node_id, CanardTransferKindResponse, T_RSP::PORT_ID, payload_size, payload_buf, const_cast<CanardTransferID *>(&transfer_id));
}

template <typename T_REQ, typename T_RESP>
bool ArduinoUAVCAN::request(T_REQ const & req, CanardNodeID const remote_node_id, OnTransferReceivedFunc func)
{
  uint8_t payload_buf[T_REQ::MAX_PAYLOAD_SIZE];
  size_t const payload_size = req.encode(payload_buf);
  
  CanardTransferID transfer_id;
  if (!publish(remote_node_id, CanardTransferKindRequest, T_REQ::PORT_ID, payload_size, payload_buf, &transfer_id))
    return false;

  return subscribeResponse(T_RESP::PORT_ID, T_RESP::MAX_PAYLOAD_SIZE, transfer_id, func);
}
