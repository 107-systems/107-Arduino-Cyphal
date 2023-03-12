//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.9 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl
// Generated at:  2023-03-10 05:17:53.889313 UTC
// Is deprecated: yes
// Fixed port-ID: None
// Full name:     uavcan.node.port.SubjectIDList
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
//           _____  ______ _____  _____  ______ _____       _______ ______ _____
//          |  __ `|  ____|  __ `|  __ `|  ____/ ____|   /`|__   __|  ____|  __ `
//          | |  | | |__  | |__) | |__) | |__ | |       /  `  | |  | |__  | |  | |
//          | |  | |  __| |  ___/|  _  /|  __|| |      / /` ` | |  |  __| | |  | |
//          | |__| | |____| |    | | ` `| |___| |____ / ____ `| |  | |____| |__| |
//          |_____/|______|_|    |_|  `_`______`_____/_/    `_`_|  |______|_____/
//
// WARNING: this data type is deprecated and is nearing the end of its life cycle. Seek replacement.
#ifndef UAVCAN_NODE_PORT_SUBJECT_ID_LIST_0_1_HPP_INCLUDED
#define UAVCAN_NODE_PORT_SUBJECT_ID_LIST_0_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <nunavut/support/variable_length_array.hpp>
#include <types/uavcan/node/port/SubjectID_1_0.hpp>
#include <types/uavcan/primitive/Empty_1_0.hpp>
#include <bitset>
#include <cstdint>
#include <limits>

namespace uavcan
{
namespace node
{
namespace port
{
// +-------------------------------------------------------------------------------------------------------------------+
// | LANGUAGE OPTION ASSERTIONS
// |    These static assertions ensure that the header is being used with
// | Nunavut C++ serialization support that is compatible with the language
// | options in effect when that support code was generated.
// +-------------------------------------------------------------------------------------------------------------------+
static_assert( nunavut::support::options::target_endianness == 1693710260,
              "/tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 628873475,
              "/tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl "
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
/// A list of subject identifiers.
/// The range of subject-ID is large, so using a fixed-size bitmask would make this type difficult to handle on
/// resource-constrained systems. To address that, we provide two extra options: a simple variable-length list,
/// and a special case that indicates that every subject-ID is in use.
///
[[deprecated("uavcan.node.port.SubjectIDList.0.1 is reaching the end of its life; there may be a newer version available")]]
struct SubjectIDList_0_1 final
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
        static constexpr std::size_t ExtentBytes                  = 4097UL;
        static constexpr std::size_t SerializationBufferSizeBytes = 1025UL;
        static_assert(ExtentBytes >= SerializationBufferSizeBytes, "Internal constraint violation");
        static_assert(ExtentBytes < (std::numeric_limits<std::size_t>::max() / 8U), "This message is too large to be handled by the selected types");
        struct TypeOf
        {
            TypeOf() = delete;
            using mask = std::bitset<8192>;
            using sparse_list = nunavut::support::VariableLengthArray<uavcan::node::port::SubjectID_1_0, 255>;
            using total = uavcan::primitive::Empty_1_0;
        };
    };

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+

    static constexpr std::uint16_t CAPACITY = 8192U;
    class VariantType final : public std::variant<
        ///
        /// The index represents the identifier value. True -- present/used. False -- absent/unused.
        ///
        _traits_::TypeOf::mask,
        ///
        /// A list of identifiers that can be used instead of the mask if most of the identifiers are unused.
        ///
        _traits_::TypeOf::sparse_list,
        ///
        /// A special case indicating that all identifiers are in use.
        ///
        _traits_::TypeOf::total
    >
    {
    public:

        static const constexpr std::size_t variant_npos = std::variant_npos;

        struct IndexOf final
        {
            IndexOf() = delete;
            static constexpr const std::size_t mask = 0U;
            static constexpr const std::size_t sparse_list = 1U;
            static constexpr const std::size_t total = 2U;
        };
        static constexpr const std::size_t MAX_INDEX = 3U;

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

    bool is_mask() const {
        return VariantType::IndexOf::mask == union_value.index();
    }

    typename std::add_pointer<_traits_::TypeOf::mask>::type get_mask_if(){
        return VariantType::get_if<VariantType::IndexOf::mask>(&union_value);
    }

    typename std::add_pointer<const _traits_::TypeOf::mask>::type get_mask_if() const{
        return VariantType::get_if<VariantType::IndexOf::mask>(&union_value);
    }

    typename std::add_lvalue_reference<_traits_::TypeOf::mask>::type get_mask(){

        return *VariantType::get_if<VariantType::IndexOf::mask>(&union_value);
    }

    typename std::add_lvalue_reference<const _traits_::TypeOf::mask>::type get_mask() const{

        return *VariantType::get_if<VariantType::IndexOf::mask>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<_traits_::TypeOf::mask>::type
    set_mask(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::mask>(v...);
    }
    bool is_sparse_list() const {
        return VariantType::IndexOf::sparse_list == union_value.index();
    }

    typename std::add_pointer<_traits_::TypeOf::sparse_list>::type get_sparse_list_if(){
        return VariantType::get_if<VariantType::IndexOf::sparse_list>(&union_value);
    }

    typename std::add_pointer<const _traits_::TypeOf::sparse_list>::type get_sparse_list_if() const{
        return VariantType::get_if<VariantType::IndexOf::sparse_list>(&union_value);
    }

    typename std::add_lvalue_reference<_traits_::TypeOf::sparse_list>::type get_sparse_list(){

        return *VariantType::get_if<VariantType::IndexOf::sparse_list>(&union_value);
    }

    typename std::add_lvalue_reference<const _traits_::TypeOf::sparse_list>::type get_sparse_list() const{

        return *VariantType::get_if<VariantType::IndexOf::sparse_list>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<_traits_::TypeOf::sparse_list>::type
    set_sparse_list(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::sparse_list>(v...);
    }
    bool is_total() const {
        return VariantType::IndexOf::total == union_value.index();
    }

    typename std::add_pointer<_traits_::TypeOf::total>::type get_total_if(){
        return VariantType::get_if<VariantType::IndexOf::total>(&union_value);
    }

    typename std::add_pointer<const _traits_::TypeOf::total>::type get_total_if() const{
        return VariantType::get_if<VariantType::IndexOf::total>(&union_value);
    }

    typename std::add_lvalue_reference<_traits_::TypeOf::total>::type get_total(){

        return *VariantType::get_if<VariantType::IndexOf::total>(&union_value);
    }

    typename std::add_lvalue_reference<const _traits_::TypeOf::total>::type get_total() const{

        return *VariantType::get_if<VariantType::IndexOf::total>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<_traits_::TypeOf::total>::type
    set_total(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::total>(v...);
    }
};

inline nunavut::support::SerializeResult serialize(const SubjectIDList_0_1& obj,
                                                   nunavut::support::bitspan out_buffer)
{
    const std::size_t capacity_bits = out_buffer.size();
    if ((static_cast<std::size_t>(capacity_bits)) < 8200UL)
    {
        return -nunavut::support::Error::SerializationBufferTooSmall;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    using VariantType = SubjectIDList_0_1::VariantType;
    const auto _index0_ = obj.union_value.index();
    {   // Union tag field: truncated uint8
        const auto _result3_ = out_buffer.setUxx(_index0_, 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
    }
    if (VariantType::IndexOf::mask == _index0_)
    {
        auto _ptr0_ = obj.get_mask_if();
        const std::size_t _origin0_ = out_buffer.offset();
        for (std::size_t _index1_ = 0U; _index1_ < 8192UL; ++_index1_)
        {
            auto _result2_ = out_buffer.setBit((*_ptr0_)[_index1_]);
            if(not _result2_){
                return -_result2_.error();
            }
            out_buffer.add_offset(1UL);
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        (void) _origin0_;
    }
    else if (VariantType::IndexOf::sparse_list == _index0_)
    {
        auto _ptr0_ = obj.get_sparse_list_if();
        if ((*_ptr0_).size() > 255)
        {
            return -nunavut::support::Error::SerializationBadArrayLength;
        }
        // Array length prefix: truncated uint8
        const auto _result3_ = out_buffer.setUxx((*_ptr0_).size(), 8U);
        if(not _result3_){
            return -_result3_.error();
        }
        out_buffer.add_offset(8U);
        for (std::size_t _index2_ = 0U; _index2_ < (*_ptr0_).size(); ++_index2_)
        {
            std::size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            auto _err0_ = serialize((*_ptr0_)[_index2_], _subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            out_buffer.add_offset(_size_bytes0_ * 8U);
            //
        }
    }
    else if (VariantType::IndexOf::total == _index0_)
    {
        auto _ptr0_ = obj.get_total_if();
        std::size_t _size_bytes0_ = 0UL;  // Nested object (max) size, in bytes.
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

inline nunavut::support::SerializeResult deserialize(SubjectIDList_0_1& obj,
                                                     nunavut::support::const_bitspan in_buffer)
{
    const auto capacity_bits = in_buffer.size();
    using VariantType = SubjectIDList_0_1::VariantType;
    // Union tag field: truncated uint8
    auto _index3_ = obj.union_value.index();
    _index3_ = in_buffer.getU8(8U);
    in_buffer.add_offset(8U);
    if (VariantType::IndexOf::mask == _index3_)
    {
        obj.set_mask();
        auto _ptr1_ = obj.get_mask_if();
        for (std::size_t _index4_ = 0U; _index4_ < 8192UL; ++_index4_)
        {
            (*_ptr1_)[_index4_] = in_buffer.getBit();
            in_buffer.add_offset(1U);
        }
    }
    else if (VariantType::IndexOf::sparse_list == _index3_)
    {
        obj.set_sparse_list();
        auto _ptr1_ = obj.get_sparse_list_if();
        {
            // Array length prefix: truncated uint8
        const std::size_t _size0_ = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
            if ( _size0_ > 255U)
            {
                return -nunavut::support::Error::SerializationBadArrayLength;
            }
            (*_ptr1_).reserve(_size0_);
            for (std::size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
            {
                // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
                // move semantics instead of assuming C-style containers
                (*_ptr1_).push_back();
                {
                std::size_t _size_bytes1_ = in_buffer.size() / 8U;
                {
                    const auto _err1_ = deserialize((*_ptr1_)[_index5_], in_buffer.subspan());
                    if(_err1_){
                        _size_bytes1_ = _err1_.value();
                    }else{
                        return -_err1_.error();
                    }
                }
                in_buffer.add_offset(_size_bytes1_ * 8U);  // Advance by the size of the nested serialized representation.
            }
            }
        }
    }
    else if (VariantType::IndexOf::total == _index3_)
    {
        obj.set_total();
        auto _ptr1_ = obj.get_total_if();
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

} // namespace port
} // namespace node
} // namespace uavcan

#endif // UAVCAN_NODE_PORT_SUBJECT_ID_LIST_0_1_HPP_INCLUDED
