// PX2TriggerActor.cpp

#include "PX2TriggerActor.hpp"
#include "PX2ContSphere3.hpp"
#include "PX2Node.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, TriggerActor);
PX2_IMPLEMENT_STREAM(TriggerActor);
PX2_IMPLEMENT_FACTORY(TriggerActor);

//----------------------------------------------------------------------------
TriggerActor::TriggerActor() :
mAreaType(AT_SPHERE),
mTrigerType(TT_ENTER_ONCE),
mIsTrigered(false)
{
	SetName("TrigAtr");

	SetAreaType(AT_SPHERE);
}
//----------------------------------------------------------------------------
TriggerActor::~TriggerActor()
{
}
//----------------------------------------------------------------------------
void TriggerActor::SetAreaType(AreaType type)
{
	mAreaType = type;

	CreateGetHelpNode()->DetachChild(mAreaMovable);

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	if (AT_SPHERE == mAreaType)
	{
		StandardMesh stdMesh(vf);
		stdMesh.SetVertexColor(Float4(1.0f, 1.0f, 0.0f, 1.0f));
		TriMesh *mesh = stdMesh.Sphere(16, 16, 1.0f);
		VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
		mtl->GetWireProperty(0, 0)->Enabled = true;
		mtl->GetCullProperty(0, 0)->Enabled = false;
		mesh->LocalTransform.SetUniformScale(0.5f);
		mesh->SetMaterialInstance(mtl->CreateInstance());
		mAreaMovable = mesh;
	}
	else if (AT_BOX == mAreaType)
	{
		StandardMesh stdMesh(vf);
		stdMesh.SetVertexColor(Float4(1.0f, 1.0f, 0.0f, 1.0f));
		TriMesh *mesh = stdMesh.Box(1, 1, 1);
		VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
		mtl->GetWireProperty(0, 0)->Enabled = true;
		mtl->GetCullProperty(0, 0)->Enabled = false;
		mesh->LocalTransform.SetUniformScale(0.5f);
		mesh->SetMaterialInstance(mtl->CreateInstance());
		mAreaMovable = mesh;
	}

	CreateGetHelpNode()->AttachChild(mAreaMovable);
}
//----------------------------------------------------------------------------
bool TriggerActor::IsPointIn(const PX2::APoint &point) const
{
	Transform trans = WorldTransform;
	APoint localPoint = trans.Inverse() * point;

	if (mAreaType == AT_SPHERE)
	{
		Sphere3f sphere;
		sphere.Radius = mAreaParam[0];

		if (InSphere<float>(localPoint, sphere))
			return true;
	}
	else if (mAreaType == AT_BOX)
	{
		Box3f box;
		box.Extent[0] = mAreaParam[0];
		box.Extent[1] = mAreaParam[1];
		box.Extent[2] = mAreaParam[2];

		if (localPoint.X() >= -box.Extent[0] &&
			localPoint.Y() >= -box.Extent[1] &&
			localPoint.Z() >= -box.Extent[2] &&
			localPoint.X() <= box.Extent[0] &&
			localPoint.Y() <= box.Extent[1] &&
			localPoint.Z() <= box.Extent[2])
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void TriggerActor::Triger()
{
	mIsTrigered = true;
}
//----------------------------------------------------------------------------
void TriggerActor::ResetTriger()
{
	mIsTrigered = false;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void TriggerActor::RegistProperties()
{
	Actor::RegistProperties();

	AddPropertyClass("TriggerActor");

	std::vector<std::string> areaTypes;
	areaTypes.push_back("AT_SPHERE");
	areaTypes.push_back("AT_BOX");
	AddPropertyEnum("AreaType", (int)mAreaType, areaTypes);

	std::vector<std::string> trigerTypes;
	trigerTypes.push_back("TT_ENTER_ONCE");
	trigerTypes.push_back("TT_ENTER_EVERYENTER");
	AddPropertyEnum("TrigerType", GetTrigerType(), trigerTypes);
}
//----------------------------------------------------------------------------
void TriggerActor::OnPropertyChanged(const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);

	if ("AreaType" == obj.Name)
	{
		SetAreaType((AreaType)PX2_ANY_AS(obj.Data, int));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* TriggerActor::GetObjectByName(const std::string& name)
{
	Object* found = Actor::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void TriggerActor::GetAllObjectsByName(const std::string& name,
	std::vector<Object*>& objects)
{
	Actor::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
TriggerActor::TriggerActor(LoadConstructor value) :
Actor(value),
mTrigerType(TT_ENTER_ONCE),
mIsTrigered(false)
{
}
//----------------------------------------------------------------------------
void TriggerActor::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mAreaType);
	source.ReadAggregate(mAreaParam);
	source.ReadPointer(mAreaMovable);

	source.ReadEnum(mTrigerType);

	PX2_END_DEBUG_STREAM_LOAD(TriggerActor, source);
}
//----------------------------------------------------------------------------
void TriggerActor::Link(InStream& source)
{
	Actor::Link(source);

	if (mAreaMovable)
	{
		source.ResolveLink(mAreaMovable);
	}
}
//----------------------------------------------------------------------------
void TriggerActor::PostLink()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool TriggerActor::Register(OutStream& target) const
{
	if (Actor::Register(target))
	{
		if (mAreaMovable)
		{
			target.Register(mAreaMovable);
		}

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void TriggerActor::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mAreaType);
	target.WriteAggregate(mAreaParam);
	target.WritePointer(mAreaMovable);

	target.WriteEnum(mTrigerType);

	PX2_END_DEBUG_STREAM_SAVE(TriggerActor, target);
}
//----------------------------------------------------------------------------
int TriggerActor::GetStreamingSize(Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mAreaType);
	size += sizeof(mAreaParam);
	size += PX2_POINTERSIZE(mAreaMovable);

	size += PX2_ENUMSIZE(mTrigerType);

	return size;
}
//----------------------------------------------------------------------------