// PX2UIPaintManager_Win.cpp

#include "PX2UIPaintManager_Win.hpp"
#include "PX2UIDefine.hpp"
#include "PX2UIPre.hpp"
#include "PX2Assert.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
COLORREF TheCtrlColors[UICOLOR__LAST][2] = { 0 };
HPEN ThePens[UICOLOR__LAST] = { 0 };
HFONT TheFonts[UIFONT__LAST] = { 0 };
LOGFONT TheLogFonts[UIFONT__LAST] = { 0 };
HBRUSH TheBrushes[UICOLOR__LAST] = { 0 };
HIMAGELIST TheHImgIcons16 = 0;
HIMAGELIST TheHImgIcons24 = 0;
HIMAGELIST TheHImgIcons32 = 0;
HIMAGELIST TheHImgIcons50 = 0;
//----------------------------------------------------------------------------
UIPaintManager_Win::UIPaintManager_Win() :
mHWndPaint(0),
mHDCPaint(0),
mHDCOffscreen(0),
mHBMPOffscreen(0),
mHWndTooltip(0)
{
	// fill in default font information

	// normal
	LOGFONT lf = { 0 };
	::GetObject(::GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &lf);
	_tcscpy(lf.lfFaceName, _T("Tahoma"));
	lf.lfHeight = -12;
	TheLogFonts[UIFONT_NORMAL] = lf;
	TheLogFonts[UIFONT_CAPTION] = lf;

	// bold
	LOGFONT lfBold = lf;
	lfBold.lfWeight += FW_BOLD;
	TheLogFonts[UIFONT_BOLD] = lfBold;
	lfBold.lfHeight -= 2;
	TheLogFonts[UIFONT_TITLE] = lfBold;
	lfBold.lfHeight -= 4;
	TheLogFonts[UIFONT_HEADLINE] = lfBold;

	// underline
	LOGFONT lfSubscript = lf;
	lfSubscript.lfHeight -= 4;
	TheLogFonts[UIFONT_SUBSCRIPT] = lfSubscript;
	LOGFONT lfLink = lf;
	lfLink.lfUnderline = TRUE;
	TheLogFonts[UIFONT_LINK] = lfLink;

	// Fill the color table
	TheCtrlColors[UICOLOR_WINDOW_BACKGROUND][0] = RGB(239, 239, 235);
	TheCtrlColors[UICOLOR_DIALOG_BACKGROUND][0] = RGB(238, 238, 238);
	TheCtrlColors[UICOLOR_DIALOG_TEXT_NORMAL][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_DIALOG_TEXT_DARK][0] = RGB(96, 96, 80);
	TheCtrlColors[UICOLOR_TITLE_BACKGROUND][0] = RGB(114, 136, 172);
	TheCtrlColors[UICOLOR_TITLE_TEXT][0] = RGB(255, 255, 255);
	TheCtrlColors[UICOLOR_TITLE_BORDER_LIGHT][0] = RGB(171, 192, 231);
	TheCtrlColors[UICOLOR_TITLE_BORDER_DARK][0] = RGB(0, 55, 122);
	TheCtrlColors[UICOLOR_BUTTON_BACKGROUND_NORMAL][0] = RGB(250, 250, 252);
	TheCtrlColors[UICOLOR_BUTTON_BACKGROUND_NORMAL][1] = RGB(215, 215, 227);
	TheCtrlColors[UICOLOR_BUTTON_BACKGROUND_DISABLED][0] = RGB(248, 248, 248);
	TheCtrlColors[UICOLOR_BUTTON_BACKGROUND_DISABLED][1] = RGB(214, 214, 214);
	TheCtrlColors[UICOLOR_BUTTON_BACKGROUND_PUSHED][0] = RGB(215, 215, 227);
	TheCtrlColors[UICOLOR_BUTTON_BACKGROUND_PUSHED][1] = RGB(250, 250, 252);
	TheCtrlColors[UICOLOR_BUTTON_TEXT_NORMAL][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_BUTTON_TEXT_PUSHED][0] = RGB(0, 0, 20);
	TheCtrlColors[UICOLOR_BUTTON_TEXT_DISABLED][0] = RGB(204, 204, 204);
	TheCtrlColors[UICOLOR_BUTTON_BORDER_LIGHT][0] = RGB(123, 158, 189);
	TheCtrlColors[UICOLOR_BUTTON_BORDER_DARK][0] = RGB(123, 158, 189);
	TheCtrlColors[UICOLOR_BUTTON_BORDER_DISABLED][0] = RGB(204, 204, 204);
	TheCtrlColors[UICOLOR_BUTTON_BORDER_FOCUS][0] = RGB(140, 140, 140);
	TheCtrlColors[UICOLOR_TOOL_BACKGROUND_NORMAL][0] = RGB(114, 136, 172);
	TheCtrlColors[UICOLOR_TOOL_BACKGROUND_DISABLED][0] = RGB(100, 121, 156);
	TheCtrlColors[UICOLOR_TOOL_BACKGROUND_HOVER][0] = RGB(100, 121, 156);
	TheCtrlColors[UICOLOR_TOOL_BACKGROUND_PUSHED][0] = RGB(80, 101, 136);
	TheCtrlColors[UICOLOR_TOOL_BORDER_NORMAL][0] = RGB(0, 55, 122);
	TheCtrlColors[UICOLOR_TOOL_BORDER_DISABLED][0] = RGB(0, 55, 122);
	TheCtrlColors[UICOLOR_TOOL_BORDER_HOVER][0] = RGB(0, 55, 122);
	TheCtrlColors[UICOLOR_TOOL_BORDER_PUSHED][0] = RGB(0, 55, 122);
	TheCtrlColors[UICOLOR_EDIT_BACKGROUND_DISABLED][0] = RGB(255, 251, 255);
	TheCtrlColors[UICOLOR_EDIT_BACKGROUND_READONLY][0] = RGB(255, 251, 255);
	TheCtrlColors[UICOLOR_EDIT_BACKGROUND_NORMAL][0] = RGB(255, 255, 255);
	TheCtrlColors[UICOLOR_EDIT_BACKGROUND_HOVER][0] = RGB(255, 251, 255);
	TheCtrlColors[UICOLOR_EDIT_TEXT_NORMAL][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_EDIT_TEXT_DISABLED][0] = RGB(167, 166, 170);
	TheCtrlColors[UICOLOR_EDIT_TEXT_READONLY][0] = RGB(167, 166, 170);
	TheCtrlColors[UICOLOR_NAVIGATOR_BACKGROUND][0] = RGB(229, 217, 213);
	TheCtrlColors[UICOLOR_NAVIGATOR_BACKGROUND][1] = RGB(201, 199, 187);
	TheCtrlColors[UICOLOR_NAVIGATOR_TEXT_NORMAL][0] = RGB(102, 102, 102);
	TheCtrlColors[UICOLOR_NAVIGATOR_TEXT_SELECTED][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_NAVIGATOR_TEXT_PUSHED][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_NAVIGATOR_BORDER_NORMAL][0] = RGB(131, 133, 116);
	TheCtrlColors[UICOLOR_NAVIGATOR_BORDER_SELECTED][0] = RGB(159, 160, 144);
	TheCtrlColors[UICOLOR_NAVIGATOR_BUTTON_HOVER][0] = RGB(200, 200, 200);
	TheCtrlColors[UICOLOR_NAVIGATOR_BUTTON_PUSHED][0] = RGB(184, 184, 183);
	TheCtrlColors[UICOLOR_NAVIGATOR_BUTTON_SELECTED][0] = RGB(238, 238, 238);
	TheCtrlColors[UICOLOR_TAB_BACKGROUND_NORMAL][0] = RGB(255, 251, 255);
	TheCtrlColors[UICOLOR_TAB_FOLDER_NORMAL][0] = RGB(255, 251, 255);
	TheCtrlColors[UICOLOR_TAB_FOLDER_NORMAL][1] = RGB(233, 231, 215);
	TheCtrlColors[UICOLOR_TAB_FOLDER_SELECTED][0] = RGB(255, 251, 255);
	TheCtrlColors[UICOLOR_TAB_BORDER][0] = RGB(148, 166, 181);
	TheCtrlColors[UICOLOR_TAB_TEXT_NORMAL][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_TAB_TEXT_SELECTED][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_TAB_TEXT_DISABLED][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_HEADER_BACKGROUND][0] = RGB(233, 231, 215);
	TheCtrlColors[UICOLOR_HEADER_BACKGROUND][1] = RGB(150, 150, 147);
	TheCtrlColors[UICOLOR_HEADER_BORDER][0] = RGB(218, 219, 201);
	TheCtrlColors[UICOLOR_HEADER_SEPARATOR][0] = RGB(197, 193, 177);
	TheCtrlColors[UICOLOR_HEADER_TEXT][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_TASK_BACKGROUND][0] = RGB(230, 243, 255);
	TheCtrlColors[UICOLOR_TASK_BACKGROUND][1] = RGB(255, 255, 255);
	TheCtrlColors[UICOLOR_TASK_BORDER][0] = RGB(140, 158, 198);
	TheCtrlColors[UICOLOR_TASK_CAPTION][0] = RGB(140, 158, 198);
	TheCtrlColors[UICOLOR_TASK_TEXT][0] = RGB(65, 65, 110);
	TheCtrlColors[UICOLOR_LINK_TEXT_NORMAL][0] = RGB(0, 0, 255);
	TheCtrlColors[UICOLOR_LINK_TEXT_HOVER][0] = RGB(0, 0, 100);
	TheCtrlColors[UICOLOR_CONTROL_BACKGROUND_NORMAL][0] = RGB(255, 255, 255);
	TheCtrlColors[UICOLOR_CONTROL_BACKGROUND_SELECTED][0] = RGB(173, 195, 231);
	TheCtrlColors[UICOLOR_CONTROL_BACKGROUND_READONLY][0] = RGB(255, 255, 255);
	TheCtrlColors[UICOLOR_CONTROL_BACKGROUND_DISABLED][0] = RGB(255, 255, 255);
	TheCtrlColors[UICOLOR_CONTROL_BACKGROUND_HOVER][0] = RGB(233, 245, 255);
	TheCtrlColors[UICOLOR_CONTROL_BACKGROUND_SORTED][0] = RGB(242, 242, 246);
	TheCtrlColors[UICOLOR_CONTROL_BACKGROUND_EXPANDED][0] = RGB(255, 255, 255);
	TheCtrlColors[UICOLOR_CONTROL_BACKGROUND_EXPANDED][1] = RGB(236, 242, 255);
	TheCtrlColors[UICOLOR_CONTROL_BORDER_NORMAL][0] = RGB(123, 158, 189);
	TheCtrlColors[UICOLOR_CONTROL_BORDER_SELECTED][0] = RGB(123, 158, 189);
	TheCtrlColors[UICOLOR_CONTROL_BORDER_DISABLED][0] = RGB(204, 204, 204);
	TheCtrlColors[UICOLOR_CONTROL_TEXT_NORMAL][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_CONTROL_TEXT_SELECTED][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_CONTROL_TEXT_DISABLED][0] = RGB(204, 204, 204);
	TheCtrlColors[UICOLOR_STANDARD_BLACK][0] = RGB(0, 0, 0);
	TheCtrlColors[UICOLOR_STANDARD_YELLOW][0] = RGB(255, 255, 204);
	TheCtrlColors[UICOLOR_STANDARD_RED][0] = RGB(255, 204, 204);
	TheCtrlColors[UICOLOR_STANDARD_GREY][0] = RGB(145, 146, 119);
	TheCtrlColors[UICOLOR_STANDARD_LIGHTGREY][0] = RGB(195, 196, 179);
	TheCtrlColors[UICOLOR_STANDARD_WHITE][0] = RGB(255, 255, 255);

	mMinSize.Width = 140;
	mMinSize.Height = 200;
	mLastMousePos = Float2(-1.0f, -1.0f);

	mMsgMouseWheel = ::RegisterWindowMessage(MSH_MOUSEWHEEL);

	// System Metrics
	mSystemMetrics.Cxvscroll = ::GetSystemMetrics(SM_CXVSCROLL);
}
//----------------------------------------------------------------------------
UIPaintManager_Win::~UIPaintManager_Win()
{
	if (mHWndTooltip != 0) ::DestroyWindow(mHWndTooltip);
	if (mHDCOffscreen != 0) ::DeleteDC(mHDCOffscreen);
	if (mHBMPOffscreen != 0) ::DeleteObject(mHBMPOffscreen);
	if (mHDCPaint != 0) ::ReleaseDC(mHWndPaint, mHDCPaint);
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::SetPlatformData(void *data)
{
	UIPaintManager::SetPlatformData(data);

	SetResourceInstance(HINSTANCE(data));
}
//----------------------------------------------------------------------------
COLORREF UIPaintManager_Win::GetColor(UITYPE_COLOR index) const
{
	if (index <= UICOLOR__FIRST || index >= UICOLOR__LAST)
		return RGB(0, 0, 0);

	return TheCtrlColors[index][0];
}
//----------------------------------------------------------------------------
bool UIPaintManager_Win::GetColorPair(UITYPE_COLOR Index, COLORREF& clr1,
	COLORREF& clr2) const
{
	if (Index <= UICOLOR__FIRST || Index >= UICOLOR__LAST) 
		return false;
	
	clr1 = TheCtrlColors[Index][0];
	clr2 = TheCtrlColors[Index][1];
	
	return true;
}
//----------------------------------------------------------------------------
HPEN UIPaintManager_Win::GetPen(UITYPE_COLOR index) const
{
	if (index<=UICOLOR__FIRST || index>=UICOLOR__LAST)
		return 0;

	if (ThePens[index] == 0) 
		ThePens[index] = ::CreatePen(PS_SOLID, 1, TheCtrlColors[index][0]);
	
	return ThePens[index];
}
//----------------------------------------------------------------------------
HFONT UIPaintManager_Win::GetFont(UITYPE_FONT index) const
{
	if (index <= UIFONT__FIRST || index >= UIFONT__LAST)
		return 0;

	if (TheFonts[index] == 0) 
		TheFonts[index] = ::CreateFontIndirect(&TheLogFonts[index]);
	
	return TheFonts[index];
}
//----------------------------------------------------------------------------
HBRUSH UIPaintManager_Win::GetBrush(UITYPE_COLOR index) const
{
	if (index <= UICOLOR__FIRST || index >= UICOLOR__LAST)
		return 0;

	if (TheBrushes[index] == 0) 
		TheBrushes[index] = ::CreateSolidBrush(TheCtrlColors[index][0]);

	return TheBrushes[index];
}
//----------------------------------------------------------------------------
#define PX2_IDB_ICONS16 200
#define PX2_IDB_ICONS24 201
#define PX2_IDB_ICONS32 202
#define PX2_IDB_ICONS50 203
//----------------------------------------------------------------------------
HICON UIPaintManager_Win::GetIcon (int index, int cxySize) const
{
	if (TheHImgIcons16 == 0) 
	{
		TheHImgIcons16 = ImageList_LoadImage(mHInstance, MAKEINTRESOURCE(PX2_IDB_ICONS16), 16, 0, RGB(255, 0, 255), IMAGE_BITMAP, LR_CREATEDIBSECTION);
		TheHImgIcons24 = ImageList_LoadImage(mHInstance, MAKEINTRESOURCE(PX2_IDB_ICONS24), 16, 0, RGB(255, 0, 255), IMAGE_BITMAP, LR_CREATEDIBSECTION);
		TheHImgIcons32 = ImageList_LoadImage(mHInstance, MAKEINTRESOURCE(PX2_IDB_ICONS32), 16, 0, RGB(255, 0, 255), IMAGE_BITMAP, LR_CREATEDIBSECTION);
		TheHImgIcons50 = ImageList_LoadImage(mHInstance, MAKEINTRESOURCE(PX2_IDB_ICONS50), 50, 0, RGB(255, 0, 255), IMAGE_BITMAP, LR_CREATEDIBSECTION);
	}
	if (cxySize == 16) return ImageList_GetIcon(TheHImgIcons16, index, ILD_NORMAL);
	else if (cxySize == 24) return ImageList_GetIcon(TheHImgIcons24, index, ILD_NORMAL);
	else if (cxySize == 32) return ImageList_GetIcon(TheHImgIcons32, index, ILD_NORMAL);
	else if (cxySize == 50) return ImageList_GetIcon(TheHImgIcons50, index, ILD_NORMAL);
	return 0;
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::SetResourceInstance(HINSTANCE hInst)
{
	mHInstance = hInst;
}
//----------------------------------------------------------------------------
HINSTANCE UIPaintManager_Win::GetResourceInstance()
{
	return mHInstance;
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::Init(HWND hWnd)
{
	assertion(TRUE == ::IsWindow(hWnd), "must be window\n");

	mHWndPaint = hWnd;
	mHDCPaint = ::GetDC(hWnd);
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::Invalidate(const Rectf &rcItem)
{
	RECT rect;
	rect.left = (int)rcItem.Left;
	rect.right = (int)rcItem.Right;
	rect.bottom = (int)rcItem.Bottom;
	rect.top = (int)rcItem.Top;

	::InvalidateRect(mHWndPaint, &RectfToRECT(rcItem), FALSE);
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
	::InvalidateRect(mHWndPaint, 0, FALSE);
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::Invalidate(RECT rcItem)
{
	::InvalidateRect(mHWndPaint, &rcItem, FALSE);
}
//----------------------------------------------------------------------------
void UIPaintManager_Win::Run()
{
	MSG msg = { 0 };
	while (::GetMessage(&msg, 0, 0, 0))
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