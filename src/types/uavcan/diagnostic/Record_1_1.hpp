//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/diagnostic/8184.Record.1.1.dsdl
// Generated at:  2023-03-10 05:17:53.330799 UTC
// Is deprecated: no
// Fixed port-ID: 8184
// Full name:     uavcan.diagnostic.Record
// Type Version:  1.1
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
#ifndef UAVCAN_DIAGNOSTIC_RECORD_1_1_HPP_INCLUDED
#define UAVCAN_DIAGNOSTIC_RECORD_1_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <nunavut/support/variable_length_array.hpp>
#include <types/uavcan/diagnostic/Severity_1_0.hpp>
#include <types/uavcan/time/SynchronizedTimestamp_1_0.hpp>
#include <cstdint>
#include <limits>

namespace uavcan
{
namespace diagnostic
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/diagnostic/8184.Record.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/diagnostic/8184.Record.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/diagnostic/8184.Record.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/diagnostic/8184.Record.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/uavcan/diagnostic/8184.Record.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/diagnostic/8184.Record.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/diagnostic/8184.Record.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/diagnostic/8184.Record.1.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/diagnostic/8184.Record.1.1.dsdl "
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
/// Generic human-readable text message for logging and displaying purposes.
/// Generally, it should be published at the lowest priority level.
///
struct Record_1_1 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 8184U;
        static constexpr bool IsServiceType = false;

        /// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
        /// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
        /// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
        /// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
        /// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
        /// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
        /// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
        static constexpr std::size_t ExtentBytes                  = 300UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 264UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using timestamp = uavcan::time::SynchronizedTimestamp_1_0;
            using severity = uavcan::diagnostic::Severity_1_0;
            using text = nunavut::support::VariableLengthArray<std::uint8_t, 255>;
        };
    };

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// Optional timestamp in the network-synchronized time system; zero if undefined.
    /// The timestamp value conveys the exact moment when the reported event took place.
    ///
    _traits_::TypeOf::timestamp timestamp;

    _traits_::TypeOf::severity severity;
    ///
    /// Message text.
    /// Normally, messages should be kept as short as possible, especially those of high severity.
    ///
    _traits_::TypeOf::text text{};
};

inline nunavut::support::SerializeResult serialize(const Record_1_1& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 2112UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // uavcan.time.SynchronizedTimestamp.1.0 timestamp
        std::size_t _size_bytes0_ = 7UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.timestamp, _subspan0_.value());
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
    {   // uavcan.diagnostic.Severity.1.0 severity
        std::size_t _size_bytes0_ = 1UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.severity, _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    {   // saturated uint8[<=255] text
        if (obj.text.size() > 255)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        // Array length prefix: truncated uint8
        const auto _result3_ = out_buffer.setUxx(obj.text.size(), 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
        for (std::size_t _index2_ = 0U; _index2_ < obj.text.size(); ++_index2_)
        {
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(obj.text[_index2_], 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
        }
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

inline nunavut::support::SerializeResult deserialize(Record_1_1& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // uavcan.time.SynchronizedTimestamp.1.0 timestamp
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.timestamp, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    in_buffer.align_offset_to<8U>();
    // uavcan.diagnostic.Severity.1.0 severity
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.severity, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    // saturated uint8[<=255] text
    {
        // Array length prefix: truncated uint8
    const std::size_t _size0_ = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
        if ( _size0_ > 255U)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        obj.text.reserve(_size0_);
        for (std::size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
        {
            // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
            // move semantics instead of assuming C-style containers
            obj.text.push_back();
            obj.text[_index5_] = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
        }
    }
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace diagnostic
} // namespace uavcan

#endif // UAVCAN_DIAGNOSTIC_RECORD_1_1_HPP_INCLUDED
