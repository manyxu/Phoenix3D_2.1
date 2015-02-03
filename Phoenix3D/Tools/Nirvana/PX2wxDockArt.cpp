/*
*
* ÎÄ¼þÃû³Æ	£º	PX2NwxDockArt.cpp
*
*/

#include "PX2wxDockArt.hpp"
#include "PX2Edit.hpp"
#include "PX2EditParams.hpp"
using namespace PX2;

wxColor wxAuiLightContrastColour1(const wxColour& c)
{
	int amount = 120;

	// if the color is especially dark, then
	// make the contrast even lighter
	if (c.Red() < 128 && c.Green() < 128 && c.Blue() < 128)
		amount = 160;

	return c.ChangeLightness(amount);
}

// wxAuiBitmapFromBits1() is a utility function that creates a
// masked bitmap from raw bits (XBM format)
wxBitmap wxAuiBitmapFromBits1(const unsigned char bits[], int w, int h,
	const wxColour& color)
{
	wxImage img = wxBitmap((const char*)bits, w, h).ConvertToImage();
	img.Replace(0, 0, 0, 123, 123, 123);
	img.Replace(255, 255, 255, color.Red(), color.Green(), color.Blue());
	img.SetMaskColour(123, 123, 123);
	return wxBitmap(img);
}

wxString wxAuiChopText1(wxDC& dc, const wxString& text, int max_size)
{
	wxCoord x, y;

	// first check if the text fits with no problems
	dc.GetTextExtent(text, &x, &y);
	if (x <= max_size)
		return text;

	size_t i, len = text.Length();
	size_t last_good_length = 0;
	for (i = 0; i < len; ++i)
	{
		wxString s = text.Left(i);
		s += wxT("...");

		dc.GetTextExtent(s, &x, &y);
		if (x > max_size)
			break;

		last_good_length = i;
	}

	wxString ret = text.Left(last_good_length);
	ret += wxT("...");
	return ret;
}

PX2wxDockArt::PX2wxDockArt()
{
#if defined( __WXMAC__ ) && wxOSX_USE_COCOA_OR_CARBON
	wxColor baseColour = wxColour(wxMacCreateCGColorFromHITheme(kThemeBrushToolbarBackground));
#else
	wxColor baseColour = wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE);
#endif

	// the baseColour is too pale to use as our base colour,
	// so darken it a bit --
	if ((255 - baseColour.Red()) +
		(255 - baseColour.Green()) +
		(255 - baseColour.Blue()) < 60)
	{
		baseColour = baseColour.ChangeLightness(92);
	}

	m_baseColour = baseColour;
	wxColor darker1Colour = baseColour.ChangeLightness(85);
	wxColor darker2Colour = baseColour.ChangeLightness(75);
	wxColor darker3Colour = baseColour.ChangeLightness(60);
	//wxColor darker4Colour = baseColour.ChangeLightness(50);
	wxColor darker5Colour = baseColour.ChangeLightness(40);

	m_activeCaptionColour = wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT);
	m_activeCaptionGradientColour = wxAuiLightContrastColour1(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	m_activeCaptionTextColour = wxColor(117, 99, 61);

	m_inactiveCaptionColour = darker1Colour;
	m_inactiveCaptionGradientColour = baseColour.ChangeLightness(97);
	m_inactiveCaptionTextColour = wxColor(206, 212, 221);

	m_sashBrush = wxBrush(baseColour);
	m_backgroundBrush = wxBrush(baseColour);
	m_gripperBrush = wxBrush(baseColour);

	m_borderPen = wxPen(darker2Colour);
	m_gripperPen1 = wxPen(darker5Colour);
	m_gripperPen2 = wxPen(darker3Colour);
	m_gripperPen3 = *wxWHITE_PEN;

	m_captionFont = *wxNORMAL_FONT;

	// default metric values
#if defined( __WXMAC__ ) && wxOSX_USE_COCOA_OR_CARBON
	SInt32 height;
	GetThemeMetric(kThemeMetricSmallPaneSplitterHeight, &height);
	m_sashSize = height;
#elif defined(__WXGTK__)
	m_sashSize = wxRendererNative::Get().GetSplitterParams(NULL).widthSash;
#else
	m_sashSize = 4;
#endif
	m_captionSize = 17;
	m_borderSize = 1;
	m_buttonSize = 14;
	m_gripperSize = 9;
	m_gradientType = wxAUI_GRADIENT_VERTICAL;

	InitBitmaps();
}

void
PX2wxDockArt::InitBitmaps()
{
	// some built in bitmaps
#if defined( __WXMAC__ )
	static const unsigned char close_bits[] = {
		0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFE, 0x03, 0xF8, 0x01, 0xF0, 0x19, 0xF3,
		0xB8, 0xE3, 0xF0, 0xE1, 0xE0, 0xE0, 0xF0, 0xE1, 0xB8, 0xE3, 0x19, 0xF3,
		0x01, 0xF0, 0x03, 0xF8, 0x0F, 0xFE, 0xFF, 0xFF };
#elif defined(__WXGTK__)
	static const unsigned char close_bits[] = {
		0xff, 0xff, 0xff, 0xff, 0x07, 0xf0, 0xfb, 0xef, 0xdb, 0xed, 0x8b, 0xe8,
		0x1b, 0xec, 0x3b, 0xee, 0x1b, 0xec, 0x8b, 0xe8, 0xdb, 0xed, 0xfb, 0xef,
		0x07, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
#else
	static const unsigned char close_bits[] = {
		// reduced height, symmetric
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xf3, 0x9f, 0xf9,
		0x3f, 0xfc, 0x7f, 0xfe, 0x3f, 0xfc, 0x9f, 0xf9, 0xcf, 0xf3, 0xff, 0xff,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
	/*
	// same height as maximize/restore
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xe7, 0xcf, 0xf3, 0x9f, 0xf9,
	0x3f, 0xfc, 0x7f, 0xfe, 0x3f, 0xfc, 0x9f, 0xf9, 0xcf, 0xf3, 0xe7, 0xe7,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
	*/
#endif

	static const unsigned char maximize_bits[] = {
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xf0, 0xf7, 0xf7, 0x07, 0xf0,
		0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0xf7, 0x07, 0xf0,
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

	static const unsigned char restore_bits[] = {
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xf0, 0x1f, 0xf0, 0xdf, 0xf7,
		0x07, 0xf4, 0x07, 0xf4, 0xf7, 0xf5, 0xf7, 0xf1, 0xf7, 0xfd, 0xf7, 0xfd,
		0x07, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

	static const unsigned char pin_bits[] = {
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xfc, 0xdf, 0xfc, 0xdf, 0xfc,
		0xdf, 0xfc, 0xdf, 0xfc, 0xdf, 0xfc, 0x0f, 0xf8, 0x7f, 0xff, 0x7f, 0xff,
		0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

#ifdef __WXMAC__
	m_inactiveCloseBitmap = wxAuiBitmapFromBits1(close_bits, 16, 16, *wxWHITE);
	m_activeCloseBitmap = wxAuiBitmapFromBits1(close_bits, 16, 16, *wxWHITE);
#else
	m_inactiveCloseBitmap = wxAuiBitmapFromBits1(close_bits, 16, 16, m_inactiveCaptionTextColour);
	m_activeCloseBitmap = wxAuiBitmapFromBits1(close_bits, 16, 16, m_activeCaptionTextColour);
#endif

#ifdef __WXMAC__
	m_inactiveMaximizeBitmap = wxAuiBitmapFromBits1(maximize_bits, 16, 16, *wxWHITE);
	m_activeMaximizeBitmap = wxAuiBitmapFromBits1(maximize_bits, 16, 16, *wxWHITE);
#else
	m_inactiveMaximizeBitmap = wxAuiBitmapFromBits1(maximize_bits, 16, 16, m_inactiveCaptionTextColour);
	m_activeMaximizeBitmap = wxAuiBitmapFromBits1(maximize_bits, 16, 16, m_activeCaptionTextColour);
#endif

#ifdef __WXMAC__
	m_inactiveRestoreBitmap = wxAuiBitmapFromBits1(restore_bits, 16, 16, *wxWHITE);
	m_activeRestoreBitmap = wxAuiBitmapFromBits1(restore_bits, 16, 16, *wxWHITE);
#else
	m_inactiveRestoreBitmap = wxAuiBitmapFromBits1(restore_bits, 16, 16, m_inactiveCaptionTextColour);
	m_activeRestoreBitmap = wxAuiBitmapFromBits1(restore_bits, 16, 16, m_activeCaptionTextColour);
#endif

	m_inactivePinBitmap = wxAuiBitmapFromBits1(pin_bits, 16, 16, m_inactiveCaptionTextColour);
	m_activePinBitmap = wxAuiBitmapFromBits1(pin_bits, 16, 16, m_activeCaptionTextColour);
}

int PX2wxDockArt::GetMetric(int id)
{
	switch (id)
	{
	case wxAUI_DOCKART_SASH_SIZE:          return m_sashSize;
	case wxAUI_DOCKART_CAPTION_SIZE:       return m_captionSize;
	case wxAUI_DOCKART_GRIPPER_SIZE:       return m_gripperSize;
	case wxAUI_DOCKART_PANE_BORDER_SIZE:   return m_borderSize;
	case wxAUI_DOCKART_PANE_BUTTON_SIZE:   return m_buttonSize;
	case wxAUI_DOCKART_GRADIENT_TYPE:      return m_gradientType;
	default: wxFAIL_MSG(wxT("Invalid Metric Ordinal")); break;
	}

	return 0;
}

void PX2wxDockArt::SetMetric(int id, int new_val)
{
	switch (id)
	{
	case wxAUI_DOCKART_SASH_SIZE:          m_sashSize = new_val; break;
	case wxAUI_DOCKART_CAPTION_SIZE:       m_captionSize = new_val; break;
	case wxAUI_DOCKART_GRIPPER_SIZE:       m_gripperSize = new_val; break;
	case wxAUI_DOCKART_PANE_BORDER_SIZE:   m_borderSize = new_val; break;
	case wxAUI_DOCKART_PANE_BUTTON_SIZE:   m_buttonSize = new_val; break;
	case wxAUI_DOCKART_GRADIENT_TYPE:      m_gradientType = new_val; break;
	default: wxFAIL_MSG(wxT("Invalid Metric Ordinal")); break;
	}
}

wxColour PX2wxDockArt::GetColour(int id)
{
	switch (id)
	{
	case wxAUI_DOCKART_BACKGROUND_COLOUR:                return m_backgroundBrush.GetColour();
	case wxAUI_DOCKART_SASH_COLOUR:                      return m_sashBrush.GetColour();
	case wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR:          return m_inactiveCaptionColour;
	case wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR: return m_inactiveCaptionGradientColour;
	case wxAUI_DOCKART_INACTIVE_CAPTION_TEXT_COLOUR:     return m_inactiveCaptionTextColour;
	case wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR:            return m_activeCaptionColour;
	case wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR:   return m_activeCaptionGradientColour;
	case wxAUI_DOCKART_ACTIVE_CAPTION_TEXT_COLOUR:       return m_activeCaptionTextColour;
	case wxAUI_DOCKART_BORDER_COLOUR:                    return m_borderPen.GetColour();
	case wxAUI_DOCKART_GRIPPER_COLOUR:                   return m_gripperBrush.GetColour();
	default: wxFAIL_MSG(wxT("Invalid Metric Ordinal")); break;
	}

	return wxColour();
}

void PX2wxDockArt::SetColour(int id, const wxColor& colour)
{
	switch (id)
	{
	case wxAUI_DOCKART_BACKGROUND_COLOUR:                m_backgroundBrush.SetColour(colour); break;
	case wxAUI_DOCKART_SASH_COLOUR:                      m_sashBrush.SetColour(colour); break;
	case wxAUI_DOCKART_INACTIVE_CAPTION_COLOUR:          m_inactiveCaptionColour = colour; break;
	case wxAUI_DOCKART_INACTIVE_CAPTION_GRADIENT_COLOUR: m_inactiveCaptionGradientColour = colour; break;
	case wxAUI_DOCKART_INACTIVE_CAPTION_TEXT_COLOUR:     m_inactiveCaptionTextColour = colour; break;
	case wxAUI_DOCKART_ACTIVE_CAPTION_COLOUR:            m_activeCaptionColour = colour; break;
	case wxAUI_DOCKART_ACTIVE_CAPTION_GRADIENT_COLOUR:   m_activeCaptionGradientColour = colour; break;
	case wxAUI_DOCKART_ACTIVE_CAPTION_TEXT_COLOUR:       m_activeCaptionTextColour = colour; break;
	case wxAUI_DOCKART_BORDER_COLOUR:                    m_borderPen.SetColour(colour); break;
	case wxAUI_DOCKART_GRIPPER_COLOUR:
		m_gripperBrush.SetColour(colour);
		m_gripperPen1.SetColour(colour.ChangeLightness(40));
		m_gripperPen2.SetColour(colour.ChangeLightness(60));
		break;
	default: wxFAIL_MSG(wxT("Invalid Metric Ordinal")); break;
	}

	InitBitmaps();
}

void PX2wxDockArt::SetFont(int id, const wxFont& font)
{
	if (id == wxAUI_DOCKART_CAPTION_FONT)
		m_captionFont = font;
}

wxFont PX2wxDockArt::GetFont(int id)
{
	if (id == wxAUI_DOCKART_CAPTION_FONT)
		return m_captionFont;
	return wxNullFont;
}

void PX2wxDockArt::DrawSash(wxDC& dc, wxWindow *window, int orientation, const wxRect& rect)
{
#if defined( __WXMAC__ ) && wxOSX_USE_COCOA_OR_CARBON
	wxUnusedVar(window);
	wxUnusedVar(orientation);

	HIRect splitterRect = CGRectMake(rect.x, rect.y, rect.width, rect.height);
	CGContextRef cgContext;
	wxGCDCImpl *impl = (wxGCDCImpl*)dc.GetImpl();
	cgContext = (CGContextRef)impl->GetGraphicsContext()->GetNativeContext();

	HIThemeSplitterDrawInfo drawInfo;
	drawInfo.version = 0;
	drawInfo.state = kThemeStateActive;
	drawInfo.adornment = kHIThemeSplitterAdornmentNone;
	HIThemeDrawPaneSplitter(&splitterRect, &drawInfo, cgContext, kHIThemeOrientationNormal);

#elif defined(__WXGTK__)
	// clear out the rectangle first
	dc.SetPen(*wxTRANSPARENT_PEN);
	dc.SetBrush(m_sashBrush);
	dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);

#if 0
	GdkRectangle gdk_rect;
	if (orientation == wxVERTICAL)
	{
		gdk_rect.x = rect.x;
		gdk_rect.y = rect.y;
		gdk_rect.width = m_sashSize;
		gdk_rect.height = rect.height;
	}
	else
	{
		gdk_rect.x = rect.x;
		gdk_rect.y = rect.y;
		gdk_rect.width = rect.width;
		gdk_rect.height = m_sashSize;
	}
#endif

	if (!window) return;
	if (!window->m_wxwindow) return;
	if (!gtk_widget_is_drawable(window->m_wxwindow)) return;

	gtk_paint_handle
		(
		gtk_widget_get_style(window->m_wxwindow),
#ifdef __WXGTK3__
		static_cast<cairo_t*>(dc.GetGraphicsContext()->GetNativeContext()),
#else
		window->GTKGetDrawingWindow(),
#endif
		// flags & wxCONTROL_CURRENT ? GTK_STATE_PRELIGHT : GTK_STATE_NORMAL,
		GTK_STATE_NORMAL,
		GTK_SHADOW_NONE,
#ifndef __WXGTK3__
		NULL /* no clipping */,
#endif
		window->m_wxwindow,
		"paned",
		rect.x,
		rect.y,
		rect.width,
		rect.height,
		(orientation == wxVERTICAL) ? GTK_ORIENTATION_VERTICAL : GTK_ORIENTATION_HORIZONTAL
		);

#else
	wxUnusedVar(window);
	wxUnusedVar(orientation);
	dc.SetPen(*wxTRANSPARENT_PEN);
	dc.SetBrush(m_sashBrush);
	dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);
#endif
}


void PX2wxDockArt::DrawBackground(wxDC& dc, wxWindow *WXUNUSED(window), int, const wxRect& rect)
{
	dc.SetPen(*wxTRANSPARENT_PEN);
#ifdef __WXMAC__
	// we have to clear first, otherwise we are drawing a light striped pattern
	// over an already darker striped background
	dc.SetBrush(*wxWHITE_BRUSH);
	dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);
#endif
	dc.SetBrush(m_backgroundBrush);
	dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);
}

void PX2wxDockArt::DrawBorder(wxDC& dc, wxWindow* window, const wxRect& _rect,
	wxAuiPaneInfo& pane)
{
	dc.SetPen(m_borderPen);
	dc.SetBrush(*wxTRANSPARENT_BRUSH);

	wxRect rect = _rect;
	int i, border_width = GetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE);

	if (pane.IsToolbar())
	{
		for (i = 0; i < border_width; ++i)
		{
			dc.SetPen(*wxWHITE_PEN);
			dc.DrawLine(rect.x, rect.y, rect.x + rect.width, rect.y);
			dc.DrawLine(rect.x, rect.y, rect.x, rect.y + rect.height);
			dc.SetPen(m_borderPen);
			dc.DrawLine(rect.x, rect.y + rect.height - 1,
				rect.x + rect.width, rect.y + rect.height - 1);
			dc.DrawLine(rect.x + rect.width - 1, rect.y,
				rect.x + rect.width - 1, rect.y + rect.height);
			rect.Deflate(1);
		}
	}
	else
	{
		// notebooks draw the border themselves, so they can use native rendering (e.g. tabartgtk)
		wxAuiTabArt* art = 0;
		wxAuiNotebook* nb = wxDynamicCast(window, wxAuiNotebook);
		if (nb)
			art = nb->GetArtProvider();

		if (art)
			art->DrawBorder(dc, window, rect);
		else
		{
			for (i = 0; i < border_width; ++i)
			{
				dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);
				rect.Deflate(1);
			}
		}
	}
}

void PX2wxDockArt::DrawCaptionBackground(wxDC& dc, const wxRect& rect, bool active)
{
	dc.SetBrush(wxBrush(wxColour(142, 155, 188)));
	dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height+5);

	if (active)
		dc.SetBrush(wxBrush(m_activeCaptionColour));
	else
		dc.SetBrush(wxBrush(m_inactiveCaptionColour));

	dc.DrawRectangle(rect.x+1, rect.y+1, rect.width-2, rect.height-1);
}

void PX2wxDockArt::DrawCaption(wxDC& dc, wxWindow *WXUNUSED(window),
	const wxString& text,
	const wxRect& rect,
	wxAuiPaneInfo& pane)
{
	dc.SetPen(*wxTRANSPARENT_PEN);
	dc.SetFont(m_captionFont);

	DrawCaptionBackground(dc, rect,
		(pane.state & wxAuiPaneInfo::optionActive) ? true : false);

	int caption_offset = 0;
	if (pane.icon.IsOk())
	{
		DrawIcon(dc, rect, pane);

		caption_offset += pane.icon.GetWidth() + 3;
	}
	EditParams *params = PX2_EDIT.GetEditParams();
	if (params)
	{
		EditParams::Theme theme = params->GetCurTheme();

		if (pane.state & wxAuiPaneInfo::optionActive)
		{
			float r = theme.captionActColor[0] * 255.0f;
			float g = theme.captionActColor[1] * 255.0f;
			float b = theme.captionActColor[2] * 255.0f;
			dc.SetTextForeground(wxColour(r, g, b));
		}		
		else
		{
			float r = theme.captionColor[0] * 255.0f;
			float g = theme.captionColor[1] * 255.0f;
			float b = theme.captionColor[2] * 255.0f;
			dc.SetTextForeground(wxColour(r, g, b));
		}	
	}

	wxCoord w, h;
	dc.GetTextExtent(wxT("ABCDEFHXfgkj"), &w, &h);

	wxRect clip_rect = rect;
	clip_rect.width -= 3; // text offset
	clip_rect.width -= 2; // button padding
	if (pane.HasCloseButton())
		clip_rect.width -= m_buttonSize;
	if (pane.HasPinButton())
		clip_rect.width -= m_buttonSize;
	if (pane.HasMaximizeButton())
		clip_rect.width -= m_buttonSize;

	wxString draw_text = wxAuiChopText1(dc, text, clip_rect.width);

	dc.SetClippingRegion(clip_rect);
	dc.DrawText(draw_text, rect.x + 3 + caption_offset, rect.y + (rect.height / 2) - (h / 2) - 1);
	dc.DestroyClippingRegion();
}

void
PX2wxDockArt::DrawIcon(wxDC& dc, const wxRect& rect, wxAuiPaneInfo& pane)
{
	// Draw the icon centered vertically
	dc.DrawBitmap(pane.icon,
		rect.x + 8, rect.y + (rect.height - pane.icon.GetHeight()) / 2,
		true);
}

void PX2wxDockArt::DrawGripper(wxDC& dc, wxWindow *WXUNUSED(window),
	const wxRect& rect,
	wxAuiPaneInfo& pane)
{
	dc.SetPen(*wxTRANSPARENT_PEN);
	dc.SetBrush(m_gripperBrush);

	dc.DrawRectangle(rect.x, rect.y, rect.width, rect.height);

	if (!pane.HasGripperTop())
	{
		int y = 5;
		while (1)
		{
			dc.SetPen(m_gripperPen1);
			dc.DrawPoint(rect.x + 3, rect.y + y);
			dc.SetPen(m_gripperPen2);
			dc.DrawPoint(rect.x + 3, rect.y + y + 1);
			dc.DrawPoint(rect.x + 4, rect.y + y);
			dc.SetPen(m_gripperPen3);
			dc.DrawPoint(rect.x + 5, rect.y + y + 1);
			dc.DrawPoint(rect.x + 5, rect.y + y + 2);
			dc.DrawPoint(rect.x + 4, rect.y + y + 2);

			y += 4;
			if (y > rect.GetHeight() - 5)
				break;
		}
	}
	else
	{
		int x = 5;
		while (1)
		{
			dc.SetPen(m_gripperPen1);
			dc.DrawPoint(rect.x + x, rect.y + 3);
			dc.SetPen(m_gripperPen2);
			dc.DrawPoint(rect.x + x + 1, rect.y + 3);
			dc.DrawPoint(rect.x + x, rect.y + 4);
			dc.SetPen(m_gripperPen3);
			dc.DrawPoint(rect.x + x + 1, rect.y + 5);
			dc.DrawPoint(rect.x + x + 2, rect.y + 5);
			dc.DrawPoint(rect.x + x + 2, rect.y + 4);

			x += 4;
			if (x > rect.GetWidth() - 5)
				break;
		}
	}
}

void PX2wxDockArt::DrawPaneButton(wxDC& dc, wxWindow *WXUNUSED(window),
	int button,
	int button_state,
	const wxRect& _rect,
	wxAuiPaneInfo& pane)
{
	wxBitmap bmp;
	if (!(&pane))
		return;
	switch (button)
	{
	default:
	case wxAUI_BUTTON_CLOSE:
		if (pane.state & wxAuiPaneInfo::optionActive)
			bmp = m_activeCloseBitmap;
		else
			bmp = m_inactiveCloseBitmap;
		break;
	case wxAUI_BUTTON_PIN:
		if (pane.state & wxAuiPaneInfo::optionActive)
			bmp = m_activePinBitmap;
		else
			bmp = m_inactivePinBitmap;
		break;
	case wxAUI_BUTTON_MAXIMIZE_RESTORE:
		if (pane.IsMaximized())
		{
			if (pane.state & wxAuiPaneInfo::optionActive)
				bmp = m_activeRestoreBitmap;
			else
				bmp = m_inactiveRestoreBitmap;
		}
		else
		{
			if (pane.state & wxAuiPaneInfo::optionActive)
				bmp = m_activeMaximizeBitmap;
			else
				bmp = m_inactiveMaximizeBitmap;
		}
		break;
	}

	wxRect rect = _rect;

	int old_y = rect.y;
	rect.y = rect.y + (rect.height / 2) - (bmp.GetHeight() / 2);
	rect.height = old_y + rect.height - rect.y - 1;


	if (button_state == wxAUI_BUTTON_STATE_PRESSED)
	{
		rect.x++;
		rect.y++;
	}

	if (button_state == wxAUI_BUTTON_STATE_HOVER ||
		button_state == wxAUI_BUTTON_STATE_PRESSED)
	{
		if (pane.state & wxAuiPaneInfo::optionActive)
		{
			dc.SetBrush(wxBrush(m_activeCaptionColour.ChangeLightness(50)));
			dc.SetPen(wxPen(m_activeCaptionColour.ChangeLightness(70)));
		}
		else
		{
			dc.SetBrush(wxBrush(m_inactiveCaptionColour.ChangeLightness(50)));
			dc.SetPen(wxPen(m_inactiveCaptionColour.ChangeLightness(70)));
		}

		// draw the background behind the button
		dc.DrawRectangle(rect.x, rect.y, 15, 15);
	}

	dc.DrawBitmap(bmp, rect.x, rect.y, true);
}