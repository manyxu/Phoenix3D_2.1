// PX2UIPre.hpp

#ifndef PX2UIPRE_HPP
#define PX2UIPRE_HPP

#include "PX2CorePre.hpp"
#include "PX2Rect.hpp"

#if defined(_WIN32) || defined(WIN32)

#include <windows.h>
#include <CommCtrl.h>
#include <tchar.h>
#include <zmouse.h>
#include <windowsx.h>
#include <WinUser.h>
#include <mstcpip.h>

namespace PX2
{

	inline RECT RectfToRECT(const Rectf &rect)
	{
		RECT rc;
		rc.left = (LONG)rect.Left;
		rc.right = (LONG)rect.Right;
		rc.bottom = (LONG)rect.Bottom;
		rc.top = (LONG)rect.Top;

		return rc;
	}

	inline Rectf RECTToRectf(RECT rc)
	{
		Rectf rcf;
		rcf.Left = (float)rc.left;
		rcf.Right = (float)rc.right;
		rcf.Bottom = (float)rc.bottom;
		rcf.Top = (float)rc.top;

		return rcf;
	}

}

#endif

#endif