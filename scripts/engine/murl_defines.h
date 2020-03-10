// Copyright 2010-2015 Spraylight

#ifndef __MURL_DEFINES_H__
#define __MURL_DEFINES_H__

// Emscripten
#if defined(__EMSCRIPTEN__)

#   include <stdint.h> // uintptr_t
#   include <sys/types.h>

#   define MURL_USE_TEMPLATE_VARIABLE_FORWARD_DECLARATIONS

#   define MURL_TARGET_OS_EMSCRIPTEN
#   define MURL_COMPILER_EMCC

#   define MURL_TARGET_CPU_X86
#   define MURL_TARGET_ARCHITECTURE_32BIT
#   define MURL_ENDIANNESS_LITTLE

#   define MURL_ALIGN_DATA(x, type) type __attribute__ ((aligned(x)))

#   define MURL_PACKED_STRUCT(type) type __attribute__((__packed__))

#   define MURL_CDECL

#   define MURL_CURRENT_FUNCTION __PRETTY_FUNCTION__

// Visual Studio
#elif defined(_MSC_VER)

#   pragma warning (disable: 4018)  // signed/unsigned mismatch
#   pragma warning (disable: 4065)  // switch statement contains 'default' but no 'case' labels
#   pragma warning (disable: 4244)  // 'initializing': conversion from '' to '', possible loss of data
#   pragma warning (disable: 4577)  // 'noexcept' used with no exception handling mode specified
#   pragma warning (disable: 4838)  // conversion from '' to '' requires a narrowing conversion

#   if defined(_M_X64) || defined(_M_IA64)
#       define MURL_TARGET_CPU_I64
#       define MURL_TARGET_ARCHITECTURE_64BIT
#       define MURL_ENDIANNESS_LITTLE
#   else
#       define MURL_TARGET_CPU_X86
#       define MURL_TARGET_ARCHITECTURE_32BIT
#       define MURL_ENDIANNESS_LITTLE
#   endif

#   define MURL_TARGET_OS_WIN

#   if defined(WINAPI_FAMILY)
#       include <winapifamily.h>
#       if defined(WINAPI_PARTITION_PHONE) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)
#           define MURL_TARGET_OS_WINPHONE8
#       elif WINAPI_FAMILY == WINAPI_FAMILY_APP
#           define MURL_TARGET_OS_WIN8
#       else
#           define MURL_TARGET_OS_WIN32
#       endif
#   else
#       define MURL_TARGET_OS_WIN32
#   endif

#   if (_MSC_VER >= 1900)
#       define MURL_COMPILER_VS2015
#   elif (_MSC_VER >= 1800)
#       define MURL_COMPILER_VS2013
#   elif (_MSC_VER >= 1700)
#       define MURL_COMPILER_VS2012
#   elif (_MSC_VER >= 1600)
#       define MURL_COMPILER_VS2010
#   elif (_MSC_VER >= 1500)
#       define MURL_COMPILER_VS2008
#   endif

#   if (_MSC_VER >= 1900)
#       define MURL_COMPILER_C14
#   endif
#   if (_MSC_VER >= 1800)
#       define MURL_COMPILER_C11
#   endif
#   if (_MSC_VER >= 1500)
#       define MURL_COMPILER_C98
#   endif

#   define MURL_COMPILER_VS

#   define MURL_ALIGN_DATA(x, type) __declspec(align(x)) type

#   define MURL_PACKED_STRUCT(type) __pragma( pack(push, 1) ) type __pragma( pack(pop) )

#   ifdef MURL_TARGET_CPU_I64
typedef unsigned __int64 uintptr_t;
#   endif

#   ifdef MURL_TARGET_CPU_X86
typedef __w64 unsigned int uintptr_t;
#   endif

#   define MURL_CDECL __cdecl

#   define MURL_CURRENT_FUNCTION __FUNCSIG__


// GCC
#elif defined(__MINGW32__) || defined(__CYGWIN32__) || defined(__GNUC__)

#   if (__cplusplus >= 201103L)
#       define MURL_USE_STDATOMIC
#       define MURL_USE_TEMPLATE_VARIABLE_FORWARD_DECLARATIONS
#   endif

#   if defined(__i386__)
#       define MURL_TARGET_CPU_X86
#       define MURL_TARGET_ARCHITECTURE_32BIT
#       define MURL_ENDIANNESS_LITTLE
#   elif defined(__x86_64)
#       define MURL_TARGET_CPU_I64
#       define MURL_TARGET_ARCHITECTURE_64BIT
#       define MURL_ENDIANNESS_LITTLE
#   elif defined(__arm64__) || defined(__aarch64__)
#       define MURL_TARGET_CPU_ARM64
#       define MURL_TARGET_ARCHITECTURE_64BIT
#       define MURL_ENDIANNESS_LITTLE
#   elif defined(__arm__)
#       define MURL_TARGET_CPU_ARM
#       define MURL_TARGET_ARCHITECTURE_32BIT
#       define MURL_ENDIANNESS_LITTLE
#   endif

#   if defined(__FLASHPLAYER__)
#       define MURL_TARGET_OS_FLASH
#       define MURL_TARGET_CPU_X86
#       define MURL_TARGET_ARCHITECTURE_32BIT
#       define MURL_ENDIANNESS_LITTLE
#   elif defined(__MINGW32__)
#       define MURL_TARGET_OS_WIN
#       define MURL_TARGET_OS_WIN32
#   elif defined(__APPLE__)
#       include "TargetConditionals.h"
#       if (TARGET_OS_TV == 1)
#           define MURL_TARGET_OS_TVOS
#       elif (TARGET_OS_IPHONE == 1) || (TARGET_IPHONE_SIMULATOR == 1)
#           define MURL_TARGET_OS_IOS
#       else
#           define MURL_TARGET_OS_OSX
#       endif
#       define MURL_COMPILER_XCODE
#   elif defined(__CYGWIN32__) || defined(__GNUC__)
#       if defined(__ANDROID__)
#           define MURL_TARGET_OS_ANDROID
#       elif defined(MURL_RASPBIAN)
#           define MURL_TARGET_OS_RASPBIAN
#       else
#           define MURL_TARGET_OS_POSIX
#       endif
#   endif

#   define MURL_COMPILER_GCC

#   define MURL_ALIGN_DATA(x, type) type __attribute__ ((aligned(x)))

#   define MURL_PACKED_STRUCT(type) type __attribute__((__packed__))

typedef __SIZE_TYPE__ size_t;
typedef __SIZE_TYPE__ uintptr_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;

#   if defined(__GNUC__) && defined(__i386) && !defined(__INTEL_COMPILER)
#       define MURL_CDECL __attribute__((cdecl))
#   else
#       define MURL_CDECL
#   endif

#   define MURL_CURRENT_FUNCTION __PRETTY_FUNCTION__


// Unsupported Compiler
#elif (!defined(MURL_DOXYGEN))

#   error "Unsupported compiler"

#   if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#       define MURL_CURRENT_FUNCTION __func__
#   else
#       define MURL_CURRENT_FUNCTION "<unknown>"
#   endif

#endif


// C++ Compiler language dialect
#ifndef MURL_COMPILER_C14
#   if (__cplusplus >= 201402L)
#       define MURL_COMPILER_C14
#   endif   // __cplusplus
#endif  // MURL_COMPILER_C14

#ifndef MURL_COMPILER_C11
#   if (__cplusplus >= 201103L)
#       define MURL_COMPILER_C11
#   endif   // __cplusplus
#endif  // MURL_COMPILER_C11

#ifndef MURL_COMPILER_C98
#   if (__cplusplus >= 199711L)
#       define MURL_COMPILER_C98
#   endif   // __cplusplus
#endif  // MURL_COMPILER_C98


// Debug build
#if defined(DEBUG) || defined(_DEBUG)
#   define MURL_DEBUG
#else
#   define MURL_RELEASE
#endif


/**
 * @addtogroup MurlDefines
 * @brief The global defines should be used to ensure multi-platform compatibility.
 * @{
 */

/** @brief Definition of the NULL pointer value. */
#ifndef NULL
#   ifdef __cplusplus
#       define NULL 0
#   else
#       define NULL ((void *)0)
#   endif
#endif


#ifdef MURL_DOXYGEN

/** @brief Compiling a debug build. */
#   define MURL_DEBUG
/** @brief Compiling a release build. */
#   define MURL_RELEASE

/** @brief Compiling for an Intel 64-bit CPU. */
#   define MURL_TARGET_CPU_I64
/** @brief Compiling for an Intel 32-bit CPU. */
#   define MURL_TARGET_CPU_X86
/** @brief Compiling for an Arm 32-bit CPU. */
#   define MURL_TARGET_CPU_ARM
/** @brief Compiling for an Arm 64-bit CPU. */
#   define MURL_TARGET_CPU_ARM64

/** @brief Compiling for 64-bit architecture. */
#   define MURL_TARGET_ARCHITECTURE_64BIT
/** @brief Compiling for 32-bit architecture. */
#   define MURL_TARGET_ARCHITECTURE_32BIT

/** @brief Compiling for little endian architecture. */
#   define MURL_ENDIANNESS_LITTLE

/** @brief Compiling for a Windows system. */
#   define MURL_TARGET_OS_WIN
/** @brief Compiling for a Windows (win32 api) desktop system. */
#   define MURL_TARGET_OS_WIN32
/** @brief Compiling for a Windows 8 modern system. */
#   define MURL_TARGET_OS_WIN8
/** @brief Compiling for a Windows 8 phone system. */
#   define MURL_TARGET_OS_WINPHONE8
/** @brief Compiling for an iOS system. */
#   define MURL_TARGET_OS_IOS
/** @brief Compiling for a tvOS system. */
#   define MURL_TARGET_OS_TVOS
/** @brief Compiling for an OSX system. */
#   define MURL_TARGET_OS_OSX
/** @brief Compiling for an Android system. */
#   define MURL_TARGET_OS_ANDROID
/** @brief Compiling for a Posix (Linux) system. */
#   define MURL_TARGET_OS_POSIX
/** @brief Compiling to JavaScript/WebGL using Emscripten. */
#   define MURL_TARGET_OS_EMSCRIPTEN

/** @brief GNU Compiler. */
#   define MURL_COMPILER_GCC
/** @brief Xcode Compiler. */
#   define MURL_COMPILER_XCODE
/** @brief Visual Studio compiler. */
#   define MURL_COMPILER_VS
/** @brief Visual Studio 2008 compiler. */
#   define MURL_COMPILER_VS2008
/** @brief Visual Studio 2010 compiler. */
#   define MURL_COMPILER_VS2010
/** @brief Visual Studio 2012 compiler. */
#   define MURL_COMPILER_VS2012
/** @brief Visual Studio 2013 compiler. */
#   define MURL_COMPILER_VS2013
/** @brief Visual Studio 2015 compiler. */
#   define MURL_COMPILER_VS2015
/** @brief Emscripten compiler. */
#   define MURL_COMPILER_EMCC

/** @brief Compiling C++98 or newer language dialect. */
#   define MURL_COMPILER_C98
/** @brief Compiling C++11 or newer language dialect. */
#   define MURL_COMPILER_C11
/** @brief Compiling C++14 or newer language dialect. */
#   define MURL_COMPILER_C14

/**
 *  @brief Definition for memory alignment.
 *  e.g. defining a 16 byte-aligned struct.
 *  @code
 *  MURL_ALIGN_DATA(16,
 *  struct MyStruct
 *  {
 *      UInt64 mMyValue1;
 *      UInt32 mMyValue2;
 *  });
 *  @endcode
 *  e.g. Instantiate an 8 byte-aligned 32-bit integer.
 *  @code
 *  MURL_ALIGN_DATA(8, UInt32 myInteger);
 *  @endcode
 *  @param x The number of bytes to align.
 *  @param type The struct, union, class, or variable to align.
 */
#   define MURL_ALIGN_DATA(x, type)

/**
 *  @brief Definition for a packed structure.
 *  @code
 *  MURL_PACKED_STRUCT(
 *  struct MyStruct
 *  {
 *      UInt64 mMyValue1;
 *      UInt32 mMyValue2;
 *  });
 *  @endcode
 *  @param type The struct, union, class, or variable to pack.
 */
#   define MURL_PACKED_STRUCT(type)

/**
 *  @brief Definition for the calling convention for C and C++.
 *  e.g. declaring a public function for a library:
 *  @code
 *  void MURL_CDECL MyFunction(UInt32 myParameters);
 *  @endcode
 */
#   define MURL_CDECL

/** @brief Definition for the current function signature string. */
#   define MURL_CURRENT_FUNCTION

#endif
/** @} */

#endif  // __MURL_DEFINES_H__
