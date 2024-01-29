//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.3.1 (serialization was enabled)
// Source file:   /tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl
// Generated at:  2024-01-29 05:34:33.021334 UTC
// Is deprecated: yes
// Fixed port-ID: None
// Full name:     zubax.low_level_io.Data
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
//     python_version:  3.10.12
//     python_release_level:  final
//     python_build:  ('main', 'Nov 20 2023 15:14:05')
//     python_compiler:  GCC 11.4.0
//     python_revision:
//     python_xoptions:  {}
//     runtime_platform:  Linux-6.5.0-15-generic-x86_64-with-glibc2.35
// Language Options
//     target_endianness:  any
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  False
//     enable_override_variable_array_capacity:  False
//     std:  c++17
//     cast_format:  static_cast<{type}>({value})
//     variable_array_type_include:  <vector>
//     variable_array_type_template:  std::vector<{TYPE}>
//     variable_array_type_constructor_args:
//     allocator_include:
//     allocator_type:
//     allocator_is_default_constructible:  True
//     ctor_convention:  default
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
#ifndef ZUBAX_LOW_LEVEL_IO_DATA_0_1_HPP_INCLUDED
#define ZUBAX_LOW_LEVEL_IO_DATA_0_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <types/uavcan/primitive/array/Natural16_1_0.hpp>
#include <types/uavcan/primitive/array/Natural32_1_0.hpp>
#include <types/uavcan/primitive/array/Natural64_1_0.hpp>
#include <types/uavcan/primitive/array/Natural8_1_0.hpp>
#include <cstdint>
#include <limits>
#include <variant>

namespace zubax
{
namespace low_level_io
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 3320664631,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 4227611599,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_constructor_args == 0,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_include == 0,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_type == 0,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::allocator_is_default_constructible == 1,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::ctor_convention == 3814588639,
              "/tmp/zubax_dsdl/zubax/low_level_io/Data.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );

// +-------------------------------------------------------------------------------------------------------------------+
// | This implementation uses the C++17 standard library variant type with wrappers for the emplace and
// | get_if methods to support forward-compatibility with the C++14 version of this object. The union_value type
// | extends std::variant and can be used with the entire set of variant methods. Using std::variant directly does mean
// | your code will not be backwards compatible with the C++14 version of this object.
// +-------------------------------------------------------------------------------------------------------------------+

struct [[deprecated("zubax.low_level_io.Data.0.1 is reaching the end of its life; there may be a newer version available")]]Data_0_1 final
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
        static constexpr std::size_t ExtentBytes                  = 259UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 259UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");

        struct TypeOf
        {
            TypeOf() = delete;
            using u8 = uavcan::primitive::array::Natural8_1_0;
            using u16 = uavcan::primitive::array::Natural16_1_0;
            using u32 = uavcan::primitive::array::Natural32_1_0;
            using u64 = uavcan::primitive::array::Natural64_1_0;
        };
    };

    class VariantType final : public std::variant<

        _traits_::TypeOf::u8,

        _traits_::TypeOf::u16,

        _traits_::TypeOf::u32,

        _traits_::TypeOf::u64
    >
    {
    public:

        static const constexpr std::size_t variant_npos = std::variant_npos;

        struct IndexOf final
        {
            IndexOf() = delete;
            static constexpr const std::size_t u8 = 0U;
            static constexpr const std::size_t u16 = 1U;
            static constexpr const std::size_t u32 = 2U;
            static constexpr const std::size_t u64 = 3U;
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

    bool is_u8() const {
        return VariantType::IndexOf::u8 == union_value.index();
    }

    typename std::add_pointer<_traits_::TypeOf::u8>::type get_u8_if(){
        return VariantType::get_if<VariantType::IndexOf::u8>(&union_value);
    }

    typename std::add_pointer<const _traits_::TypeOf::u8>::type get_u8_if() const{
        return VariantType::get_if<VariantType::IndexOf::u8>(&union_value);
    }

    typename std::add_lvalue_reference<_traits_::TypeOf::u8>::type get_u8(){

        return *VariantType::get_if<VariantType::IndexOf::u8>(&union_value);
    }

    typename std::add_lvalue_reference<const _traits_::TypeOf::u8>::type get_u8() const{

        return *VariantType::get_if<VariantType::IndexOf::u8>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<_traits_::TypeOf::u8>::type
    set_u8(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::u8>(v...);
    }
    bool is_u16() const {
        return VariantType::IndexOf::u16 == union_value.index();
    }

    typename std::add_pointer<_traits_::TypeOf::u16>::type get_u16_if(){
        return VariantType::get_if<VariantType::IndexOf::u16>(&union_value);
    }

    typename std::add_pointer<const _traits_::TypeOf::u16>::type get_u16_if() const{
        return VariantType::get_if<VariantType::IndexOf::u16>(&union_value);
    }

    typename std::add_lvalue_reference<_traits_::TypeOf::u16>::type get_u16(){

        return *VariantType::get_if<VariantType::IndexOf::u16>(&union_value);
    }

    typename std::add_lvalue_reference<const _traits_::TypeOf::u16>::type get_u16() const{

        return *VariantType::get_if<VariantType::IndexOf::u16>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<_traits_::TypeOf::u16>::type
    set_u16(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::u16>(v...);
    }
    bool is_u32() const {
        return VariantType::IndexOf::u32 == union_value.index();
    }

    typename std::add_pointer<_traits_::TypeOf::u32>::type get_u32_if(){
        return VariantType::get_if<VariantType::IndexOf::u32>(&union_value);
    }

    typename std::add_pointer<const _traits_::TypeOf::u32>::type get_u32_if() const{
        return VariantType::get_if<VariantType::IndexOf::u32>(&union_value);
    }

    typename std::add_lvalue_reference<_traits_::TypeOf::u32>::type get_u32(){

        return *VariantType::get_if<VariantType::IndexOf::u32>(&union_value);
    }

    typename std::add_lvalue_reference<const _traits_::TypeOf::u32>::type get_u32() const{

        return *VariantType::get_if<VariantType::IndexOf::u32>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<_traits_::TypeOf::u32>::type
    set_u32(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::u32>(v...);
    }
    bool is_u64() const {
        return VariantType::IndexOf::u64 == union_value.index();
    }

    typename std::add_pointer<_traits_::TypeOf::u64>::type get_u64_if(){
        return VariantType::get_if<VariantType::IndexOf::u64>(&union_value);
    }

    typename std::add_pointer<const _traits_::TypeOf::u64>::type get_u64_if() const{
        return VariantType::get_if<VariantType::IndexOf::u64>(&union_value);
    }

    typename std::add_lvalue_reference<_traits_::TypeOf::u64>::type get_u64(){

        return *VariantType::get_if<VariantType::IndexOf::u64>(&union_value);
    }

    typename std::add_lvalue_reference<const _traits_::TypeOf::u64>::type get_u64() const{

        return *VariantType::get_if<VariantType::IndexOf::u64>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<_traits_::TypeOf::u64>::type
    set_u64(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::u64>(v...);
    }
};

inline nunavut::support::SerializeResult serialize(const Data_0_1& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 2072UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    using VariantType = Data_0_1::VariantType;
    const auto _index0_ = obj.union_value.index();
    {   // Union tag field: truncated uint8
        const auto _result3_ = out_buffer.setUxx(_index0_, 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
    }
    if (VariantType::IndexOf::u8 == _index0_)
    {
        auto _ptr0_ = obj.get_u8_if();
        std::size_t _size_bytes0_ = 258UL;  // Nested object (max) size, in bytes.
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
    else if (VariantType::IndexOf::u16 == _index0_)
    {
        auto _ptr0_ = obj.get_u16_if();
        std::size_t _size_bytes0_ = 257UL;  // Nested object (max) size, in bytes.
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
    else if (VariantType::IndexOf::u32 == _index0_)
    {
        auto _ptr0_ = obj.get_u32_if();
        std::size_t _size_bytes0_ = 257UL;  // Nested object (max) size, in bytes.
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
    else if (VariantType::IndexOf::u64 == _index0_)
    {
        auto _ptr0_ = obj.get_u64_if();
        std::size_t _size_bytes0_ = 257UL;  // Nested object (max) size, in bytes.
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

inline nunavut::support::SerializeResult deserialize(Data_0_1& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    using VariantType = Data_0_1::VariantType;
    // Union tag field: truncated uint8
    auto _index3_ = obj.union_value.index();
    _index3_ = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
    if (VariantType::IndexOf::u8 == _index3_)
    {
        obj.set_u8();
        auto _ptr1_ = obj.get_u8_if();
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
    else if (VariantType::IndexOf::u16 == _index3_)
    {
        obj.set_u16();
        auto _ptr1_ = obj.get_u16_if();
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
    else if (VariantType::IndexOf::u32 == _index3_)
    {
        obj.set_u32();
        auto _ptr1_ = obj.get_u32_if();
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
    else if (VariantType::IndexOf::u64 == _index3_)
    {
        obj.set_u64();
        auto _ptr1_ = obj.get_u64_if();
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

} // namespace low_level_io
} // namespace zubax

#endif // ZUBAX_LOW_LEVEL_IO_DATA_0_1_HPP_INCLUDED
