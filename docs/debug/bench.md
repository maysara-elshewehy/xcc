# `xcc` `debug` Benchmark

This file can be considered as a mini framework to facilitate the process of measure-time of codes through header files only to support all different environments and thus a new and wonderful experience for the benchmark process.

In xeerx, we benefited greatly from this project, as we dispensed with the Google Benchmark library, which was difficult to deal with, especially when running benchmarks on different environments, which complicates the process very much (I hated my life because of unit tests and performance measurements), so it was great to write code that works with the click of a button Nowhere with the same expected performance and look.

> **This is an individual project, so I always accept tips and contributions ❤️**

> This framework will be rebuilt after the formatting library and debug library are finished 📌

---

- #### Examples

  ```cpp
  // Make a new controller
  // - This controller will run the benchmark(TITLE) for 10'000 iteration per 5 threads per cycle per time
  // - So : (10'000 * 5) * 10 * 15 = 7'500'000 iteration for each node
  XCC_MAKE_BENCH_CTRL(TITLE, 10'000, 5, 10, 15)
  ```

  ```cpp
  // Make a new node and link it to the TITLE controller
  {

        XCC_BENCH_NODE_BEG

        auto a = std::to_string(_rand);
        auto b = std::to_string(_rand);
        auto c = std::to_string(_rand);
        auto d = std::to_string(_rand);
        auto e = std::to_string(_rand);
        auto f = std::to_string(_rand);
        auto x = a + b + c + d + e + f;

        xcc::debug::DoNotOptimize(x);

        XCC_BENCH_NODE_END
    }
  XCC_MAKE_BENCH_NODE(TITLE, A)
  {
      // - somecode before starting the benchmark
      const auto _rand = std::rand();

      // - start timer
      XCC_BENCH_NODE_BEG

      // - somecode
      auto a = std::to_string(_rand);
      auto b = std::to_string(_rand);
      auto c = std::to_string(_rand);
      auto d = std::to_string(_rand);
      auto e = std::to_string(_rand);
      auto f = std::to_string(_rand);
      auto x = a + b + c + d + e + f;

      // - to avoid compiler optimization
      xcc::debug::DoNotOptimize(x);

      // - stop timer
      XCC_BENCH_NODE_END
  }
  ```

  ```cpp
  // ...
  XCC_MAKE_BENCH_NODE(TITLE, B)
  {
      const auto _rand = std::rand();

      XCC_BENCH_NODE_BEG

      auto a = std::to_string(_rand);
      auto b = std::to_string(_rand);
      auto c = std::to_string(_rand);
      auto x = a + b + c;

      xcc::debug::DoNotOptimize(x);

      XCC_BENCH_NODE_END
  }
  ```

  ```cpp
  // ...
  XCC_MAKE_BENCH_NODE(TITLE, C)
  {
      const auto _rand = std::rand();

      XCC_BENCH_NODE_BEG

      auto a = std::to_string(_rand);
      auto b = std::to_string(_rand);
      auto c = std::to_string(_rand);
      auto x = a + b + c;

      xcc::debug::DoNotOptimize(x);

      XCC_BENCH_NODE_END
  }
  ```

  ```cpp
  // Run the registered benchmarks
  int main() { TITLE.Run(); }
  ```

  > Output :

  ```bash
  +---------------------------------------------------------+
  +                          TITLE                          +
  +---------------------------------------------------------+
  | NODE                       | TIME (ns)      | RATIO     |
  + ---------------------------+ ---------------+ --------- +
  | A                          | 365            | 48%       | # takes a long  time (48% of total time)
  | B                          | 195            | 25%       | # takes a short time (25% of total time)
  | C                          | 192            | 25%       | # takes a short time (25% of total time)
  + ---------------------------+ ---------------+ --------- +
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
    #include "xcc/debug/bench.h"
    ```

  ***

- ## Macros

  | Macro                                                           | Definition                                         |
  | --------------------------------------------------------------- | -------------------------------------------------- |
  | `XCC_MAKE_BENCH_NODE(ctrl, name)`                               | Create a new node                                  |
  | `XCC_MAKE_BENCH_CTRL(name, iterations, threads, cycles, times)` | Create a new node controller                       |
  | `XCC_BENCH_NODE_BEG`                                            | Start the benchmark node timer                     |
  | `XCC_BENCH_NODE_BEG`                                            | End the benchmark node timer and return the result |

  ***

- ## Functions

  ```cpp
  // - This function can be used to prevent a value or expression from being optimized away by the compiler
  template <class T_TYPE>
  void xcc::debug::DoNotOptimize(T_TYPE const& value) noexcept
  ```

  ```cpp
  // - This function can be used to prevent a value or expression from being optimized away by the compiler
  template <class T_TYPE>
  void xcc::debug::DoNotOptimize(T_TYPE& value)       noexcept
  ```

  ```cpp
  // - Force the compiler to flush pending writes to global memory. Acts as an effective read/write barrier
  void xcc::debug::ClobberMemory()                    noexcept
  ```

  ***

## Tests

> See : [dist/test/bench.cpp](../../dist/test/bench.cpp)

---

## Related

- **[`xcc` `debug` `Structural Macros`](structural-macros.md)**

- **[`xcc` `debug` `Test`](test.md)**

- **[`xcc` `debug`](readme.md)**

- **[`xcc`](../../readme.md)**
