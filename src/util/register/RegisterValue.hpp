/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef CYPHAL_REGISTERVALUE_HPP
#define CYPHAL_REGISTERVALUE_HPP

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <type_traits>

#include "../../DSDL_Types.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace registry
{

/**************************************************************************************
 * STRUCT DECLARATION
 **************************************************************************************/

class RegisterValue
{
private:
  using DSDL_Value = uavcan::_register::Value_1_0;
  DSDL_Value _value;

public:
  DSDL_Value const & raw() { return _value; };

  /* Assigns a numerically typed array value (ints, floats, bools, etc.) from std::array<>.
   * Dimensionality and type correctness is checked at compile time, so the method cannot fail.
   */
  template<typename T, std::size_t N>
  auto set(const std::array<T, N> &ar) -> std::enable_if_t<std::is_arithmetic_v<T> && !std::is_same_v<T, bool>>
  {
    if constexpr (std::is_same_v<T, std::int64_t>) {
      _value.union_value.emplace<DSDL_Value::VariantType::IndexOf::integer64>(ar);
    }
    else if constexpr (std::is_same_v<T, std::int32_t>) {
      _value.union_value.emplace<DSDL_Value::VariantType::IndexOf::integer32>(ar);
    }
    else if constexpr (std::is_same_v<T, std::int16_t>) {
      _value.union_value.emplace<DSDL_Value::VariantType::IndexOf::integer16>(ar);
    }
    else if constexpr (std::is_same_v<T, std::int8_t>) {
      _value.union_value.emplace<DSDL_Value::VariantType::IndexOf::integer8>(ar);
    }
    else if constexpr (std::is_same_v<T, std::uint64_t>) {
      _value.union_value.emplace<DSDL_Value::VariantType::IndexOf::natural64>(ar);
    }
    else if constexpr (std::is_same_v<T, std::uint32_t>) {
      _value.union_value.emplace<DSDL_Value::VariantType::IndexOf::natural32>(ar);
    }
    else if constexpr (std::is_same_v<T, std::uint16_t>) {
      _value.union_value.emplace<DSDL_Value::VariantType::IndexOf::natural16>(ar);
    }
    else if constexpr (std::is_same_v<T, std::uint8_t>) {
      _value.union_value.emplace<DSDL_Value::VariantType::IndexOf::natural8>(ar);
    }
    else if constexpr (std::is_same_v<T, float>) {
      _value.union_value.emplace<DSDL_Value::VariantType::IndexOf::real32>(ar);
    }
    else if constexpr (std::is_same_v<T, double>) {
      _value.union_value.emplace<DSDL_Value::VariantType::IndexOf::real64>(ar);
    }
    else
    {
      /* The expression we feed to static_assert() shall always evaluate to falsity.
       * We can't use a literal false here because the discarded constexpr if branch shall be valid.
       * Details at https://en.cppreference.com/w/cpp/language/if
       */
      static_assert(std::is_void_v<T>,
                    "No known conversion from supplied arguments to register value. "
                    "Consider using explicit type conversion?");
    }
  }

  /* Assigns a string value. Strings that are too long are silently truncated.
   */
  void set(std::string const & str)
  {
    /*uavcan_register_Value_1_0_select_string_(this);
    _string.value.count = std::min<std::size_t>(uavcan_primitive_String_1_0_value_ARRAY_CAPACITY_, str.size());
    std::memmove(&_string.value.elements[0], str.begin(), _string.value.count);
    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    std::fill(std::begin(_string.value.elements) + _string.value.count, std::end(_string.value.elements), 0);
     */
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* registry */

#endif /* CYPHAL_REGISTERVALUE_HPP */
