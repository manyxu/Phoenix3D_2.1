// PX2WindowMain.hpp

#ifndef PX2WINDOWMAIN_HPP
#define PX2WINDOWMAIN_HPP

#include "PX2UIWindow.hpp"

namespace PX2
{

	class WindowMain : public UIWindow
	{
	public:
		WindowMain();
		virtual ~WindowMain();

		void CreateWindows();

	protected:
	};
	typedef Pointer0<WindowMain> WindowMainPtr;

}

#endif