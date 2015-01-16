// PX2MaterialManager.cpp

#include "PX2MaterialManager.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2PVMatrixConstant.hpp"
#include "PX2PVWMatrixConstant.hpp"
#include "PX2ShineEmissiveConstant.hpp"
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
Material *MaterialManager::GetMaterial(const FString &filename)
{
	Material *mtl = 0;
	std::map<FString, MaterialPtr>::iterator it = mMaterialMap.find(filename);
	if (it != mMaterialMap.end())
	{
		mtl = it->second;
	}
	else
	{
		mtl = DynamicCast<Material>(GraphicsRoot::msUserLoadFun(filename));
		mMaterialMap[filename] = mtl;

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

				vs->SetShaderKey(mNextShaderKey);
				ps->SetShaderKey(mNextShaderKey);

				mNextShaderKey++;
			}
		}
	}

	return mtl;
}
//----------------------------------------------------------------------------
ShaderFloat *MaterialManager::CreateShaderFloat(const FString &name)
{
	if (FString("PVWMatrix") == name)
	{
		return new0 PVWMatrixConstant();
	}
	else if (FString("ShineEmissive") == name)
	{
		return new0 ShineEmissiveConstant();
	}

	return 0;
}
//----------------------------------------------------------------------------