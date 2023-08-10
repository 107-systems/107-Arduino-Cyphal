/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <array>

#undef max
#undef min
#include <nunavut/support/serialization.hpp>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace cyphal
{

namespace impl {

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

template<typename T_REQ, typename T_RSP, typename OnResponseCb>
ServiceClient<T_REQ, T_RSP, OnResponseCb>::~ServiceClient()
{
  _node_hdl.unsubscribe(_response_port_id, SubscriptionBase::canard_transfer_kind());
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template<typename T_REQ, typename T_RSP, typename OnResponseCb>
bool ServiceClient<T_REQ, T_RSP, OnResponseCb>::request(CanardNodeID const remote_node_id, T_REQ const & req)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
  CanardTransferMetadata const transfer_metadata =
    {
      .priority       = CanardPriorityNominal,
      .transfer_kind  = CanardTransferKindRequest,
      .port_id        = _response_port_id,
      .remote_node_id = remote_node_id,
      .transfer_id    = _transfer_id++,
    };
#pragma GCC diagnostic pop

  /* Serialize message into payload buffer. */
  std::array<uint8_t, T_REQ::_traits_::SerializationBufferSizeBytes> req_buf;
  nunavut::support::bitspan req_buf_bitspan{req_buf};
  auto const req_rc = serialize(req, req_buf_bitspan);
  if (!req_rc) return false;

  /* Serialize transfer into a series of CAN frames. */
  return _node_hdl.enqueue_transfer(_tx_timeout_usec,
                                    &transfer_metadata,
                                    *req_rc,
                                    req_buf.data());
}

template<typename T_REQ, typename T_RSP, typename OnResponseCb>
bool ServiceClient<T_REQ, T_RSP, OnResponseCb>::onTransferReceived(CanardRxTransfer const & transfer)
{
  /* Deserialize the response message. */
  T_RSP rsp;
  nunavut::support::const_bitspan rsp_bitspan(static_cast<uint8_t *>(transfer.payload), transfer.payload_size);
  auto const rc = deserialize(rsp, rsp_bitspan);
  if (!rc) return false;

  /* Invoke the user registered callback. */
  _on_response_cb(rsp);

  return true;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
} /* cyphal */
