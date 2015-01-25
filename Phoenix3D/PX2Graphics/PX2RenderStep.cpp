// PX2UIView.cpp

#include "PX2RenderStep.hpp"
#include "PX2Renderer.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
RenderStep::RenderStep() :
mRenderer(0),
mIsUpdated(false)
{
	mSize.Set(1024.0f, 768.0f);
}
//----------------------------------------------------------------------------
RenderStep::~RenderStep()
{
}
//----------------------------------------------------------------------------
void RenderStep::Clear()
{
	mNode = 0;
}
//----------------------------------------------------------------------------
void RenderStep::Update(double appSeconds, double elapsedSeconds)
{
	if (!mIsUpdated)
	{
		OnSizeChange();
		mIsUpdated = true;
	}

	PX2_UNUSED(elapsedSeconds);
	if (mNode) mNode->Update(appSeconds, false);
}
//----------------------------------------------------------------------------
void RenderStep::SetSize(float width, float height)
{
	SetSize(Sizef(width, height));
}
//----------------------------------------------------------------------------
void RenderStep::SetSize(const Sizef &size)
{
	mSize = size;

	OnSizeChange();
}
//----------------------------------------------------------------------------
void RenderStep::OnSizeChange()
{
	if (mRenderer)
	{
		mRenderer->ResizeWindow((int)mSize.Width, (int)mSize.Height);
	}
}
//----------------------------------------------------------------------------
void RenderStep::SetCamera(Camera *camera)
{
	mCamera = camera;
	mCuller.SetCamera(mCamera);
}
//----------------------------------------------------------------------------
void RenderStep::SetNode(Node *node)
{
	mNode = node;
}
//----------------------------------------------------------------------------
void RenderStep::ComputeVisibleSet()
{
	const Camera *cam = mCuller.GetCamera();
	if (mNode && cam)
	{
		mCuller.ComputeVisibleSet(mNode);
		mCuller.GetVisibleSet().Sort();
	}
	else mCuller.GetVisibleSet().Clear();
}
//----------------------------------------------------------------------------
void RenderStep::Draw()
{
	if (mRenderer)
	{
		CameraPtr beforeCamer = mRenderer->GetCamera();

		mRenderer->InitRenderStates();

		mRenderer->SetCamera(mCamera);
		mRenderer->Draw(mCuller.GetVisibleSet());

		mRenderer->SetCamera(beforeCamer);
	}
}
//----------------------------------------------------------------------------