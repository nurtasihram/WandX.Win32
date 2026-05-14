#pragma once

#define S(str) T(str##_S)

#pragma region Compilation Informations
//----------- _WX_COMPILED_TIME ----------------------------------------------------------//
#      define _WX_COMPILED_TIME               __DATE__ " " __TIME__                       //
//----------- _WX_CPP_STANDARD -----------------------------------------------------------//
#      define _WX_CPP_STANDARD                macro_str(__cplusplus)                         //
//----------- _WX_CHAR_MODE --------------------------------------------------------------//
#if   defined                                 UNICODE                                     //
#      define _WX_CHAR_MODE                   "Unicode"                                   //
#else                                                                                     //
#      define _WX_CHAR_MODE                   "MultiByte"                                 //
#endif                                                                                    //
//----------- _WX_BUILD_MODE -------------------------------------------------------------//
#if   defined                                 _DEBUG                                      //
#      define _WX_BUILD_MODE                  "Debug"                                     //
#else                                                                                     //
#      define _WX_BUILD_MODE                  "Release"                                   //
#endif                                                                                    //
//----------- _WX_PLATFORM_BITS ----------------------------------------------------------//
#if   defined                                 _WIN64                                      //
#      define _WX_PLATFORM_BITS               "64-bits"                                   //
#elif defined                                 _WIN32                                      //
#      define _WX_PLATFORM_BITS               "32-bits"                                   //
#else                                                                                     //
#      define _WX_PLATFORM_BITS               "Unknown"                                   //
#endif                                                                                    //
//----------- _WX_ARCHITECTURE -----------------------------------------------------------//
#if   defined                                 _M_X64                                      //
#      define _WX_ARCHITECTURE                "x64"                                       //
#elif defined                                 _M_IX86                                     //
#      define _WX_ARCHITECTURE                "x86"                                       //
#elif defined                                 _M_AMD64                                    //
#      define _WX_ARCHITECTURE                "AMD64"                                     //
#elif defined                                 _M_ARM64                                    //
#      define _WX_ARCHITECTURE                "ARM64"                                     //
#elif defined                                 _M_ARM                                      //
#      define _WX_ARCHITECTURE                "ARM"                                       //
#elif defined                                 _M_ARM64EC                                  //
#      define _WX_ARCHITECTURE                "ARM64EC"                                   //
#else                                                                                     //
#      define _WX_ARCHITECTURE                "Unknown"                                   //
#endif                                                                                    //
//----------- _WX_COMPILER ---------------------------------------------------------------//
#if   defined                                 __clang__                                   //
#      define _WX_COMPILER                    "Clang "       macro_str(__clang_version__)    //
#elif defined                                 __GNUC__                                    //
#      define _WX_COMPILER                    "GCC "         macro_str(__VERSION__)          //
#elif defined                                 _MSC_VER                                    //
#      define _WX_COMPILER                    "MSVC "        macro_str(_MSC_FULL_VER)        //
#else                                                                                     //
#      define _WX_COMPILER                    "Unknown"                                   //
#endif                                                                                    //
//----------- _NTDDI_ --------------------------------------------------------------------//
#if            NTDDI_VERSION >=               NTDDI_WIN11_GE                              //
#      define _WX_NTDDI_NAME                  "Windows 11 'Germanium'"                    //
#elif          NTDDI_VERSION >=               NTDDI_WIN11_GA                              //
#      define _WX_NTDDI_NAME                  "Windows 11 'Gallium'"                      //
#elif          NTDDI_VERSION >=               NTDDI_WIN11_ZN                              //
#      define _WX_NTDDI_NAME                  "Windows 11 'Zinc'"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_CU                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Copper'"                       //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_NI                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Nickel'"                       //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_CO                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Cobalt'"                       //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_FE                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Iron'"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_MN                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Manganese'"                    //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_VB                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Vibranium'"                    //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_19H1                            //
#      define _WX_NTDDI_NAME                  "Windows 10 1903 '19H1''"                   //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS5                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1809 'Redstone 5'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS4                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1803 'Redstone 4'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS3                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1709 'Redstone 3'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS2                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1703 'Redstone 2'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS1                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1607 'Redstone 1'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_TH2                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1511 'Threshold 2'"             //
#elif          NTDDI_VERSION >=               NTDDI_WIN10                                 //
#      define _WX_NTDDI_NAME                  "Windows 10 1507 'Threshold'"               //
#elif          NTDDI_VERSION >=               NTDDI_WINBLUE                               //
#      define _WX_NTDDI_NAME                  "Windows 8.1"                               //
#elif          NTDDI_VERSION >=               NTDDI_WIN8                                  //
#      define _WX_NTDDI_NAME                  "Windows 8"                                 //
#elif          NTDDI_VERSION >=               NTDDI_WIN7                                  //
#      define _WX_NTDDI_NAME                  "Windows 7"                                 //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP4                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP4"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP3                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP3"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP2                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP2"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP1                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP1"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6                                  //
#      define _WX_NTDDI_NAME                  "Windows Vista"                             //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP4                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP4"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP3                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP3"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP2                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP2"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP1                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP1"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03                                  //
#      define _WX_NTDDI_NAME                  "Windows Server 2003"                       //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP4                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP4"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP3                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP3"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP2                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP2"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP1                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP1"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXP                                 //
#      define _WX_NTDDI_NAME                  "Windows XP"                                //
#else                                                                                     //
#      define _WX_NTDDI_NAME                  "Windows Unknown"                           //
#endif                                                                                    //
#      define _NTDDI_INFO                     _WX_NTDDI_NAME " - " macro_str(NTDDI_VERSION)  //
//-------------------------------- _WX_COMPILATION_INFO ----------------------------------//
#             define                          _WX_COMPILATION_INFO                         \
              "Compiled Date: "               _WX_COMPILED_TIME                       "\n" \
              "C++ Standard:  "               _WX_CPP_STANDARD                        "\n" \
              "Char Mode:     "               _WX_CHAR_MODE                           "\n" \
              "Build Mode:    "               _WX_BUILD_MODE                          "\n" \
              "Platform Bits: "               _WX_PLATFORM_BITS                       "\n" \
              "Architecture:  "               _WX_ARCHITECTURE                        "\n" \
              "Compiler:      "               _WX_COMPILER                            "\n" \
              "NTDDI Version: "               _WX_NTDDI_NAME                              //
#pragma endregion //////////////////////////////////////////////////////////////////////////

#ifdef WANDX_CPPM_EXPORT_NATIVE

#	pragma region Windows API Reflectors

#	define __wapi_info(name) ThisFile, GetLastError, LiString(#name)

#	define __wapi_rops_noreturn(...)         RefNoReturn
#	define __wapi_rops_direct(...)           RefReturnDirect
#	define __wapi_rops_true(...)             RefReturnTrue
#	define __wapi_rops_positive(...)         RefReturnPositive
#	define __wapi_rops_notzero(...)          RefReturnNotZero
#	define __wapi_rops_natural(...)          RefReturnNatural
#	define __wapi_rops_notnull(...)          RefReturnNotNull
#	define __wapi_rops_validhd(...)          RefReturnHandle
#	define __wapi_rops_success(...)          RefReturnSuccess
#	define __wapi_rops_fault(fault_val)      RefReturnFaultBy<fault_val, LiString(#fault_val)>::template Value

#	define __wapi_rops(type, ...)            macro_call(macro_cat(__wapi_rops_, type), __VA_ARGS__)

/* Macro Windows API reflectors */

#	define wapi_ret(name, type, ...)         constexpr              __wapi_rops(type, __VA_ARGS__)< __wapi_info(name   ), ::name   > name
#	define wapi_ret_W(name, type, ...)       constexpr              __wapi_rops(type, __VA_ARGS__)< __wapi_info(name##W), ::name##W> name
#	define wapi_ret_A(name, type, ...)       constexpr              __wapi_rops(type, __VA_ARGS__)< __wapi_info(name##A), ::name##A> name
#	define wapi_ret_WAO(name, type, ...)     constexpr RefReturnWAO<__wapi_rops(type, __VA_ARGS__), __wapi_info(name   ), ::name##W, ::name##A> name
#	define wapi_ret_WAT(name, type, ...)     template<bool IsUnicode = Native::IsUnicode> \
                                             constexpr RefReturnWAT<__wapi_rops(type, __VA_ARGS__), __wapi_info(name   ), ::name##W, ::name##A, IsUnicode> name

/* Macro exception system reflect for Windows */

#	define wx_throw_line_nt(sent) throw WandX::Exception(__FILE__, __FUNCTION__, #sent, __LINE__, GetLastError())
#	define nt_assert(sent) { using namespace WandX; if (!(sent)) wx_throw_line_nt(sent); }

#	pragma endregion

#	pragma region

// Macro of string property
#	define class_prop_strfix_getas_WAO(name, maxlen, body) \
    template<bool IsUnicode = Native::IsUnicode, SizeT MaxLen = maxlen> \
    inline StringX<IsUnicode> name() const { \
        StringX<IsUnicode> value(MaxLen); \
        auto len = body; \
        return right_cast(value.Resize(len)); \
    } \
    template<SizeT MaxLen = maxlen> const \
    inline StringA name##A() const ret_as(name<false, MaxLen>()); \
    template<SizeT MaxLen = maxlen> const \
    inline StringW name##W() const ret_as(name<true, MaxLen>())

// proxy struct WAT
#define proxy_structWAT(name, struct_name) \
    template<bool IsUnicode = Native::IsUnicode> \
    struct name##X; \
    using  name    = name##X<>; \
    using  name##A = name##X<false>; \
    using  name##W = name##X<true>; \
    template<bool IsUnicode> \
    struct name##X final : WandX::ProxyCStruct<name, TypeIf<IsUnicode, struct_name##W, struct_name##A>>

#	pragma endregion

///////////////////////////////////////////// !!!!DEPRECATE SOON!!!! /////////////////////////////////////////////

#	define safe_ret_as(sent, ...) { if (sent) return __VA_ARGS__; wx_throw_line_nt(sent); }
#	define safe_ret_to(defs, sent, ...) { defs; if (sent) return __VA_ARGS__; wx_throw_line_nt(sent); }
#	define ret_safe_to(sent, ...) { SetLastError(ERROR_SUCCESS); sent; if (GetLastError()) wx_throw_line_nt(sent); return __VA_ARGS__; }

/* Macro string branch selector */
#	define locale_symbolx(name)     static constexpr auto name = AnyX<IsUnicode>(name##W, name##A)
#	define const_stringx(name, str) static constexpr auto name##A = str; \
                                    static constexpr auto name##W = L##str
#	define auto_stringx(name, str)  const_stringx(name, str); \
                                    locale_symbolx(name)
#	define structx(name)            TypeIf<IsUnicode, name##W, name##A>
#	define using_structx(name)      using name = TypeIf<IsUnicode, name##W, name##A>

#endif

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32;
#endif

#include "WandX.h"

#undef min
#undef max
