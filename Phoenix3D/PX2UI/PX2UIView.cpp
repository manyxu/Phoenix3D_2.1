// PX2UIView.cpp

#include "PX2UIView.hpp"
#include "PX2UISizeFrame.hpp"
#include "PX2UIPicBox.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
float UIView::msUICameraZ = -2000.0f;
//----------------------------------------------------------------------------
UIView::UIView() :
mIsCameraAutoAdjust(true)
{
	Camera *camera = new0 Camera(false);
	camera->SetFrame(APoint(0.0f, msUICameraZ, 0.0f), AVector::UNIT_Y,
		AVector::UNIT_Z, AVector::UNIT_X);
	SetCamera(camera);

	mCameraNode = new0 CameraNode();
	mCameraNode->SetCamera(camera);

#if defined(_WIN32) || defined(WIN32)
	mMoveAdjugeParam = 5.0f;
#else
	mMoveAdjugeParam = 64.0f;
#endif

	OnSizeChange();
}
//----------------------------------------------------------------------------
UIView::~UIView()
{
}
//----------------------------------------------------------------------------
void UIView::SetNode(Node *node)
{
	if (mNode)
	{
		mNode->DetachChild(mCameraNode);
	}

	mNode = node;

	if (mNode)
	{
		mNode->AttachChild(mCameraNode);
	}
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