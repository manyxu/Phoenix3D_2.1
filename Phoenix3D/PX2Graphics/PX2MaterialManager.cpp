// PX2MaterialManager.cpp

#include "PX2MaterialManager.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2PVMatrixConstant.hpp"
#include "PX2PVWMatrixConstant.hpp"
#include "PX2WMatrixConstant.hpp"
#include "PX2ProjectorMatrixConstant.hpp"
#include "PX2ShineEmissiveConstant.hpp"
#include "PX2ShineAmbientConstant.hpp"
#include "PX2ShineDiffuseConstant.hpp"
#include "PX2ShineSpecularConstant.hpp"
#include "PX2CameraWorldPositionConstant.hpp"
#include "PX2CameraModelPositionConstant.hpp"
#include "PX2LightWorldDVectorConstant.hpp"
#include "PX2LightAmbientConstant.hpp"
#include "PX2LightDiffuseConstant.hpp"
#include "PX2LightSpecularConstant.hpp"
#include "PX2FogParamConstant.hpp"
#include "PX2FogColorHeightConstant.hpp"
#include "PX2FogColorDistConstant.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
MaterialManager::MaterialManager() :
mNextShaderKey(1000)
{
}
//----------------------------------------------------------------------------
MaterialManager::~MaterialManager()
{
}
//----------------------------------------------------------------------------
bool MaterialManager::Initlize()
{
	mNextShaderKey = 1000;

	return true;
}
//----------------------------------------------------------------------------
bool MaterialManager::Terminate()
{
	mMaterialMap.clear();

	return true;
}
//----------------------------------------------------------------------------
Material *MaterialManager::GetMaterial(const FString &filename, bool share)
{
	if (share)
	{
		Material *mtl = 0;
		std::map<FString, _MtlObject>::iterator it = mMaterialMap.find(filename);
		if (it != mMaterialMap.end())
		{
			mtl = it->second.TheMaterial;
		}
		else
		{
			int shaderKey = QueryShaderKey();

			mtl = DynamicCast<Material>(GraphicsRoot::msUserLoadFun(filename));
			mMaterialMap[filename].TheMaterial = mtl;
			mMaterialMap[filename].ShaderKey = shaderKey;

			_SetMaterialShaderKey(mtl, shaderKey);
		}

		return mtl;
	}
	else
	{
		Material *mtl = 0;
		mtl = DynamicCast<Material>(GraphicsRoot::msUserLoadFun(filename));

		std::map<FString, _MtlObject>::iterator it = mMaterialMap.find(filename);
		if (it != mMaterialMap.end())
		{
			_SetMaterialShaderKey(mtl, it->second.ShaderKey);
		}
		else
		{
			int shaderKey = QueryShaderKey();

			mMaterialMap[filename].TheMaterial = mtl;
			mMaterialMap[filename].ShaderKey = shaderKey;

			_SetMaterialShaderKey(mtl, shaderKey);
		}

		return mtl;
	}
}
//----------------------------------------------------------------------------
void MaterialManager::AddMaterial(const FString &filename, Material *mtl)
{
	int shaderKey = 99999;
	std::map<FString, _MtlObject>::iterator it = mMaterialMap.find(filename);
	if (it == mMaterialMap.end())
	{
		shaderKey = QueryShaderKey();

		mMaterialMap[filename].TheMaterial = mtl;
		mMaterialMap[filename].ShaderKey = shaderKey;
	}
	else
	{
		shaderKey = it->second.ShaderKey;
	}

	_SetMaterialShaderKey(mtl, shaderKey);
}
//----------------------------------------------------------------------------
int MaterialManager::QueryShaderKey()
{
	return mNextShaderKey++;
}
//----------------------------------------------------------------------------
void MaterialManager::_SetMaterialShaderKey(Material *mtl, int shaderKey)
{
	int numTechniques = mtl->GetNumTechniques();
	for (int i = 0; i < numTechniques; i++)
	{
		MaterialTechnique *tech = mtl->GetTechnique(i);
		int numPass = tech->GetNumPasses();
		for (int i = 0; i < numPass; i++)
		{
			MaterialPass *mtlPass = tech->GetPass(i);
			VertexShader *vs = mtlPass->GetVertexShader();
			PixelShader *ps = mtlPass->GetPixelShader();

			vs->SetShaderKey(shaderKey);
			ps->SetShaderKey(shaderKey);
		}
	}
}
//----------------------------------------------------------------------------
ShaderFloat *MaterialManager::CreateShaderFloat(const FString &name,
	int numRegister)
{
	ShaderFloat *shaderFloat = 0;

	if (FString("PVWMatrix") == name)
	{
		shaderFloat = new0 PVWMatrixConstant();
	}
	else if (FString("WMatrix") == name)
	{
		shaderFloat = new0 WMatrixConstant();
	}
	else if (FString("ProjectPVBSMatrix_Dir") == name)
	{
		shaderFloat = new0 ProjectorMatrixConstant(
			PX2_GR.GetLight_Dir_Projector(), true);
	}
	else if (FString("ShineEmissive") == name)
	{
		shaderFloat = new0 ShineEmissiveConstant();
	}
	else if (FString("ShineAmbient") == name)
	{
		shaderFloat = new0 ShineAmbientConstant();
	}
	else if (FString("ShineDiffuse") == name)
	{
		shaderFloat = new0 ShineDiffuseConstant();
	}
	else if (FString("ShineSpecular") == name)
	{
		shaderFloat = new0 ShineSpecularConstant();
	}
	else if (FString("CameraWorldPosition") == name)
	{
		shaderFloat = new0 CameraWorldPositionConstant();
	}
	else if (FString("CameraModelPosition") == name)
	{
		shaderFloat = new0 CameraModelPositionConstant();
	}
	else if (FString("LightWorldDVector_Dir") == name)
	{
		shaderFloat = new0 LightWorldDVectorConstant(PX2_GR.GetLight_Dir());
		((LightConstant*)shaderFloat)->SetDefaultDir(true);
	}
	else if (FString("LightAmbient_Dir") == name)
	{
		shaderFloat = new0 LightAmbientConstant(PX2_GR.GetLight_Dir());
		((LightConstant*)shaderFloat)->SetDefaultDir(true);
	}
	else if (FString("LightDiffuse_Dir") == name)
	{
		shaderFloat = new0 LightDiffuseConstant(PX2_GR.GetLight_Dir());
		((LightConstant*)shaderFloat)->SetDefaultDir(true);
	}
	else if (FString("LightSpecular_Dir") == name)
	{
		shaderFloat = new0 LightSpecularConstant(PX2_GR.GetLight_Dir());
		((LightConstant*)shaderFloat)->SetDefaultDir(true);
	}
	else if (FString("FogParam") == name)
	{
		shaderFloat = new0 FogParamConstant();
	}
	else if (FString("FogColorDist") == name)
	{
		shaderFloat = new0 FogColorDistConstant();
	}
	else if (FString("FogColorHeight") == name)
	{
		shaderFloat = new0 FogColorHeightConstant();
	}
	else
	{
		shaderFloat = new0 ShaderFloat(numRegister);
	}

	return shaderFloat;
}
//----------------------------------------------------------------------------