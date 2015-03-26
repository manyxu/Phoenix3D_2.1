// PX2LightActor.cpp

#include "PX2LightActor.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2Scene.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, LightActor);
PX2_IMPLEMENT_STREAM(LightActor);
PX2_IMPLEMENT_FACTORY(LightActor);
PX2_IMPLEMENT_DEFAULT_NAMES(Actor, LightActor);

//----------------------------------------------------------------------------
LightActor::LightActor()
{
	SetName("LitAtr");

	mLight = new0 Light(Light::LT_POINT);
	mLightNode = new0 LightNode(mLight);
	SetMovable(mLightNode);

	Node *helpNode = new0 Node();

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);

	PX2::VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
	mtl->GetWireProperty(0, 0)->Enabled = true;
	mtl->GetCullProperty(0, 0)->Enabled = false;
	MaterialInstancePtr mtlInst = mtl->CreateInstance();

	StandardMesh stdMesh(vf);
	stdMesh.SetVertexColor(Float4(0.0f, 1.0f, 0.0f, 1.0f));

	TriMesh *mesh = stdMesh.Octahedron();
	mesh->LocalTransform.SetUniformScale(0.5f);
	mesh->SetMaterialInstance(mtlInst);
	helpNode->AttachChild(mesh);

	TriMesh *box = stdMesh.Box(0.005f, 0.005f, 5.0f);
	box->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, -5.5f));
	box->SetMaterialInstance(mtlInst);
	helpNode->AttachChild(box);

	CreateHelpNode()->AttachChild(helpNode);

	WorldBoundIsCurrent = true;
	SetRadius(1.0f);
}
//----------------------------------------------------------------------------
LightActor::~LightActor()
{
}
//----------------------------------------------------------------------------
void LightActor::SetLightType(LightType type)
{
	mLightType = type;

	if (LT_POINT == type)
	{
		mLight->SetType(Light::LT_POINT);
	}
	else if (LT_SPOT == type)
	{
		mLight->SetType(Light::LT_SPOT);
	}
}
//----------------------------------------------------------------------------
void LightActor::SetColor(const Float3 &color)
{
	Actor::SetColor(color);

	mLight->Diffuse = Float4(mColor[0] * mBrightness, mColor[1] * mBrightness,
		mColor[2] * mBrightness, 1.0f);
}
//----------------------------------------------------------------------------
void LightActor::SetBrightness(float brightness)
{
	Actor::SetBrightness(brightness);

	mLight->Diffuse = Float4(mColor[0] * mBrightness, mColor[1] * mBrightness,
		mColor[2] * mBrightness, 1.0f);
}
//----------------------------------------------------------------------------
void LightActor::SetRadius(float radius)
{
	mRadius = radius;
	mLight->Range = radius;

	WorldBound.SetRadius(GetRadius());

	if (PX2_GR.IsInEditor())
	{
		Event *ent = SimuES_E::CreateEventX(SimuES_E::SetRadius);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
}
//----------------------------------------------------------------------------
void LightActor::SetBake_CalShadow(bool caseShadow)
{
	mIsBakeCastShadow = caseShadow;
}
//----------------------------------------------------------------------------
void LightActor::UpdateWorldData(double applicationTime, double elapsedTime)
{
	Actor::UpdateWorldData(applicationTime, elapsedTime);

	WorldBound.SetCenter(WorldTransform.GetTranslate());
	WorldBound.SetRadius(GetRadius());
}
//----------------------------------------------------------------------------
void LightActor::SetParent(Movable* parent)
{
	Actor::SetParent(parent);

	Scene *scene = DynamicCast<Scene>(parent->GetTopestParent());
	if (scene)
	{
		EnvirParam *envirParam = scene->GetEnvirParam();

		if (parent)
		{
			envirParam->AddLight(mLight);
		}
		else
		{
			envirParam->RemoveLight(mLight);
		}
	}
	else
	{
		assertion(false, "There must be a scene.");
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// LightActor
//----------------------------------------------------------------------------
void LightActor::RegistProperties()
{
	Actor::RegistProperties();

	AddPropertyClass("LightActor");

	std::vector<std::string> lightTypes;
	lightTypes.push_back("LT_POINT");
	lightTypes.push_back("LT_SPOT");
	AddPropertyEnum("LightType", (int)mLightType, lightTypes);
	AddProperty("IsBake_CastShadow", PT_BOOL, mIsBakeCastShadow);
}
//----------------------------------------------------------------------------
void LightActor::OnPropertyChanged(const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);

	if ("LightType" == obj.Name)
	{
		SetLightType((LightType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("IsBake_CastShadow" == obj.Name)
	{
		SetBake_CalShadow(PX2_ANY_AS(obj.Data, bool));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
LightActor::LightActor(LoadConstructor value) :
Actor(value)
{
}
//----------------------------------------------------------------------------
void LightActor::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mLight);
	source.ReadPointer(mLightNode);

	source.ReadEnum(mLightType);
	source.ReadBool(mIsBakeCastShadow);

	PX2_END_DEBUG_STREAM_LOAD(LightActor, source);
}
//----------------------------------------------------------------------------
void LightActor::Link(InStream& source)
{
	Actor::Link(source);

	source.ResolveLink(mLight);
	source.ResolveLink(mLightNode);
}
//----------------------------------------------------------------------------
void LightActor::PostLink()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool LightActor::Register(OutStream& target) const
{
	if (Actor::Register(target))
	{
		target.Register(mLight);
		target.Register(mLightNode);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void LightActor::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mLight);
	target.WritePointer(mLightNode);

	target.WriteEnum(mLightType);
	target.WriteBool(mIsBakeCastShadow);

	PX2_END_DEBUG_STREAM_SAVE(LightActor, target);
}
//----------------------------------------------------------------------------
int LightActor::GetStreamingSize(Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mLight);
	size += PX2_POINTERSIZE(mLightNode);

	size += PX2_ENUMSIZE(mLightType);
	size += PX2_BOOLSIZE(mIsBakeCastShadow);

	return size;
}
//----------------------------------------------------------------------------