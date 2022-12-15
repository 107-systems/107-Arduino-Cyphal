/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "NodeInfo.h"

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

NodeInfo::NodeInfo(uint8_t const protocol_major, uint8_t const protocol_minor,
                   uint8_t const hardware_major, uint8_t const hardware_minor,
                   uint8_t const software_major, uint8_t const software_minor,
                   uint64_t const software_vcs_revision_id,
                   UniqueId16Array const unique_id,
                   std::string const & name)
{
  _node_info.protocol_version.major = protocol_major;
  _node_info.protocol_version.minor = protocol_minor;

  _node_info.hardware_version.major = hardware_major;
  _node_info.hardware_version.minor = hardware_minor;

  _node_info.software_version.major = software_major;
  _node_info.software_version.minor = software_minor;

  _node_info.software_vcs_revision_id = software_vcs_revision_id;

  memcpy(_node_info.unique_id, unique_id.data(), sizeof(_node_info.unique_id));

  _node_info.name.count = std::min(name.length(), uavcan_node_GetInfo_Response_1_0_name_ARRAY_CAPACITY_);
  memcpy(_node_info.name.elements, name.c_str(), _node_info.name.count);
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void NodeInfo::subscribe(Node & node_hdl)
{
  node_hdl.subscribe<uavcan::node::GetInfo_1_0::Request<>>
    ([this](CanardRxTransfer const & transfer, Node & node_hdl) { this->onGetInfo_1_0_Request_Received(transfer, node_hdl); });
}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

void NodeInfo::onGetInfo_1_0_Request_Received(CanardRxTransfer const & transfer, Node & node_hdl)
{
  uavcan::node::GetInfo_1_0::Response<> rsp = uavcan::node::GetInfo_1_0::Response<>();
  memcpy(&rsp.data, &_node_info, sizeof(uavcan_node_GetInfo_Response_1_0));
  node_hdl.respond(rsp, transfer.metadata.remote_node_id, transfer.metadata.transfer_id);
}
