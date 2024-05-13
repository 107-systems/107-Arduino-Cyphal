/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal-Support/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "kv_host.h"

#if !defined(__GNUC__) || (__GNUC__ >= 11) || defined(__clang__)

#include <cstdio>
#include <fstream>
#include <sstream>

#include <sys/stat.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace cyphal::support::platform::storage::host {

/**************************************************************************************
 * PRIVATE FREE FUNCTIONS
 **************************************************************************************/

[[nodiscard]] static inline std::string toFilename(std::string_view const key) {
  auto const key_hash = std::hash<std::string_view>{}(key);
  const std::string dir_path = "ros_nodes/firmware_bridge/cyphal_registry/";

  // Check if the directory exists
  struct stat info;
  if (stat(dir_path.c_str(), &info) != 0 ||
      !(info.st_mode & S_IFDIR)) {  // Path does not exist or is not a directory
    // Create the directory with read/write/search permissions for owner and group, and with read/search
    // permissions for others.
    mkdir(dir_path.c_str(), 0755);
  }

  std::stringstream key_filename;
  key_filename << dir_path << key_hash;
  return key_filename.str();
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

auto KeyValueStorage::get(const std::string_view key, const std::size_t size,
                          void* const data) const -> std::variant<Error, std::size_t> {
  std::ifstream in(toFilename(key), std::ifstream::in | std::ifstream::binary);

  if (!in.good())
    return Error::Existence;

  in.read(static_cast<char*>(data), size);
  size_t const bytes_read = in ? size : in.gcount();
  in.close();

  return bytes_read;
}

auto KeyValueStorage::put(const std::string_view key, const std::size_t size,
                          const void* const data) -> std::optional<Error> {
  std::ofstream out(toFilename(key), std::ofstream::in | std::ofstream::binary | std::ofstream::trunc);

  if (!out.good())
    return Error::Existence;

  out.write(static_cast<const char*>(data), size);
  out.close();

  return std::nullopt;
}

auto KeyValueStorage::drop(const std::string_view key) -> std::optional<Error> {
  if (std::remove(toFilename(key).c_str()))
    return Error::IO;

  return std::nullopt;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

}  // namespace cyphal::support::platform::storage::host

#endif /* !defined(__GNUC__) || (__GNUC__ >= 11) || defined(__clang__) */
