/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EditorFrame.hpp
*
*/

#ifndef PX2MAINFRAME_HPP
#define PX2MAINFRAME_HPP

#include "PX2EditorPre.hpp"

namespace PX2Editor
{

	class MainFrame : public wxFrame
	{
	public:
		MainFrame(const std::string &title, int xPos, int yPos, 
			int width, int height);
		virtual ~MainFrame();

		void OnTimer(wxTimerEvent& event);
		void OnSize(wxSizeEvent& e);
		void OnMotion(wxMouseEvent& e);
		void OnEnterWindow(wxMouseEvent& e);
		void OnLeaveWindow(wxMouseEvent& e);
		void OnLeftDown(wxMouseEvent& e);
		void OnLeftUp(wxMouseEvent& e);

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