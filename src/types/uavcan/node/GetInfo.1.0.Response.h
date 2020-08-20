/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

#ifndef ARDUINO_TYPES_UAVCAN_NODE_GET_INFO_1_0_RESPONSE_H_
#define ARDUINO_TYPES_UAVCAN_NODE_GET_INFO_1_0_RESPONSE_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdlib.h>

#include <array>
#include <string>

#include <libcanard/canard.h>

#include "GetInfo.1.0.Request.h"

#include "Version.1.0.hpp"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace GetInfo_1_0
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Response
{

public:

  static constexpr CanardPortID       PORT_ID = Request::PORT_ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = (Version_1_0<PORT_ID>::MAX_PAYLOAD_SIZE) * 3
                                                         + sizeof(uint64_t)
                                                         + sizeof(uint8_t[16])
                                                         + sizeof(uint8_t) + sizeof(uint8_t[50])
                                                         + sizeof(uint8_t) + sizeof(uint64_t)
                                                         + sizeof(uint8_t) + sizeof(uint8_t[222]);
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindResponse;


  Response(uint8_t const protocol_version_major,
           uint8_t const protocol_version_minor,
           uint8_t const hardware_version_major,
           uint8_t const hardware_version_minor,
           uint8_t const software_version_major,
           uint8_t const software_version_minor,
           uint64_t const software_vcs_revision_id,
           std::array<uint8_t, 16> const unique_id);

  static Response create(CanardTransfer const & transfer);
         size_t   encode(uint8_t * payload) const;


  inline Version_1_0<PORT_ID>    protocol_version        () const { return _protocol_version; }
  inline Version_1_0<PORT_ID>    hardware_version        () const { return _hardware_version; }
  inline Version_1_0<PORT_ID>    software_version        () const { return _software_version; }
  inline uint64_t                software_vcs_revision_id() const { return _software_vcs_revision_id; }
  inline std::array<uint8_t, 16> unique_id               () const { return _unique_id; };
  inline bool                    is_opt_name             () const { return _is_opt_name_set; }
  inline std::string             opt_name                () const { return _opt_name; }

  void set_opt_name                   (std::string const & name);
  void set_opt_software_image_crc     (uint64_t const software_image_crc);
  void set_certificate_of_authenticity(uint8_t const * cert, size_t const length_cert);


private:

    static constexpr size_t UNIQUE_ID_LENGTH = 16;
    static constexpr size_t MAX_LENGTH_OPT_NAME = 50;
    static constexpr size_t MAX_LENGTH_OPT_CERTIFICATE_OF_AUTHENTICITY = 222;

    Version_1_0<PORT_ID> _protocol_version, _hardware_version, _software_version;
    uint64_t _software_vcs_revision_id;
    std::array<uint8_t, UNIQUE_ID_LENGTH> _unique_id;
    std::string _opt_name;
    bool _is_opt_name_set;
    uint64_t _opt_software_image_crc;
    bool _is_opt_software_image_crc_set;
    uint8_t _certificate_of_authenticity[MAX_LENGTH_OPT_CERTIFICATE_OF_AUTHENTICITY];
    bool  _is_certificate_of_authenticity_set;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* GetInfo_1_0 */

#endif /* ARDUINO_TYPES_UAVCAN_NODE_GET_INFO_1_0_RESPONSE_H_ */
