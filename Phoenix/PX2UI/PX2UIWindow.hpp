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

<<<<<<< HEAD
=======
		virtual UIWindow *Create(UIWindow *parent, const std::string &name,
			unsigned long stype, unsigned long exStyle, const Rectf &rect) = 0;

		virtual UIWindow *Subcalss(UIWindow *window) = 0;
		virtual void UnSubclass() = 0;

>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
		virtual void ShowWindow(bool show = true, bool takeFocus = true) = 0;
		virtual bool ShowModal() = 0;
		virtual void Close() = 0;
		virtual void CenterWindow() = 0;

		virtual void SetIcon(unsigned int res) = 0;
<<<<<<< HEAD

	protected:
		bool mIsSubclassed;
=======
>>>>>>> d7d7322973c15255a2595ab89885b4ef0270c6ca
	};

}

#endif