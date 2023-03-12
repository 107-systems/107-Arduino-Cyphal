//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/time/510.GetSynchronizationMasterInfo.0.1.dsdl
// Generated at:  2023-03-10 05:17:53.540735 UTC
// Is deprecated: no
// Fixed port-ID: 510
// Full name:     uavcan.time.GetSynchronizationMasterInfo
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
#ifndef UAVCAN_TIME_GET_SYNCHRONIZATION_MASTER_INFO_0_1_HPP_INCLUDED
#define UAVCAN_TIME_GET_SYNCHRONIZATION_MASTER_INFO_0_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <types/uavcan/time/TAIInfo_0_1.hpp>
#include <types/uavcan/time/TimeSystem_0_1.hpp>
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
              "/tmp/public_regulated_data_types/uavcan/time/510.GetSynchronizationMasterInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/time/510.GetSynchronizationMasterInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/time/510.GetSynchronizationMasterInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/time/510.GetSynchronizationMasterInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/uavcan/time/510.GetSynchronizationMasterInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/time/510.GetSynchronizationMasterInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/time/510.GetSynchronizationMasterInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/time/510.GetSynchronizationMasterInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/time/510.GetSynchronizationMasterInfo.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

namespace GetSynchronizationMasterInfo
{

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+
///
/// Every node that acts as a time synchronization master, or is capable of acting as such,
/// should support this service.
/// Its objective is to provide information about which time system is currently used in the network.
///
/// Once a time system is chosen, it cannot be changed as long as at least one node on the network is running.
/// In other words, the time system cannot be changed while the network is operating.
/// An implication of this is that if there are redundant time synchronization masters, they all shall
/// use the same time system always.
///
struct Request_0_1 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 510U;
        static constexpr bool IsServiceType  = true;
        static constexpr bool IsService      = false;
        static constexpr bool IsRequest      = true;
        static constexpr bool IsResponse     = false;
        /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
        /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
        /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
        /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
        /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
        /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
        /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
        static constexpr std::size_t ExtentBytes                  = 48UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 0UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
    };
};

inline nunavut::support::SerializeResult serialize(const Request_0_1& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    (void)(out_buffer);
    (void)(obj);
    return 0U;
}

inline nunavut::support::SerializeResult deserialize(Request_0_1& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    (void)(in_buffer);
    (void)(obj);
    return 0;
}

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+

struct Response_0_1 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 510U;
        static constexpr bool IsServiceType  = true;
        static constexpr bool IsService      = false;
        static constexpr bool IsRequest      = false;
        static constexpr bool IsResponse     = true;
        /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
        /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
        /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
        /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
        /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
        /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
        /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
        static constexpr std::size_t ExtentBytes                  = 192UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 7UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using error_variance = float;
            using time_system = uavcan::time::TimeSystem_0_1;
            using tai_info = uavcan::time::TAIInfo_0_1;
        };
    };

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// [second^2]
    /// Error variance, in second^2, of the time value reported by this master.
    /// This value is allowed to change freely while the master is running.
    /// For example, if the master's own clock is synchronized with a GNSS, the error variance is expected to increase
    /// as signal reception deteriorates. If the signal is lost, this value is expected to grow steadily, the rate of
    /// growth would be dependent on the quality of the time keeping hardware available locally (bad hardware yields
    /// faster growth). Once the signal is regained, this value would drop back to nominal.
    ///
    _traits_::TypeOf::error_variance error_variance{};
    ///
    /// Time system currently in use by the master.
    /// Cannot be changed while the network is operating.
    ///
    _traits_::TypeOf::time_system time_system;
    ///
    /// Actual information about TAI provided by this master, if supported.
    /// The fields in this data type are optional.
    ///
    _traits_::TypeOf::tai_info tai_info;
};

inline nunavut::support::SerializeResult serialize(const Response_0_1& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 56UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // saturated float32 error_variance
        // Saturation code not emitted -- assume the native representation of float32 is conformant.
        static_assert(NUNAVUT_PLATFORM_IEEE754_FLOAT, "Native IEEE754 binary32 required. TODO: relax constraint");
        auto _result4_ = out_buffer.setF32(obj.error_variance);
        if(not _result4_){
            return -_result4_.error();
        }
        out_buffer.add_offset(32U);
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // uavcan.time.TimeSystem.0.1 time_system
        std::size_t _size_bytes0_ = 1UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.time_system, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // uavcan.time.TAIInfo.0.1 tai_info
        std::size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.tai_info, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
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

inline nunavut::support::SerializeResult deserialize(Response_0_1& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // saturated float32 error_variance
    obj.error_variance = in_buffer.getF32();
    in_buffer.add_offset(32U);
    in_buffer.align_offset_to<8U>();
    // uavcan.time.TimeSystem.0.1 time_system
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.time_system, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    in_buffer.align_offset_to<8U>();
    // uavcan.time.TAIInfo.0.1 tai_info
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.tai_info, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

}  // namespace GetSynchronizationMasterInfo

struct GetSynchronizationMasterInfo_0_1
{
    GetSynchronizationMasterInfo_0_1() = delete;

    using Request  = GetSynchronizationMasterInfo::Request_0_1;
    using Response = GetSynchronizationMasterInfo::Response_0_1;

    struct _traits_
    {
        _traits_() = delete;

        static constexpr bool IsServiceType = true;
        static constexpr bool IsService = true;
        static constexpr bool IsRequest = false;
        static constexpr bool IsResponse = false;
    };
};

} // namespace time
} // namespace uavcan

#endif // UAVCAN_TIME_GET_SYNCHRONIZATION_MASTER_INFO_0_1_HPP_INCLUDED
