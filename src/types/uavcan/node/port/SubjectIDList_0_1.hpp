//
// This is an AUTO-GENERATED UAVCAN DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-1.9.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl
// Generated at:  2023-01-18 06:33:55.951058 UTC
// Is deprecated: no
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
#ifndef UAVCAN_NODE_PORT_SUBJECT_ID_LIST_0_1_HPP_INCLUDED
#define UAVCAN_NODE_PORT_SUBJECT_ID_LIST_0_1_HPP_INCLUDED

#include "nunavut/support/serialization.hpp"
#include "nunavut/support/variable_length_array.hpp"
#include "uavcan/node/port/SubjectID_1_0.hpp"
#include "uavcan/primitive/Empty_1_0.hpp"
#include <array>
#include <cstdint>

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
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/node/port/SubjectIDList.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
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
/// A list of subject identifiers.
/// The range of subject-ID is large, so using a fixed-size bitmask would make this type difficult to handle on
/// resource-constrained systems. To address that, we provide two extra options: a simple variable-length list,
/// and a special case that indicates that every subject-ID is in use.
///
struct SubjectIDList_0_1 final
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

    static constexpr std::size_t EXTENT_BYTES                    =4097UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =1025UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");

    // +---------------------------------------------------------------------------------------------------------------+
    // | CONSTANTS
    // +---------------------------------------------------------------------------------------------------------------+

    static constexpr std::uint16_t CAPACITY = 8192U;
    class VariantType final
    {
        std::size_t tag_;

        union internal_union_t
        {
            ///
            /// The index represents the identifier value. True -- present/used. False -- absent/unused.
            ///
            std::aligned_storage<sizeof(std::array<bool,8192>), alignof(std::array<bool,8192>)>::type mask;
            ///
            /// A list of identifiers that can be used instead of the mask if most of the identifiers are unused.
            ///
            std::aligned_storage<sizeof(nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>), alignof(nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>)>::type sparse_list;
            ///
            /// A special case indicating that all identifiers are in use.
            ///
            std::aligned_storage<sizeof(uavcan::primitive::Empty_1_0), alignof(uavcan::primitive::Empty_1_0)>::type total;
        } internal_union_value_;

    public:
        static const constexpr std::size_t variant_npos = -1;

        VariantType()
            : tag_(0)
            , internal_union_value_()
        {
            // This is how the C++17 standard library does it; default initialization as the 0th index.
            emplace<0>();
        }

        VariantType(const VariantType& rhs)
            : tag_(variant_npos)
            , internal_union_value_()
        {
            if(rhs.tag_ == 0)
            {
                do_copy<0>(
                    *reinterpret_cast<std::add_pointer<const std::array<bool,8192>>::type>(&rhs.internal_union_value_.mask)
                );
            }
            else if(rhs.tag_ == 1)
            {
                do_copy<1>(
                    *reinterpret_cast<std::add_pointer<const nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>>::type>(&rhs.internal_union_value_.sparse_list)
                );
            }
            else if(rhs.tag_ == 2)
            {
                do_copy<2>(
                    *reinterpret_cast<std::add_pointer<const uavcan::primitive::Empty_1_0>::type>(&rhs.internal_union_value_.total)
                );
            }
            tag_ = rhs.tag_;
        }

        VariantType(VariantType&& rhs)
            : tag_(variant_npos)
            , internal_union_value_()
        {
            if(rhs.tag_ == 0)
            {
                do_emplace<0>(
                    std::forward<std::array<bool,8192>>(
                        *reinterpret_cast<std::add_pointer<std::array<bool,8192>>::type>(&rhs.internal_union_value_.mask)
                    )
                );
            }
            else if(rhs.tag_ == 1)
            {
                do_emplace<1>(
                    std::forward<nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>>(
                        *reinterpret_cast<std::add_pointer<nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>>::type>(&rhs.internal_union_value_.sparse_list)
                    )
                );
            }
            else if(rhs.tag_ == 2)
            {
                do_emplace<2>(
                    std::forward<types/uavcan::primitive::Empty_1_0>(
                        *reinterpret_cast<std::add_pointer<types/uavcan::primitive::Empty_1_0>::type>(&rhs.internal_union_value_.total)
                    )
                );
            }
            tag_ = rhs.tag_;
        }
        VariantType& operator=(const VariantType& rhs)
        {
            destroy_current();
            if(rhs.tag_ == 0)
            {
                do_copy<0>(
                    *reinterpret_cast<std::add_pointer<const std::array<bool,8192>>::type>(&rhs.internal_union_value_.mask)
                );
            }
            else if(rhs.tag_ == 1)
            {
                do_copy<1>(
                    *reinterpret_cast<std::add_pointer<const nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>>::type>(&rhs.internal_union_value_.sparse_list)
                );
            }
            else if(rhs.tag_ == 2)
            {
                do_copy<2>(
                    *reinterpret_cast<std::add_pointer<const uavcan::primitive::Empty_1_0>::type>(&rhs.internal_union_value_.total)
                );
            }
            tag_ = rhs.tag_;
            return *this;
        }

        VariantType& operator=(VariantType&& rhs)
        {
            destroy_current();
            if(rhs.tag_ == 0)
            {
                do_emplace<0>(
                    std::forward<std::array<bool,8192>>(
                        *reinterpret_cast<std::add_pointer<std::array<bool,8192>>::type>(&rhs.internal_union_value_.mask)
                    )
                );
            }
            else if(rhs.tag_ == 1)
            {
                do_emplace<1>(
                    std::forward<nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>>(
                        *reinterpret_cast<std::add_pointer<nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>>::type>(&rhs.internal_union_value_.sparse_list)
                    )
                );
            }
            else if(rhs.tag_ == 2)
            {
                do_emplace<2>(
                    std::forward<types/uavcan::primitive::Empty_1_0>(
                        *reinterpret_cast<std::add_pointer<types/uavcan::primitive::Empty_1_0>::type>(&rhs.internal_union_value_.total)
                    )
                );
            }
            tag_ = rhs.tag_;
            return *this;
        }

        ~VariantType()
        {
            destroy_current();
        }

        size_t index() const{
            return tag_;
        }

        struct IndexOf final
        {
            IndexOf() = delete;
            static constexpr const std::size_t mask = 0U;
            static constexpr const std::size_t sparse_list = 1U;
            static constexpr const std::size_t total = 2U;
        };
        static constexpr const std::size_t MAX_INDEX = 3U;

        template<std::size_t I, class...Types> struct alternative;

        template<class...Types> struct alternative<0U, Types...>
        {
            using type = std::array<bool,8192>;
            static constexpr auto pointer = &VariantType::internal_union_t::mask;
        };
        template<class...Types> struct alternative<1U, Types...>
        {
            using type = nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>;
            static constexpr auto pointer = &VariantType::internal_union_t::sparse_list;
        };
        template<class...Types> struct alternative<2U, Types...>
        {
            using type = uavcan::primitive::Empty_1_0;
            static constexpr auto pointer = &VariantType::internal_union_t::total;
        };

        template<std::size_t I, class... Args> typename VariantType::alternative<I, VariantType>::type& emplace(Args&&... v)
        {
            destroy_current();
            typename alternative<I>::type& result = do_emplace<I>(v...);
            tag_ = I;
            return result;
        }

        template<std::size_t I, class... Types>
        static constexpr typename alternative<I, VariantType>::type* get_if(VariantType* v) noexcept
        {
            return (v) ? v->do_get_if<I>() : nullptr;
        }

        template<std::size_t I, class... Types>
        static constexpr const typename alternative<I, VariantType>::type* get_if(const VariantType* v) noexcept
        {
            return (v) ? v->do_get_if_const<I>() : nullptr;
        }

    private:
        template<std::size_t I, class... Args> typename VariantType::alternative<I, VariantType>::type& do_emplace(Args&&... v)
        {
            return *(new (&(internal_union_value_.*(alternative<I>::pointer)) ) typename alternative<I>::type(std::forward<Args>(v)...));
        }

        template<std::size_t I, class... Args> typename VariantType::alternative<I, VariantType>::type& do_copy(const Args&... v)
        {
            return *(new (&(internal_union_value_.*(alternative<I>::pointer)) ) typename alternative<I>::type(typename alternative<I>::type(v...)));
        }

        template<std::size_t I, class... Types>
        constexpr typename VariantType::alternative<I, VariantType>::type* do_get_if() noexcept
        {
            return (tag_ == I) ? reinterpret_cast<typename std::add_pointer<typename VariantType::alternative<I>::type>::type>(&(internal_union_value_.*(alternative<I>::pointer))) : nullptr;
        }

        template<std::size_t I, class... Types>
        constexpr const typename VariantType::alternative<I, VariantType>::type* do_get_if_const() const noexcept
        {
            return (tag_ == I) ? reinterpret_cast<typename std::add_pointer<const typename VariantType::alternative<I>::type>::type>(&(internal_union_value_.*(alternative<I>::pointer))) : nullptr;
        }

        void destroy_current()
        {
            if (tag_ == 0)
            {
                reinterpret_cast<std::array<bool,8192>*>(std::addressof(internal_union_value_.mask))->~array<bool,8192>();
            }
            else if (tag_ == 1)
            {
                reinterpret_cast<nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>*>(std::addressof(internal_union_value_.sparse_list))->~VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>();
            }
            else if (tag_ == 2)
            {
                reinterpret_cast<types/uavcan::primitive::Empty_1_0*>(std::addressof(internal_union_value_.total))->~Empty_1_0();
            }
        }

    };

    VariantType union_value;

    bool is_mask() const {
        return VariantType::IndexOf::mask == union_value.index();
    }

    typename std::add_pointer<std::array<bool,8192>>::type get_mask_if(){
        return VariantType::get_if<VariantType::IndexOf::mask>(&union_value);
    }

    typename std::add_pointer<const std::array<bool,8192>>::type get_mask_if() const{
        return VariantType::get_if<VariantType::IndexOf::mask>(&union_value);
    }

    typename std::add_lvalue_reference<std::array<bool,8192>>::type get_mask(){
        NUNAVUT_ASSERT(is_mask());
        return *VariantType::get_if<VariantType::IndexOf::mask>(&union_value);
    }

    typename std::add_lvalue_reference<const std::array<bool,8192>>::type get_mask() const{
        NUNAVUT_ASSERT(is_mask());
        return *VariantType::get_if<VariantType::IndexOf::mask>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<std::array<bool,8192>>::type
    set_mask(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::mask>(v...);
    }
    bool is_sparse_list() const {
        return VariantType::IndexOf::sparse_list == union_value.index();
    }

    typename std::add_pointer<nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>>::type get_sparse_list_if(){
        return VariantType::get_if<VariantType::IndexOf::sparse_list>(&union_value);
    }

    typename std::add_pointer<const nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>>::type get_sparse_list_if() const{
        return VariantType::get_if<VariantType::IndexOf::sparse_list>(&union_value);
    }

    typename std::add_lvalue_reference<nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>>::type get_sparse_list(){
        NUNAVUT_ASSERT(is_sparse_list());
        return *VariantType::get_if<VariantType::IndexOf::sparse_list>(&union_value);
    }

    typename std::add_lvalue_reference<const nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>>::type get_sparse_list() const{
        NUNAVUT_ASSERT(is_sparse_list());
        return *VariantType::get_if<VariantType::IndexOf::sparse_list>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<nunavut::support::VariableLengthArray<types/uavcan::node::port::SubjectID_1_0, 255>>::type
    set_sparse_list(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::sparse_list>(v...);
    }
    bool is_total() const {
        return VariantType::IndexOf::total == union_value.index();
    }

    typename std::add_pointer<types/uavcan::primitive::Empty_1_0>::type get_total_if(){
        return VariantType::get_if<VariantType::IndexOf::total>(&union_value);
    }

    typename std::add_pointer<const uavcan::primitive::Empty_1_0>::type get_total_if() const{
        return VariantType::get_if<VariantType::IndexOf::total>(&union_value);
    }

    typename std::add_lvalue_reference<types/uavcan::primitive::Empty_1_0>::type get_total(){
        NUNAVUT_ASSERT(is_total());
        return *VariantType::get_if<VariantType::IndexOf::total>(&union_value);
    }

    typename std::add_lvalue_reference<const uavcan::primitive::Empty_1_0>::type get_total() const{
        NUNAVUT_ASSERT(is_total());
        return *VariantType::get_if<VariantType::IndexOf::total>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<types/uavcan::primitive::Empty_1_0>::type
    set_total(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::total>(v...);
    }

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 8200UL)
        {
            return -nunavut::support::Error::SERIALIZATION_BUFFER_TOO_SMALL;
        }
        // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
        // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        const auto _index0_ = union_value.index();
        {   // Union tag field: truncated uint8
            const auto _result3_ = out_buffer.setUxx(_index0_, 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
        }
        if (VariantType::IndexOf::mask == _index0_)
        {
            auto _ptr0_ = get_mask_if();
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(8192ULL <= out_buffer.size());
            const std::size_t _origin0_ = out_buffer.offset();
            for (size_t _index1_ = 0U; _index1_ < 8192UL; ++_index1_)
            {
                NUNAVUT_ASSERT(1ULL <= out_buffer.size());
                auto _result2_ = out_buffer.setBit((*_ptr0_)[_index1_]);
                if(not _result2_){
                    return -_result2_.error();
                }
                out_buffer.add_offset(1UL);
            }
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((out_buffer.offset() - _origin0_) == 8192ULL);
            (void) _origin0_;
        }
        else if (VariantType::IndexOf::sparse_list == _index0_)
        {
            auto _ptr0_ = get_sparse_list_if();
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(4088ULL <= out_buffer.size());
            if ((*_ptr0_).size() > 255)
            {
                return -nunavut::support::Error::REPRESENTATION_BAD_ARRAY_LENGTH;
            }
            // Array length prefix: truncated uint8
            const auto _result3_ = out_buffer.setUxx((*_ptr0_).size(), 8U);
            if(not _result3_){
                return -_result3_.error();
            }
            out_buffer.add_offset(8U);
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            for (size_t _index2_ = 0U; _index2_ < (*_ptr0_).size(); ++_index2_)
            {
                NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
                NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
                NUNAVUT_ASSERT(16ULL <= out_buffer.size());
                std::size_t _size_bytes0_ = 2UL;  // Nested object (max) size, in bytes.
                auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
                if(not _subspan0_){
                    return -_subspan0_.error();
                }
                NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
                auto _err0_ = (*_ptr0_)[_index2_].serialize(_subspan0_.value());
                if (not _err0_)
                {
                    return _err0_;
                }
                _size_bytes0_ = _err0_.value();
                // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
                NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 16ULL);
                out_buffer.add_offset(_size_bytes0_ * 8U);
                // NUNAVUT_ASSERT(out_buffer.size() >= 0);
            }
        }
        else if (VariantType::IndexOf::total == _index0_)
        {
            auto _ptr0_ = get_total_if();
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            std::size_t _size_bytes0_ = 0UL;  // Nested object (max) size, in bytes.
            auto _subspan0_ = out_buffer.subspan(0U, _size_bytes0_ * 8U);
            if(not _subspan0_){
                return -_subspan0_.error();
            }
            NUNAVUT_ASSERT(_subspan0_->offset_alings_to_byte());
            auto _err0_ = (*_ptr0_).serialize(_subspan0_.value());
            if (not _err0_)
            {
                return _err0_;
            }
            _size_bytes0_ = _err0_.value();
            // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 0ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        else
        {
            return -nunavut::support::Error::REPRESENTATION_BAD_UNION_TAG;
        }
        {
            const auto _result0_ = out_buffer.padAndMoveToAlignment(8U);
            if(not _result0_){
                return -_result0_.error();
            }
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT(out_buffer.offset() >= 8ULL);
        NUNAVUT_ASSERT(out_buffer.offset() <= 8200ULL);
        NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
        return out_buffer.offset_bytes_ceil();
    }

    nunavut::support::SerializeResult
    deserialize(nunavut::support::const_bitspan in_buffer)
    {
        const auto capacity_bits = in_buffer.size();
        // Union tag field: truncated uint8
        auto _index3_ = union_value.index();
        _index3_ = in_buffer.getU8(8U);
        in_buffer.add_offset(8U);
        if (VariantType::IndexOf::mask == _index3_)
        {
            set_mask();
            auto _ptr1_ = get_mask_if();
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            for (size_t _index4_ = 0U; _index4_ < 8192UL; ++_index4_)
            {
                (*_ptr1_)[_index4_] = in_buffer.getBit();
                in_buffer.add_offset(1U);
            }
        }
        else if (VariantType::IndexOf::sparse_list == _index3_)
        {
            set_sparse_list();
            auto _ptr1_ = get_sparse_list_if();
            NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                // Array length prefix: truncated uint8
            const std::uint8_t _size0_ = in_buffer.getU8(8U);
            in_buffer.add_offset(8U);
                if ( _size0_ > 255U)
                {
                    return -nunavut::support::Error::REPRESENTATION_BAD_ARRAY_LENGTH;
                }
                (*_ptr1_).reserve(_size0_);
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
                for (size_t _index5_ = 0U; _index5_ < _size0_; ++_index5_)
                {
                    // TODO This is terribly inefficient. We need to completely refactor this template to use C++ emplace and
                    // move semantics instead of assuming C-style containers
                    (*_ptr1_).push_back();
                    NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
                NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
                {
                    std::size_t _size_bytes1_ = in_buffer.size() / 8U;
                    NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
                    {
                        const auto _err1_ = (*_ptr1_)[_index5_].deserialize(in_buffer.subspan());
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
            set_total();
            auto _ptr1_ = get_total_if();
            NUNAVUT_ASSERT(in_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
            {
                std::size_t _size_bytes1_ = in_buffer.size() / 8U;
                NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
                {
                    const auto _err1_ = (*_ptr1_).deserialize(in_buffer.subspan());
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
            return -nunavut::support::Error::REPRESENTATION_BAD_UNION_TAG;
        }
        in_buffer.align_offset_to<8U>();
        NUNAVUT_ASSERT(in_buffer.offset_alings_to_byte());
        auto _bits_got_ = std::min<std::size_t>(in_buffer.offset(), capacity_bits);
        NUNAVUT_ASSERT(capacity_bits >= _bits_got_);
        return { static_cast<std::size_t>(_bits_got_ / 8U) };
    }
};

} // namespace port
} // namespace node
} // namespace uavcan

#endif // UAVCAN_NODE_PORT_SUBJECT_ID_LIST_0_1_HPP_INCLUDED
