// PX2UIBase.hpp

#ifndef PX2UIBASE_HPP
#define PX2UIBASE_HPP

#include "PX2UIPre.hpp"
#include "PX2Rect.hpp"

namespace PX2
{

	class UIWindow
	{
	public:
		UIWindow();
		virtual ~UIWindow();

		virtual UIWindow *Create(UIWindow *parent, const std::string &name,
			unsigned long stype, unsigned long exStyle, const Rectf &rect) = 0;

		virtual UIWindow *Subcalss(UIWindow *window) = 0;
		virtual void UnSubclass() = 0;

		virtual void ShowWindow(bool show = true, bool takeFocus = true) = 0;
		virtual bool ShowModal() = 0;
		virtual void Close() = 0;
		virtual void CenterWindow() = 0;

		virtual void SetIcon(unsigned int res) = 0;
	};

}

#endif