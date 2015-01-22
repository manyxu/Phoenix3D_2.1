// PX2E_PreView.hpp

#ifndef PX2E_PREVIEW_HPP
#define PX2E_PREVIEW_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class PreView : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(PreView)

	public:
		PreView(wxWindow *parent);
		virtual ~PreView();

	protected:
		DECLARE_EVENT_TABLE()

		PreView();
	};

}

#endif