// PX2E_TopView.hpp

#ifndef PX2E_TOPVIEW_HPP
#define PX2E_TOPVIEW_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class TopView : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(TopView)

	public:
		TopView(wxWindow *parent);
		virtual ~TopView();

	protected:
		DECLARE_EVENT_TABLE()
		TopView();
	};

}

#endif