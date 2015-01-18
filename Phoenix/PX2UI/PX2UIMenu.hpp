// PX2UIMenu.hpp

#ifndef PX2UIMENU_HPP
#define PX2UIMENU_HPP

#include "PX2UISizeFrame.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIMenuItem.hpp"

namespace PX2
{

	class UIMenuBar : public UISizeFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UIMenuBar);
	public:
		UIMenuBar();
		virtual ~UIMenuBar();

		UIPicBox *GetBackPicBox();

		void AddItem(UIMenuItem *item);

		virtual void OnParentSizeChanged(const Sizef &parentSize,
			const Sizef &parentBorderSize);

	protected:
		void _SortItemsPos();

		UIPicBoxPtr mPB_Back;
	};

	PX2_REGISTER_STREAM(UIMenuBar);
	typedef Pointer0<UIMenuBar> UIMenuBarPtr;

}

#endif