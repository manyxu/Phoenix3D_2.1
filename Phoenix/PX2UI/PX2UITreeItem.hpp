// PX2UITreeItem.hpp

#ifndef PX2UITREEITEM_HPP
#define PX2UITREEITEM_HPP

#include "PX2UISizeFrame.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIText.hpp"
#include "PX2UIButton.hpp"

namespace PX2
{

	class UITreeItem : public UISizeFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(UITreeItem);

	public:
		UITreeItem();
		~UITreeItem();

		virtual void OnSizeChanged();

	protected:
		UIButtonPtr mBT_Arrow;
		UIPicBoxPtr mPB_Icon;
		UITextPtr mT_Text;

		std::vector<Pointer0<UITreeItem> > mChildItems;
	};

	PX2_REGISTER_STREAM(UITreeItem);
	typedef Pointer0<UITreeItem> UITreeItemPtr;

}

#endif