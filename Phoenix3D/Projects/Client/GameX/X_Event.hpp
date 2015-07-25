// X_Event.hpp

#ifndef X_EVENT_HPP
#define X_EVENT_HPP

#include "PX2EventSystem.hpp"
#include "PX2EventSpace.hpp"
#include "PX2Event.hpp"

namespace PX2
{

	PX2_DECLARE_EVENT_BEGIN(X_EventSpace)

	PX2_EVENT(Show_SplashOver)
	PX2_EVENT(EnterMap)

	PX2_DECLARE_EVENT_END(X_EventSpace)

	struct MoveDistData
	{
		MoveDistData()
		{
			ID = 0;
			Time = 0.0f;
			Dist = 0.0f;
		}
		~MoveDistData()
		{
		}

		int ID;
		float Time;
		float Dist;
	};

}

#endif