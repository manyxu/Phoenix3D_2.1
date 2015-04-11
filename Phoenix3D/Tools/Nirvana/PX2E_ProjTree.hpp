// PX2E_ProjTree.hpp

#ifndef PX2E_PROJTREE_HPP
#define PX2E_PROJTREE_HPP

#include "PX2EditorPre.hpp"
#include "PX2EventHandler.hpp"
#include "PX2E_ProjTreeItem.hpp"
#include "PX2E_ProjTreeDef.hpp"
#include "PX2EditParams.hpp"

namespace PX2Editor
{

	class ProjTree : public wxTreeCtrl, public PX2::EventHandler
	{
		DECLARE_DYNAMIC_CLASS(ProjTree)

	public:
		ProjTree();
		ProjTree(wxWindow *parent);
		virtual ~ProjTree();

		void ShowHelpNode(bool showHelpNode);
		bool IsShowHelpNode() const;

		void SetTreeLevel(ProjTreeLevel level);
		ProjTreeLevel GetTreeLevel() const;
		void SetSelectItemLevel(ProjTreeLevel level);

		ProjTreeItem *GetItem(wxTreeItemId id);
		ProjTreeItem *GetItem(PX2::Object *obj);

		virtual void DoExecute(PX2::Event *event);

		void OnRightDown(wxMouseEvent& e);
		void OnRightUp(wxMouseEvent& e);
		void OnItemActivated(wxTreeEvent& event);
		void OnSelChanged(wxTreeEvent& event);
		void OnSelChanging(wxTreeEvent& event);
		void OnSelDelete(wxTreeEvent& event);

		void ExpandSelect();
		void CollapseSelect();

	public_internal:
		std::map<std::string, int> Icons;

	protected:
		DECLARE_EVENT_TABLE()

		void _RefreshProject();
		void _ClearProject();

		void _RefreshScene();
		void _ClearScene();

		void _RefreshUI();
		void _ClearUI();

		void _RefreshLogic();
		void _ClearLogic();

		void _AddObject(PX2::Object *obj);
		void _RemoveObject(PX2::Object *obj);

		bool mIsShowHelpNode;
		ProjTreeLevel mTreeLevel;

		wxImageList *mImageList;

		ProjTreeItem *mItemProj;
		ProjTreeItem *mItemScene;

		ProjTreeItem *mItemCameras;
		ProjTreeItem *mItemSky;
		ProjTreeItem *mItemTerrain;
		ProjTreeItem *mItemCharacters;
		ProjTreeItem *mItemObjects;
		ProjTreeItem *mItemLights;
		ProjTreeItem *mItemEffects;
		ProjTreeItem *mItemSounds;
		ProjTreeItem *mItemTriggers;
		ProjTreeItem *mItemAmbientRegions;
		std::vector<ProjTreeItem*> mCalItems;

		ProjTreeItem *mItemUI;
		ProjTreeItem *mItemLogic;

		wxMenu *mEditMenu;
	};

}

#endif