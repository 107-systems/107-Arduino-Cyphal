/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal-Support/graphs/contributors.
 */

#pragma once

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <107-Arduino-Cyphal.h>


/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace cyphal::support::platform::storage::host
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class KeyValueStorage final : public interface::KeyValueStorage
{
public:
  KeyValueStorage() { }
  virtual ~KeyValueStorage() { }

  /// The return value is the number of bytes read into the buffer or the error.
  [[nodiscard]] virtual auto get(const std::string_view key, const std::size_t size, void* const data) const
  -> std::variant<Error, std::size_t> override;

  /// Existing data, if any, is replaced entirely. New file and its parent directories created implicitly.
  /// Either all or none of the data bytes are written.
  [[nodiscard]] virtual auto put(const std::string_view key, const std::size_t size, const void* const data)
  -> std::optional<Error> override;

  /// Remove key. If the key does not exist, the existence error is returned.
  [[nodiscard]] virtual auto drop(const std::string_view key) -> std::optional<Error> override;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* cyphal::support::platform::storage::host */


