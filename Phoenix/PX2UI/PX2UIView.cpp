// PX2UIView.cpp

#include "PX2UIView.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIPicBox.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
float UIView::msUICameraZ = -2000.0f;
//----------------------------------------------------------------------------
UIView::UIView() :
mIsCameraAutoCenter(true)
{
	mSize.Set(1024.0f, 768.0f);

	Camera *camera = new0 Camera(false);
	camera->SetFrame(APoint(0.0f, msUICameraZ, 0.0f), AVector::UNIT_Y,
		AVector::UNIT_Z, AVector::UNIT_X);
	SetCamera(camera);

	UIFrame *mainFrame = new0 UIFrame();
	SetNode(mainFrame);
	mainFrame->SetName("UIMainFrame");

#if defined(_WIN32) || defined(WIN32)
	mMoveAdjugeParam = 5.0f;
#else
	mMoveAdjugeParam = 64.0f;
#endif

	OnSizeChange();

	UIPicBox *picBox = new0 UIPicBox();
	mainFrame->AttachChild(picBox);
	picBox->LocalTransform.SetTranslate(APoint(200.0f, 0.0f, 200.0f));
}
//----------------------------------------------------------------------------
UIView::~UIView()
{
}
//----------------------------------------------------------------------------
void UIView::SetCameraAutoCenter(bool autoCenter)
{
	mIsCameraAutoCenter = autoCenter;
}
//----------------------------------------------------------------------------
void UIView::OnSizeChange()
{
	float helfWidth = mSize.Width / 2.0f;
	float helfHeight = mSize.Height / 2.0f;

	mCamera->SetFrustum(0.1f, Mathf::FAbs(msUICameraZ)+100.0f,
		-helfHeight, helfHeight, -helfWidth, helfWidth);

	if (mIsCameraAutoCenter)
	{
		mCamera->SetPosition(APoint(helfWidth, msUICameraZ, helfHeight));
	}
}
//----------------------------------------------------------------------------