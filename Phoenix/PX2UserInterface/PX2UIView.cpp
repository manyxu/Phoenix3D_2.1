/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIView.cpp
*
*/

#include "PX2UIView.hpp"
#include "PX2Picker.hpp"
#include "PX2InputEvent.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2InputEventAdapter.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
UIView::UIView (int id)
	:
mID(id),
mIsEnable(true),
mRenderer(0),
mNonPickedCallback(0),
mIsPressed(false),
mIsPressedVailed(false),
mMoveAdjuge(1.0f),
mPressedX(0.0f),
mPressedY(0.0f)
{
	mSize.Width = 1024;
	mSize.Height = 768;
	mProjSize.Width = 1024;
	mProjSize.Height = 1024;

	mCamera = new0 Camera(false);
	mUIMainFrame = new0 UIFrame();
	mCuller.SetCamera(mCamera);
	//mCuller.GetVisibleSet().SetSortFun(UILessThan);

	OnSizeChange();

	mCamera->SetFrame(APoint(0.0f, -2000.0f, 0.0f), AVector::UNIT_Y, 
		AVector::UNIT_Z, AVector::UNIT_X);

#if defined(_WIN32) || defined(WIN32)
	mMoveAdjuge = 5.0f;
#else
	mMoveAdjuge = 64.0f;
#endif

	SetPriority(10);
}
//----------------------------------------------------------------------------
UIView::~UIView ()
{
}
//----------------------------------------------------------------------------
void UIView::Clear ()
{
	mUIMainFrame = 0;
	mSuperTopFrame = 0;
	mTopFrames.clear();
	mPickedPicBoxes.clear();
	mAcceptRect.Clear();
	mPressedButs.clear();
}
//----------------------------------------------------------------------------
void UIView::SetSize (float width, float height)
{
	mSize.Width = width;
	mSize.Height = height;

	OnSizeChange();
}
//----------------------------------------------------------------------------
void UIView::SetSize (const Sizef &size)
{
	mSize = size;

	OnSizeChange();
}
//----------------------------------------------------------------------------
void UIView::SetWidth (float width)
{
	mSize.Width = width;

	OnSizeChange();
}
//----------------------------------------------------------------------------
void UIView::SetHeight (float height)
{
	mSize.Height = height;

	OnSizeChange();
}
//----------------------------------------------------------------------------
void UIView::SetProjSize (float width, float height)
{
	mProjSize.Width = width;
	mProjSize.Height = height;
}
//----------------------------------------------------------------------------
void UIView::SetProjSize (const Sizef &size)
{
	mProjSize = size;
}
//----------------------------------------------------------------------------
void UIView::SetProjWidth (float width)
{
	mProjSize.Width = width;
}
//----------------------------------------------------------------------------
void UIView::SetProjHeight (float height)
{
	mProjSize.Height = height;
}
//----------------------------------------------------------------------------
void UIView::Enable (bool enable)
{
	mIsEnable = enable;
}
//----------------------------------------------------------------------------
void UIView::PushTopFrame (UIFrame *frame)
{
	mTopFrames.push_back(frame);
}
//----------------------------------------------------------------------------
void UIView::PopTopFrame ()
{
	if (!mTopFrames.empty())
		mTopFrames.pop_back();
}
//----------------------------------------------------------------------------
UIFrame *UIView::GetCurTopFrame () const
{
	if (mSuperTopFrame)
		return mSuperTopFrame;

	if (!mTopFrames.empty())
		return mTopFrames.back();

	return 0;
}
//----------------------------------------------------------------------------
void UIView::CallRendererSetViewport ()
{
	if (!mRenderer) return;

	const Rectf &rect = GraphicsRoot::GetSingleton().GetRect();

	if (!rect.IsEmpty() && 0==mID)
	{
		mRenderer->SetViewport((int)rect.Left, (int)rect.Bottom, 
			(int)rect.Width(), (int)rect.Height());
	}
}
//----------------------------------------------------------------------------
void UIView::Update (double appSeconds, double elapsedSeconds)
{
	PX2_UNUSED(elapsedSeconds);

	if (mUIMainFrame)
		mUIMainFrame->Update(appSeconds, false);
}
//----------------------------------------------------------------------------
void UIView::ComputeVisibleSet ()
{
	if (mUIMainFrame)
		mCuller.ComputeVisibleSet(mUIMainFrame);
	else
		mCuller.GetVisibleSet().Clear();
}
//----------------------------------------------------------------------------
void UIView::SetNonPickedCallback (NonPickedCallback callback)
{
	mNonPickedCallback = callback;
}
//----------------------------------------------------------------------------
void UIView::DoExecute (Event *event)
{
	if (mUIMainFrame)
		mUIMainFrame->OnEvent(event);
}
//----------------------------------------------------------------------------
bool UIView::TouchMoved (const InputEventData &data)
{
	if (!InputEventHandler::TouchMoved(data))
		return false;

	if (!mIsEnable)
		return false;

	int id = data.ViewID;

	if (id == mID)
	{
		float x = (float)data.TState.X.Absoulate;
		float y = (float)data.TState.Y.Absoulate;

		float moveDisX = x-mPressedX;
		float moveDisY = y-mPressedY;

		float distdist = moveDisX*moveDisX + moveDisY*moveDisY;

		if (distdist >= mMoveAdjuge*mMoveAdjuge)
		{
			mIsPressedVailed = false;
		}
	}
	
	return true;
}
//----------------------------------------------------------------------------
bool UIView::TouchPressed (const InputEventData &data)
{
	if (!InputEventHandler::TouchPressed(data))
		return false;

	if (!mIsEnable)
		return false;

	int id = data.ViewID;

	if (id == mID)
	{
		mIsPressed = true;
		mIsPressedVailed = true;

		float x = (float)data.TState.X.Absoulate;
		float y = (float)data.TState.Y.Absoulate;

		if (mSuperTopFrame)
		{
			DoPick(mPickedPicBoxes, x, y, 1);
		}
		else
		{
			if (mAcceptRect.IsEmpty())
			{
				DoPick(mPickedPicBoxes, x, y, 1);
			}
			else if (IsInRect(x, y))
			{
				DoPick(mPickedPicBoxes, x, y, 1);
			}
		}

		mPressedX = x;
		mPressedY = y;
	}

	return true;
}
//----------------------------------------------------------------------------
bool UIView::TouchReleased (const InputEventData &data)
{
	if (!InputEventHandler::TouchReleased(data))
		return false;

	if (!mIsEnable)
		return false;

	mIsPressed = false;

	if (!mIsPressedVailed)
	{
		std::list<UIButton *>::iterator it = mPressedButs.begin();
		for (; it!=mPressedButs.end(); it++)
		{
			(*it)->OnReleasedNotValied();
		}
		mPressedButs.clear();

		return false;
	}

	int id = data.ViewID;

	if (id == mID)
	{
		float x = (float)data.TState.X.Absoulate;
		float y = (float)data.TState.Y.Absoulate;

		if (mSuperTopFrame)
		{
			DoPick(mPickedPicBoxes, x, y, 2);
		}
		else
		{
			if (mAcceptRect.IsEmpty())
			{
				DoPick(mPickedPicBoxes, x, y, 2);
			}
			else if (IsInRect(x, y))
			{
				DoPick(mPickedPicBoxes, x, y, 2);
			}
		}
	}

	std::list<UIButton *>::iterator it = mPressedButs.begin();
	for (; it!=mPressedButs.end(); it++)
	{
		(*it)->OnReleasedNotValied();
	}
	mPressedButs.clear();

	return true;
}
//----------------------------------------------------------------------------
bool UIView::TouchCancelled (const InputEventData &data)
{
	if (!InputEventHandler::TouchCancelled(data))
		return false;

	if (!mIsEnable)
		return false;

	return true;
}
//----------------------------------------------------------------------------
void UIView::SetAcceptRect (const Rectf &rect)
{
	mAcceptRect = rect;
}
//----------------------------------------------------------------------------
void UIView::SetAcceptRect (float centerX, float centerY, float width,
	float height)
{
	float halfWidth = width/2.0f;
	float halfHeight = height/2.0f;

	mAcceptRect.Left = centerX - halfWidth;
	mAcceptRect.Right = centerX + halfWidth;
	mAcceptRect.Bottom = centerY - halfHeight;
	mAcceptRect.Top = centerY + halfHeight;
}
//----------------------------------------------------------------------------
void UIView::OnSizeChange ()
{
	float helfWidth = mSize.Width/2.0f;
	float helfHeight = mSize.Height/2.0f;

	mCamera->SetFrustum(0.1f, 2500.0f, -helfHeight, helfHeight, -helfWidth,
		helfWidth);
}
//----------------------------------------------------------------------------
void UIView::DoPick (std::vector<UIPicBoxPtr> &vec, float x, float y,
	int pickInfo)
{
	if (!mRenderer)
		return;

	CallRendererSetViewport();

	CameraPtr camBefore = mRenderer->GetCamera();
	mRenderer->SetCamera(mCamera);

	vec.clear();

	Picker pick(true, pickInfo);
	APoint origin;
	AVector direction;
	mRenderer->GetPickRay((int)x, (int)y, origin, direction);

	UIFrame *topFrame = GetCurTopFrame();
	if (topFrame)
	{
		pick.Execute(topFrame, origin, direction, 0.0f, Mathf::MAX_REAL);
	}
	else
	{
		pick.Execute(mUIMainFrame, origin, direction, 0.0f, Mathf::MAX_REAL);
	}

	for (int i=0; i<(int)pick.Records.size(); i++)
	{
		Movable *mov = pick.Records[i].Intersected;
		UIPicBox *picBox = DynamicCast<UIPicBox>(mov);
		if (picBox)
		{
			vec.push_back(picBox);
		}
	}

	for (int i=0; i<(int)vec.size(); i++)
	{
		vec[i]->UIAfterPicked(pickInfo);
	}

	if (vec.empty() && mNonPickedCallback)
	{
		mNonPickedCallback(pickInfo);
	}

	mRenderer->SetCamera(camBefore);
}
//----------------------------------------------------------------------------
bool UIView::IsInRect (float x, float z)
{
	const Rectf &rect = InputEventAdapter::GetSingleton().GetRect();

	float newLeft = rect.Left + mAcceptRect.Left/mProjSize.Width * rect.Width();
	float newRight = rect.Left + mAcceptRect.Right/mProjSize.Width * rect.Width();
	float newBot = rect.Bottom + mAcceptRect.Bottom/mProjSize.Height * rect.Height();
	float newTop = rect.Bottom + mAcceptRect.Top/mProjSize.Height * rect.Height();

	Rectf rectAccept(newLeft, newBot, newRight, newTop);

	if (rectAccept.IsInsize(x, z))
		return true;

	return false;
}
//----------------------------------------------------------------------------