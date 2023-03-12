//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl
// Generated at:  2023-03-10 05:17:53.551525 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     uavcan.time.TAIInfo
// Type Version:  0.1
// Support
//    Support Namespace: nunavut.lang.cpp.support
//    Support Version:   (1, 0, 0)
// Template Set (package)
//    priority: 0
//    package:  nunavut.lang.cpp.templates
//    version:  (1, 0, 0)
// Platform
//     python_implementation:  CPython
//     python_version:  3.10.6
//     python_release_level:  final
//     python_build:  ('main', 'Nov 14 2022 16:10:14')
//     python_compiler:  GCC 11.3.0
//     python_revision:
//     python_xoptions:  {}
//     runtime_platform:  Linux-5.19.0-35-generic-x86_64-with-glibc2.35
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  False
//     enable_override_variable_array_capacity:  False
//     std:  c++17
//     variable_array_type_template:
//     variable_array_type_include:
//     cast_format:  static_cast<{type}>({value})
//     enable_allocator_support:  False
// Uses Language Features
//     Uses std_variant:yes
#ifndef UAVCAN_TIME_TAI_INFO_0_1_HPP_INCLUDED
#define UAVCAN_TIME_TAI_INFO_0_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <cstdint>
#include <limits>

namespace uavcan
{
namespace time
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+
///
/// This data types defines constants and runtime values pertaining to the International Atomic Time, also known as TAI.
/// See https://en.wikipedia.org/wiki/International_Atomic_Time.
///
/// The relationship between the three major time systems -- TAI, GPS, and UTC -- is as follows:
///
///   TAI = GPS + 19 seconds
///   TAI = UTC + LS + 10 seconds
///
/// Where "LS" is the current number of leap seconds: https://en.wikipedia.org/wiki/Leap_second.
///
/// Cyphal applications should only rely on TAI whenever a global time system is needed.
/// GPS time is strongly discouraged for reasons of consistency across different positioning systems and applications.
///
struct TAIInfo_0_1 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        /// This type does not have a fixed port-ID. See https://forum.opencyphal.org/t/choosing-message-and-service-ids/889
        static constexpr bool HasFixedPortID = false;

        static constexpr bool IsServiceType = false;

        /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
        /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
        /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
        /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
        /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
        /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
        /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
        static constexpr std::size_t ExtentBytes                  = 2UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 2UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using difference_tai_minus_utc = std::uint16_t;
        };
    };

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+
    ///
    /// [second]
    /// The fixed difference, in seconds, between TAI and GPS time. Does not change ever.
    /// Systems that use GPS time as a reference should convert that to TAI by adding this difference.
    ///
    static constexpr std::uint8_t DIFFERENCE_TAI_MINUS_GPS = 19U;

    static constexpr std::uint16_t DIFFERENCE_TAI_MINUS_UTC_UNKNOWN = 0U;

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// The current difference between TAI and UTC, if known. If unknown, set to zero.
    ///
    /// This value may change states between known and unknown while the master is running,
    /// depending on its ability to obtain robust values from external sources.
    ///
    /// This value may change twice a year, possibly while the system is running;
    /// https://en.wikipedia.org/wiki/Leap_second.
    /// Since the rotation of Earth is decelerating, this value may only be positive. Do not use outside Earth.
    ///
    /// For reference, here is the full list of recorded TAI-UTC difference values, valid at the time of writing:
    ///
    ///     Date     | TAI-UTC difference [second]
    ///    ----------|-----------------------------
    ///     Jan 1972 | 10
    ///     Jul 1972 | 11
    ///     Jan 1973 | 12
    ///     Jan 1974 | 13
    ///     Jan 1975 | 14
    ///     Jan 1976 | 15
    ///     Jan 1977 | 16
    ///     Jan 1978 | 17
    ///     Jan 1979 | 18
    ///     Jan 1980 | 19
    ///     Jul 1981 | 20
    ///     Jul 1982 | 21
    ///     Jul 1983 | 22
    ///     Jul 1985 | 23
    ///     Jan 1988 | 24
    ///     Jan 1990 | 25
    ///     Jan 1991 | 26
    ///     Jul 1992 | 27
    ///     Jul 1993 | 28
    ///     Jul 1994 | 29
    ///     Jan 1996 | 30
    ///     Jul 1997 | 31
    ///     Jan 1999 | 32
    ///     Jan 2006 | 33
    ///     Jan 2009 | 34
    ///     Jul 2012 | 35
    ///     Jul 2015 | 36
    ///     Jan 2017 | 37
    ///
    /// As of 2020, the future of the leap second and the relation between UTC and TAI remains uncertain.
    ///
    _traits_::TypeOf::difference_tai_minus_utc difference_tai_minus_utc{};
};

inline nunavut::support::SerializeResult serialize(const TAIInfo_0_1& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 16UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // saturated uint10 difference_tai_minus_utc
        std::uint16_t _sat0_ = obj.difference_tai_minus_utc;
        if (_sat0_ > 1023U)
        {
            _sat0_ = 1023U;
        }
        const auto _result3_ = out_buffer.setUxx(_sat0_, 10U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(10U);
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
    return out_buffer.offset_bytes_ceil();
}

inline nunavut::support::SerializeResult deserialize(TAIInfo_0_1& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // saturated uint10 difference_tai_minus_utc
    obj.difference_tai_minus_utc = in_buffer.getU16(10U);
    in_buffer.add_offset(10U);
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace time
} // namespace uavcan

#endif // UAVCAN_TIME_TAI_INFO_0_1_HPP_INCLUDED
