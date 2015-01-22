/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ConditionType.hpp
*
*/

#ifndef PX2CONDITIONTYPE_HPP
#define PX2CONDITIONTYPE_HPP

#include "PX2CorePre.hpp"

#if (defined(_WIN32) || defined(WIN32)) && !defined(PX2_USE_PTHREAD)
namespace PX2
{
	typedef void *ConditionType;
}
#elif defined(PX2_USE_PTHREAD)
#include <semaphore.h>
namespace PX2
{
	typedef sem_t ConditionType;
}
#endif

#endif
