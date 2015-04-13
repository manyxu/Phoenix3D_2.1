// PX2RenderStepScene.cpp

#include "PX2RenderStepScene.hpp"
#include "PX2Renderer.hpp"
#include "PX2Project.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2SimulationEventType.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, RenderStep, RenderStepScene);

//----------------------------------------------------------------------------
RenderStepScene::RenderStepScene() :
mIsShowShadowBloomEveryPass(false),
mIsBloomChanged(true),
mIsShadowMapChanged(true)
{
	mScreenCamera = new0 Camera(false);
	mScreenCamera->SetAxes(AVector::UNIT_Y, AVector::UNIT_Z, AVector::UNIT_X);

	mEffect_UIView = new0 UIView(-1);
	mEffect_UIView->SetDoDepthClear(true);
	mEffect_UIView->SetName("Effect_UI");

	mEffect_UIFrame = new0 UIFrame();
	mEffect_UIView->SetNode(mEffect_UIFrame);

	mBloomShadowPicSize = 256.0f;
}
//----------------------------------------------------------------------------
RenderStepScene::~RenderStepScene()
{
}
//----------------------------------------------------------------------------
void RenderStepScene::SetRenderer(Renderer *renderer)
{
	RenderStep::SetRenderer(renderer);

	mEffect_UIView->SetRenderer(renderer);
}
//----------------------------------------------------------------------------
void RenderStepScene::Update(double appSeconds, double elapsedSeconds)
{
	if (!mIsUpdated) mIsUpdated = true;
	if (!mNode) return;

	bool changed = mIsBloomChanged || mIsShadowMapChanged;
	if (mIsBloomChanged)
	{
		_UpdateBloomChanged();
	}
	if (mIsShadowMapChanged)
	{
		_UpdateShadowChanged();
	}

	if (changed)
	{
		mAlignPicBoxes.clear();

		if (mEffect_UIPicBoxShow_Normal) mAlignPicBoxes.push_back(mEffect_UIPicBoxShow_Normal);
		if (mEffect_UIPicBox_BloomBright) mAlignPicBoxes.push_back(mEffect_UIPicBox_BloomBright);
		if (mEffect_UIPicBox_BlurH) mAlignPicBoxes.push_back(mEffect_UIPicBox_BlurH);
		if (mEffect_UIPicBox_BlurV) mAlignPicBoxes.push_back(mEffect_UIPicBox_BlurV);
		if (mBloom_UIPicBox_Final) mAlignPicBoxes.push_back(mBloom_UIPicBox_Final);
		if (mEffect_UIPicBox_Shadow) mAlignPicBoxes.push_back(mEffect_UIPicBox_Shadow);

		_UpdateALightPicBoxTranslateSize();
	}

	EnvirParamPtr beformParam = PX2_GR.GetCurEnvirParam();
	CameraPtr beforeCamer = mRenderer->GetCamera();

	Scene *scene = (Scene*)((Node*)mNode);
	EnvirParam *sceneEnvirParam = scene->GetEnvirParam();
	PX2_GR.SetCurEnvirParam(sceneEnvirParam);
	mRenderer->SetCamera(mCamera);

	PX2_UNUSED(elapsedSeconds);
	if (mNode) mNode->Update(appSeconds, elapsedSeconds, false);

	PX2_GR.SetCurEnvirParam(beformParam);
	mRenderer->SetCamera(beforeCamer);

	mEffect_UIView->Update(appSeconds, elapsedSeconds);
	mEffect_UIView->ComputeVisibleSetAndEnv();

	if (mHelpGridRenderStep)
		mHelpGridRenderStep->Update(appSeconds, elapsedSeconds);
}
//----------------------------------------------------------------------------
void RenderStepScene::ComputeVisibleSetAndEnv()
{
	if (!IsEnable()) return;

	if (!mNode) return;

	Scene *scene = (Scene*)((Node*)mNode);

	const Camera *cam = mCuller.GetCamera();
	if (mNode && cam)
	{
		mCuller.ComputeVisibleSet(mNode);
		mCuller.GetVisibleSet().Sort();
	}
	else mCuller.GetVisibleSet().Clear();

	EnvirParam *envirParam = scene->GetEnvirParam();
	envirParam->ComputeEnvironment(mCuller.GetVisibleSet());
	
	Projector *lightProjector = envirParam->GetLight_Dir_Projector();
	mEffect_Culler_Shadow.SetCamera(lightProjector);
	mEffect_Culler_Shadow.SetFlag_CastShadow(1);
	mEffect_Culler_Shadow.ComputeVisibleSet(mNode);
	mEffect_Culler_Shadow.GetVisibleSet().Sort();

	if (mHelpGridRenderStep)
		mHelpGridRenderStep->ComputeVisibleSetAndEnv();
}
//----------------------------------------------------------------------------
void RenderStepScene::Draw()
{
	if (!IsEnable()) return;
	if (!mRenderer) return;
	if (!mNode) return;

	EnvirParamPtr beformParam = PX2_GR.GetCurEnvirParam();
	CameraPtr beforeCamer = mRenderer->GetCamera();

	Scene *scene = (Scene*)((Node*)mNode);
	EnvirParam *sceneEnvirParam = scene->GetEnvirParam();
	PX2_GR.SetCurEnvirParam(sceneEnvirParam);

	// shadow map depth
	if (mEffect_RenderTarget_Shadow)
	{
		mRenderer->Enable(mEffect_RenderTarget_Shadow);
		mRenderer->SetViewport(Rectf(0.0f, 0.0f, 
			(float)mEffect_RenderTarget_Shadow->GetWidth(), 
			(float)mEffect_RenderTarget_Shadow->GetHeight()));
		mRenderer->InitRenderStates();
		mRenderer->SetClearColor(Float4(1.0f, 1.0f, 1.0f, 1.0f));
		mRenderer->ClearColorBuffer();
		mRenderer->ClearDepthBuffer();

		Projector *lightProjector = scene->GetEnvirParam()->GetLight_Dir_Projector();
		mRenderer->SetCamera(lightProjector);
		mRenderer->Draw(mEffect_Culler_Shadow.GetVisibleSet(), mEffect_Material_Shadow);

		mRenderer->Disable(mEffect_RenderTarget_Shadow);

		sceneEnvirParam->SetLight_Dir_DepthTexture(mEffect_RenderTarget_Shadow->GetDepthStencilTexture());
		mEffect_UIPicBox_Shadow->SetTexture(mEffect_RenderTarget_Shadow->GetDepthStencilTexture());
	}

	Rectf viewPortSimu = mViewPort;
	if (viewPortSimu.IsEmpty()) viewPortSimu = Rectf(0.0f, 0.0f, mSize.Width, mSize.Height);

	// normal
	if (!scene->IsUseBloom())
	{
		mRenderer->SetCamera(mCamera);

		mRenderer->SetClearColor(MathHelp::Float3ToFloat4(scene->GetColor(), 0.0f));
		mRenderer->SetClearDepth(1.0f);
		mRenderer->ClearColorBuffer();
		mRenderer->ClearDepthBuffer();

		if (mHelpGridRenderStep)
			mHelpGridRenderStep->Draw();

		mRenderer->SetViewport(viewPortSimu);
		mRenderer->InitRenderStates();
		mRenderer->SetCamera(mCamera);
		mRenderer->Draw(mCuller.GetVisibleSet());
	}

	// bloom
	if (scene->IsUseBloom())
	{
		if (mEffect_RenderTarget_Normal)
		{
			mRenderer->Enable(mEffect_RenderTarget_Normal);
			mRenderer->SetViewport(Rectf(0.0f, 0.0f,
				(float)mEffect_RenderTarget_Normal->GetWidth(),
				(float)mEffect_RenderTarget_Normal->GetHeight()));

			mRenderer->InitRenderStates();
			mRenderer->SetClearColor(MathHelp::Float3ToFloat4(scene->GetColor(), 1.0f));
			mRenderer->SetClearDepth(1.0f);
			mRenderer->ClearBuffers();

			mRenderer->SetCamera(mCamera);

			if (mHelpGridRenderStep)
			{
				mRenderer->Draw(mHelpGridRenderStep->GetCuller().GetVisibleSet());
			}

			mRenderer->Draw(mCuller.GetVisibleSet());
			mRenderer->Disable(mEffect_RenderTarget_Normal);

			mEffect_UIPicBoxShow_Normal->SetTexture(mEffect_RenderTarget_Normal->GetColorTexture(0));
		}

		if (mEffect_RenderTarget_BloomBright)
		{
			mEffect_UIPicBox_BloomBright->SetTexture(mEffect_RenderTarget_Normal->GetColorTexture(0));

			mRenderer->Enable(mEffect_RenderTarget_BloomBright);
			mRenderer->SetViewport(Rectf(0.0f, 0.0f,
				(float)mEffect_RenderTarget_Normal->GetWidth(),
				(float)mEffect_RenderTarget_Normal->GetHeight()));

			mRenderer->InitRenderStates();
			mRenderer->ClearColorBuffer();
			mRenderer->ClearDepthBuffer();
			_SetCameraF(mScreenCamera, mEffect_UIPicBox_BloomBright);
			mRenderer->SetCamera(mScreenCamera);
			mRenderer->Draw(mEffect_UIPicBox_BloomBright);
			mRenderer->Disable(mEffect_RenderTarget_BloomBright);
		}

		// hor blur
		if (mEffect_RenderTarget_BlurH)
		{
			mEffect_UIPicBox_BlurH->SetTexture(mEffect_RenderTarget_BloomBright->GetColorTexture(0));

			mRenderer->Enable(mEffect_RenderTarget_BlurH);
			mRenderer->SetViewport(Rectf(0.0f, 0.0f,
				(float)mEffect_RenderTarget_Normal->GetWidth(),
				(float)mEffect_RenderTarget_Normal->GetHeight()));

			mRenderer->InitRenderStates();
			mRenderer->SetClearColor(Float4::BLACK);
			mRenderer->ClearColorBuffer();
			mRenderer->ClearDepthBuffer();
			_SetCameraF(mScreenCamera, mEffect_UIPicBox_BlurH);
			mRenderer->SetCamera(mScreenCamera);
			mRenderer->Draw(mEffect_UIPicBox_BlurH);
			mRenderer->Disable(mEffect_RenderTarget_BlurH);
		}

		// ver blur
		if (mEffect_RenderTarget_BlurV)
		{
			mEffect_UIPicBox_BlurV->SetTexture(mEffect_RenderTarget_BlurH->GetColorTexture(0));

			mRenderer->Enable(mEffect_RenderTarget_BlurV);
			mRenderer->SetViewport(Rectf(0.0f, 0.0f,
				(float)mEffect_RenderTarget_Normal->GetWidth(),
				(float)mEffect_RenderTarget_Normal->GetHeight()));

			mRenderer->InitRenderStates();
			mRenderer->SetClearColor(Float4::BLACK);
			mRenderer->ClearColorBuffer();
			mRenderer->ClearDepthBuffer();
			_SetCameraF(mScreenCamera, mEffect_UIPicBox_BlurV);
			mRenderer->SetCamera(mScreenCamera);
			mRenderer->Draw(mEffect_UIPicBox_BlurV);
			mRenderer->Disable(mEffect_RenderTarget_BlurV);
		}

		// bloom final
		if (mBloom_UIPicBox_Final)
		{
			mBoom_MtlInstance->SetPixelTexture(0, "SamplerBase", mEffect_RenderTarget_Normal->GetColorTexture(0));
			mBoom_MtlInstance->SetPixelTexture(0, "SamplerBloom", mEffect_RenderTarget_BlurV->GetColorTexture(0));
		}
	}

	mRenderer->SetCamera(beforeCamer);
	PX2_GR.SetCurEnvirParam(beformParam);

	mEffect_UIView->SetViewPort(viewPortSimu);
	mEffect_UIView->Draw();
}
//----------------------------------------------------------------------------
void RenderStepScene::SetSize(const Sizef &size)
{
	RenderStep::SetSize(size);

	Scene *scene = DynamicCast<Scene>(mNode);
	if (scene && scene->IsBloomRenderTargetSizeSameWithScreen())
		mIsBloomChanged = true;

	if (scene && scene->IsShadowRenderTargetSizeSameWithScreen())
		mIsShadowMapChanged = true;

	if (mEffect_UIView)
	{
		mEffect_UIView->SetSize(mSize);
	}

	_UpdateALightPicBoxTranslateSize();
}
//----------------------------------------------------------------------------
void RenderStepScene::SetScreenSize(const Sizef &size)
{
	RenderStep::SetScreenSize(size);

	Scene *scene = DynamicCast<Scene>(mNode);
	if (scene && scene->IsBloomRenderTargetSizeSameWithScreen())
		mIsBloomChanged = true;

	if (scene && scene->IsShadowRenderTargetSizeSameWithScreen())
		mIsShadowMapChanged = true;
}
//----------------------------------------------------------------------------
void RenderStepScene::SetNode(Node *node)
{
	RenderStep::SetNode(node);

	mIsBloomChanged = true;
	mIsShadowMapChanged = true;
}
//----------------------------------------------------------------------------
void RenderStepScene::DoExecute(Event *event)
{
	RenderStep::DoExecute(event);

	if (SimuES::IsEqual(event, SimuES::Scene_BloomChanged))
	{
		mIsBloomChanged = true;
	}
	else if (SimuES::IsEqual(event, SimuES::Scene_ShadowMapChange))
	{
		mIsShadowMapChanged = true;
	}
}
//----------------------------------------------------------------------------
float gaussianDistribution(float x, float y, float rho)
{
	float g = 1.0f / sqrtf(2.0f * Mathf::PI * rho * rho);
	g *= expf(-(x*x + y*y) / (2 * rho*rho));

	return g;
}
//----------------------------------------------------------------------------
void _SetSampleOffsetWeight(const Float2 &surfsize, Float4 *offsets, float fDeviation, 
	float multiplier, bool isHor)
{
	int i = 0;

	offsets[0][2] = multiplier * gaussianDistribution(0, 0, fDeviation); // weight
	offsets[0][0] = 0.0f; // offset
	offsets[0][1] = 0.0f;

	for (i = 1; i < 8; i++)
	{
		offsets[i][2] = multiplier * gaussianDistribution((float)i, 0, fDeviation);

		if (isHor)
		{
			float tu = 1.0f / (float)surfsize[0];

			offsets[i][0] = i * tu;
			offsets[i][1] = 0.0f;
		}
		else
		{
			float tu = 1.0f / (float)surfsize[1];

			offsets[i][0] = 0.0f;
			offsets[i][1] = i * tu;
		}
	}

	// Mirror to the second half
	for (i = 8; i < 15; i++)
	{
		offsets[i][2] = offsets[i - 7][2];

		offsets[i][0] = -offsets[i - 7][0];
		offsets[i][1] = -offsets[i - 7][1];
	}
}
//----------------------------------------------------------------------------
void RenderStepScene::SetShowShadowBloomEveryPass(bool isShowBloomEveryPass)
{
	mIsShowShadowBloomEveryPass = isShowBloomEveryPass;

	_UpdateALightPicBoxTranslateSize();
}
//----------------------------------------------------------------------------
bool RenderStepScene::IsShowShadowBloomEveryPass() const
{
	return mIsShowShadowBloomEveryPass;
}
//----------------------------------------------------------------------------
void RenderStepScene::_UpdateBloomChanged()
{
	mEffect_UIFrame->DetachChild(mEffect_UIPicBoxShow_Normal);
	mEffect_UIFrame->DetachChild(mEffect_UIPicBox_BloomBright);
	mEffect_UIFrame->DetachChild(mEffect_UIPicBox_BlurH);
	mEffect_UIFrame->DetachChild(mEffect_UIPicBox_BlurV);
	mEffect_UIFrame->DetachChild(mBloom_UIPicBox_Final);

	mEffect_RenderTarget_Normal = 0;
	mEffect_UIPicBoxShow_Normal = 0;

	mEffect_RenderTarget_BloomBright = 0;
	mEffect_UIPicBox_BloomBright = 0;
	mBoom_MtlInstance = 0;
	mBloom_BrightParam = 0;

	mEffect_RenderTarget_BlurH = 0;
	mEffect_UIPicBox_BlurH = 0;
	mEffect_RenderTarget_BlurV = 0;
	mEffect_UIPicBox_BlurV = 0;
	mBloom_UIPicBox_Final = 0;
	mBloom_BloomParam = 0;

	Scene *scene = DynamicCast<Scene>(mNode);
	std::string renderTag = Renderer::GetRenderTag();

	if (scene && scene->IsUseBloom())
	{
		Float2 rtSize = scene->GetBloomRenderTargetSize();
		if (scene->IsBloomRenderTargetSizeSameWithScreen())
			rtSize = Float2(mScreenSize.Width, mScreenSize.Height);

		Sizef size(mBloomShadowPicSize, mBloomShadowPicSize);
		Texture::Format tformat = Texture::TF_A8R8G8B8;
		mEffect_RenderTarget_Normal = new0 RenderTarget(1, tformat,
			(int)rtSize[0], (int)rtSize[1], false, false);
		mEffect_UIPicBoxShow_Normal = new0 UIPicBox();
		mEffect_UIFrame->AttachChild(mEffect_UIPicBoxShow_Normal);
		if ("OGLES" == renderTag) mEffect_UIPicBoxShow_Normal->SetPicBoxType(UIPicBox::PBT_NORAML_UVREVERSE);
		mEffect_UIPicBoxShow_Normal->SetAnchorPoint(Float2::ZERO);
		mEffect_UIPicBoxShow_Normal->SetSize(size);
		mEffect_UIPicBoxShow_Normal->Update(0.0f);
		mEffect_UIPicBoxShow_Normal->GetMaterialInstance()->GetMaterial()->GetAlphaProperty(0, 0)->BlendEnabled = false;

		MaterialInstancePtr blurMtlInstanceBloomBright = new0 MaterialInstance("Data/engine_mtls/bloom/bloom.px2obj", "bloom_bright", false);
		mEffect_RenderTarget_BloomBright = new0 RenderTarget(1, tformat,
			(int)rtSize[0], (int)rtSize[1], false, false);
		mEffect_UIPicBox_BloomBright = new0 UIPicBox();
		mEffect_UIFrame->AttachChild(mEffect_UIPicBox_BloomBright);
		if ("OGLES" == renderTag) mEffect_UIPicBox_BloomBright->SetPicBoxType(UIPicBox::PBT_NORAML_UVREVERSE);
		mEffect_UIPicBox_BloomBright->SetAnchorPoint(Float2::ZERO);
		mEffect_UIPicBox_BloomBright->SetSize(size);
		mEffect_UIPicBox_BloomBright->Update(0.0f);
		mEffect_UIPicBox_BloomBright->SetMaterialInstance(blurMtlInstanceBloomBright);
		mBloom_BrightParam = blurMtlInstanceBloomBright->GetPixelConstant(0, "BrightParam");

		MaterialInstancePtr blurMtlInstanceH = new0 MaterialInstance("Data/engine_mtls/blur/blur.px2obj", "blur", false);
		mEffect_RenderTarget_BlurH = new0 RenderTarget(1, tformat,
			(int)rtSize[0], (int)rtSize[1], false, false);
		mEffect_UIPicBox_BlurH = new0 UIPicBox();
		mEffect_UIFrame->AttachChild(mEffect_UIPicBox_BlurH);
		mEffect_UIPicBox_BlurH->SetMaterialInstance(blurMtlInstanceH);
		if ("OGLES" == renderTag) mEffect_UIPicBox_BlurH->SetPicBoxType(UIPicBox::PBT_NORAML_UVREVERSE);
		mEffect_UIPicBox_BlurH->SetAnchorPoint(Float2::ZERO);
		mEffect_UIPicBox_BlurH->SetSize(size);
		mEffect_UIPicBox_BlurH->SetUVRepeat(Float2::UNIT);
		mEffect_UIPicBox_BlurH->SetColor(Float3::WHITE);
		mEffect_UIPicBox_BlurH->SetAlpha(1.0f);
		mEffect_UIPicBox_BlurH->SetTexture("Data/engine/default.png");

		_SetSampleOffsetWeight(rtSize, mEffect_Blur_UVOffsets_H, scene->GetBloomBlurDeviation(), scene->GetBloomBlurWeight(), true);
		ShaderFloat *shaderFloatUVOffsets_H = mEffect_UIPicBox_BlurH->GetMaterialInstance()->GetPixelConstant(0, "UVOffsets");
		shaderFloatUVOffsets_H->SetRegisters((const float*)mEffect_Blur_UVOffsets_H);

		MaterialInstancePtr blurMtlInstanceV = new0 MaterialInstance("Data/engine_mtls/blur/blur.px2obj", "blur", false);
		mEffect_RenderTarget_BlurV = new0 RenderTarget(1, tformat,
			(int)rtSize[0], (int)rtSize[1], false, false);
		mEffect_UIPicBox_BlurV = new0 UIPicBox();
		mEffect_UIFrame->AttachChild(mEffect_UIPicBox_BlurV);
		mEffect_UIPicBox_BlurV->SetMaterialInstance(blurMtlInstanceV);
		if ("OGLES" == renderTag) mEffect_UIPicBox_BlurV->SetPicBoxType(UIPicBox::PBT_NORAML_UVREVERSE);
		mEffect_UIPicBox_BlurV->SetAnchorPoint(Float2::ZERO);
		mEffect_UIPicBox_BlurV->SetSize(size);
		mEffect_UIPicBox_BlurV->SetUVRepeat(Float2::UNIT);
		mEffect_UIPicBox_BlurV->SetColor(Float3::WHITE);
		mEffect_UIPicBox_BlurV->SetAlpha(1.0f);
		mEffect_UIPicBox_BlurV->SetTexture("Data/engine/default.png");

		_SetSampleOffsetWeight(rtSize, mEffect_Blur_UVOffsets_V, scene->GetBloomBlurDeviation(), scene->GetBloomBlurWeight(), false);
		ShaderFloat *shaderFloatUVOffsets_V = mEffect_UIPicBox_BlurV->GetMaterialInstance()->GetPixelConstant(0, "UVOffsets");
		shaderFloatUVOffsets_V->SetRegisters((const float*)mEffect_Blur_UVOffsets_V);

		mBoom_MtlInstance = new0 MaterialInstance("Data/engine_mtls/bloom/bloom.px2obj", "bloom", false);
		mBloom_UIPicBox_Final = new0 UIPicBox();
		mBloom_UIPicBox_Final->SetSize(size);
		mEffect_UIFrame->AttachChild(mBloom_UIPicBox_Final);
		if ("OGLES" == renderTag) mBloom_UIPicBox_Final->SetPicBoxType(UIPicBox::PBT_NORAML_UVREVERSE);
		mBloom_UIPicBox_Final->SetAnchorPoint(Float2::ZERO);
		mBloom_UIPicBox_Final->SetMaterialInstance(mBoom_MtlInstance);
		mBloom_BloomParam = mBoom_MtlInstance->GetPixelConstant(0, "BloomParam");

		_UpdateBloomParams();
	}

	mIsBloomChanged = false;
}
//----------------------------------------------------------------------------
void RenderStepScene::_UpdateBloomParams()
{
	Scene *scene = DynamicCast<Scene>(mNode);
	if (!scene) return;

	if (mBloom_BrightParam)
	{
		mBloom_BrightParam->SetRegister(0, scene->GetBloomBrightParam());
	}

	Float2 rtSize = scene->GetBloomRenderTargetSize();
	if (scene->IsBloomRenderTargetSizeSameWithScreen())
		rtSize = Float2(mScreenSize.Width, mScreenSize.Height);

	_SetSampleOffsetWeight(rtSize, mEffect_Blur_UVOffsets_H,
		scene->GetBloomBlurDeviation(), 
		scene->GetBloomBlurWeight(), true);

	_SetSampleOffsetWeight(rtSize, mEffect_Blur_UVOffsets_V,
		scene->GetBloomBlurDeviation(), 
		scene->GetBloomBlurWeight(), false);

	if (mEffect_UIPicBox_BlurH)
	{
		ShaderFloat *shaderFloatUVOffsets_H = mEffect_UIPicBox_BlurH->GetMaterialInstance()->GetPixelConstant(0, "UVOffsets");
		shaderFloatUVOffsets_H->SetRegisters((const float*)mEffect_Blur_UVOffsets_H);
	}

	if (mEffect_UIPicBox_BlurV)
	{
		ShaderFloat *shaderFloatUVOffsets_V = mEffect_UIPicBox_BlurV->GetMaterialInstance()->GetPixelConstant(0, "UVOffsets");
		shaderFloatUVOffsets_V->SetRegisters((const float*)mEffect_Blur_UVOffsets_V);
	}

	if (mBloom_BloomParam)
	{
		mBloom_BloomParam->SetRegister(0, scene->GetBloomParam());
	}
}
//----------------------------------------------------------------------------
void RenderStepScene::_UpdateALightPicBoxTranslateSize()
{
	if (mIsShowShadowBloomEveryPass)
	{
		int alignPicBoxSize = (int)mAlignPicBoxes.size();
		for (int i = 0; i < alignPicBoxSize; i++)
		{
			int x = (i + 2) % 2;
			int z = i / 2;

			float xPos = x * mBloomShadowPicSize;
			float zPos = mSize.Height - (z + 1) * mBloomShadowPicSize;
			mAlignPicBoxes[i]->LocalTransform.SetTranslateXZ(xPos, zPos);

			mAlignPicBoxes[i]->Show(true);
		}
	}
	else
	{
		int alignPicBoxSize = (int)mAlignPicBoxes.size();
		for (int i = 0; i < alignPicBoxSize; i++)
		{
			mAlignPicBoxes[i]->Show(false);
		}

		if (mBloom_UIPicBox_Final)
		{
			mBloom_UIPicBox_Final->Show(true);
			mBloom_UIPicBox_Final->SetSize(mSize);
		}
	}
}
//----------------------------------------------------------------------------
void RenderStepScene::_UpdateShadowChanged()
{
	Scene *scene = (Scene*)((Node*)mNode);
	if (!scene) return;

	std::string renderTag = Renderer::GetRenderTag();

	EnvirParam *sceneEnvirParam = scene->GetEnvirParam();
	sceneEnvirParam->SetLight_Dir_DepthTexture(0);

	mEffect_RenderTarget_Shadow = 0;
	mEffect_Material_Shadow = 0;
	mEffect_UIFrame->DetachChild(mEffect_UIPicBox_Shadow);
	mEffect_UIPicBox_Shadow = 0;

	if (scene && scene->IsUseShadowMap())
	{
		PX2_GR.SetCurEnvirParam(sceneEnvirParam);

		Float2 rtSize = scene->GetShadowRenderTargetSize();
		if (scene->IsShadowRenderTargetSizeSameWithScreen())
			rtSize = Float2(mScreenSize.Width, mScreenSize.Height);

		Texture::Format tformat = Texture::TF_A8R8G8B8;
		mEffect_RenderTarget_Shadow = new0 RenderTarget(1, tformat, (int)rtSize[0], 
			(int)rtSize[1], false, true);
		mEffect_Material_Shadow = new0 ShadowMap_Material();

		mEffect_UIPicBox_Shadow = new0 UIPicBox();
		mEffect_UIFrame->AttachChild(mEffect_UIPicBox_Shadow);
		if ("OGLES" == renderTag) mEffect_UIPicBox_Shadow->SetPicBoxType(UIPicBox::PBT_NORAML_UVREVERSE);
		mEffect_UIPicBox_Shadow->SetAnchorPoint(Float2::ZERO);
		mEffect_UIPicBox_Shadow->SetSize(Sizef(mBloomShadowPicSize, 
			mBloomShadowPicSize));
	}

	mIsShadowMapChanged = false;
}
//----------------------------------------------------------------------------
void RenderStepScene::_SetCameraF(Camera *camera, UIPicBox *uiPicBox)
{
	const APoint &worldPos = uiPicBox->WorldTransform.GetTranslate();
	const Float2 &anchor = uiPicBox->GetAnchorPoint();
	const Sizef &size = uiPicBox->GetSize();

	APoint cameraPos = worldPos;
	cameraPos.Y() -= 10.0f;

	float uMin = 0.0f;
	float uMax = 0.0f;
	float rMin = 0.0f;
	float rMax = 0.0f;

	rMin = anchor[0] * size.Width;
	rMax = (1.0f - anchor[0]) * size.Width;

	uMin = anchor[1] * size.Height;
	uMax = (1.0f - anchor[1]) * size.Height;
	
	camera->SetPosition(cameraPos);
	camera->SetFrustum(0.1f, 1000.0f, uMin, uMax, rMin, rMax);
}
//----------------------------------------------------------------------------
void RenderStepScene::SetHelpGridRenderStep(RenderStep *renderStep)
{
	mHelpGridRenderStep = renderStep;
}
//----------------------------------------------------------------------------
RenderStep *RenderStepScene::GetHelpGridRenderStep()
{
	return mHelpGridRenderStep;
}
//----------------------------------------------------------------------------