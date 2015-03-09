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
		RenderView_Cot(PX2::RenderViewType type, wxWindow *parent);
		virtual ~RenderView_Cot();

		RenderView *GetRenderView();

	protected:
		DECLARE_EVENT_TABLE()

		RenderView_Cot();
		wxAuiToolBar *_CreateRenderViewBar(PX2::RenderViewType type);

		wxAuiToolBar *mRenderViewBar;
		RenderView *mRenderView;
	};

}

#endif