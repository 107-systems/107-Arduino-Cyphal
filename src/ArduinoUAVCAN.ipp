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
bool ArduinoUAVCAN::subscribe(CanardPortID const port_id, OnTransferReceivedFunc func)
{
  LockGuard lock;

  return subscribe(T::TRANSFER_KIND, port_id, T::MAX_PAYLOAD_SIZE, func);
}

template <typename T_MSG>
bool ArduinoUAVCAN::publish(T_MSG const & msg)
{
  LockGuard lock;

  static_assert(T_MSG::TRANSFER_KIND == CanardTransferKindMessage, "ArduinoUAVCAN::publish API only works with CanardTransferKindMessage");

  std::array<uint8_t, T_MSG::MAX_PAYLOAD_SIZE> payload_buf;
  payload_buf.fill(0);
  size_t const payload_size = msg.serialize(payload_buf.data());
  CanardTransferID const transfer_id = getNextTransferId(msg.port_id());

  return enqeueTransfer(CANARD_NODE_ID_UNSET, T_MSG::TRANSFER_KIND, msg.port_id(), payload_size, payload_buf.data(), transfer_id);
}

template <typename T_RSP>
bool ArduinoUAVCAN::respond(T_RSP const & rsp, CanardNodeID const remote_node_id, CanardTransferID const transfer_id)
{
  LockGuard lock;

  static_assert(T_RSP::TRANSFER_KIND == CanardTransferKindResponse, "ArduinoUAVCAN::respond API only works with CanardTransferKindResponse");

  std::array<uint8_t, T_RSP::MAX_PAYLOAD_SIZE> payload_buf;
  payload_buf.fill(0);
  size_t const payload_size = rsp.serialize(payload_buf.data());

  return enqeueTransfer(remote_node_id, T_RSP::TRANSFER_KIND, T_RSP::PORT_ID, payload_size, payload_buf.data(), transfer_id);
}

template <typename T_REQ, typename T_RSP>
bool ArduinoUAVCAN::request(T_REQ const & req, CanardNodeID const remote_node_id, OnTransferReceivedFunc func)
{
  LockGuard lock;

  static_assert(T_REQ::TRANSFER_KIND == CanardTransferKindRequest,  "ArduinoUAVCAN::request<T_REQ, T_RSP> API - T_REQ != CanardTransferKindRequest");
  static_assert(T_RSP::TRANSFER_KIND == CanardTransferKindResponse, "ArduinoUAVCAN::request<T_REQ, T_RSP> API - T_RSP != CanardTransferKindResponse");

  std::array<uint8_t, T_REQ::MAX_PAYLOAD_SIZE> payload_buf;
  payload_buf.fill(0);
  size_t const payload_size = req.serialize(payload_buf.data());
  CanardTransferID const transfer_id = getNextTransferId(T_REQ::PORT_ID);

  if (!enqeueTransfer(remote_node_id, T_REQ::TRANSFER_KIND, T_REQ::PORT_ID, payload_size, payload_buf.data(), transfer_id))
    return false;

  return subscribe(T_RSP::TRANSFER_KIND, T_RSP::PORT_ID, T_RSP::MAX_PAYLOAD_SIZE, func);
}
