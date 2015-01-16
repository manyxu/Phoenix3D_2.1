// PX2E_MainFrame.hpp

#ifndef PX2E_MAINFRAME_HPP
#define PX2E_MAINFRAME_HPP

#include "PX2wxFrame.hpp"

namespace PX2Editor
{

	class E_MainFrame : public PX2WXFrame
	{
	public:
		E_MainFrame(const std::string &title, int xPos, int yPos,
			int width, int height);
		virtual ~E_MainFrame();

	protected:
		virtual void OnTimer_Update();
		virtual void OnSize_Update(const PX2::Sizef &size);
	};

}

#endif