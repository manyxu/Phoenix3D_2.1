// PX2InspView.hpp

#ifndef PX2INSPVIEW_HPP
#define PX2INSPVIEW_HPP

#include "PX2EditorPre.hpp"
#include "PX2Actor.hpp"
#include "PX2EventHandler.hpp"

namespace PX2Editor
{

	class InspView : public wxWindow, public PX2::EventHandler
	{
	public:
		InspView(wxWindow *parent);
		~InspView();

		void OnSize(wxSizeEvent& e);

		virtual void DoExecute(PX2::Event *event);

	protected:
		DECLARE_EVENT_TABLE()

		void _SetObject(PX2::Object *object);
		void _ChangeToWindow(std::string strTag, int userData = 0);

		PX2::ObjectPtr mObject;
		std::string mStrTag;
		wxWindow *mCurWindow;
	};

}

#endif