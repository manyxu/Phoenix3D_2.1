/*
*
* 文件名称	：	PX2ThreadType.hpp
*
*/

#ifndef PX2THREADTYPE_HPP
#define PX2THREADTYPE_HPP

#include "PX2CorePre.hpp"

#if (defined(_WIN32) || defined(WIN32)) && !defined(PX2_USE_PTHREAD)
//----------------------------------------------------------------------------
// 在Windows中，Mutex是一个HANDLE，需要包含<windows.h>，这样会暴露大量
// Windows接口。所以我们用void*代替HANDLE。
//----------------------------------------------------------------------------
namespace PX2
{
	typedef void* ThreadType;
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
	typedef pthread_t ThreadType;
}
//----------------------------------------------------------------------------
#else
//----------------------------------------------------------------------------
// 其他平台的线程没有支持
//----------------------------------------------------------------------------
#error Other platforms not yet implemented.
#endif

#endif
