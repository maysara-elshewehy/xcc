/* ┏TEST─SETUP━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌HEADERS───────────────────────────────────────────────────────────────────────────┐ */
        #include "../../src/pre/env.h"                  // ↭ ...
        #include "../../src/debug/test.h"               // ↭ ...
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏TEST─IMPL━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    XCC_MAKE_TEST_CTRL(xcc_pre)

    XCC_MAKE_TEST_NODE(xcc_pre, output)
    {
        // - C++
        {
            const auto ver = XCC_ENV_CPP_VER;      XCC_MAKE_TEST_VERIFY(ver);
            const auto maj = XCC_ENV_CPP_MAJ;      XCC_MAKE_TEST_VERIFY(maj);

            XCC_MAKE_TEST_MSG("C++");
            XCC_MAKE_TEST_MSG(std::string("  full  version   : ") + std::to_string(ver));
            XCC_MAKE_TEST_MSG(std::string("  major version   : ") + std::to_string(maj));
            XCC_MAKE_TEST_MSG("");
        }

        // - Compiler
        {
            const auto str = XCC_ENV_COMP_STR;      XCC_MAKE_TEST_VERIFY(str);
            const auto maj = XCC_ENV_COMP_MAJ;      XCC_MAKE_TEST_VERIFY(maj);
            const auto min = XCC_ENV_COMP_MIN;
            const auto pat = XCC_ENV_COMP_PAT;

            XCC_MAKE_TEST_MSG("Compiler");
            XCC_MAKE_TEST_MSG(std::string("  name            : ") + std::string(str));
            XCC_MAKE_TEST_MSG(std::string("  major version   : ") + std::to_string(maj));
            XCC_MAKE_TEST_MSG(std::string("  minor version   : ") + std::to_string(min));
            XCC_MAKE_TEST_MSG(std::string("  patch version   : ") + std::to_string(pat));
            XCC_MAKE_TEST_MSG("");
        }

        // - Standard Library
        {
            const auto str = XCC_ENV_SLIB_STR;      XCC_MAKE_TEST_VERIFY(str);
            const auto maj = XCC_ENV_SLIB_MAJ;      XCC_MAKE_TEST_VERIFY(maj);
            const auto min = XCC_ENV_SLIB_MIN;
            const auto pat = XCC_ENV_SLIB_PAT;

            XCC_MAKE_TEST_MSG("Standard Library");
            XCC_MAKE_TEST_MSG(std::string("  name            : ") + std::string(str));
            XCC_MAKE_TEST_MSG(std::string("  major version   : ") + std::to_string(maj));
            XCC_MAKE_TEST_MSG(std::string("  minor version   : ") + std::to_string(min));
            XCC_MAKE_TEST_MSG(std::string("  patch version   : ") + std::to_string(pat));
            XCC_MAKE_TEST_MSG("");
        }

        // - Platform
        {
            const auto str = XCC_ENV_PLAT_STR;      XCC_MAKE_TEST_VERIFY(str);
            const auto bas = XCC_ENV_PLAT_BASE_STR; XCC_MAKE_TEST_VERIFY(bas);

            XCC_MAKE_TEST_MSG("Platform");
            XCC_MAKE_TEST_MSG(std::string("  name            : ") + std::string(str));
            XCC_MAKE_TEST_MSG(std::string("  base            : ") + std::string(bas));
            XCC_MAKE_TEST_MSG("");
        }

        // - Architecture
        {
            const auto str = XCC_ENV_ARCH_STR;      XCC_MAKE_TEST_VERIFY(str);
            const auto bas = XCC_ENV_ARCH_BASE_STR; XCC_MAKE_TEST_VERIFY(bas);
            const auto bit = XCC_ENV_ARCH_BIT;      XCC_MAKE_TEST_VERIFY(bit);
            const auto end = XCC_ENV_ARCH_END;      XCC_MAKE_TEST_VERIFY(end);

            XCC_MAKE_TEST_MSG("Architecture");
            XCC_MAKE_TEST_MSG(std::string("  name            : ") + std::string(str));
            XCC_MAKE_TEST_MSG(std::string("  base            : ") + std::string(bas));
            XCC_MAKE_TEST_MSG(std::string("  bits            : ") + std::to_string(bit));
            XCC_MAKE_TEST_MSG(std::string("  endian          : ") + (end ? std::string("Little") : std::string("Big")));
            XCC_MAKE_TEST_MSG("");
        }
    }

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏TEST─RUN━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    int main() { xcc_pre.Run(); }

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */