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
                   std::array<uint8_t, 16> const & unique_id,
                   std::string const & name)
{
  _node_info_rsp.protocol_version.major = protocol_major;
  _node_info_rsp.protocol_version.minor = protocol_minor;

  _node_info_rsp.hardware_version.major = hardware_major;
  _node_info_rsp.hardware_version.minor = hardware_minor;

  _node_info_rsp.software_version.major = software_major;
  _node_info_rsp.software_version.minor = software_minor;

  _node_info_rsp.software_vcs_revision_id = software_vcs_revision_id;

  _node_info_rsp.unique_id = unique_id;

  std::copy_n(name.begin(),
              std::min(name.length(), _node_info_rsp.name.capacity()),
              _node_info_rsp.name.begin());

  typedef uavcan::node::GetInfo::Request_1_0 TGetInfoRequest;
  typedef uavcan::node::GetInfo::Response_1_0 TGetInfoResponse;

  _node_info_srv = node_hdl.create_service_server<TGetInfoRequest, TGetInfoResponse>(
    TGetInfoRequest::FixedPortId,
    2*1000*1000UL,
    [this](TGetInfoRequest const &) -> TGetInfoResponse
    {
      return _node_info_rsp;
    });
}
