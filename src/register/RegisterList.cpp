/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */


/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterList.h"

#include <algorithm>

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

RegisterList::RegisterList(Node & node_hdl)
: _reg_last{"", Access::ReadOnly, Persistent::No}
{
  _reg_list_srv = node_hdl.create_service_server<TListRequest, TListResponse>(
    TListRequest::FixedPortId,
    2*1000*1000UL,
    [this](TListRequest const & req)
    {
      return onList_1_0_Request_Received(req);
    });

  _reg_access_srv = node_hdl.create_service_server<TAccessRequest, TAccessResponse>(
    TAccessRequest::FixedPortId,
    2*1000*1000UL,
    [this](TAccessRequest const & req)
    {
      return onAccess_1_0_Request_Received(req);
    });
}

/**************************************************************************************
* PRIVATE MEMBER FUNCTIONS
**************************************************************************************/

RegisterList::TListResponse RegisterList::onList_1_0_Request_Received(TListRequest const & /* req */)
{
  return {};
}

RegisterList::TAccessResponse RegisterList::onAccess_1_0_Request_Received(TAccessRequest const & /* req */)
{
  return {};
}
