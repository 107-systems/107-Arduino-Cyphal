/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-UAVCAN/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "GetInfo.1.0.Response.h"

#include <assert.h>

#include <algorithm>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace GetInfo_1_0
{

/**************************************************************************************
 * STATIC MEMBER DECLARATION
 **************************************************************************************/

constexpr CanardPortID       Response::PORT_ID;
constexpr size_t             Response::MAX_PAYLOAD_SIZE;
constexpr CanardTransferKind Response::TRANSFER_KIND;
constexpr size_t             Response::UNIQUE_ID_LENGTH;
constexpr size_t             Response::MAX_LENGTH_OPT_NAME;
constexpr size_t             Response::MAX_LENGTH_OPT_CERTIFICATE_OF_AUTHENTICITY;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Response::Response(uint8_t const protocol_version_major,
                   uint8_t const protocol_version_minor,
                   uint8_t const hardware_version_major,
                   uint8_t const hardware_version_minor,
                   uint8_t const software_version_major,
                   uint8_t const software_version_minor,
                   uint64_t const software_vcs_revision_id,
                   std::array<uint8_t, 16> const unique_id)
: _protocol_version{protocol_version_major, protocol_version_minor}
, _hardware_version{hardware_version_major, hardware_version_minor}
, _software_version{software_version_major, software_version_minor}
, _software_vcs_revision_id{software_vcs_revision_id}
, _unique_id{unique_id}
, _opt_name{""}
, _is_opt_name_set{false}
, _opt_software_image_crc{0}
, _is_opt_software_image_crc_set{false}
, _certificate_of_authenticity{0}
, _is_certificate_of_authenticity_set{false}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

Response Response::create(CanardTransfer const & transfer)
{
  size_t off_bit = 0;
  uint8_t const protocol_version_major = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8); off_bit += 8;
  uint8_t const protocol_version_minor = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8); off_bit += 8;
  uint8_t const hardware_version_major = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8); off_bit += 8;
  uint8_t const hardware_version_minor = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8); off_bit += 8;
  uint8_t const software_version_major = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8); off_bit += 8;
  uint8_t const software_version_minor = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8); off_bit += 8;

  uint64_t const software_vcs_revision_id  = canardDSDLGetU64(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 64);
  off_bit += 64;

  std::array<uint8_t, 16> unique_id;
  std::generate(std::begin(unique_id),
                std::end  (unique_id),
                [&off_bit, &transfer]() -> uint8_t
                {
                  uint8_t const id_byte = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8);
                  off_bit += 8;
                  return id_byte;
                });

  Response response(protocol_version_major,
                    protocol_version_minor,
                    hardware_version_major,
                    hardware_version_minor,
                    software_version_major,
                    software_version_minor,
                    software_vcs_revision_id,
                    unique_id);

  uint8_t const length_opt_name = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8);
  off_bit += 8;
  if (length_opt_name > 0)
  {
    char opt_name[MAX_LENGTH_OPT_NAME + 1] = {0};
    size_t const length_name = std::min(static_cast<size_t>(length_opt_name), MAX_LENGTH_OPT_NAME);
    std::generate(opt_name,
                  opt_name + length_name,
                  [&off_bit, &transfer]() -> char
                  {
                    char const c = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8);
                    off_bit += 8;
                    return c;
                  });
    response.set_opt_name(std::string(opt_name, opt_name + length_name));
  }

  uint8_t const length_opt_software_image_crc = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8);
  off_bit += 8;
  if (length_opt_software_image_crc == 1)
  {
    uint64_t const opt_software_image_crc = canardDSDLGetU64(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 64);
    off_bit += 64;
    response.set_opt_software_image_crc(opt_software_image_crc);
  }

  uint8_t const length_certificate_of_authenticity = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8);
  off_bit += 8;
  if (length_certificate_of_authenticity)
  {
    size_t const length_cert = std::min(static_cast<size_t>(length_certificate_of_authenticity), MAX_LENGTH_OPT_CERTIFICATE_OF_AUTHENTICITY);
    uint8_t cert[MAX_LENGTH_OPT_CERTIFICATE_OF_AUTHENTICITY];
    std::generate(cert,
                  cert + length_cert,
                  [&off_bit, &transfer]() -> uint8_t
                  {
                    uint8_t const b = canardDSDLGetU8(reinterpret_cast<uint8_t const *>(transfer.payload), transfer.payload_size, off_bit, 8);
                    off_bit += 8;
                    return b;
                  });
    response.set_certificate_of_authenticity(cert, length_cert);
  }

  return response;
}

size_t Response::encode(uint8_t * payload) const
{
  size_t off_bit = 0;

  canardDSDLSetUxx(payload, off_bit, _protocol_version.get_major(),  8); off_bit +=  8;
  canardDSDLSetUxx(payload, off_bit, _protocol_version.get_minor(),  8); off_bit +=  8;
  canardDSDLSetUxx(payload, off_bit, _hardware_version.get_major(),  8); off_bit +=  8;
  canardDSDLSetUxx(payload, off_bit, _hardware_version.get_minor(),  8); off_bit +=  8;
  canardDSDLSetUxx(payload, off_bit, _software_version.get_major(),  8); off_bit +=  8;
  canardDSDLSetUxx(payload, off_bit, _software_version.get_minor(),  8); off_bit +=  8;
  canardDSDLSetUxx(payload, off_bit, _software_vcs_revision_id,     64); off_bit += 64;
  canardDSDLSetUxx(payload, off_bit, UNIQUE_ID_LENGTH,               8); off_bit +=  8;
  std::for_each(std::begin(_unique_id),
                std::end  (_unique_id),
                [&payload, &off_bit](uint8_t const b)
                {
                  canardDSDLSetUxx(payload, off_bit, b, 8);
                  off_bit += 8;
                });
  return (off_bit / 8);
}

void Response::set_opt_name(std::string const & name)
{
  _opt_name = name;
  _is_opt_name_set = true;
}

void Response::set_opt_software_image_crc(uint64_t const software_image_crc)
{
  _opt_software_image_crc = software_image_crc;
  _is_opt_software_image_crc_set = true;
}

void Response::set_certificate_of_authenticity(uint8_t const * cert, size_t const length_cert)
{
  std::copy(cert,
            cert + std::min(length_cert, MAX_LENGTH_OPT_CERTIFICATE_OF_AUTHENTICITY),
            _certificate_of_authenticity);
  _is_certificate_of_authenticity_set = true;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* GetInfo_1_0 */
