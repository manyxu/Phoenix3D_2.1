// PX2LightActor.cpp

#include "PX2LightActor.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, LightActor);
PX2_IMPLEMENT_STREAM(LightActor);
PX2_IMPLEMENT_FACTORY(LightActor);

//----------------------------------------------------------------------------
LightActor::LightActor()
{
	SetName("LitAtr");

	mLight = new0 Light(Light::LT_POINT);
	mLightNode = new0 LightNode(mLight);
	SetMovable(mLightNode);

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	StandardMesh stdMesh(vf);
	stdMesh.SetVertexColor(Float4(1.0f, 1.0f, 0.0f, 1.0f));
	TriMesh *mesh = stdMesh.Octahedron();
	PX2::VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
	mtl->GetWireProperty(0, 0)->Enabled = true;
	mtl->GetCullProperty(0, 0)->Enabled = false;
	mesh->LocalTransform.SetUniformScale(0.5f);
	mesh->SetMaterialInstance(mtl->CreateInstance());
	CreateHelpNode()->AttachChild(mesh);
}
//----------------------------------------------------------------------------
LightActor::~LightActor()
{
}
//----------------------------------------------------------------------------
void LightActor::SetParent(Movable* parent)
{
	if (parent)
	{
		if (mLight) GraphicsRoot::GetSingleton().AddLight(mLight);
	}
	else
	{
		if (mLight) GraphicsRoot::GetSingleton().RemoveLight(mLight);
	}

	Actor::SetParent(parent);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// LightActor
//----------------------------------------------------------------------------
void LightActor::RegistProperties()
{
	Actor::RegistProperties();

	AddPropertyClass("LightActor");
}
//----------------------------------------------------------------------------
void LightActor::OnPropertyChanged(const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* LightActor::GetObjectByName(const std::string& name)
{
	Object* found = Actor::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	return 0;
}
//----------------------------------------------------------------------------
void LightActor::GetAllObjectsByName(const std::string& name,
	std::vector<Object*>& objects)
{
	Actor::GetAllObjectsByName(name, objects);
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

	PX2_END_DEBUG_STREAM_SAVE(LightActor, target);
}
//----------------------------------------------------------------------------
int LightActor::GetStreamingSize(Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mLight);
	size += PX2_POINTERSIZE(mLightNode);

	return size;
}
//----------------------------------------------------------------------------