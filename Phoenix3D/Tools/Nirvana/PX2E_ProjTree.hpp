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
	public:
		ProjTree(wxWindow *parent);
		virtual ~ProjTree();

		virtual void DoExecute(PX2::Event *event);

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