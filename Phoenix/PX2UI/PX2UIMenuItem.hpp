// PX2UIMenuItem.hpp

#ifndef PX2UIMENUITEM_HPP
#define PX2UIMENUITEM_HPP

#include "PX2UISizeFrame.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIText.hpp"

namespace PX2
{

	class UIMenuItem : public UISizeFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UIMenuItem);

	public:
		UIMenuItem(const std::string &name, const std::string &text);
		~UIMenuItem();

		virtual void OnSizeChanged();

	protected:
		UIPicBoxPtr mPB_Over;
		UIPicBoxPtr mPB_Pressed;
		UITextPtr mT_Text;
	};

	PX2_REGISTER_STREAM(UIMenuItem);
	typedef Pointer0<UIMenuItem> UIMenuItemPtr;

}

#endif