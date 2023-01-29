//
// Copyright 2021 Amazon.com, Inc. or its affiliates. All Rights Reserved.
// Copyright (C) 2014 Pavel Kirienko <pavel.kirienko@gmail.com>
// Copyright (C) 2021  OpenCyphal Development Team  <opencyphal.org>
// This software is distributed under the terms of the MIT License.
//

#ifndef NUNAVUT_SUPPORT_VARIABLE_LENGTH_ARRAY_HPP_INCLUDED
#define NUNAVUT_SUPPORT_VARIABLE_LENGTH_ARRAY_HPP_INCLUDED

#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <type_traits>
#include <memory>
#include <utility>
#include <initializer_list>
#if __cpp_exceptions
#    include <stdexcept>
#endif

static_assert(
    __cplusplus >= 201402L,
    "Unsupported language: ISO C14, C++14, or a newer version of either is required to use the built-in VLA type");

namespace nunavut
{
namespace support
{

/**
 * Default allocator using malloc and free.
 */
template <typename T>
class MallocAllocator
{
public:
    using value_type = T;

    MallocAllocator() noexcept {}

    T* allocate(std::size_t n) noexcept
    {
        return reinterpret_cast<T*>(malloc(n * sizeof(T)));
    }

    constexpr void deallocate(T* p, std::size_t n) noexcept
    {
        (void) n;
        free(p);
    }
};

///
/// Minimal, generic container for storing Cyphal variable-length arrays. One property that is unique
/// for variable-length arrays is that they have a maximum bound which this implementation enforces.
/// This allows use of an allocator that is backed by statically allocated memory.
///
/// @tparam  T           The type of elements in the array.
/// @tparam  MaxSize     The maximum allowable size and capacity of the array.
/// @tparam  Allocator   The type of allocator.
///
template <typename T, std::size_t MaxSize, typename Allocator = MallocAllocator<T>>
class VariableLengthArray
{
public:
    VariableLengthArray() noexcept(std::is_nothrow_constructible<Allocator>::value)
        : data_(nullptr)
        , capacity_(0)
        , size_(0)
        , alloc_()
    {
    }

    VariableLengthArray(std::initializer_list<T> l) noexcept(
        noexcept(VariableLengthArray<T, MaxSize, Allocator>().reserve(1)) &&
        std::is_nothrow_constructible<Allocator>::value && std::is_nothrow_copy_constructible<T>::value)
        : data_(nullptr)
        , capacity_(0)
        , size_(0)
        , alloc_()
    {
        reserve(l.size());
        for (const_iterator list_item = l.begin(), end = l.end(); list_item != end; ++list_item)
        {
            push_back_impl(*list_item);
        }
    }

    template <class InputIt>
    constexpr VariableLengthArray(
        InputIt           first,
        InputIt           last,
        const std::size_t length,
        const Allocator&  alloc =
            Allocator()) noexcept(noexcept(VariableLengthArray<T, MaxSize, Allocator>().reserve(1)) &&
                                  std::is_nothrow_copy_constructible<Allocator>::value &&
                                  std::is_nothrow_copy_constructible<T>::value)
        : data_(nullptr)
        , capacity_(0)
        , size_(0)
        , alloc_(alloc)
    {
        reserve(length);
        for (size_t inserted = 0; first != last && inserted < length; ++first)
        {
            push_back_impl(*first);
        }
    }

    //
    // Rule of Five.
    //
    VariableLengthArray(const VariableLengthArray& rhs) noexcept(
        noexcept(VariableLengthArray<T, MaxSize, Allocator>().reserve(1)) &&
        std::is_nothrow_copy_constructible<Allocator>::value && std::is_nothrow_copy_constructible<T>::value)
        : data_(nullptr)
        , capacity_(0)
        , size_(0)
        , alloc_(rhs.alloc_)
    {
        reserve(rhs.size());
        for (const_iterator list_item = rhs.cbegin(), end = rhs.cend(); list_item != end; ++list_item)
        {
            push_back_impl(*list_item);
        }
    }

    VariableLengthArray& operator=(const VariableLengthArray& rhs) noexcept(
        noexcept(VariableLengthArray<T, MaxSize, Allocator>::template fast_deallocate<T>(
            nullptr,
            0,
            0,
            std::declval<Allocator&>())) && noexcept(VariableLengthArray<T, MaxSize, Allocator>().reserve(1)) &&
        std::is_nothrow_copy_constructible<Allocator>::value && std::is_nothrow_copy_constructible<T>::value)
    {
        fast_deallocate(data_, size_, capacity_, alloc_);
        data_     = nullptr;
        capacity_ = 0;
        size_     = 0;
        alloc_    = rhs.alloc_;
        reserve(rhs.size());
        for (const_iterator list_item = rhs.cbegin(), end = rhs.cend(); list_item != end; ++list_item)
        {
            push_back_impl(*list_item);
        }
        return *this;
    }

    VariableLengthArray(VariableLengthArray&& rhs) noexcept(std::is_nothrow_move_constructible<Allocator>::value)
        : data_(rhs.data_)
        , capacity_(rhs.capacity_)
        , size_(rhs.size_)
        , alloc_(std::move(rhs.alloc_))
    {
        rhs.data_     = nullptr;
        rhs.capacity_ = 0;
        rhs.size_     = 0;
    }

    VariableLengthArray& operator=(VariableLengthArray&& rhs) noexcept(
        noexcept(VariableLengthArray<T, MaxSize, Allocator>::template fast_deallocate<T>(nullptr,
                                                                                         0,
                                                                                         0,
                                                                                         std::declval<Allocator&>())) &&
        std::is_nothrow_move_assignable<Allocator>::value)
    {
        fast_deallocate(data_, size_, capacity_, alloc_);

        alloc_ = std::move(rhs.alloc_);

        data_     = rhs.data_;
        rhs.data_ = nullptr;

        capacity_     = rhs.capacity_;
        rhs.capacity_ = 0;

        size_     = rhs.size_;
        rhs.size_ = 0;

        return *this;
    }

    ~VariableLengthArray() noexcept(
        noexcept(VariableLengthArray<T, MaxSize, Allocator>::template fast_deallocate<T>(nullptr,
                                                                                         0,
                                                                                         0,
                                                                                         std::declval<Allocator&>())))
    {
        fast_deallocate(data_, size_, capacity_, alloc_);
    }

    constexpr bool operator==(const VariableLengthArray& rhs) const noexcept
    {
        if (size() != rhs.size())
        {
            return false;
        }
        if (data() != rhs.data())
        {
            const_iterator rnext = rhs.cbegin();
            const_iterator rend  = rhs.cend();
            const_iterator lnext = cbegin();
            const_iterator lend  = cend();
            for (; rnext != rend && lnext != lend; ++lnext, ++rnext)
            {
                if (!internal_compare_element(*lnext, *rnext))
                {
                    return false;
                }
            }
            if (rnext != rend || lnext != lend)
            {
                // One of the two iterators returned less then the size value? This is probably a bug but we can only
                // say they are not equal here.
                return false;
            }
        }
        return true;
    }

    constexpr bool operator!=(const VariableLengthArray& rhs) const noexcept(noexcept(operator==(rhs)))
    {
        return !(operator==(rhs));
    }

    ///
    /// STL-like declaration of pointer type.
    ///
    using pointer = typename std::add_pointer<T>::type;

    ///
    /// STL-like declaration of the allocator type.
    ///
    using allocator_type = Allocator;

    ///
    /// STL-like declaration of the iterator type.
    ///
    using iterator = typename std::add_pointer<T>::type;

    ///
    /// STL-like declaration of the const iterator type.
    ///
    using const_iterator = typename std::add_pointer<typename std::add_const<T>::type>::type;

    ///
    /// STL-like declaration of the container's storage type.
    ///
    using value_type = T;

    ///
    /// The maximum size (and capacity) of this array type. This size is derived
    /// from the DSDL definition for a field and represents the maximum number of
    /// elements allowed if the specified allocator is able to provide adequate
    /// memory (i.e. there may be up to this many elements but there shall never
    /// be more).
    ///
    static constexpr const std::size_t type_max_size = MaxSize;

    ///
    /// The maximum size (and capacity) of this array. This method is compatible
    /// with {@code stl::vector::max_size} and always returns {@code type_max_size}.
    ///
    constexpr std::size_t max_size() const noexcept
    {
        return type_max_size;
    }

    // +----------------------------------------------------------------------+
    // | ELEMENT ACCESS
    // +----------------------------------------------------------------------+
    ///
    /// Provides direct, unsafe access to the internal data buffer. This pointer
    /// is invalidated by calls to {@code shrink_to_fit} and {@code reserve}.
    ///
    constexpr const_iterator cbegin() const noexcept
    {
        return data_;
    }

    ///
    /// Pointer to memory location after the last, valid element. This pointer
    /// is invalidated by calls to {@code shrink_to_fit} and {@code reserve}.
    ///
    constexpr const_iterator cend() const noexcept
    {
        if (nullptr == data_)
        {
            return nullptr;
        }
        else
        {
            return &data_[size_];
        }
    }

    ///
    /// Provides direct, unsafe access to the internal data buffer. This pointer
    /// is invalidated by calls to {@code shrink_to_fit} and {@code reserve}.
    ///
    constexpr iterator begin() noexcept
    {
        return data_;
    }

    ///
    /// Pointer to memory location after the last, valid element. This pointer
    /// is invalidated by calls to {@code shrink_to_fit} and {@code reserve}.
    ///
    constexpr iterator end() noexcept
    {
        if (nullptr == data_)
        {
            return nullptr;
        }
        else
        {
            return &data_[size_];
        }
    }

    ///
    /// Provides direct, unsafe access to the internal data buffer. This pointer
    /// is invalidated by calls to {@code shrink_to_fit} and {@code reserve}.
    ///
    constexpr T* data() noexcept
    {
        return data_;
    }

    ///
    /// Provides direct, unsafe access to the internal data buffer. This pointer
    /// is invalidated by calls to {@code shrink_to_fit} and {@code reserve}.
    ///
    constexpr const T* data() const noexcept
    {
        return data_;
    }

    ///
    /// Direct, const access to an element. If {@code pos} is > {@code size}
    /// the behavior is undefined.
    ///
    /// The returned reference is valid while this object is unless
    /// {@code reserve} or {@code shrink_to_fit} is called.
    ///
    constexpr const T& operator[](std::size_t pos) const noexcept
    {
        return data_[pos];
    }

    ///
    /// Direct access to an element. If {@code pos} is > {@code size}
    /// the behavior is undefined.
    ///
    /// The returned reference is valid while this object is unless
    /// {@code reserve} or {@code shrink_to_fit} is called.
    ///
    constexpr T& operator[](std::size_t pos) noexcept
    {
        return data_[pos];
    }

    ///
    /// Safe, const access to an element. Returns a pointer to the element if
    /// pos is < {@link size} otherwise returns {@code nullptr}.
    ///
    /// The returned pointer is valid while this object is unless
    /// {@code reserve} or {@code shrink_to_fit} is called.
    ///
    constexpr const T* at_or_null(std::size_t pos) const noexcept
    {
        if (pos < size_)
        {
            return &data_[pos];
        }
        else
        {
            return nullptr;
        }
    }

    ///
    /// Safe access to an element. Returns a pointer to the element if
    /// pos is < {@link size} otherwise returns {@code nullptr}.
    ///
    /// The returned pointer is valid while this object is unless
    /// {@code reserve} or {@code shrink_to_fit} is called.
    ///
    constexpr T* at_or_null(std::size_t pos) noexcept
    {
        if (pos < size_)
        {
            return &data_[pos];
        }
        else
        {
            return nullptr;
        }
    }

    ///
    /// STL-like access to a copy of the internal allocator.
    ///
    constexpr allocator_type get_allocator() const noexcept
    {
        return alloc_;
    }

    ///
    /// Provided to allow access to statically allocated buffers stored within
    /// the allocator instance.
    ///
    constexpr const allocator_type& peek_allocator() const noexcept
    {
        return alloc_;
    }

    // +----------------------------------------------------------------------+
    // | CAPACITY
    // +----------------------------------------------------------------------+
    ///
    /// The number of elements that can be stored in the array without further
    /// allocations. This number will only grow through calls to {@code reserve}
    /// and can shrink through calls to {@code shrink_to_fit}. This value shall
    /// never exceed {@code max_size}.
    ///
    constexpr std::size_t capacity() const noexcept
    {
        return capacity_;
    }

    ///
    /// The current number of elements in the array. This number increases with each
    /// successful call to {@code push_back} and decreases with each call to
    /// {@code pop_back} (when size is > 0).
    ///
    constexpr std::size_t size() const noexcept
    {
        return size_;
    }

    ///
    /// Ensure enough memory is allocated to store at least the {@code desired_capacity} number of elements.
    /// This container is different then STL vector in requiring up-front reservation of the necessary
    /// capacity. It does not allocate on push_back.
    ///
    /// @param  desired_capacity The number of elements to allocate, but not initialize, memory for.
    /// @return The new (or unchanged) capacity of this object.
    ///
    std::size_t reserve(const std::size_t desired_capacity) noexcept(noexcept(allocator_type().allocate(0)) && noexcept(
        VariableLengthArray<T, MaxSize, Allocator>::template move_and_free<T>(nullptr,
                                                                              nullptr,
                                                                              0,
                                                                              0,
                                                                              std::declval<Allocator&>())))
    {
        const std::size_t clamped_capacity   = (desired_capacity > MaxSize) ? MaxSize : desired_capacity;
        const std::size_t no_shrink_capacity = (clamped_capacity > size_) ? clamped_capacity : size_;

        T* new_data = nullptr;

#if __cpp_exceptions
        try
        {
            new_data = alloc_.allocate(no_shrink_capacity);
        } catch (const std::bad_alloc& e)
        {
            // we ignore the exception since all allocation failures are modeled using
            // null by this class.
            (void) e;
        }
#else
        new_data = alloc_.allocate(no_shrink_capacity);
#endif

        if (new_data != nullptr)
        {
            if (new_data != data_)
            {
                move_and_free(new_data, data_, size_, capacity_, alloc_);
            }  // else the allocator was able to simply extend the reserved area for the same memory pointer.
            data_     = new_data;
            capacity_ = no_shrink_capacity;
        }

        return capacity_;
    }

    ///
    /// Deallocate or reallocate memory such that not more than {@code size()} elements can be stored in this object.
    ///
    /// @return True if nothing was done or if memory was successfully resized. False to indicate that the allocator
    ///         could not provide enough memory to move the existing objects to a smaller allocation.
    ///
    bool shrink_to_fit() noexcept(
        noexcept(allocator_type().deallocate(nullptr, 0)) && noexcept(allocator_type().allocate(0)) && noexcept(
            VariableLengthArray<T, MaxSize, Allocator>::template move_and_free<T>(nullptr,
                                                                                  nullptr,
                                                                                  0,
                                                                                  0,
                                                                                  std::declval<Allocator&>())))
    {
        if (size_ == capacity_)
        {
            // already shrunk
            return true;
        }

        // Special case where we are shrinking to empty
        if (size_ == 0)
        {
            alloc_.deallocate(data_, capacity_);
            data_     = nullptr;
            capacity_ = 0;
            return true;
        }

        // Allocate only enough to store what we have.
        T* minimized_data = nullptr;

        try
        {
            minimized_data = alloc_.allocate(size_ * sizeof(T));
        } catch (const std::bad_alloc& e)
        {
            // we ignore the exception since all allocation failures are modeled using
            // null by this class.
            (void) e;
        }

        if (minimized_data == nullptr)
        {
            return false;
        }
        else
        {
            if (minimized_data != data_)
            {
                move_and_free(minimized_data, data_, size_, capacity_, alloc_);
            }  // else the allocator was able to simply shrink the reserved area for the same memory pointer.
            data_     = minimized_data;
            capacity_ = size_;
            return true;
        }
    }

    // +----------------------------------------------------------------------+
    // | MODIFIERS
    // +----------------------------------------------------------------------+
    ///
    /// Construct a new element on to the back of the array. Grows size by 1 and may grow capacity.
    ///
    /// If exceptions are disabled the caller must check before and after to see if the size grew to determine success.
    /// If using exceptions this method throws {@code std::length_error} if the size of this collection is at capacity
    /// or {@code std::bad_alloc} if the allocator failed to provide enough memory.
    ///
    /// If exceptions are disabled use the following logic:
    ///
    ///     const size_t size_before = my_array.size();
    ///     my_array.push_back();
    ///     if (size_before == my_array.size())
    ///     {
    ///         // failure
    ///         if (size_before == my_array.max_size())
    ///         {
    ///             // length_error: you probably should have checked this first.
    ///         }
    ///         else
    ///         {
    ///             // bad_alloc: out of memory
    ///         }
    //      } // else, success.
    ///
    /// @throw std::length_error if the size of this collection is at capacity.
    /// @throw std::bad_alloc if memory was needed and none could be allocated.
    ///
    constexpr void push_back()
    {
        if (!ensure_size_plus_one())
        {
            return;
        }

        if (nullptr == push_back_impl())
        {
#if __cpp_exceptions
            throw std::length_error("size is at capacity. Use reserve to grow the capacity.");
#endif
        }
    }

    ///
    /// Allocate a new element on to the back of the array and move value into it. Grows size by 1 and
    /// may grow capacity.
    ///
    /// See VariableLengthArray::push_back() for full documentation.
    ///
    /// @throw std::length_error if the size of this collection is at capacity.
    /// @throw std::bad_alloc if memory was needed and none could be allocated.
    ///
    constexpr void push_back(T&& value)
    {
        if (!ensure_size_plus_one())
        {
            return;
        }

        if (nullptr == push_back_impl(std::move(value)))
        {
#if __cpp_exceptions
            throw std::length_error("size is at capacity. Use reserve to grow the capacity.");
#endif
        }
    }

    ///
    /// Allocate a new element on to the back of the array and copy value into it. Grows size by 1 and
    /// may grow capacity.
    ///
    /// See VariableLengthArray::push_back() for full documentation.
    ///
    /// @throw std::length_error if the size of this collection is at capacity.
    /// @throw std::bad_alloc if memory was needed and none could be allocated.
    ///
    constexpr void push_back(const T& value)
    {
        if (!ensure_size_plus_one())
        {
            return;
        }

        if (nullptr == push_back_impl(value))
        {
#if __cpp_exceptions
            throw std::length_error("size is at capacity. Use reserve to grow the capacity.");
#endif
        }
    }

    ///
    /// Remove and destroy the last item in the array. This reduces the array size by 1 unless
    /// the array is already empty.
    ///
    constexpr void pop_back() noexcept(std::is_nothrow_destructible<T>::value)
    {
        if (size_ > 0)
        {
            data_[--size_].~T();
        }
    }

private:
    /**
     * Ensure amortized, constant-time expansion of capacity as single items are added.
     */
    constexpr bool ensure_size_plus_one()
    {
        if (size_ < capacity_)
        {
            return true;
        }

        if (capacity_ == MaxSize)
        {
#if __cpp_exceptions
            throw std::length_error("Already at max size. Cannot increase capacity.");
#endif
            return false;
        }

        // https://stackoverflow.com/questions/1100311/what-is-the-ideal-growth-rate-for-a-dynamically-allocated-array/20481237#20481237
        const std::size_t capacity_before = capacity_;

        const std::size_t half_capacity = capacity_before / 2U;

        // That is, instead of a capacity sequence of 1, 2, 3, 4, 6, 9 we start from zero as 2, 4, 6, 9. The first
        // opportunity for reusing previously freed memory comes when increasing to 19 from 13 since E(n-1) == 21.
        const std::size_t new_capacity = capacity_before + ((half_capacity <= 1) ? 2 : half_capacity);

        if (new_capacity > MaxSize)
        {
            reserve(MaxSize);
        }
        else
        {
            reserve(new_capacity);
        }

        if (capacity_before == capacity_)
        {
#if __cpp_exceptions
            throw std::bad_alloc();
#endif
            return false;
        }
        else
        {
            return true;
        }
    }

    template <typename U>
    static constexpr bool internal_compare_element(
        const U& lhs,
        const U& rhs,
        typename std::enable_if<!std::is_floating_point<U>::value>::type* = 0) noexcept
    {
        return (lhs == rhs);
    }

    template <typename U>
    static constexpr bool internal_compare_element(
        const U& lhs,
        const U& rhs,
        typename std::enable_if<std::is_floating_point<U>::value>::type* = 0) noexcept
    {
        // From the C++ documentation for std::numeric_limits<T>::epsilon()
        // https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon

        const auto diff = std::fabs(lhs - rhs);
        const auto sum  = std::fabs(lhs + rhs);
        // Scale the relative machine epsilon up.
        const auto epsilon = std::numeric_limits<U>::epsilon() * sum;

        return (diff <= epsilon) || diff < std::numeric_limits<U>::min();
    }

    constexpr pointer push_back_impl() noexcept(std::is_nothrow_default_constructible<T>::value)
    {
        if (size_ < capacity_)
        {
            return new (&data_[size_++]) T();
        }
        else
        {
            return nullptr;
        }
    }

    constexpr pointer push_back_impl(T&& value) noexcept(std::is_nothrow_move_constructible<T>::value)
    {
        if (size_ < capacity_)
        {
            return new (&data_[size_++]) T(std::move(value));
        }
        else
        {
            return nullptr;
        }
    }

    constexpr pointer push_back_impl(const T& value) noexcept(std::is_nothrow_copy_constructible<T>::value)
    {
        if (size_ < capacity_)
        {
            return new (&data_[size_++]) T(value);
        }
        else
        {
            return nullptr;
        }
    }

    ///
    /// If trivially destructible then we don't have to call the destructors.
    ///
    template <typename U>
    static constexpr void fast_deallocate(U* const          src,
                                          const std::size_t src_size_count,
                                          const std::size_t src_capacity_count,
                                          Allocator&        alloc,
                                          typename std::enable_if<std::is_trivially_destructible<U>::value>::type* =
                                              0) noexcept(noexcept(allocator_type().deallocate(nullptr, 0)))
    {
        (void) src_size_count;
        alloc.deallocate(src, src_capacity_count);
    }

    ///
    /// If not trivially destructible then we invoke each destructor.
    ///
    template <typename U>
    static constexpr void fast_deallocate(
        U* const          src,
        const std::size_t src_size_count,
        const std::size_t src_capacity_count,
        Allocator&        alloc,
        typename std::enable_if<!std::is_trivially_destructible<U>::value>::type* =
            0) noexcept(std::is_nothrow_destructible<U>::value&& noexcept(allocator_type().deallocate(nullptr, 0)))
    {
        std::size_t dtor_iterator = src_size_count;
        while (dtor_iterator > 0)
        {
            src[--dtor_iterator].~U();
        }
        alloc.deallocate(src, src_capacity_count);
    }

    ///
    /// Move stuff in src to dst and then free all the memory allocated for src.
    ///
    template <typename U>
    static constexpr void move_and_free(
        U* const    dst,
        U* const    src,
        std::size_t src_len_count,
        std::size_t src_capacity_count,
        Allocator&  alloc,
        typename std::enable_if<std::is_fundamental<U>::value>::type* =
            0) noexcept(noexcept(fast_deallocate<U>(nullptr, 0, 0, std::declval<Allocator&>())))
    {
        if (src_len_count > 0)
        {
            // The allocator returned new memory. Copy any initialized objects in the old region to the new one.
            std::memcpy(dst, src, src_len_count * sizeof(U));
        }
        fast_deallocate(src, src_len_count, src_capacity_count, alloc);
    }

    ///
    /// Same as above but for non-fundamental types. We can't just memcpy for these.
    ///
    template <typename U>
    static constexpr void move_and_free(
        U* const    dst,
        U* const    src,
        std::size_t src_len_count,
        std::size_t src_capacity_count,
        Allocator&  alloc,
        typename std::enable_if<!std::is_fundamental<U>::value>::type* = 0,
        typename std::enable_if<std::is_move_constructible<U>::value || std::is_copy_constructible<U>::value>::type* =
            0) noexcept((std::is_nothrow_move_constructible<U>::value ||
                         std::is_nothrow_copy_constructible<
                             U>::value) && noexcept(fast_deallocate<U>(nullptr, 0, 0, std::declval<Allocator&>())))
    {
        if (src_len_count > 0)
        {
            // The allocator returned new memory. Copy any initialized objects in the old region to the new one.
            for (size_t i = 0; i < src_len_count; ++i)
            {
                new (&dst[i]) U(std::move_if_noexcept(src[i]));
            }
        }
        fast_deallocate(src, src_len_count, src_capacity_count, alloc);
    }

    // +----------------------------------------------------------------------+
    // | DATA MEMBERS
    // +----------------------------------------------------------------------+
    T*          data_;
    std::size_t capacity_;
    std::size_t size_;
    Allocator   alloc_;
};

// required till C++ 17. Redundant but allowed after that.
template <typename T, std::size_t MaxSize, typename Allocator>
const std::size_t VariableLengthArray<T, MaxSize, Allocator>::type_max_size;

}  // namespace support
}  // namespace nunavut

#endif  // NUNAVUT_SUPPORT_VARIABLE_LENGTH_ARRAY_HPP_INCLUDED
