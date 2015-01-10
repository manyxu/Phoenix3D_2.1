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

		virtual void SetPlatformData(void *data);
		void SetResourceInstance(HINSTANCE hInst);
		HINSTANCE GetResourceInstance();

		COLORREF GetColor(UITYPE_COLOR index) const;
		bool GetColorPair(UITYPE_COLOR index, COLORREF& clr1, COLORREF& clr2) const;
		HPEN GetPen(UITYPE_COLOR index) const;
		HFONT GetFont(UITYPE_FONT index) const;
		HBRUSH GetBrush(UITYPE_COLOR index) const;
		HICON GetIcon(int index, int cxySize) const;

		void Init(HWND hWnd);

		void Invalidate(const Rectf &rcItem);

		HDC GetPaintDC() const;
		HWND GetPaintWindow() const;

		Sizef GetClientSize() const;

		void UpdateLayout();
		void Invalidate(RECT rcItem);

		virtual void Run();

		static bool TranslateMessage(const LPMSG pMsg);

	protected:
		HWND mHWndPaint;
		HDC mHDCPaint;
		HDC mHDCOffscreen;
		HBITMAP mHBMPOffscreen;
		HWND mHWndTooltip;

		unsigned int mMsgMouseWheel;

		HINSTANCE mHInstance;
	};

}

#endif