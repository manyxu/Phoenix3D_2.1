// PX2EditSceneTreeItem.hpp

#ifndef PX2EDITSCENETREEITEM_HPP
#define PX2EDITSCENETREEITEM_HPP

#include "PX2UISizeFrame.hpp"
#include "PX2UITreeItem.hpp"

namespace PX2
{

	class EditSceneTreeItem : public UITreeItem
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(EditSceneTreeItem);

	public:
		EditSceneTreeItem();
		virtual ~EditSceneTreeItem();
	};

	PX2_REGISTER_STREAM(EditSceneTreeItem);
	typedef Pointer0<EditSceneTreeItem> EditSceneTreeItemPtr;

}

#endif