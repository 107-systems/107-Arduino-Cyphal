/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Pavel Kirienko <pavel@opencyphal.org>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#pragma once

#if !defined(__GNUC__) || (__GNUC__ >= 11)

#include <string_view>
#include <optional>
#include <variant>

namespace cyphal::support::platform::storage
{

enum class Error : std::uint8_t
{
    Existence,  ///< Entry does not exist but should; or exists but shouldn't.
    API,        ///< Bad API invocation (e.g., null pointer).
    Capacity,   ///< No space left on the storage device.
    IO,         ///< Device input/output error.
    Internal,   ///< Internal failure in the filesystem (storage corruption or logic error).
};

namespace interface
{

/// Key-value storage provides a very simple API for storing and retrieving named blobs.
/// The underlying storage implementation is required to be power-loss tolerant and to
/// validate data integrity per key (e.g., using CRC and such).
/// This interface is fully blocking and should only be used during initialization and shutdown,
/// never during normal operation. Non-blocking adapters can be built on top of it.
class KeyValueStorage
{
public:
    KeyValueStorage()                                          = default;
    KeyValueStorage(const KeyValueStorage&)                    = delete;
    KeyValueStorage(KeyValueStorage&&)                         = delete;
    auto operator=(const KeyValueStorage&) -> KeyValueStorage& = delete;
    auto operator=(KeyValueStorage&&) -> KeyValueStorage&      = delete;
    virtual ~KeyValueStorage()                                 = default;

    /// The return value is the number of bytes read into the buffer or the error.
    [[nodiscard]] virtual auto get(const std::string_view key, const std::size_t size, void* const data) const
        -> std::variant<Error, std::size_t> = 0;

    /// Existing data, if any, is replaced entirely. New file and its parent directories created implicitly.
    /// Either all or none of the data bytes are written.
    [[nodiscard]] virtual auto put(const std::string_view key, const std::size_t size, const void* const data)
        -> std::optional<Error> = 0;

    /// Remove key. If the key does not exist, the existence error is returned.
    [[nodiscard]] virtual auto drop(const std::string_view key) -> std::optional<Error> = 0;
};

} /* interface */

} /* cyphal::support::platform::storage */

#endif /* !defined(__GNUC__) || (__GNUC__ >= 11) */
