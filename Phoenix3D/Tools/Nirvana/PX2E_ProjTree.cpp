// PX2E_ProjTree.cpp

#include "PX2E_ProjTree.hpp"
#include "PX2Project.hpp"
#include "PX2Edit.hpp"
#include "PX2EditEventType.hpp"
using namespace PX2Editor;
using namespace PX2;

BEGIN_EVENT_TABLE(ProjTree, wxTreeCtrl)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ProjTree::ProjTree(wxWindow *parent) :
wxTreeCtrl(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
wxTR_DEFAULT_STYLE | wxTR_FULL_ROW_HIGHLIGHT | wxTR_NO_LINES | wxTR_TWIST_BUTTONS| wxNO_BORDER),
mTreeLevel(OTL_GENERAL),
mImageList(0),
mItemProj(0),
mItemScene(0),
mItemUI(0)
{
	mImageList = new wxImageList(16, 16);

	int imageProject = mImageList->Add(wxIcon(wxT("DataEditor/icons/proj.png"), wxBITMAP_TYPE_PNG));
	int imageScene = mImageList->Add(wxIcon(wxT("DataEditor/icons/scene.png"), wxBITMAP_TYPE_PNG));
	int imageUI = mImageList->Add(wxIcon(wxT("DataEditor/icons/ui.png"), wxBITMAP_TYPE_PNG));
	int imageLogic = mImageList->Add(wxIcon(wxT("DataEditor/icons/logic.png"), wxBITMAP_TYPE_PNG));
	SetImageList(mImageList);

	Icons["proj"] = imageProject;
	Icons["scene"] = imageScene;
	Icons["ui"] = imageUI;
	Icons["logic"] = imageLogic;
}
//----------------------------------------------------------------------------
ProjTree::~ProjTree()
{
	UnselectAll();

	_ClearProject();

	if (mImageList)
	{
		delete mImageList;
		mImageList = 0;
	}
}
//----------------------------------------------------------------------------
void ProjTree::_RefreshProject()
{
	Project *proj = Project::GetSingletonPtr();

	wxTreeItemId projectID = AddRoot("Project", 0);
	mItemProj = new ProjTreeItem(this, projectID, ProjTreeItem::IT_CATALOG, 
		Icons["proj"], "Project");
	mItemProj->SetObject(proj);

	mItemScene = new ProjTreeItem(this, mItemProj,
		ProjTreeItem::IT_CATALOG, Icons["scene"], 0, mTreeLevel, "Scene");
	mItemProj->mChildItems.push_back(mItemScene);

	mItemUI = new ProjTreeItem(this, mItemProj,
		ProjTreeItem::IT_CATALOG, Icons["ui"], 0, mTreeLevel, "UI");
	mItemProj->mChildItems.push_back(mItemUI);

	mItemLogic = new ProjTreeItem(this, mItemProj,
		ProjTreeItem::IT_CATALOG, Icons["logic"], 0, mTreeLevel, "Logic");
	mItemProj->mChildItems.push_back(mItemLogic);
}
//----------------------------------------------------------------------------
void ProjTree::_ClearProject()
{
	if (mItemProj)
	{
		mItemProj->SetObject(0);
		delete mItemProj;
		mItemProj = 0;
	}
}
//----------------------------------------------------------------------------
void ProjTree::DoExecute(Event *event)
{
	if (EditEventSpace::IsEqual(event, EditEventSpace::NewProject))
	{
		_RefreshProject();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::LoadedProject))
	{
		_RefreshProject();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::SavedProject))
	{
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::ClosedProject))
	{
		_ClearProject();
	}
}
//----------------------------------------------------------------------------