/* ┏TEST─SETUP━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌HEADERS───────────────────────────────────────────────────────────────────────────┐ */
        #include "../../src/debug/test.h"               // ↭ ...
        #include "../../src/types/array.h"              // ↭ ...
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏TEST─IMPL━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    #define TITLE xcc_type_array

    XCC_MAKE_TEST_CTRL(TITLE)

    XCC_MAKE_TEST_NODE(TITLE, devZone)
    {
        // : zero size
        {
            // - creation
            xcc::array<xcc::t_size, 0>   _arr;

            // - filling
            xcc::t_size                         _ind = 0;
            for(auto& _elm : _arr)
            _elm = _ind++;

            // - testing
            for(_ind = 0; _ind < _arr.size(); ++_ind)
            { XCC_MAKE_TEST_VERIFY(_arr[_ind]    == _ind); }
            XCC_MAKE_TEST_VERIFY(_ind == 0);
            XCC_MAKE_TEST_VERIFY(_arr.size()     == 0);
            XCC_MAKE_TEST_VERIFY(_arr.max_size() == 0);
            XCC_MAKE_TEST_VERIFY(_arr.empty()    == 1);
        }

        // : non-zero size
        {
            // - creation
            xcc::array<xcc::t_size, 999> _arr;

            // - filling
            xcc::t_size                         _ind = 0;
            for(auto& _elm : _arr)
            _elm = _ind++;

            // - testing
            for(_ind = 0; _ind < _arr.size(); ++_ind)
            { XCC_MAKE_TEST_VERIFY(_arr[_ind]    == _ind); }
            XCC_MAKE_TEST_VERIFY(_ind >  0);
            XCC_MAKE_TEST_VERIFY(_arr.size()     == _ind);
            XCC_MAKE_TEST_VERIFY(_arr.max_size() == _ind);
            XCC_MAKE_TEST_VERIFY(_arr.empty()    == 0);
        }

        // : to_array
        {
            // :
            {
                // : lvalue
                {
                    xcc::t_size _iar[] = { 0,1,2,3,4,5 };
                    auto        _arr = xcc::to_array(_iar);
                    xcc::t_size _ind = 0;
                    for(auto   _elm : _arr)
                    { XCC_MAKE_TEST_VERIFY(_elm == _iar[_ind++] ); }
                }

                // : rvalue
                {
                    auto        _arr = xcc::to_array({ xcc::t_size(0), xcc::t_size(1), xcc::t_size(2), xcc::t_size(3), xcc::t_size(4), xcc::t_size(5) });
                    xcc::t_size _ind = 0;
                    for(auto   _elm : _arr)
                    { XCC_MAKE_TEST_VERIFY(_elm ==_ind++ ); }
                }
            }

            // : constexpr
            {
                // : lvalue
                {
                    constexpr xcc::t_size _iar[] = { 0,1,2,3,4,5 };
                    constexpr auto _arr = xcc::to_array(_iar);
                    xcc::t_size _ind = 0;
                    for(const auto   _elm : _arr)
                    { XCC_MAKE_TEST_VERIFY(_elm == _iar[_ind++] ); }
                }

                // : rvalue
                {
                    constexpr auto _arr = xcc::to_array({ xcc::t_size(0), xcc::t_size(1), xcc::t_size(2), xcc::t_size(3), xcc::t_size(4), xcc::t_size(5) });
                    xcc::t_size _ind = 0;
                    for(const auto   _elm : _arr)
                    { XCC_MAKE_TEST_VERIFY(_elm ==_ind++ ); }
                }
            }
        }

        // : more ...
        {
            constexpr xcc::array _arr1 = { 0,1,2,3,4,5 };
            constexpr xcc::array _arr2 = _arr1;

            for(xcc::t_size i = 0; i < _arr1.size(); i++)
                { XCC_MAKE_TEST_VERIFY(_arr1[i] ==_arr2[i]); }
        }
    }

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏TEST─RUN━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    int main() { TITLE.Run(); }

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */