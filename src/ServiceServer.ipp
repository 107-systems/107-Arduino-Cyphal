/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

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
  _node_hdl.unsubscribe(_port_id, canard_transfer_kind());
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

template<typename T_REQ, typename T_RSP, typename OnRequestCb>
bool ServiceServer<T_REQ, T_RSP, OnRequestCb>::onTransferReceived(CanardRxTransfer const & transfer)
{
  /* Deserialize the request message. */
  T_REQ const req = T_REQ::deserialize(transfer);

  /* Invoke the service callback and obtain the desired response. */
  T_RSP const rsp = _on_request_cb(req);

  /* Serialize the response message. */
  std::array<uint8_t, T_RSP::MAX_PAYLOAD_SIZE> payload_buf{};
  size_t const payload_buf_size = rsp.serialize(payload_buf.data());

  /* Enqueue the transfer. */
  CanardTransferMetadata const transfer_metadata =
  {
    .priority       = CanardPriorityNominal,
    .transfer_kind  = CanardTransferKindResponse,
    .port_id        = transfer.metadata.port_id,
    .remote_node_id = transfer.metadata.remote_node_id,
    .transfer_id    = transfer.metadata.transfer_id,
  };

  /* Serialize transfer into a series of CAN frames */
  return _node_hdl.enqueue_transfer(_tx_timeout_usec,
                                    &transfer_metadata,
                                    payload_buf_size,
                                    payload_buf.data());
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */
