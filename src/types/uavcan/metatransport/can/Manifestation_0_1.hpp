//
// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended since metadata in this header will change for each
// build invocation. TODO: add --reproducible option to prevent any volatile metadata from being generated.
//
// Generator:     nunavut-2.0.0 (serialization was enabled)
// Source file:   /tmp/public_regulated_data_types/uavcan/metatransport/can/Manifestation.0.1.dsdl
// Generated at:  2023-01-29 16:46:55.316211 UTC
// Is deprecated: yes
// Fixed port-ID: None
// Full name:     uavcan.metatransport.can.Manifestation
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
//           _____  ______ _____  _____  ______ _____       _______ ______ _____
//          |  __ `|  ____|  __ `|  __ `|  ____/ ____|   /`|__   __|  ____|  __ `
//          | |  | | |__  | |__) | |__) | |__ | |       /  `  | |  | |__  | |  | |
//          | |  | |  __| |  ___/|  _  /|  __|| |      / /` ` | |  |  __| | |  | |
//          | |__| | |____| |    | | ` `| |___| |____ / ____ `| |  | |____| |__| |
//          |_____/|______|_|    |_|  `_`______`_____/_/    `_`_|  |______|_____/
//
// WARNING: this data type is deprecated and is nearing the end of its life cycle. Seek replacement.
#ifndef UAVCAN_METATRANSPORT_CAN_MANIFESTATION_0_1_HPP_INCLUDED
#define UAVCAN_METATRANSPORT_CAN_MANIFESTATION_0_1_HPP_INCLUDED

#include <nunavut/support/serialization.hpp>
#include <types/uavcan/metatransport/can/DataClassic_0_1.hpp>
#include <types/uavcan/metatransport/can/DataFD_0_1.hpp>
#include <types/uavcan/metatransport/can/Error_0_1.hpp>
#include <types/uavcan/metatransport/can/RTR_0_1.hpp>
#include <cstdint>

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
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Manifestation.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::omit_float_serialization_support == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Manifestation.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_serialization_asserts == 1,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Manifestation.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_override_variable_array_capacity == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Manifestation.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::std == 3161622713,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Manifestation.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_template == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Manifestation.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::variable_array_type_include == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Manifestation.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::cast_format == 1407868567,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Manifestation.0.1.dsdl "
              "is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not "
              "allowed." );
static_assert( nunavut::support::options::enable_allocator_support == 0,
              "/tmp/public_regulated_data_types/uavcan/metatransport/can/Manifestation.0.1.dsdl "
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
/// CAN frame properties that can be manifested on the bus.
///
struct Manifestation_0_1 final
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

    static constexpr std::size_t EXTENT_BYTES                    =71UL;
    static constexpr std::size_t SERIALIZATION_BUFFER_SIZE_BYTES =71UL;
    static_assert(EXTENT_BYTES >= SERIALIZATION_BUFFER_SIZE_BYTES, "Internal constraint violation");
    static_assert(EXTENT_BYTES < (std::numeric_limits<std::size_t>::max() /8U), "This message is too large to be handled by current types!");
    class VariantType final
    {
        std::size_t tag_;

        union internal_union_t
        {
            ///
            /// CAN error (intentional or disturbance)
            ///
            std::aligned_storage<sizeof(uavcan::metatransport::can::Error_0_1), alignof(uavcan::metatransport::can::Error_0_1)>::type _error;
            ///
            /// Bit rate switch flag active
            ///
            std::aligned_storage<sizeof(uavcan::metatransport::can::DataFD_0_1), alignof(uavcan::metatransport::can::DataFD_0_1)>::type data_fd;
            ///
            /// Bit rate switch flag not active
            ///
            std::aligned_storage<sizeof(uavcan::metatransport::can::DataClassic_0_1), alignof(uavcan::metatransport::can::DataClassic_0_1)>::type data_classic;
            ///
            /// Bit rate switch flag not active
            ///
            std::aligned_storage<sizeof(uavcan::metatransport::can::RTR_0_1), alignof(uavcan::metatransport::can::RTR_0_1)>::type remote_transmission_request;
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
                    *reinterpret_cast<std::add_pointer<const uavcan::metatransport::can::Error_0_1>::type>(&rhs.internal_union_value_._error)
                );
            }
            else if(rhs.tag_ == 1)
            {
                do_copy<1>(
                    *reinterpret_cast<std::add_pointer<const uavcan::metatransport::can::DataFD_0_1>::type>(&rhs.internal_union_value_.data_fd)
                );
            }
            else if(rhs.tag_ == 2)
            {
                do_copy<2>(
                    *reinterpret_cast<std::add_pointer<const uavcan::metatransport::can::DataClassic_0_1>::type>(&rhs.internal_union_value_.data_classic)
                );
            }
            else if(rhs.tag_ == 3)
            {
                do_copy<3>(
                    *reinterpret_cast<std::add_pointer<const uavcan::metatransport::can::RTR_0_1>::type>(&rhs.internal_union_value_.remote_transmission_request)
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
                    std::forward<uavcan::metatransport::can::Error_0_1>(
                        *reinterpret_cast<std::add_pointer<uavcan::metatransport::can::Error_0_1>::type>(&rhs.internal_union_value_._error)
                    )
                );
            }
            else if(rhs.tag_ == 1)
            {
                do_emplace<1>(
                    std::forward<uavcan::metatransport::can::DataFD_0_1>(
                        *reinterpret_cast<std::add_pointer<uavcan::metatransport::can::DataFD_0_1>::type>(&rhs.internal_union_value_.data_fd)
                    )
                );
            }
            else if(rhs.tag_ == 2)
            {
                do_emplace<2>(
                    std::forward<uavcan::metatransport::can::DataClassic_0_1>(
                        *reinterpret_cast<std::add_pointer<uavcan::metatransport::can::DataClassic_0_1>::type>(&rhs.internal_union_value_.data_classic)
                    )
                );
            }
            else if(rhs.tag_ == 3)
            {
                do_emplace<3>(
                    std::forward<uavcan::metatransport::can::RTR_0_1>(
                        *reinterpret_cast<std::add_pointer<uavcan::metatransport::can::RTR_0_1>::type>(&rhs.internal_union_value_.remote_transmission_request)
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
                    *reinterpret_cast<std::add_pointer<const uavcan::metatransport::can::Error_0_1>::type>(&rhs.internal_union_value_._error)
                );
            }
            else if(rhs.tag_ == 1)
            {
                do_copy<1>(
                    *reinterpret_cast<std::add_pointer<const uavcan::metatransport::can::DataFD_0_1>::type>(&rhs.internal_union_value_.data_fd)
                );
            }
            else if(rhs.tag_ == 2)
            {
                do_copy<2>(
                    *reinterpret_cast<std::add_pointer<const uavcan::metatransport::can::DataClassic_0_1>::type>(&rhs.internal_union_value_.data_classic)
                );
            }
            else if(rhs.tag_ == 3)
            {
                do_copy<3>(
                    *reinterpret_cast<std::add_pointer<const uavcan::metatransport::can::RTR_0_1>::type>(&rhs.internal_union_value_.remote_transmission_request)
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
                    std::forward<uavcan::metatransport::can::Error_0_1>(
                        *reinterpret_cast<std::add_pointer<uavcan::metatransport::can::Error_0_1>::type>(&rhs.internal_union_value_._error)
                    )
                );
            }
            else if(rhs.tag_ == 1)
            {
                do_emplace<1>(
                    std::forward<uavcan::metatransport::can::DataFD_0_1>(
                        *reinterpret_cast<std::add_pointer<uavcan::metatransport::can::DataFD_0_1>::type>(&rhs.internal_union_value_.data_fd)
                    )
                );
            }
            else if(rhs.tag_ == 2)
            {
                do_emplace<2>(
                    std::forward<uavcan::metatransport::can::DataClassic_0_1>(
                        *reinterpret_cast<std::add_pointer<uavcan::metatransport::can::DataClassic_0_1>::type>(&rhs.internal_union_value_.data_classic)
                    )
                );
            }
            else if(rhs.tag_ == 3)
            {
                do_emplace<3>(
                    std::forward<uavcan::metatransport::can::RTR_0_1>(
                        *reinterpret_cast<std::add_pointer<uavcan::metatransport::can::RTR_0_1>::type>(&rhs.internal_union_value_.remote_transmission_request)
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
            static constexpr const std::size_t _error = 0U;
            static constexpr const std::size_t data_fd = 1U;
            static constexpr const std::size_t data_classic = 2U;
            static constexpr const std::size_t remote_transmission_request = 3U;
        };
        static constexpr const std::size_t MAX_INDEX = 4U;

        template<std::size_t I, class...Types> struct alternative;

        template<class...Types> struct alternative<0U, Types...>
        {
            using type = uavcan::metatransport::can::Error_0_1;
            static constexpr auto pointer = &VariantType::internal_union_t::_error;
        };
        template<class...Types> struct alternative<1U, Types...>
        {
            using type = uavcan::metatransport::can::DataFD_0_1;
            static constexpr auto pointer = &VariantType::internal_union_t::data_fd;
        };
        template<class...Types> struct alternative<2U, Types...>
        {
            using type = uavcan::metatransport::can::DataClassic_0_1;
            static constexpr auto pointer = &VariantType::internal_union_t::data_classic;
        };
        template<class...Types> struct alternative<3U, Types...>
        {
            using type = uavcan::metatransport::can::RTR_0_1;
            static constexpr auto pointer = &VariantType::internal_union_t::remote_transmission_request;
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
                reinterpret_cast<uavcan::metatransport::can::Error_0_1*>(std::addressof(internal_union_value_._error))->~Error_0_1();
            }
            else if (tag_ == 1)
            {
                reinterpret_cast<uavcan::metatransport::can::DataFD_0_1*>(std::addressof(internal_union_value_.data_fd))->~DataFD_0_1();
            }
            else if (tag_ == 2)
            {
                reinterpret_cast<uavcan::metatransport::can::DataClassic_0_1*>(std::addressof(internal_union_value_.data_classic))->~DataClassic_0_1();
            }
            else if (tag_ == 3)
            {
                reinterpret_cast<uavcan::metatransport::can::RTR_0_1*>(std::addressof(internal_union_value_.remote_transmission_request))->~RTR_0_1();
            }
        }

    };

    VariantType union_value;

    bool is__error() const {
        return VariantType::IndexOf::_error == union_value.index();
    }

    typename std::add_pointer<uavcan::metatransport::can::Error_0_1>::type get__error_if(){
        return VariantType::get_if<VariantType::IndexOf::_error>(&union_value);
    }

    typename std::add_pointer<const uavcan::metatransport::can::Error_0_1>::type get__error_if() const{
        return VariantType::get_if<VariantType::IndexOf::_error>(&union_value);
    }

    typename std::add_lvalue_reference<uavcan::metatransport::can::Error_0_1>::type get__error(){
        NUNAVUT_ASSERT(is__error());
        return *VariantType::get_if<VariantType::IndexOf::_error>(&union_value);
    }

    typename std::add_lvalue_reference<const uavcan::metatransport::can::Error_0_1>::type get__error() const{
        NUNAVUT_ASSERT(is__error());
        return *VariantType::get_if<VariantType::IndexOf::_error>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<uavcan::metatransport::can::Error_0_1>::type
    set__error(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::_error>(v...);
    }
    bool is_data_fd() const {
        return VariantType::IndexOf::data_fd == union_value.index();
    }

    typename std::add_pointer<uavcan::metatransport::can::DataFD_0_1>::type get_data_fd_if(){
        return VariantType::get_if<VariantType::IndexOf::data_fd>(&union_value);
    }

    typename std::add_pointer<const uavcan::metatransport::can::DataFD_0_1>::type get_data_fd_if() const{
        return VariantType::get_if<VariantType::IndexOf::data_fd>(&union_value);
    }

    typename std::add_lvalue_reference<uavcan::metatransport::can::DataFD_0_1>::type get_data_fd(){
        NUNAVUT_ASSERT(is_data_fd());
        return *VariantType::get_if<VariantType::IndexOf::data_fd>(&union_value);
    }

    typename std::add_lvalue_reference<const uavcan::metatransport::can::DataFD_0_1>::type get_data_fd() const{
        NUNAVUT_ASSERT(is_data_fd());
        return *VariantType::get_if<VariantType::IndexOf::data_fd>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<uavcan::metatransport::can::DataFD_0_1>::type
    set_data_fd(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::data_fd>(v...);
    }
    bool is_data_classic() const {
        return VariantType::IndexOf::data_classic == union_value.index();
    }

    typename std::add_pointer<uavcan::metatransport::can::DataClassic_0_1>::type get_data_classic_if(){
        return VariantType::get_if<VariantType::IndexOf::data_classic>(&union_value);
    }

    typename std::add_pointer<const uavcan::metatransport::can::DataClassic_0_1>::type get_data_classic_if() const{
        return VariantType::get_if<VariantType::IndexOf::data_classic>(&union_value);
    }

    typename std::add_lvalue_reference<uavcan::metatransport::can::DataClassic_0_1>::type get_data_classic(){
        NUNAVUT_ASSERT(is_data_classic());
        return *VariantType::get_if<VariantType::IndexOf::data_classic>(&union_value);
    }

    typename std::add_lvalue_reference<const uavcan::metatransport::can::DataClassic_0_1>::type get_data_classic() const{
        NUNAVUT_ASSERT(is_data_classic());
        return *VariantType::get_if<VariantType::IndexOf::data_classic>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<uavcan::metatransport::can::DataClassic_0_1>::type
    set_data_classic(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::data_classic>(v...);
    }
    bool is_remote_transmission_request() const {
        return VariantType::IndexOf::remote_transmission_request == union_value.index();
    }

    typename std::add_pointer<uavcan::metatransport::can::RTR_0_1>::type get_remote_transmission_request_if(){
        return VariantType::get_if<VariantType::IndexOf::remote_transmission_request>(&union_value);
    }

    typename std::add_pointer<const uavcan::metatransport::can::RTR_0_1>::type get_remote_transmission_request_if() const{
        return VariantType::get_if<VariantType::IndexOf::remote_transmission_request>(&union_value);
    }

    typename std::add_lvalue_reference<uavcan::metatransport::can::RTR_0_1>::type get_remote_transmission_request(){
        NUNAVUT_ASSERT(is_remote_transmission_request());
        return *VariantType::get_if<VariantType::IndexOf::remote_transmission_request>(&union_value);
    }

    typename std::add_lvalue_reference<const uavcan::metatransport::can::RTR_0_1>::type get_remote_transmission_request() const{
        NUNAVUT_ASSERT(is_remote_transmission_request());
        return *VariantType::get_if<VariantType::IndexOf::remote_transmission_request>(&union_value);
    }

    template<class... Args> typename std::add_lvalue_reference<uavcan::metatransport::can::RTR_0_1>::type
    set_remote_transmission_request(Args&&...v){
        return union_value.emplace<VariantType::IndexOf::remote_transmission_request>(v...);
    }

    nunavut::support::SerializeResult
    serialize(nunavut::support::bitspan out_buffer) const
    {
        const std::size_t capacity_bits = out_buffer.size();
        if ((static_cast<std::size_t>(capacity_bits)) < 568UL)
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
        if (VariantType::IndexOf::_error == _index0_)
        {
            auto _ptr0_ = get__error_if();
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(32ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 4UL;  // Nested object (max) size, in bytes.
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
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 32ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        else if (VariantType::IndexOf::data_fd == _index0_)
        {
            auto _ptr0_ = get_data_fd_if();
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(560ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 70UL;  // Nested object (max) size, in bytes.
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
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) >= 48ULL);
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) <= 560ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        else if (VariantType::IndexOf::data_classic == _index0_)
        {
            auto _ptr0_ = get_data_classic_if();
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(112ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 14UL;  // Nested object (max) size, in bytes.
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
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) >= 48ULL);
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) <= 112ULL);
            out_buffer.add_offset(_size_bytes0_ * 8U);
            // NUNAVUT_ASSERT(out_buffer.size() >= 0);
        }
        else if (VariantType::IndexOf::remote_transmission_request == _index0_)
        {
            auto _ptr0_ = get_remote_transmission_request_if();
            NUNAVUT_ASSERT(out_buffer.offset_alings_to(8U));
            NUNAVUT_ASSERT(out_buffer.offset_alings_to_byte());
            NUNAVUT_ASSERT(40ULL <= out_buffer.size());
            std::size_t _size_bytes0_ = 5UL;  // Nested object (max) size, in bytes.
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
            NUNAVUT_ASSERT((_size_bytes0_ * 8U) == 40ULL);
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
        NUNAVUT_ASSERT(out_buffer.offset() >= 40ULL);
        NUNAVUT_ASSERT(out_buffer.offset() <= 568ULL);
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
        if (VariantType::IndexOf::_error == _index3_)
        {
            set__error();
            auto _ptr1_ = get__error_if();
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
        else if (VariantType::IndexOf::data_fd == _index3_)
        {
            set_data_fd();
            auto _ptr1_ = get_data_fd_if();
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
        else if (VariantType::IndexOf::data_classic == _index3_)
        {
            set_data_classic();
            auto _ptr1_ = get_data_classic_if();
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
        else if (VariantType::IndexOf::remote_transmission_request == _index3_)
        {
            set_remote_transmission_request();
            auto _ptr1_ = get_remote_transmission_request_if();
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

} // namespace can
} // namespace metatransport
} // namespace uavcan

#endif // UAVCAN_METATRANSPORT_CAN_MANIFESTATION_0_1_HPP_INCLUDED
