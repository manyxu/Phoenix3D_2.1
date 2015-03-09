// PX2StandardMaterial.cpp

#include "PX2JunglerMaterial.hpp"
#include "PX2PVWMatrixConstant.hpp"
#include "PX2WMatrixConstant.hpp"
#include "PX2CameraWorldPositionConstant.hpp"
#include "PX2ShineEmissiveConstant.hpp"
#include "PX2ShineAmbientConstant.hpp"
#include "PX2ShineDiffuseConstant.hpp"
#include "PX2ShineSpecularConstant.hpp"
#include "PX2LightAmbientConstant.hpp"
#include "PX2LightDiffuseConstant.hpp"
#include "PX2LightSpecularConstant.hpp"
#include "PX2LightAttenuationConstant.hpp"
#include "PX2LightModelDVectorConstant.hpp"
#include "PX2UserConstant.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Material, JunglerMaterial);
PX2_IMPLEMENT_STREAM(JunglerMaterial);
PX2_IMPLEMENT_FACTORY(JunglerMaterial);
PX2_IMPLEMENT_DEFAULT_NAMES(Material, JunglerMaterial);

//----------------------------------------------------------------------------
JunglerMaterial::JunglerMaterial ()
{
	VertexShader* vshader = new0 VertexShader("PX2.Jungler",
		3, 3, 8, 0, false);
	vshader->SetInput(0, "modelPosition", Shader::VT_FLOAT3,
		Shader::VS_POSITION);
	vshader->SetInput(1, "modelNormal", Shader::VT_FLOAT3,
		Shader::VS_NORMAL);
	vshader->SetInput(2, "modelTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);

	vshader->SetOutput(0, "clipPosition", Shader::VT_FLOAT4,
		Shader::VS_POSITION);
	vshader->SetOutput(1, "vertexTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);
	vshader->SetOutput(2, "vertexTCoord1", Shader::VT_FLOAT4,
		Shader::VS_TEXCOORD1);

	vshader->SetConstant(0, "gPVWMatrix", 4);
	vshader->SetConstant(1, "gShineEmissive", 1);
	vshader->SetConstant(2, "gShineAmbient", 1);
	vshader->SetConstant(3, "gShineDiffuse", 1);
	vshader->SetConstant(4, "gLightColour", 1);
	vshader->SetConstant(5, "gLightAttenuation", 1);
	vshader->SetConstant(6, "gLightModelDirection", 1);
	vshader->SetConstant(7, "gUser", 1);
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);

	PixelShader* pshader = new0 PixelShader("PX2.Jungler",
		2, 1, 0, 1, false);
	pshader->SetInput(0, "vertexTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);
	pshader->SetInput(1, "vertexTCoord1", Shader::VT_FLOAT4,
		Shader::VS_TEXCOORD1);
	pshader->SetOutput(0, "pixelColor", Shader::VT_FLOAT4,
		Shader::VS_COLOR0);

	pshader->SetSampler(0, "gDiffuseSampler", Shader::ST_2D);
	pshader->SetFilter(0, Shader::SF_LINEAR);
	pshader->SetCoordinate(0, 0, Shader::SC_REPEAT);
	pshader->SetCoordinate(0, 1, Shader::SC_REPEAT);
	pshader->SetTextureUnits(msPTextureUnits);
	pshader->SetPrograms(msPPrograms);

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
}
//----------------------------------------------------------------------------
JunglerMaterial::~JunglerMaterial ()
{
}
//----------------------------------------------------------------------------
MaterialInstance* JunglerMaterial::CreateInstance (
	PX2::Texture2D *diffTex, PX2::Light *dirLight, PX2::Shine* shine) const
{
	MaterialInstance *instance = new0 MaterialInstance(this, 0);

	if (!dirLight)
	{
		dirLight = new0 Light(Light::LT_DIRECTIONAL);
		dirLight->Ambient = Float4(1.0f, 1.0f, 1.0f, 1.0f);
		dirLight->Diffuse = Float4(1.0f, 1.0f, 1.0f, 1.0f);
	}
	if (!shine)
	{
		shine = new0 Shine();
		shine->Ambient = Float4(0.3f, 0.3f, 0.3f, 1.0f);
		shine->Diffuse = Float4(1.0f, 1.0f, 1.0f, 1.0f);
	}

	// vertex
	instance->SetVertexConstant(0, "gPVWMatrix", new0 PVWMatrixConstant());
	instance->SetVertexConstant(0, "gShineEmissive", 
		new0 ShineEmissiveConstant());
	instance->SetVertexConstant(0, "gShineAmbient",
		new0 ShineAmbientConstant());
	instance->SetVertexConstant(0, "gShineDiffuse",
		new0 ShineDiffuseConstant());
	instance->SetVertexConstant(0, "gLightColour",
		new0 LightDiffuseConstant(dirLight));
	instance->SetVertexConstant(0, "gLightAttenuation",
		new0 LightAttenuationConstant(dirLight));
	instance->SetVertexConstant(0, "gLightModelDirection",
		new0 LightModelDVectorConstant(dirLight));
	UserConstantPtr userConst = new0 UserConstant();
	instance->SetVertexConstant(0, "gUser", userConst);
	ShaderFloat *cSF = instance->GetVertexConstant(0, "gUser");
	(*cSF)[0] = 0.0f;
	(*cSF)[1] = 1.0f;
	(*cSF)[2] = 0.1f;

	// pixel
	instance->SetPixelTexture(0, "gDiffuseSampler", diffTex);

	return instance;
}
//----------------------------------------------------------------------------
MaterialInstance* JunglerMaterial::CreateUniqueInstance (	
	Texture2D *diffTex, Light *dirLight, Shine* shine)
{
	JunglerMaterial *mtl = new0 JunglerMaterial(); 
	return mtl->CreateInstance(diffTex, dirLight, shine);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
JunglerMaterial::JunglerMaterial (LoadConstructor value)
	:
Material(value)
{
}
//----------------------------------------------------------------------------
void JunglerMaterial::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Material::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(JunglerMaterial, source);
}
//----------------------------------------------------------------------------
void JunglerMaterial::Link (InStream& source)
{
	Material::Link(source);
}
//----------------------------------------------------------------------------
void JunglerMaterial::PostLink ()
{
	Material::PostLink();

	MaterialPass* pass = mTechniques[0]->GetPass(0);
	VertexShader* vshader = pass->GetVertexShader();
	PixelShader* pshader = pass->GetPixelShader();
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);
	pshader->SetTextureUnits(msPTextureUnits);
	pshader->SetPrograms(msPPrograms);
}
//----------------------------------------------------------------------------
bool JunglerMaterial::Register (OutStream& target) const
{
	if (Material::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void JunglerMaterial::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Material::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(JunglerMaterial, target);
}
//----------------------------------------------------------------------------
int JunglerMaterial::GetStreamingSize (Stream &stream) const
{
	int size = Material::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	return size;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// profile
//----------------------------------------------------------------------------
int JunglerMaterial::msDx9VRegisters[8] =
{ 0, 4, 5, 6, 7, 8, 9, 10};
int JunglerMaterial::msOglVRegisters[8] =
{ 1, 5, 6, 7, 8, 9, 10, 11};
int JunglerMaterial::msOpenGLES2VRegisters[8] = 
{ 0, 0, 0, 0, 0, 0, 0, 0};
int* JunglerMaterial::msVRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9VRegisters,
	msDx9VRegisters,
	msDx9VRegisters,
	msOglVRegisters,
	msOpenGLES2VRegisters
};

std::string JunglerMaterial::msVPrograms[Shader::MAX_PROFILES] =
{
	// VP_NONE
	"",

	// VP_VS_1_1
	"",

	// VP_VS_2_0
	"vs_2_0\n"
	"dcl_position0 v0\n"
	"def c11, -0.02083333, -0.12500000, 1.00000000, 0.50000000\n"
	"def c12, -0.00000155, -0.00002170, 0.00260417, 0.00026042\n"
	"def c13, 0.15915491, 0.50000000, 6.28318501, -3.14159298\n"
	"def c14, 0.00000000, 0, 0, 0\n"
	"dcl_normal0 v1\n"
	"dcl_texcoord0 v2\n"
	"mad r0.x, c10, c10.y, v0.y\n"
	"mad r0.x, r0, c13, c13.y\n"
	"frc r0.x, r0\n"
	"mad r0.x, r0, c13.z, c13.w\n"
	"sincos r2.xy, r0.x, c12.xyzw, c11.xyzw\n"
	"mov r0.xyz, c7\n"
	"mul r0.xyz, c5, r0\n"
	"dp3 r0.w, v1, -c9\n"
	"abs r0.w, r0\n"
	"mul r1.xyz, v1, c10.z\n"
	"mul r1.xyz, r1, r2.y\n"
	"mul r0.xyz, r0, c8.w\n"
	"add r2.xyz, r0, c4\n"
	"mov r0.xyz, c7\n"
	"max r0.w, r0, c14.x\n"
	"mul r0.xyz, c6, r0\n"
	"mul r0.xyz, r0, r0.w\n"
	"mov r0.w, c11.z\n"
	"mul r1.xyz, r1, v2.y\n"
	"mad oT1.xyz, r0, c8.w, r2\n"
	"mul r0.xyz, r1, v2.y\n"
	"add r0.xyz, r0, v0\n"
	"dp4 oPos.w, r0, c3\n"
	"dp4 oPos.z, r0, c2\n"
	"dp4 oPos.y, r0, c1\n"
	"dp4 oPos.x, r0, c0\n"
	"mov oT0.xy, v2\n"
	"mov oT1.w, c6\n",

	// VP_VS_3_0
	"vs_3_0\n"
	"dcl_position0 v0\n"
	"dcl_position o0\n"
	"dcl_texcoord0 o1\n"
	"dcl_texcoord1 o2\n"
	"def c11, 0.15915491, 0.50000000, 6.28318501, -3.14159298\n"
	"def c12, 1.00000000, 0.00000000, 0, 0\n"
	"dcl_normal0 v1\n"
	"dcl_texcoord0 v2\n"
	"mad r0.x, c10, c10.y, v0.y\n"
	"mad r0.x, r0, c11, c11.y\n"
	"frc r0.x, r0\n"
	"mad r0.x, r0, c11.z, c11.w\n"
	"sincos r2.xy, r0.x\n"
	"mov r0.xyz, c7\n"
	"mul r0.xyz, c5, r0\n"
	"dp3 r0.w, v1, -c9\n"
	"abs r0.w, r0\n"
	"mul r1.xyz, v1, c10.z\n"
	"mul r1.xyz, r1, r2.y\n"
	"mul r0.xyz, r0, c8.w\n"
	"add r2.xyz, r0, c4\n"
	"mov r0.xyz, c7\n"
	"max r0.w, r0, c12.y\n"
	"mul r0.xyz, c6, r0\n"
	"mul r0.xyz, r0, r0.w\n"
	"mov r0.w, c12.x\n"
	"mul r1.xyz, r1, v2.y\n"
	"mad o2.xyz, r0, c8.w, r2\n"
	"mul r0.xyz, r1, v2.y\n"
	"add r0.xyz, r0, v0\n"
	"dp4 o0.w, r0, c3\n"
	"dp4 o0.z, r0, c2\n"
	"dp4 o0.y, r0, c1\n"
	"dp4 o0.x, r0, c0\n"
	"mov o1.xy, v2\n"
	"mov o2.w, c6\n",

	// VP_ARBVP1
	"",

	// vp_gles2
	"uniform mat4 gPVWMatrix;\n"
	"uniform mediump vec4 gShineEmissive;\n"
	"uniform mediump vec4 gShineAmbient;\n"
	"uniform mediump vec4 gShineDiffuse;\n"
	"uniform mediump vec4 gLightColour;\n"
	"uniform mediump vec4 gLightAttenuation;\n"
	"uniform mediump vec4 gLightModelDirection;\n"
	"uniform mediump vec4 gUser;\n"
	"attribute vec3 modelPosition;\n"
	"attribute vec3 modelNormal;\n"
	"attribute vec2 modelTCoord0;\n"
	"varying vec2 vertexTCoord0;\n"
	"varying vec4 vertexTCoord1;\n"
	"void main()\n"
	"{\n"
	"	mediump float valSin = sin(gUser.x*gUser.y + modelPosition.y);"
	"	mediump vec3 mpTrans = modelPosition + modelNormal * gUser.z * valSin * modelTCoord0.y*modelTCoord0.y;"
	"	gl_Position = gPVWMatrix*vec4(mpTrans, 1.0);\n"
	"	vertexTCoord0 = vec2(modelTCoord0.x, 1.0-modelTCoord0.y);\n"
	"	vertexTCoord1.rgb = gShineEmissive.rgb"
	"		+ gLightColour.rgb*gShineAmbient.rgb*gLightAttenuation[3]"
	"		+ gLightColour.rgb*gShineDiffuse.rgb* max(0.0, abs(dot(modelNormal, -gLightModelDirection.rgb)))*gLightAttenuation[3];\n"
	"	vertexTCoord1.a = gShineDiffuse.a;\n"
	"}\n"
};

int JunglerMaterial::msAllPTextureUnits[1] = { 0 };
int* JunglerMaterial::msPTextureUnits[Shader::MAX_PROFILES] =
{
	0,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits
};

std::string JunglerMaterial::msPPrograms[Shader::MAX_PROFILES] =
{
	// PP_NONE
	"",

	// PP_PS_1_1
	"",

	// PP_PS_2_0
	"ps_2_0\n"
	"dcl_2d s0\n"
	"def c0, 1.00000000, 0, 0, 0\n"
	"dcl t0.xy\n"
	"dcl t1\n"
	"add r0.y, -t0, c0.x\n"
	"mov r0.x, t0\n"
	"texld r0, r0, s0\n"
	"mul r0, r0, t1\n"
	"mov oC0, r0\n",

	// PP_PS_3_0
	"ps_3_0\n"
	"dcl_2d s0\n"
	"def c0, 1.00000000, 0, 0, 0\n"
	"dcl_texcoord0 v0.xy\n"
	"dcl_texcoord1 v1\n"
	"add r0.y, -v0, c0.x\n"
	"mov r0.x, v0\n"
	"texld r0, r0, s0\n"
	"mul oC0, r0, v1\n",

	// PP_ARBFP1
	"",

	// fp_gles2
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec4 vertexTCoord1;\n"
	"uniform sampler2D gDiffuseSampler;\n"
	"void main()\n"
	"{\n"
	"	mediump vec4 color = texture2D(gDiffuseSampler, vertexTCoord0)*vertexTCoord1;\n"
	"	if (color.a < 0.2)\n"
	"		discard;\n"
	"	else\n"
	"		gl_FragColor = texture2D(gDiffuseSampler, vertexTCoord0)*vertexTCoord1;\n"
	"}\n"
};
//----------------------------------------------------------------------------
