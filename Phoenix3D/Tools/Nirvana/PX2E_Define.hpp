// PX2EditorDefine.hpp

#ifndef PX2EDITORDEFINE_HPP
#define PX2EDITORDEFINE_HPP

#include "PX2EditorPre.hpp"
#include "PX2APoint.hpp"

enum RenderViewType
{
	RVT_SCENEUI,
	RVT_LOGIC,
	RVT_RES,
	RVT_TIMELINE,
	RVT_MAX_TYPE
};

inline PX2::APoint wxPointToAPoint(wxPoint &point, wxSize &size)
{
	return PX2::APoint((float)point.x, 0.0f, (float)(size.GetHeight() - point.y));
}

#endif