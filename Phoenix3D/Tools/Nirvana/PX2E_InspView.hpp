// PX2E_InspView.hpp

#ifndef PX2E_INSPVIEW_HPP
#define PX2E_INSPVIEW_HPP

#include "PX2EditorPre.hpp"
#include "PX2Actor.hpp"
#include "PX2EventHandler.hpp"
#include "PX2wxAui.hpp"

namespace PX2Editor
{

	class ObjectInspector;

	class InspView : public wxWindow, public PX2::EventHandler
	{
	public:
		InspView(wxWindow *parent);
		~InspView();

		virtual void DoExecute(PX2::Event *event);

	protected:
		DECLARE_EVENT_TABLE()

		void _SetObject(PX2::Object *object);
		void _ChangeToWindow(std::string strTag, int userData = 0);

		PX2::ObjectPtr mObject;
		std::string mStrTag;
		wxBoxSizer *mCurSizer;
		PX2wxAuiToolBar *mInspTreeBar;
		ObjectInspector *mCurWindow;
	};

}

#endif