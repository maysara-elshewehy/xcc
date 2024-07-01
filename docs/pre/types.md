# `xcc` `pre` Types

This section contains standardized definitions and terms for the basic data types used in our `xcc` project.

---

## API

| Section                         |
| ------------------------------- |
| [Setup](#setup)                 |
| [Concepts](#concepts)           |
| [Types](#types)                 |
| [Type Concepts](#type-concepts) |

---

- ## Setup

  > Download the project from [github repo](https://github.com/xeerx/xcc) then rename the _src_ folder to _xcc_ then copy the _xcc_ folder to your project directory, That's it !

  - #### Include

    ```cpp
    #include "xcc/pre/types.h"
    ```

  - #### Namespaces

    ```cpp
    namespace xcc;          // The main namespace
    namespace xcc::conc;    // The concepts namespace
    ```

  ***

- ## Concepts

  - #### Same AS

    | Concept                          | Condition              |
    | -------------------------------- | ---------------------- |
    | `xcc::conc::same_as<A, ...>`     | IF `A` IS `...`        |
    | `xcc::conc::same_as_any<A, ...>` | IF `A` IS ANY OF `...` |

  - #### Child OF

    | Concept                           | Condition                       |
    | --------------------------------- | ------------------------------- |
    | `xcc::conc::child_of<A, ...>`     | IF `A` IS CHILD OF `...`        |
    | `xcc::conc::child_of_any<A, ...>` | IF `A` IS CHILD OF ANY OF `...` |

  ***

- ## Types

  - #### Characters

    | Type            | Using      |
    | --------------- | ---------- |
    | `xcc::t_wchar`  | `wchar_t`  |
    | `xcc::t_char`   | `char`     |
    | `xcc::t_char`   | `char8_t`  |
    | `xcc::t_char8`  | `char8_t`  |
    | `xcc::t_char16` | `char16_t` |
    | `xcc::t_char32` | `char32_t` |

    ***

  - #### Unsigned-Integers

    | Type            | Using            |
    | --------------- | ---------------- |
    | `xcc::t_uint8`  | `unsigned char`  |
    | `xcc::t_uint16` | `unsigned short` |
    | `xcc::t_uint32` | `unsigned int`   |
    | `xcc::t_uint64` | `unsigned long`  |

    ***

  - #### Signed-Integers

    | Type           | Using          |
    | -------------- | -------------- |
    | `xcc::t_int8`  | `signed char`  |
    | `xcc::t_int16` | `signed short` |
    | `xcc::t_int32` | `signed int`   |
    | `xcc::t_int64` | `signed long`  |

    ***

  - #### Floating-Point

    | Type             | Using           |
    | ---------------- | --------------- |
    | `xcc::t_float`   | `float`         |
    | `xcc::t_float32` | `xcc::t_float`  |
    | `xcc::t_double`  | `double`        |
    | `xcc::t_float64` | `xcc::t_double` |

    ***

  - #### Booleans

    | Type          | Using  |
    | ------------- | ------ |
    | `xcc::t_bool` | `bool` |

    ***

  - #### Common Types

    | Type           | Using              |
    | -------------- | ------------------ |
    | `xcc::t_size`  | `std::size_t`      |
    | `xcc::t_pdif`  | `std::ptrdiff_t`   |
    | `xcc::t_align` | `std::align_val_t` |

  ***

- ## Type Concepts

  | Concept                | Condition                                                  |
  | ---------------------- | ---------------------------------------------------------- |
  | `xcc::conc::chars<T>`  | IF `T` IS ANY OF [`Characters`](#characters)               |
  | `xcc::conc::uints<T>`  | IF `T` IS ANY OF [`Unsigned-Integers`](#unsigned-integers) |
  | `xcc::conc::sints<T>`  | IF `T` IS ANY OF [`Signed-Integers`](#signed-integers)     |
  | `xcc::conc::floats<T>` | IF `T` IS ANY OF [`Floating-Point`](#floating-point)       |
  | `xcc::conc::bools<T>`  | IF `T` IS ANY OF [`Booleans`](#booleans)                   |
  | `xcc::conc::ints<T>`   | IF `T` IS `xcc::conc::uints<T>` OR `xcc::conc::sints<T>`   |

---

## Related

- **[`xcc` `pre` `env`](env.md)**

- **[`xcc` `pre`](readme.md)**

- **[`xcc`](../../readme.md)**
