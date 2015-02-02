// PX2E_ResTree.cpp

#include "PX2E_ResTree.hpp"
#include "PX2Project.hpp"
#include "PX2Edit.hpp"
using namespace PX2Editor;
using namespace PX2;

static int sID_RESTREE = PX2_EDIT_GETID;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::ResTree, wxTreeCtrl)
BEGIN_EVENT_TABLE(ResTree, wxTreeCtrl)
EVT_TREE_SEL_CHANGED(sID_RESTREE, ResTree::OnSelChanged)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ResTree::ResTree(wxWindow *parent) :
wxTreeCtrl(parent, sID_RESTREE, wxDefaultPosition, wxDefaultSize,
wxTR_DEFAULT_STYLE | wxTR_FULL_ROW_HIGHLIGHT | wxTR_NO_LINES | wxTR_TWIST_BUTTONS | wxNO_BORDER)
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
	if (mImageList)
	{
		delete mImageList;
		mImageList = 0;
	}
}
//-----------------------------------------------------------------------------
void ResTree::OnSelChanged(wxTreeEvent& event)
{
	Project *proj = Project::GetSingletonPtr();

	if (!proj)
		return;

	wxTreeItemId id = event.GetItem();

	ResTreeItem *item = GetItem(id);
	if (item)
	{
	}
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
}
//----------------------------------------------------------------------------