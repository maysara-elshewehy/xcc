/* ┏BENCH─SETUP━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌HEADERS───────────────────────────────────────────────────────────────────────────┐ */
        #include "../../src/debug/bench.h"              // ↭ ...
        #include "../../src/types/allocator.h"          // ↭ ...
        #include <memory>                               // ↭ ...
        #include <random>                               // ↭ ...
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏BENCH─IMPL━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    #define RAND(max,min) min + ( std::rand() % ( max - min + 1 ) )

    XCC_MAKE_BENCH_CTRL(allocators, 1'000'00, 5, 5, 5)

    XCC_MAKE_BENCH_NODE(allocators, xcc_version)
    {
        xcc::t_size  _size = static_cast<xcc::t_size>(RAND(1000,1));

        XCC_BENCH_NODE_BEG

        // - creation
        xcc::allocator<xcc::t_size> _alloc;

        // - filling
        xcc::t_size* _area = _alloc.allocate(_size);
        for (xcc::t_size _ind = 0; _ind < _size; ++_ind)
        { _area[_ind] = _ind; }

        // - deallocate
        _alloc.deallocate(_area, _size);

        xcc::debug::DoNotOptimize(_alloc);
        xcc::debug::DoNotOptimize(_area);

        XCC_BENCH_NODE_END
    }

    XCC_MAKE_BENCH_NODE(allocators, std_version)
    {
        xcc::t_size  _size = static_cast<xcc::t_size>(RAND(1000,1));

        XCC_BENCH_NODE_BEG

        // - creation
        std::allocator<xcc::t_size> _alloc;

        // - filling
        xcc::t_size* _area = _alloc.allocate(_size);
        for (xcc::t_size _ind = 0; _ind < _size; ++_ind)
        { _area[_ind] = _ind; }

        // - deallocate
        _alloc.deallocate(_area, _size);

        xcc::debug::DoNotOptimize(_alloc);
        xcc::debug::DoNotOptimize(_area);

        XCC_BENCH_NODE_END
    }

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏BENCH─RUN━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    int main() { allocators.Run(); }

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


/* The output in my case is :

+---------------------------------------------------------+
+                          allocators                         +
+---------------------------------------------------------+
| NODE                       | TIME (ns)      | RATIO     |
+ ---------------------------+ ---------------+ --------- +
| xcc_version                | 38             | 50%       |
| std_version                | 38             | 50%       |
+ ---------------------------+ ---------------+ --------- +

*/