// PX2Creater.hpp

#ifndef PX2CREATER_HPP
#define PX2CREATER_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Object.hpp"
#include "PX2APoint.hpp"
#include "PX2Actor.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIRelativeFrame.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIText.hpp"
#include "PX2UIButton.hpp"
#include "PX2UIEditBox.hpp"
#include "PX2UICheckButton.hpp"
#include "PX2UIProgressBar.hpp"
#include "PX2ParticleEmitter.hpp"
#include "PX2Billboard.hpp"
#include "PX2BeamEmitter.hpp"
#include "PX2RibbonEmitter.hpp"
#include "PX2Soundable.hpp"
#include "PX2Character.hpp"
#include "PX2EffectActor.hpp"
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
		Actor *CreateActor_Effect(Scene *scene, const APoint &pos);
		Character *CreateActor_Character(Scene *scene, const APoint &pos);

		Movable *CreateRectangle(Node *parent, const APoint &pos, bool isPosWorld, 
			bool doAdd=true, bool usePickPos=true);
		Movable *CreateBox(Node *parent, const APoint &pos, bool isPosWorld, 
			bool doAdd = true, bool usePickPos = true);
		Movable *CreateSphere(Node *parent, const APoint &pos, bool isPosWorld,
			bool doAdd = true, bool usePickPos = true);

		UIFrame *CreateUIFrame(Node *parent, const APoint &pos, bool isPosWorld,
			bool usePickPos);
		UIRelativeFrame *CreateUIRelativeFrame(Node *parent, const APoint &pos, bool isPosWorld,
			bool usePickPos);
		UIPicBox *CreateUIPicBox(Node *parent, const APoint &pos, const std::string &filename,
			bool isPosWorld, bool usePickPos);
		UIPicBox *CreateUIPicBox(Node *parent, const APoint &pos, const std::string &texPack,
			const std::string &eleName, bool isPosWorld, bool usePickPos);
		UIText *CreateUIText(Node *parent, const APoint &pos, bool isPosWorld, 
			bool usePickPos);
		UIButton *CreateUIButton(Node *parent, const APoint &pos, bool isPosWorld,
			bool usePickPos);
		UICheckButton *CreateUICheckButton(Node *parent, const APoint &pos, bool isPosWorld,
			bool usePickPos);
		UIEditBox *CreateUIEditBox(Node *parent, const APoint &pos, bool isPosWorld,
			bool usePickPos);
		UIProgressBar *CreateUIProgressBar(Node *parent, const APoint &pos, bool isPosWorld,
			bool usePickPos);

		ParticleEmitter *CreateParticleEmitter(Node *parent, const APoint &pos, bool isPosWorld,
			bool usePickPos);
		Billboard *CreateBillboard(Node *parent, const APoint &pos, bool isPosWorld,
			bool usePickPos);
		BeamEmitter *CreateBeamEmitter(Node *parent, const APoint &pos, bool isPosWorld,
			bool usePickPos);
		RibbonEmitter *CreateRibbonEmitter(Node *parent, const APoint &pos, bool isPosWorld,
			bool usePickPos);
		Soundable *CreateSoundable(Node *parent, const APoint &pos, bool isPosWorld,
			bool usePickPos);

		Actor *AddActor(Scene *scene, const std::string &resPath, const APoint &pos);
		Character *AddCharacter(Scene *scene, const std::string &resPath, const APoint &pos);
		EffectActor *AddEffectActor(Scene *scene, const std::string &resPath, const APoint &pos);

		void AddObject(Object *parent, Object *obj,
			bool command = true);
		bool RemoveObject(Object *obj, bool command = true);

	protected:
		APoint _LocalPosCal(Node *parent, const APoint &pos,
			bool isPosWorld, bool usePickPos);

	public:
		Node *ConvertToNode(Object *obj);
		Actor *ConvertToActor(Object *obj);
		UIPicBox *ConvertToUIPicBox(Object *obj);
		UIFrame *ConvertToUIFrame(Object *obj);
	};

#define PX2_CREATER Creater::GetSingleton()

}

#endif