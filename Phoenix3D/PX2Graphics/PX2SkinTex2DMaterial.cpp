/*
*
* 文件名称	：	PX2SkinMaterial.cpp
*
*/

#include "PX2SkinTex2DMaterial.hpp"
#include "PX2PVWMatrixConstant.hpp"
#include "PX2VWMatrixConstant.hpp"
#include "PX2PMatrixConstant.hpp"
#include "PX2WMatrixConstant.hpp"
#include "PX2SkinMatrixConstant.hpp"
#include "PX2ShaderKeys.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Material, SkinTex2DMaterial);
PX2_IMPLEMENT_STREAM(SkinTex2DMaterial);
PX2_IMPLEMENT_FACTORY(SkinTex2DMaterial);
PX2_IMPLEMENT_DEFAULT_NAMES(Material, SkinTex2DMaterial);

//----------------------------------------------------------------------------
SkinTex2DMaterial::SkinTex2DMaterial ()
{
	VertexShader* vshader = new0 VertexShader("PX2.SkinTex2D",
		4, 2, 2, 0, false);
	vshader->SetInput(0, "modelPosition", Shader::VT_FLOAT3, Shader::VS_POSITION);
	vshader->SetInput(1, "modelTCoord0", Shader::VT_FLOAT2,	Shader::VS_TEXCOORD0);
	vshader->SetInput(2, "modelTCoord1", Shader::VT_FLOAT4,	Shader::VS_TEXCOORD1);
	vshader->SetInput(3, "modelTCoord2", Shader::VT_FLOAT4,	Shader::VS_TEXCOORD2);

	vshader->SetOutput(0, "clipPosition", Shader::VT_FLOAT4, Shader::VS_POSITION);
	vshader->SetOutput(1, "vertexTCoord0", Shader::VT_FLOAT2, Shader::VS_TEXCOORD0);
	vshader->SetConstant(0, "gPVWMatrix", 4);
	vshader->SetConstant(1, "gBoneTM", 120);
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);

	PixelShader* pshader = new0 PixelShader("PX2.SkinTex2D",
		1, 1, 0, 1, false);
	pshader->SetInput(0, "vertexTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);
	pshader->SetOutput(0, "pixelColor", Shader::VT_FLOAT4,
		Shader::VS_COLOR0);
	pshader->SetSampler(0, "gDiffuseSampler", Shader::ST_2D);
	pshader->SetFilter(0, Shader::SF_LINEAR);
	pshader->SetCoordinate(0, 0, Shader::SC_CLAMP);
	pshader->SetCoordinate(0, 1, Shader::SC_CLAMP);
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

	vshader->SetShaderKey(SKT_SKINTEX2D);
	pshader->SetShaderKey(SKT_SKINTEX2D);
}
//----------------------------------------------------------------------------
SkinTex2DMaterial::~SkinTex2DMaterial ()
{
}
//----------------------------------------------------------------------------
PixelShader* SkinTex2DMaterial::GetPixelShader () const
{
	return mTechniques[0]->GetPass(0)->GetPixelShader();
}
//----------------------------------------------------------------------------
MaterialInstance* SkinTex2DMaterial::CreateInstance (Texture2D* texture) const
{
	MaterialInstance* instance = new0 MaterialInstance(this, 0);
	instance->SetVertexConstant(0, "gPVWMatrix", new0 PVWMatrixConstant());
	instance->SetVertexConstant(0, "gBoneTM", new0 SkinMatrixConstant());	
	instance->SetPixelTexture(0, "gDiffuseSampler", texture);

	return instance;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
SkinTex2DMaterial::SkinTex2DMaterial (LoadConstructor value)
	:
Material(value)
{
}
//----------------------------------------------------------------------------
void SkinTex2DMaterial::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Material::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(SkinTex2DMaterial, source);
}
//----------------------------------------------------------------------------
void SkinTex2DMaterial::Link (InStream& source)
{
	Material::Link(source);
}
//----------------------------------------------------------------------------
void SkinTex2DMaterial::PostLink ()
{
	Material::PostLink();

	MaterialPass* pass = mTechniques[0]->GetPass(0);
	VertexShader* vshader = pass->GetVertexShader();
	PixelShader* pshader = pass->GetPixelShader();
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);
	pshader->SetTextureUnits(msPTextureUnits);
	pshader->SetPrograms(msPPrograms);

	vshader->SetShaderKey(SKT_SKINTEX2D);
	pshader->SetShaderKey(SKT_SKINTEX2D);
}
//----------------------------------------------------------------------------
bool SkinTex2DMaterial::Register (OutStream& target) const
{
	return Material::Register(target);
}
//----------------------------------------------------------------------------
void SkinTex2DMaterial::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Material::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(SkinTex2DMaterial, target);
}
//----------------------------------------------------------------------------
int SkinTex2DMaterial::GetStreamingSize (Stream &stream) const
{
	int size = Material::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Profiles.
//----------------------------------------------------------------------------
int SkinTex2DMaterial::msDx9VRegisters[2] = { 0, 4};
int SkinTex2DMaterial::msOglVRegisters[2] = { 1, 5};
int SkinTex2DMaterial::msOpenGLES2VRegisters[2] = { 0, 0};
int* SkinTex2DMaterial::msVRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9VRegisters,
	msDx9VRegisters,
	msDx9VRegisters,
	msOglVRegisters,
	msOpenGLES2VRegisters
};

std::string SkinTex2DMaterial::msVPrograms[Shader::MAX_PROFILES] =
{
	// VP_NONE
	"",

	// VP_VS_1_1
	"vs_1_1\n"
	"",

	// VP_VS_2_0
	"vs_2_0\n"
	"def c124, 3.00000000, 0.00000000, 1.00000000, 0\n"
	"dcl_texcoord1 v2\n"
	"dcl_position0 v0\n"
	"dcl_texcoord2 v3\n"
	"dcl_texcoord0 v1\n"
	"mul r0.x, v2.y, c124\n"
	"abs r0.z, r0.x\n"
	"frc r0.w, r0.z\n"
	"slt r0.y, r0.x, c124\n"
	"max r0.y, -r0, r0\n"
	"slt r0.y, c124, r0\n"
	"mov r1.w, c124.z\n"
	"add r0.z, r0, -r0.w\n"
	"add r1.x, -r0.y, c124.z\n"
	"mul r0.w, r0.z, r1.x\n"
	"mad r0.y, r0, -r0.z, r0.w\n"
	"mul r0.w, v2.x, c124.x\n"
	"slt r2.x, r0.w, c124.y\n"
	"max r2.x, -r2, r2\n"
	"slt r2.w, c124.y, r2.x\n"
	"abs r2.y, r0.w\n"
	"frc r2.x, r2.y\n"
	"mov r1.xyz, v0\n"
	"mova a0.x, r0\n"
	"dp4 r0.x, r1, c[a0.x + 4]\n"
	"mova a0.x, r0.y\n"
	"add r3.x, r2.y, -r2\n"
	"add r2.z, -r2.w, c124\n"
	"mul r3.y, r3.x, r2.z\n"
	"dp4 r0.y, r1, c[a0.x + 5]\n"
	"dp4 r0.z, r1, c[a0.x + 6]\n"
	"mul r2.xyz, v3.y, r0\n"
	"mad r0.x, r2.w, -r3, r3.y\n"
	"mova a0.y, r0.x\n"
	"mova a0.x, r0.w\n"
	"mul r0.w, v2.z, c124.x\n"
	"dp4 r0.x, r1, c[a0.x + 4]\n"
	"dp4 r0.y, r1, c[a0.y + 5]\n"
	"dp4 r0.z, r1, c[a0.y + 6]\n"
	"mad r2.xyz, v3.x, r0, r2\n"
	"slt r2.w, r0, c124.y\n"
	"abs r0.y, r0.w\n"
	"frc r0.z, r0.y\n"
	"mova a0.x, r0.w\n"
	"mul r0.w, v2, c124.x\n"
	"abs r3.x, r0.w\n"
	"frc r3.y, r3.x\n"
	"max r0.x, -r2.w, r2.w\n"
	"slt r0.x, c124.y, r0\n"
	"add r0.y, r0, -r0.z\n"
	"add r2.w, -r0.x, c124.z\n"
	"mul r0.z, r0.y, r2.w\n"
	"mad r0.y, r0.x, -r0, r0.z\n"
	"dp4 r0.x, r1, c[a0.x + 4]\n"
	"mova a0.x, r0.y\n"
	"slt r2.w, r0, c124.y\n"
	"max r2.w, -r2, r2\n"
	"slt r2.w, c124.y, r2\n"
	"add r3.x, r3, -r3.y\n"
	"add r3.z, -r2.w, c124\n"
	"dp4 r0.y, r1, c[a0.x + 5]\n"
	"dp4 r0.z, r1, c[a0.x + 6]\n"
	"mova a0.x, r0.w\n"
	"mad r0.xyz, v3.z, r0, r2\n"
	"mul r3.y, r3.x, r3.z\n"
	"mad r2.x, r2.w, -r3, r3.y\n"
	"mova a0.y, r2.x\n"
	"mov r0.w, c124.z\n"
	"dp4 r2.x, r1, c[a0.x + 4]\n"
	"dp4 r2.y, r1, c[a0.y + 5]\n"
	"dp4 r2.z, r1, c[a0.y + 6]\n"
	"mad r0.xyz, r2, v3.w, r0\n"
	"dp4 oPos.w, r0, c3\n"
	"dp4 oPos.z, r0, c2\n"
	"dp4 oPos.y, r0, c1\n"
	"dp4 oPos.x, r0, c0\n"
	"mov oT0.xy, v1\n",


	// VP_VS_3_0
	"vs_3_0\n"
	"dcl_position o0\n"
	"dcl_texcoord0 o1\n"
	"def c124, 3.00000000, 0.00000000, 1.00000000, 0\n"
	"dcl_texcoord1 v2\n"
	"dcl_position0 v0\n"
	"dcl_texcoord2 v3\n"
	"dcl_texcoord0 v1\n"
	"mul r0.x, v2.y, c124\n"
	"abs r0.z, r0.x\n"
	"frc r0.w, r0.z\n"
	"slt r0.y, r0.x, c124\n"
	"max r0.y, -r0, r0\n"
	"slt r0.y, c124, r0\n"
	"mov r1.w, c124.z\n"
	"add r0.z, r0, -r0.w\n"
	"add r1.x, -r0.y, c124.z\n"
	"mul r0.w, r0.z, r1.x\n"
	"mad r0.y, r0, -r0.z, r0.w\n"
	"mul r0.w, v2.x, c124.x\n"
	"slt r2.x, r0.w, c124.y\n"
	"max r2.x, -r2, r2\n"
	"slt r2.w, c124.y, r2.x\n"
	"abs r2.y, r0.w\n"
	"frc r2.x, r2.y\n"
	"mov r1.xyz, v0\n"
	"mova a0.x, r0\n"
	"dp4 r0.x, r1, c[a0.x + 4]\n"
	"mova a0.x, r0.y\n"
	"add r3.x, r2.y, -r2\n"
	"add r2.z, -r2.w, c124\n"
	"mul r3.y, r3.x, r2.z\n"
	"dp4 r0.y, r1, c[a0.x + 5]\n"
	"dp4 r0.z, r1, c[a0.x + 6]\n"
	"mul r2.xyz, v3.y, r0\n"
	"mad r0.x, r2.w, -r3, r3.y\n"
	"mova a0.y, r0.x\n"
	"mova a0.x, r0.w\n"
	"mul r0.w, v2.z, c124.x\n"
	"dp4 r0.x, r1, c[a0.x + 4]\n"
	"dp4 r0.y, r1, c[a0.y + 5]\n"
	"dp4 r0.z, r1, c[a0.y + 6]\n"
	"mad r2.xyz, v3.x, r0, r2\n"
	"slt r2.w, r0, c124.y\n"
	"abs r0.y, r0.w\n"
	"frc r0.z, r0.y\n"
	"mova a0.x, r0.w\n"
	"mul r0.w, v2, c124.x\n"
	"abs r3.x, r0.w\n"
	"frc r3.y, r3.x\n"
	"max r0.x, -r2.w, r2.w\n"
	"slt r0.x, c124.y, r0\n"
	"add r0.y, r0, -r0.z\n"
	"add r2.w, -r0.x, c124.z\n"
	"mul r0.z, r0.y, r2.w\n"
	"mad r0.y, r0.x, -r0, r0.z\n"
	"dp4 r0.x, r1, c[a0.x + 4]\n"
	"mova a0.x, r0.y\n"
	"slt r2.w, r0, c124.y\n"
	"max r2.w, -r2, r2\n"
	"slt r2.w, c124.y, r2\n"
	"add r3.x, r3, -r3.y\n"
	"add r3.z, -r2.w, c124\n"
	"dp4 r0.y, r1, c[a0.x + 5]\n"
	"dp4 r0.z, r1, c[a0.x + 6]\n"
	"mova a0.x, r0.w\n"
	"mad r0.xyz, v3.z, r0, r2\n"
	"mul r3.y, r3.x, r3.z\n"
	"mad r2.x, r2.w, -r3, r3.y\n"
	"mova a0.y, r2.x\n"
	"mov r0.w, c124.z\n"
	"dp4 r2.x, r1, c[a0.x + 4]\n"
	"dp4 r2.y, r1, c[a0.y + 5]\n"
	"dp4 r2.z, r1, c[a0.y + 6]\n"
	"mad r0.xyz, r2, v3.w, r0\n"
	"dp4 o0.w, r0, c3\n"
	"dp4 o0.z, r0, c2\n"
	"dp4 o0.y, r0, c1\n"
	"dp4 o0.x, r0, c0\n"
	"mov o1.xy, v1\n",

	// VP_ARBVP1
	"!!ARBvp1.0\n"
	"",

	// vp_gles2
	"const int c_zero = 0;\n"
	"const int c_one = 1;\n"
	"const int c_two = 2;\n"
	"const int c_three = 3;\n"
	"uniform mat4 gPVWMatrix;\n"
	"uniform vec4 gBoneTM[120];\n"
	"attribute mediump vec3 modelPosition;\n"
	"attribute mediump vec2 modelTCoord0;\n"
	"attribute mediump vec4 modelTCoord1;\n"
	"attribute mediump vec4 modelTCoord2;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"void main()\n"
	"{\n"
	"	int i0 = int(modelTCoord1[0])*3;\n"
	"	int i1 = int(modelTCoord1[1])*3;\n"
	"	int i2 = int(modelTCoord1[2])*3;\n"
	"	int i3 = int(modelTCoord1[3])*3;\n"
	"	vec4 inputPos = vec4(modelPosition.x, modelPosition.y, modelPosition.z, 1.0);\n"
	"	vec3 pos = vec3(0, 0, 0);\n"
	"	pos += vec3(dot(inputPos, gBoneTM[i0]), dot(inputPos, gBoneTM[i0 + 1]), dot(inputPos, gBoneTM[i0 + 2])) * modelTCoord2[0];\n"
	"	pos += vec3(dot(inputPos, gBoneTM[i1]), dot(inputPos, gBoneTM[i1 + 1]), dot(inputPos, gBoneTM[i1 + 2])) * modelTCoord2[1];\n"
	"	pos += vec3(dot(inputPos, gBoneTM[i2]), dot(inputPos, gBoneTM[i2 + 1]), dot(inputPos, gBoneTM[i2 + 2])) * modelTCoord2[2];\n"
	"	pos += vec3(dot(inputPos, gBoneTM[i3]), dot(inputPos, gBoneTM[i3 + 1]), dot(inputPos, gBoneTM[i3 + 2])) * modelTCoord2[3];\n"
	"	gl_Position = gPVWMatrix * vec4(pos, 1.0);\n"
	"	vertexTCoord0 = modelTCoord0;\n"
	"}\n"
};

int SkinTex2DMaterial::msAllPTextureUnits[1] = { 0 };
int* SkinTex2DMaterial::msPTextureUnits[Shader::MAX_PROFILES] =
{
	0,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits
};

std::string SkinTex2DMaterial::msPPrograms[Shader::MAX_PROFILES] =
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
	"mov r0.x, t0\n"
	"add r0.y, -t0, c0.x\n"
	"texld r0, r0, s0\n"
	"mov oC0, r0\n",

	// PP_PS_3_0
	"ps_3_0\n"
	"dcl_2d s0\n"
	"def c0, 1.00000000, 0, 0, 0\n"
	"dcl_texcoord0 v0.xy\n"
	"mov r0.x, v0\n"
	"add r0.y, -v0, c0.x\n"
	"texld r0, r0, s0\n"
	"mov oC0, r0\n",

	// PP_ARBFP1
	"",

	// fp_gles2
	"varying mediump vec2 vertexTCoord0;\n"
	"uniform sampler2D gDiffuseSampler;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 texCoord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	mediump vec4 color = texture2D(gDiffuseSampler, texCoord);\n"
	"	if (color.a < 0.25)\n"
	"	{"
	"		discard;\n"
	"	}"
	"	else"
	"	{"
	"		gl_FragColor = color;\n"
	"	}"
	"}\n"
};
//----------------------------------------------------------------------------
