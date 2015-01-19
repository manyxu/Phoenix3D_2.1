// PX2E_RenderView.hpp

#ifndef PX2E_RENDERVIEW_HPP
#define PX2E_RENDERVIEW_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class RenderView : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(RenderView)

	public:
		RenderView(wxWindow *parent);
		virtual ~RenderView();

	protected:
		DECLARE_EVENT_TABLE()

		RenderView();
	};

}

#endif