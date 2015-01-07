// PX2UIPaintManager_Win.cpp

#include "PX2UIPaintManager_Win.hpp"
#include "PX2UIDefine.hpp"
#include "PX2UIPre.hpp"
#include "PX2Assert.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
HPEN mHPens[UICOLOR__LAST] = { 0 };
HFONT mHFonts[UIFONT__LAST] = { 0 };
HBRUSH m_hBrushes[UICOLOR__LAST] = { 0 };
LOGFONT m_aLogFonts[UIFONT__LAST] = { 0 };
COLORREF mCtrlColors[UICOLOR__LAST][2] = { 0 };
COLORREF m_clrColors[UICOLOR__LAST][2] = { 0 };
TEXTMETRIC m_aTextMetrics[UIFONT__LAST] = { 0 };
HIMAGELIST m_himgIcons16 = NULL;
HIMAGELIST m_himgIcons24 = NULL;
HIMAGELIST m_himgIcons32 = NULL;
HIMAGELIST m_himgIcons50 = NULL;
//----------------------------------------------------------------------------
HINSTANCE UIPaintManager_Win::mHLangInst = 0;
HINSTANCE UIPaintManager_Win::mHInstance = 0;
//----------------------------------------------------------------------------
UIPaintManager_Win::UIPaintManager_Win() :
mHWndPaint(0),
mHDCPaint(0),
mHDCOffscreen(0),
mHBMPOffscreen(0),
mHWndTooltip(0)
{
	if (0 == mHFonts[1])
	{
		// Fill in default font information
		LOGFONT lf = { 0 };
		::GetObject(::GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &lf);
		_tcscpy(lf.lfFaceName, _T("Tahoma"));
		// TODO: Handle "large fonts" or other font sizes when
		//       screen resolution changes!!!
		lf.lfHeight = -12;
		m_aLogFonts[UIFONT_NORMAL] = lf;
		m_aLogFonts[UIFONT_CAPTION] = lf;
		LOGFONT lfBold = lf;
		lfBold.lfWeight += FW_BOLD;
		m_aLogFonts[UIFONT_BOLD] = lfBold;
		lfBold.lfHeight -= 2;
		m_aLogFonts[UIFONT_TITLE] = lfBold;
		lfBold.lfHeight -= 4;
		m_aLogFonts[UIFONT_HEADLINE] = lfBold;
		LOGFONT lfSubscript = lf;
		lfSubscript.lfHeight -= 4;
		m_aLogFonts[UIFONT_SUBSCRIPT] = lfSubscript;
		LOGFONT lfLink = lf;
		lfLink.lfUnderline = TRUE;
		m_aLogFonts[UIFONT_LINK] = lfLink;

		// Fill the color table
		mCtrlColors[UICOLOR_WINDOW_BACKGROUND][0] = RGB(239, 239, 235);
		mCtrlColors[UICOLOR_DIALOG_BACKGROUND][0] = RGB(238, 238, 238);
		mCtrlColors[UICOLOR_DIALOG_TEXT_NORMAL][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_DIALOG_TEXT_DARK][0] = RGB(96, 96, 80);
		mCtrlColors[UICOLOR_TITLE_BACKGROUND][0] = RGB(114, 136, 172);
		mCtrlColors[UICOLOR_TITLE_TEXT][0] = RGB(255, 255, 255);
		mCtrlColors[UICOLOR_TITLE_BORDER_LIGHT][0] = RGB(171, 192, 231);
		mCtrlColors[UICOLOR_TITLE_BORDER_DARK][0] = RGB(0, 55, 122);
		mCtrlColors[UICOLOR_BUTTON_BACKGROUND_NORMAL][0] = RGB(250, 250, 252);
		mCtrlColors[UICOLOR_BUTTON_BACKGROUND_NORMAL][1] = RGB(215, 215, 227);
		mCtrlColors[UICOLOR_BUTTON_BACKGROUND_DISABLED][0] = RGB(248, 248, 248);
		mCtrlColors[UICOLOR_BUTTON_BACKGROUND_DISABLED][1] = RGB(214, 214, 214);
		mCtrlColors[UICOLOR_BUTTON_BACKGROUND_PUSHED][0] = RGB(215, 215, 227);
		mCtrlColors[UICOLOR_BUTTON_BACKGROUND_PUSHED][1] = RGB(250, 250, 252);
		mCtrlColors[UICOLOR_BUTTON_TEXT_NORMAL][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_BUTTON_TEXT_PUSHED][0] = RGB(0, 0, 20);
		mCtrlColors[UICOLOR_BUTTON_TEXT_DISABLED][0] = RGB(204, 204, 204);
		mCtrlColors[UICOLOR_BUTTON_BORDER_LIGHT][0] = RGB(123, 158, 189);
		mCtrlColors[UICOLOR_BUTTON_BORDER_DARK][0] = RGB(123, 158, 189);
		mCtrlColors[UICOLOR_BUTTON_BORDER_DISABLED][0] = RGB(204, 204, 204);
		mCtrlColors[UICOLOR_BUTTON_BORDER_FOCUS][0] = RGB(140, 140, 140);
		mCtrlColors[UICOLOR_TOOL_BACKGROUND_NORMAL][0] = RGB(114, 136, 172);
		mCtrlColors[UICOLOR_TOOL_BACKGROUND_DISABLED][0] = RGB(100, 121, 156);
		mCtrlColors[UICOLOR_TOOL_BACKGROUND_HOVER][0] = RGB(100, 121, 156);
		mCtrlColors[UICOLOR_TOOL_BACKGROUND_PUSHED][0] = RGB(80, 101, 136);
		mCtrlColors[UICOLOR_TOOL_BORDER_NORMAL][0] = RGB(0, 55, 122);
		mCtrlColors[UICOLOR_TOOL_BORDER_DISABLED][0] = RGB(0, 55, 122);
		mCtrlColors[UICOLOR_TOOL_BORDER_HOVER][0] = RGB(0, 55, 122);
		mCtrlColors[UICOLOR_TOOL_BORDER_PUSHED][0] = RGB(0, 55, 122);
		mCtrlColors[UICOLOR_EDIT_BACKGROUND_DISABLED][0] = RGB(255, 251, 255);
		mCtrlColors[UICOLOR_EDIT_BACKGROUND_READONLY][0] = RGB(255, 251, 255);
		mCtrlColors[UICOLOR_EDIT_BACKGROUND_NORMAL][0] = RGB(255, 255, 255);
		mCtrlColors[UICOLOR_EDIT_BACKGROUND_HOVER][0] = RGB(255, 251, 255);
		mCtrlColors[UICOLOR_EDIT_TEXT_NORMAL][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_EDIT_TEXT_DISABLED][0] = RGB(167, 166, 170);
		mCtrlColors[UICOLOR_EDIT_TEXT_READONLY][0] = RGB(167, 166, 170);
		mCtrlColors[UICOLOR_NAVIGATOR_BACKGROUND][0] = RGB(229, 217, 213);
		mCtrlColors[UICOLOR_NAVIGATOR_BACKGROUND][1] = RGB(201, 199, 187);
		mCtrlColors[UICOLOR_NAVIGATOR_TEXT_NORMAL][0] = RGB(102, 102, 102);
		mCtrlColors[UICOLOR_NAVIGATOR_TEXT_SELECTED][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_NAVIGATOR_TEXT_PUSHED][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_NAVIGATOR_BORDER_NORMAL][0] = RGB(131, 133, 116);
		mCtrlColors[UICOLOR_NAVIGATOR_BORDER_SELECTED][0] = RGB(159, 160, 144);
		mCtrlColors[UICOLOR_NAVIGATOR_BUTTON_HOVER][0] = RGB(200, 200, 200);
		mCtrlColors[UICOLOR_NAVIGATOR_BUTTON_PUSHED][0] = RGB(184, 184, 183);
		mCtrlColors[UICOLOR_NAVIGATOR_BUTTON_SELECTED][0] = RGB(238, 238, 238);
		mCtrlColors[UICOLOR_TAB_BACKGROUND_NORMAL][0] = RGB(255, 251, 255);
		mCtrlColors[UICOLOR_TAB_FOLDER_NORMAL][0] = RGB(255, 251, 255);
		mCtrlColors[UICOLOR_TAB_FOLDER_NORMAL][1] = RGB(233, 231, 215);
		mCtrlColors[UICOLOR_TAB_FOLDER_SELECTED][0] = RGB(255, 251, 255);
		mCtrlColors[UICOLOR_TAB_BORDER][0] = RGB(148, 166, 181);
		mCtrlColors[UICOLOR_TAB_TEXT_NORMAL][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_TAB_TEXT_SELECTED][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_TAB_TEXT_DISABLED][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_HEADER_BACKGROUND][0] = RGB(233, 231, 215);
		mCtrlColors[UICOLOR_HEADER_BACKGROUND][1] = RGB(150, 150, 147);
		mCtrlColors[UICOLOR_HEADER_BORDER][0] = RGB(218, 219, 201);
		mCtrlColors[UICOLOR_HEADER_SEPARATOR][0] = RGB(197, 193, 177);
		mCtrlColors[UICOLOR_HEADER_TEXT][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_TASK_BACKGROUND][0] = RGB(230, 243, 255);
		mCtrlColors[UICOLOR_TASK_BACKGROUND][1] = RGB(255, 255, 255);
		mCtrlColors[UICOLOR_TASK_BORDER][0] = RGB(140, 158, 198);
		mCtrlColors[UICOLOR_TASK_CAPTION][0] = RGB(140, 158, 198);
		mCtrlColors[UICOLOR_TASK_TEXT][0] = RGB(65, 65, 110);
		mCtrlColors[UICOLOR_LINK_TEXT_NORMAL][0] = RGB(0, 0, 255);
		mCtrlColors[UICOLOR_LINK_TEXT_HOVER][0] = RGB(0, 0, 100);
		mCtrlColors[UICOLOR_CONTROL_BACKGROUND_NORMAL][0] = RGB(255, 255, 255);
		mCtrlColors[UICOLOR_CONTROL_BACKGROUND_SELECTED][0] = RGB(173, 195, 231);
		mCtrlColors[UICOLOR_CONTROL_BACKGROUND_READONLY][0] = RGB(255, 255, 255);
		mCtrlColors[UICOLOR_CONTROL_BACKGROUND_DISABLED][0] = RGB(255, 255, 255);
		mCtrlColors[UICOLOR_CONTROL_BACKGROUND_HOVER][0] = RGB(233, 245, 255);
		mCtrlColors[UICOLOR_CONTROL_BACKGROUND_SORTED][0] = RGB(242, 242, 246);
		mCtrlColors[UICOLOR_CONTROL_BACKGROUND_EXPANDED][0] = RGB(255, 255, 255);
		mCtrlColors[UICOLOR_CONTROL_BACKGROUND_EXPANDED][1] = RGB(236, 242, 255);
		mCtrlColors[UICOLOR_CONTROL_BORDER_NORMAL][0] = RGB(123, 158, 189);
		mCtrlColors[UICOLOR_CONTROL_BORDER_SELECTED][0] = RGB(123, 158, 189);
		mCtrlColors[UICOLOR_CONTROL_BORDER_DISABLED][0] = RGB(204, 204, 204);
		mCtrlColors[UICOLOR_CONTROL_TEXT_NORMAL][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_CONTROL_TEXT_SELECTED][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_CONTROL_TEXT_DISABLED][0] = RGB(204, 204, 204);
		mCtrlColors[UICOLOR_STANDARD_BLACK][0] = RGB(0, 0, 0);
		mCtrlColors[UICOLOR_STANDARD_YELLOW][0] = RGB(255, 255, 204);
		mCtrlColors[UICOLOR_STANDARD_RED][0] = RGB(255, 204, 204);
		mCtrlColors[UICOLOR_STANDARD_GREY][0] = RGB(145, 146, 119);
		mCtrlColors[UICOLOR_STANDARD_LIGHTGREY][0] = RGB(195, 196, 179);
		mCtrlColors[UICOLOR_STANDARD_WHITE][0] = RGB(255, 255, 255);

		::InitCommonControls();
		::LoadLibrary("msimg32.dll");
	}
	
	mMinSize.Width = 140;
	mMinSize.Height = 200;
	mLastMousePos = Float2(-1.0f, -1.0f);

	mMsgMouseWheel = ::RegisterWindowMessage(MSH_MOUSEWHEEL);

	// System Config
	mSystemConfig.IsShowKeyboardCues = false;
	mSystemConfig.IsScrollLists = false;

	// System Metrics
	mSystemMetrics.Cxvscroll = ::GetSystemMetrics(SM_CXVSCROLL);
}
//----------------------------------------------------------------------------
UIPaintManager_Win::~UIPaintManager_Win()
{
	if (mHWndTooltip != NULL) ::DestroyWindow(mHWndTooltip);
	if (mHDCOffscreen != NULL) ::DeleteDC(mHDCOffscreen);
	if (mHBMPOffscreen != NULL) ::DeleteObject(mHBMPOffscreen);
	if (mHDCPaint != NULL) ::ReleaseDC(mHWndPaint, mHDCPaint);
}
//----------------------------------------------------------------------------
HINSTANCE UIPaintManager_Win::GetResourceInstance()
{
	return mHInstance;
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::SetResourceInstance(HINSTANCE hInst)
{
	mHInstance = hInst;
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::SetLanguageInstance(HINSTANCE hInst)
{
	mHLangInst = hInst;
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::Init(HWND hWnd)
{
	assertion(TRUE==::IsWindow(hWnd), "must be window\n");

	mHWndPaint = hWnd;
	mHDCPaint = ::GetDC(hWnd);
}
//----------------------------------------------------------------------------
HDC UIPaintManager_Win::GetPaintDC() const
{
	return mHDCPaint;
}
//----------------------------------------------------------------------------
HWND UIPaintManager_Win::GetPaintWindow() const
{
	return mHWndPaint;
}
//----------------------------------------------------------------------------
Sizef UIPaintManager_Win::GetClientSize() const
{
	RECT rcClient = { 0 };
	::GetClientRect(mHWndPaint, &rcClient);
	return Sizef((float)(rcClient.right - rcClient.left), (float)rcClient.bottom - rcClient.top);
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::UpdateLayout()
{
	mIsResizeNeeded = true;
	::InvalidateRect(mHWndPaint, NULL, FALSE);
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::Invalidate(RECT rcItem)
{
	::InvalidateRect(mHWndPaint, &rcItem, FALSE);
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::MessageLoop()
{
	MSG msg = { 0 };
	while (::GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateMessage(&msg)) 
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
	}
}
//----------------------------------------------------------------------------
bool UIPaintManager_Win::TranslateMessage(const LPMSG pMsg)
{
	HWND hwndParent = ::GetParent(pMsg->hwnd);
	UINT uStyle = GetWindowStyle(pMsg->hwnd);
	LRESULT lRes = 0;
	return false;
}
//----------------------------------------------------------------------------