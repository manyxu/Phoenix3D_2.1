// PX2E_ProjTree.hpp

#ifndef PX2E_PROJTREE_HPP
#define PX2E_PROJTREE_HPP

#include "PX2EditorPre.hpp"
#include "PX2EventHandler.hpp"
#include "PX2E_ProjTreeItem.hpp"
#include "PX2E_ProjTreeDef.hpp"

namespace PX2Editor
{

	class ProjTree : public wxTreeCtrl, public PX2::EventHandler
	{
		DECLARE_DYNAMIC_CLASS(ProjTree)

	public:
		ProjTree();
		ProjTree(wxWindow *parent);
		virtual ~ProjTree();

		ProjTreeItem *GetItem(wxTreeItemId id);
		ProjTreeItem *GetItem(PX2::Object *obj);

		virtual void DoExecute(PX2::Event *event);

		void OnSelChanged(wxTreeEvent& event);
		void OnSelChanging(wxTreeEvent& event);

	public_internal:
		std::map<std::string, int> Icons;

	protected:
		DECLARE_EVENT_TABLE()

		void _RefreshProject();
		void _ClearProject();

		ProjTreeLevel mTreeLevel;

		wxImageList *mImageList;

		ProjTreeItem *mItemProj;
		ProjTreeItem *mItemScene;
		ProjTreeItem *mItemUI;
		ProjTreeItem *mItemLogic;
	};

}

#endif