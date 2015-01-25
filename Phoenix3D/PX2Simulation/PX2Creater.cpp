// PX2Creater.cpp

#include "PX2Creater.hpp"
#include "PX2Actor.hpp"
#include "PX2Scene.hpp"
#include "PX2Controller.hpp"
#include "PX2Animation.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2RedoUndo.hpp"
#include "PX2Project.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Creater::Creater()
{
}
//----------------------------------------------------------------------------
Creater::~Creater()
{
}
//----------------------------------------------------------------------------
Actor *Creater::CreateActor_Box(Scene *scene, const PX2::APoint &pos)
{
	PX2::Texture2D *tex = DynamicCast<PX2::Texture2D>(PX2_RM.BlockLoad("Data/engine/default.png"));
	if (!tex) return 0;

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PT1);

	StandardMesh stdMesh(vf);
	TriMesh *mesh = stdMesh.Box(1, 1, 1);
	mesh->SetName("NoName");

	StdMaterialPtr mtl = new0 StdMaterial();
	mesh->SetMaterialInstance(mtl->CreateInstance(tex, mesh->GetShine(), 0));

	ActorPtr actor = new0 Actor();
	actor->SetName("NoName");
	actor->SetMovable(mesh);
	actor->LocalTransform.SetTranslate(pos);

	AddObject(scene, actor);

	return actor;
}
//----------------------------------------------------------------------------
void Creater::AddObject(PX2::Object *parent, PX2::Object *obj, bool command)
{
	Movable *mov = DynamicCast<Movable>(obj);
	Controller *ctrl = DynamicCast<Controller>(obj);

	Node *nodePar = DynamicCast<Node>(parent);
	Controlledable *ctrlablePar = DynamicCast<Controlledable>(parent);

	bool added = false;

	//else if (character && anim3d)
	//{
	//	character->AddAnim(anim3d);

	//	added = true;
	//}
	if (mov && nodePar)
	{
		nodePar->AttachChild(mov);

		added = true;
	}
	else if (ctrlablePar && ctrl)
	{
		ctrlablePar->AttachController(ctrl);

		added = true;
	}

	if (added)
	{
		Event *ent = SimuES_E::CreateEventX(SimuES_E::AddObject);
		ent->SetData<Object*>(obj);
		EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
	}

	if (added && command)
	{
		ObjectAddDeleteURDo *cmd = new0 ObjectAddDeleteURDo(true, obj);
		PX2_URDOMAN.PushUnDo(cmd);
	}
}
//----------------------------------------------------------------------------
bool Creater::RemoveObject(PX2::Object *obj, bool command)
{
	Movable *mov = DynamicCast<Movable>(obj);
	Controller *ctrl = DynamicCast<Controller>(obj);
	//EffectModule *module = DynamicCast<EffectModule>(obj);
	Animation *anim = DynamicCast<Animation>(obj);

	EditCommandPtr theCommand = new0 ObjectAddDeleteURDo(false, obj);

	bool removed = false;

	if (anim)
	{
		//Character *chara = anim->GetCharacter();
		//if (chara)
		//{
		//	chara->RemoveAnim(anim);

		//	removed = true;
		//}
	}
	else if (mov)
	{
		Node *parent = DynamicCast<Node>(mov->GetParent());
		if (parent)
		{
			parent->DetachChild(mov);

			removed = true;
		}
	}
	else if (ctrl)
	{
		Controlledable *ctrlAble = ctrl->GetControlledable();
		ctrlAble->DetachController(ctrl);

		removed = true;
	}
	//else if (module)
	//{
	//	EffectableController *effCtrl = module->GetEffectableController();
	//	effCtrl->RemoveModule(module);

	//	removed = true;
	//}

	if (removed)
	{
		Event *ent = 0;
		ent = SimuES_E::CreateEventX(SimuES_E::RemoveObject);
		ent->SetData<Object*>(obj);
		EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
	}

	if (removed && command)
	{
		PX2_URDOMAN.PushUnDo(theCommand);
	}

	return true;
}
//----------------------------------------------------------------------------