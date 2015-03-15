// PX2GraphicsRoot.cpp

#include "PX2GraphicsRoot.hpp"
#include "PX2Environment.hpp"
#include "PX2StringHelp.hpp"
#include "PX2FString.hpp"
#include "PX2Renderer.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2LightAmbientConstant.hpp"
#include "PX2LightDiffuseConstant.hpp"
#include "PX2LightSpecularConstant.hpp"
#include "PX2LightAttenuationConstant.hpp"
#include "PX2LightModelDVectorConstant.hpp"
#include "PX2LightWorldDVectorConstant.hpp"
#include "PX2SkinMaterial.hpp"
#include "PX2MaterialManager.hpp"
#include "PX2TriMesh.hpp"
#include "PX2VertexFormat.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2Time.hpp"
using namespace PX2;

const std::string GraphicsRoot::sEmptyResPath = "EmptyResPath";
const std::string GraphicsRoot::sTerResPath = "TerResPath";
//----------------------------------------------------------------------------
GraphicsRoot::GraphicsRoot ()
{
	mIsInEditor = false;
	mFogParam = Float4(-10.0f, 0.0f, 0.0f, 120.0f);
	mFogColorHeight = Float4::RED;
	mFogColorDist = Float4::BLUE;

	MaterialManager *mi = new0 MaterialManager();
	PX2_UNUSED(mi);
}
//----------------------------------------------------------------------------
GraphicsRoot::~GraphicsRoot ()
{
	MaterialManager *mi = MaterialManager::GetSingletonPtr();
	if (mi)
	{
		mi->Terminate();

		delete0(mi);
		MaterialManager::Set(0);
	}
}
//----------------------------------------------------------------------------
bool GraphicsRoot::Initlize ()
{
	InitTerm::ExecuteInitializers();

	// Camera
	Camera::DepthType dt = Camera::PM_DEPTH_ZERO_TO_ONE;
#if defined (PX2_USE_DX9)
	// DirectX使用深度在区间[0,1]内的矩阵。
	dt = Camera::PM_DEPTH_ZERO_TO_ONE;
#endif

#if defined(PX2_USE_OPENGL) || defined(PX2_USE_OPENGLES)
	// OpenGL使用深度在区间[-1,1]内的矩阵。
	dt = Camera::PM_DEPTH_MINUS_ONE_TO_ONE;
#endif
	Camera::SetDefaultDepthType(dt);

	mLight_Dir_Projector = new0 Projector(false);

	PX2_MATERIALMAN.Initlize();

	// create help meshs
	VertexFormat *vf = GetVertexFormat(GraphicsRoot::VFT_PC);
	StandardMesh stdMesh(vf);

	mTriMeshXY = stdMesh.Rectangle(4, 4, 20000.0f, 20000.0f);
	mTriMeshXY->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);
	mTriMeshXY->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	mTriMeshXY->GetMaterialInstance()->GetMaterial()->GetWireProperty(0, 0)->Enabled = true;
	mTriMeshXY->Update(GetTimeInSeconds(), false);

	mTriMeshXZ = stdMesh.Rectangle(4, 4, 20000.0f, 20000.0f);
	mTriMeshXZ->LocalTransform.SetRotate(Matrix3f().MakeEulerXYZ(Mathf::HALF_PI,
		0.0f, 0.0f));
	mTriMeshXZ->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);
	mTriMeshXZ->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	mTriMeshXZ->Update(GetTimeInSeconds(), false);

	mTriMeshYZ = stdMesh.Rectangle(4, 4, 20000.0f, 20000.0f);
	mTriMeshYZ->LocalTransform.SetRotate(Matrix3f().MakeEulerXYZ(0.0f,
		Mathf::HALF_PI, 0.0f));
	mTriMeshYZ->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);
	mTriMeshYZ->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	mTriMeshYZ->Update(GetTimeInSeconds(), false);

	mLight_Dir = new0 Light(Light::LT_DIRECTIONAL);
	mLight_Dir->Ambient = Float4(0.5f, 0.5f, 0.5f, 1.0f);
	mLight_Dir->Diffuse = Float4(0.5f, 0.5f, 0.5f, 1.0f);
	mLight_Dir->Specular = Float4(0.5f, 0.5f, 0.5f, 1.0f);
	mLight_Dir->SetDirection(AVector::UNIT_X);

	return true;
}
//-----------------------------------------------------------------------------
bool GraphicsRoot::Terminate ()
{
	mTriMeshXY = 0;
	mTriMeshXZ = 0;
	mTriMeshYZ = 0;

	PX2_MATERIALMAN.Terminate();

	mRenderStepMap.clear();
	mRenderStepVec.clear();

	mCamera = 0;
	mAllLights.clear();
	mLight_Dir = 0;
	mCreatedVFs.clear();

	Environment::RemoveAllDirectories();

	InitTerm::ExecuteTerminators();

	return true;
}
//----------------------------------------------------------------------------
void GraphicsRoot::AddLight (Light *light)
{
	if (!light) return;

	bool bIn = false;
	for (int i=0; i<(int)mAllLights.size(); i++)
	{
		if (light == mAllLights[i])
			bIn = true;
	}

	if (!bIn)
	{
		if (Light::LT_DIRECTIONAL == light->GetType())
		{
			mLight_Dir = light;
		}

		mAllLights.push_back(light);
	}
}
//----------------------------------------------------------------------------
void GraphicsRoot::RemoveLight (Light *light)
{
	std::vector<Pointer0<Light> >::iterator it = mAllLights.begin();
	for (; it!=mAllLights.end(); it++)
	{
		if (*it == light)
		{
			mAllLights.erase(it);
			return;
		}
	}
}
//----------------------------------------------------------------------------
void GraphicsRoot::ClearAllLights ()
{
	mAllLights.clear();
}
//----------------------------------------------------------------------------
int GraphicsRoot::GetNumLights ()
{
	return (int)mAllLights.size();
}
//----------------------------------------------------------------------------
Light *GraphicsRoot::GetLight (int index)
{
	int numLights = (int)mAllLights.size();
	if (index>=0 && index<numLights)
	{
		return mAllLights[index];
	}

	return 0;
}
//----------------------------------------------------------------------------
void GraphicsRoot::ComputeEnvironment (VisibleSet &vs)
{
	for (int i=0; i<vs.GetNumVisible(); i++)
	{
		PX2::Renderable *renderable = vs.GetVisible(i);
		PX2::APoint renPos = renderable->WorldTransform.GetTranslate();
		renderable->ClearLights();

		for (int j=0; j<GraphicsRoot::GetSingleton().GetNumLights(); j++)
		{
			PX2::Light *light = GraphicsRoot::GetSingleton().GetLight(j);
			PX2::APoint lightPos = light->Position;

			if (light->GetType() == Light::LT_DIRECTIONAL ||
				light->GetType() == Light::LT_AMBIENT)
			{
				renderable->AddLight(light);
			}
			else if (light->GetType() == Light::LT_POINT)
			{
				Vector3f diff = renPos - lightPos;
				float len = diff.Length();
				if (len <= 8)
					renderable->AddLight(light);
			}
		}
	}

	for (int i=0; i<vs.GetNumVisible(); i++)
	{
		PX2::Renderable *renderable = vs.GetVisible(i);

		PX2::Light *lightDir = 0;
		for (int j=0; j<renderable->GetNumLights(); j++)
		{
			PX2::Light *light = renderable->GetLight(j);
			if (light->GetType() == Light::LT_DIRECTIONAL)
			{
				lightDir = light;
				break;
			}
		}

		PX2::MaterialInstance *inst = renderable->GetMaterialInstance();
		if (!inst)
			continue;

		PX2::Material *mtl = inst->GetMaterial();

		PX2::SkinMaterial *skinMtl = DynamicCast<SkinMaterial>(mtl);

		LightModelDVectorConstant *modelDVectorConstant = 0;
		LightWorldDVectorConstant *lightWorldDVectorConstant = 0;
		LightAmbientConstant *ambConstant = 0;
		LightDiffuseConstant *difConstant = 0;
		LightSpecularConstant *specConstant = 0;

		if (skinMtl)
		{
			lightWorldDVectorConstant = DynamicCast<LightWorldDVectorConstant>(inst->GetVertexConstant(0, "LightWorldDirection"));

			if (lightWorldDVectorConstant)
				lightWorldDVectorConstant->SetLight(lightDir);

			ambConstant = DynamicCast<LightAmbientConstant>(inst->GetVertexConstant(0, "gLightAmbient"));
			difConstant = DynamicCast<LightDiffuseConstant>(inst->GetVertexConstant(0, "gLightDiffuse"));
			specConstant = DynamicCast<LightSpecularConstant>(inst->GetVertexConstant(0, "gLightSpecular"));

			if (modelDVectorConstant)
				modelDVectorConstant->SetLight(lightDir);

			if (ambConstant)
				ambConstant->SetLight(lightDir);

			if (difConstant)
				difConstant->SetLight(lightDir);

			if (specConstant)
				specConstant->SetLight(lightDir);
		}
	}
}
//----------------------------------------------------------------------------
bool GraphicsRoot::AddRenderStep(const char *name, RenderStep *step)
{
	if (IsHasRenderStep(name))
		return false;

	if ("Scene" == std::string(name)) mRenderStepScene = step;
	if ("UI" == std::string(name)) mRenderStepUI = step;

	mRenderStepMap[name] = step;
	mRenderStepVec.push_back(step);

	std::sort(mRenderStepVec.begin(), mRenderStepVec.end(), RenderStep::LessThan);

	return true;
}
//----------------------------------------------------------------------------
bool GraphicsRoot::IsHasRenderStep(const char *name) const
{
	return mRenderStepMap.find(name) != mRenderStepMap.end();
}
//----------------------------------------------------------------------------
bool GraphicsRoot::RemoveRenderStep(const char *name)
{
	std::map<FString, RenderStepPtr>::iterator it = mRenderStepMap.find(name);
	if (it != mRenderStepMap.end())
	{
		std::vector<RenderStep*>::iterator itVec = mRenderStepVec.begin();
		for (; itVec != mRenderStepVec.end();)
		{
			if (*itVec == it->second)
			{
				itVec = mRenderStepVec.erase(itVec);
			}
			else
			{
				itVec++;
			}
		}

		mRenderStepMap.erase(it);
		
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void GraphicsRoot::RemoveRenderSteps(RenderStep *step)
{
	std::vector<RenderStep*>::iterator itVec = mRenderStepVec.begin();
	for (; itVec != mRenderStepVec.end();)
	{
		if (*itVec == step)
		{
			itVec = mRenderStepVec.erase(itVec);
		}
		else
		{
			itVec++;
		}
	}

	std::map<FString, RenderStepPtr>::iterator it = mRenderStepMap.begin();
	for (; it != mRenderStepMap.end(); it++)
	{
		if (it->second == step)
		{
			mRenderStepMap.erase(it);
			return;
		}
	}
}
//----------------------------------------------------------------------------
RenderStep *GraphicsRoot::GetRenderStep(const char *name)
{
	std::map<FString, RenderStepPtr>::iterator it = mRenderStepMap.find(name);

	if (it != mRenderStepMap.end())
		return it->second;

	return 0;
}
//----------------------------------------------------------------------------
void GraphicsRoot::Update(double appSeconds, double elapsedSeconds)
{
	for (int i = 0; i < (int)mRenderStepVec.size(); i++)
	{
		mRenderStepVec[i]->Update(appSeconds, elapsedSeconds);
	}
}
//----------------------------------------------------------------------------
void GraphicsRoot::ComputeVisibleSet()
{
	for (int i = 0; i < (int)mRenderStepVec.size(); i++)
	{
		mRenderStepVec[i]->ComputeVisibleSet();
	}
}
//----------------------------------------------------------------------------
void GraphicsRoot::Draw()
{
	for (int i = 0; i < (int)mRenderStepVec.size(); i++)
	{
		mRenderStepVec[i]->Draw();
	}
}
//----------------------------------------------------------------------------
VertexFormat *GraphicsRoot::GetVertexFormat(VertexFormatType type)
{
	std::map<VertexFormatType, VertexFormatPtr >::iterator it =
		mCreatedVFs.find(type);

	if (it != mCreatedVFs.end())
	{
		return it->second;
	}
	else
	{
		VertexFormat *vf = 0;
		if (VFT_PT1 == type)
		{
			vf = VertexFormat::Create(2,
				VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
				VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 0);
		}
		else if (VFT_PT2 == type)
		{
			vf = VertexFormat::Create(3,
				VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
				VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 0,
				VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 1);
		}
		else if (VFT_PC == type)
		{
			vf = VertexFormat::Create(2,
				VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
				VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT4, 0);
		}
		else if (VFT_PCT1 == type)
		{
			vf = VertexFormat::Create(3,
				VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
				VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT4, 0,
				VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 0);
		}
		else if (VFT_PCT2 == type)
		{
			vf = VertexFormat::Create(4,
				VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
				VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT4, 0,
				VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 0,
				VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 1);
		}
		else if (VFT_PNT1 == type)
		{
			vf = VertexFormat::Create(3,
				VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
				VertexFormat::AU_NORMAL, VertexFormat::AT_FLOAT3, 0,
				VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 0);
		}

		mCreatedVFs[type] = vf;

		return vf;
	}

	return 0;
}
//----------------------------------------------------------------------------
ObjectLoadFun GraphicsRoot::msUserLoadFun = 0;
//----------------------------------------------------------------------------
void GraphicsRoot::SetUserLoadFun(ObjectLoadFun userLoadFun)
{
	msUserLoadFun = userLoadFun;
}
//----------------------------------------------------------------------------
BufferLoadFun GraphicsRoot::msBufferLoadFun = 0;
//----------------------------------------------------------------------------
void GraphicsRoot::SetBufferLoadFun(BufferLoadFun bufferLoadFun)
{
	msBufferLoadFun = bufferLoadFun;
}
//----------------------------------------------------------------------------
const std::string *GraphicsRoot::GetShaderStr(const char *filename)
{
	std::map<FString, std::string>::iterator it = mShadersMap.find(filename);
	if (it != mShadersMap.end())
	{
		return &(it->second);
	}
	else
	{
		int bufferSize = 0;
		char *buffer = 0;
		PX2_GR.msBufferLoadFun(filename, bufferSize, buffer);
		if (0 != bufferSize && buffer)
		{
			std::string str(buffer, bufferSize);
			mShadersMap[filename] = str;
			return &(mShadersMap[filename]);
		}
	}

	return 0;
}
//----------------------------------------------------------------------------