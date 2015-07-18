// PX2PWinImplWindows.hpp

#ifndef PX2PWINIMPLWINDOWS_HPP
#define PX2PWINIMPLWINDOWS_HPP

#include "PX2PWinImpl.hpp"
#include <windows.h>

namespace PX2
{

	class PWinImplWindows : public PWinImpl
	{
	public:
		PWinImplWindows();
		virtual ~PWinImplWindows();

		const std::string &GetSuperClassName() const;
		const std::string &GetWindowClassName() const;

		virtual void Create(PWinImpl *parent, const std::string &tilte,
			const Vector2f &pos, const Sizef &size);

		virtual void Show(bool show);

	protected:
		bool _RegisterSuperClass();
		bool _RegisterWindowClass();
		static LRESULT CALLBACK _WndProc(HWND hWnd, UINT uMsg, WPARAM wParam,
			LPARAM lParam);

		HWND mhWnd;
		std::string mSuperClassName;
		std::string mWindowClassName;
	};

}

#endif