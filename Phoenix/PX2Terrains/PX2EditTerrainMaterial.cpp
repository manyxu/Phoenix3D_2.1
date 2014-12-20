/*
*
* 文件名称	：	PX2EditTerrainMaterial.cpp
*
*/

#include "PX2EditTerrainMaterial.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Material, EditTerrainMaterial);
PX2_IMPLEMENT_STREAM(EditTerrainMaterial);
PX2_IMPLEMENT_FACTORY(EditTerrainMaterial);
PX2_IMPLEMENT_DEFAULT_NAMES(Material, EditTerrainMaterial);

//----------------------------------------------------------------------------
EditTerrainMaterial::EditTerrainMaterial ()
{
	// vertex shader
	VertexShader* vshader = new0 VertexShader("PX2.EditTerrain",
		3, 4, 12, 0, false);
	vshader->SetInput(0, "modelPosition", Shader::VT_FLOAT3, Shader::VS_POSITION);
	vshader->SetInput(1, "modelNormal", Shader::VT_FLOAT3, Shader::VS_NORMAL);
	vshader->SetInput(2, "modelTCoord0", Shader::VT_FLOAT2, Shader::VS_TEXCOORD0);

	vshader->SetOutput(0, "clipPosition", Shader::VT_FLOAT4, Shader::VS_POSITION);
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

	// pixel shader
	PixelShader* pshader = new0 PixelShader("PX2.EditTerrain",
		3, 1, 4, 6, false);

	pshader->SetInput(0, "vertexColor", Shader::VT_FLOAT4,	Shader::VS_COLOR0);
	pshader->SetInput(1, "vertexTCoord0", Shader::VT_FLOAT2, Shader::VS_TEXCOORD0);
	pshader->SetInput(2, "vertexTCoord1", Shader::VT_FLOAT2, Shader::VS_TEXCOORD1);
	pshader->SetOutput(0, "pixelColor", Shader::VT_FLOAT4, Shader::VS_COLOR0);

	pshader->SetConstant(0, "UVScale01", 1);
	pshader->SetConstant(1, "UVScale23", 1);
	pshader->SetConstant(2, "UVScale4", 1);
	pshader->SetConstant(3, "FogColor", 1);

	pshader->SetSampler(0, "Sampler0", Shader::ST_2D);
	pshader->SetFilter(0, Shader::SF_LINEAR_LINEAR);
	pshader->SetCoordinate(0, 0, Shader::SC_REPEAT);
	pshader->SetCoordinate(0, 1, Shader::SC_REPEAT);

	pshader->SetSampler(1, "SamplerAlpha", Shader::ST_2D);
	pshader->SetFilter(1, Shader::SF_LINEAR);
	pshader->SetCoordinate(1, 0, Shader::SC_CLAMP_EDGE);
	pshader->SetCoordinate(1, 1, Shader::SC_CLAMP_EDGE);

	pshader->SetSampler(2, "Sampler1", Shader::ST_2D);
	pshader->SetFilter(2, Shader::SF_LINEAR_LINEAR);
	pshader->SetCoordinate(2, 0, Shader::SC_REPEAT);
	pshader->SetCoordinate(2, 1, Shader::SC_REPEAT);

	pshader->SetSampler(3, "Sampler2", Shader::ST_2D);
	pshader->SetFilter(3, Shader::SF_LINEAR_LINEAR);
	pshader->SetCoordinate(3, 0, Shader::SC_REPEAT);
	pshader->SetCoordinate(3, 1, Shader::SC_REPEAT);

	pshader->SetSampler(4, "Sampler3", Shader::ST_2D);
	pshader->SetFilter(4, Shader::SF_LINEAR_LINEAR);
	pshader->SetCoordinate(4, 0, Shader::SC_REPEAT);
	pshader->SetCoordinate(4, 1, Shader::SC_REPEAT);

	pshader->SetSampler(5, "Sampler4", Shader::ST_2D);
	pshader->SetFilter(5, Shader::SF_LINEAR_LINEAR);
	pshader->SetCoordinate(5, 0, Shader::SC_REPEAT);
	pshader->SetCoordinate(5, 1, Shader::SC_REPEAT);

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

	vshader->SetShaderKey(SKT_TERRAIN);
	pshader->SetShaderKey(SKT_TERRAIN);
}
//----------------------------------------------------------------------------
EditTerrainMaterial::~EditTerrainMaterial ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void EditTerrainMaterial::RegistProperties ()
{
	Material::RegistProperties();
	AddPropertyClass("EditTerrainMaterial");
}
//----------------------------------------------------------------------------
void EditTerrainMaterial::OnPropertyChanged (const PropertyObject &obj)
{
	Material::OnPropertyChanged(obj);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
EditTerrainMaterial::EditTerrainMaterial (LoadConstructor value)
	:
Material(value)
{
}
//----------------------------------------------------------------------------
void EditTerrainMaterial::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Material::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(EditTerrainMaterial, source);
}
//----------------------------------------------------------------------------
void EditTerrainMaterial::Link (InStream& source)
{
	Material::Link(source);
}
//----------------------------------------------------------------------------
void EditTerrainMaterial::PostLink ()
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

	vshader->SetShaderKey(SKT_TERRAIN);
	pshader->SetShaderKey(SKT_TERRAIN);
}
//----------------------------------------------------------------------------
bool EditTerrainMaterial::Register (OutStream& target) const
{
	return Material::Register(target);
}
//----------------------------------------------------------------------------
void EditTerrainMaterial::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Material::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(EditTerrainMaterial, target);
}
//----------------------------------------------------------------------------
int EditTerrainMaterial::GetStreamingSize (Stream &stream) const
{
	int size = Material::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	return size;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 版本
//----------------------------------------------------------------------------
int EditTerrainMaterial::msDx9VRegisters[12] =		{ 0, 4, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
int EditTerrainMaterial::msOglVRegisters[12] =		{ 1, 5, 9, 10,11, 12, 13, 14, 15, 16, 17, 18};
int EditTerrainMaterial::msOpenGLES2VRegisters[12] ={ 1, 5, 9, 10,11, 12, 13, 14, 15, 16, 17, 18};
int* EditTerrainMaterial::msVRegisters[Shader::MAX_PROFILES] =
{
	0,
	msDx9VRegisters,
	msDx9VRegisters,
	msDx9VRegisters,
	msOglVRegisters,
	msOpenGLES2VRegisters
};

std::string EditTerrainMaterial::msVPrograms[Shader::MAX_PROFILES] =
{
	// VP_NONE
	"",

	// VP_VS_1_1
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
	"",

	// vp_gles2
	"uniform mediump mat4 gPVWMatrix;\n"
	"uniform mediump vec4 gShineEmissive;\n"
	"uniform mediump vec4 gShineAmbient;\n"
	"uniform mediump vec4 gShineDiffuse;\n"
	"uniform mediump vec4 gLightColour;\n"
	"uniform mediump vec4 gLightAttenuation;\n"
	"uniform mediump vec4 gLightModelDirection;\n"
	"attribute mediump vec3 modelPosition;\n"
	"attribute mediump vec3 modelNormal;\n"
	"attribute mediump vec4 modelColor0;\n"
	"attribute mediump vec2 modelTCoord0;\n"
	"varying mediump vec4 vertexColor0;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = gPVWMatrix*vec4(modelPosition, 1.0);\n"
	"	vertexColor0.rgb = modelColor0.rgb + gShineEmissive.rgb"
	"		+ gLightColour.rgb*gShineAmbient.rgb*gLightAttenuation[3]"
	"		+ gLightColour.rgb*gShineDiffuse.rgb*gLightAttenuation[3]"
	"		* max(0.0, dot(modelNormal, -gLightModelDirection.xyz));\n"
	"	vertexColor0.a = gShineDiffuse.a;\n"
	"	vertexTCoord0 = vec2(modelTCoord0.x, modelTCoord0.y);\n"
	"}\n"
};

int EditTerrainMaterial::msAllPRegisters[4] = { 0, 1, 2, 3};

int* EditTerrainMaterial::msPRegisters[Shader::MAX_PROFILES] =
{
	0,
	msAllPRegisters,
	msAllPRegisters,
	msAllPRegisters,
	msAllPRegisters,
	msAllPRegisters
};

int EditTerrainMaterial::msAllPTextureUnits[6] = { 0, 1, 2, 3, 4, 5};
int* EditTerrainMaterial::msPTextureUnits[Shader::MAX_PROFILES] =
{
	0,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits,
	msAllPTextureUnits
};

std::string EditTerrainMaterial::msPPrograms[Shader::MAX_PROFILES] =
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
	"dcl_2d s3\n"
	"dcl_2d s4\n"
	"dcl_2d s5\n"
	"def c4, 1.00000000, 0, 0, 0\n"
	"dcl t0.xy\n"
	"dcl t1.xy\n"
	"dcl v0\n"
	"texld r5, t0, s1\n"
	"add r2.y, -t0, c4.x\n"
	"mov r2.x, t0\n"
	"mul r4.xy, r2, c2\n"
	"mov r0.y, c0.w\n"
	"mov r0.x, c0.z\n"
	"mul r1.xy, r2, r0\n"
	"mov r0.y, c1.w\n"
	"mov r0.x, c1.z\n"
	"mul r3.xy, r2, r0\n"
	"mul r0.xy, r2, c0\n"
	"mul r2.xy, r2, c1\n"
	"texld r4, r4, s5\n"
	"texld r3, r3, s4\n"
	"texld r2, r2, s3\n"
	"texld r0, r0, s0\n"
	"texld r1, r1, s2\n"
	"add r1, r1, -r0\n"
	"mad r0, r5.x, r1, r0\n"
	"add r1, r2, -r0\n"
	"mad r0, r5.y, r1, r0\n"
	"add r1, r3, -r0\n"
	"mad r0, r5.z, r1, r0\n"
	"add r1, r4, -r0\n"
	"mad r0, r5.w, r1, r0\n"
	"add r0.xyz, r0, -c3\n"
	"mul r0.xyz, t1.x, r0\n"
	"mad r0.xyz, t1.y, r0, c3\n"
	"mul r0, r0, v0\n"
	"mov oC0, r0\n",

	// PP_PS_3_0
	"ps_3_0\n"
	"dcl_2d s0\n"
	"dcl_2d s1\n"
	"dcl_2d s2\n"
	"dcl_2d s3\n"
	"dcl_2d s4\n"
	"dcl_2d s5\n"
	"def c4, 1.00000000, 0, 0, 0\n"
	"dcl_texcoord0 v1.xy\n"
	"dcl_texcoord1 v2.xy\n"
	"dcl_color0 v0\n"
	"mov r3.z, v1.x\n"
	"add r3.w, -v1.y, c4.x\n"
	"mul r0.xy, r3.zwzw, c0\n"
	"mul r1.xy, r3.zwzw, c0.zwzw\n"
	"texld r0, r0, s0\n"
	"texld r1, r1, s2\n"
	"add r2, r1, -r0\n"
	"texld r1, v1, s1\n"
	"mad r0, r1.x, r2, r0\n"
	"mul r3.xy, r3.zwzw, c1\n"
	"texld r2, r3, s3\n"
	"add r2, r2, -r0\n"
	"mad r0, r1.y, r2, r0\n"
	"mul r3.xy, r3.zwzw, c1.zwzw\n"
	"texld r2, r3, s4\n"
	"add r2, r2, -r0\n"
	"mad r0, r1.z, r2, r0\n"
	"mul r1.xy, r3.zwzw, c2\n"
	"texld r2, r1, s5\n"
	"add r2, r2, -r0\n"
	"mad r0, r1.w, r2, r0\n"
	"add r0.xyz, r0, -c3\n"
	"mul r0.xyz, v2.x, r0\n"
	"mad r0.xyz, v2.y, r0, c3\n"
	"mul oC0, r0, v0\n",

	// PP_ARBFP1
	"",

	// fp_gles2
	"varying mediump vec4 vertexColor0;\n"
	"varying mediump vec2 vertexTCoord0;\n"
	"uniform sampler2D Sampler0;\n"
	"uniform sampler2D SamplerAlpha;\n"
	"uniform sampler2D Sampler1;\n"
	"uniform sampler2D Sampler2;\n"
	"uniform sampler2D Sampler3;\n"
	"uniform sampler2D Sampler4;\n"
	"uniform mediump vec4 UVScale01;\n"
	"uniform mediump vec4 UVScale23;\n"
	"uniform mediump vec4 UVScale4;\n"
	"void main()\n"
	"{\n"
	"	mediump vec4 color0 = texture2D(Sampler0, vertexTCoord0*UVScale01.xy);\n"
	"	mediump vec4 colorAlpha = texture2D(SamplerAlpha, vertexTCoord0);\n"
	"	mediump vec4 color1 = texture2D(Sampler1, vertexTCoord0*UVScale01.zw);\n"
	"	mediump vec4 color2 = texture2D(Sampler2, vertexTCoord0*UVScale23.xy);\n"
	"	mediump vec4 color3 = texture2D(Sampler3, vertexTCoord0*UVScale23.zw);\n"
	"	mediump vec4 color4 = texture2D(Sampler4, vertexTCoord0*UVScale4.xy);\n"
	"	mediump vec4 lastColor = color0 + (color1-color0)*colorAlpha.r;\n"
	"	lastColor = lastColor + (color2-lastColor)*colorAlpha.g;\n"
	"	lastColor = lastColor + (color3-lastColor)*colorAlpha.b;\n"
	"	lastColor = lastColor + (color4-lastColor)*colorAlpha.a;\n"
	"	gl_FragColor = lastColor*vertexColor0;\n"
	"}\n"
};
//----------------------------------------------------------------------------