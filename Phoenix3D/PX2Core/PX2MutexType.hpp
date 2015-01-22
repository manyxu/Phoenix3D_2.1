/*
* Phoenix 3D 引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2MutexType.hpp
*
* 版本		:	1.0 (2011/01/29)
*
* 作者		：	more
*
*/

#ifndef PX2MUTEXTYPE_HPP
#define PX2MUTEXTYPE_HPP

#include "PX2CorePre.hpp"

#if (defined(_WIN32) || defined(WIN32)) && !defined(PX2_USE_PTHREAD)
//----------------------------------------------------------------------------
// 在Windows中，Mutex是一个HANDLE，需要包含<windows.h>，这样会暴露大量
// Windows接口。所以我们用void*代替HANDLE。
//----------------------------------------------------------------------------
namespace PX2
{
	typedef void* MutexType;
}
//----------------------------------------------------------------------------
#elif defined(PX2_USE_PTHREAD)
//----------------------------------------------------------------------------
// 在Linux/Apple中，pthread.h里面仅仅是原始类型数据，包含pthread.h不会暴露
// 额外的接口。
//----------------------------------------------------------------------------
#include <pthread.h>
namespace PX2
{
	typedef struct
	{
		pthread_mutexattr_t Attribute;
		pthread_mutex_t Mutex;
	}
	MutexType;
}
#else
//----------------------------------------------------------------------------
// 其他平台的线程没有支持
//----------------------------------------------------------------------------
#error Other platforms not yet implemented.
#endif

#endif
