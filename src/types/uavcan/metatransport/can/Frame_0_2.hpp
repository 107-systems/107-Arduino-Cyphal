//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/metatransport/can/Frame.0.2.dsdl
// Generated at:  2023-03-10 05:17:53.468481 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     uavcan.metatransport.can.Frame
// Type Version:  0.2
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
#ifndef UAVCAN_METATRANSPORT_CAN_FRAME_0_2_HPP_INCLUDED
#define UAVCAN_METATRANSPORT_CAN_FRAME_0_2_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <types/uavcan/metatransport/can/DataClassic_0_1.hpp>
#include <types/uavcan/metatransport/can/DataFD_0_1.hpp>
#include <types/uavcan/metatransport/can/Error_0_1.hpp>
#include <types/uavcan/metatransport/can/RTR_0_1.hpp>
#include <cstdint>
#include <limits>
#include <variant>

namespace uavcan
{
namespace metatransport
{
namespace can
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Frame.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Frame.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Frame.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Frame.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Frame.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Frame.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Frame.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Frame.0.2.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Frame.0.2.dsdl "
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
/// Classic CAN or CAN FD frame representation. This is the top-level data type in its namespace.
///
struct Frame_0_2 final
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
        static constexpr std::size_t ExtentBytes                  = 71UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 71UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using _error = uavcan::metatransport::can::Error_0_1;
            using data_fd = uavcan::metatransport::can::DataFD_0_1;
            using data_classic = uavcan::metatransport::can::DataClassic_0_1;
            using remote_transmission_request = uavcan::metatransport::can::RTR_0_1;
        };
    };
    class VariantType final : public std::variant<
        ///
        /// CAN error (intentional or disturbance)
        ///
        _traits_::TypeOf::_error,
        ///
        /// Bit rate switch flag active
        ///
        _traits_::TypeOf::data_fd,
        ///
        /// Bit rate switch flag not active
        ///
        _traits_::TypeOf::data_classic,
        ///
        /// Bit rate switch flag not active
        ///
        _traits_::TypeOf::remote_transmission_request
    >
    {
    public:

        static const constexpr std::size_t variant_npos = std::variant_npos;

        struct IndexOf final
        {
            IndexOf() = delete;
            static constexpr const std::size_t _error = 0U;
            static constexpr const std::size_t data_fd = 1U;
            static constexpr const std::size_t data_classic = 2U;
            static constexpr const std::size_t remote_transmission_request = 3U;
        };
        static constexpr const std::size_t MAX_INDEX = 4U;

        template<size_t I, typename T>
        struct alternative;

        template<size_t I, typename... Types>
        struct alternative<I, std::variant<Types...>> final
        {
            using type = typename std::variant_alternative<I, std::variant<Types...>>::type;
        };

        template<size_t I, typename T>
        struct alternative<I, const T> final
        {
            using type = std::add_const_t<typename std::variant_alternative<I, T>::type>;
        };

        template<std::size_t I, class... Types>
        static constexpr typename alternative<I, std::variant<Types...>>::type* get_if(std::variant<Types...>* v) noexcept
        {
            return std::get_if<I, Types...>(v);
        }

        template<std::size_t I, class... Types>
        static constexpr const typename alternative<I, std::variant<Types...>>::type* get_if(const std::variant<Types...>* v) noexcept
        {
            return std::get_if<I, Types...>(v);
        }

    };

    VariantType union_value;

    bool is__error() const {
        return VariantType::IndexOf::_error == union_value.index();
    }

    typename std::add_pointer<_traits_::TypeOf::_error>::type get__error_if(){
        return VariantType::get_if<VariantType::IndexOf::_error>(&union_value);
    }

    typename std::add_pointer<const _traits_::TypeOf::_error>::type get__error_if() const{
        return VariantType::get_if<VariantType::IndexOf::_error>(&union_value);
    }

    typename std::add_lvalue_reference<_traits_::TypeOf::_error>::type get__error(){

        return *VariantType::get_if<VariantType::IndexOf::_error>(&union_value);
    }

    typename std::add_lvalue_reference<const _traits_::TypeOf::_error>::type get__error() const{

        return *VariantType::get_if<VariantType::IndexOf::_error>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<_traits_::TypeOf::_error>::type
    set__error(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::_error>(v...);
    }
    bool is_data_fd() const {
        return VariantType::IndexOf::data_fd == union_value.index();
    }

    typename std::add_pointer<_traits_::TypeOf::data_fd>::type get_data_fd_if(){
        return VariantType::get_if<VariantType::IndexOf::data_fd>(&union_value);
    }

    typename std::add_pointer<const _traits_::TypeOf::data_fd>::type get_data_fd_if() const{
        return VariantType::get_if<VariantType::IndexOf::data_fd>(&union_value);
    }

    typename std::add_lvalue_reference<_traits_::TypeOf::data_fd>::type get_data_fd(){

        return *VariantType::get_if<VariantType::IndexOf::data_fd>(&union_value);
    }

    typename std::add_lvalue_reference<const _traits_::TypeOf::data_fd>::type get_data_fd() const{

        return *VariantType::get_if<VariantType::IndexOf::data_fd>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<_traits_::TypeOf::data_fd>::type
    set_data_fd(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::data_fd>(v...);
    }
    bool is_data_classic() const {
        return VariantType::IndexOf::data_classic == union_value.index();
    }

    typename std::add_pointer<_traits_::TypeOf::data_classic>::type get_data_classic_if(){
        return VariantType::get_if<VariantType::IndexOf::data_classic>(&union_value);
    }

    typename std::add_pointer<const _traits_::TypeOf::data_classic>::type get_data_classic_if() const{
        return VariantType::get_if<VariantType::IndexOf::data_classic>(&union_value);
    }

    typename std::add_lvalue_reference<_traits_::TypeOf::data_classic>::type get_data_classic(){

        return *VariantType::get_if<VariantType::IndexOf::data_classic>(&union_value);
    }

    typename std::add_lvalue_reference<const _traits_::TypeOf::data_classic>::type get_data_classic() const{

        return *VariantType::get_if<VariantType::IndexOf::data_classic>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<_traits_::TypeOf::data_classic>::type
    set_data_classic(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::data_classic>(v...);
    }
    bool is_remote_transmission_request() const {
        return VariantType::IndexOf::remote_transmission_request == union_value.index();
    }

    typename std::add_pointer<_traits_::TypeOf::remote_transmission_request>::type get_remote_transmission_request_if(){
        return VariantType::get_if<VariantType::IndexOf::remote_transmission_request>(&union_value);
    }

    typename std::add_pointer<const _traits_::TypeOf::remote_transmission_request>::type get_remote_transmission_request_if() const{
        return VariantType::get_if<VariantType::IndexOf::remote_transmission_request>(&union_value);
    }

    typename std::add_lvalue_reference<_traits_::TypeOf::remote_transmission_request>::type get_remote_transmission_request(){

        return *VariantType::get_if<VariantType::IndexOf::remote_transmission_request>(&union_value);
    }

    typename std::add_lvalue_reference<const _traits_::TypeOf::remote_transmission_request>::type get_remote_transmission_request() const{

        return *VariantType::get_if<VariantType::IndexOf::remote_transmission_request>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<_traits_::TypeOf::remote_transmission_request>::type
    set_remote_transmission_request(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::remote_transmission_request>(v...);
    }
};

inline nunavut::support::SerializeResult serialize(const Frame_0_2& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 568UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    using VariantType = Frame_0_2::VariantType;
    const auto _index0_ = obj.union_value.index();
    {   // Union tag field: truncated uint8
        const auto _result3_ = out_buffer.setUxx(_index0_, 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
    }
    if (VariantType::IndexOf::_error == _index0_)
    {
        auto _ptr0_ = obj.get__error_if();
        std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize((*_ptr0_), _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    else if (VariantType::IndexOf::data_fd == _index0_)
    {
        auto _ptr0_ = obj.get_data_fd_if();
        std::size_t _size_bytes0_ = 70UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize((*_ptr0_), _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    else if (VariantType::IndexOf::data_classic == _index0_)
    {
        auto _ptr0_ = obj.get_data_classic_if();
        std::size_t _size_bytes0_ = 14UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize((*_ptr0_), _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    else if (VariantType::IndexOf::remote_transmission_request == _index0_)
    {
        auto _ptr0_ = obj.get_remote_transmission_request_if();
        std::size_t _size_bytes0_ = 5UL;  // Nested object (max) size, in bytes.
        auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
        if(not _subspan0_){
            return -_subspan0_.error();
        }
        auto _err0_ = serialize((*_ptr0_), _subspan0_.value());
        if (not _err0_)
        {
            return _err0_;
        }
        _size_bytes0_ = _err0_.value();
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        out_buffer.add_offset(_size_bytes0_ * 8U);
        //
    }
    else
    {
        return -nunavut::support::Error::RepresentationBadUnionTag;
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

inline nunavut::support::SerializeResult deserialize(Frame_0_2& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    using VariantType = Frame_0_2::VariantType;
    // Union tag field: truncated uint8
    auto _index3_ = obj.union_value.index();
    _index3_ = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
    if (VariantType::IndexOf::_error == _index3_)
    {
        obj.set__error();
        auto _ptr1_ = obj.get__error_if();
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            {
                const auto _err1_ = deserialize((*_ptr1_), in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
    }
    else if (VariantType::IndexOf::data_fd == _index3_)
    {
        obj.set_data_fd();
        auto _ptr1_ = obj.get_data_fd_if();
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            {
                const auto _err1_ = deserialize((*_ptr1_), in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
    }
    else if (VariantType::IndexOf::data_classic == _index3_)
    {
        obj.set_data_classic();
        auto _ptr1_ = obj.get_data_classic_if();
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            {
                const auto _err1_ = deserialize((*_ptr1_), in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
    }
    else if (VariantType::IndexOf::remote_transmission_request == _index3_)
    {
        obj.set_remote_transmission_request();
        auto _ptr1_ = obj.get_remote_transmission_request_if();
        {
            std::size_t _size_bytes1_ = in_buffer.size() / 8U;
            {
                const auto _err1_ = deserialize((*_ptr1_), in_buffer.subspan());
                if(_err1_){
                    _size_bytes1_ = _err1_.value();
                }else{
                    return -_err1_.error();
                }
            }
            in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
        }
    }
    else
    {
        return -nunavut::support::Error::RepresentationBadUnionTag;
    }
    in_buffer.align_offset_to<8U>();
    auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
    return { static_cast<std::size_t>(_bits_got_ / 8U) };
}

} // namespace can
} // namespace metatransport
} // namespace uavcan

#endif // UAVCAN_METATRANSPORT_CAN_FRAME_0_2_HPP_INCLUDED
