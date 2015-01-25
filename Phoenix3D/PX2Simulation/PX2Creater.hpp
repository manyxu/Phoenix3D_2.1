// PX2Creater.hpp

#ifndef PX2CREATER_HPP
#define PX2CREATER_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Object.hpp"
#include "PX2APoint.hpp"
#include "PX2Actor.hpp"
using namespace PX2;

namespace PX2
{

	class Scene;

	class Creater : public Singleton<Creater>
	{
	public:
		Creater();
		virtual ~Creater();

		Actor *CreateActor_Box(Scene *scene, const PX2::APoint &pos);

		void AddObject(PX2::Object *parent, PX2::Object *obj,
			bool command = true);
		bool RemoveObject(PX2::Object *obj, bool command = true);
	};

#define PX2_CREATER Creater::GetSingleton()

}

#endif