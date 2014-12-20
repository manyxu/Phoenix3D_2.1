/*
*
* 文件名称	：	PX2SkinMaterial.cpp
*
*/

#include "PX2SkinMaterial.hpp"
#include "PX2PVWMatrixConstant.hpp"
#include "PX2VWMatrixConstant.hpp"
#include "PX2PMatrixConstant.hpp"
#include "PX2WMatrixConstant.hpp"
#include "PX2SkinMatrixConstant.hpp"
#include "PX2CameraWorldPositionConstant.hpp"
#include "PX2ShineEmissiveConstant.hpp"
#include "PX2ShineAmbientConstant.hpp"
#include "PX2ShineDiffuseConstant.hpp"
#include "PX2ShineSpecularConstant.hpp"
#include "PX2FogParamConstant.hpp"
#include "PX2FogColorConstant.hpp"
#include "PX2ShaderKeys.hpp"
#include "PX2LightWorldDVectorConstant.hpp"
#include "PX2LightAmbientConstant.hpp"
#include "PX2LightDiffuseConstant.hpp"
#include "PX2LightSpecularConstant.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Material, SkinMaterial);
PX2_IMPLEMENT_STREAM(SkinMaterial);
PX2_IMPLEMENT_FACTORY(SkinMaterial);
PX2_IMPLEMENT_DEFAULT_NAMES(Material, SkinMaterial);

//----------------------------------------------------------------------------
SkinMaterial::SkinMaterial ()
{
	VertexShader* vshader = new0 VertexShader("PX2.Skin", 5, 4, 12, 0, false);
	vshader->SetInput(0, "modelPosition", Shader::VT_FLOAT3, Shader::VS_POSITION);
	vshader->SetInput(1, "modelNormal", Shader::VT_FLOAT3, Shader::VS_NORMAL);
	vshader->SetInput(2, "modelTCoord0", Shader::VT_FLOAT2,	Shader::VS_TEXCOORD0);
	vshader->SetInput(3, "modelTCoord1", Shader::VT_FLOAT4,	Shader::VS_TEXCOORD1);
	vshader->SetInput(4, "modelTCoord2", Shader::VT_FLOAT4,	Shader::VS_TEXCOORD2);

	vshader->SetOutput(0, "clipPosition", Shader::VT_FLOAT4, Shader::VS_POSITION);
	vshader->SetOutput(1, "vertexColor", Shader::VT_FLOAT4, Shader::VS_COLOR0);
	vshader->SetOutput(2, "vertexTCoord0", Shader::VT_FLOAT2, Shader::VS_TEXCOORD0);
	vshader->SetOutput(3, "vertexTCoord1", Shader::VT_FLOAT2, Shader::VS_TEXCOORD1);

	vshader->SetConstant(0, "gPVWMatrix", 4);
	vshader->SetConstant(1, "gBoneTM", 114);
	vshader->SetConstant(2, "CameraWorldPosition", 1);
	vshader->SetConstant(3, "gShineEmissive", 1);
	vshader->SetConstant(4, "gShineAmbient", 1);
	vshader->SetConstant(5, "gShineDiffuse", 1);
	vshader->SetConstant(6, "gShineSpecular", 1);
	vshader->SetConstant(7, "gLightAmbient", 1);
	vshader->SetConstant(8, "gLightDiffuse", 1);
	vshader->SetConstant(9, "gLightSpecular", 1);
	vshader->SetConstant(10, "FogParam", 1);
	vshader->SetConstant(11, "LightWorldDirection", 1);
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);

	PixelShader* pshader = new0 PixelShader("PX2.Skin",
		3, 1, 1, 1, false);
	pshader->SetInput(0, "vertexColor", Shader::VT_FLOAT4, Shader::VS_COLOR0);
	pshader->SetInput(1, "vertexTCoord0", Shader::VT_FLOAT2, Shader::VS_TEXCOORD0);
	pshader->SetInput(2, "vertexTCoord1", Shader::VT_FLOAT2, Shader::VS_TEXCOORD1);
	pshader->SetOutput(0, "pixelColor", Shader::VT_FLOAT4, Shader::VS_COLOR0);
	pshader->SetConstant(0, "FogColor", 1);
	pshader->SetSampler(0, "gDiffuseSampler", Shader::ST_2D);
	pshader->SetFilter(0, Shader::SF_LINEAR);
	pshader->SetCoordinate(0, 0, Shader::SC_CLAMP);
	pshader->SetCoordinate(0, 1, Shader::SC_CLAMP);
	pshader->SetTextureUnits(msPTextureUnits);
	pshader->SetPrograms(msPPrograms);
	pshader->SetBaseRegisters(msPRegisters);

	MaterialPass* pass = new0 MaterialPass();
	pass->SetVertexShader(vshader);
	pass->SetPixelShader(pshader);
	pass->SetAlphaProperty(new0 AlphaProperty());
	pass->SetCullProperty(new0 CullProperty());
	pass->SetDepthProperty(new0 DepthProperty());
	pass->SetOffsetProperty(new0 OffsetProperty());
	pass->SetStencilProperty(new0 StencilProperty());
	pass->SetWireProperty(new0 WireProperty());

	MaterialTechnique* technique = new0 MaterialTechnique();
	technique->InsertPass(pass);
	InsertTechnique(technique);

	vshader->SetShaderKey(SKT_SKIN);
	pshader->SetShaderKey(SKT_SKIN);
}
//----------------------------------------------------------------------------
SkinMaterial::~SkinMaterial ()
{
}
//----------------------------------------------------------------------------
PixelShader* SkinMaterial::GetPixelShader () const
{
	return mTechniques[0]->GetPass(0)->GetPixelShader();
}
//----------------------------------------------------------------------------
MaterialInstance* SkinMaterial::CreateInstance (Texture2D* texture,
	Shine *shine) const
{
	if (!shine)
	{
		shine = new0 Shine();
		shine->Emissive = Float4(0.0f, 0.0f, 0.0f, 0.0f);
		shine->Ambient = Float4(1.0f, 1.0f, 1.0f, 1.0f);
		shine->Diffuse = Float4(1.0f, 1.0f, 1.0f, 1.0f);
		shine->Specular =  Float4(1.0f, 1.0f, 1.0f, 10.0f);
	}

	LightPtr light = new0 Light();
	light->Ambient = Float4::WHITE;
	light->Diffuse = Float4::WHITE;
	light->Specular = Float4::ZERO;

	MaterialInstance* instance = new0 MaterialInstance(this, 0);
	instance->SetVertexConstant(0, "gPVWMatrix", new0 PVWMatrixConstant());
	instance->SetVertexConstant(0, "gBoneTM", new0 SkinMatrixConstant(38));
	instance->SetVertexConstant(0, "CameraWorldPosition", new0 CameraWorldPositionConstant());
	instance->SetVertexConstant(0, "gShineEmissive", new0 ShineEmissiveConstant(shine));
	instance->SetVertexConstant(0, "gShineAmbient", new0 ShineAmbientConstant(shine));
	instance->SetVertexConstant(0, "gShineDiffuse", new0 ShineDiffuseConstant(shine));
	instance->SetVertexConstant(0, "gShineSpecular", new0 ShineSpecularConstant(shine));
	instance->SetVertexConstant(0, "gLightAmbient", new0 LightAmbientConstant(light));
	instance->SetVertexConstant(0, "gLightDiffuse", new0 LightDiffuseConstant(light));
	instance->SetVertexConstant(0, "gLightSpecular", new0 LightSpecularConstant(light));
	instance->SetVertexConstant(0, "FogParam", new0 FogParamConstant());
	instance->SetVertexConstant(0, "LightWorldDirection", new0 LightWorldDVectorConstant(light));

	instance->SetPixelTexture(0, "gDiffuseSampler", texture);
	instance->SetPixelConstant(0, "FogColor", new0 FogColorConstant());

	return instance;
}
//----------------------------------------------------------------------------
void SkinMaterial::_CalShaderKey()
{
	MaterialPass* pass = mTechniques[0]->GetPass(0);
	VertexShader* vshader = pass->GetVertexShader();
	PixelShader* pshader = pass->GetPixelShader();

	if (!GetAlphaProperty(0, 0)->CompareEnabled)
	{
		vshader->SetShaderKey(SKT_SKIN);
		pshader->SetShaderKey(SKT_SKIN);

		pshader->SetPrograms(msPPrograms);
	}
	else
	{
		vshader->SetShaderKey(SKT_SKIN_ALPHATEST);
		pshader->SetShaderKey(SKT_SKIN_ALPHATEST);

		msPPrograms1[0] = msPPrograms[0];
		msPPrograms1[1] = msPPrograms[1];
		msPPrograms1[2] = msPPrograms[2];
		msPPrograms1[3] = msPPrograms[3];
		msPPrograms1[4] = msPPrograms[4];
		msPPrograms1[5] = msPPrograsOGLESTest[1];

		pshader->SetPrograms(msPPrograms1);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
SkinMaterial::SkinMaterial (LoadConstructor value)
	:
Material(value)
{
}
//----------------------------------------------------------------------------
void SkinMaterial::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Material::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(SkinMaterial, source);
}
//----------------------------------------------------------------------------
void SkinMaterial::Link (InStream& source)
{
	Material::Link(source);
}
//----------------------------------------------------------------------------
void SkinMaterial::PostLink ()
{
	Material::PostLink();

	MaterialPass* pass = mTechniques[0]->GetPass(0);
	VertexShader* vshader = pass->GetVertexShader();
	PixelShader* pshader = pass->GetPixelShader();
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);

	pshader->SetBaseRegisters(msPRegisters);
	pshader->SetTextureUnits(msPTextureUnits);

	_CalShaderKey();
}
//----------------------------------------------------------------------------
bool SkinMaterial::Register (OutStream& target) const
{
	return Material::Register(target);
}
//----------------------------------------------------------------------------
void SkinMaterial::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Material::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(SkinMaterial, target);
}
//----------------------------------------------------------------------------
int SkinMaterial::GetStreamingSize (Stream &stream) const
{
	int size = Material::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Profiles.
//----------------------------------------------------------------------------
int SkinMaterial::msDx9VRegisters[12] = { 0, 4, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
int SkinMaterial::msOglVRegisters[12] = { 1, 5, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128};
int SkinMaterial::msOpenGLES2VRegisters[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int* SkinMaterial::msVRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9VRegisters,
	msDx9VRegisters,
	msDx9VRegisters,
	msOglVRegisters,
	msOpenGLES2VRegisters
};

std::string SkinMaterial::msVPrograms[Shader::MAX_PROFILES] =
{
	// VP_NONE
	"",

	// VP_VS_1_1
	"vs_1_1\n"
	"",

	// VP_VS_2_0
	"vs_2_0\n"
	"def c128, 1.00000000, 3.00000000, 0.00000000, 0.50000000\n"
	"dcl_texcoord1 v3\n"
	"dcl_position0 v0\n"
	"dcl_texcoord2 v4\n"
	"dcl_normal0 v1\n"
	"dcl_texcoord0 v2\n"
	"mul r4.y, v3, c128\n"
	"mul r4.x, v3, c128.y\n"
	"abs r2.x, r4\n"
	"abs r0.y, r4\n"
	"frc r0.z, r0.y\n"
	"frc r2.y, r2.x\n"
	"slt r0.x, r4.y, c128.z\n"
	"max r0.x, -r0, r0\n"
	"slt r0.x, c128.z, r0\n"
	"slt r1.w, r4.x, c128.z\n"
	"max r1.w, -r1, r1\n"
	"slt r1.w, c128.z, r1\n"
	"add r0.y, r0, -r0.z\n"
	"add r0.w, -r0.x, c128.x\n"
	"mul r0.z, r0.y, r0.w\n"
	"mad r1.y, r0.x, -r0, r0.z\n"
	"mov r0.xyz, v0\n"
	"mov r0.w, c128.x\n"
	"mova a0.x, r4.y\n"
	"dp4 r1.x, r0, c[a0.x + 4]\n"
	"mova a0.x, r1.y\n"
	"dp4 r1.y, r0, c[a0.x + 5]\n"
	"dp4 r1.z, r0, c[a0.x + 6]\n"
	"add r2.w, r2.x, -r2.y\n"
	"add r2.z, -r1.w, c128.x\n"
	"mul r3.x, r2.w, r2.z\n"
	"mul r2.xyz, v4.y, r1\n"
	"mad r1.x, r1.w, -r2.w, r3\n"
	"mova a0.y, r1.x\n"
	"mul r3.w, v3.z, c128.y\n"
	"mova a0.z, r4.x\n"
	"dp4 r1.x, r0, c[a0.z + 4]\n"
	"dp4 r1.y, r0, c[a0.y + 5]\n"
	"dp4 r1.z, r0, c[a0.y + 6]\n"
	"mad r2.xyz, v4.x, r1, r2\n"
	"slt r1.w, r3, c128.z\n"
	"max r1.x, -r1.w, r1.w\n"
	"slt r1.x, c128.z, r1\n"
	"abs r1.y, r3.w\n"
	"frc r1.z, r1.y\n"
	"add r1.y, r1, -r1.z\n"
	"add r1.w, -r1.x, c128.x\n"
	"mul r1.z, r1.y, r1.w\n"
	"mul r1.w, v3, c128.y\n"
	"abs r3.y, r1.w\n"
	"slt r3.x, r1.w, c128.z\n"
	"max r3.x, -r3, r3\n"
	"slt r3.x, c128.z, r3\n"
	"frc r4.z, r3.y\n"
	"mad r2.w, r1.x, -r1.y, r1.z\n"
	"mova a0.z, r3.w\n"
	"dp4 r1.x, r0, c[a0.z + 4]\n"
	"mova a0.z, r2.w\n"
	"dp4 r1.y, r0, c[a0.z + 5]\n"
	"dp4 r1.z, r0, c[a0.z + 6]\n"
	"mad r1.xyz, v4.z, r1, r2\n"
	"add r3.y, r3, -r4.z\n"
	"add r3.z, -r3.x, c128.x\n"
	"mul r3.z, r3.y, r3\n"
	"mad r2.x, r3, -r3.y, r3.z\n"
	"mova a0.z, r2.x\n"
	"mova a0.w, r1\n"
	"dp4 r2.x, r0, c[a0.w + 4]\n"
	"dp4 r2.y, r0, c[a0.z + 5]\n"
	"dp4 r2.z, r0, c[a0.z + 6]\n"
	"mad r1.xyz, r2, v4.w, r1\n"
	"add r0.xyz, -r1, c118\n"
	"dp3 r0.w, r0, r0\n"
	"rsq r0.w, r0.w\n"
	"mad r0.xyz, r0.w, r0, -c127\n"
	"mul r3.xyz, r0, c128.w\n"
	"mova a0.w, r4.y\n"
	"dp3 r0.z, c[a0.x + 6], v1\n"
	"dp3 r0.y, c[a0.x + 5], v1\n"
	"dp3 r0.x, c[a0.w + 4], v1\n"
	"mul r2.xyz, v4.y, r0\n"
	"mova a0.x, r4\n"
	"dp3 r0.x, c[a0.x + 4], v1\n"
	"dp3 r0.y, c[a0.y + 5], v1\n"
	"dp3 r0.z, c[a0.y + 6], v1\n"
	"mad r2.xyz, v4.x, r0, r2\n"
	"mova a0.x, r3.w\n"
	"dp3 r0.x, c[a0.x + 4], v1\n"
	"mova a0.x, r2.w\n"
	"dp3 r0.y, c[a0.x + 5], v1\n"
	"dp3 r0.z, c[a0.x + 6], v1\n"
	"mad r2.xyz, v4.z, r0, r2\n"
	"mova a0.x, r1.w\n"
	"dp3 r0.x, c[a0.x + 4], v1\n"
	"dp3 r0.y, c[a0.z + 5], v1\n"
	"dp3 r0.z, c[a0.z + 6], v1\n"
	"mad r0.xyz, v4.w, r0, r2\n"
	"dp3 r2.x, r3, r3\n"
	"dp3 r1.w, r0, r0\n"
	"rsq r1.w, r1.w\n"
	"mul r0.xyz, r1.w, r0\n"
	"rsq r2.x, r2.x\n"
	"mul r2.xyz, r2.x, r3\n"
	"dp3 r2.x, r0, r2\n"
	"mov r1.w, c122\n"
	"mul r3.x, c125.w, r1.w\n"
	"max r1.w, r2.x, c128.z\n"
	"pow r2, r1.w, r3.x\n"
	"dp3 r0.x, r0, -c127\n"
	"max r1.w, r0.x, c128.z\n"
	"mov r2.w, r2.x\n"
	"mov r0.xyz, c120\n"
	"mul r3.xyz, c123, r0\n"
	"mov r2.xyz, c122\n"
	"mov r0.xyz, c121\n"
	"add r3.xyz, r3, c119\n"
	"mul r0.xyz, c124, r0\n"
	"mad r0.xyz, r0, r1.w, r3\n"
	"mov r1.w, c128.x\n"
	"mul r2.xyz, c125, r2\n"
	"mad oD0.xyz, r2, r2.w, r0\n"
	"add r0.x, c126.w, -c126.z\n"
	"rcp r0.y, r0.x\n"
	"add r0.x, r1.z, -c126.z\n"
	"mul r0.x, r0, r0.y\n"
	"add r0.z, c126.y, -c126.x\n"
	"rcp r0.y, r0.w\n"
	"min r0.x, r0, c128\n"
	"rcp r0.z, r0.z\n"
	"add r0.y, -r0, c126\n"
	"mul r0.y, r0, r0.z\n"
	"min r0.y, r0, c128.x\n"
	"dp4 oPos.w, r1, c3\n"
	"dp4 oPos.z, r1, c2\n"
	"dp4 oPos.y, r1, c1\n"
	"dp4 oPos.x, r1, c0\n"
	"max oT1.y, r0.x, c128.z\n"
	"max oT1.x, r0.y, c128.z\n"
	"mov oT0.xy, v2\n"
	"mov oD0.w, c121\n",

	// VP_VS_3_0
	"vs_3_0\n"
	"dcl_position o0\n"
	"dcl_color0 o1\n"
	"dcl_texcoord0 o2\n"
	"dcl_texcoord1 o3\n"
	"def c128, 1.00000000, 3.00000000, 0.00000000, 0.50000000\n"
	"dcl_texcoord1 v3\n"
	"dcl_position0 v0\n"
	"dcl_texcoord2 v4\n"
	"dcl_normal0 v1\n"
	"dcl_texcoord0 v2\n"
	"mul r4.y, v3, c128\n"
	"mul r4.x, v3, c128.y\n"
	"abs r2.x, r4\n"
	"abs r0.y, r4\n"
	"frc r0.z, r0.y\n"
	"frc r2.y, r2.x\n"
	"slt r0.x, r4.y, c128.z\n"
	"max r0.x, -r0, r0\n"
	"slt r0.x, c128.z, r0\n"
	"slt r1.w, r4.x, c128.z\n"
	"max r1.w, -r1, r1\n"
	"slt r1.w, c128.z, r1\n"
	"add r0.y, r0, -r0.z\n"
	"add r0.w, -r0.x, c128.x\n"
	"mul r0.z, r0.y, r0.w\n"
	"mad r1.y, r0.x, -r0, r0.z\n"
	"mov r0.xyz, v0\n"
	"mov r0.w, c128.x\n"
	"mova a0.x, r4.y\n"
	"dp4 r1.x, r0, c[a0.x + 4]\n"
	"mova a0.x, r1.y\n"
	"dp4 r1.y, r0, c[a0.x + 5]\n"
	"dp4 r1.z, r0, c[a0.x + 6]\n"
	"add r2.w, r2.x, -r2.y\n"
	"add r2.z, -r1.w, c128.x\n"
	"mul r3.x, r2.w, r2.z\n"
	"mul r2.xyz, v4.y, r1\n"
	"mad r1.x, r1.w, -r2.w, r3\n"
	"mova a0.y, r1.x\n"
	"mul r3.w, v3.z, c128.y\n"
	"mova a0.z, r4.x\n"
	"dp4 r1.x, r0, c[a0.z + 4]\n"
	"dp4 r1.y, r0, c[a0.y + 5]\n"
	"dp4 r1.z, r0, c[a0.y + 6]\n"
	"mad r2.xyz, v4.x, r1, r2\n"
	"slt r1.w, r3, c128.z\n"
	"max r1.x, -r1.w, r1.w\n"
	"slt r1.x, c128.z, r1\n"
	"abs r1.y, r3.w\n"
	"frc r1.z, r1.y\n"
	"add r1.y, r1, -r1.z\n"
	"add r1.w, -r1.x, c128.x\n"
	"mul r1.z, r1.y, r1.w\n"
	"mul r1.w, v3, c128.y\n"
	"abs r3.y, r1.w\n"
	"slt r3.x, r1.w, c128.z\n"
	"max r3.x, -r3, r3\n"
	"slt r3.x, c128.z, r3\n"
	"frc r4.z, r3.y\n"
	"mad r2.w, r1.x, -r1.y, r1.z\n"
	"mova a0.z, r3.w\n"
	"dp4 r1.x, r0, c[a0.z + 4]\n"
	"mova a0.z, r2.w\n"
	"dp4 r1.y, r0, c[a0.z + 5]\n"
	"dp4 r1.z, r0, c[a0.z + 6]\n"
	"mad r1.xyz, v4.z, r1, r2\n"
	"add r3.y, r3, -r4.z\n"
	"add r3.z, -r3.x, c128.x\n"
	"mul r3.z, r3.y, r3\n"
	"mad r2.x, r3, -r3.y, r3.z\n"
	"mova a0.z, r2.x\n"
	"mova a0.w, r1\n"
	"dp4 r2.x, r0, c[a0.w + 4]\n"
	"dp4 r2.y, r0, c[a0.z + 5]\n"
	"dp4 r2.z, r0, c[a0.z + 6]\n"
	"mad r1.xyz, r2, v4.w, r1\n"
	"add r0.xyz, -r1, c118\n"
	"dp3 r0.w, r0, r0\n"
	"rsq r0.w, r0.w\n"
	"mad r0.xyz, r0.w, r0, -c127\n"
	"mul r3.xyz, r0, c128.w\n"
	"mova a0.w, r4.y\n"
	"dp3 r0.z, c[a0.x + 6], v1\n"
	"dp3 r0.y, c[a0.x + 5], v1\n"
	"dp3 r0.x, c[a0.w + 4], v1\n"
	"mul r2.xyz, v4.y, r0\n"
	"mova a0.x, r4\n"
	"dp3 r0.x, c[a0.x + 4], v1\n"
	"dp3 r0.y, c[a0.y + 5], v1\n"
	"dp3 r0.z, c[a0.y + 6], v1\n"
	"mad r2.xyz, v4.x, r0, r2\n"
	"mova a0.x, r3.w\n"
	"dp3 r0.x, c[a0.x + 4], v1\n"
	"mova a0.x, r2.w\n"
	"dp3 r0.y, c[a0.x + 5], v1\n"
	"dp3 r0.z, c[a0.x + 6], v1\n"
	"mad r2.xyz, v4.z, r0, r2\n"
	"mova a0.x, r1.w\n"
	"dp3 r0.x, c[a0.x + 4], v1\n"
	"dp3 r0.y, c[a0.z + 5], v1\n"
	"dp3 r0.z, c[a0.z + 6], v1\n"
	"mad r0.xyz, v4.w, r0, r2\n"
	"dp3 r2.x, r3, r3\n"
	"dp3 r1.w, r0, r0\n"
	"rsq r1.w, r1.w\n"
	"mul r0.xyz, r1.w, r0\n"
	"rsq r2.x, r2.x\n"
	"mul r2.xyz, r2.x, r3\n"
	"dp3 r2.x, r0, r2\n"
	"mov r1.w, c122\n"
	"mul r3.x, c125.w, r1.w\n"
	"max r1.w, r2.x, c128.z\n"
	"pow r2, r1.w, r3.x\n"
	"dp3 r0.x, r0, -c127\n"
	"max r1.w, r0.x, c128.z\n"
	"mov r2.w, r2.x\n"
	"mov r0.xyz, c120\n"
	"mul r3.xyz, c123, r0\n"
	"mov r2.xyz, c122\n"
	"mov r0.xyz, c121\n"
	"add r3.xyz, r3, c119\n"
	"mul r0.xyz, c124, r0\n"
	"mad r0.xyz, r0, r1.w, r3\n"
	"mov r1.w, c128.x\n"
	"mul r2.xyz, c125, r2\n"
	"mad o1.xyz, r2, r2.w, r0\n"
	"add r0.x, c126.w, -c126.z\n"
	"rcp r0.y, r0.x\n"
	"add r0.x, r1.z, -c126.z\n"
	"mul_sat o3.y, r0.x, r0\n"
	"add r0.y, c126, -c126.x\n"
	"rcp r0.x, r0.w\n"
	"rcp r0.y, r0.y\n"
	"add r0.x, -r0, c126.y\n"
	"dp4 o0.w, r1, c3\n"
	"dp4 o0.z, r1, c2\n"
	"dp4 o0.y, r1, c1\n"
	"dp4 o0.x, r1, c0\n"
	"mul_sat o3.x, r0, r0.y\n"
	"mov o2.xy, v2\n"
	"mov o1.w, c121\n",

	// VP_ARBVP1
	"!!ARBvp1.0\n"
	"",

	// vp_gles2
	"uniform mat4 gPVWMatrix;\n"
	"uniform vec4 gBoneTM[114];\n"
	"uniform vec4 gShineEmissive;\n"
	"uniform vec4 gShineAmbient;\n"
	"uniform vec4 gShineDiffuse;\n"
	"uniform vec4 gShineSpecular;\n"
	"uniform vec4 gLightAmbient;\n"
	"uniform vec4 gLightDiffuse;\n"
	"uniform vec4 gLightSpecular;\n"
	"uniform vec4 FogParam;\n"
	"uniform vec4 CameraWorldPosition;\n"
	"uniform vec4 LightWorldDirection;\n"
	"attribute mediump vec3 modelPosition;\n"
	"attribute mediump vec3 modelNormal;\n"
	"attribute mediump vec2 modelTCoord0;\n"
	"attribute mediump vec4 modelTCoord1;\n"
	"attribute mediump vec4 modelTCoord2;\n"
	"varying mediump vec4 vertexColor;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"void main()\n"
	"{\n"
	"	int i0 = int(modelTCoord1[0])*3;\n"
	"	int i1 = int(modelTCoord1[1])*3;\n"
	"	int i2 = int(modelTCoord1[2])*3;\n"
	"	int i3 = int(modelTCoord1[3])*3;\n"
	"	vec4 inputPos = vec4(modelPosition.x, modelPosition.y, modelPosition.z, 1.0);\n"
	"	vec3 worldPosition = vec3(0, 0, 0);\n"
	"	worldPosition += vec3(dot(inputPos, gBoneTM[i0]), dot(inputPos, gBoneTM[i0 + 1]), dot(inputPos, gBoneTM[i0 + 2])) * modelTCoord2[0];\n"
	"	worldPosition += vec3(dot(inputPos, gBoneTM[i1]), dot(inputPos, gBoneTM[i1 + 1]), dot(inputPos, gBoneTM[i1 + 2])) * modelTCoord2[1];\n"
	"	worldPosition += vec3(dot(inputPos, gBoneTM[i2]), dot(inputPos, gBoneTM[i2 + 1]), dot(inputPos, gBoneTM[i2 + 2])) * modelTCoord2[2];\n"
	"	worldPosition += vec3(dot(inputPos, gBoneTM[i3]), dot(inputPos, gBoneTM[i3 + 1]), dot(inputPos, gBoneTM[i3 + 2])) * modelTCoord2[3];\n"
	"	vec3 worldNormal = vec3(0, 0, 0);\n"
	"	worldNormal += vec3(dot(modelNormal, gBoneTM[i0].xyz), dot(modelNormal, gBoneTM[i0 + 1].xyz), dot(modelNormal, gBoneTM[i0 + 2].xyz)) * modelTCoord2[0];\n"
	"	worldNormal += vec3(dot(modelNormal, gBoneTM[i1].xyz), dot(modelNormal, gBoneTM[i1 + 1].xyz), dot(modelNormal, gBoneTM[i1 + 2].xyz)) * modelTCoord2[1];\n"
	"	worldNormal += vec3(dot(modelNormal, gBoneTM[i2].xyz), dot(modelNormal, gBoneTM[i2 + 1].xyz), dot(modelNormal, gBoneTM[i2 + 2].xyz)) * modelTCoord2[2];\n"	
	"	worldNormal += vec3(dot(modelNormal, gBoneTM[i3].xyz), dot(modelNormal, gBoneTM[i3 + 1].xyz), dot(modelNormal, gBoneTM[i3 + 2].xyz)) * modelTCoord2[3];\n"
	"	worldNormal = normalize(worldNormal);\n"
	"	gl_Position = gPVWMatrix * vec4(worldPosition, 1.0);\n"
	"	vec3 viewVector = normalize(CameraWorldPosition.xyz - worldPosition);\n"
	"	float dist = sqrt((CameraWorldPosition.x - worldPosition.x)*(CameraWorldPosition.x - worldPosition.x) + (CameraWorldPosition.y - worldPosition.y)*(CameraWorldPosition.y - worldPosition.y) + (CameraWorldPosition.z - worldPosition.z)*(CameraWorldPosition.z - worldPosition.z));\n"
	"	vec3 halfVector = normalize((viewVector - LightWorldDirection.xyz)/2.0);\n"
	"	float dotH = dot(worldNormal, halfVector);\n"
	"	float fogValue = (FogParam.y - dist)/(FogParam.y - FogParam.x);\n"
	"	fogValue = clamp(fogValue, 0.0, 1.0);\n"
	"	float fogValueHeight = (-FogParam.z + worldPosition.z)/(FogParam.w - FogParam.z);\n"
	"	fogValueHeight = clamp(fogValueHeight, 0.0, 1.0);\n"
	"	vertexColor.rgb = gShineEmissive.rgb + gShineAmbient.rgb * gLightAmbient.rgb + gShineDiffuse.rgb * gLightDiffuse.rgb * max(dot(worldNormal, -LightWorldDirection.xyz), 0.0) + gShineSpecular.rgb * gLightSpecular.rgb * pow(max(dotH, 0.0), gShineSpecular.a);\n"
	"	vertexColor.a = gShineDiffuse.a;\n"
	"	vertexTCoord0 = modelTCoord0;\n"
	"	vertexTCoord1.x = fogValue;\n"
	"	vertexTCoord1.y = fogValueHeight;\n"
	"}\n"
};

int SkinMaterial::msAllPTextureUnits[1] = { 0 };
int* SkinMaterial::msPTextureUnits[Shader::MAX_PROFILES] =
{
	0,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits
};

int SkinMaterial::msDx9PRegisters[1]= {0};
int SkinMaterial::msOglPRegisters[1] = {1};
int SkinMaterial::msOpenGLES2PRegisters[1] = {0};

int* SkinMaterial::msPRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9PRegisters,
	msDx9PRegisters,
	msDx9PRegisters,
	msOglPRegisters,
	msOpenGLES2PRegisters
};

std::string SkinMaterial::msPPrograms[Shader::MAX_PROFILES] =
{
	// PP_NONE
	"",

	// PP_PS_1_1
	"",

	// PP_PS_2_0
	"ps_2_0\n"
	"dcl_2d s0\n"
	"def c1, 1.00000000, 0, 0, 0\n"
	"dcl t0.xy\n"
	"dcl v0\n"
	"dcl t1.xy\n"
	"mov r0.x, t0\n"
	"add r0.y, -t0, c1.x\n"
	"texld r0, r0, s0\n"
	"mul r0, r0, v0\n"
	"add r0.xyz, r0, -c0\n"
	"mul r0.xyz, t1.x, r0\n"
	"mad r0.xyz, t1.y, r0, c0\n"
	"mov oC0, r0\n",

	// PP_PS_3_0
	"ps_3_0\n"
	"dcl_2d s0\n"
	"def c1, 1.00000000, 0, 0, 0\n"
	"dcl_texcoord0 v1.xy\n"
	"dcl_color0 v0\n"
	"dcl_texcoord1 v2.xy\n"
	"mov r0.x, v1\n"
	"add r0.y, -v1, c1.x\n"
	"texld r0, r0, s0\n"
	"mul r0, r0, v0\n"
	"add r0.xyz, r0, -c0\n"
	"mul r0.xyz, v2.x, r0\n"
	"mad oC0.xyz, v2.y, r0, c0\n"
	"mov oC0.w, r0\n",

	// PP_ARBFP1
	"",

	// fp_gles2
	"varying mediump vec4 vertexColor;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"uniform sampler2D gDiffuseSampler;\n"
	"uniform mediump vec4 FogColor;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 texCoord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	mediump vec4 lastColor = texture2D(gDiffuseSampler, texCoord) * vertexColor;\n"
	"	lastColor.rgb = lastColor.rgb * vertexTCoord1.x + FogColor.rgb * (1.0 - vertexTCoord1.x);\n"
	"	lastColor.rgb = lastColor.rgb * vertexTCoord1.y + FogColor.rgb * (1.0 - vertexTCoord1.y);\n"
	"	gl_FragColor = lastColor;\n"
	"}\n"
};
//----------------------------------------------------------------------------
std::string SkinMaterial::msPPrograms1[Shader::MAX_PROFILES]=
{
	//msPPrograms1[0],
	//msPPrograms1[1],
	//msPPrograms1[2],
	//msPPrograms1[3],
	//msPPrograms1[4],
	//msPPrograsOGLESTest[1]
};
std::string SkinMaterial::msPPrograsOGLESTest[2] =
{
	"varying mediump vec4 vertexColor;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"uniform sampler2D gDiffuseSampler;\n"
	"uniform mediump vec4 FogColor;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 texCoord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	mediump vec4 lastColor = texture2D(gDiffuseSampler, texCoord) * vertexColor;\n"
	"	lastColor.rgb = lastColor.rgb * vertexTCoord1.x + FogColor.rgb * (1.0 - vertexTCoord1.x);\n"
	"	lastColor.rgb = lastColor.rgb * vertexTCoord1.y + FogColor.rgb * (1.0 - vertexTCoord1.y);\n"
	"	gl_FragColor = lastColor;\n"
	"}\n",

	"varying mediump vec4 vertexColor;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"uniform sampler2D gDiffuseSampler;\n"
	"uniform mediump vec4 FogColor;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 texCoord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	mediump vec4 lastColor = texture2D(gDiffuseSampler, texCoord) * vertexColor;\n"
	"	if (lastColor.a < 0.25)\n"
	"	{\n"
	"		discard;\n"
	"	}\n"
	"	else\n"
	"	{\n"
	"		lastColor.rgb = lastColor.rgb * vertexTCoord1.x + FogColor.rgb * (1.0 - vertexTCoord1.x);\n"
	"		lastColor.rgb = lastColor.rgb * vertexTCoord1.y + FogColor.rgb * (1.0 - vertexTCoord1.y);\n"
	"		gl_FragColor = lastColor;\n"
	"	}\n"
	"}\n"
};
//----------------------------------------------------------------------------