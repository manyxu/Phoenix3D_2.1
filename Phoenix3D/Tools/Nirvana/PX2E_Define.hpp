// PX2EditorDefine.hpp

#ifndef PX2EDITORDEFINE_HPP
#define PX2EDITORDEFINE_HPP

#include "PX2EditorPre.hpp"
#include "PX2APoint.hpp"
#include "PX2Float3.hpp"

enum RenderViewType
{
	RVT_SCENEUI,
	RVT_LOGIC,
	RVT_RES,
	RVT_PREVIEW,
	RVT_TIMELINE,
	RVT_MAX_TYPE
};

inline PX2::APoint wxPointToAPoint(wxPoint &point, wxSize &size)
{
	return PX2::APoint((float)point.x, 0.0f, (float)(size.GetHeight() - point.y));
}

inline wxColour Float3TowxColour(const PX2::Float3 &color)
{
	return wxColour((unsigned char)(color[0] * 255.0f),
		unsigned char(color[1] * 255.0f), unsigned char(color[2] * 255.0f));
}

struct PinData
{
public:
	PinData()
	{
		TheBook = 0;
		TheWindow = 0;
	}
	~PinData()
	{
	}

	wxAuiNotebook *TheBook;
	wxWindow *TheWindow;
	wxPoint Pos;
	wxSize Size;
	wxString Caption;
};

#endif