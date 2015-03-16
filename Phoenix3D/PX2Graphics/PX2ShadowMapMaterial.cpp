// PX2ShadowMap_Std_Material.cpp

#include "PX2ShadowMapMaterial.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, GlobalMaterial, ShadowMap_Material);
PX2_IMPLEMENT_STREAM(ShadowMap_Material);
PX2_IMPLEMENT_FACTORY(ShadowMap_Material);
PX2_IMPLEMENT_DEFAULT_NAMES(GlobalMaterial, ShadowMap_Material);

//----------------------------------------------------------------------------
ShadowMap_Material::ShadowMap_Material()
{
	mInstance = new0 MaterialInstance(
		"Data/engine_mtls/std/std.px2obj", "std_shadowmapdepth", false);
}
//----------------------------------------------------------------------------
ShadowMap_Material::~ShadowMap_Material()
{
}
//----------------------------------------------------------------------------
void ShadowMap_Material::Draw(Renderer* renderer, const VisibleSet& visibleSet)
{
	const int numVisible = visibleSet.GetNumVisible();
	for (int j = 0; j < numVisible; ++j)
	{
		Renderable *renderable = visibleSet.GetVisible(j);
		MaterialInstancePtr save = renderable->GetMaterialInstance();

		mInstance->SetPixelTexture(0, "SampleBase", save->GetPixelTexture(0, "SampleBase"));

		renderable->SetMaterialInstance(mInstance);
		renderer->Draw(renderable);

		renderable->SetMaterialInstance(save);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
ShadowMap_Material::ShadowMap_Material(LoadConstructor value):
GlobalMaterial(value)
{
}
//----------------------------------------------------------------------------
void ShadowMap_Material::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	GlobalMaterial::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadPointer(mInstance);

	PX2_END_DEBUG_STREAM_LOAD(ShadowMap_Material, source);
}
//----------------------------------------------------------------------------
void ShadowMap_Material::Link(InStream& source)
{
	GlobalMaterial::Link(source);

	source.ResolveLink(mInstance);
}
//----------------------------------------------------------------------------
void ShadowMap_Material::PostLink()
{
	GlobalMaterial::PostLink();
}
//----------------------------------------------------------------------------
bool ShadowMap_Material::Register(OutStream& target) const
{
	if (GlobalMaterial::Register(target))
	{
		target.Register(mInstance);
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void ShadowMap_Material::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	GlobalMaterial::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointer(mInstance);

	PX2_END_DEBUG_STREAM_SAVE(ShadowMap_Material, target);
}
//----------------------------------------------------------------------------
int ShadowMap_Material::GetStreamingSize(Stream &stream) const
{
	int size = GlobalMaterial::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_POINTERSIZE(mInstance);

	return size;
}
//----------------------------------------------------------------------------
