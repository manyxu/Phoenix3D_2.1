// PX2E_RenderView.hpp

#ifndef PX2E_RENDERVIEW_HPP
#define PX2E_RENDERVIEW_HPP

#include "PX2EditorPre.hpp"
#include "PX2EditRenderView.hpp"
#include "PX2EventHandler.hpp"
#include "PX2E_Define.hpp"
#include "PX2EditDefine.hpp"

namespace PX2Editor
{

	class RenderView : public wxWindow, public PX2::EventHandler
	{
		DECLARE_DYNAMIC_CLASS(RenderView)

	public:
		RenderView(PX2::RenderViewType viewType, wxWindow *parent);
		virtual ~RenderView();

		void OnTimer(wxTimerEvent& event);
		void OnSize(wxSizeEvent& e);
		void OnPaint(wxPaintEvent& e);
		void OnEraseBackground(wxEraseEvent& rEvent);
		void OnEnterWindow(wxMouseEvent& e);
		void OnLeaveWindow(wxMouseEvent& e);
		void OnLeftDown(wxMouseEvent& e);
		void OnLeftUp(wxMouseEvent& e);
		void OnLeftDoubleClick(wxMouseEvent& e);
		void OnMiddleDown(wxMouseEvent& e);
		void OnMiddleUp(wxMouseEvent& e);
		void OnMouseWheel(wxMouseEvent& e);
		void OnRightDown(wxMouseEvent& e);
		void OnRightUp(wxMouseEvent& e);
		void OnMotion(wxMouseEvent& e);
		void OnKeyDown(wxKeyEvent& e);
		void OnKeyUp(wxKeyEvent& e);

		void OnMenuItem(wxCommandEvent &e);

		virtual void DoExecute(PX2::Event *event);

	protected:
		DECLARE_EVENT_TABLE()

		RenderView();

	public_internal:
		void _CloseEidtRenderView(const std::string &name);
		void _NewEditRenderView(const std::string &name);

	protected:
		bool mIsInited;

		PX2::RenderViewType mRenderViewType;

		int mTimerID;
		wxTimer mTimer;
		std::map<std::string, PX2::EditRenderViewPtr> mEditRenderViews;
		wxSize mSize;

		wxMenu *mEditMenu;
		bool mIsRightDown;
		bool mIsRightDownOnMotion;
	};

}

#endif