// PX2LightTex2Material.cpp

#include "PX2LightTex2Material.hpp"
#include "PX2PVWMatrixConstant.hpp"
#include "PX2WMatrixConstant.hpp"
#include "PX2CameraWorldPositionConstant.hpp"
#include "PX2LightWorldDVectorConstant.hpp"
#include "PX2LightDiffuseConstant.hpp"
#include "PX2LightSpecularConstant.hpp"
#include "PX2FogColorConstant.hpp"
#include "PX2FogParamConstant.hpp"
#include "PX2ShaderKeys.hpp"
#include "PX2FogColorDistConstant.hpp"
#include "PX2ShineSpecularConstant.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Material, LightTex2Material);
PX2_IMPLEMENT_STREAM(LightTex2Material);
PX2_IMPLEMENT_FACTORY(LightTex2Material);
PX2_IMPLEMENT_DEFAULT_NAMES(Material, LightTex2Material);

//----------------------------------------------------------------------------
LightTex2Material::LightTex2Material ()
{
	VertexShader* vshader = new0 VertexShader("PX2.LightTex2",
		4, 5, 7, 0, false);
	vshader->SetInput(0, "modelPosition", Shader::VT_FLOAT3, Shader::VS_POSITION);
	vshader->SetInput(1, "modelNormal", Shader::VT_FLOAT3, Shader::VS_NORMAL);
	vshader->SetInput(2, "modelTCoord0", Shader::VT_FLOAT2,	Shader::VS_TEXCOORD0);
	vshader->SetInput(3, "modelTCoord1", Shader::VT_FLOAT2,	Shader::VS_TEXCOORD1);

	vshader->SetOutput(0, "clipPosition", Shader::VT_FLOAT4, Shader::VS_POSITION);
	vshader->SetOutput(1, "vertexColor", Shader::VT_FLOAT4, Shader::VS_COLOR0);
	vshader->SetOutput(2, "vertexTCoord0", Shader::VT_FLOAT2, Shader::VS_TEXCOORD0);
	vshader->SetOutput(3, "vertexTCoord1", Shader::VT_FLOAT2, Shader::VS_TEXCOORD1);
	vshader->SetOutput(4, "vertexTCoord2", Shader::VT_FLOAT2, Shader::VS_TEXCOORD2);

	vshader->SetConstant(0, "PVWMatrix", 4);
	vshader->SetConstant(1, "WMatrix", 4);
	vshader->SetConstant(2, "CameraWorldPosition", 1);
	vshader->SetConstant(3, "gShineSpecular", 1);
	vshader->SetConstant(4, "LightWorldDirection", 1);
	vshader->SetConstant(5, "LightSpecular", 1);
	vshader->SetConstant(6, "FogParam", 1);
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);

	PixelShader* pshader = new0 PixelShader("PX2.LightTex2",
		4, 1, 2, 2, false);
	pshader->SetInput(0, "vertexColor", Shader::VT_FLOAT4, Shader::VS_COLOR0);
	pshader->SetInput(1, "vertexTCoord0", Shader::VT_FLOAT2, Shader::VS_TEXCOORD0);
	pshader->SetInput(2, "vertexTCoord1", Shader::VT_FLOAT2, Shader::VS_TEXCOORD1);
	pshader->SetInput(3, "vertexTCoord2", Shader::VT_FLOAT2, Shader::VS_TEXCOORD2);

	pshader->SetOutput(0, "pixelColor", Shader::VT_FLOAT4, Shader::VS_COLOR0);
	pshader->SetConstant(0, "FogColor", 1);
	pshader->SetConstant(1, "FogColorDist", 1);
	pshader->SetSampler(0, "Sampler0", Shader::ST_2D);
	pshader->SetSampler(1, "Sampler1", Shader::ST_2D);
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

	vshader->SetShaderKey(SKT_LIGHTTEX2);
	pshader->SetShaderKey(SKT_LIGHTTEX2);
}
//----------------------------------------------------------------------------
LightTex2Material::~LightTex2Material ()
{
}
//----------------------------------------------------------------------------
PixelShader* LightTex2Material::GetPixelShader () const
{
	return mTechniques[0]->GetPass(0)->GetPixelShader();
}
//----------------------------------------------------------------------------
MaterialInstance* LightTex2Material::CreateInstance (Texture2D* texture0,
	Texture2D* texture1, Shine *shine, Light *dirLight) const
{
	if (!dirLight)
	{
		dirLight = new0 Light(Light::LT_DIRECTIONAL);
		dirLight->Ambient = Float4(1.0f, 1.0f, 1.0f, 1.0f);
		dirLight->Diffuse = Float4(1.0f, 1.0f, 1.0f, 1.0f);
	}

	MaterialInstance* instance = new0 MaterialInstance(this, 0);
	instance->SetVertexConstant(0, 0, new0 PVWMatrixConstant());
	instance->SetVertexConstant(0, 1, new0 WMatrixConstant());
	instance->SetVertexConstant(0, 2, new0 CameraWorldPositionConstant());
	instance->SetVertexConstant(0, 3, new0 ShineSpecularConstant(shine));
	instance->SetVertexConstant(0, 4, new0 LightWorldDVectorConstant(dirLight));
	instance->SetVertexConstant(0, 5, new0 LightSpecularConstant(dirLight));
	instance->SetVertexConstant(0, 6, new0 FogParamConstant());
	instance->SetPixelTexture(0, 0, texture0);
	instance->SetPixelTexture(0, 1, texture1);
	instance->SetPixelConstant(0, 0, new0 FogColorConstant());
	instance->SetPixelConstant(0, 1, new0 FogColorDistConstant());

	PixelShader* pshader = GetPixelShader();
	pshader->SetFilter(0, Shader::SF_LINEAR);
	pshader->SetFilter(1, Shader::SF_LINEAR);
	pshader->SetCoordinate(0, 0, Shader::SC_CLAMP);
	pshader->SetCoordinate(0, 1, Shader::SC_CLAMP);
	pshader->SetCoordinate(1, 0, Shader::SC_CLAMP);
	pshader->SetCoordinate(1, 1, Shader::SC_CLAMP);

	return instance;
}
//----------------------------------------------------------------------------
void LightTex2Material::_CalShaderKey ()
{
	MaterialPass* pass = mTechniques[0]->GetPass(0);
	VertexShader* vshader = pass->GetVertexShader();
	PixelShader* pshader = pass->GetPixelShader();

	if (!GetAlphaProperty(0, 0)->CompareEnabled)
	{
		vshader->SetShaderKey(SKT_LIGHTTEX2);
		pshader->SetShaderKey(SKT_LIGHTTEX2);

		pshader->SetPrograms(msPPrograms);
	}
	else
	{
		vshader->SetShaderKey(SKT_LIGHTTEX2_ALPHATEST);
		pshader->SetShaderKey(SKT_LIGHTTEX2_ALPHATEST);

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
// Streaming support.
//----------------------------------------------------------------------------
LightTex2Material::LightTex2Material (LoadConstructor value)
	:
Material(value)
{
}
//----------------------------------------------------------------------------
void LightTex2Material::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Material::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(LightTex2Material, source);
}
//----------------------------------------------------------------------------
void LightTex2Material::Link (InStream& source)
{
	Material::Link(source);
}
//----------------------------------------------------------------------------
void LightTex2Material::PostLink ()
{
	Material::PostLink();

	MaterialPass* pass = mTechniques[0]->GetPass(0);
	VertexShader* vshader = pass->GetVertexShader();
	PixelShader* pshader = pass->GetPixelShader();
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);
	pshader->SetTextureUnits(msPTextureUnits);
	pshader->SetBaseRegisters(msPRegisters);

	_CalShaderKey();
}
//----------------------------------------------------------------------------
bool LightTex2Material::Register (OutStream& target) const
{
	return Material::Register(target);
}
//----------------------------------------------------------------------------
void LightTex2Material::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Material::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(LightTex2Material, target);
}
//----------------------------------------------------------------------------
int LightTex2Material::GetStreamingSize (Stream &stream) const
{
	int size = Material::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Profiles.
//----------------------------------------------------------------------------
int LightTex2Material::msDx9VRegisters[7] = { 0, 4, 8, 9, 10, 11, 12};
int LightTex2Material::msOglVRegisters[7] = { 1, 5, 9, 10, 11, 12, 13};
int LightTex2Material::msOpenGLES2VRegisters[7] = { 0, 0, 0, 0, 0, 0, 0};
int* LightTex2Material::msVRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9VRegisters,
	msDx9VRegisters,
	msDx9VRegisters,
	msOglVRegisters,
	msOpenGLES2VRegisters
};

std::string LightTex2Material::msVPrograms[Shader::MAX_PROFILES] =
{
	// VS_NONE
	"",

	// VS_1_1
	"vs_1_1\n"
	"",

	// VS_2_0
	"vs_2_0\n"
	"def c13, 1.00000000, 0.50000000, 0.00000000, 0\n"
	"dcl_position0 v0\n"
	"dcl_texcoord0 v2\n"
	"dcl_texcoord1 v3\n"
	"dcl_normal0 v1\n"
	"mov r1.w, c13.x\n"
	"mov r1.xyz, v0\n"
	"dp4 r2.w, r1, c6\n"
	"mov r0.z, r2.w\n"
	"dp4 r0.x, r1, c4\n"
	"dp4 r0.y, r1, c5\n"
	"add r0.xyz, -r0, c8\n"
	"dp3 r0.w, r0, r0\n"
	"rsq r3.x, r0.w\n"
	"mad r0.xyz, r3.x, r0, -c10\n"
	"mul r2.xyz, r0, c13.y\n"
	"dp3 r0.w, r2, r2\n"
	"rsq r3.y, r0.w\n"
	"dp3 r0.z, v1, c6\n"
	"dp3 r0.x, v1, c4\n"
	"dp3 r0.y, v1, c5\n"
	"dp3 r3.z, r0, r0\n"
	"rsq r0.w, r3.z\n"
	"mul r0.xyz, r0.w, r0\n"
	"mul r2.xyz, r3.y, r2\n"
	"dp3 r0.x, r0, r2\n"
	"max r2.x, r0, c13.z\n"
	"pow r0, r2.x, c9.w\n"
	"mov r0.w, r0.x\n"
	"add r0.y, c12, -c12.x\n"
	"rcp r0.x, r3.x\n"
	"rcp r0.y, r0.y\n"
	"add r0.x, -r0, c12.y\n"
	"mul r2.x, r0, r0.y\n"
	"mov r0.xyz, c9\n"
	"mul r0.xyz, c11, r0\n"
	"mul oD0.xyz, r0, r0.w\n"
	"add r0.x, c12.w, -c12.z\n"
	"rcp r0.y, r0.x\n"
	"min r2.x, r2, c13\n"
	"add r0.x, r2.w, -c12.z\n"
	"mul r0.x, r0, r0.y\n"
	"min r0.x, r0, c13\n"
	"max oT2.x, r2, c13.z\n"
	"dp4 oPos.w, r1, c3\n"
	"dp4 oPos.z, r1, c2\n"
	"dp4 oPos.y, r1, c1\n"
	"dp4 oPos.x, r1, c0\n"
	"max oT2.y, r0.x, c13.z\n"
	"mov oT0.xy, v2\n"
	"mov oT1.xy, v3\n"
	"mov oD0.w, c13.x\n",

	// VS_3_0
	"vs_3_0\n"
	"dcl_position o0\n"
	"dcl_texcoord0 o2\n"
	"dcl_texcoord1 o3\n"
	"dcl_color0 o1\n"
	"dcl_texcoord2 o4\n"
	"def c13, 1.00000000, 0.50000000, 0.00000000, 0\n"
	"dcl_position0 v0\n"
	"dcl_texcoord0 v2\n"
	"dcl_texcoord1 v3\n"
	"dcl_normal0 v1\n"
	"mov r1.w, c13.x\n"
	"mov r1.xyz, v0\n"
	"dp4 r2.w, r1, c6\n"
	"mov r0.z, r2.w\n"
	"dp4 r0.x, r1, c4\n"
	"dp4 r0.y, r1, c5\n"
	"add r0.xyz, -r0, c8\n"
	"dp3 r0.w, r0, r0\n"
	"rsq r3.x, r0.w\n"
	"mad r0.xyz, r3.x, r0, -c10\n"
	"mul r2.xyz, r0, c13.y\n"
	"dp3 r0.w, r2, r2\n"
	"rsq r3.y, r0.w\n"
	"mul r2.xyz, r3.y, r2\n"
	"dp3 r0.z, v1, c6\n"
	"dp3 r0.x, v1, c4\n"
	"dp3 r0.y, v1, c5\n"
	"dp3 r3.z, r0, r0\n"
	"rsq r0.w, r3.z\n"
	"mul r0.xyz, r0.w, r0\n"
	"dp3 r0.x, r0, r2\n"
	"max r2.x, r0, c13.z\n"
	"pow r0, r2.x, c9.w\n"
	"mov r0.w, r0.x\n"
	"mov r2.xyz, c9\n"
	"mul r0.xyz, c11, r2\n"
	"mul o1.xyz, r0, r0.w\n"
	"add r0.y, c12, -c12.x\n"
	"rcp r0.x, r3.x\n"
	"rcp r0.y, r0.y\n"
	"add r0.x, -r0, c12.y\n"
	"mul_sat o4.x, r0, r0.y\n"
	"add r0.x, c12.w, -c12.z\n"
	"rcp r0.y, r0.x\n"
	"add r0.x, r2.w, -c12.z\n"
	"dp4 o0.w, r1, c3\n"
	"dp4 o0.z, r1, c2\n"
	"dp4 o0.y, r1, c1\n"
	"dp4 o0.x, r1, c0\n"
	"mul_sat o4.y, r0.x, r0\n"
	"mov o2.xy, v2\n"
	"mov o3.xy, v3\n"
	"mov o1.w, c13.x\n",

	// ARBVP1
	"!!ARBvp1.0\n"
	"",

	// vp_gles2
	"uniform mat4 PVWMatrix;\n"
	"uniform mat4 WMatrix;\n"
	"uniform vec4 CameraWorldPosition;\n"
	"uniform vec4 gShineSpecular;\n"
	"uniform vec4 LightWorldDirection;\n"
	"uniform vec4 LightSpecular;\n"
	"uniform vec4 FogParam;\n"
	"attribute mediump vec3 modelPosition;\n"
	"attribute mediump vec3 modelNormal;\n"
	"attribute mediump vec2 modelTCoord0;\n"
	"attribute mediump vec2 modelTCoord1;\n"
	"varying mediump vec4 vertexColor;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"varying mediump vec2 vertexTCoord2;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = PVWMatrix * vec4(modelPosition, 1.0);\n"
	"	vertexTCoord0 = modelTCoord0;\n"
	"	vertexTCoord1 = modelTCoord1;\n"
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
	"	vertexColor.rgb = gShineSpecular.rgb*LightSpecular.rgb*pow(max(dotH, 0.0), gShineSpecular.a);\n"
	"	vertexColor.a = 1.0;\n"
	"	vertexTCoord2.x = fogValue;\n"
	"	vertexTCoord2.y = fogValueHeight;\n"
	"}\n"
};

int LightTex2Material::msAllPTextureUnits[2] = { 0, 1 };
int LightTex2Material::msDx9PRegisters[2]= {0, 1};
int LightTex2Material::msOglPRegisters[2] = {1, 2};
int LightTex2Material::msOpenGLES2PRegisters[2] = {0, 1};
int* LightTex2Material::msPTextureUnits[Shader::MAX_PROFILES] =
{
	0,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits
};
int* LightTex2Material::msPRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9PRegisters,
	msDx9PRegisters,
	msDx9PRegisters,
	msOglPRegisters,
	msOpenGLES2PRegisters
};

std::string LightTex2Material::msPPrograms[Shader::MAX_PROFILES] =
{
	// PS_NONE
	"",

	// PS_1_1
	"ps.1.1\n"
	"tex t0\n"
	"tex t1\n"
	"mul r0, t0, t1\n",

	// PS_2_0
	"ps_2_0\n"
	"dcl_2d s0\n"
	"dcl_2d s1\n"
	"def c2, 1.00000000, 0, 0, 0\n"
	"dcl t0.xy\n"
	"dcl t1.xy\n"
	"dcl v0.xyz\n"
	"dcl t2.xy\n"
	"add r1.y, -t0, c2.x\n"
	"mov r1.x, t0\n"
	"mov r0.x, t1\n"
	"add r0.y, -t1, c2.x\n"
	"texld r0, r0, s1\n"
	"texld r1, r1, s0\n"
	"mul r0.xyz, r1, r0\n"
	"mad r0.xyz, r0, c0.w, v0\n"
	"add r0.xyz, r0, -c0\n"
	"mad r0.xyz, t2.y, r0, c0\n"
	"add r0.xyz, r0, -c1\n"
	"mad r0.xyz, t2.x, r0, c1\n"
	"mov r0.w, r1\n"
	"mov oC0, r0\n",

	// PS_3_0
	"ps_3_0\n"
	"dcl_2d s0\n"
	"dcl_2d s1\n"
	"def c2, 1.00000000, 0, 0, 0\n"
	"dcl_texcoord0 v1.xy\n"
	"dcl_texcoord1 v2.xy\n"
	"dcl_color0 v0.xyz\n"
	"dcl_texcoord2 v3.xy\n"
	"mov r0.x, v2\n"
	"add r0.y, -v2, c2.x\n"
	"texld r1.xyz, r0, s1\n"
	"mov r0.x, v1\n"
	"add r0.y, -v1, c2.x\n"
	"texld r0, r0, s0\n"
	"mul r0.xyz, r0, r1\n"
	"mad r0.xyz, r0, c0.w, v0\n"
	"add r0.xyz, r0, -c0\n"
	"mad r0.xyz, v3.y, r0, c0\n"
	"add r0.xyz, r0, -c1\n"
	"mad oC0.xyz, v3.x, r0, c1\n"
	"mov oC0.w, r0\n",

	// ARBFP1
	"!!ARBfp1.0\n"
	"",

	// fp_gles2
	"varying mediump vec4 vertexColor;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"varying mediump vec2 vertexTCoord2;\n"
	"uniform sampler2D Sampler0;\n"
	"uniform sampler2D Sampler1;\n"
	"uniform mediump vec4 FogColor;\n"
	"uniform mediump vec4 FogColorDist;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 texCoord0 = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	mediump vec2 texCoord1 = vec2(vertexTCoord1.x, 1.0-vertexTCoord1.y);\n"
	"	mediump vec4 color0 = texture2D(Sampler0, texCoord0);\n"
	"	mediump vec4 color1 = texture2D(Sampler1, texCoord1);\n"
	"	mediump vec4 lastColor = color0*color1*FogColor.a + vertexColor;\n"
	"	lastColor.rgb = lastColor.rgb * vertexTCoord2.y + FogColor.rgb * (1.0 - vertexTCoord2.y);\n"
	"	lastColor.rgb = lastColor.rgb * vertexTCoord2.x + FogColorDist.rgb * (1.0 - vertexTCoord2.x);\n"
	"	gl_FragColor.rgb = lastColor.rgb;\n"
	"	gl_FragColor.a = color0.a;\n"
	"}\n"
};
//----------------------------------------------------------------------------
std::string LightTex2Material::msPPrograsOGLESTest[2] = 
{
	"varying mediump vec4 vertexColor;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"varying mediump vec2 vertexTCoord2;\n"
	"uniform sampler2D Sampler0;\n"
	"uniform sampler2D Sampler1;\n"
	"uniform mediump vec4 FogColor;\n"
	"uniform mediump vec4 FogColorDist;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 texCoord0 = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	mediump vec2 texCoord1 = vec2(vertexTCoord1.x, 1.0-vertexTCoord1.y);\n"
	"	mediump vec4 color0 = texture2D(Sampler0, texCoord0);\n"
	"	mediump vec4 color1 = texture2D(Sampler1, texCoord1);\n"
	"	mediump vec4 lastColor = color0*color1*FogColor.a + vertexColor;\n"
	"	lastColor.rgb = lastColor.rgb * vertexTCoord2.y + FogColor.rgb * (1.0 - vertexTCoord2.y);\n"
	"	lastColor.rgb = lastColor.rgb * vertexTCoord2.x + FogColorDist.rgb * (1.0 - vertexTCoord2.x);\n"
	"	gl_FragColor.rgb = lastColor.rgb;\n"
	"	gl_FragColor.a = color0.a;\n"
	"}\n",

	"varying mediump vec4 vertexColor;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"varying mediump vec2 vertexTCoord2;\n"
	"uniform sampler2D Sampler0;\n"
	"uniform sampler2D Sampler1;\n"
	"uniform mediump vec4 FogColor;\n"
	"uniform mediump vec4 FogColorDist;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 texCoord0 = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	mediump vec2 texCoord1 = vec2(vertexTCoord1.x, 1.0-vertexTCoord1.y);\n"
	"	mediump vec4 color0 = texture2D(Sampler0, texCoord0);\n"
	"	if (color0.a < 0.25)\n"
	"	{"
	"		discard;\n"
	"	}"
	"	else"
	"	{"
	"		mediump vec4 color1 = texture2D(Sampler1, texCoord1);\n"
	"		mediump vec4 lastColor = color0*color1*FogColor.a + vertexColor;\n"
	"		lastColor.rgb = lastColor.rgb * vertexTCoord2.y + FogColor.rgb * (1.0 - vertexTCoord2.y);\n"
	"		lastColor.rgb = lastColor.rgb * vertexTCoord2.x + FogColorDist.rgb * (1.0 - vertexTCoord2.x);\n"
	"		gl_FragColor.rgb = lastColor.rgb;\n"
	"		gl_FragColor.a = color0.a;\n"
	"	}"
	"}\n"
};
//----------------------------------------------------------------------------
std::string LightTex2Material::msPPrograms1[Shader::MAX_PROFILES] =
{
	//msPPrograms[0],
	//msPPrograms[1],
	//msPPrograms[2],
	//msPPrograms[3],
	//msPPrograms[4],
	//msPPrograsOGLESTest[1]
};
//----------------------------------------------------------------------------