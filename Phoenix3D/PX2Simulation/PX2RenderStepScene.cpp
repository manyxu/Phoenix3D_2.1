// PX2RenderStepScene.cpp

#include "PX2RenderStepScene.hpp"
#include "PX2Renderer.hpp"
#include "PX2Project.hpp"
#include "PX2EngineLoop.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, RenderStep, RenderStepScene);

//----------------------------------------------------------------------------
RenderStepScene::RenderStepScene() :
mIsUseBloom(false),
mIsUseShaderMap(false)
{
	mScreenCamera = new0 Camera(false);
	mScreenCamera->SetAxes(AVector::UNIT_Y, AVector::UNIT_Z, AVector::UNIT_X);

	mEffect_UIView = new0 UIView(-1);
	mEffect_UIView->SetDoDepthClear(true);
	mEffect_UIView->SetName("Effect_UI");

	mEffect_UIFrame = new0 UIFrame();
	mEffect_UIView->SetNode(mEffect_UIFrame);

	//SetUseBloom(true);
	//SetUseShaderMap(false);
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

	EnvirParamPtr beformParam = PX2_GR.GetCurEnvirParam();
	CameraPtr beforeCamer = mRenderer->GetCamera();

	Scene *scene = (Scene*)((Node*)mNode);
	EnvirParam *sceneEnvirParam = scene->GetEnvirParam();
	PX2_GR.SetCurEnvirParam(sceneEnvirParam);
	mRenderer->SetCamera(mCamera);

	if (mEffect_RenderTarget_Shadow)
		sceneEnvirParam->SetLight_Dir_DepthTexture(
		mEffect_RenderTarget_Shadow->GetDepthStencilTexture());

	PX2_UNUSED(elapsedSeconds);
	if (mNode) mNode->Update(appSeconds, elapsedSeconds, false);

	PX2_GR.SetCurEnvirParam(beformParam);
	mRenderer->SetCamera(beforeCamer);

	mEffect_UIView->Update(appSeconds, elapsedSeconds);
	mEffect_UIView->ComputeVisibleSetAndEnv();
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
	mEffect_Culler_Shadow.ComputeVisibleSet(mNode);
	mEffect_Culler_Shadow.GetVisibleSet().Sort();
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

	Rectf viewPort = mViewPort;
	if (viewPort.IsEmpty()) viewPort = Rectf(0.0f, 0.0f, mSize.Width, mSize.Height);
	mRenderer->SetViewport(viewPort);

	// shadow map depth
	//if (mEffect_RenderTarget_Shadow)
	//{
	//	mRenderer->Enable(mEffect_RenderTarget_Shadow);
	//	mRenderer->InitRenderStates();
	//	mRenderer->ClearBuffers();

	//	Projector *lightProjector = PX2_GR.GetLight_Dir_Projector();
	//	mRenderer->SetCamera(lightProjector);
	//	mRenderer->Draw(mEffect_Culler_Shadow.GetVisibleSet(), mEffect_Material_Shadow);
	//	mRenderer->Disable(mEffect_RenderTarget_Shadow);
	//}

	// normal
	{
		mRenderer->InitRenderStates();
		mRenderer->SetCamera(mCamera);
		mRenderer->Draw(mCuller.GetVisibleSet());
	}

	// bloom
	{
		if (mEffect_RenderTarget_Normal)
		{
			mRenderer->Enable(mEffect_RenderTarget_Normal);
			mRenderer->InitRenderStates();
			mRenderer->ClearBuffers();
			mRenderer->SetCamera(mCamera);
			mRenderer->Draw(mCuller.GetVisibleSet());
			mRenderer->Disable(mEffect_RenderTarget_Normal);

			mEffect_UIPicBox_Normal->SetTexture(mEffect_RenderTarget_Normal->GetColorTexture(0));
		}

		// hor blur
		if (mEffect_UIPicBox_BlurH)
		{
			mEffect_UIPicBox_BlurH->SetTexture(mEffect_RenderTarget_Normal->GetColorTexture(0));

			mRenderer->Enable(mEffect_RenderTarget_BlurH);
			mRenderer->InitRenderStates();
			mRenderer->SetClearColor(Float4::WHITE);
			mRenderer->ClearBuffers();
			_SetCameraF(mScreenCamera, mEffect_UIPicBox_BlurH);
			mRenderer->SetCamera(mScreenCamera);
			mRenderer->Draw(mEffect_UIPicBox_BlurH);
			mRenderer->Disable(mEffect_RenderTarget_BlurH);
		}

		// ver blur
		if (mEffect_UIPicBox_BlurV)
		{
			mEffect_UIPicBox_BlurV->SetTexture(mEffect_RenderTarget_BlurH->GetColorTexture(0));

			mRenderer->Enable(mEffect_RenderTarget_BlurV);
			mRenderer->InitRenderStates();
			mRenderer->SetClearColor(Float4::WHITE);
			mRenderer->ClearBuffers();
			_SetCameraF(mScreenCamera, mEffect_UIPicBox_BlurV);
			mRenderer->SetCamera(mScreenCamera);
			mRenderer->Draw(mEffect_UIPicBox_BlurV);
			mRenderer->Disable(mEffect_RenderTarget_BlurV);
		}
	}

	mRenderer->SetCamera(beforeCamer);
	PX2_GR.SetCurEnvirParam(beformParam);

	mEffect_UIView->SetViewPort(viewPort);
	mEffect_UIView->Draw();
}
//----------------------------------------------------------------------------
void RenderStepScene::OnSizeChange()
{
	RenderStep::OnSizeChange();

	if (mEffect_UIView)
	{
		mEffect_UIView->SetSize(mSize);
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
void _SetSampleOffsetWeight(int surfsize, Float4 *offsets, float fDeviation, 
	float multiplier, bool isHor)
{
	int i = 0;
	float tu = 1.0f / (float)surfsize;

	offsets[0][2] = multiplier * gaussianDistribution(0, 0, fDeviation); // weight
	offsets[0][0] = 0.0f; // offset
	offsets[0][1] = 0.0f;

	for (i = 1; i < 8; i++)
	{
		offsets[i][2] = multiplier * gaussianDistribution((float)i, 0, fDeviation);

		if (isHor)
		{
			offsets[i][0] = i * tu;
			offsets[i][1] = 0.0f;
		}
		else
		{
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
void RenderStepScene::SetUseBloom(bool useBloom)
{
	if (useBloom == mIsUseBloom) return;

	mIsUseBloom = useBloom;

	mBloomPicSize = 256.0f;
	mBloomTexSize = 1024.0f;
	mBloomBlurWeight = 3.0f;
	mBloomBlurValue = 1.0f;

	Texture::Format tformat = Texture::TF_A8R8G8B8;
	Sizef size(mBloomPicSize, mBloomPicSize);

	mEffect_RenderTarget_Normal = new0 RenderTarget(1, tformat, (int)mBloomTexSize, (int)mBloomTexSize, false, false);
	mEffect_UIPicBox_Normal = new0 UIPicBox();
	mEffect_UIFrame->AttachChild(mEffect_UIPicBox_Normal);
	mEffect_UIPicBox_Normal->SetAnchorPoint(Float2::ZERO);
	mEffect_UIPicBox_Normal->SetSize(size);
	mEffect_UIPicBox_Normal->Update(0.0f);
	mEffect_UIPicBox_Normal->GetMaterialInstance()->GetMaterial()->GetAlphaProperty(0, 0)->BlendEnabled = false;

	MaterialInstancePtr blurMtlInstanceH = new0 MaterialInstance("Data/engine_mtls/blur/blur.px2obj", "blur", false);
	mEffect_RenderTarget_BlurH = new0 RenderTarget(1, tformat, (int)mBloomTexSize, (int)mBloomTexSize, false, false);
	mEffect_UIPicBox_BlurH = new0 UIPicBox();
	mEffect_UIFrame->AttachChild(mEffect_UIPicBox_BlurH);
	mEffect_UIPicBox_BlurH->SetMaterialInstance(blurMtlInstanceH);
	mEffect_UIPicBox_BlurH->SetAnchorPoint(Float2::ZERO);
	mEffect_UIPicBox_BlurH->LocalTransform.SetTranslate(APoint(256.0f, -1.0f, 0.0f));
	mEffect_UIPicBox_BlurH->LocalTransform.SetTranslateY(-1.0f);
	mEffect_UIPicBox_BlurH->SetSize(size);
	mEffect_UIPicBox_BlurH->SetUVRepeat(Float2::UNIT);
	mEffect_UIPicBox_BlurH->SetColor(Float3::WHITE);
	mEffect_UIPicBox_BlurH->SetAlpha(1.0f);
	mEffect_UIPicBox_BlurH->SetTexture("Data/engine/default.png");

	_SetSampleOffsetWeight((int)mBloomTexSize, mEffect_Blur_UVOffsets_H, mBloomBlurWeight, mBloomBlurValue, true);
	ShaderFloat *shaderFloatUVOffsets_H = mEffect_UIPicBox_BlurH->GetMaterialInstance()->GetPixelConstant(0, "UVOffsets");
	shaderFloatUVOffsets_H->SetRegisters((const float*)mEffect_Blur_UVOffsets_H);

	MaterialInstancePtr blurMtlInstanceV = new0 MaterialInstance("Data/engine_mtls/blur/blur.px2obj", "blur", false);
	mEffect_RenderTarget_BlurV = new0 RenderTarget(1, tformat, (int)mBloomTexSize, (int)mBloomTexSize, false, false);
	mEffect_UIPicBox_BlurV = new0 UIPicBox();
	mEffect_UIFrame->AttachChild(mEffect_UIPicBox_BlurV);
	mEffect_UIPicBox_BlurV->SetMaterialInstance(blurMtlInstanceV);
	mEffect_UIPicBox_BlurV->SetAnchorPoint(Float2::ZERO);
	mEffect_UIPicBox_BlurV->LocalTransform.SetTranslate(APoint(256.0f, -2.0f, 256.0f));
	mEffect_UIPicBox_BlurV->LocalTransform.SetTranslateY(-2.0f);
	mEffect_UIPicBox_BlurV->SetSize(size);
	mEffect_UIPicBox_BlurV->SetUVRepeat(Float2::UNIT);
	mEffect_UIPicBox_BlurV->SetColor(Float3::WHITE);
	mEffect_UIPicBox_BlurV->SetAlpha(1.0f);
	mEffect_UIPicBox_BlurV->SetTexture("Data/engine/default.png");

	_SetSampleOffsetWeight((int)mBloomTexSize, mEffect_Blur_UVOffsets_V, mBloomBlurWeight, mBloomBlurValue, false);
	ShaderFloat *shaderFloatUVOffsets_V = mEffect_UIPicBox_BlurV->GetMaterialInstance()->GetPixelConstant(0, "UVOffsets");
	shaderFloatUVOffsets_V->SetRegisters((const float*)mEffect_Blur_UVOffsets_V);
}
//----------------------------------------------------------------------------
bool RenderStepScene::IsUseBloom() const
{
	return mIsUseBloom;
}
//----------------------------------------------------------------------------
void RenderStepScene::SetUseShaderMap(bool useShaderMap)
{
	if (useShaderMap == mIsUseShaderMap) return;

	mIsUseShaderMap = useShaderMap;

	Texture::Format tformat = Texture::TF_A8R8G8B8;
	mEffect_RenderTarget_Shadow = new0 RenderTarget(1, tformat, 1024, 1024, false, true);
	mEffect_Material_Shadow = new0 ShadowMap_Material();

	mEffect_UIPicBox_Shadow = new0 UIPicBox();
	mEffect_UIFrame->AttachChild(mEffect_UIPicBox_Shadow);

	mEffect_UIPicBox_Shadow->SetAnchorPoint(Float2::ZERO);
	mEffect_UIPicBox_Shadow->SetSize(Sizef(256.0f, 256.0f));
	mEffect_UIPicBox_Shadow->SetTexture(mEffect_RenderTarget_Shadow->GetColorTexture(0));
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
	camera->SetFrustum(0.1f, 100.0f, uMin, uMax, rMin, rMax);
}
//----------------------------------------------------------------------------