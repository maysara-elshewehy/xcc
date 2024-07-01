/* ┏FILE─INFO━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */
    /**
     * @file        src/debug/bencmp.h
     *
     * @brief       Mechanism to create and run useful benchmark
     *
     * @author      Maysara Elshewehy (maysara.elshewehy@gmail.com)
     *
     * @version     1.0.0
     *
     * @date        2023-05-23
     *
     * @copyright   Copyright (c) 2023 - xeerx
     *
     * @see         docs/debug/bencmp.md
    */
/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─SETUP━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #ifndef XCC_H_DEBUG_BENCH
        #define XCC_H_DEBUG_BENCH
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌VERSION───────────────────────────────────────────────────────────────────────────┐ */
        #define XCC_H_DEBUG_BENCH_MAJ                   1
        #define XCC_H_DEBUG_BENCH_MIN                   0
        #define XCC_H_DEBUG_BENCH_PAT                   0
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌HEADERS───────────────────────────────────────────────────────────────────────────┐ */
        #include "../pre/env.h"                         // ↭ X++ Environment
        #include "../pre/types.h"                       // ↭ X++ Types
        #include <iostream>                             // ↭ C++ std::cout ..
        #include <iomanip>                              // ↭ C++ std::cout_tools ..
        #include <vector>                               // ↭ C++ std::vector
        #include <thread>                               // ↭ C++ std::thread
        #include <atomic>                               // ↭ C++ std::atomic_signal_fence ..
        #include <functional>                           // ↭ C++ std::ref
        #include <chrono>                               // ↭ C++ std::chrono ..
        #include <cmath>                                // ↭ C++ std::round
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌REQUIREMENTS──────────────────────────────────────────────────────────────────────┐ */
        // -
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏CODE━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

     /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::debug::details
        {
            // : Helper for xcc::debug::DoNotOptimize function
            // - credit : https://github.com/google/benchmark/blob/main/include/benchmark/benchmark.h
            XCC_ENV_ATTR_INLINE
            void UseCharPointer(char const volatile*)   noexcept
            { }
        }


        namespace xcc::debug
        {
            // : Force the compiler to flush pending writes to global memory. Acts as an effective read/write barrier
            // - credit : https://github.com/google/benchmark/blob/main/include/benchmark/benchmark.h
            XCC_ENV_ATTR_INLINE
            void ClobberMemory  ()                      noexcept
            {
                std::atomic_signal_fence(std::memory_order_acq_rel);
            }

            #if XCC_ENV_HAS_ASSEMBLY

            // : This function can be used to prevent a value or expression from being optimized away by the compiler
            // - credit : https://github.com/google/benchmark/blob/main/include/benchmark/benchmark.h
            template <class T_TYPE>
            XCC_ENV_ATTR_INLINE
            void DoNotOptimize  (T_TYPE const& value)   noexcept
            {
                asm volatile("" : : "r,m"(value) : "memory");
            }

            // : This function can be used to prevent a value or expression from being optimized away by the compiler
            // - credit : https://github.com/google/benchmark/blob/main/include/benchmark/benchmark.h
            template <class T_TYPE>
            XCC_ENV_ATTR_INLINE
            void DoNotOptimize  (T_TYPE& value)         noexcept
            {
                #if defined(__clang__)
                    asm volatile("" : "+r,m"(value) : : "memory");
                #else
                    asm volatile("" : "+m,r"(value) : : "memory");
                #endif
            }

            #elif defined(_MSC_VER)

            // : This function can be used to prevent a value or expression from being optimized away by the compiler
            // - credit : https://github.com/google/benchmark/blob/main/include/benchmark/benchmark.h
            template <class T_TYPE>
            XCC_ENV_ATTR_INLINE
            void DoNotOptimize  (T_TYPE const& value)   noexcept
            {
                details::UseCharPointer(&reinterpret_cast<char const volatile&>(value));
                _ReadWriteBarrier();
            }

            #else

            // : This function can be used to prevent a value or expression from being optimized away by the compiler
            // - credit : https://github.com/google/benchmark/blob/main/include/benchmark/benchmark.h
            template <class T_TYPE>
            XCC_ENV_ATTR_INLINE
            void DoNotOptimize  (T_TYPE const& value)   noexcept
            {
                details::UseCharPointer(&reinterpret_cast<char const volatile&>(value));
            }

            #endif

        }

        namespace xcc::debug::details
        {
            // : Helper for xcc::debug::details::print function (Position of the context)
            enum PRINT_IT_POS   { LEFT, CENTER, RIGHT };

            // : Helper function for printing the results
            void PRINT_IT       ( std::string str, PRINT_IT_POS pos = LEFT, size_t len = 80, std::string beg = "", char fill = ' ', std::string end = "")
            {
                // - beg
                std::cout << beg;

                // - str
                {
                    size_t req_len = str.length() + beg.length() + end.length() + (beg.length() || end.length() ? 1 : 0);

                    size_t spaces = 0;

                    if(req_len < len)
                    {
                        if(pos == CENTER) spaces = ( len - req_len ) / 2;
                        else spaces = len - req_len;
                    }

                    if ( spaces > 0 && pos != LEFT)
                    {
                        if(pos == CENTER)
                        {
                            auto half_req_len = req_len / 2;
                            if((half_req_len + half_req_len) < req_len)
                            {
                                std::cout << std::string( spaces + 1, fill );
                            }
                            else
                            {
                                std::cout << std::string( spaces, fill );
                            }
                        }
                        else
                        {
                            std::cout << std::string( spaces, fill );
                        }
                    }
                    std::cout << str;
                    if ( spaces > 0 && pos != RIGHT)
                    {
                        std::cout << std::string( spaces, fill );
                    }
                }

                // - end
                std::cout << end;
            }

            // : Print Progress Bar
            void PRINT_BAR(t_size _val, t_size _max XCC_ENV_ATTR_MAYBE_UNUSED, t_size _len = 57, t_char _char = '+')
            {
                _val = _val % _len;

                // -
                std::cout << '|';
                for (t_size i = 0; i < _len; ++i)
                {
                    if (i < _val) std::cout << '-';
                    else if (i == _val) std::cout << _char;
                    else std::cout << "-";
                }

                std::cout << '|';
                std::cout << "\r";
                std::cout.flush();
            }
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ RESULT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::debug::bench
        {
            // : The result structure of xcc::debug::bench::Manager
            struct Result
            {
                // : The ratio of the time spent performing this node compared to the total time of all nodes
                t_size              M_ratio         {0};

                // : Average time spent per operation in nanoseconds
                t_size              M_average       {0};

                // : Total time spent in nanoseconds
                t_size              M_total         {0};

                // : Average time spent per operation in nanoseconds
                const t_char*       M_name          {""};

                // : Empty constructor
                constexpr Result                    ()                                                          noexcept
                : M_ratio { 0  } , M_average { 0  } , M_name { "" }
                { }

                // : Assignment constructor
                constexpr Result                    (const t_size& _r, const t_size& _a , const t_char* _n)     noexcept
                : M_ratio { _r } , M_average { _a } , M_name { _n }
                { }

                // : Copy constructor
                constexpr Result                    (const Result&)                                             noexcept = default;

                // : Move constructor
                constexpr Result                    (Result&&)                                                  noexcept = default;

                // : Copy operator
                constexpr Result& operator=         (const Result&)                                             noexcept = default;

                // : Move operator
                constexpr Result& operator=         (Result&&)                                                  noexcept = default;
            };


            // : The results container of xcc::debug::bench::Result
            using Results = std::vector<Result>;

            // : Print result
            static void Print_Result(const Result& _item)
            {
                details::PRINT_IT(_item.M_name                                       , details::LEFT  , 30, "| ", ' ', "");
                details::PRINT_IT(std::to_string(_item.M_average)                    , details::LEFT  , 18, "| ", ' ', "");
                details::PRINT_IT(std::string(std::to_string(_item.M_ratio) + "%")   , details::LEFT  , 12, "| ", ' ', "");
                details::PRINT_IT(" | \n"                                            , details::LEFT  ,  1,   "", ' ', "");
            }

            // : Print result separator
            static void Print_Result_Sep()
            {
                details::PRINT_IT(""         , details::LEFT  , 30, "+ ", '-', "");
                details::PRINT_IT(""         , details::LEFT  , 18, "+ ", '-', "");
                details::PRINT_IT(""         , details::LEFT  , 12, "+ ", '-', "");
                details::PRINT_IT(" + \n"    , details::LEFT  ,  1,   "", '-', "");
            }

            // : Print result titles
            static void Print_Result_Items()
            {
                details::PRINT_IT("NODE"     , details::LEFT  , 30, "| ", ' ', "");
                details::PRINT_IT("TIME (ns)", details::LEFT  , 18, "| ", ' ', "");
                details::PRINT_IT("RATIO"    , details::LEFT  , 12, "| ", ' ', "");
                details::PRINT_IT(" | \n"    , details::LEFT  ,  1,   "", ' ', "");
                Print_Result_Sep();
            }

            // : Print result Title
            static void Print_Result_Title    (const std::string& _name)
            {
                details::PRINT_IT(""        , details::CENTER, 60, "+", '-', "+"); details::PRINT_IT("\n"    , details::LEFT  ,  1,   "", ' ', "");
                details::PRINT_IT(_name     , details::CENTER, 60, "+", ' ', "+"); details::PRINT_IT("\n"    , details::LEFT  ,  1,   "", ' ', "");
                details::PRINT_IT(""        , details::CENTER, 60, "+", '-', "+"); details::PRINT_IT("\n"    , details::LEFT  ,  1,   "", ' ', "");
            }

        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ NODE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::debug::bench
        {
            // : The node of bench (structural-macros)
            // - For more information take a look at : docs/debug/structural-macros.md
            class Node
            {
                public :

                // : Name of the node
                virtual const t_char*   name    ()                                              const noexcept = 0;

                // : Body of the node
                virtual void            body    (t_size&)                                       const noexcept = 0;
            };
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CTRL ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::debug::bench
        {
            // : The node controller of bench (structural-macros)
            // - For more information take a look at : docs/debug/structural-macros.md
            class Manager
            {
                public :

                // : Data
                const t_char*               M_name;
                const t_size                M_iterations;
                const t_size                M_threads;
                const t_size                M_cycles;
                const t_size                M_times;
                std::vector<Node*>          M_nodes;

                // : Assignment constructor
                Manager (const t_char* _n, const t_size& _i, const t_size& _t, const t_size& _c, const t_size& _N) noexcept
                : M_name { _n }, M_iterations { _i }, M_threads { _t }, M_cycles { _c }, M_times { _N }
                { }

                // : Thread function
                static void H_loop_for_I_and_store_total_time(Manager& _obj, Results& _res)
                {
                    // - result
                    std::vector<t_size> _timers (_obj.M_nodes.size(), 0);

                    // - core
                    for(t_size _I = 0; _I < _obj.M_iterations; ++_I)
                    {
                        for(t_size _N = 0; _N < _obj.M_nodes.size(); _N++)
                        {
                            // - run
                            _obj.M_nodes[_N]->body(_timers[_N]);

                            // - record
                            _res[_N].M_total += static_cast<t_size>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count()) - _timers[_N];
                        }
                    }

                    // - pass to thread results : get average of total time
                    for(t_size _N = 0; _N < _obj.M_nodes.size(); _N++)
                    {
                        _res[_N].M_total /= _obj.M_iterations;
                    }
                }

                // : Run benchmark
                Results Run (const t_bool& _print = true)
                {
                    // - Print benchmark form
                    if(_print)
                    {
                        // - title
                        Print_Result_Title(M_name);

                        // - items
                        Print_Result_Items();
                    }

                    // - results
                    Results _results (M_nodes.size(), Result());

                    // - counter
                    t_size _counter   { 0 };
                    t_size _max_count { M_times * (M_cycles * M_threads) };

                    // - update counter
                    details::PRINT_BAR(0, _max_count);

                    // - for times result
                    std::vector<Results>    _times_results (M_times, Results(M_nodes.size(), Result()));

                    // - for times
                    for(t_size _Z = 0; _Z < M_times; ++_Z)
                    {
                        // - for cycles result
                        std::vector<Results>    _cycles_results (M_cycles, Results(M_nodes.size(), Result()));

                        // - for cycles
                        for(t_size _Y = 0; _Y < M_cycles; ++_Y)
                        {
                            // - for threads itself
                            std::vector<std::thread>        _threads;

                            // - for threads result
                            std::vector<Results>    _threads_results (M_threads, Results(M_nodes.size(), Result()));

                            // - launch the threads
                            for(t_size _X = 0; _X < M_threads; ++_X)
                            {
                                _threads.push_back(std::thread(H_loop_for_I_and_store_total_time, std::ref(*this), std::ref(_threads_results[_X])));
                            }

                            // - wait for threads
                            for(t_size _X = 0; _X < M_threads; ++_X)
                            {
                                _threads[_X].join();

                                // - update counter
                                details::PRINT_BAR(++_counter, _max_count);
                            }

                            // - pass to cycle results
                            for(t_size _N = 0; _N < M_nodes.size(); _N++)
                            {
                                // - save total
                                t_size _total { 0 };

                                // - calc total
                                for(auto& _R : _threads_results) _total += _R[_N].M_total;

                                // - pass
                                _cycles_results[_Y][_N].M_total = _total / M_threads;
                            }

                            // - update counter
                            details::PRINT_BAR(++_counter, _max_count);
                        }

                        // - pass to times results
                        for(t_size _N = 0; _N < M_nodes.size(); _N++)
                        {
                            // - save total
                            t_size _total { 0 };

                            // - calc total
                            for(auto& _R : _cycles_results) _total += _R[_N].M_total;

                            // - pass
                            _times_results[_Z][_N].M_total = _total / M_cycles;
                        }

                        // - update counter
                        details::PRINT_BAR(++_counter, _max_count);
                    }

                    // - filter the times result
                    for(t_size _Z = 0; _Z < M_times; ++_Z)
                    {
                        // - pass to times results
                        for(t_size _N = 0; _N < M_nodes.size(); _N++)
                        {
                            // - save total
                            t_size _total { 0 };

                            // - calc total
                            for(auto& _R : _times_results) _total += _R[_N].M_total;

                            // - pass
                            _results[_N].M_total = _total / M_times;
                        }
                    }

                    // - total time for ratio
                    t_double _tmp_total { 0 }; for(auto _N : _results) _tmp_total += t_double(_N.M_total);
                    t_size   _total = t_size( std::ceil(_tmp_total * 100.0) / 100.0 );

                    // - calc ratio and pass to printer
                    for(t_size _N = 0; _N < M_nodes.size(); _N++)
                    {
                        _results[_N].M_name    = M_nodes[_N]->name();
                        _results[_N].M_average = t_size( std::round(t_double(_results[_N].M_total) * 100.0) / 100.0 );
                        _results[_N].M_ratio   = t_size(_results[_N].M_average * 100 / _total);

                        if(_print)
                        {
                            // - cleanup the progress bar
                            // std::cout << "\r";

                            Print_Result(_results[_N]);
                        }
                    }

                    // - print form end
                    if(_print) Print_Result_Sep();

                    // - return results
                    return _results;
                }
            };
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CREATORES ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::debug::details
        {
            // : The node creators of bench (structural-macros)
            // - For more information take a look at : docs/debug/structural-macros.md

            // : Helpers for Structural-Macros
            #define CCX_MAKE_BENCH_SM_OBJ(c,n) c##_##n
            #define CCX_MAKE_BENCH_SM_TAG(c,n) c##_##n##_node

            // Create a new node
            #define XCC_MAKE_BENCH_NODE(c, n)                                               \
                                                                                            \
            class CCX_MAKE_BENCH_SM_OBJ(c,n) : public xcc::debug::bench::Node               \
            {                                                                               \
                public :                                                                    \
                                                                                            \
                const xcc::t_char*  name () const noexcept { return XCC_MAKE_STR_VAL(n); }  \
                void                body (xcc::t_size&) const noexcept override;            \
                CCX_MAKE_BENCH_SM_OBJ(c,n)() { c.M_nodes.push_back(this); };                \
            };                                                                              \
                                                                                            \
            CCX_MAKE_BENCH_SM_OBJ(c,n) CCX_MAKE_BENCH_SM_TAG(c,n);                          \
                                                                                            \
            void  CCX_MAKE_BENCH_SM_OBJ(c,n)::body (xcc::t_size& _time) const noexcept

            // Create a new controller
            #define XCC_MAKE_BENCH_CTRL(n,i,t,c,T) xcc::debug::bench::Manager n(XCC_MAKE_STR_VAL(n), i, t, c, T);


            // :
            #define XCC_BENCH_NODE_BEG _time = static_cast<xcc::t_size>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
            #define XCC_BENCH_NODE_END return;
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─END━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #endif
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */