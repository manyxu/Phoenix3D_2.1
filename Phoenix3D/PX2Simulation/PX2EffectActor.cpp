// PX2EffectActor.cpp

#include "PX2EffectActor.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Actor, EffectActor);
PX2_IMPLEMENT_STREAM(EffectActor);
PX2_IMPLEMENT_FACTORY(EffectActor);
PX2_IMPLEMENT_DEFAULT_NAMES(Actor, EffectActor);

//----------------------------------------------------------------------------
EffectActor::EffectActor()
{
	SetName("EffectActor");

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	StandardMesh stdMesh(vf);
	stdMesh.SetVertexColor(Float4(0.0f, 1.0f, 0.0f, 1.0f));
	TriMesh *mesh = stdMesh.Box(0.5f, 0.5f, 0.5f);
	PX2::VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
	mtl->GetWireProperty(0, 0)->Enabled = true;
	mtl->GetCullProperty(0, 0)->Enabled = false;
	mesh->LocalTransform.SetUniformScale(0.5f);
	mesh->SetMaterialInstance(mtl->CreateInstance());
	CreateGetHelpNode()->DetachAllChildren();
	CreateGetHelpNode()->AttachChild(mesh);
	CreateGetHelpNode()->SetParentTransformIngore(false, false, true);
}
//----------------------------------------------------------------------------
EffectActor::~EffectActor()
{
}
//----------------------------------------------------------------------------
void EffectActor::RegistProperties()
{
	Actor::RegistProperties();

	AddPropertyClass("EffectActor");
}
//----------------------------------------------------------------------------
void EffectActor::OnPropertyChanged(const PropertyObject &obj)
{
	Actor::OnPropertyChanged(obj);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EffectActor::EffectActor(LoadConstructor value) :
Actor(value)
{
}
//----------------------------------------------------------------------------
void EffectActor::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Actor::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(EffectActor, source);
}
//----------------------------------------------------------------------------
void EffectActor::Link(InStream& source)
{
	Actor::Link(source);
}
//----------------------------------------------------------------------------
void EffectActor::PostLink()
{
	Actor::PostLink();
}
//----------------------------------------------------------------------------
bool EffectActor::Register(OutStream& target) const
{
	if (Actor::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void EffectActor::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Actor::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(EffectActor, target);
}
//----------------------------------------------------------------------------
int EffectActor::GetStreamingSize(Stream &stream) const
{
	int size = Actor::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------