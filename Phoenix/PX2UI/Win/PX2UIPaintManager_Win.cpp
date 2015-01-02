// PX2UIPaintManager_Win.cpp

#include "PX2UIPaintManager_Win.hpp"
#include "PX2UIDefinePre.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
HPEN mHPens[UICOLOR__LAST] = { 0 };
HFONT mHFonts[UIFONT__LAST] = { 0 };
HBRUSH m_hBrushes[UICOLOR__LAST] = { 0 };
LOGFONT m_aLogFonts[UIFONT__LAST] = { 0 };
COLORREF m_clrColors[UICOLOR__LAST][2] = { 0 };
TEXTMETRIC m_aTextMetrics[UIFONT__LAST] = { 0 };
HIMAGELIST m_himgIcons16 = NULL;
HIMAGELIST m_himgIcons24 = NULL;
HIMAGELIST m_himgIcons32 = NULL;
HIMAGELIST m_himgIcons50 = NULL;
//----------------------------------------------------------------------------
UIPaintManager_Win::UIPaintManager_Win() :
mHWndPaint(0),
mHDCPaint(0),
mHDCOffscreen(0),
mHBMPOffscreen(0),
mHWndTooltip(0)
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
	m_clrColors[UICOLOR_WINDOW_BACKGROUND][0] = RGB(239, 239, 235);
	m_clrColors[UICOLOR_DIALOG_BACKGROUND][0] = RGB(238, 238, 238);
	m_clrColors[UICOLOR_DIALOG_TEXT_NORMAL][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_DIALOG_TEXT_DARK][0] = RGB(96, 96, 80);
	m_clrColors[UICOLOR_TITLE_BACKGROUND][0] = RGB(114, 136, 172);
	m_clrColors[UICOLOR_TITLE_TEXT][0] = RGB(255, 255, 255);
	m_clrColors[UICOLOR_TITLE_BORDER_LIGHT][0] = RGB(171, 192, 231);
	m_clrColors[UICOLOR_TITLE_BORDER_DARK][0] = RGB(0, 55, 122);
	m_clrColors[UICOLOR_BUTTON_BACKGROUND_NORMAL][0] = RGB(250, 250, 252);
	m_clrColors[UICOLOR_BUTTON_BACKGROUND_NORMAL][1] = RGB(215, 215, 227);
	m_clrColors[UICOLOR_BUTTON_BACKGROUND_DISABLED][0] = RGB(248, 248, 248);
	m_clrColors[UICOLOR_BUTTON_BACKGROUND_DISABLED][1] = RGB(214, 214, 214);
	m_clrColors[UICOLOR_BUTTON_BACKGROUND_PUSHED][0] = RGB(215, 215, 227);
	m_clrColors[UICOLOR_BUTTON_BACKGROUND_PUSHED][1] = RGB(250, 250, 252);
	m_clrColors[UICOLOR_BUTTON_TEXT_NORMAL][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_BUTTON_TEXT_PUSHED][0] = RGB(0, 0, 20);
	m_clrColors[UICOLOR_BUTTON_TEXT_DISABLED][0] = RGB(204, 204, 204);
	m_clrColors[UICOLOR_BUTTON_BORDER_LIGHT][0] = RGB(123, 158, 189);
	m_clrColors[UICOLOR_BUTTON_BORDER_DARK][0] = RGB(123, 158, 189);
	m_clrColors[UICOLOR_BUTTON_BORDER_DISABLED][0] = RGB(204, 204, 204);
	m_clrColors[UICOLOR_BUTTON_BORDER_FOCUS][0] = RGB(140, 140, 140);
	m_clrColors[UICOLOR_TOOL_BACKGROUND_NORMAL][0] = RGB(114, 136, 172);
	m_clrColors[UICOLOR_TOOL_BACKGROUND_DISABLED][0] = RGB(100, 121, 156);
	m_clrColors[UICOLOR_TOOL_BACKGROUND_HOVER][0] = RGB(100, 121, 156);
	m_clrColors[UICOLOR_TOOL_BACKGROUND_PUSHED][0] = RGB(80, 101, 136);
	m_clrColors[UICOLOR_TOOL_BORDER_NORMAL][0] = RGB(0, 55, 122);
	m_clrColors[UICOLOR_TOOL_BORDER_DISABLED][0] = RGB(0, 55, 122);
	m_clrColors[UICOLOR_TOOL_BORDER_HOVER][0] = RGB(0, 55, 122);
	m_clrColors[UICOLOR_TOOL_BORDER_PUSHED][0] = RGB(0, 55, 122);
	m_clrColors[UICOLOR_EDIT_BACKGROUND_DISABLED][0] = RGB(255, 251, 255);
	m_clrColors[UICOLOR_EDIT_BACKGROUND_READONLY][0] = RGB(255, 251, 255);
	m_clrColors[UICOLOR_EDIT_BACKGROUND_NORMAL][0] = RGB(255, 255, 255);
	m_clrColors[UICOLOR_EDIT_BACKGROUND_HOVER][0] = RGB(255, 251, 255);
	m_clrColors[UICOLOR_EDIT_TEXT_NORMAL][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_EDIT_TEXT_DISABLED][0] = RGB(167, 166, 170);
	m_clrColors[UICOLOR_EDIT_TEXT_READONLY][0] = RGB(167, 166, 170);
	m_clrColors[UICOLOR_NAVIGATOR_BACKGROUND][0] = RGB(229, 217, 213);
	m_clrColors[UICOLOR_NAVIGATOR_BACKGROUND][1] = RGB(201, 199, 187);
	m_clrColors[UICOLOR_NAVIGATOR_TEXT_NORMAL][0] = RGB(102, 102, 102);
	m_clrColors[UICOLOR_NAVIGATOR_TEXT_SELECTED][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_NAVIGATOR_TEXT_PUSHED][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_NAVIGATOR_BORDER_NORMAL][0] = RGB(131, 133, 116);
	m_clrColors[UICOLOR_NAVIGATOR_BORDER_SELECTED][0] = RGB(159, 160, 144);
	m_clrColors[UICOLOR_NAVIGATOR_BUTTON_HOVER][0] = RGB(200, 200, 200);
	m_clrColors[UICOLOR_NAVIGATOR_BUTTON_PUSHED][0] = RGB(184, 184, 183);
	m_clrColors[UICOLOR_NAVIGATOR_BUTTON_SELECTED][0] = RGB(238, 238, 238);
	m_clrColors[UICOLOR_TAB_BACKGROUND_NORMAL][0] = RGB(255, 251, 255);
	m_clrColors[UICOLOR_TAB_FOLDER_NORMAL][0] = RGB(255, 251, 255);
	m_clrColors[UICOLOR_TAB_FOLDER_NORMAL][1] = RGB(233, 231, 215);
	m_clrColors[UICOLOR_TAB_FOLDER_SELECTED][0] = RGB(255, 251, 255);
	m_clrColors[UICOLOR_TAB_BORDER][0] = RGB(148, 166, 181);
	m_clrColors[UICOLOR_TAB_TEXT_NORMAL][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_TAB_TEXT_SELECTED][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_TAB_TEXT_DISABLED][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_HEADER_BACKGROUND][0] = RGB(233, 231, 215);
	m_clrColors[UICOLOR_HEADER_BACKGROUND][1] = RGB(150, 150, 147);
	m_clrColors[UICOLOR_HEADER_BORDER][0] = RGB(218, 219, 201);
	m_clrColors[UICOLOR_HEADER_SEPARATOR][0] = RGB(197, 193, 177);
	m_clrColors[UICOLOR_HEADER_TEXT][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_TASK_BACKGROUND][0] = RGB(230, 243, 255);
	m_clrColors[UICOLOR_TASK_BACKGROUND][1] = RGB(255, 255, 255);
	m_clrColors[UICOLOR_TASK_BORDER][0] = RGB(140, 158, 198);
	m_clrColors[UICOLOR_TASK_CAPTION][0] = RGB(140, 158, 198);
	m_clrColors[UICOLOR_TASK_TEXT][0] = RGB(65, 65, 110);
	m_clrColors[UICOLOR_LINK_TEXT_NORMAL][0] = RGB(0, 0, 255);
	m_clrColors[UICOLOR_LINK_TEXT_HOVER][0] = RGB(0, 0, 100);
	m_clrColors[UICOLOR_CONTROL_BACKGROUND_NORMAL][0] = RGB(255, 255, 255);
	m_clrColors[UICOLOR_CONTROL_BACKGROUND_SELECTED][0] = RGB(173, 195, 231);
	m_clrColors[UICOLOR_CONTROL_BACKGROUND_READONLY][0] = RGB(255, 255, 255);
	m_clrColors[UICOLOR_CONTROL_BACKGROUND_DISABLED][0] = RGB(255, 255, 255);
	m_clrColors[UICOLOR_CONTROL_BACKGROUND_HOVER][0] = RGB(233, 245, 255);
	m_clrColors[UICOLOR_CONTROL_BACKGROUND_SORTED][0] = RGB(242, 242, 246);
	m_clrColors[UICOLOR_CONTROL_BACKGROUND_EXPANDED][0] = RGB(255, 255, 255);
	m_clrColors[UICOLOR_CONTROL_BACKGROUND_EXPANDED][1] = RGB(236, 242, 255);
	m_clrColors[UICOLOR_CONTROL_BORDER_NORMAL][0] = RGB(123, 158, 189);
	m_clrColors[UICOLOR_CONTROL_BORDER_SELECTED][0] = RGB(123, 158, 189);
	m_clrColors[UICOLOR_CONTROL_BORDER_DISABLED][0] = RGB(204, 204, 204);
	m_clrColors[UICOLOR_CONTROL_TEXT_NORMAL][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_CONTROL_TEXT_SELECTED][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_CONTROL_TEXT_DISABLED][0] = RGB(204, 204, 204);
	m_clrColors[UICOLOR_STANDARD_BLACK][0] = RGB(0, 0, 0);
	m_clrColors[UICOLOR_STANDARD_YELLOW][0] = RGB(255, 255, 204);
	m_clrColors[UICOLOR_STANDARD_RED][0] = RGB(255, 204, 204);
	m_clrColors[UICOLOR_STANDARD_GREY][0] = RGB(145, 146, 119);
	m_clrColors[UICOLOR_STANDARD_LIGHTGREY][0] = RGB(195, 196, 179);
	m_clrColors[UICOLOR_STANDARD_WHITE][0] = RGB(255, 255, 255);

	// Boot Windows Common Controls (for the ToolTip control)
	::InitCommonControls();

	// We need the image library for effects. It is however optional in Windows so
	// we'll also need to provide a gracefull fallback.
	::LoadLibrary("msimg32.dll");
}
m_szMinWindow.cx = 140;
m_szMinWindow.cy = 200;
m_ptLastMousePos.x = m_ptLastMousePos.y = -1;
m_uMsgMouseWheel = ::RegisterWindowMessage(MSH_MOUSEWHEEL);
// System Config
m_SystemConfig.bShowKeyboardCues = false;
m_SystemConfig.bScrollLists = false;
// System Metrics
m_SystemMetrics.cxvscroll = (INT) ::GetSystemMetrics(SM_CXVSCROLL);
}
//----------------------------------------------------------------------------
UIPaintManager_Win::~UIPaintManager_Win()
{

}
//----------------------------------------------------------------------------