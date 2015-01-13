// PX2UIView.cpp

#include "PX2UIView.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
float UIView::msUICameraZ = -2000.0f;
//----------------------------------------------------------------------------
UIView::UIView() :
mRenderer(0)
{
	mSize.Set(1024.0f, 768.0f);

	mCamera = new0 Camera(false);
	mCuller.SetCamera(mCamera);
	mCamera->SetFrame(APoint(0.0f, msUICameraZ, 0.0f), AVector::UNIT_Y,
		AVector::UNIT_Z, AVector::UNIT_X);

	mUIFrame = new0 UIFrame();

#if defined(_WIN32) || defined(WIN32)
	mMoveAdjugeParam = 5.0f;
#else
	mMoveAdjugeParam = 64.0f;
#endif

}
//----------------------------------------------------------------------------
UIView::~UIView()
{
}
//----------------------------------------------------------------------------
void UIView::Clear()
{
	mUIFrame = 0;
}
//----------------------------------------------------------------------------
void UIView::SetSize(float width, float height)
{
	SetSize(Sizef(width, height));
}
//----------------------------------------------------------------------------
void UIView::SetSize(const Sizef &size)
{
	mSize = size;

	OnSizeChange();
}
//----------------------------------------------------------------------------
void UIView::OnSizeChange()
{
}
//----------------------------------------------------------------------------