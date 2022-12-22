/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CYPHAL_PUBLISHER_H
#define INC_107_ARDUINO_CYPHAL_PUBLISHER_H

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "libcanard/canard.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace impl
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <typename T>
class Publisher
{
public:
  Publisher(CanardInstance & canard_hdl, CanardTxQueue & canard_tx_queue, CanardPortID const port_id, CanardMicrosecond const tx_timeout_usec = CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC)
  : _canard_hdl{canard_hdl}
  , _canard_tx_queue{canard_tx_queue}
  , _port_id{port_id}
  , _tx_timeout_usec{tx_timeout_usec}
  , _transfer_id{0}
  { }

  bool publish(T const & msg);

private:
  CanardInstance & _canard_hdl;
  CanardTxQueue & _canard_tx_queue;
  CanardPortID const _port_id;
  CanardMicrosecond const _tx_timeout_usec;
  CanardTransferID _transfer_id;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* impl */

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

template <typename T>
using Publisher = std::shared_ptr<impl::Publisher<T>>;

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "Publisher.ipp"

#endif /* INC_107_ARDUINO_CYPHAL_PUBLISHER_H */
