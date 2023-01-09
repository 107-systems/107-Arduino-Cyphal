/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
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
  return std::make_shared<impl::Publisher<T>>(
    *this,
    port_id,
    tx_timeout_usec
    );
}

template <typename T, typename OnReceiveCb>
Subscription Node::create_subscription(CanardPortID const port_id,
                                       CanardMicrosecond const rx_timeout_usec,
                                       OnReceiveCb&& on_receive_cb)
{
  auto sub = std::make_shared<impl::Subscription<T, OnReceiveCb>>(
    *this,
    port_id,
    std::forward<OnReceiveCb>(on_receive_cb)
    );

  int8_t const rc = canardRxSubscribe(&_canard_hdl,
                                      CanardTransferKindMessage,
                                      port_id,
                                      T::MAX_PAYLOAD_SIZE,
                                      rx_timeout_usec,
                                      &(sub->canard_rx_subscription()));
  if (rc < 0)
    return nullptr;

  return sub;
}

template <typename T_REQ, typename T_RSP, typename OnRequestCb>
ServiceServer Node::create_service_server(CanardPortID const port_id,
                                          CanardMicrosecond const tx_timeout_usec,
                                          OnRequestCb&& on_request_cb)
{
  auto srv = std::make_shared<impl::ServiceServer<T_REQ, T_RSP, OnRequestCb>>(
    *this,
    port_id,
    tx_timeout_usec,
    std::forward<OnRequestCb>(on_request_cb)
    );

  int8_t const rc = canardRxSubscribe(&_canard_hdl,
                                      CanardTransferKindRequest,
                                      port_id,
                                      T_REQ::MAX_PAYLOAD_SIZE,
                                      CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC,
                                      &(srv->canard_rx_subscription()));
  if (rc < 0)
    return nullptr;

  return srv;
}

template <typename T_REQ, typename T_RSP, typename OnResponseCb>
ServiceClient<T_REQ> Node::create_service_client(CanardPortID const port_id,
                                                 CanardMicrosecond const tx_timeout_usec,
                                                 OnResponseCb&& on_response_cb)
{
  auto clt = std::make_shared<impl::ServiceClient<T_REQ, T_RSP, OnResponseCb>>(
    *this,
    port_id,
    tx_timeout_usec,
    std::forward<OnResponseCb>(on_response_cb)
  );

  int8_t const rc = canardRxSubscribe(&_canard_hdl,
                                      CanardTransferKindResponse,
                                      port_id,
                                      T_RSP::MAX_PAYLOAD_SIZE,
                                      CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC,
                                      &(clt->canard_rx_subscription()));
  if (rc < 0)
    return nullptr;

  return clt;
}
