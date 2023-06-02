/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Pavel Kirienko <pavel@opencyphal.org>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#pragma once

#if !defined(__GNUC__) || (__GNUC__ >= 11)

#include "KeyValueStorage.hpp"

#include <functional>

#include "../registry/registry_base.hpp"

namespace cyphal::support
{

/// Scan all persistent registers in the registry and load their values from the storage if present.
/// Each register is loaded from a separate file, the file name equals the name of the register (no extension).
/// Stored registers that are not present in the registry will not be loaded.
/// The serialization format is simply the Cyphal DSDL.
/// In case of error, only part of the registers may be loaded and the registry will be left in an inconsistent state.
template <typename FeedWatchdogFunc>
[[nodiscard]] inline std::optional<platform::storage::Error> load(
  const platform::storage::interface::KeyValueStorage & kv,
  registry::IIntrospectableRegistry & rgy,
  FeedWatchdogFunc const & feed_watchdog_func)
{
    for (std::size_t index = 0; index < rgy.size(); index++)
    {
        // Prevent timeout during slow persistent storage IO access
        feed_watchdog_func();

        // Find the next register in the registry.
        const auto reg_name_storage = rgy.index(index);  // This is a little suboptimal but we don't care.
        const auto reg_name = std::string_view(reinterpret_cast<const char *>(reg_name_storage.name.cbegin()), reg_name_storage.name.size());
        if (reg_name.empty())
        {
            break;  // No more registers to load.
        }
        // If we get nothing, this means that the register has disappeared from the storage.
        if (const auto reg_meta = rgy.get(reg_name); reg_meta && reg_meta.value().flags.persistent)
        {
            // We will attempt to restore the register even if it is not mutable,
            // as it is not incompatible with the protocol.
            std::array<std::uint8_t, uavcan::_register::Value_1_0::_traits_::SerializationBufferSizeBytes> serialized;
            const auto kv_get_result = kv.get(reg_name, serialized.size(), serialized.data());
            if (const auto* const err = std::get_if<platform::storage::Error>(&kv_get_result))
            {
                if (platform::storage::Error::Existence != *err)
                {
                    return *err;
                }
                // The register is simply not present in the storage, which is OK.
            }
            else
            {
                registry::Value value;
                // Invalid data in the storage will be ignored.
                nunavut::support::const_bitspan serialized_bitspan(serialized.data(), serialized.size());
                auto const rc = deserialize(value, serialized_bitspan);
                if (rc)
                {
                    // Assign the value to the register.
                    // Shall it fail, the error is likely to be corrected during the next save().
                    (void) rgy.set(reg_name, value);
                }
            }
        }
    }
    return std::nullopt;
}

[[nodiscard]] inline std::optional<platform::storage::Error> load(
  const platform::storage::interface::KeyValueStorage & kv,
  registry::IIntrospectableRegistry & rgy)
{
  return load(kv, rgy, []() { });
}

/// The register savior is the counterpart of load().
/// Saves all persistent mutable registers from the registry to the storage.
/// Registers that are not persistent OR not mutable will not be saved;
/// the reason immutable registers are not saved is that they are assumed to be constant or runtime-computed,
/// so there is no point wasting storage on them (which may be limited).
/// Eventually this logic should be decoupled from the network register presentation facade by introducing more
/// fine-grained register flags, such as "internally mutable" and "externally mutable".
///
/// Existing stored registers that are not found in the registry will not be altered.
/// In case of failure, one failure handling strategy is to clear or reformat the entire storage and try again.
///
/// The removal predicate, if provided, allows the caller to specify which registers need to be removed from the
/// storage instead of being saved. This is useful for implementing the "factory reset" feature.
template <typename ResetPredicate, typename FeedWatchdogFunc>
[[nodiscard]] inline std::optional<platform::storage::Error> save(
  platform::storage::interface::KeyValueStorage & kv,
  const registry::IIntrospectableRegistry & rgy,
  FeedWatchdogFunc const & feed_watchdog_func,
  ResetPredicate const reset_predicate)
{
    for (std::size_t index = 0; index < rgy.size(); index++)
    {
        // Prevent timeout during slow persistent storage IO access
        feed_watchdog_func();

        const auto reg_name_storage = rgy.index(index);  // This is a little suboptimal but we don't care.
        const auto reg_name = std::string_view(reinterpret_cast<const char *>(reg_name_storage.name.cbegin()), reg_name_storage.name.size());
        if (reg_name.empty())
        {
            break;  // No more registers to load.
        }
        // Reset is handled before any other checks to enhance forward compatibility.
        if (reset_predicate(reg_name))
        {
            if (const auto err = kv.drop(reg_name); err && (err != platform::storage::Error::Existence))
            {
                return err;
            }
        }
        // If we get nothing, this means that the register has disappeared from the storage.
        // We do not save immutable registers because they are assumed to be constant, so no need to waste storage.
        else if (const auto reg_meta = rgy.get(reg_name);
                 reg_meta && reg_meta.value().flags.persistent && reg_meta.value().flags.mutable_)
        {
            // Now we have the register and we know that it is persistent, so we can save it.
            std::array<std::uint8_t, uavcan::_register::Value_1_0::_traits_::SerializationBufferSizeBytes> serialized;
            nunavut::support::bitspan serialized_bitspan{serialized};
            auto const rc = serialize(reg_meta.value().value, serialized_bitspan);
            if (!rc)
            {
              std::abort();  // This should never happen.
            }
            if (const auto err = kv.put(reg_name, *rc, serialized.data()); err)
            {
                return err;
            }
        }
        else
        {
            (void) 0;  // Nothing to do -- the register needs to be neither reset nor saved.
        }
    }
    return std::nullopt;
}

template <typename FeedWatchdogFunc>
[[nodiscard]] inline std::optional<platform::storage::Error> save(
  platform::storage::interface::KeyValueStorage & kv,
  const registry::IIntrospectableRegistry & rgy,
  FeedWatchdogFunc const & feed_watchdog_func)
{
    return save(kv, rgy, feed_watchdog_func, [](std::string_view) { return false; });
}

[[nodiscard]] inline std::optional<platform::storage::Error> save(
  platform::storage::interface::KeyValueStorage & kv,
  const registry::IIntrospectableRegistry & rgy)
{
    return save(kv, rgy, []() { }, [](std::string_view) { return false; });
}

} /* cyphal::support */

#endif /* !defined(__GNUC__) || (__GNUC__ >= 11) */
