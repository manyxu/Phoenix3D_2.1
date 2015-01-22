// PX2Creater.hpp

#ifndef PX2CREATER_HPP
#define PX2CREATER_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Object.hpp"
using namespace PX2;

namespace PX2
{

	class Creater : public Singleton<Creater>
	{
	public:
		Creater();
		virtual ~Creater();

		void AddObject(PX2::Object *parent, PX2::Object *obj,
			bool command = true);
		bool RemoveObject(PX2::Object *obj, bool command = true);
	};

#define PX2_CREATER Creater::GetSingleton()

}

#endif