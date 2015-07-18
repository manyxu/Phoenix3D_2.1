// PX2PAppImplWindows.hpp

#ifndef PX2APPIMPLWINDOWS_HPP
#define PX2APPIMPLWINDOWS_HPP

#include "PX2PAppImpl.hpp"
#include <windows.h>

namespace PX2
{

	class PAppImplWindows : public PAppImpl
	{
	public:
		PAppImplWindows();
		virtual ~PAppImplWindows();

		virtual void Run();
	
	public_internal:
		bool _TranslateMessage(LPMSG msg);
	};

}

#endif
