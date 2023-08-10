/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Pavel Kirienko <pavel@opencyphal.org>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#pragma once

#include "registry_value.hpp"

#if !defined(__GNUC__) || (__GNUC__ >= 11)

namespace cyphal
{
namespace registry
{
struct RegisterFlags final
{
  bool mutable_ = false;
  bool persistent = false;
};

struct ValueWithMetadata final
{
  Value value;
  RegisterFlags flags;
};

enum class SetError : std::uint8_t
{
  Existence,   ///< Register does not exist.
  Mutability,  ///< Register is immutable.
  Coercion,    ///< Value cannot be coerced to the register type.
  Semantics,   ///< Rejected by the register semantics (e.g. out of range, inappropriate value, bad state, etc).
};

/// This is the main, basic interface for the application to its registers.
/// The registry is just a collection of named getters[/setters],
/// where getters allow one to obtain the value by name,
/// and the optional setters allow modifying that value (non-modifiable values have no setters).
///
/// Typically, the application will have a single registry instance that is populated once during
/// initialization and then never modified until shutdown.
/// Registers are also intended to be used as configuration parameters;
/// to facilitate this scenario, the application should save mutable persistent registers during shutdown (or earlier),
/// and restore them during startup.
class IRegistry
{
public:
  IRegistry() = default;

  virtual ~IRegistry() = default;

  IRegistry(const IRegistry &) = delete;

  IRegistry(IRegistry &&) = delete;

  IRegistry &operator=(const IRegistry &) = delete;

  IRegistry &operator=(IRegistry &&) = delete;

  /// Reads the current value of the register. Empty if nonexistent.
  /// The worst-case complexity is log(n), where n is the number of registers.
  [[nodiscard]] virtual std::optional <ValueWithMetadata> get(const std::string_view nm) const = 0;

  /// Assign the register with the specified value.
  /// The worst-case complexity is log(n), where n is the number of registers.
  [[nodiscard]] virtual std::optional <SetError> set(const std::string_view nm, const Value &val) = 0;
};

/// Extends the basic registry interface with additional methods that enable introspection.
class IIntrospectableRegistry : public IRegistry
{
public:
  /// Gets the name of the register at the specified index. Empty name if the index is out of range.
  /// The ordering is arbitrary but stable as long as the register set is not modified.
  /// The worst-case complexity may be up to linear of the number of registers.
  /// Keep in mind that the register may cease to exist at any time (this is why the name is returned by value).
  [[nodiscard]] virtual Name index(const std::size_t index) const = 0;

  /// The worst-case complexity may be up to linear of the number of registers.
  [[nodiscard]] virtual std::size_t size() const = 0;
};

}  // namespace registry
} // cyphal

#endif /* !defined(__GNUC__) || (__GNUC__ >= 11) */
