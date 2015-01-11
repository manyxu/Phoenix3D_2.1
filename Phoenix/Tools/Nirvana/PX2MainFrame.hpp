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

	protected:
		DECLARE_EVENT_TABLE()
	};

}

#endif