/*
*
* 文件名称	：	PX2UIMaterialUV3.cpp
*
*/

#include "PX2UIMaterialUV3.hpp"
#include "PX2PVWMatrixConstant.hpp"
#include "PX2ShaderKeys.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Material, UIMaterialUV3);
PX2_IMPLEMENT_STREAM(UIMaterialUV3);
PX2_IMPLEMENT_FACTORY(UIMaterialUV3);
PX2_IMPLEMENT_DEFAULT_NAMES(Material, UIMaterialUV3);

//----------------------------------------------------------------------------
UIMaterialUV3::UIMaterialUV3 ()
{
	VertexShader* vshader = new0 VertexShader("PX2.UIUV3",
		5, 5, 1, 0, false);

	vshader->SetInput(0, "modelPosition", Shader::VT_FLOAT3,
		Shader::VS_POSITION);
	vshader->SetInput(1, "modelColor0", Shader::VT_FLOAT4,
		Shader::VS_COLOR0);
	vshader->SetInput(2, "modelTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);
	vshader->SetInput(3, "modelTCoord1", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD1);
	vshader->SetInput(4, "modelTCoord2", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD2);

	vshader->SetOutput(0, "clipPosition", Shader::VT_FLOAT4,
		Shader::VS_POSITION);
	vshader->SetOutput(1, "vertexColor0", Shader::VT_FLOAT4,
		Shader::VS_COLOR0);
	vshader->SetOutput(2, "vertexTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);
	vshader->SetOutput(3, "vertexTCoord1", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD1);
	vshader->SetOutput(4, "vertexTCoord2", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD2);

	vshader->SetConstant(0, "gPVWMatrix", 4);
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);

	PixelShader* pshader = new0 PixelShader("PX2.UIUV3",
		4, 1, 1, 3, false);
	pshader->SetInput(0, "vertexColor0", Shader::VT_FLOAT4,
		Shader::VS_COLOR0);
	pshader->SetInput(1, "vertexTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);
	pshader->SetInput(2, "vertexTCoord1", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD1);
	pshader->SetInput(3, "vertexTCoord2", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD2);

	pshader->SetOutput(0, "pixelColor", Shader::VT_FLOAT4,
		Shader::VS_COLOR0);

	pshader->SetConstant(0, "gAddedColor", 1);
	pshader->SetBaseRegisters(msPRegisters);

	pshader->SetSampler(0, "gDiffuseSampler", Shader::ST_2D);
	pshader->SetFilter(0, Shader::SF_LINEAR);
	pshader->SetCoordinate(0, 0, Shader::SC_CLAMP);
	pshader->SetCoordinate(0, 1, Shader::SC_CLAMP);
	pshader->SetSampler(1, "gAddedSampler", Shader::ST_2D);
	pshader->SetFilter(1, Shader::SF_LINEAR);
	pshader->SetCoordinate(1, 0, Shader::SC_CLAMP);
	pshader->SetCoordinate(1, 1, Shader::SC_CLAMP);
	pshader->SetSampler(2, "gMaskSampler", Shader::ST_2D);
	pshader->SetFilter(2, Shader::SF_LINEAR);
	pshader->SetCoordinate(2, 0, Shader::SC_CLAMP);
	pshader->SetCoordinate(2, 1, Shader::SC_CLAMP);

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

	pass->GetDepthProperty()->Enabled = true;
	pass->GetDepthProperty()->Writable = false;
	pass->GetDepthProperty()->Compare = DepthProperty::CM_LEQUAL;

	pass->GetAlphaProperty()->BlendEnabled = true;

	MaterialTechnique* technique = new0 MaterialTechnique();
	technique->InsertPass(pass);
	InsertTechnique(technique);

	vshader->SetShaderKey(SKT_UIUV3);
	pshader->SetShaderKey(SKT_UIUV3);
}
//----------------------------------------------------------------------------
UIMaterialUV3::~UIMaterialUV3 ()
{
}
//----------------------------------------------------------------------------
PixelShader* UIMaterialUV3::GetPixelShader () const
{
	return mTechniques[0]->GetPass(0)->GetPixelShader();
}
//----------------------------------------------------------------------------
MaterialInstance* UIMaterialUV3::CreateInstance (Texture2D* texture, Texture2D *added,
	ShaderFloat *addedColor, Texture2D *mask) const
{
	MaterialInstance* instance = new0 MaterialInstance(this, 0);
	instance->SetVertexConstant(0, "gPVWMatrix", new0 PVWMatrixConstant());
	instance->SetPixelTexture(0, "gDiffuseSampler", texture);
	instance->SetPixelTexture(0, "gAddedSampler", added);
	instance->SetPixelTexture(0, "gMaskSampler", mask);
	instance->SetPixelConstant(0, "gAddedColor", addedColor);

	return instance;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
UIMaterialUV3::UIMaterialUV3 (LoadConstructor value)
	:
Material(value)
{
}
//----------------------------------------------------------------------------
void UIMaterialUV3::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Material::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(UIMaterialUV3, source);
}
//----------------------------------------------------------------------------
void UIMaterialUV3::Link (InStream& source)
{
	Material::Link(source);
}
//----------------------------------------------------------------------------
void UIMaterialUV3::PostLink ()
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

	pshader->SetFilter(0, Shader::SF_LINEAR);
	pshader->SetFilter(1, Shader::SF_LINEAR);
	pshader->SetFilter(2, Shader::SF_LINEAR);

	pshader->SetCoordinate(0, 0, Shader::SC_CLAMP);
	pshader->SetCoordinate(0, 1, Shader::SC_CLAMP);
	pshader->SetCoordinate(1, 0, Shader::SC_CLAMP);
	pshader->SetCoordinate(1, 1, Shader::SC_CLAMP);
	pshader->SetCoordinate(2, 0, Shader::SC_CLAMP);
	pshader->SetCoordinate(2, 1, Shader::SC_CLAMP);

	vshader->SetShaderKey(SKT_UIUV3);
	pshader->SetShaderKey(SKT_UIUV3);
}
//----------------------------------------------------------------------------
bool UIMaterialUV3::Register (OutStream& target) const
{
	return Material::Register(target);
}
//----------------------------------------------------------------------------
void UIMaterialUV3::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Material::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(UIMaterialUV3, target);
}
//----------------------------------------------------------------------------
int UIMaterialUV3::GetStreamingSize (Stream &stream) const
{
	int size = Material::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	return size;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 版本
//----------------------------------------------------------------------------
int UIMaterialUV3::msDx9VRegisters[1] = { 0 };
int UIMaterialUV3::msOglVRegisters[1] = { 1 };
int UIMaterialUV3::msOpenGLES2VRegisters[1] = { 1 };
int* UIMaterialUV3::msVRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9VRegisters,
	msDx9VRegisters,
	msDx9VRegisters,
	msOglVRegisters,
	msOpenGLES2VRegisters
};

int UIMaterialUV3::msDx9PRegisters[1] = { 0 };
int UIMaterialUV3::msOglPRegisters[1] = { 1 };
int UIMaterialUV3::msOpenGLES2PRegisters[1] = { 1 };

int* UIMaterialUV3::msPRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9PRegisters,
	msDx9PRegisters,
	msDx9PRegisters,
	msOglVRegisters,
	msOpenGLES2PRegisters
};

std::string UIMaterialUV3::msVPrograms[Shader::MAX_PROFILES] =
{
	// VP_NONE
	"",

	// VP_VS_1_1
	"",

	// VP_VS_2_0
	"vs_2_0\n"
	"def c4, 1.00000000, 0, 0, 0\n"
	"dcl_position0 v0\n"
	"dcl_color0 v1\n"
	"dcl_texcoord0 v2\n"
	"dcl_texcoord1 v3\n"
	"dcl_texcoord2 v4\n"
	"mov r0.w, c4.x\n"
	"mov r0.xyz, v0\n"
	"dp4 oPos.w, r0, c3\n"
	"dp4 oPos.z, r0, c2\n"
	"dp4 oPos.y, r0, c1\n"
	"dp4 oPos.x, r0, c0\n"
	"mov oD0, v1\n"
	"mov oT0.xy, v2\n"
	"mov oT1.xy, v3\n"
	"mov oT2.xy, v4\n",

	// VP_VS_3_0
	"vs_3_0\n"
	"dcl_position o0\n"
	"dcl_color0 o1\n"
	"dcl_texcoord0 o2\n"
	"dcl_texcoord1 o3\n"
	"dcl_texcoord2 o4\n"
	"def c4, 1.00000000, 0, 0, 0\n"
	"dcl_position0 v0\n"
	"dcl_color0 v1\n"
	"dcl_texcoord0 v2\n"
	"dcl_texcoord1 v3\n"
	"dcl_texcoord2 v4\n"
	"mov r0.w, c4.x\n"
	"mov r0.xyz, v0\n"
	"dp4 o0.w, r0, c3\n"
	"dp4 o0.z, r0, c2\n"
	"dp4 o0.y, r0, c1\n"
	"dp4 o0.x, r0, c0\n"
	"mov o1, v1\n"
	"mov o2.xy, v2\n"
	"mov o3.xy, v3\n"
	"mov o4.xy, v4\n",

	// VP_ARBVP1
	"",

	// vp_gles2
	"uniform mat4 gPVWMatrix;\n"
	"attribute mediump vec3 modelPosition;\n"
	"attribute mediump vec4 modelColor0;\n"
	"attribute mediump vec2 modelTCoord0;\n"
	"attribute mediump vec2 modelTCoord1;\n"
	"attribute mediump vec2 modelTCoord2;\n"
	"varying mediump vec4 vertexColor0;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"varying mediump vec2 vertexTCoord2;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = gPVWMatrix*vec4(modelPosition, 1.0);\n"
	"	vertexColor0 = modelColor0;\n"
	"	vertexTCoord0 = modelTCoord0;\n"
	"	vertexTCoord1 = modelTCoord1;\n"
	"	vertexTCoord2 = modelTCoord2;\n"
	"}\n"
};

int UIMaterialUV3::msAllPTextureUnits[3] = { 0, 1, 2 };
int* UIMaterialUV3::msPTextureUnits[Shader::MAX_PROFILES] =
{
	0,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits
};

std::string UIMaterialUV3::msPPrograms[Shader::MAX_PROFILES] =
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
	"def c1, 1.00000000, 0, 0, 0\n"
	"dcl t0.xy\n"
	"dcl t1.xy\n"
	"dcl t2.xy\n"
	"dcl v0.xyz\n"
	"mov r2.x, t0\n"
	"add r2.y, -t0, c1.x\n"
	"mov r1.x, t1\n"
	"add r1.y, -t1, c1.x\n"
	"add r0.y, -t2, c1.x\n"
	"mov r0.x, t2\n"
	"texld r1, r1, s1\n"
	"texld r0, r0, s2\n"
	"texld r2, r2, s0\n"
	"mul r1.xyz, r1, c0\n"
	"mul r1.xyz, r1, c0.w\n"
	"mad r1.xyz, r2, v0, r1\n"
	"mov r1.w, r2\n"
	"mul r0, r1, r0\n"
	"mov oC0, r0\n",

	// PP_PS_3_0
	"ps_3_0\n"
	"dcl_2d s0\n"
	"dcl_2d s1\n"
	"dcl_2d s2\n"
	"def c1, 1.00000000, 0, 0, 0\n"
	"dcl_texcoord0 v1.xy\n"
	"dcl_texcoord1 v2.xy\n"
	"dcl_texcoord2 v3.xy\n"
	"dcl_color0 v0.xyz\n"
	"add r0.y, -v2, c1.x\n"
	"mov r0.x, v2\n"
	"texld r0.xyz, r0, s1\n"
	"mul r0.xyz, r0, c0\n"
	"mul r0.xyz, r0, c0.w\n"
	"add r1.y, -v1, c1.x\n"
	"mov r1.x, v1\n"
	"texld r1, r1, s0\n"
	"mad r1.xyz, r1, v0, r0\n"
	"add r0.y, -v3, c1.x\n"
	"mov r0.x, v3\n"
	"texld r0, r0, s2\n"
	"mul oC0, r1, r0\n",

	// PP_ARBFP1
	"",

	// fp_gles2
	"varying mediump vec4 vertexColor0;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"varying mediump vec2 vertexTCoord1;\n"
	"varying mediump vec2 vertexTCoord2;\n"
	"uniform sampler2D gDiffuseSampler;\n"
	"uniform sampler2D gAddedSampler;\n"
	"uniform sampler2D gMaskSampler;\n"
	"uniform mediump vec4 gAddedColor;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 tecCord0 = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	mediump vec2 tecCord1 = vec2(vertexTCoord1.x, 1.0-vertexTCoord1.y);\n"
	"	mediump vec2 tecCord2 = vec2(vertexTCoord2.x, 1.0-vertexTCoord2.y);\n"
	"	mediump vec4 color0 = texture2D(gDiffuseSampler, tecCord0);\n"
	"	mediump vec4 color1 = texture2D(gAddedSampler, tecCord1);\n"
	"	mediump vec4 color2 = texture2D(gMaskSampler, tecCord2);\n"
	"	mediump vec4 addedColor = vec4(0, 0, 0, 0);\n"
	"	addedColor.rgb = (color0*vertexColor0).rgb + (color1*gAddedColor).rgb * gAddedColor.a;\n"
	"	addedColor.a = color0.a;\n"
	"	gl_FragColor = addedColor*color2;\n"
	"}\n"
};
//----------------------------------------------------------------------------