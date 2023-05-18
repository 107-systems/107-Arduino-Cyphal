/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

template<size_t MTU_BYTES>
void Node::processRxFrame(CanRxQueueItem<MTU_BYTES> const * const rx_queue_item)
{
  CanardFrame rx_frame;
  rx_frame.extended_can_id = rx_queue_item->extended_can_id();
  rx_frame.payload_size = rx_queue_item->payload_size();
  rx_frame.payload = reinterpret_cast<const void *>(rx_queue_item->payload_buf().data());

  NodeBase::onCanFrameReceived(rx_frame, rx_queue_item->rx_timestamp_usec());
}
