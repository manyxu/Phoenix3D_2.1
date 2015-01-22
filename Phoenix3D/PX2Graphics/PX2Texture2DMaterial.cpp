/*
*
* 文件名称	：	PX2Texture2DMaterial.cpp
*
*/

#include "PX2Texture2DMaterial.hpp"
#include "PX2PVWMatrixConstant.hpp"
#include "PX2PMatrixConstant.hpp"
#include "PX2WMatrixConstant.hpp"
#include "PX2ShaderKeys.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Material, Texture2DMaterial);
PX2_IMPLEMENT_STREAM(Texture2DMaterial);
PX2_IMPLEMENT_FACTORY(Texture2DMaterial);
PX2_IMPLEMENT_DEFAULT_NAMES(Material, Texture2DMaterial);

//----------------------------------------------------------------------------
Texture2DMaterial::Texture2DMaterial ()
{
	VertexShader* vshader = new0 VertexShader("PX2.Texture2D",
		2, 2, 1, 0, false);
	vshader->SetInput(0, "modelPosition", Shader::VT_FLOAT3,
		Shader::VS_POSITION);
	vshader->SetInput(1, "modelTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);
	vshader->SetOutput(0, "clipPosition", Shader::VT_FLOAT4,
		Shader::VS_POSITION);
	vshader->SetOutput(1, "vertexTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);
	vshader->SetConstant(0, "gPVWMatrix", 4);
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);

	PixelShader* pshader = new0 PixelShader("PX2.Texture2D",
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

	vshader->SetShaderKey(SKT_TEXTURE2D);
	pshader->SetShaderKey(SKT_TEXTURE2D);
}
//----------------------------------------------------------------------------
Texture2DMaterial::~Texture2DMaterial ()
{
}
//----------------------------------------------------------------------------
PixelShader* Texture2DMaterial::GetPixelShader () const
{
	return mTechniques[0]->GetPass(0)->GetPixelShader();
}
//----------------------------------------------------------------------------
MaterialInstance* Texture2DMaterial::CreateInstance (Texture2D* texture) const
{
	MaterialInstance* instance = new0 MaterialInstance(this, 0);
	instance->SetVertexConstant(0, "gPVWMatrix", new0 PVWMatrixConstant());
	instance->SetPixelTexture(0, "gDiffuseSampler", texture);

	return instance;
}
//----------------------------------------------------------------------------
void Texture2DMaterial::_CalShaderKey ()
{
	MaterialPass* pass = mTechniques[0]->GetPass(0);
	VertexShader* vshader = pass->GetVertexShader();
	PixelShader* pshader = pass->GetPixelShader();

	if (!GetAlphaProperty(0, 0)->CompareEnabled)
	{
		vshader->SetShaderKey(SKT_TEXTURE2D);
		pshader->SetShaderKey(SKT_TEXTURE2D);

		pshader->SetPrograms(msPPrograms);
	}
	else
	{
		vshader->SetShaderKey(SKT_TEXTURE2D_ALPHATEST);
		pshader->SetShaderKey(SKT_TEXTURE2D_ALPHATEST);

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
Texture2DMaterial::Texture2DMaterial (LoadConstructor value)
:
Material(value)
{
}
//----------------------------------------------------------------------------
void Texture2DMaterial::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Material::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(Texture2DMaterial, source);
}
//----------------------------------------------------------------------------
void Texture2DMaterial::Link (InStream& source)
{
	Material::Link(source);
}
//----------------------------------------------------------------------------
void Texture2DMaterial::PostLink ()
{
	Material::PostLink();

	MaterialPass* pass = mTechniques[0]->GetPass(0);
	VertexShader* vshader = pass->GetVertexShader();
	PixelShader* pshader = pass->GetPixelShader();
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);
	pshader->SetTextureUnits(msPTextureUnits);

	_CalShaderKey();
}
//----------------------------------------------------------------------------
bool Texture2DMaterial::Register (OutStream& target) const
{
	return Material::Register(target);
}
//----------------------------------------------------------------------------
void Texture2DMaterial::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Material::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(Texture2DMaterial, target);
}
//----------------------------------------------------------------------------
int Texture2DMaterial::GetStreamingSize (Stream &stream) const
{
	int size = Material::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Profiles.
//----------------------------------------------------------------------------
int Texture2DMaterial::msDx9VRegisters[1] = { 0 };
int Texture2DMaterial::msOglVRegisters[1] = { 1 };
int Texture2DMaterial::msOpenGLES2VRegisters[1] = { 0 };
int* Texture2DMaterial::msVRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9VRegisters,
	msDx9VRegisters,
	msDx9VRegisters,
	msOglVRegisters,
	msOpenGLES2VRegisters
};

std::string Texture2DMaterial::msVPrograms[Shader::MAX_PROFILES] =
{
	// VP_NONE
	"",

	// VP_VS_1_1
	"vs_1_1\n"
	"",

	// VP_VS_2_0
	"vs_2_0\n"
	"def c4, 1.00000000, 0, 0, 0\n"
	"dcl_position v0\n"
	"dcl_texcoord0 v1\n"
	"mov r0.w, c4.x\n"
	"mov r0.xyz, v0\n"
	"dp4 oPos.w, r0, c3\n"
	"dp4 oPos.z, r0, c2\n"
	"dp4 oPos.y, r0, c1\n"
	"dp4 oPos.x, r0, c0\n"
	"mov oT0.xy, v1\n",

	// VP_VS_3_0
	"vs_3_0\n"
	"dcl_position o0\n"
	"dcl_texcoord0 o1\n"
	"def c4, 1.00000000, 0, 0, 0\n"
	"dcl_position0 v0\n"
	"dcl_texcoord0 v1\n"
	"mov r0.w, c4.x\n"
	"mov r0.xyz, v0\n"
	"dp4 o0.w, r0, c3\n"
	"dp4 o0.z, r0, c2\n"
	"dp4 o0.y, r0, c1\n"
	"dp4 o0.x, r0, c0\n"
	"mov o1.xy, v1\n",

	// VP_ARBVP1
	"!!ARBvp1.0\n"
	"",

	// vp_gles2
	"uniform mat4 gPVWMatrix;\n"
	"attribute mediump vec3 modelPosition;\n"
	"attribute mediump vec2 modelTCoord0;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = gPVWMatrix * vec4(modelPosition, 1.0);\n"
	"	vertexTCoord0 = modelTCoord0;\n"
	"}\n"
};

int Texture2DMaterial::msAllPTextureUnits[1] = { 0 };
int* Texture2DMaterial::msPTextureUnits[Shader::MAX_PROFILES] =
{
	0,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits
};

std::string Texture2DMaterial::msPPrograms[Shader::MAX_PROFILES] =
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
std::string Texture2DMaterial::msPPrograms1[Shader::MAX_PROFILES]=
{
	//msPPrograms1[0],
	//msPPrograms1[1],
	//msPPrograms1[2],
	//msPPrograms1[3],
	//msPPrograms1[4],
	//msPPrograsOGLESTest[1]
};
std::string Texture2DMaterial::msPPrograsOGLESTest[2] =
{
	"varying mediump vec2 vertexTCoord0;\n"
	"uniform sampler2D gDiffuseSampler;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 texCoord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	mediump vec4 color = texture2D(gDiffuseSampler, texCoord);\n"
	"	gl_FragColor = color;\n"
	"}\n",

	"varying mediump vec2 vertexTCoord0;\n"
	"uniform sampler2D gDiffuseSampler;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 texCoord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	mediump vec4 color = texture2D(gDiffuseSampler, texCoord);\n"
	"	if (color.a < 0.25)\n"
	"	{\n"
	"		discard;\n"
	"	}\n"
	"	else"
	"	{\n"
	"		gl_FragColor = color;\n"
	"	}\n"
	"}\n"
};
//----------------------------------------------------------------------------