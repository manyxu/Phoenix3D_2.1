// PX2UIWindow_Win.hpp

#ifndef PX2UIWINDOW_WIN_HPP
#define PX2UIWINDOW_WIN_HPP

#include "PX2UIWindow.hpp"

namespace PX2
{

	class UIWindow_Win : public UIWindow
	{
	public:
		UIWindow_Win();
		~UIWindow_Win();

		HWND GetHWND() const;

		HWND Create(UIWindow *parent, const std::string &name,
			unsigned long stype, unsigned long exStyle, const Rectf &rect);
		HWND Create(HWND hwndParent, LPCTSTR pstrName, DWORD dwStyle, DWORD dwExStyle, int x, int y, int cx, int cy, HMENU hMenu);

		HWND Subcalss(HWND hWnd);
		virtual void UnSubclass();

		virtual void ShowWindow(bool show = true, bool takeFocus = true);
		virtual bool ShowModal();
		virtual void Close();
		virtual void CenterWindow();

		virtual void SetIcon(unsigned int res);

	protected:
		virtual LPCTSTR GetWindowClassName() const = 0;
		virtual LPCTSTR GetSuperClassName() const;
		virtual unsigned int GetClassStyle() const;

		LRESULT SendMessage(UINT uMsg, WPARAM wParam = 0, LPARAM lParam = 0);
		LRESULT PostMessage(UINT uMsg, WPARAM wParam = 0, LPARAM lParam = 0);

		bool RegisterWindowClass();
		bool RegisterSuperclass();
		static LRESULT CALLBACK __WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK __ControlProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		HWND mHWnd;
		WNDPROC mOldWndProc;
	};

}

#endif