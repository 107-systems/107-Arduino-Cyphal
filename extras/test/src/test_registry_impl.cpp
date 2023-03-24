/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Pavel Kirienko <pavel@opencyphal.org>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#include <registry_impl.hpp>
#include <catch2/catch.hpp>

namespace registry::verification
{

TEST_CASE("Basic")
{
    Registry reg;

    // Ensure empty.
    REQUIRE(0 == reg.size());
    REQUIRE(reg.index(0).name.size() == 0);
    REQUIRE_FALSE(reg.get("foo"));
    REQUIRE(SetError::Existence == reg.set("foo", Value()).value());

    // Create exposable values. Using exposure because its functionality is a superset of the routing functionality.
    std::array<std::int32_t, 3> val_arr{{123, 456, -789}};
    auto                        r_arr = reg.expose("arr", Registry::Options{true}, val_arr);  // Mutable.
    REQUIRE(r_arr);
    REQUIRE(1 == reg.size());
    REQUIRE(0 == std::strncmp("arr", reinterpret_cast<const char*>(reg.index(0).name.data()), 3));
    {
        std::array<float, 6> vec{{1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F}};
        // Create registers.
        const auto r_pi  = reg.route("pi", {true}, [] { return 3.14F; });  // RO
        const auto r_mat = reg.expose("vec", {}, vec);                     // RW
        REQUIRE(3 == reg.size());

        // Constant registers cannot be changed.
        REQUIRE(SetError::Mutability == reg.set("pi", makeValue(123.456F)).value());
        {
            const auto r_pi_get = reg.get("pi");
            REQUIRE(r_pi_get);
            REQUIRE(Approx(3.14F) == get<float>(r_pi_get.value().value).value());
            REQUIRE(r_pi_get.value().flags.persistent);
            REQUIRE(!r_pi_get.value().flags.mutable_);
        }

        // Mutate mutable array.
        {
            const auto set_result = reg.set("arr", makeValue(-654.456F));  // Coerced to -654.
            REQUIRE_FALSE(set_result);
            const auto r_arr_get = reg.get("arr");
            REQUIRE(r_arr_get);
            const auto val = get<std::array<std::int32_t, 4>>(r_arr_get.value().value).value();
            REQUIRE(-654 == val[0]);
            REQUIRE(456 == val[1]);
            REQUIRE(-789 == val[2]);
            REQUIRE(0 == val[3]);
            REQUIRE(r_arr_get.value().flags.persistent);
            REQUIRE(r_arr_get.value().flags.mutable_);
        }
        // Ensure the array itself is actually updated.
        REQUIRE(-654 == val_arr[0]);
        REQUIRE(456 == val_arr[1]);
        REQUIRE(-789 == val_arr[2]);

        // Mutate the matrix.
        {
            const auto set_result = reg.set("vec", makeValue(std::array<std::int8_t, 3>{10, -2, 30}));
            REQUIRE_FALSE(set_result);
            const auto r_mat_get = reg.get("vec");
            REQUIRE(r_mat_get);
            const auto val = get<std::array<std::int64_t, 6>>(r_mat_get.value().value).value();
            REQUIRE(10 == val[0]);  // From the vector.
            REQUIRE(-2 == val[1]);  // From the vector.
            REQUIRE(30 == val[2]);  // From the vector.
            REQUIRE(4 == val[3]);   // Original retained.
            REQUIRE(5 == val[4]);   // Original retained.
            REQUIRE(6 == val[5]);   // Original retained.
            REQUIRE(!r_mat_get.value().flags.persistent);
            REQUIRE(r_mat_get.value().flags.mutable_);
        }
        // Ensure the matrix itself is actually updated.
        REQUIRE(Approx(10) == vec[0]);
        REQUIRE(Approx(-2) == vec[1]);
        REQUIRE(Approx(30) == vec[2]);
        REQUIRE(Approx(4) == vec[3]);
        REQUIRE(Approx(5) == vec[4]);
        REQUIRE(Approx(6) == vec[5]);

        // Attempt incoercible mutation.
        REQUIRE(SetError::Coercion == reg.set("vec", makeValue("this is not a number")).value());

        // No such register.
        REQUIRE(SetError::Existence == reg.set("mat", makeValue("this is not a number")).value());

        // Semantics error.
        const auto r_semantics = reg.route(
            "sem",  //
            {},
            [] { return makeValue("anything"); },
            [](const Value&) { return false; });
        REQUIRE(SetError::Semantics == reg.set("sem", makeValue("whatever")).value());

        // List for diagnostics.
        for (auto i = 0U; true; i++)
        {
            const auto name = reg.index(i);
            if (0 == name.name.size())
            {
                break;
            }
        }
    }

    // The other registers are removed, but the first one remains.
    REQUIRE(1 == reg.size());
    REQUIRE(0 == std::strncmp("arr", reinterpret_cast<const char*>(reg.index(0).name.data()), 3));

    // Drop the first one as well.
    r_arr.reset();
    REQUIRE(0 == reg.size());
}

}  // namespace registry::verification
