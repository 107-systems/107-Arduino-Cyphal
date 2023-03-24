/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Pavel Kirienko <pavel@opencyphal.org>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#include <registry_value.hpp>
#include <catch2/catch.hpp>

namespace registry::verification
{
TEST_CASE("makeName")
{
    auto nm = makeName("foo");
    REQUIRE(nm.name.size() == 3);
    REQUIRE(nm.name[0] == 'f');
    REQUIRE(nm.name[1] == 'o');
    REQUIRE(nm.name[2] == 'o');
}

TEST_CASE("isVariableSize")
{
    Value v;
    REQUIRE(!isVariableSize(v));
    v.set_string();
    REQUIRE(isVariableSize(v));
    v.set_unstructured();
    REQUIRE(isVariableSize(v));
    v.set_bit();
    REQUIRE(!isVariableSize(v));
    v.set_integer64();
    REQUIRE(!isVariableSize(v));
    v.set_real64();
    REQUIRE(!isVariableSize(v));
}

TEST_CASE("makeValue")
{
    Value v = makeValue(true, false, true, false, false, false, false, true, false);
    REQUIRE(v.is_bit());
    REQUIRE(9 == v.get_bit().value.size());
    REQUIRE(true == v.get_bit().value[0]);
    REQUIRE(false == v.get_bit().value[1]);
    REQUIRE(true == v.get_bit().value[2]);
    REQUIRE(false == v.get_bit().value[3]);
    REQUIRE(false == v.get_bit().value[4]);
    REQUIRE(false == v.get_bit().value[5]);
    REQUIRE(false == v.get_bit().value[6]);
    REQUIRE(true == v.get_bit().value[7]);
    REQUIRE(false == v.get_bit().value[8]);

    v = makeValue(static_cast<std::int64_t>(-1234567890), 123, 1234567890123);
    REQUIRE(v.is_integer64());
    REQUIRE(3 == v.get_integer64().value.size());
    REQUIRE(-1234567890 == v.get_integer64().value[0]);
    REQUIRE(123 == v.get_integer64().value[1]);
    REQUIRE(1234567890123 == v.get_integer64().value[2]);

    v = makeValue(static_cast<std::int32_t>(-123456789), static_cast<std::int32_t>(66));
    REQUIRE(v.is_integer32());
    REQUIRE(2 == v.get_integer32().value.size());
    REQUIRE(-123456789 == v.get_integer32().value[0]);
    REQUIRE(66 == v.get_integer32().value[1]);

    v = makeValue(static_cast<std::int16_t>(-1234));
    REQUIRE(v.is_integer16());
    REQUIRE(1 == v.get_integer16().value.size());
    REQUIRE(-1234 == v.get_integer16().value[0]);

    v = makeValue(static_cast<std::int8_t>(-128), static_cast<std::int8_t>(+127));
    REQUIRE(v.is_integer8());
    REQUIRE(2 == v.get_integer8().value.size());
    REQUIRE(-128 == v.get_integer8().value[0]);
    REQUIRE(+127 == v.get_integer8().value[1]);

    v = makeValue(static_cast<std::uint64_t>(1234567890), 123, 1234567890123);
    REQUIRE(v.is_natural64());
    REQUIRE(3 == v.get_natural64().value.size());
    REQUIRE(1234567890 == v.get_natural64().value[0]);
    REQUIRE(123 == v.get_natural64().value[1]);
    REQUIRE(1234567890123 == v.get_natural64().value[2]);

    v = makeValue(static_cast<std::uint32_t>(123456789), static_cast<std::uint32_t>(66));
    REQUIRE(v.is_natural32());
    REQUIRE(2 == v.get_natural32().value.size());
    REQUIRE(123456789 == v.get_natural32().value[0]);
    REQUIRE(66 == v.get_natural32().value[1]);

    v = makeValue(static_cast<std::uint16_t>(1234));
    REQUIRE(v.is_natural16());
    REQUIRE(1 == v.get_natural16().value.size());
    REQUIRE(1234 == v.get_natural16().value[0]);

    v = makeValue(static_cast<std::uint8_t>(128), static_cast<std::uint8_t>(127));
    REQUIRE(v.is_natural8());
    REQUIRE(2 == v.get_natural8().value.size());
    REQUIRE(128 == v.get_natural8().value[0]);
    REQUIRE(127 == v.get_natural8().value[1]);

    v = makeValue(+123.456F, -789.523F);
    REQUIRE(v.is_real32());
    REQUIRE(2 == v.get_real32().value.size());
    REQUIRE(Approx(+123.456F) == v.get_real32().value[0]);
    REQUIRE(Approx(-789.523F) == v.get_real32().value[1]);

    v = makeValue(+123.456F, -789.523F, -1.0);  // One of them is double so all converted to double.
    REQUIRE(v.is_real64());
    REQUIRE(3 == v.get_real64().value.size());
    REQUIRE(Approx(+123.456F) == v.get_real64().value[0]);
    REQUIRE(Approx(-789.523F) == v.get_real64().value[1]);
    REQUIRE(Approx(-1.0F) == v.get_real64().value[2]);

    v = makeValue("Is it Atreides custom to insult their guests?");
    REQUIRE(v.is_string());
    REQUIRE(45 == v.get_string().value.size());
    REQUIRE(0 == std::strncmp("Is it Atreides custom to insult their guests?",
                              reinterpret_cast<const char*>(v.get_string().value.data()),
                              v.get_string().value.size()));
}

TEST_CASE("Get")
{
    REQUIRE_FALSE(get<bool>(Value()));
    REQUIRE_FALSE(get<int>(Value()));
    REQUIRE_FALSE(get<double>(Value()));
    REQUIRE_FALSE(get<std::array<int, 5>>(Value()));
    REQUIRE_FALSE(get<std::string_view>(Value()));
    {
        const auto v = get<std::array<float, 2>>(makeValue(std::array<std::int64_t, 3>{{11'111, 22'222, -12'345}}));
        REQUIRE(v);
        REQUIRE(2 == v->size());
        REQUIRE(Approx(11'111.0F) == (*v)[0]);
        REQUIRE(Approx(22'222.0F) == (*v)[1]);
    }
    {
        const auto v = get<std::array<float, 4>>(makeValue(std::array<std::int64_t, 3>{{11'111, 22'222, -12'345}}));
        REQUIRE(v);
        REQUIRE(4 == v->size());
        REQUIRE(Approx(11'111.0F) == (*v)[0]);
        REQUIRE(Approx(22'222.0F) == (*v)[1]);
        REQUIRE(Approx(-12'345.0F) == (*v)[2]);
        REQUIRE(Approx(0.0F) == (*v)[3]);
    }
    {
        const auto v = get<std::array<bool, 2>>(makeValue(std::array<std::int64_t, 3>{{true, false}}));
        REQUIRE(v);
        REQUIRE(2 == v->size());
        REQUIRE((*v)[0]);
        REQUIRE(!(*v)[1]);
    }
    {
        const auto val = makeValue("abc");
        const auto v   = get<std::string_view>(val);
        REQUIRE(v);
        REQUIRE(3 == v->size());
        REQUIRE("abc" == *v);
    }
    REQUIRE(1234 == get<std::int16_t>(makeValue(std::int64_t(1234), -9876, 1521)).value());
    REQUIRE(get<bool>(makeValue(true, false)).value());
    REQUIRE(!get<bool>(makeValue(false, true)).value());
    REQUIRE(!get<float>(makeValue("foo")));
}

TEST_CASE("Coerce")
{
    Value      co_result{};
    const auto co = [&co_result](const Value& dst, const Value& src) -> const Value*
    {
        co_result = dst;
        return coerce(co_result, src) ? &co_result : nullptr;
    };

    const auto* v =
        co(makeValue(static_cast<std::int64_t>(0), 0, 0), makeValue(static_cast<std::int64_t>(123), 456, 789));
    REQUIRE(v);
    REQUIRE(v->is_integer64());
    REQUIRE(3 == v->get_integer64().value.size());
    REQUIRE(123 == v->get_integer64().value[0]);
    REQUIRE(456 == v->get_integer64().value[1]);
    REQUIRE(789 == v->get_integer64().value[2]);

    // Same type, values converted, extras truncated.
    v = co(*v,
           makeValue(static_cast<std::int8_t>(127),
                     static_cast<std::int8_t>(-45),
                     static_cast<std::int8_t>(-128),
                     static_cast<std::int8_t>(55),
                     static_cast<std::int8_t>(66)));
    REQUIRE(v);
    REQUIRE(v->is_integer64());
    REQUIRE(3 == v->get_integer64().value.size());
    REQUIRE(127 == v->get_integer64().value[0]);
    REQUIRE(-45 == v->get_integer64().value[1]);
    REQUIRE(-128 == v->get_integer64().value[2]);

    // Same type, values converted, missing values retained.
    v = co(*v, makeValue(static_cast<std::int8_t>(55), static_cast<std::int8_t>(66)));
    REQUIRE(v);
    REQUIRE(v->is_integer64());
    REQUIRE(3 == v->get_integer64().value.size());
    REQUIRE(55 == v->get_integer64().value[0]);
    REQUIRE(66 == v->get_integer64().value[1]);
    REQUIRE(-128 == v->get_integer64().value[2]);  // Keeps the old value.

    // Same type, values converted, missing values retained.
    v = co(*v, makeValue(12345.6F, 789012.34));
    REQUIRE(v);
    REQUIRE(v->is_integer64());
    REQUIRE(3 == v->get_integer64().value.size());
    REQUIRE(12345 == v->get_integer64().value[0]);
    REQUIRE(789012 == v->get_integer64().value[1]);
    REQUIRE(-128 == v->get_integer64().value[2]);  // Keeps the old value.

    // Bad conversions.
    REQUIRE_FALSE(co(*v, makeValue("I'll give you a toad")));
    REQUIRE_FALSE(co(*v, Value()));

    // Become string.
    v = co(makeValue(""), makeValue("abc"));
    REQUIRE(v);
    REQUIRE(v->is_string());
    REQUIRE(3 == v->get_string().value.size());
    REQUIRE("abc" == get<std::string_view>(*v));

    // String is convertible to unstructured.
    Value unstructured;
    unstructured.set_unstructured();
    unstructured.get_unstructured().value.push_back('z');
    v = co(unstructured, makeValue("abc"));
    REQUIRE(v);
    REQUIRE(v->is_unstructured());
    REQUIRE(3 == v->get_unstructured().value.size());
    REQUIRE('a' == v->get_unstructured().value[0]);
    REQUIRE('b' == v->get_unstructured().value[1]);
    REQUIRE('c' == v->get_unstructured().value[2]);

    // Convert bits.
    v = co(makeValue(true, false, true, false), makeValue(false, false, false, true, false));
    REQUIRE(v->is_bit());
    REQUIRE(4 == v->get_bit().value.size());  // Extra truncated away.
    REQUIRE(!v->get_bit().value[0]);
    REQUIRE(!v->get_bit().value[1]);
    REQUIRE(!v->get_bit().value[2]);
    REQUIRE(v->get_bit().value[3]);

    // Convert floats.
    v = co(makeValue(99.456F), makeValue(static_cast<std::int8_t>(-123), static_cast<std::int8_t>(+123)));
    REQUIRE(v->is_real32());
    REQUIRE(1 == v->get_real32().value.size());
    REQUIRE(Approx(-123.0F) == v->get_real32().value[0]);
}

}  // namespace registry::verification
