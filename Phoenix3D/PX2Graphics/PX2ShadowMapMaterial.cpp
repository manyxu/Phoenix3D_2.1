// PX2ShadowMap_Std_Material.cpp

#include "PX2ShadowMapMaterial.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, GlobalMaterial, ShadowMap_Material);
PX2_IMPLEMENT_STREAM(ShadowMap_Material);
PX2_IMPLEMENT_FACTORY(ShadowMap_Material);
PX2_IMPLEMENT_DEFAULT_NAMES(GlobalMaterial, ShadowMap_Material);

//----------------------------------------------------------------------------
ShadowMap_Material::ShadowMap_Material()
{
	mInstanceStd = new0 MaterialInstance(
		"Data/engine_mtls/std/std.px2obj", "std_shadowmapdepth", false);

	mInstanceStdSkinSkeleton = new0 MaterialInstance(
		"Data/engine_mtls/skinskeleton/skinskeleton.px2obj",
		"skinskeleton_shadowmapdepth", false);

	mOverRideOffsetProperty = new0 OffsetProperty();
	mOverRideOffsetProperty->FillEnabled = true;
	mOverRideOffsetProperty->Scale = 4.0f;
	mOverRideOffsetProperty->Bias = 100.0f;
}
//----------------------------------------------------------------------------
ShadowMap_Material::~ShadowMap_Material()
{
}
//----------------------------------------------------------------------------
void ShadowMap_Material::Draw(Renderer* renderer, const VisibleSet& visibleSet)
{
	renderer->SetOverrideOffsetProperty(mOverRideOffsetProperty);
	//renderer->SetColorMask(false, false, false, false);

	const int numVisible = visibleSet.GetNumVisible();
	for (int j = 0; j < numVisible; ++j)
	{
		Renderable *renderable = visibleSet.GetVisible(j);
		MaterialInstancePtr save = renderable->GetMaterialInstance();
		const std::string &mtlName = save->GetMaterial()->GetName();

		EnvirParam *envParam = PX2_GR.GetCurEnvirParam();
		if ("std" == mtlName)
		{
			mInstanceStd->SetPixelTexture(0, "SampleBase", save->GetPixelTexture(0, "SampleBase"));

			renderable->SetMaterialInstance(mInstanceStd);
			renderer->Draw(renderable);

			renderable->SetMaterialInstance(save);
			save->Update(0.0f, 0.0f);
		}
		else if ("skinskeleton" == mtlName)
		{
			mInstanceStdSkinSkeleton->SetPixelTexture(0, "SampleBase", save->GetPixelTexture(0, "SampleBase"));

			renderable->SetMaterialInstance(mInstanceStdSkinSkeleton);
			renderer->Draw(renderable);

			renderable->SetMaterialInstance(save);
			save->Update(0.0f, 0.0f);
		}
	}

	renderer->SetOverrideStencilProperty(0);
	//renderer->SetColorMask(true, true, true, true);
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

	PX2_END_DEBUG_STREAM_LOAD(ShadowMap_Material, source);
}
//----------------------------------------------------------------------------
void ShadowMap_Material::Link(InStream& source)
{
	GlobalMaterial::Link(source);
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

	PX2_END_DEBUG_STREAM_SAVE(ShadowMap_Material, target);
}
//----------------------------------------------------------------------------
int ShadowMap_Material::GetStreamingSize(Stream &stream) const
{
	int size = GlobalMaterial::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------
