// PX2E_ResTree.cpp

#include "PX2E_ResTree.hpp"
#include "PX2E_NirMan.hpp"
#include "PX2Project.hpp"
#include "PX2Edit.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2NirvanaEventType.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Selection.hpp"
#include "PX2LanguageManager.hpp"
using namespace PX2Editor;
using namespace PX2;

static int sID_RESTREE = PX2_EDIT_GETID;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::ResTree, wxTreeCtrl)
BEGIN_EVENT_TABLE(ResTree, wxTreeCtrl)
EVT_TREE_SEL_CHANGED(sID_RESTREE, ResTree::OnSelChanged)
EVT_TREE_ITEM_ACTIVATED(sID_RESTREE, ResTree::OnItemActivated)
EVT_RIGHT_DOWN(ResTree::OnRightDown)
EVT_RIGHT_UP(ResTree::OnRightUp)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ResTree::ResTree(wxWindow *parent) :
wxTreeCtrl(parent, sID_RESTREE, wxDefaultPosition, wxDefaultSize,
wxTR_DEFAULT_STYLE | wxTR_FULL_ROW_HIGHLIGHT | wxTR_NO_LINES | wxTR_TWIST_BUTTONS | wxNO_BORDER),
mEditMenu(0)
{
	mImageList = new wxImageList(16, 16);
	int imageFolder = mImageList->Add(wxIcon(wxT("DataEditor/icons/folder.png"), wxBITMAP_TYPE_PNG));
	int imageImage = mImageList->Add(wxIcon(wxT("DataEditor/icons/image.png"), wxBITMAP_TYPE_PNG));
	int imageObject = mImageList->Add(wxIcon(wxT("DataEditor/icons/object.png"), wxBITMAP_TYPE_PNG));
	int imageCSV = mImageList->Add(wxIcon(wxT("DataEditor/icons/csv.png"), wxBITMAP_TYPE_PNG));
	int imageLua = mImageList->Add(wxIcon(wxT("DataEditor/icons/lua.png"), wxBITMAP_TYPE_PNG));
	SetImageList(mImageList);

	Icons["folder"] = imageFolder;
	Icons["image"] = imageImage;
	Icons["px2obj"] = imageObject;
	Icons["csv"] = imageCSV;
	Icons["lua"] = imageLua;

	UpdateOnPath("Data/");
}
//----------------------------------------------------------------------------
ResTree::ResTree()
{
}
//----------------------------------------------------------------------------
ResTree::~ResTree()
{
	if (mEditMenu)
	{
		delete mEditMenu;
		mEditMenu = 0;
	}

	if (mImageList)
	{
		delete mImageList;
		mImageList = 0;
	}
}
//-----------------------------------------------------------------------------
void ResTree::OnRightDown(wxMouseEvent& e)
{
	PX2_UNUSED(e);
}
//-----------------------------------------------------------------------------
void ResTree::OnRightUp(wxMouseEvent& e)
{
	wxPoint mousePos = e.GetPosition();

	if (mEditMenu)
	{
		delete mEditMenu;
		mEditMenu = 0;
	}

	mEditMenu = new wxMenu();
	NirMan::GetSingleton().SetCurMenu(mEditMenu);

	PX2_SM.CallString("e_CreateResMenu()");

	if (mEditMenu) PopupMenu(mEditMenu, mousePos.x, mousePos.y);
}
//-----------------------------------------------------------------------------
void ResTree::OnItemActivated(wxTreeEvent& event)
{
	PX2_UNUSED(event);
}
//-----------------------------------------------------------------------------
void ResTree::OnSelChanged(wxTreeEvent& event)
{
	wxTreeItemId id = event.GetItem();

	ResTreeItem *item = GetItem(id);
	if (!item) return;

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::RefreshRes);
	ent->SetData<std::vector<std::string> >(item->GetChildFilenamesList());
	PX2_EW.BroadcastingLocalEvent(ent);
}
//-----------------------------------------------------------------------------
ResTreeItem *ResTree::GetItem(wxTreeItemId id)
{
	return mRootItem->GetChildItem(id);
}
//----------------------------------------------------------------------------
ResTreeItem *ResTree::GetTreeRootItem()
{
	return mRootItem;
}
//----------------------------------------------------------------------------
void ResTree::UpdateOnPath(const std::string &pathName)
{
	std::string name;
	std::string compareStr = "Data/";
	if (pathName == compareStr)
	{
		name = "Data";
	}
	else
	{
		name = pathName.substr(compareStr.length(), 
			pathName.length() - compareStr.length() - 1);
	}

	mRootItem = new0 ResTreeItem(this, name, pathName);
	mRootItem->RootBuild();

	SelectItem(mRootItem->GetItemID());
}
//----------------------------------------------------------------------------