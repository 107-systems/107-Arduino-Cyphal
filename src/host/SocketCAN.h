/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2022 LXRobotics GmbH.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/libcyphal/graphs/contributors.
 */

#ifndef CYPHAL_PHY_SOCKETCAN_H_
#define CYPHAL_PHY_SOCKETCAN_H_

#ifdef LIB_CYPHAL_CMAKE_BUILD

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <string>

#include <socketcan.h>

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class SocketCAN
{
public:
  enum class Protocol : bool
  {
    Classic = false,
    FD = true,
  };

   SocketCAN(std::string const & iface_name, Protocol const protocol);
  ~SocketCAN();


  int16_t filter(const size_t num_configs, const SocketCANFilterConfig * const configs);

  int16_t push(const CanardFrame * const frame, const CanardMicrosecond timeout_usec);
  int16_t pop (CanardFrame * const      out_frame,
               const  size_t            payload_buffer_size,
               void * const             payload_buffer,
               const  CanardMicrosecond timeout_usec,
               bool * const             loopback);

private:
  SocketCANFD _fd;
};

#endif /* LIB_CYPHAL_CMAKE_BUILD */

#endif /* CYPHAL_PHY_SOCKETCAN_H_ */
