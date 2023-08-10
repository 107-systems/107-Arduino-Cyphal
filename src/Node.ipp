/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "Publisher.hpp"
#include "Subscription.hpp"
#include "ServiceClient.hpp"
#include "ServiceServer.hpp"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace cyphal
{

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template <typename T>
Publisher<T> Node::create_publisher(CanardMicrosecond const tx_timeout_usec)
{
  static_assert(T::_traits_::HasFixedPortID, "T does not have a fixed port id.");
  return create_publisher<T>(T::_traits_::FixedPortId, tx_timeout_usec);
}

template <typename T>
Publisher<T> Node::create_publisher(CanardPortID const port_id, CanardMicrosecond const tx_timeout_usec)
{
  static_assert(!T::_traits_::IsServiceType, "T is not message type");

  if (_opt_port_list_pub.has_value())
    _opt_port_list_pub.value()->add_publisher(port_id);

  return std::make_shared<impl::Publisher<T>>(
    *this,
    port_id,
    tx_timeout_usec
    );
}

template <typename T, typename OnReceiveCb>
Subscription Node::create_subscription(OnReceiveCb&& on_receive_cb, CanardMicrosecond const tid_timeout_usec)
{
  static_assert(T::_traits_::HasFixedPortID, "T does not have a fixed port id.");
  return create_subscription<T>(T::_traits_::FixedPortId, on_receive_cb, tid_timeout_usec);
}

template <typename T, typename OnReceiveCb>
Subscription Node::create_subscription(CanardPortID const port_id, OnReceiveCb&& on_receive_cb, CanardMicrosecond const tid_timeout_usec)
{
  static_assert(!T::_traits_::IsServiceType, "T is not message type");

  if (_opt_port_list_pub.has_value())
    _opt_port_list_pub.value()->add_subscriber(port_id);

  auto sub = std::make_shared<impl::Subscription<T, OnReceiveCb>>(
    *this,
    port_id,
    std::forward<OnReceiveCb>(on_receive_cb)
    );

  int8_t const rc = canardRxSubscribe(&_canard_hdl,
                                      CanardTransferKindMessage,
                                      port_id,
                                      T::_traits_::ExtentBytes,
                                      tid_timeout_usec,
                                      &(sub->canard_rx_subscription()));
  if (rc < 0)
    return nullptr;

  return sub;
}

template <typename T_REQ, typename T_RSP, typename OnRequestCb>
ServiceServer Node::create_service_server(CanardMicrosecond const tx_timeout_usec, OnRequestCb&& on_request_cb, CanardMicrosecond const tid_timeout_usec)
{
  static_assert(T_REQ::_traits_::HasFixedPortID, "T_REQ does not have a fixed port id.");
  static_assert(T_RSP::_traits_::HasFixedPortID, "T_RSP does not have a fixed port id.");

  return create_service_server<T_REQ, T_RSP>(T_REQ::_traits_::FixedPortId, tx_timeout_usec, on_request_cb, tid_timeout_usec);
}

template <typename T_REQ, typename T_RSP, typename OnRequestCb>
ServiceServer Node::create_service_server(CanardPortID const request_port_id, CanardMicrosecond const tx_timeout_usec, OnRequestCb&& on_request_cb, CanardMicrosecond const tid_timeout_usec)
{
  static_assert(T_REQ::_traits_::IsRequest, "T_REQ is not a request");
  static_assert(T_RSP::_traits_::IsResponse, "T_RSP is not a response");

  if (_opt_port_list_pub.has_value())
    _opt_port_list_pub.value()->add_service_server(request_port_id);

  auto srv = std::make_shared<impl::ServiceServer<T_REQ, T_RSP, OnRequestCb>>(
    *this,
    request_port_id,
    tx_timeout_usec,
    std::forward<OnRequestCb>(on_request_cb)
    );

  int8_t const rc = canardRxSubscribe(&_canard_hdl,
                                      CanardTransferKindRequest,
                                      request_port_id,
                                      T_REQ::_traits_::ExtentBytes,
                                      tid_timeout_usec,
                                      &(srv->canard_rx_subscription()));
  if (rc < 0)
    return nullptr;

  return srv;
}

template <typename T_REQ, typename T_RSP, typename OnResponseCb>
ServiceClient<T_REQ> Node::create_service_client(CanardMicrosecond const tx_timeout_usec, OnResponseCb&& on_response_cb, CanardMicrosecond const tid_timeout_usec)
{
  static_assert(T_REQ::_traits_::HasFixedPortID, "T_REQ does not have a fixed port id.");
  static_assert(T_RSP::_traits_::HasFixedPortID, "T_RSP does not have a fixed port id.");

  return create_service_client<T_REQ, T_RSP>(T_RSP::_traits_::FixedPortId, tx_timeout_usec, on_response_cb, tid_timeout_usec);
}

template <typename T_REQ, typename T_RSP, typename OnResponseCb>
ServiceClient<T_REQ> Node::create_service_client(CanardPortID const response_port_id, CanardMicrosecond const tx_timeout_usec, OnResponseCb&& on_response_cb, CanardMicrosecond const tid_timeout_usec)
{
  static_assert(T_REQ::_traits_::IsRequest, "T_REQ is not a request");
  static_assert(T_RSP::_traits_::IsResponse, "T_RSP is not a response");

  if (_opt_port_list_pub.has_value())
    _opt_port_list_pub.value()->add_service_client(response_port_id);

  auto clt = std::make_shared<impl::ServiceClient<T_REQ, T_RSP, OnResponseCb>>(
    *this,
    response_port_id,
    tx_timeout_usec,
    std::forward<OnResponseCb>(on_response_cb)
  );

  int8_t const rc = canardRxSubscribe(&_canard_hdl,
                                      CanardTransferKindResponse,
                                      response_port_id,
                                      T_RSP::_traits_::ExtentBytes,
                                      tid_timeout_usec,
                                      &(clt->canard_rx_subscription()));
  if (rc < 0)
    return nullptr;

  return clt;
}

template<size_t MTU_BYTES>
void Node::processRxFrame(CanRxQueueItem<MTU_BYTES> const * const rx_queue_item)
{
  CanardFrame rx_frame;
  rx_frame.extended_can_id = rx_queue_item->extended_can_id();
  rx_frame.payload_size = rx_queue_item->payload_size();
  rx_frame.payload = reinterpret_cast<const void *>(rx_queue_item->payload_buf().data());

  CanardRxTransfer rx_transfer;
  CanardRxSubscription * rx_subscription;
  int8_t const result = canardRxAccept(&_canard_hdl,
                                       rx_queue_item->rx_timestamp_usec(),
                                       &rx_frame,
                                       0, /* redundant_transport_index */
                                       &rx_transfer,
                                       &rx_subscription);

  if(result == 1)
  {
    /* Obtain the pointer to the subscribed object and in invoke its reception callback. */
    impl::SubscriptionBase * sub_ptr = static_cast<impl::SubscriptionBase *>(rx_subscription->user_reference);
    sub_ptr->onTransferReceived(rx_transfer);

    /* Free dynamically allocated memory after processing. */
    _canard_hdl.memory_free(&_canard_hdl, rx_transfer.payload);
  }
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* cyphal */
