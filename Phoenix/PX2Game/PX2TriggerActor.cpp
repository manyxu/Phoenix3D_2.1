/*
*
* 文件名称	：	PX2TriggerActor.cpp
*
*/

#include "PX2TriggerActor.hpp"
#include "PX2ContSphere3.hpp"
#include "PX2Node.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, TriggerActor);
PX2_IMPLEMENT_STREAM(TriggerActor);
PX2_IMPLEMENT_FACTORY(TriggerActor);

//----------------------------------------------------------------------------
TriggerActor::TriggerActor ()
	:
mAreaType(AT_SPHERE),
mParam0(1.0f),
mParam1(1.0f),
mParam2(1.0)
{
	ShowHelpMovable(true);
	SetAreaType(AT_SPHERE);
}
//----------------------------------------------------------------------------
TriggerActor::~TriggerActor ()
{
}
//----------------------------------------------------------------------------
void TriggerActor::Update (double appSeconds, double elapsedSeconds)
{
	Actor::Update(appSeconds, elapsedSeconds);
}
//----------------------------------------------------------------------------
void TriggerActor::SetScale (const APoint &scale)
{
	PX2_UNUSED(scale);
	/*_*/
}
//----------------------------------------------------------------------------
void TriggerActor::SetAreaType (AreaType type)
{
	mAreaType = type;

	VertexFormat *vf = VertexFormat::Create(3,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_NORMAL, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT3, 0);

	StandardMesh stdMesh(vf);
	stdMesh.SetVertexColor(Float4(1.0f, 0.0f, 0.0f, 0.4f));
	TriMesh *mesh = 0;

	if (AT_SPHERE == type)
	{
		mesh = stdMesh.Sphere(6, 8, 1.0f);
	}
	else
	{
		mesh = stdMesh.Box(1.0f, 1.0f, 1.0f);
	}

	PX2::VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
	mtl->GetAlphaProperty(0, 0)->BlendEnabled = true;
	mtl->GetWireProperty(0, 0)->Enabled = true;
	mtl->GetCullProperty(0, 0)->Enabled = false;
	mesh->SetMaterialInstance(mtl->CreateInstance());

	SetHelpMovable(mesh);
	ShowHelpMovable(IsHelpMovableShow());

	_RefreshParams();
}
//----------------------------------------------------------------------------
void TriggerActor::SetParam0 (float val)
{
	mParam0 = val;

	_RefreshParams();
}
//----------------------------------------------------------------------------
void TriggerActor::SetParam1 (float val)
{
	mParam1 = val;

	_RefreshParams();
}
//----------------------------------------------------------------------------
void TriggerActor::SetParam2 (float val)
{
	mParam2 = val;

	_RefreshParams();
}
//----------------------------------------------------------------------------
bool TriggerActor::IsPointIn (const PX2::APoint &point) const
{
	APoint localPoint = mHelpMovable->WorldTransform.Inverse() * point;

	if (mAreaType == AT_SPHERE)
	{
		return InSphere<float>(localPoint, mSphere);
	}
	else if (mAreaType == AT_BOX)
	{
		if (point.X()>=-mBox.Extent[0]/2.0f &&
			point.Y()>=-mBox.Extent[1]/2.0f &&
			point.Z()>=-mBox.Extent[2]/2.0f &&
			point.X()<=mBox.Extent[0]/2.0f &&
			point.Y()<=mBox.Extent[1]/2.0f &&
			point.Z()<=mBox.Extent[2]/2.0f)
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void TriggerActor::_RefreshParams ()
{
	mSphere.Radius = mParam0;

	mBox.Extent[0] = mParam0;
	mBox.Extent[1] = mParam1;
	mBox.Extent[2] = mParam2;

	if (AT_SPHERE == mAreaType)
	{
		mHelpMovable->LocalTransform.SetUniformScale(mParam0);
	}
	else
	{
		mHelpMovable->LocalTransform.SetScale(Float3(mParam0, mParam1, 
			mParam2));
	}
}
//----------------------------------------------------------------------------
void TriggerActor::DoEnter ()
{
}
//----------------------------------------------------------------------------
void TriggerActor::DoExecute (Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void TriggerActor::DoLeave ()
{
}
//----------------------------------------------------------------------------
void TriggerActor::RegistProperties () 
{
	Actor::RegistProperties();

	AddPropertyClass("TriggerActor");

	std::vector<std::string> areaTypes;
	areaTypes.push_back("AT_SPHERE");
	areaTypes.push_back("AT_BOX");
	AddPropertyEnum("AreaType", (int)mAreaType, areaTypes);

	AddProperty("Param0", Object::PT_FLOAT, mParam0);
	AddProperty("Param1", Object::PT_FLOAT, mParam1);
	AddProperty("Param2", Object::PT_FLOAT, mParam2);
}
//----------------------------------------------------------------------------
void TriggerActor::OnPropertyChanged (const PropertyObject &obj)
{ 
	Actor::OnPropertyChanged(obj);

	if ("AreaType" == obj.Name)
	{
		SetAreaType((AreaType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("Param0" == obj.Name)
	{
		SetParam0(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Param1" == obj.Name)
	{
		SetParam1(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Param2" == obj.Name)
	{
		SetParam2(PX2_ANY_AS(obj.Data, float));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* TriggerActor::GetObjectByName (const std::string& name)
{
	Object* found = Actor::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void TriggerActor::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	Actor::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
TriggerActor::TriggerActor (LoadConstructor value)
	:
Actor(value),
mParam0(1.0f),
mParam1(1.0f),
mParam2(1.0)
{
}
//----------------------------------------------------------------------------
void TriggerActor::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mAreaType);
	source.Read(mParam0);
	source.Read(mParam1);
	source.Read(mParam2);

	PX2_END_DEBUG_STREAM_LOAD(TriggerActor, source);
}
//----------------------------------------------------------------------------
void TriggerActor::Link (InStream& source)
{
	Actor::Link(source);
}
//----------------------------------------------------------------------------
void TriggerActor::PostLink ()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool TriggerActor::Register (OutStream& target) const
{
	if (Actor::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void TriggerActor::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mAreaType);
	target.Write(mParam0);
	target.Write(mParam1);
	target.Write(mParam2);

	PX2_END_DEBUG_STREAM_SAVE(TriggerActor, target);
}
//----------------------------------------------------------------------------
int TriggerActor::GetStreamingSize (Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_ENUMSIZE(mAreaType);
	size += sizeof(float)*3;

	return size;
}
//----------------------------------------------------------------------------