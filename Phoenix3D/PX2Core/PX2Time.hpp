// PX2Time.hpp

#ifndef PX2TIME_H
#define PX2TIME_H

#include "PX2CorePre.hpp"

namespace PX2
{

	class PX2_CORE_ITEM Time
	{
	public:
		static double GetTimeInMicroseconds();
		static double GetTimeInSeconds();
		static void ResetTime();
	};

}

#endif
