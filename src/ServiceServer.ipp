/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <nunavut/support/serialization.hpp>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl {

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template<typename T_REQ, typename T_RSP, typename OnRequestCb>
ServiceServer<T_REQ, T_RSP, OnRequestCb>::~ServiceServer()
{
  _node_hdl.unsubscribe(_port_id, SubscriptionBase::canard_transfer_kind());
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template<typename T_REQ, typename T_RSP, typename OnRequestCb>
bool ServiceServer<T_REQ, T_RSP, OnRequestCb>::onTransferReceived(CanardRxTransfer const & transfer)
{
  /* Deserialize the request message. */
  T_REQ req{};
  nunavut::support::const_bitspan req_buf_bitspan(static_cast<uint8_t *>(transfer.payload), transfer.payload_size);
  auto const req_rc = req.deserialize(req_buf_bitspan);
  if (!req_rc) return false;

  /* Invoke the service callback and obtain the desired response. */
  T_RSP const rsp = _on_request_cb(req);

  /* Serialize the response message. */
  std::array<uint8_t, T_RSP::SERIALIZATION_BUFFER_SIZE_BYTES> rsp_buf{};
  nunavut::support::bitspan rsp_buf_bitspan{rsp_buf};
  auto const rsp_rc = rsp.serialize(rsp_buf_bitspan);
  if (!rsp_rc) return false;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
  /* Enqueue the transfer. */
  CanardTransferMetadata const transfer_metadata =
  {
    .priority       = CanardPriorityNominal,
    .transfer_kind  = CanardTransferKindResponse,
    .port_id        = transfer.metadata.port_id,
    .remote_node_id = transfer.metadata.remote_node_id,
    .transfer_id    = transfer.metadata.transfer_id,
  };
#pragma GCC diagnostic pop

  /* Serialize transfer into a series of CAN frames */
  return _node_hdl.enqueue_transfer(_tx_timeout_usec,
                                    &transfer_metadata,
                                    rsp_buf_bitspan.size() / 8,
                                    rsp_buf_bitspan.aligned_ptr());
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
