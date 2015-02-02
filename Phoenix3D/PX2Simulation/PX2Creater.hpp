// PX2Creater.hpp

#ifndef PX2CREATER_HPP
#define PX2CREATER_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Object.hpp"
#include "PX2APoint.hpp"
#include "PX2Actor.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIText.hpp"
#include "PX2UIButton.hpp"
using namespace PX2;

namespace PX2
{

	class Scene;

	class Creater : public Singleton<Creater>
	{
	public:
		Creater();
		virtual ~Creater();

		Actor *CreateActor_Rectangle(Scene *scene, const APoint &pos);
		Actor *CreateActor_Box(Scene *scene, const APoint &pos);
		Actor *CreateActor_Sphere(Scene *scene, const APoint &pos);

		Movable *CreateRectangle(Node *parent, const APoint &pos, bool isPosWorld, bool doAdd=true);
		Movable *CreateBox(Node *parent, const APoint &pos, bool isPosWorld, bool doAdd = true);
		Movable *CreateSphere(Node *parent, const APoint &pos, bool isPosWorld, bool doAdd = true);

		UIFrame *CreateUIFrame(Node *parent, const APoint &pos, bool isPosWorld);
		UIPicBox *CreateUIPicBox(Node *parent, const APoint &pos, const std::string &filename, bool isPosWorld);
		UIPicBox *CreateUIPicBox(Node *parent, const APoint &pos, const std::string &texPack, const std::string &eleName, bool isPosWorld);
		UIText *CreateUIText(Node *parent, const APoint &pos, bool isPosWorld);
		UIButton *CreateUIButton(Node *parent, const APoint &pos, bool isPosWorld);

		void AddObject(Object *parent, Object *obj,
			bool command = true);
		bool RemoveObject(Object *obj, bool command = true);

	public:
		Actor *ConvertToActor(Object *obj);
		UIPicBox *ConvertToUIPicBox(Object *obj);
		UIFrame *ConvertToUIFrame(Object *obj);
	};

#define PX2_CREATER Creater::GetSingleton()

}

#endif