// PX2E_RenderView_Cont.hpp

#ifndef PX2E_RENDERVIEW_CONT_HPP
#define PX2E_RENDERVIEW_CONT_HPP

#include "PX2EditorPre.hpp"
#include "PX2E_RenderView.hpp"

namespace PX2Editor
{

	class RenderView_Cot : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(RenderView_Cot)

	public:
		RenderView_Cot(RenderView::RenderViewType type, wxWindow *parent);
		virtual ~RenderView_Cot();

		RenderView *GetRenderView();

	protected:
		DECLARE_EVENT_TABLE()

		RenderView_Cot();

		wxToolBar *mRenderViewBar;
		RenderView *mRenderView;
	};

}

#endif