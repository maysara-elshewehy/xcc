/* ┏TEST─SETUP━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌HEADERS───────────────────────────────────────────────────────────────────────────┐ */
        #include "../../src/debug/bench.h"                  // ↭ ...
        #include <iostream>                                 // ↭ C++ Stream
        #include <string>                                   // ↭ C++ String
        #include <random>                                   // ↭ C++ Random
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏TEST─IMPL━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ ━━━━━━━━━━━━━━━━━┓ */

    XCC_MAKE_BENCH_CTRL(TITLE, 10'000, 5, 10, 15)

    XCC_MAKE_BENCH_NODE(TITLE, A)
    {
        const auto _rand = std::rand();

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

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏TEST─RUN━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    int main() { TITLE.Run(); }

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */