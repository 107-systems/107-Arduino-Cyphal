/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "NodeInfo.h"

#undef max
#undef min
#include <algorithm>

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

NodeInfo::NodeInfo(Node & node_hdl,
                   uint8_t const protocol_major,
                   uint8_t const protocol_minor,
                   uint8_t const hardware_major,
                   uint8_t const hardware_minor,
                   uint8_t const software_major,
                   uint8_t const software_minor,
                   uint64_t const software_vcs_revision_id,
                   std::array<uint8_t, 16> const unique_id,
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

  _node_info.name.count = std::min(static_cast<size_t>(name.length()), static_cast<size_t>(uavcan_node_GetInfo_Response_1_0_name_ARRAY_CAPACITY_));
  memcpy(_node_info.name.elements, name.c_str(), _node_info.name.count);

  typedef uavcan::node::GetInfo_1_0::Request<> TGetInfoRequest;
  typedef uavcan::node::GetInfo_1_0::Response<> TGetInfoResponse;

  _node_info_srv = node_hdl.create_service_server<TGetInfoRequest, TGetInfoResponse>(
    TGetInfoRequest::PORT_ID,
    2*1000*1000UL,
    [this](TGetInfoRequest const & req) -> TGetInfoResponse
    {
      TGetInfoResponse rsp = TGetInfoResponse();
      memcpy(&rsp.data, &_node_info, sizeof(uavcan_node_GetInfo_Response_1_0));
      return rsp;
    });
}
