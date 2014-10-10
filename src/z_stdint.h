/** @addtogroup GROUP_ZYLLIBC	zyllibc
 * [zyl910](https://github.com/zyl910/c99int)'s C/C++ librarys.
 * @{
 */

/** @addtogroup GROUP_ZLSTDINT	zlstdint
 * Auto C99 integer type compliant (让VC等编译器自动兼容C99的整数类型) .
 *
 * @author	[zyl910](mailto:zyl910hero@gmail.com)
 * @version	1.0
 * @date	2014-11-01
 *
 * Links:
 *
 * * Git: https://github.com/zyl910/zlstdint
 * * Blog: http://www.cnblogs.com/zyl910/tag/zlstdint/
 *
 * c99int is a lightweight C library. Use for auto C99 integer type compliant (用于让VC等编译器自动兼容C99的整数类型) .
 * 
 * 
 * References (参考文献) :
 * 
 * * ISO/IEC 9899:1999 - Programming languages -- C (C99). ISO/IEC，1999.
 * * msinttypes. http://code.google.com/p/msinttypes/
 * 
 * 
 * ## Usage (用法)
 * 
 * Add `src/``*.*` to you project (将 `src/``*.*` 加入到您的项目).
 * 
 * Example code:
 * 
 * 	#define __STDC_LIMIT_MACROS
 * 	#define __STDC_CONSTANT_MACROS
 * 	#define __STDC_FORMAT_MACROS
 * 	
 * 	#include <stdio.h>
 * 	
 * 	#include "z_stdint.h"
 * 	#include "z_inttyp.h"
 * 	
 * 	int main(int argc, char* argv[])
 * 	{
 * 		uint8_t i8 = (uint8_t)INT8_C(-1);
 * 		uint16_t i16 = (uint16_t)INT16_C(-1);
 * 		uint32_t i32 = (uint32_t)INT32_C(-1);
 * 		uint64_t i64 = (uint64_t)INT64_C(-1);
 * 	
 * 		printf("c99int:\t%" PRIu8 ", %" PRIu16 ", %" PRIu32 ", %" PRIu64 "\n", i8, i16, i32, i64);
 * 		return 0;
 * 	}
 *
 * ## Documentation (文档)
 * 
 * You can generate documentation with [doxygen](http://www.stack.nl/~dimitri/doxygen/index.html) (您可以用doxygen生成文档).
 * 
 * Use doxywizard to open *.doxygen file (使用doxywizard打开 *.doxygen).
 * 
 * * c99int_doc.doxygen: Generates documentation from interface files (生成接口的文档) .
 * * c99int_docfull.doxygen: Generates documentation from interface & implement and example files (生成接口、实现、示例等内容的详细文档).
 * 
 * You may need change INCLUDE_PATH in *.doxyfile with the actual location (您可能需要在 *.doxygen 中调整INCLUDE_PATH为实际路径).
 * 
 * 
 * ## MIT License (MIT许可证)
 * 
 * Copyright (c) 2000-2013 zyl910 \<zyl910hero@gmail.com\>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 * ## Tested compiler (测试过的编译器)
 * 
 * * Virtual C++: 6, 7.1(2003), 8(2005), 9(2008), 10(2010), 11(2012), 12(2013).
 * * C++ Builder: Turbo C++ 3, Borland C++ 3.1, C++ Builder 6.
 * * GCC(Linux): 4.7.0~4.8.1(Fedora 17~19).
 * * GCC(MinGW): 4.6.2(MinGW(20120426)), 4.7.1(TDM-GCC(MinGW-w64)).
 * * LLVM GCC: 4.2(Mac OS X Lion 10.7.4), 4.2.1(Mac OS X Mountain Lion 10.8.3).
 * 
 * 
 * 
 * ## Change history (变更日志)
 * 
 * [2014-11-01] v1.0
 * 
 * * Release v1.0 (发布1.0版) .
 * 
 *
 * @{
 */

/**
 * @file	z_stdint.h
 * @brief	Auto include C99 stdint.h (自动引用C99标准的stdint.h).
 * @since	@ref GROUP_ZLSTDINT 1.0
 */


#ifndef __AUTO_STDINT_H_INCLUDED
#define __AUTO_STDINT_H_INCLUDED

// __AUTO_STDINT_H_USESYS: 编译器是否提供了<stdint.h>
#undef __AUTO_STDINT_H_USESYS
#if defined(__GNUC__)	// GCC.
	#define __AUTO_STDINT_H_USESYS
#elif defined(_MSC_VER)	// MSVC. VC6至VC2008均没有, 从VC2010才支持的.
	#if _MSC_VER >=1600	// VC2010
		#define __AUTO_STDINT_H_USESYS
	#endif	// #if _MSC_VER >=1600	// VC2010
#elif defined(__BORLANDC__)	// BCB. BCB6是支持的.
	#if __BORLANDC__ >=0x0560	// BCB6
		#define __AUTO_STDINT_H_USESYS
	#endif	// #if __BORLANDC__ >=0x0560	// BCB6
#else
	/**
	 * Is the compiler exist `<stdint.h>` (编译器是否提供了`<stdint.h>`) ?
	 */
	#define __AUTO_STDINT_H_USESYS	// 假设其他编译器支持C99.
#endif	// __AUTO_STDINT_H_USESYS


#ifdef __AUTO_STDINT_H_USESYS
// 使用编译器提供的<stdint.h>
#include <stdint.h>

/// intmax_t bits.
#define AUTO_STDINT_INTMAX_BIT	64

#else
// 采用自定义的stdint.h. 参考了 msinttypes: http://code.google.com/p/msinttypes/
#ifndef _MSC_STDINT_H_ // [
#define _MSC_STDINT_H_

#include <limits.h>

// For Visual Studio 6 in C++ mode and for many Visual Studio versions when
// compiling for ARM we should wrap <wchar.h> include with 'extern "C++" {}'
// or compiler give many errors like this:
//   error C2733: second C linkage of overloaded function 'wmemchr' not allowed
//#ifdef __cplusplus
//extern "C" {
//#endif
//#  include <wchar.h>
//#ifdef __cplusplus
//}
//#endif
// <zyl910>: 在VC6下测试时, 发现上面的方法会报告很多C2733错误. 还是直接include算了.
#if defined(_MSC_VER)
#include <wchar.h>
#endif

// Define _W64 macros to mark types changing their size, like intptr_t.
#ifndef _W64
#  if !defined(__midl) && (defined(_X86_) || defined(_M_IX86)) && _MSC_VER >= 1300
#     define _W64 __w64
#  else
#     define _W64
#  endif
#endif


// 7.18.1 Integer types

// 7.18.1.1 Exact-width integer types

// Visual Studio 6 and Embedded Visual C++ 4 doesn't
// realize that, e.g. char has the same size as __int8
// so we give up on __intX for them.
#if defined(_MSC_VER) && _MSC_VER>=1300	// > VC7(2002)
   typedef signed __int8     int8_t;
   typedef signed __int16    int16_t;
   typedef signed __int32    int32_t;
   typedef unsigned __int8   uint8_t;
   typedef unsigned __int16  uint16_t;
   typedef unsigned __int32  uint32_t;
#else
   typedef signed char       int8_t;
   typedef signed short      int16_t;
   typedef unsigned char     uint8_t;
   typedef unsigned short    uint16_t;
#if INT_MAX <= 32767
   typedef signed long        int32_t;
   typedef unsigned long      uint32_t;
#else
   typedef signed int        int32_t;
   typedef unsigned int      uint32_t;
#endif
#endif

#ifdef _INTEGRAL_MAX_BITS
#define AUTO_STDINT_INTMAX_BIT	_INTEGRAL_MAX_BITS
#elif defined(_MSC_VER)
#define AUTO_STDINT_INTMAX_BIT	64
#else
#define AUTO_STDINT_INTMAX_BIT	32
#endif

#if (AUTO_STDINT_INTMAX_BIT >= 64)
#if defined(_MSC_VER)
typedef signed __int64       int64_t;
typedef unsigned __int64     uint64_t;
#else
typedef signed long long       int64_t;
typedef unsigned long long     uint64_t;
#endif
#endif

// 7.18.1.2 Minimum-width integer types
typedef int8_t    int_least8_t;
typedef int16_t   int_least16_t;
typedef int32_t   int_least32_t;
typedef uint8_t   uint_least8_t;
typedef uint16_t  uint_least16_t;
typedef uint32_t  uint_least32_t;
#if AUTO_STDINT_INTMAX_BIT >= 64
typedef int64_t   int_least64_t;
typedef uint64_t  uint_least64_t;
#endif

// 7.18.1.3 Fastest minimum-width integer types
typedef int8_t    int_fast8_t;
typedef int16_t   int_fast16_t;
typedef int32_t   int_fast32_t;
typedef uint8_t   uint_fast8_t;
typedef uint16_t  uint_fast16_t;
typedef uint32_t  uint_fast32_t;
#if AUTO_STDINT_INTMAX_BIT >= 64
typedef int64_t   int_fast64_t;
typedef uint64_t  uint_fast64_t;
#endif

// 7.18.1.4 Integer types capable of holding object pointers
#ifdef _WIN64 // [
   typedef signed __int64    intptr_t;
   typedef unsigned __int64  uintptr_t;
#else // _WIN64 ][
   typedef _W64 signed int   intptr_t;
   typedef _W64 unsigned int uintptr_t;
#endif // _WIN64 ]

// 7.18.1.5 Greatest-width integer types
#if AUTO_STDINT_INTMAX_BIT >= 64
typedef int64_t   intmax_t;
typedef uint64_t  uintmax_t;
#else
typedef int32_t   intmax_t;
typedef uint32_t  uintmax_t;
#endif


// 7.18.2 Limits of specified-width integer types

#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) // [   See footnote 220 at page 257 and footnote 221 at page 259

// 7.18.2.1 Limits of exact-width integer types
#if defined(_MSC_VER)	// VC.
#define INT8_MIN     ((int8_t)_I8_MIN)
#define INT8_MAX     _I8_MAX
#define INT16_MIN    ((int16_t)_I16_MIN)
#define INT16_MAX    _I16_MAX
#define INT32_MIN    ((int32_t)_I32_MIN)
#define INT32_MAX    _I32_MAX
#define UINT8_MAX    _UI8_MAX
#define UINT16_MAX   _UI16_MAX
#define UINT32_MAX   _UI32_MAX
#if AUTO_STDINT_INTMAX_BIT >= 64
#define INT64_MIN    ((int64_t)_I64_MIN)
#define INT64_MAX    _I64_MAX
#define UINT64_MAX   _UI64_MAX
#endif
#else
#define INT8_MIN     0
#define INT8_MAX     0x7F
#define UINT8_MAX    0xFFU
#define INT16_MIN    0
#define INT16_MAX    0x7FFF
#define UINT16_MAX   0xFFFFU
#define INT32_MIN    ((int32_t)0)
#if INT_MAX <= 0x7FFF
#define INT32_MAX    ((int32_t)0x7FFFFFFFL)
#define UINT32_MAX   ((int32_t)0xFFFFFFFFUL)
#else
#define INT32_MAX    ((int32_t)0x7FFFFFFF)
#define UINT32_MAX   ((int32_t)0xFFFFFFFFU)
#endif
#if AUTO_STDINT_INTMAX_BIT >= 64
#define INT64_MIN    ((int64_t)0)
#if LONG_MAX <= 0x7FFFFFFFL
#define INT64_MAX    ((int64_t)0x7FFFFFFFFFFFFFFFLL)
#define UINT64_MAX   ((int64_t)0xFFFFFFFFFFFFFFFFULL)
#else
#define INT64_MAX    ((int64_t)0x7FFFFFFFFFFFFFFFL)
#define UINT64_MAX   ((int64_t)0xFFFFFFFFFFFFFFFFUL)
#endif
#endif
#endif

// 7.18.2.2 Limits of minimum-width integer types
#define INT_LEAST8_MIN    INT8_MIN
#define INT_LEAST8_MAX    INT8_MAX
#define INT_LEAST16_MIN   INT16_MIN
#define INT_LEAST16_MAX   INT16_MAX
#define INT_LEAST32_MIN   INT32_MIN
#define INT_LEAST32_MAX   INT32_MAX
#define UINT_LEAST8_MAX   UINT8_MAX
#define UINT_LEAST16_MAX  UINT16_MAX
#define UINT_LEAST32_MAX  UINT32_MAX
#if AUTO_STDINT_INTMAX_BIT >= 64
#define INT_LEAST64_MIN   INT64_MIN
#define INT_LEAST64_MAX   INT64_MAX
#define UINT_LEAST64_MAX  UINT64_MAX
#endif

// 7.18.2.3 Limits of fastest minimum-width integer types
#define INT_FAST8_MIN    INT8_MIN
#define INT_FAST8_MAX    INT8_MAX
#define INT_FAST16_MIN   INT16_MIN
#define INT_FAST16_MAX   INT16_MAX
#define INT_FAST32_MIN   INT32_MIN
#define INT_FAST32_MAX   INT32_MAX
#define UINT_FAST8_MAX   UINT8_MAX
#define UINT_FAST16_MAX  UINT16_MAX
#define UINT_FAST32_MAX  UINT32_MAX
#if AUTO_STDINT_INTMAX_BIT >= 64
#define INT_FAST64_MIN   INT64_MIN
#define INT_FAST64_MAX   INT64_MAX
#define UINT_FAST64_MAX  UINT64_MAX
#endif

// 7.18.2.4 Limits of integer types capable of holding object pointers
#ifdef _WIN64 // [
#  define INTPTR_MIN   INT64_MIN
#  define INTPTR_MAX   INT64_MAX
#  define UINTPTR_MAX  UINT64_MAX
#else // _WIN64 ][
#  define INTPTR_MIN   INT_MIN
#  define INTPTR_MAX   INT_MAX
#  define UINTPTR_MAX  UINT_MAX
#endif // _WIN64 ]

// 7.18.2.5 Limits of greatest-width integer types
#if AUTO_STDINT_INTMAX_BIT >= 64
#define INTMAX_MIN   INT64_MIN
#define INTMAX_MAX   INT64_MAX
#define UINTMAX_MAX  UINT64_MAX
#else
#define INTMAX_MIN   INT32_MIN
#define INTMAX_MAX   INT32_MAX
#define UINTMAX_MAX  UINT32_MAX
#endif

// 7.18.3 Limits of other integer types

#define PTRDIFF_MIN  INTPTR_MIN
#define PTRDIFF_MAX  INTPTR_MAX

#define SIG_ATOMIC_MIN  INT_MIN
#define SIG_ATOMIC_MAX  INT_MAX

#ifndef SIZE_MAX // [
#  define SIZE_MAX  UINTPTR_MAX
#endif // SIZE_MAX ]

// WCHAR_MIN and WCHAR_MAX are also defined in <wchar.h>
//#ifndef WCHAR_MIN // [
//#  define WCHAR_MIN  0
//#endif  // WCHAR_MIN ]
//#ifndef WCHAR_MAX // [
//#  define WCHAR_MAX  _UI16_MAX
//#endif  // WCHAR_MAX ]

#if defined(WIN32)	// Win32 平台下的 wint_t 是16位的.
#  define WINT_MIN  0
#  define WINT_MAX  UINT16_MAX
#elif defined(WCHAR_MAX)
#  define WINT_MIN  WCHAR_MIN
#  define WINT_MAX  WCHAR_MAX
#else
#endif


#endif // __STDC_LIMIT_MACROS ]


// 7.18.4 Limits of other integer types

#if !defined(__cplusplus) || defined(__STDC_CONSTANT_MACROS) // [   See footnote 224 at page 260

// 7.18.4.1 Macros for minimum-width integer constants

#if defined(_MSC_VER)
#define INT8_C(val)  val##i8
#define INT16_C(val) val##i16
#define INT32_C(val) val##i32
#define INT64_C(val) val##i64

#define UINT8_C(val)  val##ui8
#define UINT16_C(val) val##ui16
#define UINT32_C(val) val##ui32
#define UINT64_C(val) val##ui64
#else
#define INT8_C(val)  val
#define INT16_C(val) val
#define UINT8_C(val)  val##U
#define UINT16_C(val) val##U
#if INT_MAX >= INT32_MAX
#define INT32_C(val) val
#define UINT32_C(val) val##U
#else
#define INT32_C(val) val##L
#define UINT32_C(val) val##UL
#endif	// #if LONG_MAX > INT32_MAX
#if AUTO_STDINT_INTMAX_BIT >= 64
#if LONG_MAX > INT32_MAX
#define INT64_C(val) val##L
#define UINT64_C(val) val##UL
#else
#define INT64_C(val) val##LL
#define UINT64_C(val) val##ULL
#endif	// #if LONG_MAX > INT32_MAX
#endif	// #if AUTO_STDINT_INTMAX_BIT >= 64
#endif

// 7.18.4.2 Macros for greatest-width integer constants
#if AUTO_STDINT_INTMAX_BIT >= 64
#define INTMAX_C   INT64_C
#define UINTMAX_C  UINT64_C
#else
#define INTMAX_C   INT32_C
#define UINTMAX_C  UINT32_C
#endif

#endif // __STDC_CONSTANT_MACROS ]


#endif // _MSC_STDINT_H_ ]

#endif // #ifdef __AUTO_STDINT_H_USESYS

#endif // #ifndef __AUTO_STDINT_H_INCLUDED


/** @} */	// @addtogroup GROUP_ZLSTDINT
/** @} */	// @addtogroup GROUP_ZYLLIBC
