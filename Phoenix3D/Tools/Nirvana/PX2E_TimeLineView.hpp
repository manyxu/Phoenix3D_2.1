// PX2E_TimeLineView.hpp

#ifndef PX2E_TIMELINEVIEW_HPP
#define PX2E_TIMELINEVIEW_HPP

#include "PX2EditorPre.hpp"
#include "PX2EditParams.hpp"
#include "PX2E_TimeLineRender.hpp"

namespace PX2Editor
{

	class PX2wxAuiToolBar;

	class TimeLineView : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(TimeLineView)

	public:
		TimeLineView(wxWindow *parent);
		~TimeLineView();

		void SetTheme(PX2::Theme *theme);

	protected:
		DECLARE_EVENT_TABLE()

		TimeLineView();

		PX2wxAuiToolBar *mTimeLineBar;
		TimeLineRender *mTimeLineRender;
		wxSearchCtrl *mSearchCtrl;
	};

}

#endif