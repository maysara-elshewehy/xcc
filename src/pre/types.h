/* ┏FILE─INFO━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */
    /**
     * @file        src/pre/types.h
     *
     * @brief       Standardize basic data types and facilitate access to it
     *
     * @author      Maysara Elshewehy (maysara.elshewehy@gmail.com)
     *
     * @version     0.0.3
     *
     * @date        2018-05-23
     *
     * @copyright   Copyright (c) 2018 - xeerx
     *
     * @see         docs/pre/types.md
    */
/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─SETUP━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #ifndef XCC_H_PRE_TYPES
        #define XCC_H_PRE_TYPES

        #define XCC_H_PRE_TYPES_MAJ                     1
        #define XCC_H_PRE_TYPES_MIN                     0
        #define XCC_H_PRE_TYPES_PAT                     0
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌HEADERS───────────────────────────────────────────────────────────────────────────┐ */
        #include <concepts>                             // ↭ [C++] concepts
        #include <cstddef>                              // ↭ [C++] definitions
        #include <type_traits>                          // ↭ [C++] traits
        #include <iterator>                             // ↭ [C++] iterators
        #include <algorithm>                            // ↭ [C++] algorithms
        #include <compare>                              // ↭ [C++] comparison
        #include <utility>                              // ↭ [C++] utilities
        #include <cassert>                              // ↭ [C++] assertions
        #include <memory>                               // ↭ [C++] allocators
        #include <new>                                  // ↭ [C++] memory options
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌REQUIREMENTS──────────────────────────────────────────────────────────────────────┐ */
        // -
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏CODE━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TYPES ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc
        {
            // : Characters
            using t_wchar       =       wchar_t;
            using t_char        =       char;
            using t_char8       =       char8_t;
            using t_char16      =       char16_t;
            using t_char32      =       char32_t;


            // : Unsigned Integers
            using t_uint8       =       unsigned char;
            using t_uint16      =       unsigned short;
            using t_uint32      =       unsigned int;
            using t_uint64      =       unsigned long;


            // : Signed Integers
            using t_int8        =       signed char;
            using t_int16       =       signed short;
            using t_int32       =       signed int;
            using t_int64       =       signed long;


            // : Floating Point
            using t_float       =       float;
            using t_float32     =       t_float;
            using t_double      =       double;
            using t_float64     =       t_double;


            // : Booleans
            using t_bool        =       bool;


            // : Common types
            using t_align       =       std::align_val_t;
            using t_size        =       std::size_t;
            using t_pdif        =       std::ptrdiff_t;
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONCEPTS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::conc
        {
            // :
            template <typename A, typename ...B>
            concept same_as                         = (... && std::same_as<A, B>);

            template <typename A, typename ...B>
            concept same_as_any                     = (... || same_as<A, B>);

            template <typename A, typename ...B>
            concept child_of                        = (... && std::is_base_of_v<B, A>);

            template <typename A, typename ...B>
            concept child_of_any                    = (... || child_of<B, A>);


            // :
            template <typename T>
            concept chars                           = same_as_any<T, char, wchar_t, char8_t, char16_t, char32_t>;

            template <typename T>
            concept uints                           = same_as_any<T, t_uint8, t_uint16, t_uint32, t_uint64>;

            template <typename T>
            concept sints                           = same_as_any<T, t_int8, t_int16, t_int32, t_int64>;

            template <typename T>
            concept ints                            = uints<T> || sints<T>;

            template <typename T>
            concept floats                          = same_as_any<T, t_float32, t_float64>;

            template <typename T>
            concept bools                           = same_as_any<T, t_bool>;
        }


        namespace xcc::conc::details
        {
            // :
            template<typename _Tp>
            concept boolean_testable_impl = std::convertible_to<_Tp, bool>;

            template<typename _Tp>
            concept boolean_testable = boolean_testable_impl<_Tp> && requires(_Tp&& _t) { { !static_cast<_Tp&&>(_t) } -> boolean_testable_impl; };
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ TYPE TRAITS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::traits
        {
            // :
            template<typename T_TYPE, t_size T_SIZE>
            struct array
            {
                /* ┌TYPES─────────────────────────────────────────────────────────┐ */

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
                    using t__pdif           = t_pdif;
                    using c__pdif           = const t_pdif;
                    using cr_pdif           = const t_pdif&;

                    // : traits
                    typedef std::is_swappable<t__val> Is_swappable;
                    typedef std::is_nothrow_swappable<t__val> Is_nothrow_swappable;

                    // : array
                    using t__arr            = T_TYPE[T_SIZE];

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌HELPER─FUNCTIONS──────────────────────────────────────────────┐ */

                    static constexpr t__ref     H_ref       (const t__arr& _t, cr_size _n)      noexcept
                    { return const_cast<t__ref>(_t[_n]); }

                    static constexpr t__ptr     H_ptr       (const t__arr& _t)                  noexcept
                    { return const_cast<t__ptr>(_t); }

                /* └──────────────────────────────────────────────────────────────┘ */
            };

            // :
            template<typename T_TYPE>
            struct array<T_TYPE, 0>
            {
                /* ┌TYPES─────────────────────────────────────────────────────────┐ */

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
                    using t__pdif           = t_pdif;
                    using c__pdif           = const t_pdif;
                    using cr_pdif           = const t_pdif&;

                    // : traits
                    typedef std::true_type Is_swappable;
                    typedef std::true_type Is_nothrow_swappable;

                    // : array
                    struct t__arr           { };

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌HELPER─FUNCTIONS──────────────────────────────────────────────┐ */

                    static constexpr t__ref     H_ref       (const t__arr&, cr_size)            noexcept
                    { return *static_cast<t__ptr>(nullptr); }

                    static constexpr t__ptr     H_ptr       (const t__arr&)                     noexcept
                    { return nullptr; }

                /* └──────────────────────────────────────────────────────────────┘ */
            };
        }


        namespace xcc::traits::details
        {
            // :
            // - credit : GCC/MSVC <compare> header file
            struct synth3way
            {

                /* ┌HELPER─FUNCTIONS──────────────────────────────────────────────┐ */

                    // :
                    template<typename _Tp, typename _Up>
                    static constexpr bool       H_noexcept  (const _Tp* _t = nullptr, const _Up* _u = nullptr)
                    {
                        if constexpr (std::three_way_comparable_with<_Tp, _Up>)
                            return noexcept(*_t <=> *_u);
                        else
                            return noexcept(*_t < *_u) && noexcept(*_u < *_t);
                    }

                    // :
                    template<typename _Tp, typename _Up>
                    constexpr auto              operator()  (const _Tp& _t, const _Up& _u)      const noexcept(H_noexcept<_Tp, _Up>())
                    requires requires
                    {
                        { _t < _u } -> conc::details::boolean_testable;
                        { _u < _t } -> conc::details::boolean_testable;
                    }
                    {
                        if constexpr (std::three_way_comparable_with<_Tp, _Up>)
                            return _t <=> _u;
                        else
                        {
                            if (_t < _u)
                                return std::weak_ordering::less;
                            else if (_u < _t)
                                return std::weak_ordering::greater;
                            else
                                return std::weak_ordering::equivalent;
                        }
                    }

                /* └──────────────────────────────────────────────────────────────┘ */

            };


            // :
            template<typename _Tp, typename _Up = _Tp>
            using synth3way_t = decltype(synth3way(std::declval<_Tp&>(), std::declval<_Up&>()));
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─END━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #endif
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */
