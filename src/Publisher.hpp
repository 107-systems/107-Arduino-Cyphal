/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef INC_107_ARDUINO_CYPHAL_PUBLISHER_H
#define INC_107_ARDUINO_CYPHAL_PUBLISHER_H

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "Types.h"

#include "libcanard/canard.h"

/**************************************************************************************
 * FORWARD DECLARATION
 **************************************************************************************/

class Node;

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
  Publisher(Node & node_hdl, CanardPortID const port_id, CanardMicrosecond const tx_timeout_usec)
  : _node_hdl{node_hdl}
  , _port_id{port_id}
  , _tx_timeout_usec{tx_timeout_usec}
  , _transfer_id{0}
  { }

  bool publish(T const & msg);

private:
  Node & _node_hdl;
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
