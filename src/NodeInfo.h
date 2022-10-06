/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_OPENCYPHAL_NODE_INFO_H_
#define ARDUINO_OPENCYPHAL_NODE_INFO_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <string>

#include "Node.h"
#include "utility/UniqueId16.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class NodeInfo
{
public:

  NodeInfo(uint8_t const protocol_major, uint8_t const protocol_minor,
           uint8_t const hardware_major, uint8_t const hardware_minor,
           uint8_t const software_major, uint8_t const software_minor,
           uint64_t const software_vcs_revision_id,
           std::array<uint8_t, 16> const unique_id,
           std::string const & name);


  void subscribe(Node & node_hdl);


private:
  uavcan_node_GetInfo_Response_1_0 _node_info;

  void onGetInfo_1_0_Request_Received(CanardRxTransfer const & transfer, Node & node_hdl);
};

#endif /* ARDUINO_OPENCYPHAL_NODE_INFO_H_ */
