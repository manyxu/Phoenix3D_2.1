// PX2UIButton.cpp

#include "PX2UIButton.hpp"
#include "PX2UIRenderManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
UIButton::UIButton()
{

}
//----------------------------------------------------------------------------
UIButton::~UIButton()
{

}
//----------------------------------------------------------------------------
void UIButton::DoPaint(HDC hDC, const Rectf &rect)
{
	UINT uState = 0;
	if (IsFocused())
		uState |= UISTATE_FOCUSED;
	if (!IsEnabled())
		uState |= UISTATE_DISABLED;

	Rectf rcPadding;

	UIRenderManager::GetSingleton().DoPaintButton(0, mPaintMan, rect, mText,
		rcPadding, mButtonState | uState, mTextStyle);
}
//----------------------------------------------------------------------------