// PX2UIRenderManager_Win.cpp

#include "PX2UIRenderManager_Win.hpp"
#include "PX2UIPaintManager_Win.hpp"
#include "PX2UIRender.hpp"
using namespace PX2;

COLORREF TheColors[UICOLOR__LAST][2] = { 0 };

//----------------------------------------------------------------------------
UIRenderManager_Win::UIRenderManager_Win()
{
}
//----------------------------------------------------------------------------
UIRenderManager_Win::~UIRenderManager_Win()
{
}
//----------------------------------------------------------------------------
void UIRenderManager_Win::DoFillRect(UIRenderer *uiRenderer,
	UIPaintManager *paintMan, const Rectf &rc, UITYPE_COLOR color)
{
	UIPaintManager_Win *paintMan_Win = (UIPaintManager_Win*)paintMan;

	ASSERT(::GetObjectType(hDC) == OBJ_DC || ::GetObjectType(hDC) == OBJ_MEMDC);

	::SetBkColor(uiRenderer->TheDC, paintMan_Win->GetColor(color));
	::ExtTextOut(uiRenderer->TheDC, 0, 0, ETO_OPAQUE, &RectfToRECT(rc), NULL, 0, NULL);
}
//----------------------------------------------------------------------------
void UIRenderManager_Win::DoPaintFrame(UIRenderer *uiRenderer, 
	UIPaintManager *paintMan, const Rectf &rc, 
	UITYPE_COLOR colorLight, UITYPE_COLOR colorDark,
	UITYPE_COLOR colorBackground, UINT uStyle)
{
	UIPaintManager_Win *paintMan_Win = (UIPaintManager_Win*)paintMan;

	HDC hDC = uiRenderer->TheDC;

	if (colorBackground != UICOLOR__INVALID)
	{
		DoFillRect(uiRenderer, paintMan, rc, colorBackground);
	}

	RECT rcItem = RectfToRECT(rc);
	if ((uStyle & UIFRAME_ROUND) != 0)
	{
		POINT ptTemp;
		::SelectObject(hDC, paintMan_Win->GetPen(colorLight));
		::MoveToEx(hDC, rcItem.left, rcItem.bottom - 2, &ptTemp);
		::LineTo(hDC, rcItem.left, rcItem.top + 1);
		::LineTo(hDC, rcItem.left + 1, rcItem.top);
		::LineTo(hDC, rcItem.right - 2, rcItem.top);
		::SelectObject(hDC, paintMan_Win->GetPen(colorDark));
		::LineTo(hDC, rcItem.right - 1, rcItem.top + 1);
		::LineTo(hDC, rcItem.right - 1, rcItem.bottom - 2);
		::LineTo(hDC, rcItem.right - 2, rcItem.bottom - 1);
		::LineTo(hDC, rcItem.left, rcItem.bottom - 1);
	}

	if ((uStyle & UIFRAME_FOCUS) != 0)
	{
		HPEN hPen = ::CreatePen(PS_DOT, 1, paintMan_Win->GetColor(UICOLOR_BUTTON_BORDER_FOCUS));
		HPEN hOldPen = (HPEN) ::SelectObject(hDC, hPen);
		POINT ptTemp;
		::MoveToEx(hDC, rcItem.left, rcItem.bottom - 1, &ptTemp);
		::LineTo(hDC, rcItem.left, rcItem.top);
		::LineTo(hDC, rcItem.right - 1, rcItem.top);
		::LineTo(hDC, rcItem.right - 1, rcItem.bottom - 1);
		::LineTo(hDC, rcItem.left, rcItem.bottom - 1);
		::SelectObject(hDC, hOldPen);
		::DeleteObject(hPen);
	}
	else
	{
		POINT ptTemp;
		::SelectObject(hDC, paintMan_Win->GetPen(colorLight));
		::MoveToEx(hDC, rcItem.left, rcItem.bottom - 1, &ptTemp);
		::LineTo(hDC, rcItem.left, rcItem.top);
		::LineTo(hDC, rcItem.right - 1, rcItem.top);
		::SelectObject(hDC, paintMan_Win->GetPen(colorDark));
		::LineTo(hDC, rcItem.right - 1, rcItem.bottom - 1);
		::LineTo(hDC, rcItem.left, rcItem.bottom - 1);
	}
}
//----------------------------------------------------------------------------
void UIRenderManager_Win::DoPaintButton(UIRenderer *uiRenderer,
	UIPaintManager* paintMan, const Rectf &rc, const std::string &text,
	const Rectf &rcPadding, uint32_t uState, uint32_t drawStyle)
{
	ASSERT(::GetObjectType(hDC) == OBJ_DC || ::GetObjectType(hDC) == OBJ_MEMDC);

	UIPaintManager_Win *paintMan_Win = (UIPaintManager_Win*)paintMan;

	HDC hDC = uiRenderer->TheDC;

	RECT rcItem = RectfToRECT(rc);

	if (((uState & UISTATE_FOCUSED) != 0) &&
		paintMan->GetSystemSettings().IsShowKeyboardCues)
	{
		DoPaintFrame(uiRenderer, paintMan, rc, UICOLOR_BUTTON_BORDER_FOCUS,
			UICOLOR_BUTTON_BORDER_FOCUS, UICOLOR__INVALID, UIFRAME_ROUND);
		::InflateRect(&rcItem, -1, -1);
	}

	// Draw frame and body
	COLORREF clrColor1, clrColor2;
	UITYPE_COLOR clrBorder1, clrBorder2, clrText, clrBack;
	if ((uState & UISTATE_DISABLED) != 0) 
	{
		clrBorder1 = UICOLOR_BUTTON_BORDER_DISABLED;
		clrBorder2 = UICOLOR_BUTTON_BORDER_DISABLED;
		clrText = UICOLOR_BUTTON_TEXT_DISABLED;
		clrBack = UICOLOR_BUTTON_BACKGROUND_DISABLED;
	}
	else if ((uState & UISTATE_PUSHED) != 0)
	{
		clrBorder1 = UICOLOR_BUTTON_BORDER_DARK;
		clrBorder2 = UICOLOR_BUTTON_BORDER_LIGHT;
		clrText = UICOLOR_BUTTON_TEXT_PUSHED;
		clrBack = UICOLOR_BUTTON_BACKGROUND_PUSHED;
	}
	else 
	{
		clrBorder1 = UICOLOR_BUTTON_BORDER_LIGHT;
		clrBorder2 = UICOLOR_BUTTON_BORDER_DARK;
		clrText = UICOLOR_BUTTON_TEXT_NORMAL;
		clrBack = UICOLOR_BUTTON_BACKGROUND_NORMAL;
	}

	// Draw button
	DoPaintFrame(uiRenderer, paintMan, rc, clrBorder1, clrBorder2, UICOLOR__INVALID, UIFRAME_ROUND);
	::InflateRect(&rcItem, -1, -1);

	// The pushed button has an inner light shade
	if ((uState & UISTATE_PUSHED) != 0)
	{
		DoPaintFrame(uiRenderer, paintMan, rc, UICOLOR_STANDARD_LIGHTGREY, UICOLOR_STANDARD_LIGHTGREY, UICOLOR__INVALID);
		rcItem.top += 1;
		rcItem.left += 1;
	}

	// Gradient background
	paintMan_Win->GetColorPair(clrBack, clrColor1, clrColor2);

	DoPaintGradient(hDC, paintMan, rcItem, clrColor1, clrColor2, true, 32);

	// Draw hightlight inside button
	::SelectObject(hDC, paintMan_Win->GetPen(UICOLOR_DIALOG_BACKGROUND));
	POINT ptTemp;
	::MoveToEx(hDC, rcItem.left, rcItem.top, &ptTemp);
	::LineTo(hDC, rcItem.left, rcItem.bottom - 1);
	::LineTo(hDC, rcItem.right - 2, rcItem.bottom - 1);
	::LineTo(hDC, rcItem.right - 2, rcItem.top);

	// Draw text
	RECT rectText = rcItem;
	RECT rectPadding = RectfToRECT(rcPadding);
	::InflateRect(&rectText, -1, -1);

	rectText.left += rectPadding.left;
	rectText.top += rectPadding.top;
	rectText.right -= rectPadding.right;
	rectText.bottom -= rectPadding.bottom;
	int nLinks = 0;
	DoPaintPrettyText(uiRenderer, paintMan, RECTToRectf(rectText),
		text, clrText, UICOLOR__INVALID, NULL, nLinks, 
		DT_SINGLELINE|drawStyle);
}
//----------------------------------------------------------------------------
void UIRenderManager_Win::DoPaintGradient(HDC hDC, UIPaintManager *paintMan,
	RECT rc, COLORREF clrFirst, COLORREF clrSecond, bool bVertical, int nSteps)
{
	typedef BOOL(WINAPI *PGradientFill)(HDC, PTRIVERTEX, ULONG, PVOID, ULONG, ULONG);
	static PGradientFill lpGradientFill = (PGradientFill) ::GetProcAddress(::GetModuleHandle("msimg32.dll"), "GradientFill");
	if (lpGradientFill != NULL)
	{
		// Use Windows gradient function from msimg32.dll
		// It may be slower than the code below but makes really pretty gradients on 16bit colors.
		TRIVERTEX triv[2] =
		{
			{ rc.left, rc.top, GetRValue(clrFirst) << 8, GetGValue(clrFirst) << 8, GetBValue(clrFirst) << 8, 0xFF00 },
			{ rc.right, rc.bottom, GetRValue(clrSecond) << 8, GetGValue(clrSecond) << 8, GetBValue(clrSecond) << 8, 0xFF00 }
		};
		GRADIENT_RECT grc = { 0, 1 };
		lpGradientFill(hDC, triv, 2, &grc, 1, bVertical ? GRADIENT_FILL_RECT_V : GRADIENT_FILL_RECT_H);
	}
	else
	{
		// Determine how many shades
		int nShift = 1;
		if (nSteps >= 64) nShift = 6;
		else if (nSteps >= 32) nShift = 5;
		else if (nSteps >= 16) nShift = 4;
		else if (nSteps >= 8) nShift = 3;
		else if (nSteps >= 4) nShift = 2;
		int nLines = 1 << nShift;
		for (int i = 0; i < nLines; i++) 
		{
			// Do a little alpha blending
			BYTE bR = (BYTE)((GetRValue(clrSecond) * (nLines - i) + GetRValue(clrFirst) * i) >> nShift);
			BYTE bG = (BYTE)((GetGValue(clrSecond) * (nLines - i) + GetGValue(clrFirst) * i) >> nShift);
			BYTE bB = (BYTE)((GetBValue(clrSecond) * (nLines - i) + GetBValue(clrFirst) * i) >> nShift);
			// ... then paint with the resulting color
			HBRUSH hBrush = ::CreateSolidBrush(RGB(bR, bG, bB));
			RECT r2 = rc;
			if (bVertical) 
			{
				r2.bottom = rc.bottom - ((i * (rc.bottom - rc.top)) >> nShift);
				r2.top = rc.bottom - (((i + 1) * (rc.bottom - rc.top)) >> nShift);
				if ((r2.bottom - r2.top) > 0) ::FillRect(hDC, &r2, hBrush);
			}
			else 
			{
				r2.left = rc.right - (((i + 1) * (rc.right - rc.left)) >> nShift);
				r2.right = rc.right - ((i * (rc.right - rc.left)) >> nShift);
				if ((r2.right - r2.left) > 0) ::FillRect(hDC, &r2, hBrush);
			}
			::DeleteObject(hBrush);
		}
	}
}
//----------------------------------------------------------------------------
void UIRenderManager_Win::DoPaintPrettyText(UIRenderer *uiRenderer,
	UIPaintManager *pMan,
	const Rectf& rc, const std::string &text, UITYPE_COLOR iTextColor,
	UITYPE_COLOR backColor, const Rectf *links, int &numLinkRects,
	uint32_t style)
{

}
//----------------------------------------------------------------------------