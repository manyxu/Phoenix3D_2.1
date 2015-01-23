// PX2E_TimeLineRender.hpp

#ifndef PX2E_TIMELINERENDER_HPP
#define PX2E_TIMELINERENDER_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class TimeLineRender : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(TimeLineRender)

	public:
		TimeLineRender(wxWindow *parent);
		~TimeLineRender();

	protected:
		DECLARE_EVENT_TABLE()

		TimeLineRender();
	};

}

#endif