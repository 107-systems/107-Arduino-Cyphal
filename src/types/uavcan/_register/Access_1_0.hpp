//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/register/384.Access.1.0.dsdl
// Generated at:  2023-03-10 05:17:53.893140 UTC
// Is deprecated: no
// Fixed port-ID: 384
// Full name:     uavcan.register.Access
// Type Version:  1.0
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
#ifndef UAVCAN_REGISTER_ACCESS_1_0_HPP_INCLUDED
#define UAVCAN_REGISTER_ACCESS_1_0_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <types/uavcan/_register/Name_1_0.hpp>
#include <types/uavcan/_register/Value_1_0.hpp>
#include <types/uavcan/time/SynchronizedTimestamp_1_0.hpp>
#include <limits>

namespace uavcan
{
namespace _register
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/register/384.Access.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/register/384.Access.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/register/384.Access.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/register/384.Access.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/uavcan/register/384.Access.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/register/384.Access.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/register/384.Access.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/register/384.Access.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/register/384.Access.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

namespace Access
{

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+
///
/// Registers are strongly-typed named values used to store the configuration parameters of a node.
/// This service is used to write and read a register.
///
///
///   READ/WRITE BEHAVIORS
///
/// The write operation is performed first, unless skipped by sending an empty value in the request.
/// The server may attempt to convert the type of the supplied value to the correct type if there is a type mismatch
/// (e.g. uint8 may be converted to uint16); however, servers are not required to perform implicit type conversion,
/// and the rules of such conversion are not explicitly specified, so this behavior should not be relied upon.
///
/// On the next step the register will be read regardless of the outcome of the write operation. As such, if the write
/// operation could not be performed (e.g. due to a type mismatch or any other issue), the register will retain its old
/// value. By evaluating the response the caller can determine whether the register was written successfully.
///
/// The write-read sequence is not guaranteed to be atomic, meaning that external influences may cause the register to
/// change its value between the write and the subsequent read operation. The caller is responsible for handling that
/// case properly.
///
/// The timestamp provided in the response corresponds to the time when the register was read. The timestamp may
/// be empty if the server does not support timestamping or its clock is not (yet) synchronized with the network.
///
/// If only read is desired, but not write, the caller shall provide a value of type 'empty'. That will signal the
/// server
/// that the write operation shall be skipped, and it will proceed to read the register immediately.
///
/// If the requested register does not exist, the write operation will have no effect and the returned value will be
/// empty. Existing registers should not return 'empty' when read since that would make them indistinguishable from
/// nonexistent registers.
///
///
///   REGISTER DEFINITION REQUIREMENTS
///
/// Registers shall never change their type or flags as long as the server is running. Meaning that:
///   - Mutability and persistence flags cannot change their states.
///   - Read operations shall always return values of the same type and same dimensionality.
///     The dimensionality requirement does not apply to inherently variable-length values such as strings and
///     unstructured chunks.
///
/// Register name should contain only:
///   - Lowercase ASCII alphanumeric characters (a-z, 0-9)
///   - Full stop (.)
///   - Low line (underscore) (_)
/// With the following limitations/recommendations:
///   - The name shall not begin with a decimal digit (0-9).
///   - The name shall neither begin nor end with a full stop.
///   - A low line shall not be followed by a non-alphanumeric character.
///   - The name should contain at least one full stop character.
/// Other patterns and ASCII characters are reserved for special function registers (introduced below).
///
///
///   ENVIRONMENT VARIABLES
///
/// This section applies only to software nodes executed in a high-level operating system that supports environment
/// variables or an equivalent mechanism.
///
/// When a software node is launched, it is usually necessary to provide some of its configuration information early,
/// particularly that which is related to Cyphal networking, before the node is started. Environment variables offer
/// a convenient way of addressing this. Software nodes that support the register interface should evaluate the
/// available environment variables during initialization and update their registers (whether they are stored in
/// a persistent storage or in memory) accoringly. This should be completed before the first register read access.
///
/// A register name is mapped to an environment variable name as follows:
///   - the name is upper-cased;
///   - full stop characters are replaced with double low line characters.
/// For example: 'motor.inductance_dq' is mapped to 'MOTOR__INDUCTANCE_DQ'.
///
/// Register values are represented in environment variables as follows:
///   - string:                         utf-8 or platform-specific
///   - unstructured:                   as-is
///   - bit, integer*, natural*, real*: space-separated decimals
///
/// If an environment variable matches the name of an existing register but its value cannot be converted to the
/// register's type, an error should be raised.
///
/// If an environment variable does not match the name of any register, it may be ignored. However, if the
/// implementation
/// can reliably deduce the type and purpose of the register, it may create one automatically. This provision is to
/// support applications where the register schema may be altered by configuration.
///
///
///   SPECIAL FUNCTION REGISTERS
///
/// The following optional special function register names are defined:
///   - suffix '<' is used to define an immutable persistent value that contains the maximum value
///     of the respective register.
///   - suffix '>' is like above, used to define the minimum value of the respective register.
///   - suffix '=' is like above, used to define the default value of the respective register.
///   - prefix '*' is reserved for raw memory access (to be defined later).
/// Examples:
///   - register name "system.parameter"
///   - maximum value is contained in the register named "system.parameter<" (optional)
///   - minimum value is contained in the register named "system.parameter>" (optional)
///   - default value is contained in the register named "system.parameter=" (optional)
///
/// The type and dimensionality of the special function registers containing the minimum, maximum, and the default
/// value of a register shall be the same as those of the register they relate to.
///
/// If a written value exceeds the minimum/maximum specified by the respective special function registers,
/// the server may either adjust the value automatically, or to retain the old value, depending on which behavior
/// suits the objectives of the application better.
/// The values of registers containing non-scalar numerical entities should be compared elementwise.
///
///
///   STANDARD REGISTERS
///
/// The following table specifies the register name patterns that are reserved by the specification for
/// common functions. These conventions are not mandatory to follow, but implementers are recommended to adhere because
/// they enable enhanced introspection capabilities and simplify device configuration and diagnostics.
///
///   REGISTER NAME PATTERN                               TYPE            FLAGS                   RECOMMENDED DEFAULT
/// =====================================================================================================================
///
///   uavcan.node.id                                      natural16[1]    mutable, persistent     65535 (unset/PnP)
///
/// Contains the node-ID of the local node. Values above the maximum valid node-ID for the current transport
/// indicate that the node-ID is not set; if plug-and-play is supported, it will be used by the node to obtain an
/// automatic node-ID. Invalid values other than 65535 should be avoided for consistency.
///
/// ---------------------------------------------------------------------------------------------------------------------
///
///   uavcan.node.description                             string          mutable, persistent     (empty)
///
/// User/integrator-defined, human-readable description of this specific node.
/// This is intended for use by a system integrator and should not be set by the manufacturer of a component.
/// For example: on a quad-rotor drone this might read "motor 2" for one of the ESC nodes.
///
/// ---------------------------------------------------------------------------------------------------------------------
///
///   uavcan.pub.PORT_NAME.id                             natural16[1]    mutable, persistent     65535 (unset, invalid)
///   uavcan.sub.PORT_NAME.id                             ditto           ditto                   ditto
///   uavcan.cln.PORT_NAME.id                             ditto           ditto                   ditto
///   uavcan.srv.PORT_NAME.id                             ditto           ditto                   ditto
///
/// Publication/subscription/client/server port-ID, respectively. These registers are configured by the system
/// integrator
/// or an autoconfiguration authority when the node is first connected to a network.
///
/// The "PORT_NAME" defines the human-friendly name of the port, which is related to the corresponding function
/// or a network service supported by the node. The name shall match the following POSIX ERE expression:
///
///   [a-zA-Z_][a-zA-Z0-9_.]*
///
/// The names are defined by the vendor of the node. The user/integrator is expected to understand their meaning and
/// relation to the functional capabilities of the node by reading the technical documentation provided by the vendor.
///
/// A port whose port-ID register is unset (invalid value) remains inactive (unused); the corresponding function may
/// be disabled. For example, a register named "uavcan.pub.measurement.id" defines the subject-ID of a measurement
/// published by this node; if the register contains an invalid value (above the maximum valid subject-ID),
/// said measurement is not published.
///
/// The same name is used in other similar registers defined below. Network introspection and autoconfiguration tools
/// will expect to find a register of this form for every configurable port supported by the node.
///
/// ---------------------------------------------------------------------------------------------------------------------
///
///   uavcan.pub.PORT_NAME.type                           string          immutable, persistent   N/A
///   uavcan.sub.PORT_NAME.type                           ditto           ditto                   ditto
///   uavcan.cln.PORT_NAME.type                           ditto           ditto                   ditto
///   uavcan.srv.PORT_NAME.type                           ditto           ditto                   ditto
///
/// Publication/subscription/client/server full data type name and dot-separated version numbers, respectively.
/// These registers are set by the vendor once and typically they are to remain unchanged (hence "immutable").
/// The "PORT_NAME" defines the human-friendly name of the port as specified above.
/// For example, a register named "uavcan.pub.measurement.type" may contain "uavcan.si.sample.angle.Quaternion.1.0".
///
/// ---------------------------------------------------------------------------------------------------------------------
///
///   uavcan.diagnostic.*
///
/// Prefix reserved for future use.
///
/// ---------------------------------------------------------------------------------------------------------------------
///
///   uavcan.can.bitrate                                  natural32[2]    implementation-defined  implementation-defined
///   uavcan.can.iface                                    string          mutable, persistent     implementation-defined
///
/// These registers are only relevant for nodes that support Cyphal/CAN.
///
/// uavcan.can.bitrate defines the CAN bus bit rate: the first value is the arbitration bit rate, the second is the
/// data phase bit rate. Nodes that support only Classic CAN should ignore the second value. Nodes that support CAN FD
/// should initialize in the Classic CAN mode (MTU 8 bytes, BRS flag not set) if the values are equal. If CAN bitrate
/// is not configurable or is always auto-detected, this register may be omitted or made immutable; otherwise it should
/// be mutable and persistent.
///
/// uavcan.can.iface is only relevant for software nodes or nodes that are capable of using different CAN interfaces.
/// The value is a space-separated list of CAN interface names to use. The name format is implementation-defined
/// (for example, "can0").
///
/// ---------------------------------------------------------------------------------------------------------------------
///
///   uavcan.udp.*
///
/// Prefix reserved for future use.
///
/// ---------------------------------------------------------------------------------------------------------------------#
///
///   uavcan.serial.*
///
/// Prefix reserved for future use.
///
/// ---------------------------------------------------------------------------------------------------------------------
///
struct Request_1_0 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 384U;
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
        static constexpr std::size_t ExtentBytes                  = 515UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 515UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using name = uavcan::_register::Name_1_0;
            using value = uavcan::_register::Value_1_0;
        };
    };

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// The name of the accessed register. Shall not be empty.
    /// Use the List service to obtain the list of registers on the node.
    ///
    _traits_::TypeOf::name name;
    ///
    /// Value to be written. Empty if no write is required.
    ///
    _traits_::TypeOf::value value;
};

inline nunavut::support::SerializeResult serialize(const Request_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 4120UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // uavcan.register.Name.1.0 name
        std::size_t _size_bytes0_ = 256UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.name, _subspan0_.value());
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
    {   // uavcan.register.Value.1.0 value
        std::size_t _size_bytes0_ = 259UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.value, _subspan0_.value());
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

inline nunavut::support::SerializeResult deserialize(Request_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // uavcan.register.Name.1.0 name
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.name, in_buffer.subspan());
            if(_err1_){
                _size_bytes1_ = _err1_.value();
            }else{
                return -_err1_.error();
            }
        }
        in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
    }
    in_buffer.align_offset_to<8U>();
    // uavcan.register.Value.1.0 value
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.value, in_buffer.subspan());
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

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+

struct Response_1_0 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 384U;
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
        static constexpr std::size_t ExtentBytes                  = 267UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 267UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using timestamp = uavcan::time::SynchronizedTimestamp_1_0;
            using _mutable = bool;
            using persistent = bool;
            using value = uavcan::_register::Value_1_0;
        };
    };

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// The moment of time when the register was read (not written).
    /// Zero if the server does not support timestamping.
    ///
    _traits_::TypeOf::timestamp timestamp;
    ///
    /// Mutable means that the register can be written using this service.
    /// Immutable registers cannot be written, but that doesn't imply that their values are constant (unchanging).
    ///
    _traits_::TypeOf::_mutable _mutable{};
    ///
    /// Persistence means that the register retains its value permanently across power cycles or any other changes
    /// in the state of the server, until it is explicitly overwritten (either via Cyphal, any other interface,
    /// or by the device itself).
    ///
    /// The server is recommended to manage persistence automatically by committing changed register values to a
    /// non-volatile storage automatically as necessary. If automatic persistence management is not implemented, it
    /// can be controlled manually via the standard service uavcan.node.ExecuteCommand. The same service can be used
    /// to return the configuration to a factory-default state. Please refer to its definition for more information.
    ///
    /// Consider the following examples:
    ///   - Configuration parameters are usually both mutable and persistent.
    ///   - Diagnostic values are usually immutable and non-persisient.
    ///   - Registers that trigger an activity when written are typically mutable but non-persisient.
    ///   - Registers that contain factory-programmed values such as calibration coefficients that can't
    ///     be changed are typically immutable but persistent.
    ///
    _traits_::TypeOf::persistent persistent{};
    ///
    /// The value of the register when it was read (beware of race conditions).
    /// Registers never change their type and dimensionality while the node is running.
    /// Empty value means that the register does not exist (in this case the flags should be cleared/ignored).
    /// By comparing the returned value against the write request the caller can determine whether the register
    /// was written successfully, unless write was not requested.
    /// An empty value shall never be returned for an existing register.
    ///
    _traits_::TypeOf::value value;
};

inline nunavut::support::SerializeResult serialize(const Response_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 2136UL)
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
    {   // saturated bool mutable
        auto _result2_ = out_buffer.setBit(obj._mutable);
        if(not _result2_){
            return -_result2_.error();
        }
        out_buffer.add_offset(1UL);
    }
    {   // saturated bool persistent
        auto _result2_ = out_buffer.setBit(obj.persistent);
        if(not _result2_){
            return -_result2_.error();
        }
        out_buffer.add_offset(1UL);
    }
    {   // void6
        auto _result1_ = out_buffer.setZeros(6UL);
        if(not _result1_){
            return -_result1_.error();
        }
        out_buffer.add_offset(6UL);
    }
    {
        const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
        if(not _result0_){
            return -_result0_.error();
        }
    }
    {   // uavcan.register.Value.1.0 value
        std::size_t _size_bytes0_ = 259UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize(obj.value, _subspan0_.value());
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

inline nunavut::support::SerializeResult deserialize(Response_1_0& obj,
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
    // saturated bool mutable
    obj._mutable = in_buffer.getBit();
    in_buffer.add_offset(1U);
    // saturated bool persistent
    obj.persistent = in_buffer.getBit();
    in_buffer.add_offset(1U);
    // void6
    in_buffer.add_offset(6);
    in_buffer.align_offset_to<8U>();
    // uavcan.register.Value.1.0 value
    {
        std::size_t _size_bytes1_ = in_buffer.size() / 8U;
        {
            const auto _err1_ = deserialize(obj.value, in_buffer.subspan());
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

}  // namespace Access

struct Access_1_0
{
    Access_1_0() = delete;

    using Request  = Access::Request_1_0;
    using Response = Access::Response_1_0;

    struct _traits_
    {
        _traits_() = delete;

        static constexpr bool IsServiceType = true;
        static constexpr bool IsService = true;
        static constexpr bool IsRequest = false;
        static constexpr bool IsResponse = false;
    };
};

} // namespace _register
} // namespace uavcan

#endif // UAVCAN_REGISTER_ACCESS_1_0_HPP_INCLUDED
