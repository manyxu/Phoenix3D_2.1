// PX2UIPaintManager_Win.hpp

#ifndef PX2UIPAINTMANAGER_WIN_HPP
#define PX2UIPAINTMANAGER_WIN_HPP

#include "PX2UIPaintManager.hpp"
#include "PX2UIPre.hpp"

namespace PX2
{

	class UIPaintManager_Win : public UIPaintManager
	{
	public:
		UIPaintManager_Win();
		virtual ~UIPaintManager_Win();

		void Init();

	protected:
		HWND mHWndPaint;
		HDC mHDCPaint;
		HDC mHDCOffscreen;
		HBITMAP mHBMPOffscreen;
		HWND mHWndTooltip;
	};

}

#endif