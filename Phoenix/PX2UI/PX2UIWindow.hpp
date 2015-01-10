// PX2UIWindow.hpp

#ifndef PX2UIBASE_HPP
#define PX2UIBASE_HPP

#include "PX2UIPre.hpp"
#include "PX2Rect.hpp"
#include "PX2UIDefine.hpp"
#include "PX2UIWindowImpl.hpp"

namespace PX2
{

	class UIWindow
	{
	public:
		UIWindow();
		virtual ~UIWindow();

		void SetClassStyle(UIClassType stype);
		UIClassType GetClassStype() const;
		void SetClassName(const std::string &className);
		const std::string &GetClassName() const;

		virtual void Create(UIWindow *parent, const std::string &name, UIWindowStyle style, const Rectf &rect);
		void Close();

		virtual void ShowWindow(bool show = true, bool takeFocus = true);
		virtual bool ShowModal();
		virtual void CenterWindow();

		virtual void SetIcon(unsigned int res);

	public_internal:
		UIWindowImpl *GetImpl();

	protected:
		UIWindowImplPtr mImpl;
	};
	typedef Pointer0<UIWindow> UIWindowPtr;
#include "PX2UIWindow.inl"

}

#endif