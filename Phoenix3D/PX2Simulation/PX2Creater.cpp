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
Actor *Creater::CreateActor_Rectangle(Scene *scene, const APoint &pos)
{
	Movable *mov = CreateRectangle(scene, pos, true, false);

	ActorPtr actor = new0 Actor();
	actor->SetName("NoName");
	actor->SetMovable(mov);
	actor->LocalTransform.SetTranslate(pos);

	AddObject(scene, actor);

	return actor;
}
//----------------------------------------------------------------------------
Actor *Creater::CreateActor_Box(Scene *scene, const APoint &pos)
{
	Movable *mov = CreateBox(scene, pos, true, false);

	ActorPtr actor = new0 Actor();
	actor->SetName("NoName");
	actor->SetMovable(mov);
	actor->LocalTransform.SetTranslate(pos);

	AddObject(scene, actor);

	return actor;
}
//----------------------------------------------------------------------------
Actor *Creater::CreateActor_Sphere(Scene *scene, const APoint &pos)
{
	Movable *mov = CreateSphere(scene, pos, true, false);

	ActorPtr actor = new0 Actor();
	actor->SetName("NoName");
	actor->SetMovable(mov);
	actor->LocalTransform.SetTranslate(pos);

	AddObject(scene, actor);

	return actor;
}
//----------------------------------------------------------------------------
Movable *Creater::CreateRectangle(Node *parent, const APoint &pos,
	bool isPosWorld, bool doAdd, bool usePickPos)
{
	APoint localPos = pos;

	if (parent && isPosWorld)
	{
		localPos = parent->WorldTransform.Inverse() * localPos;
	}

	if (!usePickPos)
		localPos = APoint::ORIGIN;

	Texture2D *tex = DynamicCast<Texture2D>(PX2_RM.BlockLoad(
		"Data/engine/default.png"));
	if (!tex) return 0;

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PT1);

	StandardMesh stdMesh(vf);
	TriMesh *mesh = stdMesh.Rectangle(2, 2, 1.0f, 1.0f, Float2(0.5f, 0.5f));
	mesh->SetName("NoName");

	StdMaterialPtr mtl = new0 StdMaterial();
	mesh->SetMaterialInstance(mtl->CreateInstance(tex, mesh->GetShine(), 0));

	mesh->LocalTransform.SetTranslate(localPos);

	if (doAdd)
		AddObject(parent, mesh);

	return mesh;
}
//----------------------------------------------------------------------------
Movable *Creater::CreateBox(Node *parent, const APoint &pos, bool isPosWorld,
	bool doAdd, bool usePickPos)
{
	APoint localPos = pos;

	if (parent && isPosWorld)
	{
		localPos = parent->WorldTransform.Inverse() * localPos;
	}

	if (!usePickPos)
		localPos = APoint::ORIGIN;

	Texture2D *tex = DynamicCast<Texture2D>(PX2_RM.BlockLoad(
		"Data/engine/default.png"));
	if (!tex) return 0;

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PT1);

	StandardMesh stdMesh(vf);
	TriMesh *mesh = stdMesh.Box(1, 1, 1);
	mesh->SetName("NoName");

	StdMaterialPtr mtl = new0 StdMaterial();
	mesh->SetMaterialInstance(mtl->CreateInstance(tex, mesh->GetShine(), 0));

	mesh->LocalTransform.SetTranslate(localPos);

	if (doAdd)
		AddObject(parent, mesh);

	return mesh;
}
//----------------------------------------------------------------------------
Movable *Creater::CreateSphere(Node *parent, const APoint &pos, 
	bool isPosWorld, bool doAdd, bool usePickPos)
{
	APoint localPos = pos;

	if (parent && isPosWorld)
	{
		localPos = parent->WorldTransform.Inverse() * localPos;
	}

	if (!usePickPos)
		localPos = APoint::ORIGIN;

	Texture2D *tex = DynamicCast<Texture2D>(PX2_RM.BlockLoad(
		"Data/engine/default.png"));
	if (!tex) return 0;

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PT1);

	StandardMesh stdMesh(vf);
	TriMesh *mesh = stdMesh.Sphere(32, 32, 1);
	mesh->SetName("NoName");

	StdMaterialPtr mtl = new0 StdMaterial();
	mesh->SetMaterialInstance(mtl->CreateInstance(tex, mesh->GetShine(), 0));

	mesh->LocalTransform.SetTranslate(localPos);

	if (doAdd)
		AddObject(parent, mesh);

	return mesh;
}
//----------------------------------------------------------------------------
UIFrame *Creater::CreateUIFrame(Node *parent, const APoint &pos,
	bool isPosWorld, bool usePickPos)
{
	APoint localPos = pos;

	if (parent && isPosWorld)
	{
		localPos = parent->WorldTransform.Inverse() * localPos;
	}

	if (!usePickPos)
		localPos = APoint::ORIGIN;

	UIFrame *frame = new0 UIFrame();
	frame->LocalTransform.SetTranslate(localPos);

	AddObject(parent, frame);

	return frame;
}
//----------------------------------------------------------------------------
UIPicBox *Creater::CreateUIPicBox(Node *parent, const APoint &pos, 
	const std::string &filename, bool isPosWorld, bool usePickPos)
{
	APoint localPos = pos;

	if (parent && isPosWorld)
	{
		localPos = parent->WorldTransform.Inverse() * localPos;
	}

	if (!usePickPos)
		localPos = APoint::ORIGIN;

	UIPicBox *picBox = new0 UIPicBox(filename);
	picBox->LocalTransform.SetTranslate(localPos);

	AddObject(parent, picBox);

	return picBox;
}
//----------------------------------------------------------------------------
UIPicBox *Creater::CreateUIPicBox(Node *parent, const APoint &pos,
	const std::string &texPack, const std::string &eleName, bool isPosWorld,
	bool usePickPos)
{
	APoint localPos = pos;

	if (parent && isPosWorld)
	{
		localPos = parent->WorldTransform.Inverse() * localPos;
	}

	if (!usePickPos)
		localPos = APoint::ORIGIN;

	UIPicBox *picBox = new0 UIPicBox(texPack, eleName);
	picBox->LocalTransform.SetTranslate(localPos);

	AddObject(parent, picBox);

	return picBox;
}
//----------------------------------------------------------------------------
UIText *Creater::CreateUIText(Node *parent, const APoint &pos, 
	bool isPosWorld, bool usePickPos)
{
	APoint localPos = pos;

	if (parent && isPosWorld)
	{
		localPos = parent->WorldTransform.Inverse() * localPos;
	}

	if (!usePickPos)
		localPos = APoint::ORIGIN;

	UIText *text = new0 UIText();
	text->LocalTransform.SetTranslate(localPos);

	AddObject(parent, text);

	return text;
}
//----------------------------------------------------------------------------
UIButton *Creater::CreateUIButton(Node *parent, const APoint &pos, 
	bool isPosWorld, bool usePickPos)
{
	APoint localPos = pos;

	if (parent && isPosWorld)
	{
		localPos = parent->WorldTransform.Inverse() * localPos;
	}

	if (!usePickPos)
		localPos = APoint::ORIGIN;

	UIButton *but = new0 UIButton();
	but->LocalTransform.SetTranslate(localPos);

	AddObject(parent, but);

	return but;
}
//----------------------------------------------------------------------------
void Creater::AddObject(Object *parent, Object *obj, bool command)
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
bool Creater::RemoveObject(Object *obj, bool command)
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
Node *Creater::ConvertToNode(Object *obj)
{
	return DynamicCast<Node>(obj);
}
//----------------------------------------------------------------------------
Actor *Creater::ConvertToActor(Object *obj)
{
	return DynamicCast<Actor>(obj);
}
//----------------------------------------------------------------------------
UIPicBox *Creater::ConvertToUIPicBox(Object *obj)
{
	return DynamicCast<UIPicBox>(obj);
}
//----------------------------------------------------------------------------
UIFrame *Creater::ConvertToUIFrame(Object *obj)
{
	return DynamicCast<UIFrame>(obj);
}
//----------------------------------------------------------------------------