# `xcc` `types` Allocator

Allocator type (fully compatible with C++ standards, interface as `std::allocator`).

---

## API

| Section                                   |
| ----------------------------------------- |
| [Setup](#setup)                           |
| [Prototype](#prototype)                   |
| [Member Types](#member-types)             |
| [Member Functions](#member-function)      |
| [Member Comparisons](#member-comparisons) |

---

- ## Setup

  > Download the project from [github repo](https://github.com/xeerx/xcc) then rename the _src_ folder to _xcc_ then copy the _xcc_ folder to your project directory, That's it !

  - #### Include

    ```cpp
    #include "xcc/types/allocator.h"
    ```

  - #### Namespaces

    ```cpp
    namespace xcc;          // The main namespace
    ```

  ***

- ## Prototype

  ```cpp
  template<typename T_TYPE>
  struct xcc::allocator
  ```

  ***

- ## Member Types

  | type       | real-type                          |
  | ---------- | ---------------------------------- |
  | `t__val`   | `T_TYPE`                           |
  | `t__ptr`   | `t__val*`                          |
  | `c__ptr`   | `const t__val*`                    |
  | `t__ref`   | `t__val&`                          |
  | `c__ref`   | `const t__val&`                    |
  | `t__size`  | `xcc::t_size`                      |
  | `c__size`  | `const xcc::t_size`                |
  | `cr_size`  | `const xcc::t_size&`               |
  | `t__self`  | `allocator<T_TYPE, T_SIZE>`        |
  | `c__self`  | `const allocator<T_TYPE, T_SIZE>`  |
  | `r__self`  | `allocator<T_TYPE, T_SIZE>&`       |
  | `cr_self`  | `const allocator<T_TYPE, T_SIZE>&` |
  | `l__self`  | `allocator<T_TYPE, T_SIZE>&&`      |
  | `s__pocma` | `std::true_type`                   |
  | `s__equal` | `std::true_type`                   |

  ***

- ## Member Functions

  ```cpp
  XCC_ENV_ATTR_NODISCARD XCC_ENV_ATTR_INLINE
  static constexpr t__ptr allocate   (cr_size _size)                                noexcept
  ```

  ```cpp
  XCC_ENV_ATTR_INLINE
  static constexpr void   deallocate  (t__ptr _ptr, cr_size _size)
  ```

  ```cpp
  static constexpr t__size max_size    ()
  ```

  ***

- ## Member Comparisons

  ```cpp
  template<typename O_TYPE>
  friend constexpr bool   operator==  (const allocator&, const allocator<O_TYPE>&)  noexcept
  ```

---

## More

- ### Tests

  > see : [`dist/test/allocator.cpp`](../../dist/test/allocator.cpp)

- ### Benchmark

  > see : [`dist/bench/allocator.cpp`](../../dist/bench/allocator.cpp)

  ```
  +---------------------------------------------------------+
  +                        allocators                       +
  +---------------------------------------------------------+
  | NODE                       | TIME (ns)      | RATIO     |
  + ---------------------------+ ---------------+ --------- +
  | xcc_version                | 255            | 50%       |
  | std_version                | 255            | 50%       |
  + ---------------------------+ ---------------+ --------- +
  ```

---

## Related

- **[`xcc` `types`](readme.md)**

- **[`xcc`](../../readme.md)**
