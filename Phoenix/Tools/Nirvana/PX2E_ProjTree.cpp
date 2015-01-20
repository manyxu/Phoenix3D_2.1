// PX2E_ProjTree.cpp

#include "PX2E_ProjTree.hpp"
#include "PX2Edit.hpp"
using namespace PX2Editor;
using namespace PX2;

BEGIN_EVENT_TABLE(ProjTree, wxTreeCtrl)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ProjTree::ProjTree(wxWindow *parent) :
wxTreeCtrl(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
wxTR_DEFAULT_STYLE | wxTR_FULL_ROW_HIGHLIGHT | wxTR_NO_LINES | wxTR_TWIST_BUTTONS| wxNO_BORDER),
mTreeLevel(OTL_GENERAL)
{
	wxTreeItemId projectID = AddRoot("Project", 0);
	mItemProj = new ProjTreeItem(this, projectID, ProjTreeItem::IT_CATALOG, 0,
		"Project");

	mItemScene = new ProjTreeItem(this, mItemProj, 
		ProjTreeItem::IT_CATALOG, 0, 0, mTreeLevel, "Scene");
	mItemProj->mChildItems.push_back(mItemScene);

	mItemUI = new ProjTreeItem(this, mItemProj, 
		ProjTreeItem::IT_CATALOG, 0, 0, mTreeLevel, "UI");
	mItemProj->mChildItems.push_back(mItemUI);

	mItemLogic = new ProjTreeItem(this, mItemProj, 
		ProjTreeItem::IT_CATALOG, 0, 0, mTreeLevel, "Logic");
	mItemProj->mChildItems.push_back(mItemLogic);
}
//----------------------------------------------------------------------------
ProjTree::~ProjTree()
{
	UnselectAll();

	if (mItemProj)
	{
		mItemProj->SetObject(0);
		delete mItemProj;
		mItemProj = 0;
	}
}
//----------------------------------------------------------------------------