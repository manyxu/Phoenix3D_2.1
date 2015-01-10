// PX2UIWindowImpl.hpp

#ifndef PX2UIWINDOWIMPL_HPP
#define PX2UIWINDOWIMPL_HPP

#include "PX2UIPre.hpp"
#include "PX2Rect.hpp"
#include "PX2UIDefine.hpp"
#include "PX2SmartPointer.hpp"

namespace PX2
{

	class UIWindow;

	class UIWindowImpl
	{
	public:
		UIWindowImpl(UIWindow *window);
		virtual ~UIWindowImpl();

		void SetClassStyle(UIClassType stype);
		UIClassType GetClassStype() const;
		void SetClassName(const std::string &className);
		const std::string &GetClassName() const;

		virtual UIWindowImpl *Create(UIWindowImpl *parent, 
			const std::string &name, UIWindowStyle style, 
			const Rectf &rect) = 0;

		virtual void ShowWindow(bool show, bool takeFocus) = 0;
		virtual bool ShowModal() = 0;
		virtual void Close() = 0;
		virtual void CenterWindow() = 0;

		virtual void SetIcon(unsigned int res) = 0;

	protected:
		UIWindowImpl();

		UIClassType mClassType;
		std::string mClassName;
		bool mIsSubclassed;

		UIWindow *mWindow;
	};
	typedef Pointer0<UIWindowImpl> UIWindowImplPtr;

}

#endif