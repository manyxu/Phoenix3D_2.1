// PX2SkyMesh.cpp

#include "PX2SkyMesh.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, TriMesh, SkyMesh);
PX2_IMPLEMENT_STREAM(SkyMesh);
PX2_IMPLEMENT_FACTORY(SkyMesh);
PX2_IMPLEMENT_DEFAULT_NAMES(TriMesh, SkyMesh);

//----------------------------------------------------------------------------
SkyMesh::SkyMesh()
{
	mRadius = 500.0f;
	mSkyParam = Float4(50.0f, 2.0f, 0.0f, 0.0f);
	mSunMoonParam = Float4(512.0f, 0.2f, 400.0f, 0.2f);
	mSunMoonColourIn = Float4::WHITE;
	mSunMoonColourOut = Float4::WHITE;

	SetRenderLayer(Renderable::RL_SKY);

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	SetVertexFormat(vf);

	TriMeshPtr mesh = StandardMesh(vf, true, true).Sphere(32, 32, mRadius);
	SetVertexBuffer(mesh->GetVertexBuffer());
	SetIndexBuffer(mesh->GetIndexBuffer());

	UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);

	MaterialInstance *mi = new0 MaterialInstance("Data/engine_mtls/sky/sky.px2obj",
		"sky_sunmoon", false);
	SetMaterialInstance(mi);

	SetDayTexture("Data/engine/sky/day.png");
	SetSunsetTexture("Data/engine/sky/sunset.png");
	SetNightTexture("Data/engine/sky/night.png");
	SetSkyParam(mSkyParam);
	SetSunMoonParam(mSunMoonParam);
	SetSunMoonColourIn(mSunMoonColourIn);
	SetSunMoonColourOut(mSunMoonColourOut);
}
//----------------------------------------------------------------------------
SkyMesh::~SkyMesh()
{
}
//----------------------------------------------------------------------------
void SkyMesh::SetDayTexture(const std::string &filename)
{
	Texture2D *tex = DynamicCast<Texture2D>(PX2_RM.BlockLoad(filename));
	if (tex)
	{
		if (!tex->HasMipmaps())
		{
			tex->GenerateMipmaps();
		}

		mDayTexFilename = filename;
		mMaterialInstance->SetPixelTexture(0, "SamplerDay", tex);
	}
}
//----------------------------------------------------------------------------
void SkyMesh::SetSunsetTexture(const std::string &filename)
{
	Texture2D *tex = DynamicCast<Texture2D>(PX2_RM.BlockLoad(filename));
	if (tex)
	{
		if (!tex->HasMipmaps())
		{
			tex->GenerateMipmaps();
		}

		mSunsetTexFilename = filename;
		mMaterialInstance->SetPixelTexture(0, "SamplerSunset", tex);
	}
}
//----------------------------------------------------------------------------
void SkyMesh::SetNightTexture(const std::string &filename)
{
	Texture2D *tex = DynamicCast<Texture2D>(PX2_RM.BlockLoad(filename));
	if (tex)
	{
		if (!tex->HasMipmaps())
		{
			tex->GenerateMipmaps();
		}

		mNightTexFilename = filename;
		mMaterialInstance->SetPixelTexture(0, "SamplerNight", tex);
	}
}
//----------------------------------------------------------------------------
void SkyMesh::SetSkyParam(const Float4 &skyParam)
{
	mSkyParam = skyParam;

	ShaderFloat *sf = mMaterialInstance->GetPixelConstant(0, "SkyParam");
	if (sf)
	{
		sf->SetRegister(0, (float*)&mSkyParam);
	}
}
//----------------------------------------------------------------------------
void SkyMesh::SetSunMoonParam(const Float4 &sunParam)
{
	mSunMoonParam = sunParam;

	ShaderFloat *sf = mMaterialInstance->GetPixelConstant(0, "SunMoonParam");
	if (sf)
	{
		sf->SetRegister(0, (float*)&mSunMoonParam);
	}
}
//----------------------------------------------------------------------------
void SkyMesh::SetSunMoonColourIn(const Float4 &color)
{
	mSunMoonColourIn = color;

	ShaderFloat *sf = mMaterialInstance->GetPixelConstant(0, "SunMoonColourIn");
	if (sf)
	{
		sf->SetRegister(0, (float*)&mSunMoonColourIn);
	}
}
//----------------------------------------------------------------------------
void SkyMesh::SetSunMoonColourOut(const Float4 &color)
{
	mSunMoonColourOut = color;

	ShaderFloat *sf = mMaterialInstance->GetPixelConstant(0, "SunMoonColourOut");
	if (sf)
	{
		sf->SetRegister(0, (float*)&mSunMoonColourOut);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkyMesh::SkyMesh(LoadConstructor value) :
TriMesh(value),
mRadius(500.0f)
{
}
//----------------------------------------------------------------------------
void SkyMesh::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	TriMesh::Load(source);
	PX2_VERSION_LOAD(source);

	source.Read(mRadius);
	source.ReadAggregate(mSkyParam);
	
	source.ReadString(mDayTexFilename);
	source.ReadString(mSunsetTexFilename);
	source.ReadString(mNightTexFilename);

	source.ReadAggregate(mSunMoonParam);
	source.ReadAggregate(mSunMoonColourIn);
	source.ReadAggregate(mSunMoonColourOut);

	PX2_END_DEBUG_STREAM_LOAD(SkyMesh, source);
}
//----------------------------------------------------------------------------
void SkyMesh::Link(InStream& source)
{
	TriMesh::Link(source);
}
//----------------------------------------------------------------------------
void SkyMesh::PostLink()
{
	TriMesh::PostLink();
}
//----------------------------------------------------------------------------
bool SkyMesh::Register(OutStream& target) const
{
	if (TriMesh::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void SkyMesh::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	TriMesh::Save(target);
	PX2_VERSION_SAVE(target);

	target.Write(mRadius);
	target.WriteAggregate(mSkyParam);

	target.WriteString(mDayTexFilename);
	target.WriteString(mSunsetTexFilename);
	target.WriteString(mNightTexFilename);

	target.WriteAggregate(mSunMoonParam);
	target.WriteAggregate(mSunMoonColourIn);
	target.WriteAggregate(mSunMoonColourOut);

	PX2_END_DEBUG_STREAM_SAVE(SkyMesh, target);
}
//----------------------------------------------------------------------------
int SkyMesh::GetStreamingSize(Stream &stream) const
{
	int size = TriMesh::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += sizeof(mRadius);
	size += sizeof(mSkyParam);

	size += PX2_STRINGSIZE(mDayTexFilename);
	size += PX2_STRINGSIZE(mSunsetTexFilename);
	size += PX2_STRINGSIZE(mNightTexFilename);

	size += sizeof(mSunMoonParam);
	size += sizeof(mSunMoonColourIn);
	size += sizeof(mSunMoonColourOut);

	return size;
}
//----------------------------------------------------------------------------
