// PX2E_ProjTreeItem.hpp

#ifndef PX2E_PROJTREEITEM_HPP
#define PX2E_PROJTREEITEM_HPP

#include "PX2EditorPre.hpp"
#include "PX2Object.hpp"
#include "PX2E_ProjTreeDef.hpp"

namespace PX2Editor
{

	class ProjTree;

	class ProjTreeItem
	{ 
	public:
		enum ItemType
		{
			IT_OBJECT,
			IT_CATALOG,
			IT_MAX_TYPE
		};

		ProjTreeItem(ProjTree *tree, ProjTreeItem *parent, 
			ItemType type, int iconID, PX2::Object *obj,
			ProjTreeLevel showLevel, const std::string &name = "", 
			bool doInsert = false, wxTreeItemId insertUpID=wxTreeItemId());
		virtual ~ProjTreeItem();

		void SetTreeLevel(ProjTreeLevel level);
		ProjTreeLevel GetTreeLevel() const { return mTreeLevel; }

		void SetName(const std::string &name);
		const std::string &GetName() const { return mName; }

		void SetObject(PX2::Object *obj) { mObject = obj; }
		PX2::Object *GetObject() const { return mObject; }

		int GetIconID() const { return mIconID; }
		wxTreeItemId GetItemID() const { return mItemID; }
		ProjTreeItem *GetParent() const { return mParentItem; }

		ProjTreeItem *AddChild(PX2::Object *obj, int iconID, ProjTreeLevel showLevel);
		ProjTreeItem *InsertChild(wxTreeItemId upID, PX2::Object *obj, int iconID, ProjTreeLevel showLevel);
		void RemoveChild(PX2::Object *obj);
		void ClearChildren();

		ProjTreeItem *GetItem(PX2::Object *obj);
		ProjTreeItem *GetItem(wxTreeItemId id);

	public_internal:
		ProjTreeItem(ProjTree *tree, wxTreeItemId id, 
			ItemType type, int iconID, const std::string &name);

		std::vector<ProjTreeItem*> mChildItems;

	protected:
		ProjTree *mProjTree;
		ProjTreeItem *mParentItem;

		ItemType mItemType;
		int mIconID;
		PX2::ObjectPtr mObject;
		std::string mName;
		wxTreeItemId mItemID;

		ProjTreeLevel mTreeLevel;
	};

}

#endif