/* ┏FILE─INFO━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */
    /**
     * @file        src/types/array.h
     *
     * @brief       A container for storing a fixed size sequence of elements
     *
     * @author      Maysara Elshewehy (maysara.elshewehy@gmail.com)
     *
     * @version     1.0.0
     *
     * @date        2023-05-31
     *
     * @copyright   Copyright (c) 2023 - xeerx
     *
     * @see         docs/types/array.md
    */
/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─SETUP━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #ifndef XCC_H_TYPES_ARRAY
        #define XCC_H_TYPES_ARRAY
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌VERSION───────────────────────────────────────────────────────────────────────────┐ */
        #define XCC_H_TYPES_ARRAY_MAJ                   1
        #define XCC_H_TYPES_ARRAY_MIN                   0
        #define XCC_H_TYPES_ARRAY_PAT                   0
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌HEADERS───────────────────────────────────────────────────────────────────────────┐ */
        #include "../pre/env.h"                         // ↭ X++ Environment
        #include "../pre/types.h"                       // ↭ X++ Types
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌REQUIREMENTS──────────────────────────────────────────────────────────────────────┐ */
        // -
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏CODE━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ BASE / INTERFACE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc
        {
            // :
            template<typename T_TYPE, t_size T_SIZE>
            struct array
            {
                /* ┌TYPES─────────────────────────────────────────────────────────┐ */

                    // : traits
                    using t__traits         = traits::array<T_TYPE, T_SIZE>;

                    // : value
                    using t__val            = T_TYPE;
                    using t__ptr            = t__val*;
                    using c__ptr            = const t__val*;
                    using t__ref            = t__val&;
                    using c__ref            = const t__val&;

                    // : iterators
                    using t__itr            = t__val*;
                    using c__itr            = const t__val*;
                    using t__ritr           = std::reverse_iterator<t__itr>;
                    using c__ritr           = std::reverse_iterator<c__itr>;

                    // : size types
                    using t__size           = t_size;
                    using c__size           = const t_size;
                    using cr_size           = const t_size&;

                    // : self
                    using t__self           = array<T_TYPE, T_SIZE>;
                    using c__self           = const array<T_TYPE, T_SIZE>;
                    using r__self           = array<T_TYPE, T_SIZE>&;
                    using cr_self           = const array<T_TYPE, T_SIZE>&;
                    using l__self           = array<T_TYPE, T_SIZE>&&;

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌DATA──────────────────────────────────────────────────────────┐ */

                    // : source
                    typename t__traits::t__arr                         M_src;

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌ASSIGNMENTS───────────────────────────────────────────────────┐ */

                    // -

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌FUNCTIONS─────────────────────────────────────────────────────┐ */

                    // : Fill all elements with _val
                    constexpr void          fill        (c__ref  _val)
                    { std::fill_n(begin(), size(), _val); }

                    // : Swap this object with another
                    constexpr void          swap        (r__self _val)                          noexcept(t__traits::Is_nothrow_swappable::value)
                    { std::swap_ranges(begin(), end(), _val.begin()); }

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌ITERATORS─────────────────────────────────────────────────────┐ */

                    // : Iterator of the begin
                    constexpr t__itr        begin       ()                                      noexcept
                    { return t__itr(data()); }

                    // : Iterator of the begin (const)
                    constexpr c__itr        begin       ()                                      const noexcept
                    { return c__itr(data()); }

                    // : Const Iterator of the begin
                    constexpr c__itr        cbegin      ()                                      const noexcept
                    { return c__itr(data()); }

                    // : Iterator of the end
                    constexpr t__itr        end         ()                                      noexcept
                    { return t__itr(data() + T_SIZE); }

                    // : Iterator of the end (const)
                    constexpr c__itr        end         ()                                      const noexcept
                    { return c__itr(data() + T_SIZE); }

                    // : Const Iterator of the end
                    constexpr c__itr        cend        ()                                      const noexcept
                    { return c__itr(data() + T_SIZE); }

                    // : Reverse Iterator of the begin
                    constexpr t__ritr       rbegin      ()                                      noexcept
                    { return t__ritr(end()); }

                    // : Reverse Iterator of the begin (const)
                    constexpr c__ritr       rbegin      ()                                      const noexcept
                    { return c__ritr(end()); }

                    // : Const Reverse Iterator of the begin
                    constexpr c__ritr       crbegin     ()                                      const noexcept
                    { return c__ritr(end()); }

                    // : Reverse Iterator of the end
                    constexpr t__ritr       rend        ()                                      noexcept
                    { return t__ritr(begin()); }

                    // : Reverse Iterator of the end (const)
                    constexpr c__ritr       rend        ()                                      const noexcept
                    { return c__ritr(begin()); }

                    // : Const Reverse Iterator of the end
                    constexpr c__ritr       crend       ()                                      const noexcept
                    { return c__ritr(begin()); }

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌CAPACITY──────────────────────────────────────────────────────┐ */

                    // : Return the size of the memory (fixed)
                    constexpr t__size       size        ()                                      const noexcept
                    { return T_SIZE; }

                    // : Return the max-size of the memory (fixed)
                    constexpr t__size       max_size    ()                                      const noexcept
                    { return T_SIZE; }

                    // : Return true if the size of the array is not equal to zero
                    XCC_ENV_ATTR_NODISCARD
                    constexpr t_bool        empty       ()                                      const noexcept
                    { return size() == 0; }

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌ELEMENT─ACCESS────────────────────────────────────────────────┐ */

                    // : Reference of the element
                    constexpr t__ref        operator[]  (cr_size _val)                          noexcept
                    { assert(_val < T_SIZE); return t__traits::H_ref(M_src, _val); }

                    // : Reference of the element (const)
                    constexpr c__ref        operator[]  (cr_size _val)                          const noexcept
                    { assert(_val < T_SIZE); return t__traits::H_ref(M_src, _val); }

                    // : Reference of the element
                    constexpr t__ref        at          (cr_size _val)
                    { if (_val >= T_SIZE) throw ("array::at: _val >= T_SIZE"); return t__traits::H_ref(M_src, _val); }

                    // : Reference of the element (const)
                    constexpr c__ref        at          (cr_size _val)                          const
                    { return _val < T_SIZE ? t__traits::H_ref(M_src, _val) : (throw ("array::at: _val >= T_SIZE"), t__traits::H_ref(M_src, 0)); }

                    // : Reference of the front of the array
                    constexpr t__ref        front       ()                                      noexcept
                    { assert(!empty()); return *begin(); }

                    // : Reference of the front of the array (const)
                    constexpr c__ref        front       ()                                      const noexcept
                    { assert(!empty()); return t__traits::H_ref(M_src, 0); }

                    // : Reference of the back of the array
                    constexpr t__ref        back        ()                                      noexcept
                    { assert(!empty()); return T_SIZE ? *(end() - 1) : *end(); }

                    // : Reference of the back of the array (const)
                    constexpr c__ref        back        ()                                      const noexcept
                    { assert(!empty()); return T_SIZE ? t__traits::H_ref(M_src, T_SIZE - 1) : t__traits::H_ref(M_src, 0); }

                    // : Pointer of the source array
                    constexpr t__ptr        data        ()                                      noexcept
                    { return t__traits::H_ptr(M_src); }

                    // : Pointer of the source array (const)
                    constexpr c__ptr        data        ()                                      const noexcept
                    { return t__traits::H_ptr(M_src); }

                /* └──────────────────────────────────────────────────────────────┘ */
            };
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MORE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc
        {
            /* ┌DEDUCTION─────────────────────────────────────────────────────┐ */

                // : Special declaration
                template<typename T_A, typename... T_B>
                array                              (T_A, T_B...)
                -> array<std::enable_if_t<(std::is_same_v<T_A, T_B> && ...), T_A>, 1 + sizeof...(T_B)>;

            /* └──────────────────────────────────────────────────────────────┘ */


            /* ┌COMPARISONS───────────────────────────────────────────────────┐ */

                // : Return true if the _a and _b are equal
                template<typename T_TYPE, t_size T_SIZE>
                constexpr inline t_bool
                operator==  (const array<T_TYPE, T_SIZE>& _a, const array<T_TYPE, T_SIZE>& _b)
                { return std::equal(_a.begin(), _a.end(), _b.begin()); }

                // : Return to (compare_three_way) result object
                template<typename T_TYPE, t_size T_SIZE>
                constexpr inline traits::details::synth3way_t<T_TYPE>
                operator<=> (const array<T_TYPE, T_SIZE>& _a, const array<T_TYPE, T_SIZE>& _b)
                { return std::lexicographical_compare_three_way(_a.begin(), _a.end(), _b.begin(), _b.end(), traits::details::synth3way{}); }

            /* └──────────────────────────────────────────────────────────────┘ */


            /* ┌FUNCTIONS─────────────────────────────────────────────────────┐ */

                // : Swap two arrays (swappable)
                template<typename T_TYPE, t_size T_SIZE>
                constexpr inline typename std::enable_if<traits::array<T_TYPE, T_SIZE>::Is_swappable::value>::type
                swap(array<T_TYPE, T_SIZE>& _a, array<T_TYPE, T_SIZE>& _b)                    noexcept(noexcept(_a.swap(_b)))
                { _a.swap(_b); }

                // : Swap two arrays (not swappable) (!!?)
                template<typename T_TYPE, t_size T_SIZE>
                inline typename std::enable_if<!traits::array<T_TYPE, T_SIZE>::Is_swappable::value>::type
                swap(array<T_TYPE, T_SIZE>&, array<T_TYPE, T_SIZE>&)                          = delete;

                // : Access to the elements (constant evaluation)
                template<t_size T_INT, typename T_TYPE, t_size T_SIZE>
                constexpr T_TYPE&           get         (array<T_TYPE, T_SIZE>& _v)            noexcept
                { static_assert(T_INT < T_SIZE); return traits::array<T_TYPE, T_SIZE>::H_ref(_v.M_src, T_INT); }

                // : Access to the elements (constant evaluation)
                template<t_size T_INT, typename T_TYPE, t_size T_SIZE>
                constexpr const T_TYPE&     get         (const array<T_TYPE, T_SIZE>& _v)      noexcept
                { static_assert(T_INT < T_SIZE); return traits::array<T_TYPE, T_SIZE>::H_ref(_v.M_src, T_INT); }

                // : Access to the elements (constant evaluation)
                template<t_size T_INT, typename T_TYPE, t_size T_SIZE>
                constexpr T_TYPE&&          get         (array<T_TYPE, T_SIZE>&& _v)           noexcept
                { static_assert(T_INT < T_SIZE); return std::move(std::get<T_INT>(_v)); }

                // : Access to the elements (constant evaluation)
                template<t_size T_INT, typename T_TYPE, t_size T_SIZE>
                constexpr const T_TYPE&&    get         (const array<T_TYPE, T_SIZE>&& _v)     noexcept
                { static_assert(T_INT < T_SIZE); return std::move(std::get<T_INT>(_v)); }

            /* └──────────────────────────────────────────────────────────────┘ */


            /* ┌CONVERSIONS───────────────────────────────────────────────────┐ */

                namespace details
                {
                    // : lvalue implementation version of xcc::to_array
                    template <class T_TYPE, t_size T_SIZE, t_size... T_INDX>
                    XCC_ENV_ATTR_NODISCARD
                    constexpr array<std::remove_cv_t<T_TYPE>, T_SIZE> to_array_lvalue_impl( T_TYPE (&_a)[T_SIZE], std::index_sequence<T_INDX...>)
                    { return {{_a[T_INDX]...}}; }

                    // : rvalue implementation version of xcc::to_array
                    template <class T_TYPE, t_size T_SIZE, t_size... T_INDX>
                    XCC_ENV_ATTR_NODISCARD
                    constexpr array<std::remove_cv_t<T_TYPE>, T_SIZE> to_array_rvalue_impl( T_TYPE (&&_a)[T_SIZE], std::index_sequence<T_INDX...>)
                    { return {{std::move(_a[T_INDX])...}}; }
                }

                // : Return a new array of inputs (lvalue)
                template <class T_TYPE, size_t T_SIZE>
                XCC_ENV_ATTR_NODISCARD
                constexpr array<std::remove_cv_t<T_TYPE>, T_SIZE> to_array(T_TYPE (&_a)[T_SIZE])
                {
                    static_assert(!std::is_array_v<T_TYPE>);
                    static_assert(std::is_constructible_v<T_TYPE, T_TYPE&>);
                    return details::to_array_lvalue_impl(_a, std::make_index_sequence<T_SIZE>{});
                }

                // : Return a new array of inputs (rvalue)
                template <class T_TYPE, size_t T_SIZE>
                XCC_ENV_ATTR_NODISCARD
                constexpr array<std::remove_cv_t<T_TYPE>, T_SIZE> to_array(T_TYPE (&&_a)[T_SIZE])
                {
                    static_assert(!std::is_array_v<T_TYPE>);
                    static_assert(std::is_move_constructible_v<T_TYPE>);
                    return details::to_array_rvalue_impl(std::move(_a), std::make_index_sequence<T_SIZE>{});
                }

            /* └──────────────────────────────────────────────────────────────┘ */
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─END━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #endif
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */