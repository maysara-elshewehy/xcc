# `xcc` `types` Array

Fixed-size array type (fully compatible with C++ standards, interface as `std::array`).

---

## API

| Section                                         |
| ----------------------------------------------- |
| [Setup](#setup)                                 |
| [Prototype](#prototype)                         |
| [Member Types](#member-types)                   |
| [Member Data](#member-data)                     |
| [Member Functions](#member-function)            |
| [Member Iterator](#member-iterator)             |
| [Member Capacity](#member-capacity)             |
| [Member Element Access](#member-element-access) |
| [Global Conversions](#global-conversions)       |
| [Global Comparisons](#global-comparisons)       |
| [Global Functions](#global-functions)           |

---

- ## Setup

  > Download the project from [github repo](https://github.com/xeerx/xcc) then rename the _src_ folder to _xcc_ then copy the _xcc_ folder to your project directory, That's it !

  - #### Include

    ```cpp
    #include "xcc/types/array.h"
    ```

  - #### Namespaces

    ```cpp
    namespace xcc;          // The main namespace
    ```

  ***

- ## Prototype

  ```cpp
  template<typename T_TYPE, xcc::t_size T_SIZE>
  struct xcc::array
  ```

  ***

- ## Member Types

  | type        | real-type                            |
  | ----------- | ------------------------------------ |
  | `t__traits` | `xcc::traits::array<T_TYPE, T_SIZE>` |
  | `t__val`    | `T_TYPE`                             |
  | `t__ptr`    | `t__val*`                            |
  | `c__ptr`    | `const t__val*`                      |
  | `t__ref`    | `t__val&`                            |
  | `c__ref`    | `const t__val&`                      |
  | `t__itr`    | `t__val*`                            |
  | `c__itr`    | `const t__val*`                      |
  | `t__ritr`   | `std::reverse_iterator<t__itr>`      |
  | `c__ritr`   | `std::reverse_iterator<c__itr>`      |
  | `t__size`   | `xcc::t_size`                        |
  | `c__size`   | `const xcc::t_size`                  |
  | `cr_size`   | `const xcc::t_size&`                 |
  | `t__self`   | `array<T_TYPE, T_SIZE>`              |
  | `c__self`   | `const array<T_TYPE, T_SIZE>`        |
  | `r__self`   | `array<T_TYPE, T_SIZE>&`             |
  | `cr_self`   | `const array<T_TYPE, T_SIZE>&`       |
  | `l__self`   | `array<T_TYPE, T_SIZE>&&`            |

  ***

- ## Member Data

  | data    | type                | definition               |
  | ------- | ------------------- | ------------------------ |
  | `M_src` | `t__traits::t__arr` | to store the source data |

  ***

- ## Member Functions

  ```cpp
  constexpr void          fill        (c__ref  _val)
  ```

  ```cpp
  constexpr void          swap        (r__self _val) noexcept(...)
  ```

  ***

- ## Member Iterators

  ```cpp
  constexpr t__itr        begin       () noexcept
  ```

  ```cpp
  constexpr c__itr        begin       () const noexcept
  ```

  ```cpp
  constexpr t__itr        end         () noexcept
  ```

  ```cpp
  constexpr c__itr        end         () const noexcept
  ```

  ```cpp
  constexpr t__ritr       rbegin      () noexcept
  ```

  ```cpp
  constexpr c__ritr       rbegin      () const noexcept
  ```

  ```cpp
  constexpr t__ritr       rend        () noexcept
  ```

  ```cpp
  constexpr c__ritr       rend        () const noexcept
  ```

  ```cpp
  constexpr c__itr        cbegin      () const noexcept
  ```

  ```cpp
  constexpr c__itr        cend        () const noexcept
  ```

  ```cpp
  constexpr c__ritr       crbegin     () const noexcept
  ```

  ```cpp
  constexpr c__ritr       crend       () const noexcept
  ```

  ***

- ## Member Capacity

  ```cpp
  constexpr t__size       size        () const noexcept
  ```

  ```cpp
  constexpr t__size       max_size    () const noexcept
  ```

  ```cpp
  XCC_ENV_ATTR_NODISCARD
  constexpr t_bool        empty       () const noexcept
  ```

  ***

- ## Member Element Access

  ```cpp
  constexpr t__ref        operator[]  (cr_size _val) noexcept
  ```

  ```cpp
  constexpr c__ref        operator[]  (cr_size _val) const noexcept
  ```

  ```cpp
  constexpr t__ref        at          (cr_size _val)
  ```

  ```cpp
  constexpr c__ref        at          (cr_size _val) const
  ```

  ```cpp
  constexpr t__ref        front       () noexcept
  ```

  ```cpp
  constexpr c__ref        front       () const noexcept
  ```

  ```cpp
  constexpr t__ref        back        () noexcept
  ```

  ```cpp
  constexpr c__ref        back        () const noexcept
  ```

  ```cpp
  constexpr t__ptr        data        () noexcept
  ```

  ```cpp
  constexpr c__ptr        data        () const noexcept
  ```

  ***

- ## Global conversions

  > in namespace `xcc`

  ```cpp
  XCC_ENV_ATTR_NODISCARD
  constexpr xcc::array<std::remove_cv_t<T_TYPE>, T_SIZE> xcc::to_array(T_TYPE (&_a)[T_SIZE])
  ```

  ```cpp
  XCC_ENV_ATTR_NODISCARD
  constexpr xcc::array<std::remove_cv_t<T_TYPE>, T_SIZE> xcc::to_array(T_TYPE (&&_a)[T_SIZE])
  ```

  ***

- ## Global Comparisons

  ```cpp
  template<typename T_TYPE, t_size T_SIZE>
  constexpr inline t_bool
  operator==  (const xcc::array<T_TYPE, T_SIZE>& _one, const xcc::array<T_TYPE, T_SIZE>& _two)
  ```

  ```cpp
  template<typename T_TYPE, t_size T_SIZE>
  constexpr inline traits::details::synth3way_t<T_TYPE>
  operator<=> (const xcc::array<T_TYPE, T_SIZE>& _a, const xcc::array<T_TYPE, T_SIZE>& _b)
  ```

  ***

- ## Global Functions

  ```cpp
  template<typename T_TYPE, t_size T_SIZE>
  constexpr inline typename std::enable_if<traits::array<T_TYPE, T_SIZE>::Is_swappable::value>::type
  xcc::swap(xcc::array<T_TYPE, T_SIZE>& _a, xcc::array<T_TYPE, T_SIZE>& _b) noexcept(...)
  ```

  ```cpp
  template<typename T_TYPE, t_size T_SIZE>
  inline typename std::enable_if<!traits::array<T_TYPE, T_SIZE>::Is_swappable::value>::type
  xcc::swap(xcc::array<T_TYPE, T_SIZE>&, xcc::array<T_TYPE, T_SIZE>&) = delete;
  ```

  ```cpp
  template<t_size T_INT, typename T_TYPE, t_size T_SIZE>
  constexpr T_TYPE&           xcc::get         (xcc::array<T_TYPE, T_SIZE>& _v)         noexcept
  ```

  ```cpp
  template<t_size T_INT, typename T_TYPE, t_size T_SIZE>
  constexpr const T_TYPE&     xcc::get         (const xcc::array<T_TYPE, T_SIZE>& _v)   noexcept
  ```

  ```cpp
  template<t_size T_INT, typename T_TYPE, t_size T_SIZE>
  constexpr T_TYPE&&          xcc::get         (xcc::array<T_TYPE, T_SIZE>&& _v)        noexcept
  ```

  ```cpp
  template<t_size T_INT, typename T_TYPE, t_size T_SIZE>
  constexpr const T_TYPE&&    xcc::get         (const xcc::array<T_TYPE, T_SIZE>&& _v)  noexcept
  ```

---

## More

- ### Tests

  > see : [`dist/test/array.cpp`](../../dist/test/array.cpp)

- ### Benchmark

  > see : [`dist/bench/array.cpp`](../../dist/bench/array.cpp)

  ```
  +---------------------------------------------------------+
  +                          arrays                         +
  +---------------------------------------------------------+
  | NODE                       | TIME (ns)      | RATIO     |
  + ---------------------------+ ---------------+ --------- +
  | xcc_version                | 38             | 50%       |
  | std_version                | 38             | 50%       |
  + ---------------------------+ ---------------+ --------- +
  ```

---

## Related

- **[`xcc` `types`](readme.md)**

- **[`xcc`](../../readme.md)**
