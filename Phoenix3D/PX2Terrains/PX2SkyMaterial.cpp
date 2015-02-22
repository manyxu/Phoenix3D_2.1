// PX2SkyMaterial.cpp

#include "PX2SkyMaterial.hpp"
#include "PX2ShaderKeys.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Material, SkyMaterial);
PX2_IMPLEMENT_STREAM(SkyMaterial);
PX2_IMPLEMENT_FACTORY(SkyMaterial);
PX2_IMPLEMENT_DEFAULT_NAMES(Material, SkyMaterial);

//----------------------------------------------------------------------------
SkyMaterial::SkyMaterial ()
{
	// vertex shader
	VertexShader* vshader = new0 VertexShader("PX2.Sky",
		1, 2, 3, 0, false);
	vshader->SetInput(0, "modelPosition", Shader::VT_FLOAT3,
		Shader::VS_POSITION);

	vshader->SetOutput(0, "clipPosition", Shader::VT_FLOAT4, 
		Shader::VS_POSITION);
	vshader->SetOutput(1, "camToVertex", Shader::VT_FLOAT3,
		Shader::VS_TEXCOORD0);

	vshader->SetConstant(0, "gPVWMatrix", 4);
	vshader->SetConstant(1, "gVMatrix", 4);
	vshader->SetConstant(2, "gCameraWorldPosition", 1);

	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);

	// pixel shader
	PixelShader* pshader = new0 PixelShader("PX2.Sky",
		1, 1, 5, 3, false);

	pshader->SetInput(0, "camToVertex", Shader::VT_FLOAT3,
		Shader::VS_COLOR0);

	pshader->SetOutput(0, "pixelColor", Shader::VT_FLOAT4,
		Shader::VS_COLOR0);

	pshader->SetConstant(0, "gLightWorldDirection", 1);
	pshader->SetConstant(1, "gCameraWorldDVector", 1);
	pshader->SetConstant(2, "gLightColour", 1);
	pshader->SetConstant(3, "sunParams", 1);
	pshader->SetConstant(4, "skyParams", 1);

	pshader->SetSampler(0, "gDaySampler", Shader::ST_2D);
	pshader->SetFilter(0, Shader::SF_LINEAR_LINEAR);
	pshader->SetCoordinate(0, 0, Shader::SC_CLAMP_EDGE);
	pshader->SetCoordinate(0, 1, Shader::SC_CLAMP_EDGE);

	pshader->SetSampler(1, "gSunsetSampler", Shader::ST_2D);
	pshader->SetFilter(1, Shader::SF_LINEAR_LINEAR);
	pshader->SetCoordinate(1, 0, Shader::SC_CLAMP_EDGE);
	pshader->SetCoordinate(1, 1, Shader::SC_CLAMP_EDGE);

	pshader->SetSampler(2, "gNightSampler", Shader::ST_2D);
	pshader->SetFilter(2, Shader::SF_LINEAR_LINEAR);
	pshader->SetCoordinate(2, 0, Shader::SC_CLAMP_EDGE);
	pshader->SetCoordinate(2, 1, Shader::SC_CLAMP_EDGE);

	pshader->SetBaseRegisters(msPRegisters);
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

	vshader->SetShaderKey(SKT_SKY);
	pshader->SetShaderKey(SKT_SKY);
}
//----------------------------------------------------------------------------
SkyMaterial::~SkyMaterial ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// ³Ö¾Ã»¯
//----------------------------------------------------------------------------
SkyMaterial::SkyMaterial (LoadConstructor value)
	:
Material(value)
{
}
//----------------------------------------------------------------------------
void SkyMaterial::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Material::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(SkyMaterial, source);
}
//----------------------------------------------------------------------------
void SkyMaterial::Link (InStream& source)
{
	Material::Link(source);
}
//----------------------------------------------------------------------------
void SkyMaterial::PostLink ()
{
	Material::PostLink();

	MaterialPass* pass = mTechniques[0]->GetPass(0);
	VertexShader* vshader = pass->GetVertexShader();
	PixelShader* pshader = pass->GetPixelShader();
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);
	pshader->SetBaseRegisters(msPRegisters);
	pshader->SetTextureUnits(msPTextureUnits);
	pshader->SetPrograms(msPPrograms);

	vshader->SetShaderKey(SKT_SKY);
	pshader->SetShaderKey(SKT_SKY);
}
//----------------------------------------------------------------------------
bool SkyMaterial::Register (OutStream& target) const
{
	return Material::Register(target);
}
//----------------------------------------------------------------------------
void SkyMaterial::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Material::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(SkyMaterial, target);
}
//----------------------------------------------------------------------------
int SkyMaterial::GetStreamingSize (Stream &stream) const
{
	int size = Material::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	return size;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// °æ±¾
//----------------------------------------------------------------------------
int SkyMaterial::msDx9VRegisters[3] = { 0, 4, 8};
int SkyMaterial::msOglVRegisters[3] = { 1, 5, 9};
int SkyMaterial::msOpenGLES2VRegisters[3] = { 1, 5, 9};
int* SkyMaterial::msVRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9VRegisters,
	msDx9VRegisters,
	msDx9VRegisters,
	msOglVRegisters,
	msOpenGLES2VRegisters
};

std::string SkyMaterial::msVPrograms[Shader::MAX_PROFILES] =
{
	// VP_NONE
	"",

	// VP_VS_1_1
	"",

	// VP_VS_2_0
	"vs_2_0\n"
	"def c9, 1.00000000, 0, 0, 0\n"
	"dcl_position0 v0\n"
	"mov r1.w, c9.x\n"
	"mov r1.xyz, v0\n"
	"dp4 r0.z, r1, c6\n"
	"dp4 r0.x, r1, c4\n"
	"dp4 r0.y, r1, c5\n"
	"add oT0.xyz, r0, -c8\n"
	"dp4 oPos.w, r1, c3\n"
	"dp4 oPos.z, r1, c2\n"
	"dp4 oPos.y, r1, c1\n"
	"dp4 oPos.x, r1, c0\n",

	// VP_VS_3_0
	"vs_3_0\n"
	"dcl_position o0\n"
	"dcl_texcoord0 o1\n"
	"def c9, 1.00000000, 0, 0, 0\n"
	"dcl_position0 v0\n"
	"mov r1.w, c9.x\n"
	"mov r1.xyz, v0\n"
	"dp4 r0.z, r1, c6\n"
	"dp4 r0.x, r1, c4\n"
	"dp4 r0.y, r1, c5\n"
	"add o1.xyz, r0, -c8\n"
	"dp4 o0.w, r1, c3\n"
	"dp4 o0.z, r1, c2\n"
	"dp4 o0.y, r1, c1\n"
	"dp4 o0.x, r1, c0\n",

	// VP_ARBVP1
	"",

	// vp_gles2
	"uniform mediump mat4 gPVWMatrix;\n"
	"uniform mediump mat4 gVMatrix;\n"
	"uniform mediump vec4 gCameraWorldPosition;\n"
	"attribute mediump vec3 modelPosition;\n"
	"varying mediump vec3 camToVertex;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = gPVWMatrix*vec4(modelPosition, 1.0);\n"
	"	vec4 worldPosition = gVMatrix*vec4(modelPosition, 1.0);\n"
	"	camToVertex = worldPosition.xyz - gCameraWorldPosition.xyz;\n"
	"}\n"
};

int SkyMaterial::msAllPRegisters[5] = { 0, 1, 2, 3, 4 };

int* SkyMaterial::msPRegisters[Shader::MAX_PROFILES] =
{
	0,
	msAllPRegisters,
	msAllPRegisters,
	msAllPRegisters,
	msAllPRegisters,
	msAllPRegisters
};

int SkyMaterial::msAllPTextureUnits[3] = { 0, 1, 2};
int* SkyMaterial::msPTextureUnits[Shader::MAX_PROFILES] =
{
	0,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits
};

std::string SkyMaterial::msPPrograms[Shader::MAX_PROFILES] =
{
	// PP_NONE
	"",

	// PP_PS_1_1
	"",

	// PP_PS_2_0
	"ps_2_0\n"
	"dcl_2d s0\n"
	"dcl_2d s1\n"
	"dcl_2d s2\n"
	"def c5, 0.00000000, 1.00000000, 4.00000000, 0.50000000\n"
	"def c6, 0.00010000, 0.25000000, 0, 0\n"
	"dcl t0.xyz\n"
	"mov r0.z, c0\n"
	"max r0.x, c6, -r0.z\n"
	"rcp r0.x, r0.x\n"
	"dp3 r1.x, t0, t0\n"
	"rsq r1.x, r1.x\n"
	"mul r0.x, r0, c4\n"
	"mul r5.xyz, r1.x, t0\n"
	"min r0.x, r0, c5.y\n"
	"add r1.x, r0, c6.y\n"
	"max r0.x, r5.z, c5\n"
	"pow r4, r0.x, r1.x\n"
	"mov r2.z, c5.x\n"
	"mov r2.xy, c1\n"
	"dp3 r1.x, r2, r2\n"
	"rsq r1.x, r1.x\n"
	"mul r1.xyz, r1.x, r2\n"
	"mov r3.z, c5.x\n"
	"mov r3.xy, -c0\n"
	"dp3 r0.x, r3, r3\n"
	"rsq r0.x, r0.x\n"
	"mul r0.xyz, r0.x, r3\n"
	"dp3 r0.x, r0, r1\n"
	"mov r1.x, r4\n"
	"add r0.x, r0, c5.y\n"
	"add r0.y, -r1.x, c5\n"
	"mad r0.x, -r0, c5.w, c5.y\n"
	"mov r0.z, c0\n"
	"texld r3, r0, s2\n"
	"texld r1, r0, s0\n"
	"texld r2, r0, s1\n"
	"add r0.x, c5.y, r0.z\n"
	"pow r4, r0.x, c4.y\n"
	"mov r0.x, r4\n"
	"add r4, r2, -r1\n"
	"min r0.x, r0, c5.y\n"
	"mad r1, r0.x, r4, r1\n"
	"mov r0.z, c0\n"
	"mul r0.x, c5.z, r0.z\n"
	"add r3, r3, -r2\n"
	"min r0.x, r0, c5.y\n"
	"mad r3, r0.x, r3, r2\n"
	"mov_pp r0.z, c0\n"
	"cmp r2.x, r0.z, c5, c5.y\n"
	"dp3 r0.x, r5, -c0\n"
	"max r0.x, r0, c5\n"
	"pow r4, r0.x, c3.z\n"
	"abs_pp r2.x, r2\n"
	"cmp r2, -r2.x, r3, r1\n"
	"pow r1, r0.x, c3.x\n"
	"mov r0.x, r4\n"
	"mul r0.x, r0, c3.w\n"
	"mad r0.x, r1, c3.y, r0\n"
	"mad r0, r0.x, c2, r2\n"
	"mov oC0, r0\n",

	// PP_PS_3_0
	"ps_3_0\n"
	"dcl_2d s0\n"
	"dcl_2d s1\n"
	"dcl_2d s2\n"
	"def c5, 0.00000000, 1.00000000, 4.00000000, 0.50000000\n"
	"def c6, 0.00010000, 0.25000000, 0, 0\n"
	"dcl_texcoord0 v0.xyz\n"
	"mov r0.xy, c1\n"
	"mov r0.z, c5.x\n"
	"dp3 r1.w, r0, r0\n"
	"rsq r1.w, r1.w\n"
	"mul r2.xyz, r1.w, r0\n"
	"mov r0.x, c0.z\n"
	"mov r1.z, c5.x\n"
	"mov r1.xy, -c0\n"
	"dp3 r0.w, r1, r1\n"
	"rsq r0.w, r0.w\n"
	"mul r1.xyz, r0.w, r1\n"
	"dp3 r0.y, r1, r2\n"
	"add r1.x, r0.y, c5.y\n"
	"max r0.x, c6, -r0\n"
	"rcp r0.y, r0.x\n"
	"dp3 r0.x, v0, v0\n"
	"rsq r0.x, r0.x\n"
	"mul r3.xyz, r0.x, v0\n"
	"mul r0.y, r0, c4.x\n"
	"min r0.y, r0, c5\n"
	"mad r4.x, -r1, c5.w, c5.y\n"
	"add r1.z, r0.y, c6.y\n"
	"max r1.y, r3.z, c5.x\n"
	"pow r0, r1.y, r1.z\n"
	"add r4.y, -r0.x, c5\n"
	"mov r0.y, c0.z\n"
	"add r0.y, c5, r0\n"
	"pow r2, r0.y, c4.y\n"
	"mov r3.w, r2.x\n"
	"texld r1, r4, s1\n"
	"texld r0, r4, s0\n"
	"add r2, r1, -r0\n"
	"min r3.w, r3, c5.y\n"
	"mad r2, r3.w, r2, r0\n"
	"mov r3.w, c0.z\n"
	"texld r0, r4, s2\n"
	"mul r3.w, c5.z, r3\n"
	"add r0, r0, -r1\n"
	"min r3.w, r3, c5.y\n"
	"mad r0, r3.w, r0, r1\n"
	"dp3 r1.y, r3, -c0\n"
	"mov_pp r1.x, c0.z\n"
	"max r3.x, r1.y, c5\n"
	"cmp r3.y, r1.x, c5.x, c5\n"
	"pow r1, r3.x, c3.z\n"
	"abs_pp r1.y, r3\n"
	"cmp r2, -r1.y, r0, r2\n"
	"pow r0, r3.x, c3.x\n"
	"mov r0.y, r1.x\n"
	"mul r0.y, r0, c3.w\n"
	"mad r0.x, r0, c3.y, r0.y\n"
	"mad oC0, r0.x, c2, r2\n",

	// PP_ARBFP1
	"",

	// fp_gles2
	"varying mediump vec3 camToVertex;\n"
	"uniform sampler2D gDaySampler;\n"
	"uniform sampler2D gSunsetSampler;\n"
	"uniform sampler2D gNightSampler;\n"
	"uniform mediump vec4 gLightWorldDirection;\n"
	"uniform mediump vec4 gCameraWorldDVector;\n"
	"uniform mediump vec4 gLightColour;\n"
	"uniform mediump vec4 sunParams;\n"
	"uniform mediump vec4 skyParams;\n"
	"void main()\n"
	"{\n"
	"	mediump vec3 camToVertexN = normalize(camToVertex);"
	"	mediump float sunHighLight = pow(max(0.0, dot(camToVertexN, -gLightWorldDirection.xyz)), sunParams[0]) * sunParams[1];\n"
	"	mediump float largeSunHighLight = pow(max(0.0, dot(camToVertexN, -gLightWorldDirection.xyz)), sunParams[2]) * sunParams[3];\n"
	"	mediump vec3 flatLightVec = normalize(vec3(-gLightWorldDirection.x, -gLightWorldDirection.y, 0.0));\n"
	"	mediump vec3 flatCameraVec = normalize(vec3(gCameraWorldDVector.x, gCameraWorldDVector.y, 0.0));\n"
	"	mediump float lcDot = dot(flatLightVec, flatCameraVec);\n"
	"	mediump float u =  1.0 - (lcDot + 1.0) * 0.5;\n"
	"	mediump float val = 0.25 + (1.25-0.25)*min(1.0, skyParams[0] / max(0.0001, -gLightWorldDirection.z));\n"	
	"	mediump float yAngle = pow(max(0.0, camToVertexN.z), val);\n"	
	"	mediump float v =  (1.0 - yAngle);\n"
	"	mediump vec4 colorDay = texture2D(gDaySampler, vec2(u, v));\n"
	"	mediump vec4 colorSunSet = texture2D(gSunsetSampler, vec2(u, v));\n"
	"	mediump vec4 colorNight = texture2D(gNightSampler, vec2(u, v));\n"
	"	mediump vec4 color = vec4(0.0, 0.0, 0.0, 1.0);\n"
	"	if (-gLightWorldDirection.z > 0.0)\n"
	"	{\n"
	"		color = colorDay + (colorSunSet-colorDay)*min(1.0, pow(1.0 + gLightWorldDirection.z, skyParams[1]));\n"
	"	}\n"
	"	else\n"
	"	{\n"
	"		color = colorSunSet + (colorNight-colorSunSet)*min(1.0, gLightWorldDirection.z * 4.0);\n"
	"	}\n"
	"	color = color + gLightColour * (sunHighLight + largeSunHighLight);\n"
	"	gl_FragColor = color;\n"
	"}\n"
};
//----------------------------------------------------------------------------