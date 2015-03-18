// PX2Creater.cpp

#include "PX2Creater.hpp"
#include "PX2Actor.hpp"
#include "PX2EffectActor.hpp"
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
	Movable *mov = CreateRectangle(scene, APoint::ORIGIN, true, false);

	ActorPtr actor = new0 Actor();
	actor->SetMovable(mov);
	actor->LocalTransform.SetTranslate(pos);

	AddObject(scene, actor);

	return actor;
}
//----------------------------------------------------------------------------
Actor *Creater::CreateActor_Box(Scene *scene, const APoint &pos)
{
	Movable *mov = CreateBox(scene, APoint::ORIGIN, true, false);

	ActorPtr actor = new0 Actor();
	actor->SetMovable(mov);
	actor->LocalTransform.SetTranslate(pos);

	AddObject(scene, actor);

	return actor;
}
//----------------------------------------------------------------------------
Actor *Creater::CreateActor_Sphere(Scene *scene, const APoint &pos)
{
	Movable *mov = CreateSphere(scene, APoint::ORIGIN, true, false);

	ActorPtr actor = new0 Actor();
	actor->SetMovable(mov);
	actor->LocalTransform.SetTranslate(pos);

	AddObject(scene, actor);

	return actor;
}
//----------------------------------------------------------------------------
Actor *Creater::CreateActor_Effect(Scene *scene, const APoint &pos)
{
	ActorPtr actor = new0 EffectActor();
	actor->LocalTransform.SetTranslate(pos);

	AddObject(scene, actor);

	return actor;
}
//----------------------------------------------------------------------------
Character *Creater::CreateActor_Character(Scene *scene, const APoint &pos)
{
	CharacterPtr chara = new0 Character();
	chara->LocalTransform.SetTranslate(pos);

	AddObject(scene, chara);

	return chara;
}
//----------------------------------------------------------------------------
TriggerActor *Creater::CreateActor_Trigger(Scene *scene, const APoint &pos)
{
	TriggerActor *actor = new0 TriggerActor();
	actor->LocalTransform.SetTranslate(pos);

	AddObject(scene, actor);

	return actor;
}
//----------------------------------------------------------------------------
SkyActor *Creater::CreateActor_Sky(Scene *scene, const APoint &pos)
{
	SkyActor *actor = new0 SkyActor();
	actor->LocalTransform.SetTranslate(pos);

	AddObject(scene, actor);

	return actor;
}
//----------------------------------------------------------------------------
TerrainActor *Creater::CreateActor_Terrain(Scene *scene, const APoint &pos,
	const std::string &name, int terrainSize, int pageSize,
	float gridSpacing)
{
	TerrainActor *actor = new0 TerrainActor();
	actor->SetName(name);
	actor->LocalTransform.SetTranslate(pos);

	RawTerrain *rawTerrain = new0 RawTerrain();
	rawTerrain->SetName("RawTerrain");
	rawTerrain->SetSize(pageSize);
	int quantity = terrainSize / (pageSize - 1);
	rawTerrain->SetRowQuantity(quantity);
	rawTerrain->SetColQuantity(quantity);
	rawTerrain->SetSpacing(gridSpacing);
	rawTerrain->AllocateRawTerrainPages();

	actor->SetRawTerrain(rawTerrain);

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

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PNT1);

	StandardMesh stdMesh(vf);
	TriMesh *mesh = stdMesh.Rectangle(2, 2, 1.0f, 1.0f, Float2(0.5f, 0.5f));
	mesh->SetName("NoName");

	MaterialInstance *mi = new0 MaterialInstance(
		"Data/engine_mtls/std/std.px2obj", "std_lightshadow", false);
	mesh->SetMaterialInstance(mi);

	mi->SetPixelTexture(0, "SampleBase", tex);

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

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PNT1);

	StandardMesh stdMesh(vf);
	Node *meshNode = stdMesh.BoxPieces(2, 1);
	meshNode->SetName("NoName");

	for (int i = 0; i < meshNode->GetNumChildren(); i++)
	{
		TriMesh *mesh = DynamicCast<TriMesh>(meshNode->GetChild(i));

		if (mesh)
		{
			MaterialInstance *mi = new0 MaterialInstance(
				"Data/engine_mtls/std/std.px2obj", "std_lightshadow", false);
			mesh->SetMaterialInstance(mi);

			mi->SetPixelTexture(0, "SampleBase", tex);
		}
	}

	meshNode->LocalTransform.SetTranslate(localPos);

	if (doAdd)
		AddObject(parent, meshNode);

	return meshNode;
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

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PNT1);

	StandardMesh stdMesh(vf);
	TriMesh *mesh = stdMesh.Sphere(32, 32, 1);
	mesh->SetName("NoName");

	MaterialInstance *mi = new0 MaterialInstance(
		"Data/engine_mtls/std/std.px2obj", "std_lightshadow", false);
	mesh->SetMaterialInstance(mi);

	mi->SetPixelTexture(0, "SampleBase", tex);

	mesh->LocalTransform.SetTranslate(localPos);

	if (doAdd)
		AddObject(parent, mesh);

	return mesh;
}
//----------------------------------------------------------------------------
Movable *Creater::CreateTerrainPage(PX2::Terrain *terrain, int indexRow, 
	int indexCol)
{
	RawTerrain *rawTerrain = DynamicCast<RawTerrain>(terrain);
	if (rawTerrain)
	{
		RawTerrainPage *terrainPage = rawTerrain->CreatePage(indexRow, indexCol);
		AddObject(rawTerrain, terrainPage);

		return terrainPage;
	}

	return 0;
}
//----------------------------------------------------------------------------
UIFrame *Creater::CreateUIFrame(Node *parent, const APoint &pos,
	bool isPosWorld, bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	UIFrame *frame = new0 UIFrame();
	frame->LocalTransform.SetTranslate(localPos);

	AddObject(parent, frame);

	return frame;
}
//----------------------------------------------------------------------------
UIPicBox *Creater::CreateUIPicBox(Node *parent, const APoint &pos, 
	const std::string &filename, bool isPosWorld, bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

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
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	UIPicBox *picBox = new0 UIPicBox(texPack, eleName, false);
	picBox->LocalTransform.SetTranslate(localPos);

	AddObject(parent, picBox);

	return picBox;
}
//----------------------------------------------------------------------------
UIText *Creater::CreateUIText(Node *parent, const APoint &pos, 
	bool isPosWorld, bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	UIText *text = new0 UIText();
	text->LocalTransform.SetTranslate(localPos);

	AddObject(parent, text);

	return text;
}
//----------------------------------------------------------------------------
UIButton *Creater::CreateUIButton(Node *parent, const APoint &pos, 
	bool isPosWorld, bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	UIButton *but = new0 UIButton();
	but->LocalTransform.SetTranslate(localPos);

	AddObject(parent, but);

	return but;
}
//----------------------------------------------------------------------------
UICheckButton *Creater::CreateUICheckButton(Node *parent, const APoint &pos, 
	bool isPosWorld, bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	UICheckButton *checkButton = new0 UICheckButton();
	checkButton->LocalTransform.SetTranslate(localPos);

	AddObject(parent, checkButton);

	return checkButton;
}
//----------------------------------------------------------------------------
UIEditBox *Creater::CreateUIEditBox(Node *parent, const APoint &pos, bool isPosWorld,
	bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	UIEditBox *editBox = new0 UIEditBox();
	editBox->LocalTransform.SetTranslate(localPos);

	AddObject(parent, editBox);

	return editBox;
}
//----------------------------------------------------------------------------
UIProgressBar *Creater::CreateUIProgressBar(Node *parent, const APoint &pos,
	bool isPosWorld, bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	UIProgressBar *progBar = new0 UIProgressBar();
	progBar->LocalTransform.SetTranslate(localPos);

	AddObject(parent, progBar);

	return progBar;
}
//----------------------------------------------------------------------------
ParticleEmitter *Creater::CreateParticleEmitter(Node *parent,
	const APoint &pos, bool isPosWorld, bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	ParticleEmitter *mov = new0 ParticleEmitter();
	mov->LocalTransform.SetTranslate(localPos);

	AddObject(parent, mov);

	return mov;

}
//----------------------------------------------------------------------------
Billboard *Creater::CreateBillboard(Node *parent,
	const APoint &pos, bool isPosWorld, bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	Billboard *mov = new0 Billboard();
	mov->LocalTransform.SetTranslate(localPos);

	AddObject(parent, mov);

	return mov;
}
//----------------------------------------------------------------------------
BeamEmitter *Creater::CreateBeamEmitter(Node *parent,
	const APoint &pos, bool isPosWorld, bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	BeamEmitter *mov = new0 BeamEmitter();
	mov->LocalTransform.SetTranslate(localPos);

	AddObject(parent, mov);

	return mov;
}
//----------------------------------------------------------------------------
RibbonEmitter *Creater::CreateRibbonEmitter(Node *parent,
	const APoint &pos, bool isPosWorld, bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	RibbonEmitter *mov = new0 RibbonEmitter();
	mov->LocalTransform.SetTranslate(localPos);

	AddObject(parent, mov);

	return mov;
}
//----------------------------------------------------------------------------
Soundable *Creater::CreateSoundable(Node *parent, const APoint &pos, 
	bool isPosWorld, bool usePickPos)
{
	APoint localPos = _LocalPosCal(parent, pos, isPosWorld, usePickPos);

	Soundable *mov = new0 Soundable();
	mov->LocalTransform.SetTranslate(localPos);

	AddObject(parent, mov);

	return mov;
}
//----------------------------------------------------------------------------
Actor *Creater::AddActor(Scene *scene, const std::string &resPath,
	const APoint &pos)
{
	Movable *mov = DynamicCast<Movable>(PX2_RM.BlockLoad(resPath));
	if (mov)
	{
		Actor *actor = new0 Actor();
		actor->SetMovableFilename(resPath);
		actor->LocalTransform.SetTranslate(pos);

		AddObject(scene, actor);

		return actor;
	}

	return 0;
}
//----------------------------------------------------------------------------
Character *Creater::AddCharacter(Scene *scene, const std::string &resPath,
	const APoint &pos)
{
	Movable *mov = DynamicCast<Movable>(PX2_RM.BlockLoad(resPath));
	if (mov)
	{
		Character *chara = new0 Character();
		chara->SetMovableFilename(resPath);
		chara->LocalTransform.SetTranslate(pos);

		AddObject(scene, chara);

		return chara;
	}

	return 0;
}
//----------------------------------------------------------------------------
EffectActor *Creater::AddEffectActor(Scene *scene, const std::string &resPath,
	const APoint &pos)
{
	Movable *mov = DynamicCast<Movable>(PX2_RM.BlockLoad(resPath));
	if (mov)
	{
		EffectActor *ea = new0 EffectActor();
		ea->SetMovableFilename(resPath);
		ea->LocalTransform.SetTranslate(pos);

		AddObject(scene, ea);

		return ea;
	}

	return 0;
}
//----------------------------------------------------------------------------
APoint Creater::_LocalPosCal(Node *parent, const APoint &pos,
	bool isPosWorld, bool usePickPos)
{
	APoint localPos = pos;

	if (parent && isPosWorld)
	{
		localPos = parent->WorldTransform.Inverse() * localPos;
	}

	if (!usePickPos)
		localPos = APoint::ORIGIN;

	return localPos;
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
			int ret = parent->DetachChild(mov);
			
			if (-1 != ret)
			{
				removed = true;
			}
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