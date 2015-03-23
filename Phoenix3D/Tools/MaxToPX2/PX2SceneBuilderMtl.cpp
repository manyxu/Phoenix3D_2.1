/*
*
* 文件名称	：	PX2SceneBuilderMtl.cpp
*
*/

#include "PX2SceneBuilder.hpp"
#include "PX2ExportSettings.hpp"
#include "PX2AlphaProperty.hpp"
#include "PX2Shader.hpp"

#define PX2_DEFAULT_TEXTURE "Data/engine/default.png"

#define DIRECTX_9_SHADER_CLASS_ID Class_ID(0x0ed995e4 ,0x6133daf2)
//----------------------------------------------------------------------------
const TCHAR* SceneBuilder::msMapName[NTEXMAPS] =
{
	_T("map_ambient"),             // ID_AM 环境光
	_T("map_diffuse"),             // ID_DI 漫反射
	_T("map_specular"),            // ID_SP 高光颜色
	_T("map_shininess"),           // ID_SH 高光级别
	_T("map_shininess_strength"),  // ID_SS 光泽度
	_T("map_selfillumination"),    // ID_SI 自发光
	_T("map_opacity"),             // ID_OP 不透明度
	_T("map_filter_color"),        // ID_FI 过滤色
	_T("map_bump"),                // ID_BU 凹凸贴图
	_T("map_reflection"),          // ID_RL 反射
	_T("map_refraction"),          // ID_RR 折射
	_T("map_displacment")          // ID_DP 置换
};
//----------------------------------------------------------------------------
const char* SceneBuilder::msEnvName[5] =
{
	"env_explicit",
	"env_sphere",
	"env_cylinder",
	"env_shrink",
	"env_screen"
};
//----------------------------------------------------------------------------
const TCHAR* SceneBuilder::msMapEnvironment = _T("map_environment");
const TCHAR* SceneBuilder::msMapGeneric = _T("map_generic");
//----------------------------------------------------------------------------
void SceneBuilder::CollectMaterials(INode *node)
{
	Mtl *mtl = node->GetMtl();
	bool hasModifiers = IsNodeHasModifierSkin(node);

	if (mtl)
	{
		mMtls.Add(mtl);
	}

	for (int i=0; i<node->NumberOfChildren(); i++)
	{
		CollectMaterials(node->GetChildNode(i));
	}
}
//----------------------------------------------------------------------------
void SceneBuilder::ConvertMaterials ()
{
	int quantity = mMtls.GetQuantity();

	mMtlTreeList.resize(quantity);
	for (int i=0; i<quantity; i++)
	{
		Mtl *mtl = mMtls.GetMtl(i);
		if (mtl)
		{
			ConvertMaterial(*mtl, mMtlTreeList[i]);
		}
	}
}
//----------------------------------------------------------------------------
void SceneBuilder::ConvertMaterial (Mtl &mtl, MtlTree &mtlTree)
{
	// 光照属性
	PX2::Shine *shine = new0 PX2::Shine;
	Color color = mtl.GetAmbient();
	float alpha = 1.0f - mtl.GetXParency();
	shine->Ambient = PX2::Float4(color.r, color.g, color.b, 1.0f);
	color = mtl.GetDiffuse();
	shine->Diffuse = PX2::Float4(color.r, color.g, color.b, alpha);
	color = mtl.GetSpecular();
	float shininess = mtl.GetShininess()*2.0f;
	shine->Specular = PX2::Float4(color.r, color.g, color.b, shininess);

	const char *name = (const char*)mtl.GetName();
	shine->SetName(name);

	mtlTree.SetShine(shine);

	bool IsDirect9Shader = false;

	if (mtl.ClassID() == Class_ID(CMTL_CLASS_ID, 0)
		|| mtl.ClassID() == Class_ID(DMTL_CLASS_ID, 0))
	{
		bool isEnableDI = false;
		bool isEnableOP = false;
		float opacity = 1.0f;

		StdMat2 *stdMat2 = (StdMat2*)(&mtl);
		Interval valid = FOREVER;
		stdMat2->Update(mTimeStart, valid);

		std::string strName(stdMat2->GetName());
		bool doubleSide = (stdMat2->GetTwoSided()==1);

		char strBitMapName[256];
		memset(strBitMapName, 0, 256*sizeof(char));
		std::string resourcePath_Diffuse;

		PX2::Shader::SamplerFilter filter = PX2::Shader::SF_LINEAR_LINEAR;
		PX2::Shader::SamplerCoordinate uvCoord0 = PX2::Shader::SC_CLAMP;
		PX2::Shader::SamplerCoordinate uvCoord1 = PX2::Shader::SC_CLAMP;

		if (stdMat2->MapEnabled(ID_DI))
		{
			isEnableDI = true;

			BitmapTex *tex = (BitmapTex*)stdMat2->GetSubTexmap(ID_DI);
			int tt = tex->GetTextureTiling();
			if (tt & U_WRAP)
			{
				uvCoord0 = PX2::Shader::SC_REPEAT;
			}
			if (tt & V_WRAP)
			{
				uvCoord1 = PX2::Shader::SC_REPEAT;
			}

			BitmapInfo bI;
			const char *mapName = tex->GetMapName();
			TheManager->GetImageInfo(&bI, mapName);
			strcpy(strBitMapName, bI.Name());

			std::string fullName = std::string(strBitMapName);
			std::string srcRootDirStr = std::string(mSettings->SrcRootDir);
			std::string::size_type sizeT = srcRootDirStr.length();

			if (srcRootDirStr.length()>0 && ('\\'!=srcRootDirStr[srcRootDirStr.length()-1] &&
				'/'!=srcRootDirStr[srcRootDirStr.length()-1]))
			{
				sizeT += 1;
			}

			resourcePath_Diffuse = std::string(strBitMapName).substr(sizeT);			

			StdUVGen* uvGen = tex->GetUVGen();
			PX2_UNUSED(uvGen);
			int filType = tex->GetFilterType();
			switch (filType)
			{
				case FILTER_PYR:
					filter = PX2::Shader::SF_LINEAR_LINEAR;
					break;
				case FILTER_SAT:
					filter = PX2::Shader::SF_NEAREST;
					break;
				default:
					break;
			}
		}
		else
		{
			sprintf(strBitMapName, "%s/%s", mSettings->SrcRootDir, PX2_DEFAULT_TEXTURE);
			resourcePath_Diffuse = PX2_DEFAULT_TEXTURE;
		}

		if (stdMat2->MapEnabled(ID_OP))
		{
			isEnableOP = true;
		}
		opacity = stdMat2->GetOpacity(mTimeStart);

		PX2::Texture2D *tex2d_Diffuse = PX2::DynamicCast<PX2::Texture2D>(PX2::ResourceManager
			::GetSingleton().BlockLoad(strBitMapName));
		resourcePath_Diffuse = PX2::StringHelp::StandardisePath(resourcePath_Diffuse);
		resourcePath_Diffuse = resourcePath_Diffuse.substr(0, resourcePath_Diffuse.length()-1);
		tex2d_Diffuse->SetResourcePath(resourcePath_Diffuse);

		if (tex2d_Diffuse)
		{
			if (mSettings->IncludeSkins)
			{
				PX2::MaterialPtr px2mlt;

				if (mSettings->IsUseSingleTex)
				{
					px2mlt = new0 PX2::Texture2DMaterial();
				}
				else
				{
					px2mlt = new0 PX2::SkinMaterial();

				}

				px2mlt->GetPixelShader(0, 0)->SetFilter(0, PX2::Shader::SF_LINEAR_LINEAR);
				px2mlt->GetPixelShader(0, 0)->SetCoordinate(0, 0, uvCoord0);
				px2mlt->GetPixelShader(0, 0)->SetCoordinate(0, 1, uvCoord1);

				if (doubleSide)
				{
					px2mlt->GetCullProperty(0, 0)->Enabled = false;
				}

				px2mlt->GetAlphaProperty(0, 0)->BlendEnabled = false;
				px2mlt->GetAlphaProperty(0, 0)->CompareEnabled = false;

				if (opacity < 1.0f)
				{
					px2mlt->GetAlphaProperty(0, 0)->BlendEnabled = true;
				}
				else if (isEnableOP)
				{
					px2mlt->GetAlphaProperty(0, 0)->CompareEnabled = true;
					px2mlt->GetAlphaProperty(0, 0)->Compare = PX2::AlphaProperty::CM_GREATER;
					px2mlt->GetAlphaProperty(0, 0)->Reference = 0.25f;
				}

				px2mlt->_CalShaderKey();

				PX2::Texture2DMaterial *px2Tex2DMtl = PX2::DynamicCast<PX2::Texture2DMaterial>(px2mlt);
				PX2::SkinMaterial *skinMtl = PX2::DynamicCast<PX2::SkinMaterial>(px2mlt);

				if (px2Tex2DMtl)
				{
					PX2::MaterialInstance *instance = px2Tex2DMtl->CreateInstance(tex2d_Diffuse);
					mtlTree.SetMaterialInstance(instance);
				}
				else
				{
					PX2::MaterialInstance *instance = skinMtl->CreateInstance(0, tex2d_Diffuse, shine);
					mtlTree.SetMaterialInstance(instance);
				}
			}
			else
			{
				PX2::MaterialPtr px2mlt;

				if (mSettings->IsUseSingleTex)
				{
					px2mlt = new0 PX2::Texture2DMaterial();
				}
				else if (mSettings->IncludeVertexColors)
				{
					//px2mlt = new0 PX2::StdVC4Material();
				}
				else
				{
					//px2mlt = new0 PX2::StdMaterial();

				}

				px2mlt->GetPixelShader(0, 0)->SetFilter(0, PX2::Shader::SF_LINEAR_LINEAR);
				px2mlt->GetPixelShader(0, 0)->SetCoordinate(0, 0, uvCoord0);
				px2mlt->GetPixelShader(0, 0)->SetCoordinate(0, 1, uvCoord1);

				if (doubleSide)
				{
					px2mlt->GetCullProperty(0, 0)->Enabled = false;
				}

				px2mlt->GetAlphaProperty(0, 0)->BlendEnabled = false;
				px2mlt->GetAlphaProperty(0, 0)->CompareEnabled = false;

				if (opacity < 1.0f)
				{
					px2mlt->GetAlphaProperty(0, 0)->BlendEnabled = true;
				}
				else if (isEnableOP)
				{
					px2mlt->GetAlphaProperty(0, 0)->CompareEnabled = true;
					px2mlt->GetAlphaProperty(0, 0)->Compare = PX2::AlphaProperty::CM_GREATER;
					px2mlt->GetAlphaProperty(0, 0)->Reference = 0.25f;
				}

				px2mlt->_CalShaderKey();

				PX2::Texture2DMaterial *px2Tex2DMtl = PX2::DynamicCast<PX2::Texture2DMaterial>(px2mlt);
				//PX2::StdMaterial *px2StdMtl = PX2::DynamicCast<PX2::StdMaterial>(px2mlt);
				//PX2::StdVC4Material *px2StdVC4Mtl = PX2::DynamicCast<PX2::StdVC4Material>(px2mlt);

				//if (px2Tex2DMtl)
				//{
				//	PX2::MaterialInstance *instance = px2Tex2DMtl->CreateInstance(tex2d_Diffuse);
				//	mtlTree.SetMaterialInstance(instance);
				//}
				//else if (px2StdMtl)
				//{
				//	PX2::MaterialInstance *instance = px2StdMtl->CreateInstance(tex2d_Diffuse, shine, 0);
				//	mtlTree.SetMaterialInstance(instance);
				//}
				//else if (px2StdVC4Mtl)
				//{
				//	PX2::MaterialInstance *instance = px2StdVC4Mtl->CreateInstance(0, tex2d_Diffuse, shine, 0);
				//	mtlTree.SetMaterialInstance(instance);
				//}
			}
		}
		else
		{
			PX2::VertexColor4Material *vcMtl = new0 PX2::VertexColor4Material();
			PX2::MaterialInstance *instance = vcMtl->CreateInstance();
			mtlTree.SetMaterialInstance(instance);
		}
	}
	else if (mtl.ClassID() == Class_ID(MULTI_CLASS_ID, 0))
	{
	}
	else if (mtl.ClassID() == DIRECTX_9_SHADER_CLASS_ID)
	{
		IsDirect9Shader = true;

		IDxMaterial* dxMtl = (IDxMaterial*)mtl.GetInterface(IDXMATERIAL_INTERFACE);

		const char *effectName = 0;
#if MAX_RELEASE < 10000
		effectName = dxMtl->GetEffectFilename();
#else
		const MaxSDK::AssetManagement::AssetUser &au =  dxMtl->GetEffectFile();
		effectName = au.GetFileName();
#endif

		IParamBlock2 *paramBlock = mtl.GetParamBlock(0);

		std::string outPath;
		std::string outBaseName;
		std::string outExtention;
		PX2::StringHelp::SplitFullFilename(effectName, outPath, outBaseName,
			outExtention);

		PX2::ShinePtr shineStandard = new0 PX2::Shine();
		bool alphaVertex = false;
		PX2::Texture2DPtr diffTex;
		bool normalEnable = false;
		PX2::Texture2DPtr normalTex;
		float normalScale = 0.0f;
		bool specEnable = false;
		PX2::Texture2DPtr specTex;
		float specPower = 0.0f;
		bool reflectEnable = false;
		PX2::TextureCubePtr reflectTex;
		float reflectPower = 0.0f;
		bool doubleSide = false;
		int blendMode = 2;

		ParamBlockDesc2 *paramDesc = 0;
		int numParam = 0;
		if (paramBlock)
		{
			paramDesc = paramBlock->GetDesc();
			numParam = paramBlock->NumParams();

			ParamType2 paramType;
			for (int i=0; i<numParam; i++)
			{
				std::string parmName;
				PX2::Float4 color4 = PX2::Float4(0.0f, 0.0f, 0.0f, 0.0f);
				PX2::Float3 color3 = PX2::Float3(0.0f, 0.0f, 0.0f);
				float floatValue = 0.0f;
				bool boolValue = false;
				float *floatTable = 0;
				int intValue = 0;
				std::string str;
				PX2::Texture2D *tex2d = 0;

				paramType = paramBlock->GetParameterType((ParamID)i);

				if (TYPE_STRING == paramType)
					ConvertStringAttrib(paramBlock, i, parmName, str);
				else if (TYPE_FLOAT == paramType)
					ConvertFloatAttrib(paramBlock, i, parmName, floatValue);
				else if (TYPE_INT == paramType)
					ConvertIntAttrib(paramBlock, i, parmName, intValue);
				else if (TYPE_RGBA == paramType)
					ConvertColorAttrib(paramBlock, i, parmName, color4, i);
				else if (TYPE_POINT3 == paramType)
					ConvertPoint3Attrib(paramBlock, i, parmName, color3);
				else if (TYPE_POINT4 == paramType)
					ConvertPoint4Attrib(paramBlock, i, parmName, color4);
				else if (TYPE_BOOL == paramType)
					ConvertBoolAttrib(paramBlock, i, parmName, boolValue);
				else if (TYPE_FLOAT_TAB == paramType)
					ConvertFloatTabAttrib(paramBlock, i, parmName, floatTable);
				else if (TYPE_BITMAP == paramType)
					ConvertBitMapAttrib(paramBlock, i, parmName, tex2d);
				else if (TYPE_FRGBA ==paramType)
					ConvertFRGBAAttrib(paramBlock, i, parmName, color4);

				// shine
				if (parmName == "gBlendMode")
				{
					blendMode = intValue;
				}
				else if (parmName == "gShineEmissive")
				{
					shineStandard->Emissive = color4;
				}
				else if (parmName == "gShineAmbient")
				{
					shineStandard->Ambient = color4;
				}
				else if (parmName == "gShineDiffuse")
				{
					shineStandard->Diffuse = color4;
				}
				// alpha vertex
				else if (parmName == "gAlphaVertex")
				{
					alphaVertex = boolValue;
				}
				// diffuse
				else if (parmName == "gDiffuseTexture")
				{
					diffTex = tex2d;
				}
				// normal
				else if (parmName == "gNormalEnable")
				{
					normalEnable = boolValue;
				}
				else if (parmName == "gNormalTexture")
				{
					normalTex = tex2d;
				}
				else if (parmName == "gNormalScale")
				{
					normalScale = floatValue;
				}
				// specular
				else if (parmName == "gSpecularEnable")
				{
					specEnable = boolValue;
				}
				else if (parmName == "gSpecularTexture")
				{
					specTex = tex2d;
				}
				else if (parmName == "gSpecularPower")
				{
					specPower = floatValue;
				}
				// reflect
				else if (parmName == "gReflectionEnable")
				{
					reflectEnable = boolValue;
				}
				else if (parmName == "gReflectTexture")
				{
					//reflectTex = tex2d;
				}
				else if (parmName == "gReflectPower")
				{
					reflectPower = floatValue;
				}
				// other
				else if (parmName == "gDoubleSide")
				{
					doubleSide = boolValue;
				}
			}
		}

		PX2::MaterialInstancePtr inst;
		//PX2::VertexColorStdMaterialPtr vcStdMtl;
		//if (outBaseName == "VertexColorStd")
		//{
		//	vcStdMtl = new0 PX2::VertexColorStdMaterial();

		//	if (doubleSide)
		//	{
		//		vcStdMtl->GetCullProperty(0, 0)->Enabled = false;
		//	}

		//	if (0 == blendMode)
		//	{
		//		vcStdMtl->GetAlphaProperty(0, 0)->BlendEnabled = false;
		//		vcStdMtl->GetAlphaProperty(0, 0)->CompareEnabled = false;
		//		vcStdMtl->GetAlphaProperty(0, 0)->CompareEnabled = false;
		//	}
		//	else if (1 == blendMode)
		//	{
		//		vcStdMtl->GetAlphaProperty(0, 0)->BlendEnabled = false;
		//		vcStdMtl->GetAlphaProperty(0, 0)->Compare = PX2::AlphaProperty::CM_GREATER;
		//		vcStdMtl->GetAlphaProperty(0, 0)->Reference = 0.25f;
		//	}
		//	else if (2 == blendMode)
		//	{
		//		vcStdMtl->GetAlphaProperty(0, 0)->BlendEnabled = true;
		//		vcStdMtl->GetAlphaProperty(0, 0)->CompareEnabled = false;
		//	}
		//	else if (3 == blendMode)
		//	{
		//		vcStdMtl->GetAlphaProperty(0, 0)->BlendEnabled = true;
		//		vcStdMtl->GetAlphaProperty(0, 0)->CompareEnabled = false;
		//		vcStdMtl->GetAlphaProperty(0, 0)->SrcBlend = PX2::AlphaProperty::SBM_ONE;
		//		vcStdMtl->GetAlphaProperty(0, 0)->DstBlend = PX2::AlphaProperty::DBM_ONE;
		//	}

		//	inst = vcStdMtl->CreateInstance(diffTex, 0, shineStandard);
		//	inst->SetName("MI_ES_Default");
		//}

		//if (inst)
		//{
		//	mtlTree.SetMaterialInstance(inst);
		//}
		//else
		//{
		//	PX2::MaterialInstance *instance = PX2::VertexColor4Material::CreateUniqueInstance();
		//	instance->SetName("MI_VertexColor4");
		//	mtlTree.SetMaterialInstance(instance);
		//}
	}
	else
	{
		PX2::VertexColor4Material *vcMtl = new0 PX2::VertexColor4Material();
		PX2::MaterialInstance *instance = vcMtl->CreateInstance();
		instance->SetName("MI_VertexColor4");
		mtlTree.SetMaterialInstance(instance);
	}

	// 对子材质进行处理
	if (IsDirect9Shader)
		return;

	int mQuantity = mtl.NumSubMtls(); // Class_ID(MULTI_CLASS_ID, 0)
	if (mQuantity > 0)
	{
		mtlTree.SetMChildQuantity(mQuantity);
		for (int i=0; i<mQuantity; i++)
		{
			Mtl *subMtl = 0;
			subMtl = mtl.GetSubMtl(i);
			if (subMtl)
			{
				ConvertMaterial(*subMtl, mtlTree.GetMChild(i));
			}
		}
	}
}
//----------------------------------------------------------------------------
bool SceneBuilder::IsValidName (const char *str)
{
	int length = (int)strlen(str);
	if ( length == 0) 
		return false;

	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			continue;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			continue;
		else if (str[i] >= '1' && str[i] <= '9')
			continue;
		else if (str[i] == '0')
			continue;
		else if (str[i] == ' ')
			continue;
		else if (str[i] == '\t')
			continue;
		else if (str[i] == '_')
			continue;
		else if (str[i] == '-')
			continue;
		else if (str[i] == '/')
			continue;
		else if (str[i] == '\\')
			continue; 
		else
			return false;
	}
	return true;
}
//----------------------------------------------------------------------------
//bool HasAnimation(IParamBlock2 *block, int index)
//{
//	Control *control = block->GetController(index);
//	return control != 0;
//}
//----------------------------------------------------------------------------
bool SceneBuilder::ConvertStringAttrib (IParamBlock2 *paramBlock, int index, 
										std::string &name, std::string &str)
{
	PX2_UNUSED(name);
	PX2_UNUSED(str);

	ParamBlockDesc2 *paramDesc = paramBlock->GetDesc();

	if (!paramDesc)
		return false;

	ParamDef &paramDef = paramDesc->GetParamDef(paramDesc->IndextoID(index));

	Interval validInverval;
	BOOL retrieved = false;

#if MAX_RELEASE < 10000
	char *stringValue = 0;
	retrieved = paramBlock->GetValue((ParamID)index, 0, stringValue, validInverval);
#else
	MaxSDK::AssetManagement::AssetUser au;
	retrieved = paramBlock->GetValue((ParamID)index, 0, au, validInverval);
	const char *stringValue = au.GetFileName();
	PX2_UNUSED(stringValue);
#endif

	if (retrieved)
	{
		const const char* valueName = paramDef.int_name;
		if (!IsValidName(valueName))
		{
			valueName = paramBlock->GetLocalName((ParamID)index);
		}
		assertion(IsValidName(valueName), "valueName must be valuable.");
		name = valueName;

		PX2_UNUSED(name);

		assertion(false, "");
	}

	return true;
}
//----------------------------------------------------------------------------
bool SceneBuilder::ConvertFloatAttrib (IParamBlock2* paramBlock, int index, 
									   std::string &name, float &value)
{
	ParamBlockDesc2 *paramDesc = paramBlock->GetDesc();

	if(!paramDesc)
		return false;

	ParamDef &paramDef = paramDesc->GetParamDef(paramDesc->IndextoID(index));

	float floatValue;
	Interval validInverval;
	BOOL retrieved = paramBlock->GetValue((ParamID)index, 0, floatValue, validInverval);
	if(!retrieved)
	{
		return false;
	}

	const char *valueName = paramDef.int_name;
	if (!IsValidName(valueName))
	{
		valueName = paramBlock->GetLocalName((ParamID)index);
		assertion(IsValidName(valueName), "valueName must be valuable.");
	}
	name = std::string(valueName);

	//if (!HasAnimation(paramBlock, index))
	{
		value = floatValue;

		return true;
	}
}
//----------------------------------------------------------------------------
bool SceneBuilder::ConvertIntAttrib (IParamBlock2* paramBlock, int index, 
									 std::string &name, int &value)
{
	ParamBlockDesc2 *paramDesc = paramBlock->GetDesc();

	if (!paramDesc)
		return false;

	ParamDef& paramDef = 
		paramDesc->GetParamDef(paramDesc->IndextoID(index));

	int intValue;
	Interval validInverval;
	BOOL retrieved = false;

	retrieved = paramBlock->GetValue((ParamID)index, 0, intValue, validInverval);

	if (retrieved)
	{
		const char* valueName = paramDef.int_name;
		if (!IsValidName(valueName))
		{
			valueName = paramBlock->GetLocalName((ParamID)index);
			assertion(IsValidName(valueName), "valueName must be valuable.");
		}
		name = std::string(valueName);

		value = intValue;
	}

	return true;
}
//----------------------------------------------------------------------------
bool SceneBuilder::ConvertColorAttrib(IParamBlock2 *paramBlock, int index,
									  std::string &name, PX2::Float4 &color,
									  int &increment)
{
	ParamBlockDesc2 *paramDesc = paramBlock->GetDesc();
	int numParams = paramBlock->NumParams();

	if (!paramDesc)
		return false;

	ParamDef &colorParamDef = paramDesc->GetParamDef(
		paramDesc->IndextoID(index));
	ParamDef &alphaParamDef = paramDesc->GetParamDef(
		paramDesc->IndextoID(index+1));

	Color colorValue;
	float alphaValue = 255.0f;
	Interval validInterval;
	BOOL retrievedColor = false;
	BOOL retrievedAlpha = false;
	int alphaIndex = index + 1;

	retrievedColor = paramBlock->GetValue((ParamID)index, 0, colorValue, 
		validInterval);

	if (alphaIndex < numParams)
	{
		int param_type = paramBlock->GetParameterType((ParamID)alphaIndex);
		if (param_type == TYPE_FLOAT)
		{
			retrievedAlpha = paramBlock->GetValue((ParamID)alphaIndex, 0, 
				alphaValue, validInterval);
		}
	}

	if (retrievedColor)
	{
		const char* valueName = colorParamDef.int_name;
		if (!IsValidName(valueName))
		{
			valueName = paramBlock->GetLocalName((ParamID)index);
		}
		assertion(IsValidName(valueName), "valueName must be valuable.");
		name = std::string(valueName);

		//Control *colorControl = paramBlock->GetController(index, 0);
		//PX2_UNUSED(colorControl);

		bool hasAlpha = false;
		//Control *alphaControl = 0;
		if (retrievedAlpha)
		{
			const char *valueAlphaName = alphaParamDef.int_name;
			if (!IsValidName(valueAlphaName))
				valueName = paramBlock->GetLocalName((ParamID)alphaIndex);
			assertion(IsValidName(valueAlphaName), "valueName must be valuable.");

		/*	alphaControl = paramBlock->GetController(alphaIndex, 0);*/

			std::string strColorName = valueName;
			strColorName += "Alpha";
			if (!strcmp(strColorName.c_str(), valueAlphaName))
			{
				hasAlpha = true;
				increment++;
			}
			else
			{
				//alphaControl = 0;
			}
		}

		if (hasAlpha)
		{
			color = PX2::Float4(colorValue.r, colorValue.g, colorValue.b, 
				alphaValue);
		}
		else
		{
			color = PX2::Float4(colorValue.r, colorValue.g, colorValue.b, 1.0f);
		}
	}

	return true;
}
//----------------------------------------------------------------------------
bool SceneBuilder::ConvertPoint3Attrib (IParamBlock2 *paramBlock, int index,
						  std::string &name, PX2::Float3 &value)
{
	ParamBlockDesc2 *paramDesc = paramBlock->GetDesc();

	if (!paramDesc)
		return false;

	ParamDef &paramDef = paramDesc->GetParamDef(paramDesc->IndextoID(index));

	Point3 vectorValue;
	Interval validInterval;
	BOOL retrieved = false;

	retrieved = paramBlock->GetValue ((ParamID)index, 0, vectorValue, validInterval);

	if (retrieved)
	{
		const char *valueName = paramDef.int_name;
		if (!IsValidName(valueName))
		{
			valueName = paramBlock->GetLocalName((ParamID)index);
			assertion(IsValidName(valueName), "valueName must be valuable.");
		}
		name = std::string(valueName);

		value = PX2::Float3(vectorValue.x, vectorValue.y, vectorValue.z);
	}

	return true;
}
//----------------------------------------------------------------------------
bool SceneBuilder::ConvertPoint4Attrib (IParamBlock2 *paramBlock, int index,
										std::string &name, PX2::Float4 &value)
{
	ParamBlockDesc2 *paramDesc = paramBlock->GetDesc();

	if (!paramDesc)
		return false;

	ParamDef &paramDef = paramDesc->GetParamDef(paramDesc->IndextoID(index));

	Point4 vectorValue;
	Interval validInterval;
	BOOL retrieved = false;

	retrieved = paramBlock->GetValue((ParamID)index, 0, vectorValue, validInterval);

	if (retrieved)
	{
		const char *valueName = paramDef.int_name;
		if (!IsValidName(valueName))
		{
			valueName = paramBlock->GetLocalName((ParamID)index);
			assertion(IsValidName(valueName), "valueName must be valuable.");
		}
		name = std::string(valueName);

		value = PX2::Float4(vectorValue.x, vectorValue.y, vectorValue.z, vectorValue.w);
	}

	return true;
}
//----------------------------------------------------------------------------
bool SceneBuilder::ConvertBoolAttrib (IParamBlock2 *paramBlock, int index,
									  std::string &name, bool &value)
{
	ParamBlockDesc2 *paramDesc = paramBlock->GetDesc();

	if (!paramDesc)
		return false;

	ParamDef& paramDef = paramDesc->GetParamDef(paramDesc->IndextoID(index));

	int intValue;
	Interval validInterval;
	BOOL retrieved = false;

	retrieved =  paramBlock->GetValue ((ParamID)index, 0 , intValue, validInterval );

	if (retrieved)
	{
		const char *valueName = paramDef.int_name;
		if (!IsValidName(valueName))
		{
			valueName = paramBlock->GetLocalName((ParamID)index);
			assertion(IsValidName(valueName), "valueName must be valuable.");
		}
		name = std::string(valueName);

		value = (1 == intValue);
	}

	return true;
}
//----------------------------------------------------------------------------
bool SceneBuilder::ConvertFloatTabAttrib (IParamBlock2* paramBlock, int index, 
										  std::string &name, float *table)
{
	ParamBlockDesc2 *paramDesc = paramBlock->GetDesc();

	if (!paramDesc)
		return false;

	ParamDef& paramDef = paramDesc->GetParamDef(paramDesc->IndextoID(index));

	Interval validInterval;
	BOOL retrieved = true;

	int count = paramBlock->Count(paramDesc->IndextoID(index));
	if (count == 0)
		return false;

	float* floats = new float[count];
	IParamBlock2* params = paramBlock;

	for (int i=0; i<count; i++)
	{
		retrieved &= params->GetValue((ParamID)index, 0 , floats[i], validInterval,
			i);
	}

	if (retrieved && count > 0)
	{
		const char *valueName = paramDef.int_name;
		if (!IsValidName(valueName))
		{
			valueName = paramBlock->GetLocalName((ParamID)index);
			assertion(IsValidName(valueName), "valueName must be valuable.");
		}
		name = std::string(valueName);

		for (int i=0; i<count; i++)
		{
			table[i] = floats[i];
		}
	}

	return true;
}
//----------------------------------------------------------------------------
bool SceneBuilder::ConvertIntListBoxAttrib (IParamBlock2* paramBlock,
											int index, std::string &name, 
											int &value)
{
	ParamBlockDesc2 *paramDesc = paramBlock->GetDesc();

	if (!paramDesc)
		return false;

	ParamDef& paramDef = paramDesc->GetParamDef(paramDesc->IndextoID(index));

	int intValue;
	Interval validInverval;
	BOOL retrieved = false;

	retrieved = paramBlock->GetValue((ParamID)index, 0, intValue,
		validInverval);

	if (retrieved)
	{
		const char* valueName = paramDef.int_name;
		if (!IsValidName(valueName))
		{
			valueName = paramBlock->GetLocalName((ParamID)index);
			assertion(IsValidName(valueName), "valueName must be valuable.");
		}
		name = std::string(valueName);

		//3ds Max中数组从1开始,这里的index要减1
		value = (intValue==-1) ? -1 : (intValue-1);
	}

	return true;
}
//----------------------------------------------------------------------------
bool SceneBuilder::ConvertBitMapAttrib(IParamBlock2* paramBlock, int index,
									   std::string &name, 
									   PX2::Texture2D *&tex2d)
{
	ParamBlockDesc2 *paramDesc = paramBlock->GetDesc();

	if (!paramDesc)
		return false;

	ParamDef &paramDef = paramDesc->GetParamDef(paramDesc->IndextoID(index));
	PX2_UNUSED(paramDef);

	PBBitmap *pb;
	Interval validInterval;
	BOOL retrieved = false;	
	retrieved = paramBlock->GetValue((ParamID)index, 0, pb, validInterval);

	char strBitMapName[256];
	memset(strBitMapName, 0, 256*sizeof(char));
	if (pb)
	{
		if (BMMGetFullFilename(&pb->bi) == TRUE)
		{
			strcpy(strBitMapName, pb->bi.Name());

			std::string resourcePath;
			std::string fullName = std::string(strBitMapName);
			std::string::size_type sizeT = fullName.find_first_not_of(mSettings->SrcRootDir);
			resourcePath = std::string(strBitMapName).substr(sizeT);

			tex2d = PX2::DynamicCast<PX2::Texture2D>(
				PX2::ResourceManager::GetSingleton().BlockLoad(strBitMapName));
			resourcePath = PX2::StringHelp::StandardisePath(resourcePath);
			resourcePath = resourcePath.substr(0, resourcePath.length()-1);
			tex2d->SetResourcePath(resourcePath);
		}
	}

	if (retrieved)
	{
		const char *valueName = paramDef.int_name;
		if (!IsValidName(valueName))
			valueName = paramBlock->GetLocalName((ParamID)index);
		assertion(IsValidName(valueName), "valueName must be valuable.");
		name = valueName;
	}

	return true;
}
//----------------------------------------------------------------------------
bool SceneBuilder::ConvertFRGBAAttrib(IParamBlock2* paramBlock, int index,
									  std::string &name, PX2::Float4 &value)
{
	ParamBlockDesc2 *paramDesc = paramBlock->GetDesc();

	if (!paramDesc)
		return false;

	ParamDef &paramDef = paramDesc->GetParamDef(paramDesc->IndextoID(index));

	Point4 vectorValue;
	Interval validInterval;
	BOOL retrieved = false;	

	retrieved =  paramBlock->GetValue((ParamID)index, 0 , vectorValue, validInterval);
	if(retrieved)
	{
		const char *valueName = paramDef.int_name;
		if (!IsValidName(valueName)) 
			valueName = paramBlock->GetLocalName((ParamID)index );
		assertion(IsValidName(valueName), "valueName must be valuable.");
		name = std::string(valueName);

		value = PX2::Float4(vectorValue.x, vectorValue.y, vectorValue.z, 
			vectorValue.w);

		//if(HasAnimation(paramBlock, index))
		//{
		//}
	}

	return true;
}
//----------------------------------------------------------------------------
//void SceneBuilder::ConvertTexture (Texmap &tex, Class_ID classID, int subNo, 
//								   TexTree &tree)
//{
//	PX2_UNUSED(subNo);
//	PX2_UNUSED(classID);
//
//	if (tex.ClassID() == Class_ID(BMTEX_CLASS_ID, 0))
//	{
//		BitmapTex &bmpTex = (BitmapTex&)tex;
//		Bitmap *bmp = bmpTex.GetBitmap(mTimeStart);
//		if (bmp)
//		{
//			assertion(false, "no bitmap.");
//			return;
//		}
//
//		TSTR fileName = bmpTex.GetMapName();
//		char drive[_MAX_DRIVE];
//		char dir[_MAX_DIR];
//		char fName[_MAX_FNAME];  // 路径名被去掉了的文件名
//		char ext[_MAX_EXT];
//		_splitpath_s(fileName.data(),drive,_MAX_DRIVE,dir,_MAX_DIR,
//			fName,_MAX_FNAME,ext,_MAX_EXT);
//
//		strcat_s(fName, _MAX_FNAME, ".txtf");
//
//		PX2::Texture2D *texture;
//		PX2::Texture::Format format = PX2::Texture::TF_A8B8G8R8;
//		int bytesPerPixel = 4;
//		int width = bmp->Width();
//		int height = bmp->Height();
//		bool hasAlpha = (bmp->HasAlpha() == 1);
//
//	//	if (mSettings->GenerateMaps)
//		{
//			int quantity = width * height * bytesPerPixel;
//			unsigned char *aDst = new1<unsigned char>(quantity);
//			unsigned char *pDst = aDst;
//			BMM_Color_64 *scanLine = new1<BMM_Color_64>(width);
//			BMM_Color_64 *pixel = 0;
//			BMM_Color_32 scaledColor;
//			for (int y=height-1; y>=0; y--)
//			{
//				bmp->GetLinearPixels(0, y, width, scanLine);
//				pixel = scanLine;
//				for (int x=0; x<width; x++)
//				{
//					AColor color(*pixel);
//					scaledColor = (BMM_Color_32)color;
//					if (hasAlpha)
//						*pDst++ = (unsigned char)scaledColor.a;
//					else
//						*pDst++ = (unsigned)255;
//					*pDst++ = (unsigned char)scaledColor.b;
//					*pDst++ = (unsigned char)scaledColor.g;
//					*pDst++ = (unsigned char)scaledColor.r;
//					pixel++;
//				}
//			}
//
//			delete1(scanLine);
//
//			texture = new0 PX2::Texture2D(format, width, height, 1);
//
//			int format = (int)texture->GetFormat();
//			int type = (int)texture->GetTextureType();
//			int usage = (int)texture->GetUsage();
//			int numLevels = texture->GetNumDimensions();
//			int numDimensions = texture->GetNumDimensions();
//			int numTotalBytes = texture->GetNumTotalBytes();
//
//			int dimension[3][PX2::Texture::MM_MAX_MIPMAP_LEVELS];
//			int numLevelBytes[PX2::Texture::MM_MAX_MIPMAP_LEVELS];
//			int levelOffsets[PX2::Texture::MM_MAX_MIPMAP_LEVELS];
//			for (int level = 0; level<PX2::Texture::MM_MAX_MIPMAP_LEVELS;
//				++level)
//			{
//				dimension[0][level] = texture->GetDimension(0, level);
//				dimension[1][level] = texture->GetDimension(1, level);
//				dimension[2][level] = texture->GetDimension(2, level);
//				numLevelBytes[level] = texture->GetNumLevelBytes(level);
//				levelOffsets[level] = texture->GetLevelOffset(level);
//			}
//
//			int userField[PX2::Texture::MAX_USER_FIELDS];
//			for (int j=0; j<PX2::Texture::MAX_USER_FIELDS; ++j)
//			{
//				userField[j] = 0;
//			}
//
//			FILE *outFile = fopen(fName, "wb");
//			if (!outFile)
//			{
//				assert(outFile);
//				delete1(aDst);
//				delete0(texture);
//			}
//
//			fwrite(&format, sizeof(int), 1, outFile);
//			fwrite(&type, sizeof(int), 1, outFile);
//			fwrite(&usage, sizeof(int), 1, outFile);
//			fwrite(&numLevels, sizeof(int), 1, outFile);
//			fwrite(&numDimensions, sizeof(int), 1, outFile);
//			fwrite(dimension[0], sizeof(int), PX2::Texture::MM_MAX_MIPMAP_LEVELS,
//				outFile);
//			fwrite(dimension[1], sizeof(int), PX2::Texture::MM_MAX_MIPMAP_LEVELS,
//				outFile);
//			fwrite(dimension[2], sizeof(int), PX2::Texture::MM_MAX_MIPMAP_LEVELS,
//				outFile);
//			fwrite(numLevelBytes, sizeof(int), PX2::Texture::MM_MAX_MIPMAP_LEVELS,
//				outFile);
//			fwrite(&numTotalBytes, sizeof(int), 1, outFile);
//			fwrite(levelOffsets, sizeof(int), PX2::Texture::MM_MAX_MIPMAP_LEVELS,
//				outFile);
//			fwrite(userField, sizeof(int), PX2::Texture::MAX_USER_FIELDS, outFile);
//			fwrite(aDst, sizeof(unsigned char), numLevelBytes[0], outFile);
//			fclose(outFile);
//
//			delete1(aDst);
//			delete0(texture);
//		}
//	}
//
//	// 处理附加贴图
//	int tQuantity = tex.NumSubTexmaps();
//	if (tQuantity)
//	{
//		tree.SetChildQuantity(tQuantity);
//		for (int i=0; i<tQuantity; i++)
//		{
//			Texmap *subTex = tex.GetSubTexmap(i);
//			if (subTex)
//			{
//				ConvertTexture(*subTex, tex.ClassID(), i,
//					tree.GetChild(i));
//			}
//		}
//	}
//}
////----------------------------------------------------------------------------
