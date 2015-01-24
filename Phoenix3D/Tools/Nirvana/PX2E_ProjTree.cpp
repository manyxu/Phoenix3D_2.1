// PX2E_ProjTree.cpp

#include "PX2E_ProjTree.hpp"
#include "PX2Project.hpp"
#include "PX2Edit.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Selection.hpp"
using namespace PX2Editor;
using namespace PX2;

static int sID_PROJVIEW = PX2_EDIT_GETID;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::ProjTree, wxTreeCtrl)
BEGIN_EVENT_TABLE(ProjTree, wxTreeCtrl)
EVT_TREE_SEL_CHANGED(sID_PROJVIEW, ProjTree::OnSelChanged)
EVT_TREE_SEL_CHANGING(sID_PROJVIEW, ProjTree::OnSelChanging)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ProjTree::ProjTree()
{
}
//----------------------------------------------------------------------------
ProjTree::ProjTree(wxWindow *parent) :
wxTreeCtrl(parent, sID_PROJVIEW, wxDefaultPosition, wxDefaultSize,
wxTR_DEFAULT_STYLE | wxTR_FULL_ROW_HIGHLIGHT | wxTR_NO_LINES | wxNO_BORDER),
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
//-----------------------------------------------------------------------------
ProjTreeItem *ProjTree::GetItem(wxTreeItemId id)
{
	return mItemProj->GetItem(id);
}
//-----------------------------------------------------------------------------
ProjTreeItem *ProjTree::GetItem(PX2::Object *obj)
{
	return mItemProj->GetItem(obj);
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
void ProjTree::OnSelChanged(wxTreeEvent& event)
{
	Project *proj = Project::GetSingletonPtr();
	if (!proj) return;

	wxTreeItemId id = event.GetItem();

	ProjTreeItem *item = GetItem(id);
	if (item)
	{
		void *id = item->GetItemID().GetID();
		const std::string &itemName = item->GetName();

		Object *obj = item->GetObject();
		if (obj)
		{
			PX2_SELECTION.Clear();
			PX2_SELECTION.AddObject(obj);
		}
		else
		{
			PX2_SELECTION.Clear();
		}
	}
}
//----------------------------------------------------------------------------
void ProjTree::OnSelChanging(wxTreeEvent& event)
{

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
	else if (EditEventSpace::IsEqual(event, EditEventSpace::CloseProject))
	{
		_ClearProject();
	}
}
//----------------------------------------------------------------------------