// PX2E_ResTree.hpp

#ifndef PX2E_RESTREE_HPP
#define PX2E_RESTREE_HPP

#include "PX2EditorPre.hpp"
#include "PX2E_ResTreeItem.hpp"
#include "PX2Singleton_NeedNew.hpp"

namespace PX2Editor
{

	class ResTree : public wxTreeCtrl, public PX2::Singleton<ResTree>
	{
		DECLARE_DYNAMIC_CLASS(ResTree)

	public:
		ResTree(wxWindow *parent);
		virtual ~ResTree();

		ResTreeItem *GetItem(wxTreeItemId id);

		void UpdateOnPath(const std::string &pathName);

		void OnSelChanged(wxTreeEvent &ent);

		ResTreeItem* GetTreeRootItem();

	public_internal:
		std::map<std::string, int> Icons;

	protected:
		DECLARE_EVENT_TABLE()
		ResTree();

		ResTreeItemPtr mRootItem;
		wxImageList *mImageList;
	};

}

#endif