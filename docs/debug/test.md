# `xcc` `debug` Test

This file can be considered as a mini framework to facilitate the process of testing codes through header files only to support all different environments and thus a new and wonderful experience for the testing process.

In xeerx, we benefited greatly from this project, as we dispensed with the Google Test library, which was difficult to deal with, especially when running tests on different environments, which complicates the process very much (I hated my life because of unit tests and performance measurements), so it was great to write code that works with the click of a button Nowhere with the same expected performance and look.

> **This is an individual project, so I always accept tips and contributions ❤️**

> This framework will be rebuilt after the formatting library and debug library are finished 📌

---

- #### Examples

  ```cpp
  // Make a new controller
  XCC_MAKE_TEST_CTRL(TITLE)
  ```

  ```cpp
  // Make a new test with auto registration (#1)
  XCC_MAKE_TEST_NODE(TITLE, A)
  {
    XCC_MAKE_TEST_MSG("Dummy output");
    XCC_MAKE_TEST_VERIFY(true);
  }
  ```

  ```cpp
  // ...
  XCC_MAKE_TEST_NODE(TITLE, B)
  {
    XCC_MAKE_TEST_VERIFY(false);
  }
  ```

  ```cpp
  // Run the registered tests
  int main() { TITLE.Run(); }
  ```

  > Output :

  ```bash
  +-----------------------------------TITLE/A-----------------------------------+
  +                                                                             +
  +     Dummy output                                                            +
  +---> DONE                                                                    +
  +                                                                             +
  +-----------------------------------------------------------------------------+

  +-----------------------------------TITLE/B-----------------------------------+
  +                                                                             +
  +     Expression : false                                                      +
  +     Location   : /home/xeerx/Projects/xcc/dist/test/test.cpp#31       +
  +---> FAIL                                                                    +
  +                                                                             +
  +-----------------------------------------------------------------------------+
  ```

---

## API

| Section                 |
| ----------------------- |
| [Setup](#setup)         |
| [Macros](#macros)       |
| [Functions](#functions) |

---

- ## Setup

  > Download the project from [github repo](https://github.com/xeerx/xcc) then rename the _src_ folder to _xcc_ then copy the _xcc_ folder to your project directory, That's it !

  - #### Include

    ```cpp
    #include "xcc/debug/test.h"
    ```

  ***

- ## Macros

  | Macro                                                          | Definition                                        |
  | -------------------------------------------------------------- | ------------------------------------------------- |
  | `XCC_MAKE_TEST_NODE(ctrl, name)`                               | Create a new node                                 |
  | `XCC_MAKE_TEST_NODE(name, iterations, threads, cycles, times)` | Create a new node controller                      |
  | `XCC_MAKE_TEST_VERIFY(expr)`                                   | Check if the expression is true, otherwise report |
  | `XCC_DEBUG_TEST_MSG(msg)`                                      | Print a message inside the test form              |

  ***

## Tests

> See : [dist/test/test.cpp](../../dist/test/test.cpp)

---

## Related

- **[`xcc` `debug` `Structural Macros`](structural-macros.md)**

- **[`xcc` `debug` `bench`](bench.md)**

- **[`xcc` `debug`](readme.md)**

- **[`xcc`](../../readme.md)**
