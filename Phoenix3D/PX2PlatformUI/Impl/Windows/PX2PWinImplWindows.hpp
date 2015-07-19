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
		virtual void *GetWinHandle();

		virtual void Show(bool show, bool takeFocus);
		virtual void ShowModal();

		virtual void CenterWindow();

		virtual void Minimize();
		virtual void Maximize();
		virtual void Restore();

	public_internal:
		void SetNeedUpdate();

	protected:
		bool _RegisterSuperClass();
		bool _RegisterWindowClass();
		static LRESULT CALLBACK _WndProc(HWND hWnd, UINT uMsg, WPARAM wParam,
			LPARAM lParam);
		virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
		bool _MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lRes);
		virtual void OnFinalMessage(HWND hWnd);

		LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

		HWND mhWnd;
		HDC mhDcPaint;
		HDC mhDcOffscreen;
		HDC mhDcBackground;
		HBITMAP mhbmpOffscreen;
		HBITMAP mhbmpBackground;
		HPEN mhUpdateRectPen;

		bool mIsUpdateNeeded;
		bool mIsOffScreenPaint;
		bool mIsAlphaBackground;

		WNDPROC mOldWndProc;
		std::string mSuperClassName;
		std::string mWindowClassName;
	};

}

#endif