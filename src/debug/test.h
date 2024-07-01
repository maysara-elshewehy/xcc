/* ┏FILE─INFO━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */
    /**
     * @file        src/debug/test.h
     *
     * @brief       Mechanism to create and run useful unit tests
     *
     * @author      Maysara Elshewehy (maysara.elshewehy@gmail.com)
     *
     * @version     1.0.0
     *
     * @date        2023-05-23
     *
     * @copyright   Copyright (c) 2023 - xeerx
     *
     * @see         docs/debug/test.md
    */
/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─SETUP━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #ifndef XCC_H_DEBUG_TEST
        #define XCC_H_DEBUG_TEST
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌VERSION───────────────────────────────────────────────────────────────────────────┐ */
        #define XCC_H_DEBUG_TEST_MAJ                    1
        #define XCC_H_DEBUG_TEST_MIN                    0
        #define XCC_H_DEBUG_TEST_PAT                    0
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌HEADERS───────────────────────────────────────────────────────────────────────────┐ */
        #include "../pre/env.h"                         // ↭ X++ Environment
        #include "../pre/types.h"                       // ↭ X++ Types
        #include "bench.h"                              // ↭ X++ Benchmark framework (to avoid rewrites)
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌REQUIREMENTS──────────────────────────────────────────────────────────────────────┐ */
        // -
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏CODE━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

     /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::debug::details
        {

        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ NODE ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::debug::test
        {
            // : The node of test (structural-macros)
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


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ RESULT ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::debug::test
        {
            // : The result structure of xcc::debug::test::Manager
            struct Result
            {
                // : Total time spent in nanoseconds
                t_size              M_status        {0};

                // : Average time spent per operation in nanoseconds
                const t_char*       M_name          {""};

                // : Empty constructor
                constexpr Result                    ()                                                          noexcept
                : M_status { 0  } , M_name { "" }
                { }

                // : Assignment constructor
                constexpr Result                    (const t_size& _s , const t_char* _n)   noexcept
                : M_status { _s } , M_name { _n }
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


            // : The results container of xcc::debug::test::Result
            using Results = std::vector<Result>;

            // : Print result separator
            static void Print_Result_Sep()
            {
                details::PRINT_IT("" , details::LEFT, 80, "+", '-', "+");
                std::cout << "\n";
            }

            // : Print result message
            static void Print_Result_Msg(const std::string& _msg)
            {
                details::PRINT_IT(_msg , details::LEFT, 80, "+", ' ', "+");
                std::cout << "\n";
            }

            // : Print result separator
            static void Print_Result_Line()
            {
                details::PRINT_IT("" , details::LEFT, 80, "+", ' ', "+");
                std::cout << "\n";
            }

            // : Print result
            static void Print_Result(const Result& _item)
            {
                if(_item.M_status == 1)
                Print_Result_Msg(std::string("---> DONE"));
                else
                Print_Result_Msg(std::string("---> FAIL"));

                Print_Result_Line();
                Print_Result_Sep();
            }

            // : Print result Title
            static void Print_Result_Title    (const std::string& _name, const std::string& _node)
            {
                details::PRINT_IT(_name +"/"+_node    , details::CENTER, 80, "+", '-', "+"); details::PRINT_IT("\n"    , details::LEFT  ,  1,   "", ' ', "");
                details::PRINT_IT(""        , details::CENTER, 80, "+", ' ', "+"); details::PRINT_IT("\n"    , details::LEFT  ,  1,   "", ' ', "");
            }
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CTRL ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::debug::test
        {
            // : The node controller of test (structural-macros)
            // - For more information take a look at : docs/debug/structural-macros.md
            class Manager
            {
                public :

                // : Data
                const t_char*               M_name;
                std::vector<Node*>          M_nodes;

                // : Assignment constructor
                Manager (const t_char* _n) noexcept
                : M_name { _n }
                { }

                // : Run test
                Results Run (const t_bool& _print = true)
                {
                    // - results
                    Results _results (M_nodes.size(), Result());

                    // - core
                    for(t_size _N = 0; _N < M_nodes.size(); _N++)
                    {
                        // - print title
                        if(_print) Print_Result_Title(M_name, M_nodes[_N]->name());

                        // - status
                        t_size _status = 1;

                        // - run
                        M_nodes[_N]->body(_status);

                        _results[_N].M_name = M_nodes[_N]->name();
                        _results[_N].M_status = 1;

                        // -
                        if(_status == 1)
                        {
                            // - print form end
                            if(_print)
                            {
                                Print_Result(_results[_N]);
                                std::cout << "\n";
                            }
                        }
                    }

                    // - return results
                    return _results;
                }
            };
        }

    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */


    /* ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CREATORES ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

        namespace xcc::debug::details
        {
            // : The node creators of test (structural-macros)
            // - For more information take a look at : docs/debug/structural-macros.md

            // : Helpers for Structural-Macros
            #define CCX_MAKE_TEST_SM_OBJ(c,n) c##_##n
            #define CCX_MAKE_TEST_SM_TAG(c,n) c##_##n##_node

            // : Create a new node
            #define XCC_MAKE_TEST_NODE(c, n)                                                \
                                                                                            \
            class CCX_MAKE_TEST_SM_OBJ(c,n) : public xcc::debug::test::Node                 \
            {                                                                               \
                public :                                                                    \
                                                                                            \
                const xcc::t_char*  name () const noexcept { return XCC_MAKE_STR_VAL(n); }  \
                void                body (xcc::t_size&) const noexcept override;            \
                CCX_MAKE_TEST_SM_OBJ(c,n)() { c.M_nodes.push_back(this); };                 \
            };                                                                              \
                                                                                            \
            CCX_MAKE_TEST_SM_OBJ(c,n) CCX_MAKE_TEST_SM_TAG(c,n);                            \
                                                                                            \
            void  CCX_MAKE_TEST_SM_OBJ(c,n)::body (xcc::t_size& _status XCC_ENV_ATTR_MAYBE_UNUSED) const noexcept

            // : Create a new controller
            #define XCC_MAKE_TEST_CTRL(n) xcc::debug::test::Manager n(XCC_MAKE_STR_VAL(n));

            // : Print a new message
            #define XCC_MAKE_TEST_MSG(s)  xcc::debug::test::Print_Result_Msg(std::string("     ") + s);

            // : To verify the test expression
            #define XCC_MAKE_TEST_VERIFY(expr)                                                                              \
            if(!(expr))                                                                                                     \
            {                                                                                                               \
                _status = 0;                                                                                           \
                XCC_MAKE_TEST_MSG(std::string("Expression : ") + XCC_MAKE_STR_VAL(expr));                                   \
                XCC_MAKE_TEST_MSG(std::string("Location   : ") + std::string(__FILE__) + "#" + std::to_string(__LINE__));   \
                xcc::debug::test::Print_Result_Msg(std::string("---> FAIL"));                                               \
                xcc::debug::test::Print_Result_Line();                                                                      \
                xcc::debug::test::Print_Result_Sep();                                                                       \
                return;                                                                                                     \
            }
        }
    /* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─END━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #endif
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */