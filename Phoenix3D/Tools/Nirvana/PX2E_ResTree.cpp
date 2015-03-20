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
#include "PX2ResourceManager.hpp"
#include "PX2EditEventType.hpp"
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
ResTree::ResTree(wxWindow *parent, bool isUseOnlyDir) :
wxTreeCtrl(parent, sID_RESTREE, wxDefaultPosition, wxDefaultSize,
wxTR_DEFAULT_STYLE | wxTR_FULL_ROW_HIGHLIGHT | wxTR_NO_LINES | wxNO_BORDER),
mEditMenu(0),
mIsUseOnlyDir(isUseOnlyDir)
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

	PX2_EW.ComeIn(this);
}
//----------------------------------------------------------------------------
ResTree::ResTree()
{
	PX2_EW.GoOut(this);
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
	wxTreeItemId id = event.GetItem();

	ResTreeItemPtr item = GetItem(id);

	if (!item) return;

#if defined(_WIN32) || defined(WIN32)
	WCHAR wszPath[MAX_PATH];
	GetCurrentDirectoryW(sizeof(wszPath), wszPath);
	std::wstring fullPath = wszPath + std::wstring(_T("\\")) + item->GetPathName();

	ShellExecute(0, _T("open"), fullPath.c_str(), 0, 0, SW_SHOW);
#endif
}
//-----------------------------------------------------------------------------
void ResTree::OnSelChanged(wxTreeEvent& event)
{
	wxTreeItemId id = event.GetItem();

	ResTreeItem *item = GetItem(id);
	if (!item) return;

	if (mIsUseOnlyDir)
	{
		PX2_EDIT.SetSelectPath_ChildFilenames(item->GetChildFilenamesList());
		PX2_EDIT.SetSelectPath_ChildPaths(item->GetChildPathsList());

		Event *ent = EditEventSpace::CreateEventX(EditEventSpace::RefreshRes);
		PX2_EW.BroadcastingLocalEvent(ent);
	}
	else
	{
		if (item->IsTexPackElement())
		{
			std::string eleName = item->GetName();
			std::string pathName = item->GetPathName();

			const TexPackElement &ele = PX2_RM.GetTexPackElement(pathName, eleName);
			if (ele.IsValid())
			{
				ObjectPtr obj = PX2_RM.BlockLoad(ele.ImagePathFull);

				SelectResData data(SelectResData::RT_TEXPACKELEMENT);
				data.ResPathname = pathName;
				data.EleName = eleName;
				data.TheObject = obj;
				PX2_EDIT.SetSelectedResource(data);
				PX2_EDIT.SetPreViewObject(obj);
			}

			return;
		}

		std::string resPath = item->GetPathName();
		if (resPath.find(".wav") != std::string::npos ||
			resPath.find(".WAV") != std::string::npos ||
			resPath.find(".ogg") != std::string::npos ||
			resPath.find(".OGG") != std::string::npos ||
			resPath.find(".mp3") != std::string::npos ||
			resPath.find(".MP3") != std::string::npos)
		{
			SelectResData data;
			data.ResPathname = resPath;
			PX2_EDIT.SetSelectedResource(data);
		}
		else if (resPath.find(".xml") != std::string::npos || resPath.find(".XML") != std::string::npos)
		{
			SelectResData data;
			data.ResPathname = resPath;
			PX2_EDIT.SetSelectedResource(data);
		}
		else if (resPath.find(".lua") != std::string::npos)
		{
		}
		else if (resPath.find(".px2Logic") != std::string::npos)
		{
			SelectResData data;
			data.ResPathname = resPath;

			PX2_EDIT.SetSelectedResource(data);
		}
		else if (resPath.find(".") != std::string::npos)
		{
			SelectResData data;
			data.ResPathname = resPath;

			PX2::ObjectPtr object = ResourceManager::GetSingleton().BlockLoad(
				resPath.c_str());
			data.TheObject = object;

			PX2_EDIT.SetSelectedResource(data);
			PX2_EDIT.SetPreViewObject(object);
		}
	}
}
//-----------------------------------------------------------------------------
ResTreeItem *ResTree::GetItem(wxTreeItemId id)
{
	return mRootItem->GetChildItem(id);
}
//----------------------------------------------------------------------------
ResTreeItem *ResTree::GetItem(const std::string &resPath)
{
	return mRootItem->GetChildItem(resPath);
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
	mRootItem->RootBuild(mIsUseOnlyDir);

	SelectItem(mRootItem->GetItemID());
}
//----------------------------------------------------------------------------
void ResTree::ResRefresh()
{
	UpdateOnPath("Data/");
}
//----------------------------------------------------------------------------
void ResTree::ResClear()
{
	PX2_RM.Clear();
}
//----------------------------------------------------------------------------
void ResTree::DoExecute(PX2::Event *event)
{
	PX2_UNUSED(event);

	if (EditEventSpace::IsEqual(event, EditEventSpace::ToSelectRes))
	{
		Object *obj = event->GetData<Object*>();
		if (obj)
		{
			const std::string &resPath = obj->GetResourcePath();
			if (!resPath.empty())
			{
				ResTreeItem *item = GetItem(resPath);
				if (item)
				{
					SelectItem(item->GetItemID());
					SetFocus();
				}
			}
		}
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::FindActorInResTree))
	{
		Object *obj = event->GetData<Object*>();
		Actor *actor = DynamicCast<Actor>(obj);
		if (actor)
		{
			const std::string &movFilename = actor->GetMovableFilename();
			if (!movFilename.empty())
			{
				ResTreeItem *item = GetItem(movFilename);
				if (item)
				{
					SelectItem(item->GetItemID());
					SetFocus();
				}
			}
		}
	}
}
//----------------------------------------------------------------------------