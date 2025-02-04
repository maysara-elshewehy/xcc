/* ┏BENCH─SETUP━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌HEADERS───────────────────────────────────────────────────────────────────────────┐ */
        #include "../../src/debug/bench.h"              // ↭ ...
        #include "../../src/types/array.h"              // ↭ ...
        #include <array>                                // ↭ ...
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏BENCH─IMPL━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    XCC_MAKE_BENCH_CTRL(arrays, 1'000'00, 5, 5, 5)

    XCC_MAKE_BENCH_NODE(arrays, xcc_version)
    {
        const auto _rand = std::rand();

        XCC_BENCH_NODE_BEG

        // - creation
        xcc::array<int, 999> _arr;

        // - filling
        for(auto& _elm : _arr)
        _elm = _rand;

        XCC_BENCH_NODE_END
    }

    XCC_MAKE_BENCH_NODE(arrays, std_version)
    {
        const auto _rand = std::rand();

        XCC_BENCH_NODE_BEG

        // - creation
        std::array<int, 999> _arr;

        // - filling
        for(auto& _elm : _arr)
        _elm = _rand;

        XCC_BENCH_NODE_END
    }

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏BENCH─RUN━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    int main() { arrays.Run(); }

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


/* The output in my case is :

+---------------------------------------------------------+
+                          arrays                         +
+---------------------------------------------------------+
| NODE                       | TIME (ns)      | RATIO     |
+ ---------------------------+ ---------------+ --------- +
| xcc_version                | 38             | 50%       |
| std_version                | 38             | 50%       |
+ ---------------------------+ ---------------+ --------- +

*/