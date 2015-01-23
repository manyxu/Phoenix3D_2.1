// PX2E_TimeLineView.hpp

#ifndef PX2E_TIMELINEVIEW_HPP
#define PX2E_TIMELINEVIEW_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class TimeLineView : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(TimeLineView)

	public:
		TimeLineView(wxWindow *parent);
		~TimeLineView();

	protected:
		DECLARE_EVENT_TABLE()

		TimeLineView();

		wxToolBar *TimeLineBar;
	};

}

#endif