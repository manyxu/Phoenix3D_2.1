// PX2ActorPickRecord.hpp

#ifndef PX2ACTORPICKRECORD_HPP
#define PX2ACTORPICKRECORD_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Actor.hpp"

namespace PX2
{

	class ActorPickRecord
	{
	public:
		ActorPickRecord()
		{
			T = 0.0f;
		}

		~ActorPickRecord()
		{
		}

		ActorPtr Intersected;

		// 射线P + t*D中的线性元素量。T是其中t的表示。
		float T;
	};

}

#endif