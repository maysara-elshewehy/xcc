/* ┏FILE─INFO━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */
    /**
     * @file        src/pre/env.h
     *
     * @brief       Standardize basic info macros and facilitate access to it
     *
     * @author      Maysara Elshewehy (maysara.elshewehy@gmail.com)
     *
     * @version     0.0.2
     *
     * @date        2018-05-27
     *
     * @copyright   Copyright (c) 2018 - xeerx
     *
     * @see         docs/pre/env.md
    */
/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─SETUP━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #ifndef XCC_H_PRE_ENV
        #define XCC_H_PRE_ENV

        #define XCC_H_PRE_ENV_MAJ                       1
        #define XCC_H_PRE_ENV_MIN                       0
        #define XCC_H_PRE_ENV_PAT                       0
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌HEADERS───────────────────────────────────────────────────────────────────────────┐ */
        // -
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌REQUIREMENTS──────────────────────────────────────────────────────────────────────┐ */
        // -
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏CODE━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌C++───────────────────────────────────────────────────────────────────────────────┐ */

        // : What version of C++ did this environment use? (provided by the compiler)
        #if defined(_MSVC_LANG)
            #define XCC_ENV_CPP_VER                     _MSVC_LANG
        #elif defined(__cplusplus)
            #define XCC_ENV_CPP_VER                     __cplusplus
        #else
            #error It seems we cant access this information on your environment
            #error Please let us know by sending us a description of the problem along
            #error With information about the operating system and compiler used
        #endif


        // : What major of C++ did this environment use?
        #if   XCC_ENV_CPP_VER >= 202300L
            #define XCC_ENV_CPP_MAJ                     23
        #elif XCC_ENV_CPP_VER >= 202000L
            #define XCC_ENV_CPP_MAJ                     20
        #else
            #error It looks like you are using an older version of C++
            #error If you want to use xcc correctly
            #error Please upgrade your C++ version to version 202000L or later
        #endif

    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌HAS───────────────────────────────────────────────────────────────────────────────┐ */

        // : Does this environment has : attribute x ?
        #ifdef __has_cpp_attribute
            #define XCC_ENV_HAS_ATTR(x)                 __has_cpp_attribute(x)
        #else
            #define XCC_ENV_HAS_ATTR(x)                 0
        #endif


        // : Does this environment has : feature x ?
        #ifdef __has_feature
            #define XCC_ENV_HAS_FEATURE(x)              __has_feature(x)
        #else
            #define XCC_ENV_HAS_FEATURE(x)              0
        #endif


        // : Does this environment has : include x ?
        #ifdef __has_include
            #define XCC_ENV_HAS_INCLUDE(x)              __has_include(x)
        #else
            #define XCC_ENV_HAS_INCLUDE(x)              0
        #endif


        // : Does this environment has a : builtin ?
        #ifdef __has_builtin
            #define XCC_ENV_HAS_BUILTIN(x)              __has_builtin(x)
        #else
            #define XCC_ENV_HAS_BUILTIN(x)              0
        #endif


        // : Does this environment has a : assembly supported ?
        #if (!defined(__GNUC__) && !defined(__clang__)) || defined(__pnacl__) || defined(__EMSCRIPTEN__)
            #define XCC_ENV_HAS_ASSEMBLY                0
        #else
            #define XCC_ENV_HAS_ASSEMBLY                1
        #endif

    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌COMPILER──────────────────────────────────────────────────────────────────────────┐ */

        // - NVIDIA CUDA C++ compiler for GPU
        #if defined __CUDACC__
            #define XCC_ENV_COMP_TAG_CUDA
            #define XCC_ENV_COMP_STR                    "NVIDIA CUDA C++"
            #define XCC_ENV_COMP_MAJ                    __CUDACC_VER_MAJOR__
            #define XCC_ENV_COMP_MIN                    __CUDACC_VER_MINOR__
            #define XCC_ENV_COMP_PAT                    __CUDACC_VER_BUILD__


        // - GCC-XML emulates other compilers
        #elif defined(__GCCXML__)
            #define XCC_ENV_COMP_TAG_GCC_XML
            #define XCC_ENV_COMP_STR                    "GCC XML"
            #define XCC_ENV_COMP_MAJ                    __GCCXML_GNUC__
            #define XCC_ENV_COMP_MIN                    __GCCXML_GNUC_MINOR__
            #define XCC_ENV_COMP_PAT                    __GCCXML_GNUC_PATCHLEVEL__


        // - EDG based Cray
        #elif defined(_CRAYC)
            #define XCC_ENV_COMP_TAG_CRAY
            #define XCC_ENV_COMP_STR                    "Cray C"
            #define XCC_ENV_COMP_MAJ                    _RELEASE_MINOR / 1000
            #define XCC_ENV_COMP_MIN                    (_RELEASE_MINOR / 100)  % 10
            #define XCC_ENV_COMP_PAT                    _RELEASE_MINOR % 1000


        // - Comeau C++
        #elif defined (__COMO__)
            #define XCC_ENV_COMP_TAG_COMO
            #define XCC_ENV_COMP_STR                    "Comeau C++"
            #define XCC_ENV_COMP_MAJ                    __COMO_VERSION__ / 100
            #define XCC_ENV_COMP_MIN                    __COMO_VERSION__ % 100
            #define XCC_ENV_COMP_PAT                    0


        // - PathScale EKOPath
        #elif defined(__PATHCC__)
            #define XCC_ENV_COMP_TAG_PATHCC
            #define XCC_ENV_COMP_STR                    "PathScale EKOPath"
            #define XCC_ENV_COMP_MAJ                    __PATHCC__
            #define XCC_ENV_COMP_MIN                    __PATHCC_MINOR__
            #define XCC_ENV_COMP_PAT                    __PATHCC_PATCHLEVEL__


        // - Intel ICX
        #elif defined(__INTEL_LLVM_COMPILER)
            #define XCC_ENV_COMP_TAG_ICX
            #define XCC_ENV_COMP_STR                    "Intel ICX"
            #define XCC_ENV_COMP_MAJ                    (__INTEL_LLVM_COMPILER / 10000)
            #define XCC_ENV_COMP_MIN                    (__INTEL_LLVM_COMPILER / 100) % 100
            #define XCC_ENV_COMP_PAT                    __INTEL_LLVM_COMPILER % 100


        // - Intel
        #elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
            #define XCC_ENV_COMP_TAG_ICC
            #define XCC_ENV_COMP_STR                    "Intel ICC"
            #define XCC_ENV_COMP_MAJ                    (__INTEL_COMPILER_BUILD_DATE / 10000)
            #define XCC_ENV_COMP_MIN                    (__INTEL_COMPILER_BUILD_DATE / 100) % 100
            #define XCC_ENV_COMP_PAT                    __INTEL_COMPILER_BUILD_DATE % 100


        // - Clang C++
        #elif defined (__clang__) && !defined(__ibmxl__) && !defined(__CODEGEARC__)
            #define XCC_ENV_COMP_TAG_CLANG
            #define XCC_ENV_COMP_STR                    "Clang"
            #define XCC_ENV_COMP_MAJ                    __clang_major__
            #define XCC_ENV_COMP_MIN                    __clang_minor__
            #define XCC_ENV_COMP_PAT                    __clang_patchlevel__


        // - Digital Mars C++
        #elif defined (__DMC__)
            #define XCC_ENV_COMP_TAG_DMC
            #define XCC_ENV_COMP_STR                    "Digital Mars"
            #define XCC_ENV_COMP_MAJ                    (__DMC__ >> 8) & 0xF
            #define XCC_ENV_COMP_MIN                    (__DMC__ >> 4) & 0xF
            #define XCC_ENV_COMP_PAT                    __DMC__       & 0xF


        // - Wind River Diab C++
        #elif defined (__DCC__)
            #define XCC_ENV_COMP_TAG_DCC
            #define XCC_ENV_COMP_STR                    "Diab C/C++"
            #define XCC_ENV_COMP_MAJ                    (__VERSION_NUMBER__ / 1000)
            #define XCC_ENV_COMP_MIN                    (__VERSION_NUMBER__ / 100) % 10
            #define XCC_ENV_COMP_PAT                    __VERSION_NUMBER__ % 100


        // - Portland Group C/C++
        #elif defined(__PGI)
            #define XCC_ENV_COMP_TAG_PGI
            #define XCC_ENV_COMP_STR                    "Portland Group C/C++"
            #define XCC_ENV_COMP_MAJ                    __PGIC__
            #define XCC_ENV_COMP_MIN                    __PGIC_MINOR__
            #define XCC_ENV_COMP_PAT                    __PGIC_PATCHLEVEL__


        // - GNU C++
        #elif defined(__GNUC__) && !defined(__ibmxl__)
            #define XCC_ENV_COMP_TAG_GCC
            #define XCC_ENV_COMP_STR                    "GCC"
            #define XCC_ENV_COMP_MAJ                    __GNUC__
            #define XCC_ENV_COMP_MIN                    __GNUC_MINOR__
            #define XCC_ENV_COMP_PAT                    __GNUC_PATCHLEVEL__


        // - Kai C++
        #elif defined (__KCC)
            #define XCC_ENV_COMP_TAG_KCC
            #define XCC_ENV_COMP_STR                    "Kai C++"
            #define XCC_ENV_COMP_MAJ                    (__KCC_VERSION >> 12) & 0xF
            #define XCC_ENV_COMP_MIN                    (__KCC_VERSION >> 8)  & 0xF
            #define XCC_ENV_COMP_PAT                    (((__KCC_VERSION >> 4)  & 0xF) * 10) + (__KCC_VERSION & 0xF)


        // - SGI MIPSpro C++
        #elif defined (__sgi)
            #define XCC_ENV_COMP_TAG_SGI
            #define XCC_ENV_COMP_STR                    "SGI MIPSpro C++"
            #define XCC_ENV_COMP_MAJ                    (_COMPILER_VERSION / 100)
            #define XCC_ENV_COMP_MIN                    (_COMPILER_VERSION / 10) % 10
            #define XCC_ENV_COMP_PAT                    _COMPILER_VERSION % 10


        // - Compaq Tru64 Unix cxx
        #elif defined (__DECCXX)
            #define XCC_ENV_COMP_TAG_COMPAQ
            #define XCC_ENV_COMP_STR                    "Compaq C/C++"
            #define XCC_ENV_COMP_MAJ                    __DECC_VER / 10000000
            #define XCC_ENV_COMP_MIN                    (__DECC_VER / 100000) % 100
            #define XCC_ENV_COMP_PAT                    __DECC_VER % 10000


        // - Greenhills C++
        #elif defined (__ghs)
            #define XCC_ENV_COMP_TAG_GHS
            #define XCC_ENV_COMP_STR                    "Green Hill C/C++"
            #define XCC_ENV_COMP_MAJ                    __GHS_VERSION_NUMBER__ / 100
            #define XCC_ENV_COMP_MIN                    (__GHS_VERSION_NUMBER__ / 10) % 10
            #define XCC_ENV_COMP_PAT                    __GHS_VERSION_NUMBER__ % 10


        // - CodeGear
        #elif defined (__CODEGEARC__)
            #define XCC_ENV_COMP_TAG_CODEGEARC
            #define XCC_ENV_COMP_STR                    "CodeGear"
            #define XCC_ENV_COMP_MAJ                    (__CODEGEARC_VERSION__ >> 24) & 0xF
            #define XCC_ENV_COMP_MIN                    ((__CODEGEARC_VERSION__ >> 20) & 0xF * 10) +  ((__CODEGEARC_VERSION__ >> 16) & 0xF)
            #define XCC_ENV_COMP_PAT                    (__CODEGEARC_VERSION__ >> 12) & 0xF


        // - Borland
        #elif defined (__BORLANDC__)
            #define XCC_ENV_COMP_TAG_BORLANDC
            #define XCC_ENV_COMP_STR                    "Borland C++"
            #define XCC_ENV_COMP_MAJ                    (__BORLANDC__ >> 8) & 0xF
            #define XCC_ENV_COMP_MIN                    (__BORLANDC__ >> 4) & 0xF
            #define XCC_ENV_COMP_PAT                    __BORLANDC__       & 0xF


        // - Metrowerks CodeWarrior
        #elif defined (__MWERKS__)
            #define XCC_ENV_COMP_TAG_MWERKS
            #define XCC_ENV_COMP_STR                    "Metrowerks CodeWarrior"
            #define XCC_ENV_COMP_MAJ                    (__MWERKS__ >> 12) & 0xF
            #define XCC_ENV_COMP_MIN                    (__MWERKS__ >> 8)  & 0xF
            #define XCC_ENV_COMP_PAT                    (((__MWERKS__ >> 4)  & 0xF) * 10) + (__MWERKS__ & 0xF)


        // - Sun Workshop Compiler C++
        #elif defined (__SUNPRO_CC)
            #define XCC_ENV_COMP_TAG_SUNPRO
            #define XCC_ENV_COMP_STR                    "Oracle Solaris Studio"
            #define XCC_ENV_COMP_MAJ                    (__SUNPRO_CC >> 12) & 0xF
            #define XCC_ENV_COMP_MIN                    (((__SUNPRO_CC >> 8)  & 0xF) * 10) + ((__SUNPRO_CC >> 4) & 0xF)
            #define XCC_ENV_COMP_PAT                    (  __SUNPRO_CC        & 0xF)


        // - HP aCC
        #elif defined (__HP_aCC)
            #define XCC_ENV_COMP_TAG_HPACC
            #define XCC_ENV_COMP_STR                    "HP aC++"
            #define XCC_ENV_COMP_MAJ                    __HP_aCC / 10000
            #define XCC_ENV_COMP_MIN                    (__HP_aCC / 100) % 100
            #define XCC_ENV_COMP_PAT                    __HP_aCC % 100


        // - MPW MrCpp or SCpp
        #elif defined(__MRC__) || defined(__SC__)
            #define XCC_ENV_COMP_TAG_MRC
            #define XCC_ENV_COMP_STR                    "MPW C++"
            #define XCC_ENV_COMP_MAJ                    (((__MRC__ >> 12) & 0xF) * 10) + ((__MRC__ >> 8) & 0xF)
            #define XCC_ENV_COMP_MIN                    (((__MRC__ >> 4)  & 0xF) * 10) + ( __MRC__       & 0xF)
            #define XCC_ENV_COMP_PAT                    0


        // - IBM z/OS XL C/C++
        #elif defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)
            #define XCC_ENV_COMP_TAG_IBMXL_ZOS
            #define XCC_ENV_COMP_STR                    "IBM z/OS XL C/C++"
            #define XCC_ENV_COMP_MAJ                    (__IBMCPP__ / 1000) %  10
            #define XCC_ENV_COMP_MIN                    (__IBMCPP__ / 10)   % 100
            #define XCC_ENV_COMP_PAT                    __IBMCPP__ % 10


        // - IBM XL C/C++ for Linux (Little Endian)
        #elif defined(__ibmxl__)
            #define XCC_ENV_COMP_TAG_IBMXL_CLANG
            #define XCC_ENV_COMP_STR                    "IBM XL C/C++ (Clang-based versions)"
            #define XCC_ENV_COMP_MAJ                    __ibmxl_version__
            #define XCC_ENV_COMP_MIN                    __ibmxl_release__
            #define XCC_ENV_COMP_PAT                    __ibmxl_modification__


        // - IBM Visual Age or IBM XL C/C++ for Linux (Big Endian)
        #elif defined(__IBMCPP__)
            #define XCC_ENV_COMP_TAG_IBMXL_LEGACY
            #define XCC_ENV_COMP_STR                    "IBM XL C/C++ (legacy versions)"
            #define XCC_ENV_COMP_MAJ                    (((__IBMCPP__ >> 20) & 0xF) * 10) + ((__IBMCPP__ >> 16) & 0xF)
            #define XCC_ENV_COMP_MIN                    (((__IBMCPP__ >> 12) & 0xF) * 10) + ((__IBMCPP__ >>  8) & 0xF)
            #define XCC_ENV_COMP_PAT                    (((__IBMCPP__ >>  4) & 0xF) * 10) + ( __IBMCPP__        & 0xF)


        // - Microsoft Visual C++
        #elif defined (_MSC_VER)
            #define XCC_ENV_COMP_TAG_MSVC
            #define XCC_ENV_COMP_STR                    "Microsoft Visual C++"
            #define XCC_ENV_COMP_MAJ                    (_MSC_VER / 100)
            #define XCC_ENV_COMP_MIN                    (_MSC_VER % 100)
            #define XCC_ENV_COMP_PAT                    _MSC_FULL_VER % 100000


        // - Unknown
        #else
            #define XCC_ENV_COMP_TAG_UNKNOWN
            #define XCC_ENV_COMP_STR                    "Unknown"
            #define XCC_ENV_COMP_MAJ                    0
            #define XCC_ENV_COMP_MIN                    0
            #define XCC_ENV_COMP_PAT                    0
        #endif

    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌STDLIB────────────────────────────────────────────────────────────────────────────┐ */

        // - Requirements
        #if XCC_ENV_HAS_INCLUDE(<version>)
            #include <version>                          // ↭ general predefined version macros
        #endif
        #if XCC_ENV_HAS_INCLUDE(<cstddef>)
            #include <cstddef>                          // ↭ general predefined version macros
        #endif


        // - GNU libstdc++
        #if defined(__GLIBCXX__)
            #define XCC_ENV_SLIB_TAG_GNU
            #define XCC_ENV_SLIB_STR                    "GNU"
            #define XCC_ENV_SLIB_MAJ                    __GLIBCXX__ / 10000
            #define XCC_ENV_SLIB_MIN                    (__GLIBCXX__ / 100) % 100
            #define XCC_ENV_SLIB_PAT                    __GLIBCXX__ % 100


        // - MSVC STL
        #elif defined(_CPPLIB_VER)
            #define XCC_ENV_SLIB_TAG_MSVC
            #define XCC_ENV_SLIB_STR                    "MSVC"
            #define XCC_ENV_SLIB_MAJ                    _MSVC_STL_UPDATE / 100
            #define XCC_ENV_SLIB_MIN                    _MSVC_STL_UPDATE % 100
            #define XCC_ENV_SLIB_PAT                    0


        // - libc++
        #elif defined(_LIBCPP_VERSION)
            #define XCC_ENV_SLIB_TAG_LLVM
            #define XCC_ENV_SLIB_STR                    "LLVM"
            #define XCC_ENV_SLIB_MAJ                    _LIBCPP_VERSION / 1000
            #define XCC_ENV_SLIB_MIN                    0
            #define XCC_ENV_SLIB_PAT                    0


        // - Unknown
        #else
            #define XCC_ENV_SLIB_TAG_UNKNOWN
            #define XCC_ENV_SLIB_STR                    "Unknown"
            #define XCC_ENV_SLIB_MAJ                    0
            #define XCC_ENV_SLIB_MIN                    0
            #define XCC_ENV_SLIB_PAT                    0
        #endif

    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌PLATFORM──────────────────────────────────────────────────────────────────────────┐ */

        // - Native Client
        #if defined(__native_client__)
            #define XCC_ENV_PLAT_TAG_NACL
            #define XCC_ENV_PLAT_STR                    "Native Client"


        // - Android
        #elif defined(__ANDROID__)
            #define XCC_ENV_PLAT_TAG_ANDROID
            #define XCC_ENV_PLAT_STR                    "Android"


        // - MacOS
        #elif defined(__APPLE__)
            #include <TargetConditionals.h>
            #if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
                #define XCC_ENV_PLAT_TAG_IOS
                #define XCC_ENV_PLAT_STR                "IOS"
            #elif defined(TARGET_OS_MACCATALYST) && TARGET_OS_MACCATALYST
                #define XCC_ENV_PLAT_TAG_MACCATALYST
                #define XCC_ENV_PLAT_STR                "Mac Catalyst"
            #else
                #define XCC_ENV_PLAT_TAG_MAC
                #define XCC_ENV_PLAT_STR                "Mac"
            #endif


        // - Macintosh
        #elif defined(macintosh)
            #define XCC_ENV_PLAT_TAG_MACINTOSH
            #define XCC_ENV_PLAT_STR                    "Macintosh"


        // - Linux
        #elif (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__) || defined(__unix__)) && !defined(_CRAYC)
            #define XCC_ENV_PLAT_TAG_LINUX
            #define XCC_ENV_PLAT_STR                    "Linux"


        // - Windows
        #elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__NT__)
            #ifdef _WIN64
                #define XCC_ENV_PLAT_TAG_WIN64
                #define XCC_ENV_PLAT_STR                "Windows 64-bit"
            #else
                #define XCC_ENV_PLAT_TAG_WIN32
                #define XCC_ENV_PLAT_STR                "Windows 32-bit"
            #endif


        // - BSD
        #elif defined(__FreeBSD__)
            #define XCC_ENV_PLAT_TAG_FREEBSD
            #define XCC_ENV_PLAT_STR                    "FreeBSD"
        #elif defined(__NetBSD__)
            #define XCC_ENV_PLAT_TAG_NETBSD
            #define XCC_ENV_PLAT_STR                    "NetBSD"
        #elif defined(__OpenBSD__)
            #define XCC_ENV_PLAT_TAG_OPENBSD
            #define XCC_ENV_PLAT_STR                    "OpenBSD"
        #elif defined(__DragonFly__)
            #define XCC_ENV_PLAT_TAG_DRAGONFLY
            #define XCC_ENV_PLAT_STR                    "DragonFly"


        // - Sun Solaris
        #elif defined(sun) || defined(__sun)
            #define XCC_ENV_PLAT_TAG_SUN
            #define XCC_ENV_PLAT_STR                    "Sun Solaris"


        // - SGI Irix
        #elif defined(__sgi)
            #define XCC_ENV_PLAT_TAG_SGI
            #define XCC_ENV_PLAT_STR                    "SGI Irix"


        // - HP-UX
        #elif defined(__hpux)
            #define XCC_ENV_PLAT_TAG_HPUX
            #define XCC_ENV_PLAT_STR                    "HP-UX"


        // - Cygwin
        #elif defined(__CYGWIN__)
            #define XCC_ENV_PLAT_TAG_CYGWIN
            #define XCC_ENV_PLAT_STR                    "Cygwin"


        // - Haiku
        #elif defined(__HAIKU__)
            #define XCC_ENV_PLAT_TAG_HAIKU
            #define XCC_ENV_PLAT_STR                    "Haiku"


        // - BeOS
        #elif defined(__BEOS__)
            #define XCC_ENV_PLAT_TAG_BEOS
            #define XCC_ENV_PLAT_STR                    "BeOS"


        // - IBM z/OS
        #elif defined(__TOS_MVS__)
            #define XCC_ENV_PLAT_TAG_IBMZOS
            #define XCC_ENV_PLAT_STR                    "IBM z/OS"


        // - IBM AIX
        #elif defined(__IBMCPP__) || defined(_AIX)
            #define XCC_ENV_PLAT_TAG_AIX
            #define XCC_ENV_PLAT_STR                    "IBM AIX"


        // - AmigaOS
        #elif defined(__amigaos__)
            #define XCC_ENV_PLAT_TAG_AMIGAOS
            #define XCC_ENV_PLAT_STR                    "AmigaOS"


        // - QNX
        #elif defined(__QNXNTO__)
            #define XCC_ENV_PLAT_TAG_QNX
            #define XCC_ENV_PLAT_STR                    "QNX"


        // - vxWorks
        #elif defined(__VXWORKS__)
            #define XCC_ENV_PLAT_TAG_VXWORKS
            #define XCC_ENV_PLAT_STR                    "vxWorks"


        // - Symbian
        #elif defined(__SYMBIAN32__)
            #define XCC_ENV_PLAT_TAG_SYMBIAN32
            #define XCC_ENV_PLAT_STR                    "Symbian"


        // - Cray
        #elif defined(_CRAYC)
            #define XCC_ENV_PLAT_TAG_CRAYC
            #define XCC_ENV_PLAT_STR                    "Cray"


        // - VMS
        #elif defined(__VMS)
            #define XCC_ENV_PLAT_TAG_VMS
            #define XCC_ENV_PLAT_STR                    "VMS"


        // - Nuxi CloudABI
        #elif defined(__CloudABI__)
            #define XCC_ENV_PLAT_TAG_CLOUDABI
            #define XCC_ENV_PLAT_STR                    "Nuxi CloudABI"


        // - Web assembly
        #elif defined(__wasm__)
            #define XCC_ENV_PLAT_TAG_WASM
            #define XCC_ENV_PLAT_STR                    "Web assembly"


        // - Unknown
        #else
            #define XCC_ENV_PLAT_TAG_UNKNOWN
            #define XCC_ENV_PLAT_STR                    "Unknown"
        #endif

    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌PLATFORM─FAMILY───────────────────────────────────────────────────────────────────┐ */

        // - Apple
        #if defined(XCC_ENV_PLAT_TAG_IOS) || defined(XCC_ENV_PLAT_TAG_MACCATALYST) || defined(XCC_ENV_PLAT_TAG_MAC)  || defined(XCC_ENV_PLAT_TAG_MACINTOSH)
            #define XCC_ENV_PLAT_BASE_TAG_APPLE
        #endif


        // - BSD
        #if defined(XCC_ENV_PLAT_TAG_FREEBSD) || defined(XCC_ENV_PLAT_TAG_NETBSD) || defined(XCC_ENV_PLAT_TAG_OPENBSD)
            #define XCC_ENV_PLAT_BASE_TAG_BSD
        #endif


        // - Windows
        #if defined(XCC_ENV_PLAT_TAG_WIN32) || defined(XCC_ENV_PLAT_TAG_WIN64)
            #define XCC_ENV_PLAT_BASE_TAG_WINDOWS
        #endif


        // - Posix
        #if XCC_ENV_HAS_INCLUDE(<unistd.h>)
            #include <unistd.h>
            #if defined(_POSIX_VERSION)
                #define XCC_ENV_PLAT_BASE_TAG_POSIX
            #endif
        #endif


        // - Unknown
        #if !defined(XCC_ENV_PLAT_BASE_TAG_APPLE) && !defined(XCC_ENV_PLAT_BASE_TAG_WINDOWS) && !defined(XCC_ENV_PLAT_BASE_TAG_BSD) && !defined(XCC_ENV_PLAT_BASE_TAG_POSIX)
            #define XCC_ENV_PLAT_BASE_TAG_UNKNOWN
        #endif


        // - Base Tag
        #if defined(XCC_ENV_PLAT_BASE_TAG_APPLE)
            #define XCC_ENV_PLAT_BASE_STR            "Apple"
        #elif defined(XCC_ENV_PLAT_BASE_TAG_WINDOWS)
            #define XCC_ENV_PLAT_BASE_STR            "Windows"
        #elif defined(XCC_ENV_PLAT_BASE_TAG_BSD)
            #define XCC_ENV_PLAT_BASE_STR            "BSD"
        #elif defined(XCC_ENV_PLAT_BASE_TAG_POSIX)
            #define XCC_ENV_PLAT_BASE_STR            "Posix"
        #else
            #define XCC_ENV_PLAT_BASE_STR            "Unknown"
        #endif

    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌ARCHITECTURE──────────────────────────────────────────────────────────────────────┐ */

        // - X86
        #if defined(_M_X64) || defined(__x86_64__) || defined(_M_IX86) || defined(__i386__)
            // - info
            #define XCC_ENV_ARCH_BASE_STR               "X86"
            #define XCC_ENV_ARCH_BASE_TAG_X86
            // - details
            #define XCC_ENV_ARCH_END                    1
            #if defined(_M_X64) || defined(__x86_64__)
                #define XCC_ENV_ARCH_STR                "x86_64"
                #define XCC_ENV_ARCH_TAG_X86_64
                #define XCC_ENV_ARCH_BIT                64
            #else
                #define XCC_ENV_ARCH_STR                "x86_32"
                #define XCC_ENV_ARCH_TAG_X86_32
                #define XCC_ENV_ARCH_BIT                32
            #endif


        // - ARM
        #elif defined(__ARMEL__) || defined(__aarch64__) || defined(_M_ARM64)
            // - info
            #define XCC_ENV_ARCH_BASE_STR               "ARM"
            #define XCC_ENV_ARCH_BASE_TAG_ARM
            // - details
            #define XCC_ENV_ARCH_END                     1
            #if defined(__aarch64__) || defined(_M_ARM64)
                #define XCC_ENV_ARCH_STR                "ARM_64"
                #define XCC_ENV_ARCH_TAG_ARM_64
                #define XCC_ENV_ARCH_BIT                64
            #else
                #define XCC_ENV_ARCH_STR                "ARM_32"
                #define XCC_ENV_ARCH_TAG_ARM_32
                #define XCC_ENV_ARCH_BIT                32
            #endif


        // - MIPS
        #elif defined(__MIPSEL__) || defined(__MIPSEB__)
            // - name
            #define XCC_ENV_ARCH_BASE_STR               "MIPS"
            #define XCC_ENV_ARCH_BASE_TAG_MIPS
            // - details
            #if defined(__MIPSEL__)
                #define XCC_ENV_ARCH_END                2
            #else
                #define XCC_ENV_ARCH_END                1
            #endif
            #if defined(__LP64__)
                #define XCC_ENV_ARCH_STR                "MIPS_64"
                #define XCC_ENV_ARCH_TAG_MIPS_64
                #define XCC_ENV_ARCH_BIT                64
            #else
                #define XCC_ENV_ARCH_STR                "MIPS_32"
                #define XCC_ENV_ARCH_TAG_MIPS_32
                #define XCC_ENV_ARCH_BIT                32
            #endif


        // - LOONG
        #elif defined(__loongarch32) || defined(__loongarch64)
            // - info
            #define XCC_ENV_ARCH_BASE_STR               "LOONG"
            #define XCC_ENV_ARCH_BASE_TAG_LOONG
            // - details
            #define XCC_ENV_ARCH_END                    1
            #if defined(__loongarch64)
                #define XCC_ENV_ARCH_STR                "LOONG_64"
                #define XCC_ENV_ARCH__IDSLOONG_64
                #define XCC_ENV_ARCH_BIT                64
            #else
                #define XCC_ENV_ARCH_STR                "LOONG_32"
                #define XCC_ENV_ARCH__IDSLOONG_32
                #define XCC_ENV_ARCH_BIT                32
            #endif


        // - S390
        #elif defined(__s390x__) || defined(__s390__)
            // - info
            #define XCC_ENV_ARCH_BASE_STR               "S390"
            #define XCC_ENV_ARCH_BASE_TAG_S390
            // - details
            #if defined(__s390x__)
                #define XCC_ENV_ARCH_STR                "s390_64"
                #define XCC_ENV_ARCH_TAG_S390_64
                #define XCC_ENV_ARCH_END                2
                #define XCC_ENV_ARCH_BIT                64
            #else
                #define XCC_ENV_ARCH_STR                "s390_31"
                #define XCC_ENV_ARCH_TAG_S390_31
                #define XCC_ENV_ARCH_END                2
                #define XCC_ENV_ARCH_BIT                31
            #endif


        // - PPC64
        #elif (defined(__PPC64__) || defined(__PPC__))
            // - info
            #define XCC_ENV_ARCH_STR                    "PPC64"
            #define XCC_ENV_ARCH_BASE_STR               "PPC64"
            #define XCC_ENV_ARCH_TAG_PPC64
            #define XCC_ENV_ARCH_BASE_TAG_PPC64
            // - details
            #if defined(__BIG_ENDIAN__)
                #define XCC_ENV_ARCH_END                2
            #else
                #define XCC_ENV_ARCH_END                1
            #endif
            #define XCC_ENV_ARCH_BIT                    64


        // - ASM
        #elif defined(__pnacl__) || defined(__asmjs__) || defined(__wasm__)
            // - info
            #define XCC_ENV_ARCH_STR                    "ASM"
            #define XCC_ENV_ARCH_BASE_STR               "ASM"
            #define XCC_ENV_ARCH_TAG_ASM
            #define XCC_ENV_ARCH_BASE_TAG_ASM
            // - details
            #define XCC_ENV_ARCH_END                    1
            #define XCC_ENV_ARCH_BIT                    32


        // - RISCV
        #elif defined(__riscv) && defined(__riscv_xlen) && (__riscv_xlen == 64)
            // - info
            #define XCC_ENV_ARCH_STR                    "RISCV"
            #define XCC_ENV_ARCH_BASE_STR               "RISCV"
            #define XCC_ENV_ARCH_TAG_RISCV64
            #define XCC_ENV_ARCH_BASE_TAG_RISCV
            // - details
            #define XCC_ENV_ARCH_END                    1
            #define XCC_ENV_ARCH_BIT                    64


        // - Unknown
        #else
            // - info
            #define XCC_ENV_ARCH_STR                    "Unknown"
            #define XCC_ENV_ARCH_BASE_STR               "Unknown"
            #define XCC_ENV_ARCH_TAG_UNKNOWN
            #define XCC_ENV_ARCH_BASE_TAG_UNKNOWN
            // - details
            #define XCC_ENV_ARCH_END                    0
            #define XCC_ENV_ARCH_BIT                    0
        #endif

    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌STANDARD─ATTRIBUTES───────────────────────────────────────────────────────────────┐ */

        // - assume
        #if XCC_ENV_HAS_ATTR(assume)
            #define XCC_ENV_ATTR_ASSUME(x)              [[assume(x)]]
        #else
            #define XCC_ENV_ATTR_ASSUME(x)
        #endif


        // - carries_dependency
        #if XCC_ENV_HAS_ATTR(carries_dependency)
            #define XCC_ENV_ATTR_CARRIES_DEPENDENCY     [[carries_dependency]]
        #else
            #define XCC_ENV_ATTR_CARRIES_DEPENDENCY
        #endif


        // - deprecated
        #if XCC_ENV_HAS_ATTR(deprecated)
            #define XCC_ENV_ATTR_DEPRECATED(x)          [[deprecated(x)]]
        #else
            #define XCC_ENV_ATTR_DEPRECATED(x)
        #endif


        // - fallthrough
        #if XCC_ENV_HAS_ATTR(fallthrough)
            #define XCC_ENV_ATTR_FALLTHROUGH            [[fallthrough]]
        #else
            #define XCC_ENV_ATTR_FALLTHROUGH
        #endif


        // - likely
        #if XCC_ENV_HAS_ATTR(likely)
            #define XCC_ENV_ATTR_LIKELY                 [[likely]]
        #else
            #define XCC_ENV_ATTR_LIKELY
        #endif


        // - unlikely
        #if XCC_ENV_HAS_ATTR(unlikely)
            #define XCC_ENV_ATTR_UNLIKELY               [[unlikely]]
        #else
            #define XCC_ENV_ATTR_UNLIKELY
        #endif


        // - maybe_unused
        #if XCC_ENV_HAS_ATTR(maybe_unused)
            #define XCC_ENV_ATTR_MAYBE_UNUSED           [[maybe_unused]]
        #else
            #define XCC_ENV_ATTR_MAYBE_UNUSED
        #endif


        // - nodiscard
        #if XCC_ENV_HAS_ATTR(nodiscard)
            #define XCC_ENV_ATTR_NODISCARD              [[nodiscard]]
        #else
            #define XCC_ENV_ATTR_NODISCARD
        #endif


        // - noreturn
        #if XCC_ENV_HAS_ATTR(noreturn)
            #define XCC_ENV_ATTR_NORETURN               [[noreturn]]
        #else
            #define XCC_ENV_ATTR_NORETURN
        #endif

    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌COMPILER─ATTRIBUTES───────────────────────────────────────────────────────────────┐ */

        // - always_inline
        #if defined(XCC_ENV_COMP_TAG_GCC) || defined(XCC_ENV_COMP_TAG_CLANG)
            #define XCC_ENV_ATTR_INLINE                 inline __attribute__((__always_inline__))
        #elif defined(XCC_ENV_COMP_TAG_MSVC)
            #define XCC_ENV_ATTR_INLINE                 inline __forceinline
        #else
            #define XCC_ENV_ATTR_INLINE                 inline
        #endif


        // - noinline
        #if defined(XCC_ENV_COMP_TAG_GCC) || defined(XCC_ENV_COMP_TAG_CLANG)
            #define XCC_ENV_ATTR_NOINLINE               __attribute__((noinline))
        #elif defined(XCC_ENV_COMP_TAG_MSVC)
            #define XCC_ENV_ATTR_NOINLINE               __declspec(noinline)
        #else
            #define XCC_ENV_ATTR_NOINLINE
        #endif


        // - visibility
        #if defined(__GNUC__) && __GNUC__ >= 4
            #define XCC_ENV_ATTR_VISIBLE                __attribute__ ((visibility ("default")))
            #define XCC_ENV_ATTR_HIDDEN                 __attribute__ ((visibility ("hidden")))
        #elif defined(_WIN32) || defined(__CYGWIN__)
        #ifdef BUILDING_DLL
            #define XCC_ENV_ATTR_VISIBLE                __declspec(dllexport)
            #define XCC_ENV_ATTR_HIDDEN
        #else
            #define XCC_ENV_ATTR_VISIBLE                __declspec(dllimport)
            #define XCC_ENV_ATTR_HIDDEN
        #endif
        #else
            #define XCC_ENV_ATTR_VISIBLE
            #define XCC_ENV_ATTR_HIDDEN
        #endif

    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌DEFAULT─VALUES────────────────────────────────────────────────────────────────────┐ */

        // : Default size of alignment
        #ifdef __STDCPP_DEFAULT_NEW_ALIGNMENT__
            #define XCC_ENV_DEF_ALIGN_SIZE              __STDCPP_DEFAULT_NEW_ALIGNMENT__
        #else
            #define XCC_ENV_DEF_ALIGN_SIZE              16
        #endif

    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌MAKERS────────────────────────────────────────────────────────────────────────────┐ */

        // : Stringify the arguments
        #define XCC_MAKE_STR_VAL_(str, ...)             #str
        #define XCC_MAKE_STR_VAL(...)                   XCC_MAKE_STR_VAL_(__VA_ARGS__, )

    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */




/* ┏FILE─END━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ */

    /* ┌REQUIREMENTS──────────────────────────────────────────────────────────────────────┐ */
        #if XCC_ENV_HAS_INCLUDE(<intrin.h>)
        #include <intrin.h>                             // ↭ MSVC : _ReadWriteBarrier
        #endif
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */


    /* ┌GUARD─────────────────────────────────────────────────────────────────────────────┐ */
        #endif
    /* └──────────────────────────────────────────────────────────────────────────────────┘ */

/* ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ */
