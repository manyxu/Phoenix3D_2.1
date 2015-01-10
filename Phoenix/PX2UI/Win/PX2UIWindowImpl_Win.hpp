// PX2UIWindowIMPL_Win.hpp

#ifndef PX2UIWINDOWIMPL_WIN_HPP
#define PX2UIWINDOWIMPL_WIN_HPP

#include "PX2UIWindowImpl.hpp"

namespace PX2
{

	class UIWindowImpl_Win : public UIWindowImpl
	{
	public:
		UIWindowImpl_Win(UIWindow *window);
		virtual ~UIWindowImpl_Win();

		virtual UIWindowImpl *Create(UIWindowImpl *parent, const std::string &name,
			UIWindowStyle style, const Rectf &rect);

		HWND Subcalss(HWND hWnd);

		virtual void UnSubclass();

		virtual void ShowWindow(bool show = true, bool takeFocus = true);
		virtual bool ShowModal();
		virtual void Close();
		virtual void CenterWindow();

		virtual void SetIcon(unsigned int res);

	public_internal:
		HWND GetHWND() const;

	protected:
		UIWindowImpl_Win();

		HWND Create(HWND hwndParent, LPCTSTR pstrName, DWORD dwStyle, DWORD dwExStyle, int x, int y, int cx, int cy, HMENU hMenu);

		virtual LPCTSTR GetSuperClassName() const;

		LRESULT SendMessage(UINT uMsg, WPARAM wParam = 0, LPARAM lParam = 0);
		LRESULT PostMessage(UINT uMsg, WPARAM wParam = 0, LPARAM lParam = 0);

		bool RegisterWindowClass();
		bool RegisterSuperclass();

		virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual void OnFinalMessage(HWND hWnd);

		static LRESULT CALLBACK __WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK __ControlProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		HWND mHWnd;
		WNDPROC mOldWndProc;
	};

}

#endif