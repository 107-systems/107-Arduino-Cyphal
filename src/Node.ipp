/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
Publisher<T> Node::create_publisher(CanardPortID const port_id,
                                    CanardMicrosecond const tx_timeout_usec)
{
  return std::make_shared<impl::Publisher<T>>(_canard_hdl, _canard_tx_queue, port_id, tx_timeout_usec, _micros_func);
}

template <typename T>
Subscription<T> Node::create_subscription(CanardPortID const port_id,
                                          CanardMicrosecond const rx_timeout_usec,
                                          std::function<void(T const &)> on_receive_cb)
{
  auto sub = std::make_shared<impl::Subscription<T>>(on_receive_cb,
                                                     [this, port_id]() { unsubscribe_message(port_id); });

  int8_t const rc = canardRxSubscribe(&_canard_hdl,
                                      CanardTransferKindMessage,
                                      port_id,
                                      T::MAX_PAYLOAD_SIZE,
                                      rx_timeout_usec,
                                      &(sub->canard_rx_subscription()));
  if (rc < 0)
    return nullptr;

  _msg_subscription_map[port_id] = sub;
  return sub;
}

template <typename T_RSP>
bool Node::respond(T_RSP const & rsp, CanardNodeID const remote_node_id, CanardTransferID const transfer_id)
{
  static_assert(T_RSP::TRANSFER_KIND == CanardTransferKindResponse, "Node::respond API only works with CanardTransferKindResponse");

  std::array<uint8_t, T_RSP::MAX_PAYLOAD_SIZE> payload_buf;
  payload_buf.fill(0);
  size_t const payload_size = rsp.serialize(payload_buf.data());

  return enqeueTransfer(remote_node_id, T_RSP::TRANSFER_KIND, T_RSP::PORT_ID, payload_size, payload_buf.data(), transfer_id);
}

template <typename T_REQ, typename T_RSP>
bool Node::request(T_REQ const & req, CanardNodeID const remote_node_id, OnTransferReceivedFunc func)
{
  static_assert(T_REQ::TRANSFER_KIND == CanardTransferKindRequest,  "Node::request<T_REQ, T_RSP> API - T_REQ != CanardTransferKindRequest");
  static_assert(T_RSP::TRANSFER_KIND == CanardTransferKindResponse, "Node::request<T_REQ, T_RSP> API - T_RSP != CanardTransferKindResponse");

  std::array<uint8_t, T_REQ::MAX_PAYLOAD_SIZE> payload_buf;
  payload_buf.fill(0);
  size_t const payload_size = req.serialize(payload_buf.data());
  CanardTransferID const transfer_id = getNextTransferId(T_REQ::PORT_ID);

  if (!enqeueTransfer(remote_node_id, T_REQ::TRANSFER_KIND, T_REQ::PORT_ID, payload_size, payload_buf.data(), transfer_id))
    return false;

  return subscribe(T_RSP::TRANSFER_KIND, T_RSP::PORT_ID, T_RSP::MAX_PAYLOAD_SIZE, func);
}
