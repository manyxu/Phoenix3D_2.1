// PX2UIView.cpp

#include "PX2RenderStep.hpp"
#include "PX2Renderer.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
RenderStep::RenderStep() :
mRenderer(0),
mIsUpdated(false)
{
	mRect.Set(0.0f, 0.0f, 1024.0f, 768.0f);
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
		mIsUpdated = true;
	}

	PX2_UNUSED(elapsedSeconds);
	if (mNode) mNode->Update(appSeconds, false);
}
//----------------------------------------------------------------------------
void RenderStep::SetRect(const Rectf &rect)
{
	mRect = rect;

	OnRectChange();
}
//----------------------------------------------------------------------------
Sizef RenderStep::GetSize() const
{
	return Sizef(mRect.Width(), mRect.Height());
}
//----------------------------------------------------------------------------
void RenderStep::OnRectChange()
{
	if (mRenderer)
	{
		mRenderer->SetViewport(mRect);
		mRenderer->ResizeWindow((int)mRect.Width(), (int)mRect.Height());
	}

	if (mCamera)
	{
		float fov = 0.0f;
		float asp = 1.0f;
		float dMin = 0.0f;
		float dMax = 0.0f;
		mCamera->GetFrustum(fov, asp, dMin, dMax);
		mCamera->SetFrustum(fov, mRect.Width() / mRect.Height(), dMin, dMax);
	}
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

	if (mRect.IsEmpty()) return false;

	// Get the current viewport and test whether (x,y) is in it.
	float viewX = mRect.Left;
	float viewY = mRect.Bottom;
	float viewW = mRect.Width();
	float viewH = mRect.Height();

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
std::pair<float, float> RenderStep::CalPixelToWorld()
{
	std::pair<float, float> pixelToWorld;

	if (mCamera)
	{
		if (mCamera->IsPerspective())
		{
			float rMin = mCamera->GetRMin();
			float uMin = mCamera->GetUMin();
			float viewPortWidth = mRect.Width();
			float viewPortHeight = mRect.Height();

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
			float viewPortWidth = mRect.Width();
			float viewPortHeight = mRect.Height();

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