/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
bool ArduinoUAVCAN::subscribe(OnTransferReceivedFunc func)
{
  return subscribe(T::TRANSFER_KIND, T::PORT_ID, T::MAX_PAYLOAD_SIZE, func);
}

template <typename T_MSG>
bool ArduinoUAVCAN::publish(T_MSG const & msg)
{
  static_assert(T_MSG::TRANSFER_KIND == CanardTransferKindMessage, "ArduinoUAVCAN::publish API only works with CanardTransferKindMessage");

  uint8_t payload_buf[T_MSG::MAX_PAYLOAD_SIZE];
  size_t const payload_size = msg.encode(payload_buf);

  return enqeueTransfer(CANARD_NODE_ID_UNSET, T_MSG::TRANSFER_KIND, T_MSG::PORT_ID, payload_size, payload_buf, nullptr);
}

template <typename T_RSP>
bool ArduinoUAVCAN::respond(T_RSP const & rsp, CanardNodeID const remote_node_id, CanardTransferID const transfer_id)
{
  static_assert(T_RSP::TRANSFER_KIND == CanardTransferKindResponse, "ArduinoUAVCAN::respond API only works with CanardTransferKindResponse");

  uint8_t payload_buf[T_RSP::MAX_PAYLOAD_SIZE];
  size_t const payload_size = rsp.encode(payload_buf);

  return enqeueTransfer(remote_node_id, T_RSP::TRANSFER_KIND, T_RSP::PORT_ID, payload_size, payload_buf, const_cast<CanardTransferID *>(&transfer_id));
}

template <typename T_REQ, typename T_RSP>
bool ArduinoUAVCAN::request(T_REQ const & req, CanardNodeID const remote_node_id, OnTransferReceivedFunc func)
{
  static_assert(T_REQ::TRANSFER_KIND == CanardTransferKindRequest,  "ArduinoUAVCAN::request<T_REQ, T_RSP> API - T_REQ != CanardTransferKindRequest");
  static_assert(T_RSP::TRANSFER_KIND == CanardTransferKindResponse, "ArduinoUAVCAN::request<T_REQ, T_RSP> API - T_RSP != CanardTransferKindResponse");

  uint8_t payload_buf[T_REQ::MAX_PAYLOAD_SIZE];
  size_t const payload_size = req.encode(payload_buf);

  CanardTransferID transfer_id;
  if (!enqeueTransfer(remote_node_id, T_REQ::TRANSFER_KIND, T_REQ::PORT_ID, payload_size, payload_buf, &transfer_id))
    return false;

  return subscribe(T_RSP::TRANSFER_KIND, T_RSP::PORT_ID, T_RSP::MAX_PAYLOAD_SIZE, func);
}
