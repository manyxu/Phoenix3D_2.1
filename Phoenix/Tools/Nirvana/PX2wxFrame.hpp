/*
*
* ÎÄ¼þÃû³Æ	£º	PX2wxFrame.hpp
*
*/

#ifndef PX2WXMAINFRAME_HPP
#define PX2WXMAINFRAME_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class PX2WXFrame : public wxFrame
	{
	public:
		PX2WXFrame(const std::string &title, int xPos, int yPos, 
			int width, int height);
		virtual ~PX2WXFrame();

		void OnTimer(wxTimerEvent& e);
		void OnSize(wxSizeEvent& e);
		void OnMotion(wxMouseEvent& e);
		void OnEnterWindow(wxMouseEvent& e);
		void OnLeaveWindow(wxMouseEvent& e);
		void OnLeftDown(wxMouseEvent& e);
		void OnLeftUp(wxMouseEvent& e);

	protected:
		virtual void OnTimer_Update();

	protected:
		DECLARE_EVENT_TABLE()
		bool _CalIsInSizingRange();
		void _Sizing();
		int _CalSizeDir(const wxRect &frameRect, const wxSize &borderSize,
			const wxPoint &mousePos);

		wxTimer mTimer;

		bool mIsMouseDown_Left;

		wxSize mBorderSize;
		wxRect mBeforeSizingRect;
		bool mIsDoSizing;
		int mSizeDir;
	};

}

#endif