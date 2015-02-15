// PX2wxAui.cpp

#include "PX2wxAui.hpp"
#include "PX2EngineLoop.hpp"
#include "PX2NirvanaEventType.hpp"
#include "PX2E_MainFrame.hpp"
#include "PX2Edit.hpp"
#include "PX2EditParams.hpp"
#include "PX2E_Define.hpp"
using namespace PX2Editor;

//----------------------------------------------------------------------------
// PX2wxAuiNotebook
//----------------------------------------------------------------------------
BEGIN_EVENT_TABLE(PX2wxAuiNotebook, wxAuiNotebook)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
PX2wxAuiNotebook::PX2wxAuiNotebook(wxWindow* parent, bool isTop) :
wxAuiNotebook(parent),
mIsCenter(isTop)
{
	m_selectedFont.SetWeight(wxNORMAL);

	Connect(wxEVT_COMMAND_AUINOTEBOOK_BEGIN_DRAG,
		wxAuiNotebookEventHandler(PX2wxAuiNotebook::DragFun_Begin));

	Connect(wxEVT_COMMAND_AUINOTEBOOK_END_DRAG,
		wxAuiNotebookEventHandler(PX2wxAuiNotebook::DragFun_End));

	Connect(wxEVT_COMMAND_AUINOTEBOOK_DRAG_MOTION,
		wxAuiNotebookEventHandler(PX2wxAuiNotebook::DragFun_Motion));
	Connect(wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED,
		wxAuiNotebookEventHandler(PX2wxAuiNotebook::Tab_Click));
}
//----------------------------------------------------------------------------
PX2wxAuiNotebook::~PX2wxAuiNotebook()
{
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::DragFun_Begin(wxAuiNotebookEvent &evt)
{
	Freeze();
	wxAuiTabCtrl* src_tabs = (wxAuiTabCtrl*)evt.GetEventObject();
	if (src_tabs)
	{
		int numPages = m_tabs.GetPageCount();

		if (numPages > 1)
		{
			src_tabs->SetCursor(wxCursor(wxCURSOR_ARROW));
			int src_idx = evt.GetSelection();
			wxWindow *window = GetPage(src_idx);
			RemovePage(src_idx);
			Update();

			Event *ent = NirvanaEventSpace::CreateEventX(NirvanaEventSpace::TabDrag);
			ent->SetData<wxWindow*>(window);
			PX2_EW.BroadcastingLocalEvent(ent);
		}
		
		UpdateTabsHeight();
		Thaw();
		Refresh();
	}
	
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::DragFun_End(wxAuiNotebookEvent &ent)
{
	PX2_UNUSED(ent);
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::DragFun_Motion(wxAuiNotebookEvent &ent)
{
	PX2_UNUSED(ent);
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::Tab_Click(wxAuiNotebookEvent &ent)
{
	int numPages = m_tabs.GetPageCount();

	if (numPages > 1)
	{
		wxAuiManager *auiMan = E_MainFrame::GetSingleton().GetAuiMananger();
		if (auiMan)
		{
			int src_idx = ent.GetSelection();
			wxString title = GetPageText(src_idx);
			wxString paneName = "Right";
			auiMan->GetPane(paneName).caption = title;
			auiMan->Update();
		}
	}
}
//----------------------------------------------------------------------------
void PX2wxAuiNotebook::UpdateTabsHeight()
{
	if (!mIsCenter)
	{
		int numPages = m_tabs.GetPageCount();
		if (1 == numPages)
		{
			SetTabCtrlHeight(0);
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// PX2wxAuiToolBar
//----------------------------------------------------------------------------
PX2wxAuiToolBar::PX2wxAuiToolBar()
{
}
//----------------------------------------------------------------------------
PX2wxAuiToolBar::PX2wxAuiToolBar(wxWindow* parent,
	wxWindowID id,
	const wxPoint& pos,
	const wxSize& size,
	long style)
	:
	wxAuiToolBar(parent, id, pos, size, style)
{
}
//----------------------------------------------------------------------------
PX2wxAuiToolBar::~PX2wxAuiToolBar()
{
}
//----------------------------------------------------------------------------
wxAuiToolBarItemArray PX2wxAuiToolBar::GetItems()
{
	return m_items;
}
//----------------------------------------------------------------------------
void PX2wxAuiToolBar::SetItemsState(int state)
{
	size_t i, count;
	for (i = 0, count = m_items.GetCount(); i < count; ++i)
	{
		wxAuiToolBarItem& item = m_items.Item(i);
		item.SetState(state);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// PX2wxAuiToolBarArt
//----------------------------------------------------------------------------
PX2wxAuiToolBarArt::PX2wxAuiToolBarArt()
{
}
//----------------------------------------------------------------------------
PX2wxAuiToolBarArt::~PX2wxAuiToolBarArt()
{

}
//----------------------------------------------------------------------------
void PX2wxAuiToolBarArt::DrawBackground(
	wxDC& dc,
	wxWindow*,
	const wxRect& _rect)
{
	wxRect rect = _rect;
	rect.height++;

	Theme *theme = PX2_EDIT.GetEditParams()->GetCurTheme();
	if (theme)
	{
		wxColour color = Float3TowxColour(theme->Color_AuiToolBar_Background);
		dc.GradientFillLinear(rect, color, color, wxALL);
	}
}
//----------------------------------------------------------------------------
void PX2wxAuiToolBarArt::DrawPlainBackground(wxDC& dc,
	wxWindow*,
	const wxRect& _rect)
{
	wxRect rect = _rect;
	rect.height++;

	Theme *theme = PX2_EDIT.GetEditParams()->GetCurTheme();
	if (theme)
	{
		dc.SetBrush(Float3TowxColour(theme->Color_AuiToolbar_PlainBackgound));

		dc.DrawRectangle(
			rect.GetX() - 1, 
			rect.GetY() - 1,
			rect.GetWidth() + 2,
			rect.GetHeight() + 1);
	}
}
//----------------------------------------------------------------------------
void PX2wxAuiToolBarArt::DrawSeparator(wxDC& dc, wxWindow* wnd,
	const wxRect& _rect)
{
	bool horizontal = true;
	if (m_flags & wxAUI_TB_VERTICAL)
		horizontal = false;

	wxRect rect = _rect;

	if (horizontal)
	{
		rect.x += (rect.width / 2);
		rect.width = 1;
		int new_height = (rect.height * 3) / 4;
		rect.y += (rect.height / 2) - (new_height / 2);
		rect.height = new_height;
	}
	else
	{
		rect.y += (rect.height / 2);
		rect.height = 1;
		int new_width = (rect.width * 3) / 4;
		rect.x += (rect.width / 2) - (new_width / 2);
		rect.width = new_width;
	}

	Theme *theme = PX2_EDIT.GetEditParams()->GetCurTheme();
	if (theme)
	{
		dc.GradientFillLinear(rect,
			Float3TowxColour(theme->Color_AuiToolbar_Separator),
			Float3TowxColour(theme->Color_AuiToolbar_Separator),
			wxALL);
	}
}
//----------------------------------------------------------------------------
static const unsigned char
DISABLED_TEXT_GREY_HUE = wxColour::AlphaBlend(0, 255, 0.4);
const wxColour DISABLED_TEXT_COLOR(DISABLED_TEXT_GREY_HUE,
	DISABLED_TEXT_GREY_HUE,
	DISABLED_TEXT_GREY_HUE);
//----------------------------------------------------------------------------
void PX2wxAuiToolBarArt::DrawButton(wxDC& dc,
	wxWindow* wnd,
	const wxAuiToolBarItem& item,
	const wxRect& rect)
{
	int textWidth = 0, textHeight = 0;

	if (m_flags & wxAUI_TB_TEXT)
	{
		dc.SetFont(m_font);

		int tx, ty;

		dc.GetTextExtent(wxT("ABCDHgj"), &tx, &textHeight);
		textWidth = 0;
		dc.GetTextExtent(item.GetLabel(), &textWidth, &ty);
	}

	int bmpX = 0, bmpY = 0;
	int textX = 0, textY = 0;

	if (m_textOrientation == wxAUI_TBTOOL_TEXT_BOTTOM)
	{
		bmpX = rect.x +
			(rect.width / 2) -
			(item.GetBitmap().GetWidth() / 2);

		bmpY = rect.y +
			((rect.height - textHeight) / 2) -
			(item.GetBitmap().GetHeight() / 2);

		textX = rect.x + (rect.width / 2) - (textWidth / 2) + 1;
		textY = rect.y + rect.height - textHeight - 1;
	}
	else if (m_textOrientation == wxAUI_TBTOOL_TEXT_RIGHT)
	{
		bmpX = rect.x + 3;

		bmpY = rect.y +
			(rect.height / 2) -
			(item.GetBitmap().GetHeight() / 2);

		textX = bmpX + 3 + item.GetBitmap().GetWidth();
		textY = rect.y +
			(rect.height / 2) -
			(textHeight / 2);
	}

	if (!(item.GetState() & wxAUI_BUTTON_STATE_DISABLED))
	{
		if (item.GetState() & wxAUI_BUTTON_STATE_PRESSED)
		{
			dc.SetPen(wxPen(m_highlightColour));
			dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(150)));
			dc.DrawRectangle(rect);
		}
		else if ((item.GetState() & wxAUI_BUTTON_STATE_HOVER) || item.IsSticky())
		{
			dc.SetPen(wxPen(m_highlightColour));
			dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(170)));

			// draw an even lighter background for checked item hovers (since
			// the hover background is the same color as the check background)
			if (item.GetState() & wxAUI_BUTTON_STATE_CHECKED)
				dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(180)));

			dc.DrawRectangle(rect);
		}
		else if (item.GetState() & wxAUI_BUTTON_STATE_CHECKED)
		{
			// it's important to put this code in an else statement after the
			// hover, otherwise hovers won't draw properly for checked items
			dc.SetPen(wxPen(m_highlightColour));
			dc.SetBrush(wxBrush(m_highlightColour.ChangeLightness(170)));
			dc.DrawRectangle(rect);
		}
	}

	wxBitmap bmp;
	if (item.GetState() & wxAUI_BUTTON_STATE_DISABLED)
		bmp = item.GetDisabledBitmap();
	else
		bmp = item.GetBitmap();

	if (bmp.IsOk())
		dc.DrawBitmap(bmp, bmpX, bmpY, true);

	// set the item's text color based on if it is disabled
	Theme *theme = PX2_EDIT.GetEditParams()->GetCurTheme();
	if (theme)
	{
		dc.SetTextForeground(Float3TowxColour(theme->Color_AuiToolbar_Text));

		if (item.GetState() & wxAUI_BUTTON_STATE_DISABLED)
			dc.SetTextForeground(DISABLED_TEXT_COLOR);

		if ((m_flags & wxAUI_TB_TEXT) && !item.GetLabel().empty())
		{
			dc.DrawText(item.GetLabel(), textX, textY);
		}
	}

}
//----------------------------------------------------------------------------
void PX2wxAuiToolBarArt::DrawOverflowButton(
	wxDC& dc,
	wxWindow* wnd,
	const wxRect& rect,
	int state)
{
	if (state & wxAUI_BUTTON_STATE_HOVER ||
		state & wxAUI_BUTTON_STATE_PRESSED)
	{
		Theme *theme = PX2_EDIT.GetEditParams()->GetCurTheme();
		if (theme)
		{
			dc.SetPen(wxPen(Float3TowxColour(theme->Color_AuiToolbar_FlowBorder)));
			dc.DrawLine(rect.x, rect.y, rect.x, rect.y + rect.height);

			dc.SetPen(wxPen(Float3TowxColour(theme->Color_AuiToolbar_Flow)));
			dc.SetBrush(wxBrush(Float3TowxColour(theme->Color_AuiToolbar_Flow)));
			dc.DrawRectangle(rect.x + 1, rect.y, rect.width, rect.height);
		}
	}

	int x = rect.x + 1 + (rect.width - m_overflowBmp.GetWidth()) / 2;
	int y = rect.y + 1 + (rect.height - m_overflowBmp.GetHeight()) / 2;
	dc.DrawBitmap(m_overflowBmp, x, y, true);
}
//----------------------------------------------------------------------------
void PX2wxAuiToolBarArt::SetHightlightColor(wxColour color)
{
	m_highlightColour = color;
}
//----------------------------------------------------------------------------
PX2wxAuiTabArt::PX2wxAuiTabArt(bool isTop)
{
	if (isTop)
		m_fixedTabWidth = 80;
	else
		m_fixedTabWidth = 40;
	
	mIsCenter = isTop;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// PX2wxAuiTabArt
//----------------------------------------------------------------------------
PX2wxAuiTabArt::~PX2wxAuiTabArt()
{
}
//----------------------------------------------------------------------------
wxAuiTabArt* PX2wxAuiTabArt::Clone()
{
	return new PX2wxAuiTabArt(*this);
}
//----------------------------------------------------------------------------
void PX2wxAuiTabArt::SetSizingInfo(const wxSize& tab_ctrl_size,
	size_t tab_count)
{
	if (mIsCenter)
		m_fixedTabWidth = 120;
	else
		m_fixedTabWidth = 60;

	PX2_UNUSED(tab_ctrl_size);
	PX2_UNUSED(tab_count);
}
//----------------------------------------------------------------------------
void PX2wxAuiTabArt::DrawBorder(wxDC& dc, wxWindow* wnd, const wxRect& rect)
{
	int i, border_width = GetBorderWidth(wnd);

	wxRect theRect(rect);
	for (i = 0; i < border_width; ++i)
	{
		Theme *theme = PX2_EDIT.GetEditParams()->GetCurTheme();
		if (theme)
		{
			if (mIsCenter)
			{
				dc.SetBrush(wxBrush(Float3TowxColour(theme->Color_Aui_Border_Center)));
				dc.SetPen(wxPen(Float3TowxColour(theme->Color_Aui_Border_Center)));
			}
			else
			{
				dc.SetBrush(wxBrush(Float3TowxColour(theme->Color_Aui_Border)));
				dc.SetPen(wxPen(Float3TowxColour(theme->Color_Aui_Border)));
			}
		}

		dc.DrawRectangle(theRect.x, theRect.y, theRect.width, theRect.height);
		theRect.Deflate(1);
	}
}
//----------------------------------------------------------------------------
void PX2wxAuiTabArt::DrawBackground(wxDC& dc, wxWindow*,
	const wxRect& rect)
{
	Theme *theme = PX2_EDIT.GetEditParams()->GetCurTheme();
	if (theme)
	{
		dc.SetBrush(wxBrush(Float3TowxColour(theme->Color_Aui_Background)));
		dc.DrawRectangle(-1, -5, rect.GetWidth() + 2, rect.GetHeight() + 5);

		// draw base line
		if (mIsCenter)
		{
			dc.SetBrush(wxBrush(Float3TowxColour(theme->Color_AuiTabbar_Active)));
			dc.SetPen(wxPen(Float3TowxColour(theme->Color_AuiTabbar_Active)));
			dc.DrawRectangle(-1, rect.GetHeight() - 2, rect.GetWidth() + 2, 2);
		}
	}
}
//----------------------------------------------------------------------------
static void DrawButtons(wxDC& dc,
	const wxRect& _rect,
	const wxBitmap& bmp,
	const wxColour& bkcolour,
	int button_state)
{
	wxRect rect = _rect;

	if (button_state == wxAUI_BUTTON_STATE_PRESSED)
	{
		rect.x++;
		rect.y++;
	}

	if (button_state == wxAUI_BUTTON_STATE_HOVER ||
		button_state == wxAUI_BUTTON_STATE_PRESSED)
	{
		dc.SetBrush(wxBrush(bkcolour.ChangeLightness(120)));
		dc.SetPen(wxPen(bkcolour.ChangeLightness(75)));

		// draw the background behind the button
		dc.DrawRectangle(rect.x, rect.y, 15, 15);
	}

	// draw the button itself
	dc.DrawBitmap(bmp, rect.x, rect.y, true);
}
//----------------------------------------------------------------------------
wxString wxAuiChopText(wxDC& dc, const wxString& text, int max_size);
//----------------------------------------------------------------------------
void PX2wxAuiTabArt::DrawTab(wxDC& dc,
	wxWindow* wnd,
	const wxAuiNotebookPage& page,
	const wxRect& in_rect,
	int close_button_state,
	wxRect* out_tab_rect,
	wxRect* out_button_rect,
	int* x_extent)
{
	wxCoord normal_textx, normal_texty;
	wxCoord selected_textx, selected_texty;
	wxCoord textx, texty;

	// if the caption is empty, measure some temporary text
	wxString caption = page.caption;
	if (caption.empty())
		caption = wxT("Xj");

	dc.SetFont(m_selectedFont);
	dc.GetTextExtent(caption, &selected_textx, &selected_texty);

	dc.SetFont(m_normalFont);
	dc.GetTextExtent(caption, &normal_textx, &normal_texty);

	// figure out the size of the tab
	wxSize tab_size = GetTabSize(dc,
		wnd,
		page.caption,
		page.bitmap,
		page.active,
		close_button_state,
		x_extent);

	wxCoord tab_height = tab_size.y;
	wxCoord tab_width = tab_size.x;
	wxCoord tab_x = in_rect.x;
	wxCoord tab_y = in_rect.y + in_rect.height - tab_height;

	caption = page.caption;

	// select pen, brush and font for the tab to be drawn
	Theme *theme = PX2_EDIT.GetEditParams()->GetCurTheme();
	if (theme)
	{
		if (page.active)
		{
			if (mIsCenter)
			{
				dc.SetPen(wxPen(Float3TowxColour(theme->Color_AuiTabbar_Active)));
				dc.SetBrush(Float3TowxColour(theme->Color_AuiTabbar_Active));
				dc.SetFont(m_selectedFont);
			}
			else
			{
				dc.SetPen(wxPen(Float3TowxColour(theme->Color_AuiTabbar_Active)));
				dc.SetBrush(Float3TowxColour(theme->Color_AuiTabbar_Active));
				dc.SetFont(m_selectedFont);
			}

			textx = selected_textx;
			texty = selected_texty;
		}
		else
		{
			dc.SetPen(wxPen(Float3TowxColour(theme->Color_AuiTabbar)));
			dc.SetBrush(Float3TowxColour(theme->Color_AuiTabbar));
			dc.SetFont(m_normalFont);

			textx = normal_textx;
			texty = normal_texty;
		}
	}
	
	// -- draw line --

	wxPoint points[5];
	points[0].x = tab_x;
	points[0].y = tab_y;
	points[1].x = tab_x + tab_width;
	points[1].y = tab_y;
	points[2].x = tab_x + tab_width;
	points[2].y = tab_y + tab_height;
	points[3].x = tab_x;
	points[3].y = tab_y + tab_height;
	points[4] = points[0];

	if (mIsCenter)
	{
		points[0].y -= 7;
		points[1].y -= 7;

		points[2].y -= 3;
		points[3].y -= 3;
	}
	else
	{
		points[0].y -= 8;
		points[1].y -= 8;

		points[2].y -= 4;
		points[3].y -= 4;
	}

	dc.SetClippingRegion(in_rect);
	dc.DrawPolygon(WXSIZEOF(points) - 1, points);

	int text_offset;
	int close_button_width = 0;
	if (close_button_state != wxAUI_BUTTON_STATE_HIDDEN)
	{
		close_button_width = m_activeCloseBmp.GetWidth();
		text_offset = tab_x + ((tab_width - close_button_width) / 2) - (textx / 2);
	}
	else
	{
		text_offset = tab_x + (tab_width - textx)/ 2 ;
	}

	if (theme)
	{
		if (page.active)
		{
			if (mIsCenter)
			{
				dc.SetTextForeground(Float3TowxColour(theme->Color_AuiTabbarText_Active));
			}
			else
			{
				dc.SetTextForeground(Float3TowxColour(theme->Color_AuiTabbarText_Active));
			}
		}
		else
		{
			dc.SetTextForeground(Float3TowxColour(theme->Color_AuiTabbarText));
		}
	}
	
	// chop text if necessary
	wxString draw_text = wxAuiChopText(dc,
		caption,
		tab_width - (text_offset - tab_x) - close_button_width);

	// draw tab text
	dc.DrawText(draw_text,
		text_offset,
		(tab_y + tab_height - texty) / 2);

	// draw focus rectangle
	if (page.active && (wnd->FindFocus() == wnd))
	{
		wxRect focusRect(text_offset, ((tab_y + tab_height) / 2 - (texty / 2) + 1),
			selected_textx, selected_texty);

		focusRect.Inflate(2, 2);

		wxRendererNative::Get().DrawFocusRect(wnd, dc, focusRect, 0);
	}

	// draw close button if necessary
	if (close_button_state != wxAUI_BUTTON_STATE_HIDDEN)
	{
		wxBitmap bmp;
		if (page.active)
			bmp = m_activeCloseBmp;
		else
			bmp = m_disabledCloseBmp;

		wxRect rect(tab_x + tab_width - close_button_width - 1,
			tab_y + (tab_height / 2) - (bmp.GetHeight() / 2) + 1,
			close_button_width,
			tab_height - 1);
		DrawButtons(dc, rect, bmp, *wxWHITE, close_button_state);

		*out_button_rect = rect;
	}


	*out_tab_rect = wxRect(tab_x, tab_y, tab_width, tab_height);

	dc.DestroyClippingRegion();	
}
//----------------------------------------------------------------------------
void PX2wxAuiTabArt::DrawButton(wxDC& dc,
	wxWindow* WXUNUSED(wnd),
	const wxRect& in_rect,
	int bitmap_id,
	int button_state,
	int orientation,
	wxRect* out_rect)
{
	wxBitmap bmp;
	wxRect rect;

	switch (bitmap_id)
	{
	case wxAUI_BUTTON_CLOSE:
		if (button_state & wxAUI_BUTTON_STATE_DISABLED)
			bmp = m_disabledCloseBmp;
		else
			bmp = m_activeCloseBmp;
		break;
	case wxAUI_BUTTON_LEFT:
		if (button_state & wxAUI_BUTTON_STATE_DISABLED)
			bmp = m_disabledLeftBmp;
		else
			bmp = m_activeLeftBmp;
		break;
	case wxAUI_BUTTON_RIGHT:
		if (button_state & wxAUI_BUTTON_STATE_DISABLED)
			bmp = m_disabledRightBmp;
		else
			bmp = m_activeRightBmp;
		break;
	case wxAUI_BUTTON_WINDOWLIST:
		if (button_state & wxAUI_BUTTON_STATE_DISABLED)
			bmp = m_disabledWindowListBmp;
		else
			bmp = m_activeWindowListBmp;
		break;
	}

	if (!bmp.IsOk())
		return;

	rect = in_rect;

	if (orientation == wxLEFT)
	{
		rect.SetX(in_rect.x);
		rect.SetY(((in_rect.y + in_rect.height) / 2) - (bmp.GetHeight() / 2));
		rect.SetWidth(bmp.GetWidth());
		rect.SetHeight(bmp.GetHeight());
	}
	else
	{
		rect = wxRect(in_rect.x + in_rect.width - bmp.GetWidth(),
			((in_rect.y + in_rect.height) / 2) - (bmp.GetHeight() / 2),
			bmp.GetWidth(), bmp.GetHeight());
	}


	DrawButtons(dc, rect, bmp, wxColour(255, 242, 244), button_state);

	*out_rect = rect;
}
//----------------------------------------------------------------------------
wxSize PX2wxAuiTabArt::GetTabSize(wxDC& dc,
	wxWindow* WXUNUSED(wnd),
	const wxString& caption,
	const wxBitmap& WXUNUSED(bitmap),
	bool WXUNUSED(active),
	int closeButtonState,
	int* xExtent)
{
	wxCoord measured_textx, measured_texty;

	dc.SetFont(m_measuringFont);
	dc.GetTextExtent(caption, &measured_textx, &measured_texty);

	wxCoord tab_height = measured_texty + 1;
	wxCoord tab_width = measured_textx  + 6;

	if (closeButtonState != wxAUI_BUTTON_STATE_HIDDEN)
		tab_width += m_activeCloseBmp.GetWidth();

	if (m_flags & wxAUI_NB_TAB_FIXED_WIDTH)
	{
		tab_width = m_fixedTabWidth;
	}

	*xExtent = tab_width + 1;

	return wxSize(tab_width, tab_height);
}
//----------------------------------------------------------------------------
