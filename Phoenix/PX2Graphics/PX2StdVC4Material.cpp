/*
*
* 文件名称	：	PX2StdVC4Material.cpp
*
*/

#include "PX2StdVC4Material.hpp"
#include "PX2PVWMatrixConstant.hpp"
#include "PX2PMatrixConstant.hpp"
#include "PX2WMatrixConstant.hpp"
#include "PX2ShaderKeys.hpp"
#include "PX2ShineEmissiveConstant.hpp"
#include "PX2ShineAmbientConstant.hpp"
#include "PX2ShineDiffuseConstant.hpp"
#include "PX2ShineSpecularConstant.hpp"
#include "PX2FogParamConstant.hpp"
#include "PX2LightWorldDVectorConstant.hpp"
#include "PX2FogColorConstant.hpp"
#include "PX2CameraWorldPositionConstant.hpp"
#include "PX2LightAmbientConstant.hpp"
#include "PX2LightDiffuseConstant.hpp"
#include "PX2LightSpecularConstant.hpp"
#include "PX2FogColorDistConstant.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Material, StdVC4Material);
PX2_IMPLEMENT_STREAM(StdVC4Material);
PX2_IMPLEMENT_FACTORY(StdVC4Material);
PX2_IMPLEMENT_DEFAULT_NAMES(Material, StdVC4Material);

//----------------------------------------------------------------------------
StdVC4Material::StdVC4Material ()
{
	VertexShader* vshader = new0 VertexShader("PX2.StdVC4",
		4, 4, 12, 0, false);
	vshader->SetInput(0, "modelPosition", Shader::VT_FLOAT3, Shader::VS_POSITION);
	vshader->SetInput(1, "modelNormal", Shader::VT_FLOAT3, Shader::VS_NORMAL);
	vshader->SetInput(2, "modelColor0", Shader::VT_FLOAT4, Shader::VS_COLOR0);
	vshader->SetInput(3, "modelTCoord0", Shader::VT_FLOAT2, Shader::VS_TEXCOORD0);

	vshader->SetOutput(0, "clipPosition", Shader::VT_FLOAT4,Shader::VS_POSITION);
	vshader->SetOutput(1, "vertexColor", Shader::VT_FLOAT4, Shader::VS_COLOR0);
	vshader->SetOutput(2, "vertexTCoord0", Shader::VT_FLOAT2, Shader::VS_TEXCOORD0);
	vshader->SetOutput(3, "vertexTCoord1", Shader::VT_FLOAT2, Shader::VS_TEXCOORD1);

	vshader->SetConstant(0, "PVWMatrix", 4);
	vshader->SetConstant(1, "WMatrix", 4);
	vshader->SetConstant(2, "gShineEmissive", 1);
	vshader->SetConstant(3, "gShineAmbient", 1);
	vshader->SetConstant(4, "gShineDiffuse", 1);
	vshader->SetConstant(5, "gShineSpecular", 1);
	vshader->SetConstant(6, "gLightAmbient", 1);
	vshader->SetConstant(7, "gLightDiffuse", 1);
	vshader->SetConstant(8, "gLightSpecular", 1);
	vshader->SetConstant(9, "FogParam", 1);
	vshader->SetConstant(10, "CameraWorldPosition", 1);
	vshader->SetConstant(11, "LightWorldDirection", 1);
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);

	PixelShader* pshader = new0 PixelShader("PX2.StdVC4",
		3, 1, 3, 1, false);
	pshader->SetInput(0, "vertexColor", Shader::VT_FLOAT4, Shader::VS_COLOR0);
	pshader->SetInput(1, "vertexTCoord0", Shader::VT_FLOAT2, Shader::VS_TEXCOORD0);
	pshader->SetInput(2, "vertexTCoord1", Shader::VT_FLOAT2, Shader::VS_TEXCOORD1);
	pshader->SetOutput(0, "pixelColor", Shader::VT_FLOAT4, Shader::VS_COLOR0);
	pshader->SetConstant(0, "UVOffset", 1);
	pshader->SetConstant(1, "FogColor", 1);
	pshader->SetConstant(2, "FogColorDist", 1);
	pshader->SetSampler(0, "BaseSampler", Shader::ST_2D);
	pshader->SetFilter(0, Shader::SF_LINEAR);
	pshader->SetCoordinate(0, 0, Shader::SC_CLAMP);
	pshader->SetCoordinate(0, 1, Shader::SC_CLAMP);
	pshader->SetTextureUnits(msPTextureUnits);
	pshader->SetBaseRegisters(msPRegisters);
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

	vshader->SetShaderKey(SKT_STDVC4);
	pshader->SetShaderKey(SKT_STDVC4);
}
//----------------------------------------------------------------------------
StdVC4Material::~StdVC4Material ()
{
}
//----------------------------------------------------------------------------
PixelShader* StdVC4Material::GetPixelShader () const
{
	return mTechniques[0]->GetPass(0)->GetPixelShader();
}
//----------------------------------------------------------------------------
MaterialInstance* StdVC4Material::CreateInstance (ShaderFloat *uvFloat, 
	Texture2D* texture,	Shine *shine, Light *light)
{
	if (!uvFloat)
	{
		Float4 offset = Float4::ZERO;
		uvFloat = new0 ShaderFloat(1);
		uvFloat->SetRegister(0, offset);
	}

	if (!shine)
	{
		shine = new0 Shine();
		shine->Emissive = Float4(0.0f, 0.0f, 0.0f, 0.0f);
		shine->Ambient = Float4(1.0f, 1.0f, 1.0f, 1.0f);
		shine->Diffuse = Float4(1.0f, 1.0f, 1.0f, 1.0f);
		shine->Specular =  Float4(1.0f, 1.0f, 1.0f, 10.0f);
	}

	if (!light)
	{
		light = new0 Light(Light::LT_DIRECTIONAL);
		light->Ambient = Float4::WHITE;
		light->Diffuse = Float4::WHITE;
		light->Specular = Float4::ZERO;
	}

	MaterialInstance* instance = new0 MaterialInstance(this, 0);
	instance->SetVertexConstant(0, "PVWMatrix", new0 PVWMatrixConstant());
	instance->SetVertexConstant(0, "WMatrix", new0 WMatrixConstant());
	instance->SetVertexConstant(0, "gShineEmissive", new0 ShineEmissiveConstant(shine));
	instance->SetVertexConstant(0, "gShineAmbient", new0 ShineAmbientConstant(shine));
	instance->SetVertexConstant(0, "gShineDiffuse", new0 ShineDiffuseConstant(shine));
	instance->SetVertexConstant(0, "gShineSpecular", new0 ShineSpecularConstant(shine));
	instance->SetVertexConstant(0, "gLightAmbient", new0 LightAmbientConstant(light));
	instance->SetVertexConstant(0, "gLightDiffuse", new0 LightDiffuseConstant(light));
	instance->SetVertexConstant(0, "gLightSpecular", new0 LightSpecularConstant(light));
	instance->SetVertexConstant(0, "FogParam", new0 FogParamConstant());
	instance->SetVertexConstant(0, "CameraWorldPosition", new0 CameraWorldPositionConstant()); 
	instance->SetVertexConstant(0, "LightWorldDirection", new0 LightWorldDVectorConstant(light));

	instance->SetPixelTexture(0, "BaseSampler", texture);
	instance->SetPixelConstant(0, "UVOffset", uvFloat);
	instance->SetPixelConstant(0, "FogColor", new0 FogColorConstant());
	instance->SetPixelConstant(0, "FogColorDist", new0 FogColorDistConstant());

	return instance;
}
//----------------------------------------------------------------------------
void StdVC4Material::_CalShaderKey ()
{
	MaterialPass* pass = mTechniques[0]->GetPass(0);
	VertexShader* vshader = pass->GetVertexShader();
	PixelShader* pshader = pass->GetPixelShader();

	vshader->SetShaderKey(SKT_STDVC4);
	pshader->SetShaderKey(SKT_STDVC4);

	pshader->SetPrograms(msPPrograms);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
StdVC4Material::StdVC4Material (LoadConstructor value)
	:
Material(value)
{
}
//----------------------------------------------------------------------------
void StdVC4Material::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Material::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(StdVC4Material, source);
}
//----------------------------------------------------------------------------
void StdVC4Material::Link (InStream& source)
{
	Material::Link(source);
}
//----------------------------------------------------------------------------
void StdVC4Material::PostLink ()
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
bool StdVC4Material::Register (OutStream& target) const
{
	return Material::Register(target);
}
//----------------------------------------------------------------------------
void StdVC4Material::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Material::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(StdVC4Material, target);
}
//----------------------------------------------------------------------------
int StdVC4Material::GetStreamingSize (Stream &stream) const
{
	int size = Material::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Profiles.
//----------------------------------------------------------------------------
int StdVC4Material::msDx9VRegisters[12] = { 0, 4, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
int StdVC4Material::msOglVRegisters[12] = { 1, 5, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
int StdVC4Material::msOpenGLES2VRegisters[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int* StdVC4Material::msVRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9VRegisters,
	msDx9VRegisters,
	msDx9VRegisters,
	msOglVRegisters,
	msOpenGLES2VRegisters
};

std::string StdVC4Material::msVPrograms[Shader::MAX_PROFILES] =
{
	// VP_NONE
	"",

	// VP_VS_1_1
	"vs_1_1\n"
	"",

	// VP_VS_2_0
	"vs_2_0\n"
	"def c18, 1.00000000, 0.50000000, 0.00000000, 0\n"
	"dcl_position0 v0\n"
	"dcl_texcoord0 v2\n"
	"dcl_normal0 v1\n"
	"mov r1.w, c18.x\n"
	"mov r1.xyz, v0\n"
	"dp4 r2.w, r1, c6\n"
	"dp3 r2.z, v1, c6\n"
	"dp3 r2.x, v1, c4\n"
	"dp3 r2.y, v1, c5\n"
	"mov r0.z, r2.w\n"
	"dp4 r0.x, r1, c4\n"
	"dp4 r0.y, r1, c5\n"
	"add r0.xyz, -r0, c16\n"
	"dp3 r0.w, r0, r0\n"
	"rsq r3.x, r0.w\n"
	"mad r0.xyz, r3.x, r0, -c17\n"
	"mul r0.xyz, r0, c18.y\n"
	"dp3 r3.y, r0, r0\n"
	"dp3 r0.w, r2, r2\n"
	"rsq r3.y, r3.y\n"
	"rsq r0.w, r0.w\n"
	"mul r2.xyz, r0.w, r2\n"
	"mul r0.xyz, r3.y, r0\n"
	"dp3 r0.x, r2, r0\n"
	"max r3.y, r0.x, c18.z\n"
	"pow r0, r3.y, c11.w\n"
	"mov r0.w, r0.x\n"
	"dp3 r2.x, r2, -c17\n"
	"mov r0.xyz, c9\n"
	"max r3.y, r2.x, c18.z\n"
	"mul r2.xyz, c12, r0\n"
	"mov r0.xyz, c10\n"
	"add r2.xyz, r2, c8\n"
	"mul r0.xyz, c13, r0\n"
	"mad r0.xyz, r0, r3.y, r2\n"
	"rcp r2.x, r3.x\n"
	"add r2.y, c15, -c15.x\n"
	"rcp r2.y, r2.y\n"
	"add r2.x, -r2, c15.y\n"
	"mul r3.x, r2, r2.y\n"
	"mov r2.xyz, c11\n"
	"min r3.x, r3, c18\n"
	"mul r2.xyz, c14, r2\n"
	"mad oD0.xyz, r2, r0.w, r0\n"
	"add r0.x, c15.w, -c15.z\n"
	"rcp r0.y, r0.x\n"
	"add r0.x, r2.w, -c15.z\n"
	"mul r0.x, r0, r0.y\n"
	"min r0.x, r0, c18\n"
	"max oT1.x, r3, c18.z\n"
	"dp4 oPos.w, r1, c3\n"
	"dp4 oPos.z, r1, c2\n"
	"dp4 oPos.y, r1, c1\n"
	"dp4 oPos.x, r1, c0\n"
	"max oT1.y, r0.x, c18.z\n"
	"mov oT0.xy, v2\n"
	"mov oD0.w, c10\n",

	// VP_VS_3_0
	"vs_3_0\n"
	"dcl_position o0\n"
	"dcl_texcoord0 o2\n"
	"dcl_color0 o1\n"
	"dcl_texcoord1 o3\n"
	"def c18, 1.00000000, 0.50000000, 0.00000000, 0\n"
	"dcl_position0 v0\n"
	"dcl_texcoord0 v2\n"
	"dcl_normal0 v1\n"
	"mov r1.w, c18.x\n"
	"mov r1.xyz, v0\n"
	"dp4 r2.w, r1, c6\n"
	"dp3 r2.z, v1, c6\n"
	"dp3 r2.x, v1, c4\n"
	"dp3 r2.y, v1, c5\n"
	"mov r0.z, r2.w\n"
	"dp4 r0.x, r1, c4\n"
	"dp4 r0.y, r1, c5\n"
	"add r0.xyz, -r0, c16\n"
	"dp3 r0.w, r0, r0\n"
	"rsq r3.w, r0.w\n"
	"dp3 r0.w, r2, r2\n"
	"rsq r0.w, r0.w\n"
	"mad r0.xyz, r3.w, r0, -c17\n"
	"mul r0.xyz, r0, c18.y\n"
	"dp3 r3.x, r0, r0\n"
	"rsq r3.x, r3.x\n"
	"mul r0.xyz, r3.x, r0\n"
	"mul r2.xyz, r0.w, r2\n"
	"dp3 r0.x, r2, r0\n"
	"max r3.x, r0, c18.z\n"
	"pow r0, r3.x, c11.w\n"
	"dp3 r0.y, r2, -c17\n"
	"mov r2.xyz, c11\n"
	"mov r0.w, r0.x\n"
	"max r4.x, r0.y, c18.z\n"
	"mov r0.xyz, c9\n"
	"mul r3.xyz, c12, r0\n"
	"mov r0.xyz, c10\n"
	"add r3.xyz, r3, c8\n"
	"mul r0.xyz, c13, r0\n"
	"mad r0.xyz, r0, r4.x, r3\n"
	"mul r2.xyz, c14, r2\n"
	"mad o1.xyz, r2, r0.w, r0\n"
	"add r0.y, c15, -c15.x\n"
	"rcp r0.x, r3.w\n"
	"rcp r0.y, r0.y\n"
	"add r0.x, -r0, c15.y\n"
	"mul_sat o3.x, r0, r0.y\n"
	"add r0.x, c15.w, -c15.z\n"
	"rcp r0.y, r0.x\n"
	"add r0.x, r2.w, -c15.z\n"
	"dp4 o0.w, r1, c3\n"
	"dp4 o0.z, r1, c2\n"
	"dp4 o0.y, r1, c1\n"
	"dp4 o0.x, r1, c0\n"
	"mul_sat o3.y, r0.x, r0\n"
	"mov o2.xy, v2\n"
	"mov o1.w, c10\n",

	// VP_ARBVP1
	"!!ARBvp1.0\n"
	"",

	// vp_gles2
	"uniform mat4 PVWMatrix;\n"
	"uniform mat4 WMatrix;\n"
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
	"attribute mediump vec4 modelColor;\n"
	"attribute mediump vec2 modelTCoord0;\n"
	"varying mediump vec4 vertexColor;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = PVWMatrix * vec4(modelPosition, 1.0);\n"
	"	vec3 worldPosition = (WMatrix * vec4(modelPosition, 1.0)).xyz;\n"
	"	vec4 col0 = WMatrix[0]; vec4 col1 = WMatrix[1]; vec4 col2 = WMatrix[2]; \n"
	"	mat3 worldMat = mat3(col0.xyz, col1.xyz, col2.xyz);\n"
	"	vec3 worldNormal = normalize(worldMat * modelNormal);\n"
	"	vec3 viewVector = normalize(CameraWorldPosition.xyz - worldPosition);\n"
	"	float dist = sqrt((CameraWorldPosition.x - worldPosition.x)*(CameraWorldPosition.x - worldPosition.x) + (CameraWorldPosition.y - worldPosition.y)*(CameraWorldPosition.y - worldPosition.y) + (CameraWorldPosition.z - worldPosition.z)*(CameraWorldPosition.z - worldPosition.z));\n"
	"	vec3 halfVector = normalize((viewVector - LightWorldDirection.xyz)/2.0);\n"
	"	float dotH = dot(worldNormal, halfVector);\n"
	"	float fogValue = (FogParam.y - dist)/(FogParam.y - FogParam.x);\n"
	"	fogValue = clamp(fogValue, 0.0, 1.0);\n"
	"	float fogValueHeight = (-FogParam.z + worldPosition.z)/(FogParam.w - FogParam.z);\n"
	"	fogValueHeight = clamp(fogValueHeight, 0.0, 1.0);\n"
	"	vertexColor = modelColor;\n"
	"	vertexColor.rgb = gShineEmissive.rgb + gShineAmbient.rgb * gLightAmbient.rgb + gShineDiffuse.rgb * gLightDiffuse.rgb * max(dot(worldNormal, -LightWorldDirection.xyz), 0.0) + gShineSpecular.rgb * gLightSpecular.rgb * pow(max(dotH, 0.0), gShineSpecular.a);\n"
	"	vertexColor.a = gLightDiffuse.a;\n"
	"	vertexTCoord0 = modelTCoord0;\n"
	"	vertexTCoord1.x = fogValue;\n"
	"	vertexTCoord1.y = fogValueHeight;\n"
	"}\n"
};

int StdVC4Material::msAllPTextureUnits[1] = { 0 };
int* StdVC4Material::msPTextureUnits[Shader::MAX_PROFILES] =
{
	0,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits
};

int StdVC4Material::msDx9PRegisters[3]= {0, 1, 2};
int StdVC4Material::msOglPRegisters[3] = {1, 2, 3};
int StdVC4Material::msOpenGLES2PRegisters[3] = {0, 1, 2};

int* StdVC4Material::msPRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9PRegisters,
	msDx9PRegisters,
	msDx9PRegisters,
	msOglPRegisters,
	msOpenGLES2PRegisters
};

std::string StdVC4Material::msPPrograms[Shader::MAX_PROFILES] =
{
	// PP_NONE
	"",

	// PP_PS_1_1
	"",

	// PS_2_0
	"ps_2_0\n"
	"dcl_2d s0\n"
	"def c3, 1.00000000, 0, 0, 0\n"
	"dcl t0.xy\n"
	"dcl v0\n"
	"dcl t1.xy\n"
	"mov r0.x, t0\n"
	"add r0.y, -t0, c3.x\n"
	"add r0.xy, r0, c0\n"
	"texld r0, r0, s0\n"
	"mul r0, r0, v0\n"
	"add r0.xyz, r0, -c1\n"
	"mad r0.xyz, t1.y, r0, c1\n"
	"add r0.xyz, r0, -c2\n"
	"mad r0.xyz, t1.x, r0, c2\n"
	"mov oC0, r0\n",

	// PS_3_0
	"ps_3_0\n"
	"dcl_2d s0\n"
	"def c3, 1.00000000, 0, 0, 0\n"
	"dcl_texcoord0 v1.xy\n"
	"dcl_color0 v0\n"
	"dcl_texcoord1 v2.xy\n"
	"mov r0.x, v1\n"
	"add r0.y, -v1, c3.x\n"
	"add r0.xy, r0, c0\n"
	"texld r0, r0, s0\n"
	"mul r0, r0, v0\n"
	"add r0.xyz, r0, -c1\n"
	"mad r0.xyz, v2.y, r0, c1\n"
	"add r0.xyz, r0, -c2\n"
	"mad oC0.xyz, v2.x, r0, c2\n"
	"mov oC0.w, r0\n",

	// PP_ARBFP1
	"",

	// fp_gles2
	"varying mediump vec4 vertexColor;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"uniform sampler2D BaseSampler;\n"
	"uniform mediump vec4 UVOffset;\n"
	"uniform mediump vec4 FogColor;\n"
	"uniform mediump vec4 FogColorDist;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 texCoord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	texCoord.xy += UVOffset.xy;\n"
	"	mediump vec4 lastColor = texture2D(BaseSampler, texCoord)*vertexColor;\n"
	"	lastColor.rgb = lastColor.rgb * vertexTCoord1.x + FogColor.rgb * (1.0 - vertexTCoord1.y);\n"
	"	lastColor.rgb = lastColor.rgb * vertexTCoord1.y + FogColorDist.rgb * (1.0 - vertexTCoord1.x);\n"
	"	gl_FragColor = lastColor;\n"
	"}\n"
};
//----------------------------------------------------------------------------