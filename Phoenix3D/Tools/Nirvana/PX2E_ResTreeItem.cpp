// PX2E_ResTreeItem.cpp

#include "PX2E_ResTreeItem.hpp"
#include "PX2E_ResTree.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2Editor;
using namespace PX2;

//-----------------------------------------------------------------------------
ResTreeItem::ResTreeItem(ResTree *resTree, std::string name, std::string pathName) :
mResTree(resTree),
mIsOnlyDir(false),
mResName(name),
mResPathName(pathName),
mItemID(0),
mParent(0),
mIsTexPack(false),
mIsTexPackElement(false)
{
}
//-----------------------------------------------------------------------------
ResTreeItem::~ResTreeItem()
{
}
//-----------------------------------------------------------------------------
void ResTreeItem::RootBuild(bool isOnlyDir)
{
	mResTree->DeleteAllItems();

	mParent = 0;
	int iconID = mResTree->Icons["folder"];
	mItemID = mResTree->AddRoot(mResName, iconID);

	_BuildChild(isOnlyDir);

	mResTree->Expand(mItemID);
}
//-----------------------------------------------------------------------------
void ResTreeItem::AddChild(ResTreeItem *item)
{
	mChildItems.push_back(item);

	item->SetParent(this);

	item->_BuildChild(mIsOnlyDir);
}
//-----------------------------------------------------------------------------
int ResTreeItem::GetChildNum()
{
	return (int)mChildItems.size();
}
//-----------------------------------------------------------------------------
ResTreeItem *ResTreeItem::GetChildItem(wxTreeItemId id)
{
	ResTreeItemPtr item;

	for (int i = 0; i < (int)mChildItems.size(); i++)
	{
		if (id == mChildItems[i]->GetItemID())
		{
			item = mChildItems[i];

			return item;
		}
		else
		{
			item = mChildItems[i]->GetChildItem(id);

			if (item)
				return item;
		}
	}

	return item;
}
//-----------------------------------------------------------------------------
void ResTreeItem::SetParent(ResTreeItem *parent)
{
	std::string outPath;
	std::string outBaseName;
	std::string outExt;

	std::string resPath = mResPathName;
	if ('/' == resPath[resPath.length() - 1])
	{
		resPath = resPath.substr(0, resPath.length() - 1);
	}
	StringHelp::SplitFullFilename(resPath, outPath, outBaseName, outExt);

	int iconID = -1;
	if ("" == outExt)
		iconID = mResTree->Icons["folder"];
	else if ("png" == outExt)
		iconID = mResTree->Icons["image"];
	else if ("px2obj" == outExt)
		iconID = mResTree->Icons["px2obj"];
	else if ("csv" == outExt)
		iconID = mResTree->Icons["csv"];
	else if ("lua" == outExt)
		iconID = mResTree->Icons["lua"];

	mParent = parent;

	mItemID = mResTree->AppendItem(parent->GetItemID(), mResName, iconID);
}
//-----------------------------------------------------------------------------
ResTreeItem *ResTreeItem::GetChildItem(const std::string& resPath)
{
	if (resPath == mResPathName)
		return this;

	for (int i = 0; i < (int)mChildItems.size(); i++)
	{
		if (mChildItems[i])
		{
			ResTreeItem *item = mChildItems[i]->GetChildItem(resPath);

			if (item)
			{
				return item;
			}
		}
	}

	return 0;
}
//-----------------------------------------------------------------------------
std::vector<PX2::Pointer0<ResTreeItem>> ResTreeItem::GetChildItems()
{
	return mChildItems;
}
//-----------------------------------------------------------------------------
bool ResTreeItem::_IsAFile(const std::string &filename)
{
	if (filename.find(".") != std::string::npos)
		return true;

	return false;
}
//-----------------------------------------------------------------------------
void ResTreeItem::_BuildChild(bool isOnlyDir)
{
	mIsOnlyDir = isOnlyDir;

	if (mResName.empty()) return;
	
	if (!mIsOnlyDir)
	{
		if (_IsAFile(mResPathName))
		{ // 是一个文件

			mResPathName = mResPathName.substr(0, mResPathName.size() - 1);

			if (mResPathName.find(".xml") != std::string::npos
				|| mResPathName.find(".XML") != std::string::npos)
			{
				mIsTexPack = PX2_RM.IsTexPack(mResPathName);
			}

			if (mIsTexPack)
			{
				PX2_RM.AddTexPack(mResPathName);
				const TexPack &texPack = PX2_RM.GetTexPack(mResPathName);
				if (texPack.IsValid())
				{
					for (int i = 0; i < (int)texPack.Elements.size(); i++)
					{
						std::string eleName = texPack.Elements[i].ElementName;
						ResTreeItem *item = new0 ResTreeItem(mResTree, eleName, GetPathName());
						item->SetBeTexPackElement(true);
						AddChild(item);
					}
				}
			}

			return;
		}
	}

	wxDir d;

	d.Open(mResPathName);
	wxString eachFilename;

	if (d.IsOpened())
	{
		if (!d.HasFiles() && !d.HasSubDirs())
			return;

		int flags = wxDIR_DIRS | wxDIR_FILES;
		if (d.GetFirst(&eachFilename, wxEmptyString, flags))
		{
			do
			{
				if ((eachFilename != wxT(".")) && (eachFilename != wxT("..")))
				{
					std::string fileName = eachFilename.ToAscii();
					std::string pathName = mResPathName + fileName;
					std::string pathName1 = pathName + "/";

					ResTreeItem *item = new0 ResTreeItem(mResTree, fileName, pathName1);

					if (_IsAFile(fileName))
					{
						if (!mIsOnlyDir)
						{
							AddChild(item);
						}

						mChildFilesItems.push_back(item);
						mChildFilenamesList.push_back(pathName);
					}
					else
					{
						AddChild(item);
						mChildPathsList.push_back(pathName1);
					}
				}

			} while (d.GetNext(&eachFilename));
		}
	}
}
//-----------------------------------------------------------------------------