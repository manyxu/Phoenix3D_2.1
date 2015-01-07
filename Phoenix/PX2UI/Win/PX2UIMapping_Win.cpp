// PX2UIMapping_Win.cpp

#include "PX2UIMapping_Win.hpp"
#include "PX2UIPre.hpp"

namespace PX2
{

	//----------------------------------------------------------------------------
	unsigned int gUIWindowStype[UIWS_MAX_TYPE] =
	{
		0,
		(WS_VISIBLE | WS_OVERLAPPEDWINDOW),
		(WS_VISIBLE | WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN),
		(WS_VISIBLE | WS_POPUPWINDOW | WS_CAPTION | WS_DLGFRAME | WS_CLIPSIBLINGS | WS_CLIPCHILDREN),
		(WS_EX_WINDOWEDGE),
		(WS_EX_TOOLWINDOW | WS_EX_DLGMODALFRAME)
	};
	//----------------------------------------------------------------------------

}