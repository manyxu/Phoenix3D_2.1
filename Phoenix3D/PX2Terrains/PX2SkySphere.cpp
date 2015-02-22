// PX2SkySphere.cpp

#include "PX2SkySphere.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2SkyMaterial.hpp"
#include "PX2CameraModelDVectorConstant.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, TriMesh, SkySphere);
PX2_IMPLEMENT_STREAM(SkySphere);
PX2_IMPLEMENT_FACTORY(SkySphere);
PX2_IMPLEMENT_DEFAULT_NAMES(TriMesh, SkySphere);

//----------------------------------------------------------------------------
SkySphere::SkySphere ()
{
	mRadius = 500.0f;

	SetRenderLayer(Renderable::RL_SKY);

	VertexFormatPtr vf = VertexFormat::Create(1,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0);
	SetVertexFormat(vf);

	TriMeshPtr mesh = StandardMesh(vf, true, true).Sphere(16, 16, mRadius);
	SetVertexBuffer(mesh->GetVertexBuffer());
	SetIndexBuffer(mesh->GetIndexBuffer());

	UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);

	SkyMaterial *mtl = new0 SkyMaterial();
	mMtlInst = new0 MaterialInstance(mtl, 0);

	// vs
	mMtlInst->SetVertexConstant(0, "gVMatrix", 
		new0 WMatrixConstant());
	mMtlInst->SetVertexConstant(0, "gPVWMatrix", 
		new0 PVWMatrixConstant());
	mMtlInst->SetVertexConstant(0, "gCameraWorldPosition", 
		new0 CameraWorldPositionConstant());
	// ps
	mMtlInst->SetPixelConstant(0, "gCameraWorldDVector",
		new0 CameraWorldDVectorConstant());

	mDirLight = new0 Light(Light::LT_DIRECTIONAL);
	mDirLight->SetDirection(AVector(-1.0f, -1.0f, -1.0f));
	mMtlInst->SetPixelConstant(0, "gLightColour",
		new0 LightDiffuseConstant(mDirLight));
	mMtlInst->SetPixelConstant(0, "gLightWorldDirection", 
		new0 LightWorldDVectorConstant(mDirLight));

	mSunParams = Float4(300.0f, 0.2f, 300.0f, 0.2f);
	mSunParamsShaderFloat = new0 ShaderFloat(1);
	mSunParamsShaderFloat->SetRegister(0, (float*)&mSunParams);
	mMtlInst->SetPixelConstant(0, "sunParams", mSunParamsShaderFloat);

	mSkyParams = Float4(500.0f, 7.0f, 0.0f, 0.0f);
	mSkyParamsShaderFloat = new0 ShaderFloat(1);
	mSkyParamsShaderFloat->SetRegister(0, (float*)&mSkyParams);
	mMtlInst->SetPixelConstant(0, "skyParams", mSkyParamsShaderFloat);

	SetMaterialInstance(mMtlInst);

	Texture2D *texDay = DynamicCast<Texture2D>(
		ResourceManager::GetSingleton().BlockLoad("Data/engine/skyday.png"));
	if (texDay)
		SetDayTexture(texDay);
	Texture2D *sunsetTex = DynamicCast<Texture2D>(
		ResourceManager::GetSingleton().BlockLoad("Data/engine/skysunset.png"));
	if (sunsetTex)
		SetSunSetTexture(sunsetTex);
	Texture2D *texNight = DynamicCast<Texture2D>(
		ResourceManager::GetSingleton().BlockLoad("Data/engine/skynight.png"));
	if (texNight)
		SetNightTexture(texNight);
}
//----------------------------------------------------------------------------
SkySphere::~SkySphere ()
{
}
//----------------------------------------------------------------------------
void SkySphere::SetDayTexture (Texture2D *tex)
{
	mDayTexture = tex;
	mDayTexture->GenerateMipmaps();
	mMtlInst->SetPixelTexture(0, "gDaySampler", mDayTexture);
}
//----------------------------------------------------------------------------
void SkySphere::SetSunSetTexture (Texture2D *tex)
{
	mSunSetTexture = tex;
	mSunSetTexture->GenerateMipmaps();
	mMtlInst->SetPixelTexture(0, "gSunsetSampler", mSunSetTexture);
}
//----------------------------------------------------------------------------
void SkySphere::SetNightTexture (Texture2D *tex)
{
	mNightTexture = tex;
	mNightTexture->GenerateMipmaps();
	mMtlInst->SetPixelTexture(0, "gNightSampler", mNightTexture);
}
//----------------------------------------------------------------------------
void SkySphere::SetSunParams (Float4 sunParams)
{
	mSunParams = sunParams;
	mSunParamsShaderFloat->SetRegister(0, (float*)&mSunParams);
}
//----------------------------------------------------------------------------
void SkySphere::SetSkyParams (Float4 skyParams)
{
	mSkyParams = skyParams;
	mSkyParamsShaderFloat->SetRegister(0, (float*)&mSkyParams);
}
//----------------------------------------------------------------------------
void SkySphere::UpdateWorldData (double applicationTime)
{
	TriMesh::UpdateWorldData(applicationTime);

	PX2::Light *light = 0;
	for (int i=0; i<(int)mInfulencedLights.size(); i++)
	{
		Light *lit = mInfulencedLights[i];
		if (lit->GetType() == Light::LT_DIRECTIONAL)
		{
			light = lit;
			break;
		}
	}

	if (light!=0 && light!=mDirLight)
	{
		mDirLight = light;

		mMtlInst->SetPixelConstant(0, "gLightWorldDirection",
			new0 LightWorldDVectorConstant(mDirLight));

		mMtlInst->SetPixelConstant(0, "gLightColour",
			new0 LightDiffuseConstant(mDirLight));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkySphere::SkySphere (LoadConstructor value)
	:
TriMesh(value),
mRadius(500.0f)
{
}
//----------------------------------------------------------------------------
void SkySphere::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	TriMesh::Load(source);
	PX2_VERSION_LOAD(source);

	source.Read(mRadius);
	source.ReadAggregate(mSunParams);
	source.ReadAggregate(mSkyParams);
	source.ReadPointer(mSunParamsShaderFloat);
	source.ReadPointer(mSkyParamsShaderFloat);
	source.ReadPointer(mMtlInst);
	source.ReadPointer(mDayTexture);
	source.ReadPointer(mSunSetTexture);
	source.ReadPointer(mNightTexture);

	PX2_END_DEBUG_STREAM_LOAD(SkySphere, source);
}
//----------------------------------------------------------------------------
void SkySphere::Link (InStream& source)
{
	TriMesh::Link(source);

	source.ResolveLink(mSunParamsShaderFloat);
	source.ResolveLink(mSkyParamsShaderFloat);
	source.ResolveLink(mMtlInst);
	source.ResolveLink(mDayTexture);
	source.ResolveLink(mSunSetTexture);
	source.ResolveLink(mNightTexture);
}
//----------------------------------------------------------------------------
void SkySphere::PostLink ()
{
	TriMesh::PostLink();
}
//----------------------------------------------------------------------------
bool SkySphere::Register (OutStream& target) const
{
	if (TriMesh::Register(target))
	{
		target.Register(mSunParamsShaderFloat);
		target.Register(mSkyParamsShaderFloat);
		target.Register(mMtlInst);
		target.Register(mDayTexture);
		target.Register(mSunSetTexture);
		target.Register(mNightTexture);

		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void SkySphere::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	TriMesh::Save(target);
	PX2_VERSION_SAVE(target);

	target.Write(mRadius);
	target.WriteAggregate(mSunParams);
	target.WriteAggregate(mSkyParams);
	target.WritePointer(mSunParamsShaderFloat);
	target.WritePointer(mSkyParamsShaderFloat);
	target.WritePointer(mMtlInst);
	target.WritePointer(mDayTexture);
	target.WritePointer(mSunSetTexture);
	target.WritePointer(mNightTexture);

	PX2_END_DEBUG_STREAM_SAVE(SkySphere, target);
}
//----------------------------------------------------------------------------
int SkySphere::GetStreamingSize (Stream &stream) const
{
	int size = TriMesh::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += sizeof(mRadius);
	size += sizeof(mSunParams);
	size += sizeof(mSkyParams);
	size += PX2_POINTERSIZE(mSunParamsShaderFloat);
	size += PX2_POINTERSIZE(mSkyParamsShaderFloat);
	size += PX2_POINTERSIZE(mMtlInst);
	size += PX2_POINTERSIZE(mDayTexture);
	size += PX2_POINTERSIZE(mSunSetTexture);
	size += PX2_POINTERSIZE(mNightTexture);
	return size;
}
//----------------------------------------------------------------------------
