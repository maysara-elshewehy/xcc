# `xcc` `pre` Environment

This section is designed to be used solely through predefined macros to access platform information and features (language, compiler, standard library, underlying operating system, architecture, and more) in a functional, easy-to-understand and remember form.

- ### Sample of accessible information

  > All key information can be accessed using Preprocessor operations, which makes it possible to access and produce output similar to the following :

  ```C++
  ┌C++─────────────────────────────────────────────┐
    'full '     : 202002
    'major'     : 20
  └────────────────────────────────────────────────┘

  ┌Compiler────────────────────────────────────────┐
    'name'      : "GCC"
    'major'     : 11
    'minor'     : 3
    'patch'     : 0
  └────────────────────────────────────────────────┘

  ┌Standard─Library────────────────────────────────┐
    'name'      : "GNU"
    'major'     : 2022
    'minor'     : 4
    'patch'     : 21
  └────────────────────────────────────────────────┘

  ┌Platform────────────────────────────────────────┐
    'name'      : "Linux"
    'base'      : "Posix"
  └────────────────────────────────────────────────┘

  ┌Architecture────────────────────────────────────┐
    'name'      : "x86_64"
    'base'      : "X86"
    'bits'      : 64
    'endian'    : "Little"
  └────────────────────────────────────────────────┘
  ```

  > This output Run on : _Ubuntu 22_ with _GCC 11_ and _C++ 20_, see [`dist/test/pre.cpp`](../../dist/test/pre.cpp)

---

## API

| Section                               |
| ------------------------------------- |
| [Setup](#setup)                       |
| [C++ Version](#c-version)             |
| [Has Conditions](#has-conditions)     |
| [Compiler](#compiler)                 |
| [Standard Library](#standard-library) |
| [Platform](#platform)                 |
| [Architecture](#architecture)         |
| [Attributes](#attributes)             |
| [Others](#others)                     |

---

- ## Setup

  > Download the project from [github repo](https://github.com/xeerx/xcc) then rename the _src_ folder to _xcc_ then copy the _xcc_ folder to your project directory, That's it !

  - #### Include

    ```cpp
    #include "xcc/pre/env.h"
    ```

  ***

- ## C++ Version

  | Macro             | Description                          | Return                        |
  | ----------------- | ------------------------------------ | ----------------------------- |
  | `XCC_ENV_CPP_VER` | C++ version provided by the compiler | `__cplusplus` or `_MSVC_LANG` |
  | `XCC_ENV_CPP_MAJ` | C++ version provided by the xcc      | `20` or `23` or ..            |

  ***

- ## Has Conditions

  | Macro                    | Description                               | Return                          |
  | ------------------------ | ----------------------------------------- | ------------------------------- |
  | `XCC_ENV_HAS_ATTR(x)`    | check if the env has a : x attribute      | `__has_cpp_attribute(x)` or `0` |
  | `XCC_ENV_HAS_FEATURE(x)` | check if the env has a : x feature        | `__has_feature(x)` or `0`       |
  | `XCC_ENV_HAS_INCLUDE(x)` | check if the env has a : x include        | `__has_include(x)` or `0`       |
  | `XCC_ENV_HAS_BUILTIN(x)` | check if the env has a : x builtin        | `__has_builtin(x)` or `0`       |
  | `XCC_ENV_HAS_ASM`        | check if the env has a : assembly support | `1` or `0`                      |

  ***

- ## Compiler

  - ### General Macros

    > All of the following macros will always be defined

    | Macro              | Definition                | Return                  |
    | ------------------ | ------------------------- | ----------------------- |
    | `XCC_ENV_COMP_STR` | Name of compiler          | `const char *`          |
    | `XCC_ENV_COMP_MAJ` | Major version of compiler | depends on the compiler |
    | `XCC_ENV_COMP_MIN` | Minor version of compiler | depends on the compiler |
    | `XCC_ENV_COMP_PAT` | Patch version of compiler | depends on the compiler |

    ***

  - ### ID Macros

    > Only one macro of the following will be defined, depending on the compiler used

    | Macro                           | Value of `XCC_ENV_COMP_STR` macro       |
    | ------------------------------- | --------------------------------------- |
    | `XCC_ENV_COMP_TAG_CUDA`         | `"NVIDIA CUDA C++"`                     |
    | `XCC_ENV_COMP_TAG_GCC_XML`      | `"GCC XML"`                             |
    | `XCC_ENV_COMP_TAG_CRAY`         | `"Cray C"`                              |
    | `XCC_ENV_COMP_TAG_COMO`         | `"Comeau C++"`                          |
    | `XCC_ENV_COMP_TAG_PATHCC`       | `"PathScale EKOPath"`                   |
    | `XCC_ENV_COMP_TAG_ICX`          | `"Intel ICX"`                           |
    | `XCC_ENV_COMP_TAG_ICC`          | `"Intel ICC"`                           |
    | `XCC_ENV_COMP_TAG_CLANG`        | `"Clang"`                               |
    | `XCC_ENV_COMP_TAG_DMC`          | `"Digital Mars"`                        |
    | `XCC_ENV_COMP_TAG_DCC`          | `"Diab C/C++"`                          |
    | `XCC_ENV_COMP_TAG_PGI`          | `"Portland Group C/C++"`                |
    | `XCC_ENV_COMP_TAG_GCC`          | `"GCC"`                                 |
    | `XCC_ENV_COMP_TAG_KCC`          | `"Kai C++"`                             |
    | `XCC_ENV_COMP_TAG_SGI`          | `"SGI MIPSpro C++"`                     |
    | `XCC_ENV_COMP_TAG_COMPAQ`       | `"Compaq C/C++"`                        |
    | `XCC_ENV_COMP_TAG_GHS`          | `"Green Hill C/C++"`                    |
    | `XCC_ENV_COMP_TAG_CODEGEARC`    | `"CodeGear"`                            |
    | `XCC_ENV_COMP_TAG_BORLANDC`     | `"Borland C++"`                         |
    | `XCC_ENV_COMP_TAG_MWERKS`       | `"Metrowerks CodeWarrior"`              |
    | `XCC_ENV_COMP_TAG_SUNPRO`       | `"Oracle Solaris Studio"`               |
    | `XCC_ENV_COMP_TAG_HPACC`        | `"HP aC++"`                             |
    | `XCC_ENV_COMP_TAG_MRC`          | `"MPW C++"`                             |
    | `XCC_ENV_COMP_TAG_IBMXL_ZOS`    | `"IBM z/OS XL C/C++"`                   |
    | `XCC_ENV_COMP_TAG_IBMXL_CLANG`  | `"IBM XL C/C++ (Clang-based versions)"` |
    | `XCC_ENV_COMP_TAG_IBMXL_LEGACY` | `"IBM XL C/C++ (legacy versions)"`      |
    | `XCC_ENV_COMP_TAG_MSVC`         | `"Microsoft Visual C++"`                |
    | `XCC_ENV_COMP_TAG_UNKNOWN`      | `"Unknown"`                             |

  ***

- ## Standard Library

  - ### General Macros

    > All of the following macros will always be defined

    | Macro              | Definition                        | Return                          |
    | ------------------ | --------------------------------- | ------------------------------- |
    | `XCC_ENV_SLIB_STR` | Name of standard library          | `const char *`                  |
    | `XCC_ENV_SLIB_MAJ` | Major version of standard library | depends on the standard library |
    | `XCC_ENV_SLIB_MIN` | Minor version of standard library | depends on the standard library |
    | `XCC_ENV_SLIB_PAT` | Patch version of standard library | depends on the standard library |

    ***

  - ### ID Macros

    > Only one macro of the following will be defined, depending on the standard library used

    | Macro                      | Value of `XCC_ENV_SLIB_STR` macro |
    | -------------------------- | --------------------------------- |
    | `XCC_ENV_SLIB_TAG_GNU`     | `"GNU"`                           |
    | `XCC_ENV_SLIB_TAG_MSVC`    | `"MSVC"`                          |
    | `XCC_ENV_SLIB_TAG_LLVM`    | `"LLVM"`                          |
    | `XCC_ENV_SLIB_TAG_UNKNOWN` | `"Unknown"`                       |

  ***

- ## Platform

  - ### General Macros

    > All of the following macros will always be defined

    | Macro                   | Definition            | Return         |
    | ----------------------- | --------------------- | -------------- |
    | `XCC_ENV_PLAT_STR`      | Name of platform      | `const char *` |
    | `XCC_ENV_PLAT_BASE_STR` | Name of platform base | `const char *` |

    ***

  - ### ID Macros

    > Only one macro of the following will be defined, depending on the platform used

    | Macro                          | Value of `XCC_ENV_PLAT_STR` macro |
    | ------------------------------ | --------------------------------- |
    | `XCC_ENV_PLAT_TAG_NACL`        | `"Native Client"`                 |
    | `XCC_ENV_PLAT_TAG_ANDROID`     | `"Android"`                       |
    | `XCC_ENV_PLAT_TAG_IOS`         | `"IOS"`                           |
    | `XCC_ENV_PLAT_TAG_MACCATALYST` | `"Mac Catalyst"`                  |
    | `XCC_ENV_PLAT_TAG_MAC`         | `"Mac"`                           |
    | `XCC_ENV_PLAT_TAG_MACINTOSH`   | `"Macintosh"`                     |
    | `XCC_ENV_PLAT_TAG_LINUX`       | `"Linux"`                         |
    | `XCC_ENV_PLAT_TAG_WIN64`       | `"Windows 64-bit"`                |
    | `XCC_ENV_PLAT_TAG_WIN32`       | `"Windows 32-bit"`                |
    | `XCC_ENV_PLAT_TAG_FREEBSD`     | `"FreeBSD"`                       |
    | `XCC_ENV_PLAT_TAG_NETBSD`      | `"NetBSD"`                        |
    | `XCC_ENV_PLAT_TAG_OPENBSD`     | `"OpenBSD"`                       |
    | `XCC_ENV_PLAT_TAG_DRAGONFLY`   | `"DragonFly"`                     |
    | `XCC_ENV_PLAT_TAG_SUN`         | `"Sun Solaris"`                   |
    | `XCC_ENV_PLAT_TAG_SGI`         | `"SGI Irix"`                      |
    | `XCC_ENV_PLAT_TAG_HPUX`        | `"HP-UX"`                         |
    | `XCC_ENV_PLAT_TAG_CYGWIN`      | `"Cygwin"`                        |
    | `XCC_ENV_PLAT_TAG_HAIKU`       | `"Haiku"`                         |
    | `XCC_ENV_PLAT_TAG_BEOS`        | `"BeOS"`                          |
    | `XCC_ENV_PLAT_TAG_IBMZOS`      | `"IBM z/OS"`                      |
    | `XCC_ENV_PLAT_TAG_AIX`         | `"IBM AIX"`                       |
    | `XCC_ENV_PLAT_TAG_AMIGAOS`     | `"AmigaOS"`                       |
    | `XCC_ENV_PLAT_TAG_QNX`         | `"QNX"`                           |
    | `XCC_ENV_PLAT_TAG_VXWORKS`     | `"vxWorks"`                       |
    | `XCC_ENV_PLAT_TAG_SYMBIAN32`   | `"Symbian"`                       |
    | `XCC_ENV_PLAT_TAG_CRAYC`       | `"Cray"`                          |
    | `XCC_ENV_PLAT_TAG_VMS`         | `"VMS"`                           |
    | `XCC_ENV_PLAT_TAG_CLOUDABI`    | `"Nuxi CloudABI"`                 |
    | `XCC_ENV_PLAT_TAG_WASM`        | `"Web assembly"`                  |
    | `XCC_ENV_PLAT_TAG_UNKNOWN`     | `"Unknown"`                       |

    ***

  - ### Base ID Macros

    > Only one macro of the following will be defined, depending on the platform used

    | Macro                           | Value of `XCC_ENV_PLAT_BASE_STR` macro |
    | ------------------------------- | -------------------------------------- |
    | `XCC_ENV_PLAT_BASE_TAG_APPLE`   | `"Apple"`                              |
    | `XCC_ENV_PLAT_BASE_TAG_BSD`     | `"BSD"`                                |
    | `XCC_ENV_PLAT_BASE_TAG_WINDOWS` | `"Windows"`                            |
    | `XCC_ENV_PLAT_BASE_TAG_POSIX`   | `"Posix"`                              |
    | `XCC_ENV_PLAT_BASE_TAG_UNKNOWN` | `"Unknown"`                            |

  ***

- ## Architecture

  - ### General Macros

    > All of the following macros will always be defined

    | Macro                   | Definition                | Return                                       |
    | ----------------------- | ------------------------- | -------------------------------------------- |
    | `XCC_ENV_ARCH_STR`      | Name of architecture      | `const char *`                               |
    | `XCC_ENV_ARCH_BASE_STR` | Name of architecture base | `const char *`                               |
    | `XCC_ENV_ARCH_END`      | Endian of architecture    | `0` (non) or `1` (little) or `2` (big) or .. |
    | `XCC_ENV_ARCH_BIT`      | Size of architecture      | `0` or `32` or `64` or ..                    |

    ***

  - ### ID Macros

    > Only one macro of the following will be defined, depending on the architecture used

    | Macro                       | Value of `XCC_ENV_ARCH_STR` macro |
    | --------------------------- | --------------------------------- |
    | `XCC_ENV_ARCH_TAG_X86_64`   | `"x86_64"`                        |
    | `XCC_ENV_ARCH_TAG_X86_32`   | `"X86_32"`                        |
    | `XCC_ENV_ARCH_TAG_ARM_64`   | `"ARM_64"`                        |
    | `XCC_ENV_ARCH_TAG_ARM_32`   | `"ARM_32"`                        |
    | `XCC_ENV_ARCH_TAG_MIPS_64`  | `"MIPS_64"`                       |
    | `XCC_ENV_ARCH_TAG_MIPS_32`  | `"MIPS_32"`                       |
    | `XCC_ENV_ARCH_TAG_LOONG_32` | `"LOONG_32"`                      |
    | `XCC_ENV_ARCH_TAG_LOONG_64` | `"LOONG_64"`                      |
    | `XCC_ENV_ARCH_TAG_S390_64`  | `"s390_64"`                       |
    | `XCC_ENV_ARCH_TAG_S390_31`  | `"s390_31"`                       |
    | `XCC_ENV_ARCH_TAG_PPC_64`   | `"PPC64"`                         |
    | `XCC_ENV_ARCH_TAG_RISCV_64` | `"RISCV"`                         |
    | `XCC_ENV_ARCH_TAG_UNKNOWN`  | `"Unknown"`                       |

    ***

  - ### Base ID Macros

    > Only one macro of the following will be defined, depending on the architecture used

    | Macro                           | Value of `XCC_ENV_ARCH_BASE_STR` macro |
    | ------------------------------- | -------------------------------------- |
    | `XCC_ENV_ARCH_BASE_TAG_X86`     | `"X86"`                                |
    | `XCC_ENV_ARCH_BASE_TAG_ARM`     | `"ARM"`                                |
    | `XCC_ENV_ARCH_BASE_TAG_MIPS`    | `"MIPS"`                               |
    | `XCC_ENV_ARCH_BASE_TAG_LOONG`   | `"LOONG"`                              |
    | `XCC_ENV_ARCH_BASE_TAG_S390`    | `"S390"`                               |
    | `XCC_ENV_ARCH_BASE_TAG_PPC64`   | `"PPC64"`                              |
    | `XCC_ENV_ARCH_BASE_TAG_ASM`     | `"ASM"`                                |
    | `XCC_ENV_ARCH_BASE_TAG_RISCV`   | `"RISCV"`                              |
    | `XCC_ENV_ARCH_BASE_TAG_UNKNOWN` | `"Unknown"`                            |

  ***

- ## Attributes

  - ### Standard Attributes

    > All of the following macros will always be defined

    | Macro                             | Refers To                |
    | --------------------------------- | ------------------------ |
    | `XCC_ENV_ATTR_ASSUME(x)`          | `[[assume(x)]]`          |
    | `XCC_ENV_ATTR_CARRIES_DEPENDENCY` | `[[carries_dependency]]` |
    | `XCC_ENV_ATTR_DEPRECATED(x)`      | `[[deprecated(x)]]`      |
    | `XCC_ENV_ATTR_FALLTHROUGH`        | `[[fallthrough]]`        |
    | `XCC_ENV_ATTR_LIKELY`             | `[[likely]]`             |
    | `XCC_ENV_ATTR_UNLIKELY`           | `[[unlikely]]`           |
    | `XCC_ENV_ATTR_MAYBE_UNUSED`       | `[[maybe_unused]]`       |
    | `XCC_ENV_ATTR_NODISCARD`          | `[[nodiscard]]`          |
    | `XCC_ENV_ATTR_NORETURN`           | `[[noreturn]]`           |

  ***

  - ### Compiler Attributes

    > All of the following macros will always be defined

    | Macro                   | Refers To         |
    | ----------------------- | ----------------- |
    | `XCC_ENV_ATTR_INLINE`   | `force inline`    |
    | `XCC_ENV_ATTR_NOINLINE` | `force no-inline` |
    | `XCC_ENV_ATTR_VISIBLE`  | `make it visible` |
    | `XCC_ENV_ATTR_HIDDEN`   | `make it hiddin`  |

  ***

- ## Others

  - ### Default Values

    > All of the following macros will always be defined

    | Macro                    | Definition                  | Return                     |
    | ------------------------ | --------------------------- | -------------------------- |
    | `XCC_ENV_DEF_ALIGN_SIZE` | Get the default align value | depends on the environment |

    ***

  - ### Makers

    > All of the following macros will always be defined

    | Macro                   | Definition                                               | Return         |
    | ----------------------- | -------------------------------------------------------- | -------------- |
    | `XCC_MAKE_STR_VAL(...)` | Convert the macro arguments to string using preprocessor | `const char *` |

---

## Related

- **[`xcc` `pre` `types`](types.md)**

- **[`xcc` `pre`](readme.md)**

- **[`xcc`](../../readme.md)**
