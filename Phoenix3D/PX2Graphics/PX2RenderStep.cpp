// PX2UIView.cpp

#include "PX2RenderStep.hpp"
#include "PX2Renderer.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
RenderStep::RenderStep() :
mRenderer(0),
mIsUpdated(false),
mIsSizeChangeReAdjustCamera(true),
mIsEnable(true),
mPriority(0),
mIsDoClearDepth(false)
{
	mSize.Set(1024.0f, 768.0f);

	ComeInEventWorld();
}
//----------------------------------------------------------------------------
RenderStep::~RenderStep()
{
	GoOutEventWorld();
}
//----------------------------------------------------------------------------
void RenderStep::Update(double appSeconds, double elapsedSeconds)
{
	if (!IsEnable()) return;

	if (!mIsUpdated)
	{
		mIsUpdated = true;
	}

	PX2_UNUSED(elapsedSeconds);
	if (mNode)
	{
		mNode->Update(appSeconds, false);
	}
}
//----------------------------------------------------------------------------
void RenderStep::Enable(bool enable)
{
	mIsEnable = enable;
}
//----------------------------------------------------------------------------
void RenderStep::SetSize(const Sizef &rect)
{
	mSize = rect;

	OnSizeChange();
}
//----------------------------------------------------------------------------
void RenderStep::SetSizeChangeReAdjustCamera(bool doReAdjust)
{
	mIsSizeChangeReAdjustCamera = doReAdjust;
}
//----------------------------------------------------------------------------
void RenderStep::OnSizeChange()
{
	if (mIsSizeChangeReAdjustCamera && mCamera && mCamera->IsPerspective())
	{
		float fov = 0.0f;
		float asp = 1.0f;
		float dMin = 0.0f;
		float dMax = 0.0f;
		mCamera->GetFrustum(fov, asp, dMin, dMax);
		mCamera->SetFrustum(fov, mSize.Width / mSize.Height, dMin, dMax);
	}
}
//----------------------------------------------------------------------------
void RenderStep::SetViewPort(const Rectf &viewPort)
{
	mViewPort = viewPort;
}
//----------------------------------------------------------------------------
void RenderStep::SetCamera(Camera *camera)
{
	mCamera = camera;
	mCuller.SetCamera(mCamera);
}
//----------------------------------------------------------------------------
bool RenderStep::GetPickRay(int x, int y, APoint& origin, AVector& direction)
{
	if (!mCamera) return false;

	Rectf viewPort = mViewPort;
	if (viewPort.IsEmpty())
		viewPort = Rectf(0.0f, 0.0f, mSize.Width, mSize.Height);

	if (viewPort.IsEmpty()) return false;

	// Get the current viewport and test whether (x,y) is in it.
	float viewX = viewPort.Left;
	float viewY = viewPort.Bottom;
	float viewW = viewPort.Width();
	float viewH = viewPort.Height();

	// Get the [0,1]^2-normalized coordinates of (x,y).
	float r = ((float)(x - viewX)) / (float)viewW;
	float u = ((float)(y - viewY)) / (float)viewH;

	// Get the relative coordinates in [rmin,rmax]x[umin,umax].
	float rBlend = (1.0f - r)*mCamera->GetRMin() + r*mCamera->GetRMax();
	float uBlend = (1.0f - u)*mCamera->GetUMin() + u*mCamera->GetUMax();

	if (mCamera->IsPerspective())
	{
		origin = mCamera->GetPosition();
		direction = mCamera->GetDMin()*mCamera->GetDVector() +
			rBlend*mCamera->GetRVector() + uBlend*mCamera->GetUVector();
		direction.Normalize();
	}
	else
	{
		origin = mCamera->GetPosition() + rBlend*mCamera->GetRVector() +
			uBlend*mCamera->GetUVector();
		direction = mCamera->GetDVector();
		direction.Normalize();
	}

	return true;
}
//----------------------------------------------------------------------------
void RenderStep::SetNode(Node *node)
{
	mNode = node;
}
//----------------------------------------------------------------------------
void RenderStep::ComputeVisibleSet()
{
	if (!IsEnable()) return;

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
	if (!IsEnable()) return;

	if (mRenderer)
	{
		CameraPtr beforeCamer = mRenderer->GetCamera();

		mRenderer->InitRenderStates();

		Rectf viewPort = mViewPort;
		if (viewPort.IsEmpty()) viewPort = Rectf(0.0f, 0.0f, mSize.Width, mSize.Height);
		mRenderer->SetViewport(viewPort);

		if (mIsDoClearDepth) mRenderer->ClearDepthBuffer();

		mRenderer->SetCamera(mCamera);
		mRenderer->Draw(mCuller.GetVisibleSet());

		mRenderer->SetCamera(beforeCamer);
	}
}
//----------------------------------------------------------------------------
bool RenderStep::LessThan(const RenderStep *step0, const RenderStep *step1)
{
	int priority0 = step0->GetPriority();
	int priority1 = step1->GetPriority();

	if (priority0 == priority1)
		return step0 < step1;

	return priority0 > priority1;
}
//----------------------------------------------------------------------------
std::pair<float, float> RenderStep::CalPixelToWorld()
{
	Rectf viewPort = mViewPort;
	if (viewPort.IsEmpty())
		viewPort = Rectf(0.0f, 0.0f, mSize.Width, mSize.Height);

	std::pair<float, float> pixelToWorld;

	if (mCamera)
	{
		if (mCamera->IsPerspective())
		{
			float rMin = mCamera->GetRMin();
			float uMin = mCamera->GetUMin();
			float viewPortWidth = viewPort.Width();
			float viewPortHeight = viewPort.Height();

			float worldW = 2.0f * -rMin;
			float worldH = 2.0f * -uMin;

			worldW *= 10.0f;
			worldH *= 10.0f;

			pixelToWorld.first = worldW / (float)viewPortWidth;
			pixelToWorld.second = worldH / (float)viewPortHeight;
		}
		else
		{
			float rMin = mCamera->GetRMin();
			float uMin = mCamera->GetUMin();
			float viewPortWidth = viewPort.Width();
			float viewPortHeight = viewPort.Height();

			float worldW = 2.0f * -rMin;
			float worldH = 2.0f * -uMin;

			worldW *= 1.0f;
			worldH *= 1.0f;

			pixelToWorld.first = worldW / (float)viewPortWidth;
			pixelToWorld.second = worldH / (float)viewPortHeight;
		}

	}

	return pixelToWorld;
}
//----------------------------------------------------------------------------