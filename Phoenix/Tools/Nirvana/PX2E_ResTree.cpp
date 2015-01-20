// PX2E_ResTree.cpp

#include "PX2E_ResTree.hpp"
using namespace PX2Editor;

IMPLEMENT_DYNAMIC_CLASS(PX2Editor::ResTree, wxTreeCtrl)
BEGIN_EVENT_TABLE(ResTree, wxTreeCtrl)
END_EVENT_TABLE()
//----------------------------------------------------------------------------
ResTree::ResTree(wxWindow *parent) :
wxTreeCtrl(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
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
}
//----------------------------------------------------------------------------
ResTree::ResTree()
{
}
//----------------------------------------------------------------------------
ResTree::~ResTree()
{
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