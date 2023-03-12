//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/node/435.ExecuteCommand.1.0.dsdl
// Generated at:  2023-03-10 05:17:53.835623 UTC
// Is deprecated: yes
// Fixed port-ID: 435
// Full name:     uavcan.node.ExecuteCommand
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
//           _____  ______ _____  _____  ______ _____       _______ ______ _____
//          |  __ `|  ____|  __ `|  __ `|  ____/ ____|   /`|__   __|  ____|  __ `
//          | |  | | |__  | |__) | |__) | |__ | |       /  `  | |  | |__  | |  | |
//          | |  | |  __| |  ___/|  _  /|  __|| |      / /` ` | |  |  __| | |  | |
//          | |__| | |____| |    | | ` `| |___| |____ / ____ `| |  | |____| |__| |
//          |_____/|______|_|    |_|  `_`______`_____/_/    `_`_|  |______|_____/
//
// WARNING: this data type is deprecated and is nearing the end of its life cycle. Seek replacement.
#ifndef UAVCAN_NODE_EXECUTE_COMMAND_1_0_HPP_INCLUDED
#define UAVCAN_NODE_EXECUTE_COMMAND_1_0_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <nunavut/support/variable_length_array.hpp>
#include <cstdint>
#include <limits>

namespace uavcan
{
namespace node
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/node/435.ExecuteCommand.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/node/435.ExecuteCommand.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/node/435.ExecuteCommand.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/node/435.ExecuteCommand.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/uavcan/node/435.ExecuteCommand.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/node/435.ExecuteCommand.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/node/435.ExecuteCommand.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/node/435.ExecuteCommand.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/node/435.ExecuteCommand.1.0.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

namespace ExecuteCommand
{

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+
///
/// Instructs the server node to execute or commence execution of a simple predefined command.
/// All standard commands are optional; i.e., not guaranteed to be supported by all nodes.
///
[[deprecated("uavcan.node.ExecuteCommand.Request.1.0 is reaching the end of its life; there may be a newer version available")]]
struct Request_1_0 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 435U;
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
        static constexpr std::size_t ExtentBytes                  = 300UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 115UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using command = std::uint16_t;
            using parameter = nunavut::support::VariableLengthArray<std::uint8_t, 112>;
        };
    };

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+
    ///
    /// Reboot the node.
    /// Note that some standard commands may or may not require a restart in order to take effect; e.g., factory reset.
    ///
    static constexpr std::uint16_t COMMAND_RESTART = 65535U;
    ///
    /// Shut down the node; further access will not be possible until the power is turned back on.
    ///
    static constexpr std::uint16_t COMMAND_POWER_OFF = 65534U;
    ///
    /// Begin the software update process using uavcan.file.Read. This command makes use of the "parameter" field below.
    /// The parameter contains the path to the new software image file to be downloaded by the server from the client
    /// using the standard service uavcan.file.Read. Observe that this operation swaps the roles of the client and
    /// the server.
    ///
    /// Upon reception of this command, the server (updatee) will evaluate whether it is possible to begin the
    /// software update process. If that is deemed impossible, the command will be rejected with one of the
    /// error codes defined in the response section of this definition (e.g., BAD_STATE if the node is currently
    /// on-duty and a sudden interruption of its activities is considered unsafe, and so on).
    /// If an update process is already underway, the updatee should abort the process and restart with the new file,
    /// unless the updatee can determine that the specified file is the same file that is already being downloaded,
    /// in which case it is allowed to respond SUCCESS and continue the old update process.
    /// If there are no other conditions precluding the requested update, the updatee will return a SUCCESS and
    /// initiate the file transfer process by invoking the standard service uavcan.file.Read repeatedly until the file
    /// is transferred fully (please refer to the documentation for that data type for more information about its
    /// usage).
    ///
    /// While the software is being updated, the updatee should set its mode (the field "mode" in uavcan.node.Heartbeat)
    /// to MODE_SOFTWARE_UPDATE. Please refer to the documentation for uavcan.node.Heartbeat for more information.
    ///
    /// It is recognized that most systems will have to interrupt their normal services to perform the software update
    /// (unless some form of software hot swapping is implemented, as is the case in some high-availability systems).
    ///
    /// Microcontrollers that are requested to update their firmware may need to stop execution of their current
    /// firmware
    /// and start the embedded bootloader (although other approaches are possible as well). In that case,
    /// while the embedded bootloader is running, the mode reported via the message uavcan.node.Heartbeat should be
    /// MODE_SOFTWARE_UPDATE as long as the bootloader is runing, even if no update-related activities
    /// are currently underway. For example, if the update process failed and the bootloader cannot load the software,
    /// the same mode MODE_SOFTWARE_UPDATE will be reported.
    /// It is also recognized that in a microcontroller setting, the application that served the update request will
    /// have
    /// to pass the update-related metadata (such as the node-ID of the server and the firmware image file path) to
    /// the embedded bootloader. The tactics of that transaction lie outside of the scope of this specification.
    ///
    static constexpr std::uint16_t COMMAND_BEGIN_SOFTWARE_UPDATE = 65533U;
    ///
    /// Return the node's configuration back to the factory default settings (may require restart).
    /// Due to the uncertainty whether a restart is required, generic interfaces should always force a restart.
    ///
    static constexpr std::uint16_t COMMAND_FACTORY_RESET = 65532U;
    ///
    /// Cease activities immediately, enter a safe state until restarted.
    /// Further operation may no longer be possible until a restart command is executed.
    ///
    static constexpr std::uint16_t COMMAND_EMERGENCY_STOP = 65531U;
    ///
    /// This command instructs the node to store the current configuration parameter values and other persistent states
    /// to the non-volatile storage. Nodes are allowed to manage persistent states automatically, obviating the need for
    /// this command by committing all such data to the non-volatile memory automatically as necessary. However, some
    /// nodes may lack this functionality, in which case this parameter should be used. Generic interfaces should always
    /// invoke this command in order to ensure that the data is stored even if the node doesn't implement automatic
    /// persistence management.
    ///
    static constexpr std::uint16_t COMMAND_STORE_PERSISTENT_STATES = 65530U;

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// Standard pre-defined commands are at the top of the range (defined below).
    /// Vendors can define arbitrary, vendor-specific commands in the bottom part of the range (starting from zero).
    /// Vendor-specific commands shall not use identifiers above 32767.
    ///
    _traits_::TypeOf::command command{};
    ///
    /// A string parameter supplied to the command. The format and interpretation is command-specific.
    /// The standard commands do not use this field (ignore it), excepting the following:
    ///   - COMMAND_BEGIN_SOFTWARE_UPDATE
    ///
    _traits_::TypeOf::parameter parameter{};
};

inline nunavut::support::SerializeResult serialize(const Request_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 920UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // saturated uint16 command
        // Saturation code not emitted -- native representation matches the serialized representation.
        const auto _result3_ = out_buffer.setUxx(obj.command, 16U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(16U);
    }
    {   // saturated uint8[<=112] parameter
        if (obj.parameter.size() > 112)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        // Array length prefix: truncated uint8
        const auto _result3_ = out_buffer.setUxx(obj.parameter.size(), 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
        for (std::size_t _index2_ = 0U; _index2_ < obj.parameter.size(); ++_index2_)
        {
            // Saturation code not emitted -- native representation matches the serialized representation.
            const auto _result3_ = out_buffer.setUxx(obj.parameter[_index2_], 8U);
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

inline nunavut::support::SerializeResult deserialize(Request_1_0& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    // saturated uint16 command
    obj.command = in_buffer.getU16(16U);
    in_buffer.add_offset(16U);
    // saturated uint8[<=112] parameter
    {
        // Array length prefix: truncated uint8
    const std::size_t _size0_ = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
        if ( _size0_ > 112U)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        obj.parameter.reserve(_size0_);
        for (std::size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
        {
            // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
            // move semantics instead of assuming C-style containers
            obj.parameter.push_back();
            obj.parameter[_index5_] = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
        }
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

[[deprecated("uavcan.node.ExecuteCommand.Response.1.0 is reaching the end of its life; there may be a newer version available")]]
struct Response_1_0 final
{
    struct _traits_  // The name is surrounded with underscores to avoid collisions with DSDL attributes.
    {
        _traits_() = delete;
        static constexpr bool HasFixedPortID = true;
        static constexpr std::uint16_t FixedPortId = 435U;
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
        static constexpr std::size_t ExtentBytes                  = 48UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 1UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using status = std::uint8_t;
        };
    };

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+
    ///
    /// Started or executed successfully
    ///
    static constexpr std::uint8_t STATUS_SUCCESS = 0U;
    ///
    /// Could not start or the desired outcome could not be reached
    ///
    static constexpr std::uint8_t STATUS_FAILURE = 1U;
    ///
    /// Denied due to lack of authorization
    ///
    static constexpr std::uint8_t STATUS_NOT_AUTHORIZED = 2U;
    ///
    /// The requested command is not known or not supported
    ///
    static constexpr std::uint8_t STATUS_BAD_COMMAND = 3U;
    ///
    /// The supplied parameter cannot be used with the selected command
    ///
    static constexpr std::uint8_t STATUS_BAD_PARAMETER = 4U;
    ///
    /// The current state of the node does not permit execution of this command
    ///
    static constexpr std::uint8_t STATUS_BAD_STATE = 5U;
    ///
    /// The operation should have succeeded but an unexpected failure occurred
    ///
    static constexpr std::uint8_t STATUS_INTERNAL_ERROR = 6U;

    // +----------------------------------------------------------------------+
    // | FIELDS
    // +----------------------------------------------------------------------+
    ///
    /// The result of the request.
    ///
    _traits_::TypeOf::status status{};
};

inline nunavut::support::SerializeResult serialize(const Response_1_0& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 8UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    {   // saturated uint8 status
        // Saturation code not emitted -- native representation matches the serialized representation.
        const auto _result3_ = out_buffer.setUxx(obj.status, 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
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
    // saturated uint8 status
    obj.status = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

}  // namespace ExecuteCommand

struct ExecuteCommand_1_0
{
    ExecuteCommand_1_0() = delete;

    using Request  = ExecuteCommand::Request_1_0;
    using Response = ExecuteCommand::Response_1_0;

    struct _traits_
    {
        _traits_() = delete;

        static constexpr bool IsServiceType = true;
        static constexpr bool IsService = true;
        static constexpr bool IsRequest = false;
        static constexpr bool IsResponse = false;
    };
};

} // namespace node
} // namespace uavcan

#endif // UAVCAN_NODE_EXECUTE_COMMAND_1_0_HPP_INCLUDED
