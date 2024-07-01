/* ┏FILE─INFO━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */
    /**
     * @file        src/types/allocator.h
     *
     * @brief       To alloca
     *
     * @author      Maysara Elshewehy (maysara.elshewehy@gmail.com)
     *
     * @version     1.0.0
     *
     * @date        2023-05-31
     *
     * @copyright   Copyright (c) 2023 - xeerx
     *
     * @see         docs/types/allocator.md
    */
/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─SETUP━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #ifndef XCC_H_TYPES_ALLOC
        #define XCC_H_TYPES_ALLOC
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌VERSION───────────────────────────────────────────────────────────────────────────┐ */
        #define XCC_H_TYPES_ALLOC_MAJ                   1
        #define XCC_H_TYPES_ALLOC_MIN                   0
        #define XCC_H_TYPES_ALLOC_PAT                   0
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
            // : non-void
            template<typename T_TYPE>
            struct allocator
            {
                /* ┌GUARDS────────────────────────────────────────────────────────┐ */

                    // : Avoid incomplete types
                    static_assert(sizeof(T_TYPE) != 0, "cannot allocate incomplete types");

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌TYPES─────────────────────────────────────────────────────────┐ */

                    // : value
                    using t__val            = T_TYPE;
                    using t__ptr            = t__val*;
                    using c__ptr            = const t__val*;
                    using t__ref            = t__val&;
                    using c__ref            = const t__val&;

                    // : size types
                    using t__size           = t_size;
                    using c__size           = const t_size;
                    using cr_size           = const t_size&;
                    using t__pdif           = t_pdif;
                    using c__pdif           = const t_pdif;
                    using cr_pdif           = const t_pdif&;

                    // : self
                    using t__self           = allocator<T_TYPE>;
                    using c__self           = const allocator<T_TYPE>;
                    using r__self           = allocator<T_TYPE>&;
                    using cr_self           = const allocator<T_TYPE>&;
                    using l__self           = allocator<T_TYPE>&&;

                    // : propagate on container move assignment
                    using s__pocma          = std::true_type;
                    using s__equal          = std::true_type;

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌STATICS───────────────────────────────────────────────────────┐ */

                    // : Maximum size
                    static constexpr t__size max_size    ()                                 noexcept
                    {
                        #if defined(__PTRDIFF_MAX__) && defined(__SIZE_MAX__) && (__PTRDIFF_MAX__ < __SIZE_MAX__)
                            return t__size(__PTRDIFF_MAX__) / sizeof(t__val);
                        #else
                            return t__size(-1) / sizeof(t__val);
                        #endif
                    }

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌ASSIGNMENTS───────────────────────────────────────────────────┐ */

                    // : Assign with : empty
                    constexpr allocator            ()                                      noexcept
                    { }

                    // : Assign with : object (copy)
                    constexpr allocator            (const allocator&)                       noexcept
                    { }

                    // : Assign with : other object (copy)
                    template<typename O_TYPE>
                    constexpr allocator            (const allocator<O_TYPE>&)               noexcept
                    { }

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌FUNCTIONS─────────────────────────────────────────────────────┐ */

                    // : Allocate a space in the memory (Array)
                    XCC_ENV_ATTR_NODISCARD XCC_ENV_ATTR_INLINE
                    static constexpr t__ptr allocate   (cr_size _size)
                    {
                        if (std::is_constant_evaluated())
                        {
                            return static_cast<t__ptr>(::operator new(_size * sizeof(t__val)));
                        }

                        else
                        {
                            if ( _size > max_size() ) XCC_ENV_ATTR_LIKELY
                            throw("xcc::memory::alloc::allocate(_size) : _size > max");

                            if (alignof(t__val) > XCC_ENV_DEF_ALIGN_SIZE)
                            {
                                t_align _align = t_align(alignof(t__val));
                                return static_cast<t__ptr>(::operator new(_size * sizeof(t__val), _align));
                            }

                            return static_cast<t__ptr>(::operator new(_size * sizeof(t__val)));
                        }
                    }

                    // : De-allocate a space in the memory (Array)
                    XCC_ENV_ATTR_INLINE
                    static constexpr void   deallocate  (t__ptr _ptr, cr_size _size)
                    {
                        if (std::is_constant_evaluated())
                        {
                            ::operator delete(_ptr);
                        }

                        else
                        {
                            if (alignof(t__val) > XCC_ENV_DEF_ALIGN_SIZE)
                            {
                                ::operator delete(_ptr, _size * sizeof(t__val), t_align(alignof(t__val)));
                            }

                            else
                            {
                                ::operator delete(_ptr , _size * sizeof(t__val) );
                            }
                        }
                    }

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌COMPARISONS───────────────────────────────────────────────────┐ */

                    // : Equality operator (!!?)
                    template<typename O_TYPE>
                    friend constexpr bool   operator==  (const allocator&, const allocator<O_TYPE>&) noexcept
                    { return true; }

                /* └──────────────────────────────────────────────────────────────┘ */
            };

            // : void
            template<>
            struct allocator<void>
            {
                /* ┌TYPES─────────────────────────────────────────────────────────┐ */

                    // : value
                    using t__val            = void;

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌ASSIGNMENTS───────────────────────────────────────────────────┐ */

                    // : Assign with : empty
                    constexpr allocator                 ()                                      = default;

                    // : Assign with : other object (copy)
                    template<typename O_TYPE>
                    constexpr allocator                 (const allocator<O_TYPE>&)         noexcept
                    { }

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌DESTROYERS────────────────────────────────────────────────────┐ */

                    // :
                    constexpr ~allocator                ()                                      = default;

                /* └──────────────────────────────────────────────────────────────┘ */

            };

            // : const
            template<typename T_TYPE>
            struct allocator<const T_TYPE>
            {
                /* ┌TYPES─────────────────────────────────────────────────────────┐ */

                    using t__val            = T_TYPE;

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌ASSIGNMENTS───────────────────────────────────────────────────┐ */

                    template<typename O_TYPE>
                    allocator                               (const allocator<O_TYPE>&)
                    { }

                /* └──────────────────────────────────────────────────────────────┘ */
            };

            // : volatile
            template<typename T_TYPE>
            struct allocator<volatile T_TYPE>
            {
                /* ┌TYPES─────────────────────────────────────────────────────────┐ */

                    using t__val            = T_TYPE;

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌ASSIGNMENTS───────────────────────────────────────────────────┐ */

                    template<typename O_TYPE>
                    allocator                               (const allocator<O_TYPE>&)
                    { }
                /* └──────────────────────────────────────────────────────────────┘ */
            };

            // : const volatile
            template<typename T_TYPE>
            struct allocator<const volatile T_TYPE>
            {
                /* ┌TYPES─────────────────────────────────────────────────────────┐ */

                    using t__val            = T_TYPE;

                /* └──────────────────────────────────────────────────────────────┘ */


                /* ┌ASSIGNMENTS───────────────────────────────────────────────────┐ */

                    template<typename O_TYPE>
                    allocator                               (const allocator<O_TYPE>&)
                    { }

                /* └──────────────────────────────────────────────────────────────┘ */
            };
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ MORE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc
        {
            /* ┌FUNCTIONS─────────────────────────────────────────────────────┐ */

            /* └──────────────────────────────────────────────────────────────┘ */
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─END━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #endif
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */