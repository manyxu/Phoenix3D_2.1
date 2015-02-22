// PX2UIMaterial.cpp

#include "PX2EffectMaterial.hpp"
#include "PX2PVWMatrixConstant.hpp"
#include "PX2ShaderKeys.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Material, EffectMaterial);
PX2_IMPLEMENT_STREAM(EffectMaterial);
PX2_IMPLEMENT_FACTORY(EffectMaterial);
PX2_IMPLEMENT_DEFAULT_NAMES(Material, EffectMaterial);

//----------------------------------------------------------------------------
bool EffectMaterial::msIsRegisterInitFinal = false;
std::vector<EffectMaterialPtr> EffectMaterial::msPreCreatedMtls;
//----------------------------------------------------------------------------
void EffectMaterial::Init()
{
	msPreCreatedMtls.resize(9);
	for (int i=0; i<=8; i++)
	{
		msPreCreatedMtls[i] = new0 EffectMaterial();
		msPreCreatedMtls[i]->GetCullProperty(0, 0)->Enabled = false;
		msPreCreatedMtls[i]->SetBlendMode(i);
	}
}
//----------------------------------------------------------------------------
void EffectMaterial::Final()
{
	msPreCreatedMtls.clear();
}
//----------------------------------------------------------------------------
bool EffectMaterial::RegisterInitFinal()
{
	if (!msIsRegisterInitFinal)
	{
		InitTerm::AddInitializer(Init);
		InitTerm::AddTerminator(Final);

		msIsRegisterInitFinal = true;
	}

	return msIsRegisterInitFinal;
}
//----------------------------------------------------------------------------
EffectMaterial *EffectMaterial::GetPreCreatedMtl(int mode)
{
	assertion(mode<(int)msPreCreatedMtls.size(), 
		"mode should be in right range.\n");
	return msPreCreatedMtls[mode];
}
//----------------------------------------------------------------------------
EffectMaterial::EffectMaterial ()
{
	VertexShader* vshader = new0 VertexShader("PX2.Effect",
		3, 3, 1, 0, false);
	vshader->SetInput(0, "modelPosition", Shader::VT_FLOAT3,
		Shader::VS_POSITION);
	vshader->SetInput(1, "modelColor0", Shader::VT_FLOAT4,
		Shader::VS_COLOR0);
	vshader->SetInput(2, "modelTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);
	vshader->SetOutput(0, "clipPosition", Shader::VT_FLOAT4,
		Shader::VS_POSITION);
	vshader->SetOutput(1, "vertexColor0", Shader::VT_FLOAT4,
		Shader::VS_COLOR0);
	vshader->SetOutput(2, "vertexTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);
	vshader->SetConstant(0, "gPVWMatrix", 4);
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);

	PixelShader* pshader = new0 PixelShader("PX2.Effect",
		2, 1, 0, 1, false);
	pshader->SetInput(0, "vertexColor0", Shader::VT_FLOAT4,
		Shader::VS_COLOR0);
	pshader->SetInput(1, "vertexTCoord0", Shader::VT_FLOAT2,
		Shader::VS_TEXCOORD0);
	pshader->SetOutput(0, "pixelColor", Shader::VT_FLOAT4,
		Shader::VS_COLOR0);
	pshader->SetSampler(0, "gDiffuseSampler", Shader::ST_2D);
	pshader->SetFilter(0, Shader::SF_LINEAR_LINEAR);
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
	pass->GetCullProperty()->Enabled = false;

	MaterialTechnique* technique = new0 MaterialTechnique();
	technique->InsertPass(pass);
	InsertTechnique(technique);

	vshader->SetShaderKey(SKT_EFFECT);
	pshader->SetShaderKey(SKT_EFFECT);
}
//----------------------------------------------------------------------------
EffectMaterial::~EffectMaterial ()
{
}
//----------------------------------------------------------------------------
PixelShader* EffectMaterial::GetPixelShader () const
{
	return mTechniques[0]->GetPass(0)->GetPixelShader();
}
//----------------------------------------------------------------------------
void EffectMaterial::SetBlendMode (int mode)
{
	bool BlendEnabled = false;
	AlphaProperty::SrcBlendMode SrcBlend = AlphaProperty::SBM_SRC_ALPHA;
	AlphaProperty::DstBlendMode DstBlend = AlphaProperty::DBM_ONE_MINUS_SRC_ALPHA;
	bool CompareEnabled = false;
	AlphaProperty::CompareMode Compare = AlphaProperty::CM_ALWAYS;
	float Reference = 0.0f;

	if (0 == mode)
	{
		BlendEnabled = false;
		CompareEnabled = false;
	}
	else if (1 == mode)
	{
		BlendEnabled = false;
		CompareEnabled = true;
		Reference = 0.33f;
		Compare = AlphaProperty::CM_GEQUAL;
	}
	else if (2 == mode)
	{
		BlendEnabled = true;
		SrcBlend = AlphaProperty::SBM_SRC_ALPHA;
		DstBlend = AlphaProperty::DBM_ONE_MINUS_SRC_ALPHA;
		CompareEnabled = true;
		Reference = 0.0f;
		Compare = AlphaProperty::CM_GREATER;
	}
	else if (3 == mode)
	{
		BlendEnabled = true;
		SrcBlend = AlphaProperty::SBM_SRC_ALPHA;
		DstBlend = AlphaProperty::DBM_ONE;
		CompareEnabled = false;
	}
	else if (4 == mode)
	{
		BlendEnabled = true;
		SrcBlend = AlphaProperty::SBM_SRC_COLOR;
		DstBlend = AlphaProperty::DBM_ONE_MINUS_SRC_COLOR;
		CompareEnabled = false;
	}
	else if (5 == mode)
	{
		BlendEnabled = true;
		SrcBlend = AlphaProperty::SBM_SRC_COLOR;
		DstBlend = AlphaProperty::DBM_ONE;
		CompareEnabled = false;
	}
	else if (6 == mode)
	{
		BlendEnabled = true;
		SrcBlend = AlphaProperty::SBM_ONE;
		DstBlend = AlphaProperty::DBM_ONE;
		CompareEnabled = false;
	}
	else if (7 == mode)
	{
		BlendEnabled = true;
		SrcBlend = AlphaProperty::SBM_ONE;
		DstBlend = AlphaProperty::DBM_ONE_MINUS_SRC_ALPHA;
		CompareEnabled = false;
	}
	else if (8 == mode)
	{
		BlendEnabled = true;
		SrcBlend = AlphaProperty::SBM_ONE;
		DstBlend = AlphaProperty::DBM_ONE_MINUS_SRC_COLOR;
		CompareEnabled = false;
	}

	AlphaProperty *aProp = GetAlphaProperty(0, 0);
	aProp->BlendEnabled = BlendEnabled;
	aProp->SrcBlend = SrcBlend;
	aProp->DstBlend = DstBlend;
	aProp->CompareEnabled = CompareEnabled;
	aProp->Compare = Compare;
	aProp->Reference = Reference;

	if (0==mode || 1==mode)
	{
		GetDepthProperty(0, 0)->Writable = true;
		GetDepthProperty(0, 0)->Enabled = true;
	}
	else
	{
		GetDepthProperty(0, 0)->Writable = false;
		GetDepthProperty(0, 0)->Enabled = true;
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// ³Ö¾Ã»¯
//----------------------------------------------------------------------------
EffectMaterial::EffectMaterial (LoadConstructor value)
	:
Material(value)
{
}
//----------------------------------------------------------------------------
void EffectMaterial::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Material::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(EffectMaterial, source);
}
//----------------------------------------------------------------------------
void EffectMaterial::Link (InStream& source)
{
	Material::Link(source);
}
//----------------------------------------------------------------------------
void EffectMaterial::PostLink ()
{
	Material::PostLink();

	MaterialPass* pass = mTechniques[0]->GetPass(0);
	VertexShader* vshader = pass->GetVertexShader();
	PixelShader* pshader = pass->GetPixelShader();
	vshader->SetBaseRegisters(msVRegisters);
	vshader->SetPrograms(msVPrograms);
	pshader->SetTextureUnits(msPTextureUnits);
	pshader->SetPrograms(msPPrograms);

	vshader->SetShaderKey(SKT_EFFECT);
	pshader->SetShaderKey(SKT_EFFECT);
}
//----------------------------------------------------------------------------
bool EffectMaterial::Register (OutStream& target) const
{
	return Material::Register(target);
}
//----------------------------------------------------------------------------
void EffectMaterial::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Material::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(EffectMaterial, target);
}
//----------------------------------------------------------------------------
int EffectMaterial::GetStreamingSize (Stream &stream) const
{
	int size = Material::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	return size;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// °æ±¾
//----------------------------------------------------------------------------
int EffectMaterial::msDx9VRegisters[1] = { 0 };
int EffectMaterial::msOglVRegisters[1] = { 1 };
int EffectMaterial::msOpenGLES2VRegisters[1] = { 1 };
int* EffectMaterial::msVRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9VRegisters,
	msDx9VRegisters,
	msDx9VRegisters,
	msOglVRegisters,
	msOpenGLES2VRegisters
};

std::string EffectMaterial::msVPrograms[Shader::MAX_PROFILES] =
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
	"mov r0.w, c4.x\n"
	"mov r0.xyz, v0\n"
	"dp4 oPos.w, r0, c3\n"
	"dp4 oPos.z, r0, c2\n"
	"dp4 oPos.y, r0, c1\n"
	"dp4 oPos.x, r0, c0\n"
	"mov oD0, v1\n"
	"mov oT0.xy, v2\n",

	// VP_VS_3_0
	"vs_3_0\n"
	"dcl_position o0\n"
	"dcl_color0 o1\n"
	"dcl_texcoord0 o2\n"
	"def c4, 1.00000000, 0, 0, 0\n"
	"dcl_position0 v0\n"
	"dcl_color0 v1\n"
	"dcl_texcoord0 v2\n"
	"mov r0.w, c4.x\n"
	"mov r0.xyz, v0\n"
	"dp4 o0.w, r0, c3\n"
	"dp4 o0.z, r0, c2\n"
	"dp4 o0.y, r0, c1\n"
	"dp4 o0.x, r0, c0\n"
	"mov o1, v1\n"
	"mov o2.xy, v2\n",

	// VP_ARBVP1
	"",

	// vp_gles2
	"uniform mat4 gPVWMatrix;\n"
	"attribute mediump vec3 modelPosition;\n"
	"attribute mediump vec4 modelColor0;\n"
	"attribute mediump vec2 modelTCoord0;\n"
	"varying mediump vec4 vertexColor0;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = gPVWMatrix*vec4(modelPosition, 1.0);\n"
	"	vertexColor0 = modelColor0;\n"
	"	vertexTCoord0 = modelTCoord0;\n"
	"}\n"
};

int EffectMaterial::msAllPTextureUnits[1] = { 0 };
int* EffectMaterial::msPTextureUnits[Shader::MAX_PROFILES] =
{
	0,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits
};

std::string EffectMaterial::msPPrograms[Shader::MAX_PROFILES] =
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
	"dcl v0\n"
	"add r0.y, -t0, c0.x\n"
	"mov r0.x, t0\n"
	"texld r0, r0, s0\n"
	"mul r0, r0, v0\n"
	"mov oC0, r0\n",

	// PP_PS_3_0
	"ps_3_0\n"
	"dcl_2d s0\n"
	"def c0, 1.00000000, 0, 0, 0\n"
	"dcl_texcoord0 v1.xy\n"
	"dcl_color0 v0\n"
	"add r0.y, -v1, c0.x\n"
	"mov r0.x, v1\n"
	"texld r0, r0, s0\n"
	"mul oC0, r0, v0\n",

	// PP_ARBFP1
	"",

	// fp_gles2
	"varying mediump vec4 vertexColor0;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"uniform sampler2D gDiffuseSampler;\n"
	"void main()\n"
	"{\n"
	"	mediump vec2 tecCord = vec2(vertexTCoord0.x, 1.0-vertexTCoord0.y);\n"
	"	mediump vec4 color = texture2D(gDiffuseSampler, tecCord);\n"
	"	gl_FragColor = color*vertexColor0;\n"
	"}\n"
};
//----------------------------------------------------------------------------