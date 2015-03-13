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
	mEffect_UIView = new0 UIView(-1);
	mEffect_UIView->SetDoDepthClear(true);
	mEffect_UIView->SetName("Effect_UI");
	mEffect_UIView->SetRenderer(Renderer::GetDefaultRenderer());

	mEffect_UIFrame = new0 UIFrame();
	mEffect_UIView->SetNode(mEffect_UIFrame);
	//mEffect_UIFrame->SetRelativeType_H(UIFrame::LT_HALF);
	//mEffect_UIFrame->SetRelativeType_V(UIFrame::LT_HALF);

	//SetUseBloom(false);
	SetUseShaderMap(true);
}
//----------------------------------------------------------------------------
RenderStepScene::~RenderStepScene()
{
}
//----------------------------------------------------------------------------
void RenderStepScene::Update(double appSeconds, double elapsedSeconds)
{
	if (!mIsUpdated) mIsUpdated = true;

	CameraPtr beforeCamer = mRenderer->GetCamera();
	mRenderer->SetCamera(mCamera);

	PX2_UNUSED(elapsedSeconds);
	if (mNode) mNode->Update(appSeconds, elapsedSeconds, false);

	mRenderer->SetCamera(beforeCamer);

	Project *proj = Project::GetSingletonPtr();
	if (proj)
	{
		const Sizef &projSize = proj->GetSize();
		if (mEffect_UIPicBox_Normal)
		{
			const Sizef &normalSize = mEffect_UIPicBox_Normal->GetSize();
			if (projSize != normalSize)
			{
				mEffect_UIPicBox_Normal->SetSize(projSize);
			}
		}

		if (mEffect_UIPicBox_Shadow)
		{
			const Sizef &normalSize = mEffect_UIPicBox_Shadow->GetSize();
			if (projSize != normalSize)
			{
				//mEffect_UIPicBox_Shadow->SetSize(projSize);
			}
		}
	}

	mEffect_UIView->Update(appSeconds, elapsedSeconds);
	mEffect_UIView->ComputeVisibleSet();
}
//----------------------------------------------------------------------------
void RenderStepScene::ComputeVisibleSet()
{
	RenderStep::ComputeVisibleSet();

	Scene *scene = PX2_PROJ.GetScene();
	if (!scene) return;

	Projector *lightCamera = PX2_GR.GetLight_Dir_Projector();
	mEffect_Culler_Shadow.SetCamera(lightCamera);
	mEffect_Culler_Shadow.ComputeVisibleSet(mNode);
	mEffect_Culler_Shadow.GetVisibleSet().Sort();
}
//----------------------------------------------------------------------------
void RenderStepScene::Draw()
{
	if (!IsEnable()) return;

	if (!mRenderer) return;

	Scene *scene = PX2_PROJ.GetScene();
	if (!scene) return;

	CameraPtr beforeCamer = mRenderer->GetCamera();

	Rectf viewPort = mViewPort;
	if (viewPort.IsEmpty()) viewPort = Rectf(0.0f, 0.0f, mSize.Width, mSize.Height);
	mRenderer->SetViewport(viewPort);

	// shadow map depth
	if (mEffect_RenderTarget_Shadow)
	{
		mRenderer->Enable(mEffect_RenderTarget_Shadow);
		mRenderer->InitRenderStates();
		mRenderer->ClearBuffers();

		Projector *lightProjector = PX2_GR.GetLight_Dir_Projector();
		mRenderer->SetCamera(lightProjector);
		mRenderer->Draw(mEffect_Culler_Shadow.GetVisibleSet(), mEffect_Material_Shadow);
		mRenderer->Disable(mEffect_RenderTarget_Shadow);
	}

	if (!mEffect_RenderTarget_Normal)
	{
		mRenderer->InitRenderStates();
		mRenderer->SetCamera(mCamera);
		mRenderer->Draw(mCuller.GetVisibleSet());
	}

	if (mEffect_RenderTarget_Normal)
	{
		mRenderer->Enable(mEffect_RenderTarget_Normal);
		mRenderer->InitRenderStates();
		mRenderer->ClearBuffers();
		mRenderer->Draw(mCuller.GetVisibleSet());
		mRenderer->Disable(mEffect_RenderTarget_Normal);
	}

	mRenderer->SetCamera(beforeCamer);

	if (mEffect_RenderTarget_Normal)
	{
		mEffect_UIView->SetViewPort(viewPort);
		mEffect_UIView->Draw();
	}

	if (mEffect_RenderTarget_Shadow)
	{
		mEffect_UIView->SetViewPort(viewPort);
		mEffect_UIView->Draw();
	}
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
void RenderStepScene::SetUseBloom(bool useBloom)
{
	if (useBloom == mIsUseBloom) return;

	mIsUseBloom = useBloom;

	Texture::Format tformat = Texture::TF_A8R8G8B8;
	mEffect_RenderTarget_Normal = new0 RenderTarget(1, tformat, 512, 512,
		false, false);

	mEffect_UIPicBox_Normal = new0 UIPicBox("Data/engine/default.png");
	mEffect_UIFrame->AttachChild(mEffect_UIPicBox_Normal);

	mEffect_UIPicBox_Normal->SetTexture(mEffect_RenderTarget_Normal
		->GetColorTexture(0));
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
	mEffect_RenderTarget_Shadow = new0 RenderTarget(1, tformat, 512, 512, false, true);
	mEffect_Material_Shadow = new0 ShadowMap_Material();

	mEffect_UIPicBox_Shadow = new0 UIPicBox("Data/engine/default.png");
	mEffect_UIFrame->AttachChild(mEffect_UIPicBox_Shadow);

	mEffect_UIPicBox_Shadow->SetAnchorPoint(Float2::ZERO);
	mEffect_UIPicBox_Shadow->SetSize(Sizef(256.0f, 256.0f));
	mEffect_UIPicBox_Shadow->SetTexture(mEffect_RenderTarget_Shadow->GetColorTexture(0));
	PX2_GR.SetLight_Dir_DepthTexture(mEffect_RenderTarget_Shadow->GetDepthStencilTexture());
}
//----------------------------------------------------------------------------