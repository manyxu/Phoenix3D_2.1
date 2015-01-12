/*
*
* 文件名称	：	PX2CorePre.hpp
*
*/

#ifndef PX2COREPRE_HPP
#define PX2COREPRE_HPP

//----------------------------------------------------------------------------
// 平台信息.下面的宏对平台进行控制.
// _WIN32 or WIN32  :  Microsoft Windows
// __APPLE__        :  Macintosh OS X
// __LINUX__        :  Linux
// __ANDROID__		:  Android
// __IOS__          :  IOS
//----------------------------------------------------------------------------
// Microsoft Windows
//----------------------------------------------------------------------------
#if defined(_WIN32) || defined(WIN32)

#ifndef _WIN32
#define _WIN32
#endif

#ifndef WIN32
#define WIN32
#endif

#define PX2_LITTLE_ENDIAN

#if defined(_MSC_VER)

// MSVC6版本为12.00；MSVC7.0为13.00； MSVC7.1为13.10，MSVC8.0为14.00；MSVC9.0
// 为15.00，MSVC10.0为16.00当前支持MSVC8.0及其后期版本.
#if _MSC_VER < 1400
#error 需要使用MSVC 8.0或者后期版本
#elif _MSC_VER == 1500
#define PX2_USING_VC80
#elif _MSC_VER == 1600
#define PX2_USING_VC90
#else
#define PX2_USING_VC100
#endif

#pragma warning(disable : 4996)
#pragma warning(disable : 4311)

#include <climits>
#include <stdint.h>

#endif

#endif
//----------------------------------------------------------------------------
// Macintosh OS X
//----------------------------------------------------------------------------
#if defined(__APPLE__)

#if defined(__BIG_ENDIAN__)
#define PX2_BIG_ENDIAN
#else
#define PX2_LITTLE_ENDIAN
#endif

#define PX2_USE_PTHREAD
#endif
//----------------------------------------------------------------------------
// Linux
//----------------------------------------------------------------------------
#if defined(__LINUX__)

#include <inttypes.h>

#define PX2_LITTLE_ENDIAN
#define PX2_USE_PTHREAD
#endif
//----------------------------------------------------------------------------
// Android
//----------------------------------------------------------------------------
#if defined(__ANDROID__)

#include <inttypes.h>

#define PX2_LITTLE_ENDIAN
#define PX2_USE_PTHREAD
#endif

//----------------------------------------------------------------------------
// IOS
//----------------------------------------------------------------------------
#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) || defined(__IPHONE_OS_VERSION_MIN_REQUIRED)

#ifndef __IOS__
#define __IOS__
#endif

#endif
//----------------------------------------------------------------------------



// 常用标准头文件
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#ifdef PX2_USE_PTHREAD
#include <pthread.h>
#endif

// STL
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <bitset>

// int64
#define PX2_HAVE_INT64 1

// 用户自定义关键字
#define public_internal public
#define protected_internal protected
#define private_internal private

// 阻止未使用变量产生的警告.在Debug下会产生警告，需要者这个宏消除警告；
// 在Release下不会产生警告.
#define PX2_UNUSED(variable) (void)variable

// 这些宏用来激活各种断言系统.
// 注意：当前只对Microsoft Visual Studio进行了支持.
#ifdef _DEBUG
	#if defined(WIN32) && defined(_MSC_VER)
		#define PX2_USE_ASSERT
		#ifdef PX2_USE_ASSERT
			#define PX2_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW	// 将断言写入调试窗口
			#define PX2_USE_ASSERT_WRITE_TO_MESSAGE_BOX		// 将断言写入MessageBox	
		#endif
	#endif
	#define PX2_USE_ASSERT_LOG_TO_FILE
#endif

// 用来进行内存管理的宏
#ifdef _DEBUG

	#define PX2_USE_MEMORY // 使用Phoenix的内存管理机制

	#ifdef PX2_USE_MEMORY
		// 当在main函数之前分配内存或者再main退出之后释放内存，触发宏
		#define PX2_USE_MEMORY_ASSERT_ON_PREMAIN_POSTMAIN_OPERATIONS

		// 如果指针指向的内存不是由Phoenix内存管理机制分配的，内存管理函数
		// delete0，delete1，delete2，和delete3的调用会引发断言。如果使用此宏，
		// 会使用c++标准'delete'或者'delete[]'释放由'new','new[]'分配的内存。
		#define PX2_USE_MEMORY_ALLOW_DELETE_ON_FAILED_MAP_LOOKUP
	#endif
#endif

// FileIO和BufferIO
#ifdef _DEBUG
#define PX2_FILEIO_VALIDATE_OPERATION		// 检测文件操作的正确性
#define PX2_BUFFERIO_VALIDATE_OPERATION		// 检测内存操作的正确性
#endif

#define SMART_POINTER_USEMUTEX

#endif