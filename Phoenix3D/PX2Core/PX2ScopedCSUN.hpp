/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ScopedCSUN.hpp
*
*/

#ifndef PX2SCOPEDCSUN_HPP
#define PX2SCOPEDCSUN_HPP

#include "PX2CorePre.hpp"
#include "PX2Mutex.hpp"

namespace PX2
{

	class ScopedCSUN
	{
	public:
		ScopedCSUN (Mutex* mutex, bool unlockNow=true);
		~ScopedCSUN ();

	private:
		ScopedCSUN();
		ScopedCSUN(const ScopedCSUN&);
		ScopedCSUN& operator = (const ScopedCSUN&);

		Mutex* mMutex;
	};

}

#endif