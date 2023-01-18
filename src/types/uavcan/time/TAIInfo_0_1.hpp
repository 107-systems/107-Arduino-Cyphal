//
// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-1.9.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl
// Generated at:  2023-01-18 06:06:50.231622 UTC
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
//     runtime_platform:  Linux-5.15.0-58-generic-x86_64-with-glibc2.35
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  True
//     enable_override_variable_array_capacity:  False
//     std:  c++14
//     variable_array_type_template:
//     variable_array_type_include:
//     cast_format:  static_cast<{type}>({value})
//     enable_allocator_support:  False
// Uses Language Features
//     Uses std_variant:no
#ifndef UAVCAN_TIME_TAI_INFO_0_1_HPP_INCLUDED
#define UAVCAN_TIME_TAI_INFO_0_1_HPP_INCLUDED

#include "nunavut/support/serialization.hpp"
#include <cstdint>

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
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/time/TAIInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
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
// | This implementation uses a minimal variant implementation that is forward-compatible with the same types generated
// | using the C++17 variant type in the standard library. This minimal variant implementation is limited in the
// | following ways:
// |    1. Supports only emplace and get_if.
// |    2. Only support access by index (see the IndexOf property of the VariantType).
// |    3. This object cannot be copy-constructed nor move-constructed.
// |    4. There is an O(n) lookup in this object's destructor and in the
// |       emplace method.
// |
// | The C++17 version of this object will define the same emplace and get_if wrappers so code written against this
// | version will be fully-forward compatible, but the C++17 version exposes the variant type directly allowing full
// | use of that standard library feature – it is therefore not backwards-compatible.
// +-------------------------------------------------------------------------------------------------------------------+
///
/// This data types defines constants and runtime values pertaining to the International Atomic Time, also known as TAI.
/// See https://en.wikipedia.org/wiki/International_Atomic_Time.
/// The relationship between the three major time systems -- TAI, GPS, and UTC -- is as follows:
///   TAI = GPS + 19 seconds
///   TAI = UTC + LS + 10 seconds
/// Where "LS" is the current number of leap seconds: https://en.wikipedia.org/wiki/Leap_second.
/// Cyphal applications should only rely on TAI whenever a global time system is needed.
/// GPS time is strongly discouraged for reasons of consistency across different positioning systems and applications.
///
struct TAIInfo_0_1 final
{
    // +---------------------------------------------------------------------------------------------------------------+
    // | PORT IDENTIFIERS
    // +---------------------------------------------------------------------------------------------------------------+
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

    static constexpr std::size_t EXTENT_BYTES                    =2UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =2UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

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
    /// This value may change states between known and unknown while the master is running,
    /// depending on its ability to obtain robust values from external sources.
    /// This value may change twice a year, possibly while the system is running;
    /// https://en.wikipedia.org/wiki/Leap_second.
    /// Since the rotation of Earth is decelerating, this value may only be positive. Do not use outside Earth.
    /// For reference, here is the full list of recorded TAI-UTC difference values, valid at the time of writing:
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
    /// As of 2020, the future of the leap second and the relation between UTC and TAI remains uncertain.
    ///
    std::uint16_t difference_tai_minus_utc;

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 16UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        {   // saturated uint10 difference_tai_minus_utc
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(10ULL <= out_buffer.size());
            std::uint16_t _sat0_ = difference_tai_minus_utc;
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
        NUNAVUT_ASSERT(out_buffer.offset() == 16ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // saturated uint10 difference_tai_minus_utc
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        difference_tai_minus_utc = in_buffer.getU16(10U);
        in_buffer.add_offset(10U);
        in_buffer.align_offset_to<8U>();
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
        NUNAVUT_ASSERT(capacity_bits >= _bits_got_);
        return { static_cast<std::size_t>(_bits_got_ / 8U) };
    }
};

} // namespace time
} // namespace uavcan

#endif // UAVCAN_TIME_TAI_INFO_0_1_HPP_INCLUDED
