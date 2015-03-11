// PX2UIView.cpp

#include "PX2UIView.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2InputEvent.hpp"
#include "PX2InputEventData.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, RenderStep, UIView);

//----------------------------------------------------------------------------
float UIView::msUICameraZ = -2000.0f;
//----------------------------------------------------------------------------
UIView::UIView(int viewID) :
mIsCameraAutoAdjust(true),
mViewID(viewID),
mNotPickedCallback(0),
mMoveAdjugeParam(1.0f),
mMoveAdjugeParamSquare(1.0f),
mIsPressedVailed(true) // 当按在按钮上滑动一段距离，点击设置为无效
{
	Camera *camera = new0 Camera(false);
	camera->SetFrame(APoint(0.0f, msUICameraZ, 0.0f), AVector::UNIT_Y,
		AVector::UNIT_Z, AVector::UNIT_X);
	SetCamera(camera);

	mCameraNode = new0 CameraNode();
	mCameraNode->SetName("DefaultCameraNode");
	mCameraNode->SetCamera(camera);

#if defined(_WIN32) || defined(WIN32)
	mMoveAdjugeParam = 5.0f;
#else
	mMoveAdjugeParam = 64.0f;
#endif

	mMoveAdjugeParamSquare = mMoveAdjugeParam * mMoveAdjugeParam;

	OnSizeChange();
}
//----------------------------------------------------------------------------
UIView::~UIView()
{
}
//----------------------------------------------------------------------------
void UIView::Update(double appSeconds, double elapsedSeconds)
{
	if (mCameraNode)
	{
		mCameraNode->Update(appSeconds, elapsedSeconds, false);
	}

	RenderStep::Update(appSeconds, elapsedSeconds);
}
//----------------------------------------------------------------------------
void UIView::SetNode(Node *node)
{
	mNode = node;
}
//----------------------------------------------------------------------------
void UIView::SetSuperTopMoveable(Movable *movable)
{
	mSuperTopMovable = movable;
}
//----------------------------------------------------------------------------
void UIView::PushTopMovable(Movable *movable)
{
	mTopMovables.push_back(movable);
}
//----------------------------------------------------------------------------
void UIView::PopTopMovable()
{
	if (!mTopMovables.empty())
		mTopMovables.pop_back();
}
//----------------------------------------------------------------------------
Movable *UIView::GetTopestMovable()
{
	if (mSuperTopMovable)
		return mSuperTopMovable;

	if (!mTopMovables.empty())
		return mTopMovables.back();

	return 0;
}
//----------------------------------------------------------------------------
void UIView::SetCameraAutoAdjust(bool autoAdjust)
{
	mIsCameraAutoAdjust = autoAdjust;
}
//----------------------------------------------------------------------------
void UIView::SetCameraFrustumSize(const Sizef &size)
{
	mCameraFrustumSize = size;

	float helfWidth = mCameraFrustumSize.Width / 2.0f;
	float helfHeight = mCameraFrustumSize.Height / 2.0f;

	mCamera->SetFrustum(0.1f, Mathf::FAbs(msUICameraZ) + 100.0f,
		-helfHeight, helfHeight, -helfWidth, helfWidth);
}
//----------------------------------------------------------------------------
void UIView::OnSizeChange()
{
	if (mIsCameraAutoAdjust)
	{
		mCameraFrustumSize = mSize;

		SetCameraFrustumSize(mCameraFrustumSize);

		float helfWidth = mCameraFrustumSize.Width / 2.0f;
		float helfHeight = mCameraFrustumSize.Height / 2.0f;
		mCameraNode->LocalTransform.SetTranslate(APoint(helfWidth, msUICameraZ,
			helfHeight));
	}
}
//----------------------------------------------------------------------------
void UIView::DoExecute(Event *event)
{
	if (!IsEnable()) return;

	RenderStep::DoExecute(event);

	if (InputEventSpace::IsEqual(event, InputEventSpace::MouseMoved) ||
		InputEventSpace::IsEqual(event, InputEventSpace::TouchMoved))
	{
		InputEventData data = event->GetData<InputEventData>();
		if (mViewID != data.ViewID) return;

		if (mIsPressedVailed)
		{
			const APoint &pos = data.MTPos;

			AVector delta = pos - mPressedPos;
			if (delta.SquaredLength() >= mMoveAdjugeParamSquare)
				mIsPressedVailed = false;
		}
	}
	else if (InputEventSpace::IsEqual(event, InputEventSpace::MousePressed))
	{
		InputEventData data = event->GetData<InputEventData>();
		if (mViewID != data.ViewID) return;

		mIsPressed = true;
		mIsPressedVailed = true;

		_DoPick(data.MTPos.X(), data.MTPos.Z(), 1, mPickedRenderables);

		mPressedPos = data.MTPos;
	}
	else if (InputEventSpace::IsEqual(event, InputEventSpace::TouchPressed))
	{
		InputEventData data = event->GetData<InputEventData>();
		if (mViewID != data.ViewID) return;

		mIsPressed = true;

		_DoPick(data.MTPos.X(), data.MTPos.Z(), 1, mPickedRenderables);

		mPressedPos = data.MTPos;
	}
	else if (InputEventSpace::IsEqual(event, InputEventSpace::MouseReleased))
	{
		mIsPressed = false;

		InputEventData data = event->GetData<InputEventData>();
		if (mViewID != data.ViewID) return;

		if (!mIsPressedVailed)
		{
			std::list<UIButtonPtr >::iterator it = mPressedButs.begin();
			for (; it != mPressedButs.end(); it++)
			{
				(*it)->OnReleasedNotValied();
			}
			mPressedButs.clear();

			return;
		}

		_DoPick(data.MTPos.X(), data.MTPos.Z(), 2, mPickedRenderables);

		std::list<UIButtonPtr >::iterator it = mPressedButs.begin();
		for (; it != mPressedButs.end(); it++)
		{
			(*it)->OnReleasedNotValied();
		}
		mPressedButs.clear();
	}
	else if (InputEventSpace::IsEqual(event, InputEventSpace::TouchReleased))
	{
		InputEventData data = event->GetData<InputEventData>();
		if (mViewID != data.ViewID) return;

		if (!mIsPressedVailed) return;

	}
}
//----------------------------------------------------------------------------
void UIView::SetNotPickedCallback(NotPickedCallback callback)
{
	mNotPickedCallback = callback;
}
//----------------------------------------------------------------------------
void UIView::_DoPick(float x, float z, int pickInfo, 
	std::vector<RenderablePtr> &vec)
{
	vec.clear();

	Movable *pickMov = 0;
	Movable *topestMovable = GetTopestMovable();
	if (topestMovable) pickMov = topestMovable;
	else pickMov = mNode;
	if (!pickMov) return;

	APoint origin;
	AVector direction;
	GetPickRay(x, z, origin, direction);

	Picker pick(true, pickInfo);
	pick.Execute(pickMov, origin, direction, 0.0f, Mathf::MAX_REAL);

	for (int i = 0; i < (int)pick.Records.size(); i++)
	{
		Movable *mov = pick.Records[i].Intersected;
	
		Renderable *renderable = DynamicCast<Renderable>(mov);
		if (renderable) vec.push_back(renderable);
	}

	for (int i = 0; i < (int)vec.size(); i++)
	{
		UIPicBox *picBox = DynamicCast<UIPicBox>(vec[i]);
		if (picBox) picBox->UIAfterPicked(pickInfo);
	}

	if (vec.empty() && mNotPickedCallback)
	{
		mNotPickedCallback(pickInfo);
	}
}
//----------------------------------------------------------------------------
