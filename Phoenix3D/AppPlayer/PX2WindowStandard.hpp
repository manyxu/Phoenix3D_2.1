// PX2WindowStandard.hpp

#ifndef PX2WINDOWSTANDARD_HPP
#define PX2WINDOWSTANDARD_HPP

#include "PX2UIWindow.hpp"

namespace PX2
{

	class WindowStandard : public UIWindow
	{
	public:
		WindowStandard();
		virtual ~WindowStandard();
	};
	typedef Pointer0<WindowStandard> WindowStandardPtr;

}

#endif