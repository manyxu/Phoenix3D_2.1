// PX2ResourceManager.cpp

#include "PX2ResourceManager.hpp"
#include "PX2StringHelp.hpp"
#include "PX2XMLData.hpp"
#include "PX2System.hpp"
#include "PX2Time.hpp"
#include "PX2Crypt.hpp"
#include "PX2MD5.hpp"

#include "ImageLibs/PNG/png.h"

#if defined (__IOS__)
#include <unistd.h>
#endif

#include "unzip.h"
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#include <io.h>
#include <sys/stat.h>
#elif defined __ANDROID__
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "AppPlayJNI.hpp"
#elif defined __IOS__
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#endif

#if defined(_WIN32) || defined(WIN32)
#pragma warning(disable : 4312)
#endif

using namespace PX2;
using namespace std;

#define PX2_RGB_PREMULTIPLY_ALPHA(vr,vg,vb,va) \
	(unsigned)(((unsigned)((unsigned char)(vr) * ((unsigned char)(va) + 1)) >> 8) | \
	((unsigned)((unsigned char)(vg) * ((unsigned char)(va) + 1) >> 8) << 8) | \
	((unsigned)((unsigned char)(vb) * ((unsigned char)(va) + 1) >> 8) << 16) | \
	((unsigned)(unsigned char)(va) << 24))
typedef struct
{
	unsigned char* data;
	int size;
	int offset;
}tImageSource;

static void pngReadCallBack(png_structp png_ptr, png_bytep data, png_size_t length)
{
	tImageSource* isource = (tImageSource*)png_get_io_ptr(png_ptr);

	if((int)(isource->offset + length) <= isource->size)
	{
		memcpy(data, isource->data+isource->offset,length);
		isource->offset += length;
	}
	else
	{
		png_error(png_ptr, "pngReaderCallback failed");
	}
}

//----------------------------------------------------------------------------
Object *ResManUserLoadFun(const char *filename)
{
	return ResourceManager::GetSingleton().BlockLoad(filename);
}
//----------------------------------------------------------------------------
std::string ResourceManager::msResPath;
std::string ResourceManager::mWriteablePath;
TexPack ResourceManager::msIvalidTexPack;
TexPackElement ResourceManager::msIvalidTexPackElement;
std::string ResourceManager::mDataUpdateServerType;
//----------------------------------------------------------------------------
ResourceManager::ResourceManager ()
:
mDDSKeepCompressed(true),
mLoadRecordMutex(0),
mLoadingDequeMutex(0),
mLoadingThread(0),
mQuitLoading(false),
mIsUseGarbageCollect(true),
mGarbageCollectTime(6.0f),
mGarbageUpdateTime(1.0f),
mResTableMutex(0),
mResTable(1023),
mTexPacks(1023),
mPackElements(1023),
//mCurlDownLoad(0),
mEndVersionList(19870824),
mDataVersionList(1023),
mDataUpdateVersionList(1023),
mUpdateVersionList(1023),
mResourceUpdateCallback(0)
{
	//mCurlDownLoad = new0 CURLDownload();
	//mCurlDownLoad->Initlize();
	//mCurlDownLoad->SetDownType(CURLDownload::DT_FILE);

	mLoadRecordMutex = new0 Mutex();
	mLoadingDequeMutex = new0 Mutex();
	mResTableMutex = new0 Mutex();
	mTexPacksMutex = new0 Mutex();

	GraphicsRoot::SetUserLoadFun(ResManUserLoadFun);

	CreateCondition(mLoadingDequeCondition);
	mLoadingThread = new0 Thread("ResLoadThread");
	mLoadingThread->Start(*this);

#if defined WIN32
	if (msResPath.empty())
	{
		char full_path[_MAX_PATH + 1];
		GetModuleFileName(NULL, full_path, _MAX_PATH + 1);
		std::string ret((char*)full_path);
		ret =  ret.substr(0, ret.rfind("\\") + 1);

		msResPath = StringHelp::StandardisePath(ret);
	}

	char full_path[_MAX_PATH + 1];
	GetModuleFileName(NULL, full_path, _MAX_PATH + 1);
	std::string ret((char*)full_path);
	mWriteablePath =  ret.substr(0, ret.rfind("\\") + 1);
#elif defined __ANDROID__
	// the path is: /data/data/ + package name
	std::string dir("/data/data/");
	std::string temp = GetPackageNameJNI();

	if (!temp.empty())
	{
		dir.append(temp).append("/");

		mWriteablePath = dir;
	}
	else
	{
		mWriteablePath = "";
	}
#elif defined __MARMALADE__
	mWriteablePath = "ram://";
#endif

#if defined WIN32
	mDataUpdatePath = "DataUpdateWIN/";
#elif defined __ANDROID__
	mDataUpdatePath = "DataUpdateAndroid/";
#elif defined __MARMALADE__
	mDataUpdatePath = "DataUpdateIOS/";
#endif
}
//----------------------------------------------------------------------------
ResourceManager::~ResourceManager ()
{
	PostCondition(mLoadingDequeCondition);

	if (mLoadingThread)
	{
		mQuitLoading = true;
		mLoadingThread->Join();
		delete0(mLoadingThread);
		mLoadingThread = 0;
	}

	CloseCondition(mLoadingDequeCondition);

	if (mTexPacksMutex)
	{
		delete0(mTexPacksMutex);
	}

	if (mLoadRecordMutex)
	{
		delete0(mLoadRecordMutex);
	}

	if (mLoadingDequeMutex)
	{
		delete0(mLoadingDequeMutex);
	}

	if (mResTableMutex)
	{
		delete0(mResTableMutex);
	}

	//if (mCurlDownLoad)
	{
	//	mCurlDownLoad->Terminate();
	//	delete0(mCurlDownLoad);
	}

	mDataVersionList.Clear(); 
	mDataUpdateVersionList.Clear(); 
	mUpdateVersionList.Clear(); 
}
//----------------------------------------------------------------------------
void ResourceManager::Update (double appSeconds, double elapsedSeconds)
{
	if (mIsUseGarbageCollect)
	{
		GarbageCollect(appSeconds, elapsedSeconds);
	}

	PX2_UNUSED(elapsedSeconds);
}
//----------------------------------------------------------------------------
void ResourceManager::Clear ()
{
	mResTableMutex->Enter();
	mResTable.Clear();
	mResTableMutex->Leave();

	mTexPacksMutex->Enter();	
	mTexPacks.Clear();
	mPackElements.Clear();
	mTexPacksMutex->Leave();
}
//----------------------------------------------------------------------------
void ResourceManager::ClearRes (const std::string &resPath)
{
	if (resPath.empty()) return;

	mResTableMutex->Enter();
	ResTable::Element *eleRes = mResTable.Find(resPath.c_str());
	if (eleRes)
	{
		mResTable.Erase(eleRes);
	}
	mResTableMutex->Leave();
}
//----------------------------------------------------------------------------
Object *ResourceManager::BlockLoad (const std::string &filename)
{
	if (filename.empty())
	{
		assertion(false, "filename must not be null");
		return 0;
	}

	LoadRecord &loadRec = InsertRecord(filename.c_str(), false);

	_LoadTheRecord(loadRec);

	return loadRec.Obj;
}
//----------------------------------------------------------------------------
Object *ResourceManager::BlockLoadCopy (const std::string &filename)
{
	Object *obj = BlockLoad(filename);

	if (obj)
	{
		return obj->Copy("");
	}

	return 0;
}
//----------------------------------------------------------------------------
Object *ResourceManager::BlockLoadShareCopy (const std::string &filename, bool vb,
	bool ib, bool mi)
{
	Object *obj = BlockLoad(filename);

	if (obj)
	{
		return ShareCopy(obj, vb, ib, mi);
	}

	return 0;
}
//----------------------------------------------------------------------------
bool ResourceManager::CreateFloder (const std::string &parentPath, 
	const std::string &path)
{
	std::string tempPath = path;
	int index = 0;

	bool bIsTrue = true;
	while (bIsTrue)
	{
		int pos = (int)tempPath.find('/', index);
		if(-1 == pos)
		{
			break;
		}

		std::string dirPath = parentPath;

		dirPath.append(tempPath.substr(0, pos));

#if defined(_WIN32) || defined(WIN32)
		if ((GetFileAttributesA(dirPath.c_str())) == INVALID_FILE_ATTRIBUTES)
		{
			CreateDirectoryA(dirPath.c_str(), 0);
		}
#else
#ifdef __MARMALADE__
		if("ram:"!=dirPath && "ram:/"!=dirPath)
#else
		if ("/data"!=dirPath && "/data/data"!=dirPath)
#endif
		{
			DIR *pDir = 0;
			//打开该路径
			pDir = opendir (dirPath.c_str());
			if (! pDir)
			{
				//创建该路径
				mkdir(dirPath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
			}
			else closedir(pDir);
		}
#endif

		index = pos + 1;
	}

	return true;
}
//----------------------------------------------------------------------------
bool ResourceManager::IsFloderExist (const std::string &parentPath, 
	const std::string &path)
{
	std::string dirPath = parentPath;
	dirPath.append(path);

	if (0 == access(dirPath.c_str(), 0))
	{
		return false;
	}

	return true;
}
//----------------------------------------------------------------------------
bool ResourceManager::LoadBuffer (const std::string &filename, int &bufferSize, 
	char* &buffer)
{
	if (filename == "")
	{
		assertion(false, "filename must not be null");
	}

	LoadRecord &loadRec = InsertRecord(filename.c_str(), true);

	_LoadTheRecord(loadRec);

	buffer = loadRec.Buffer;
	bufferSize = loadRec.BufferSize;

	if (buffer && 0!=bufferSize)
		return true;
	else
	{
		loadRec.Buffer = 0;
		loadRec.BufferSize = 0;

		assertion(false, "load Buffer failed.\n");
		return false;
	}
}
//----------------------------------------------------------------------------
Object *ResourceManager::ShareCopyVB_IB (Object *objFrom)
{
	if (!objFrom)
		return 0;

	Object *obj = objFrom->Copy("");
	
	if (obj)
	{
		Node *node = DynamicCast<Node>(obj);
		if (node)
		{
			ShareCopyProcess(node, (Node*)objFrom, true, true, false);
		}
		Renderable *renderable = DynamicCast<Renderable>(obj);
		if (renderable)
		{
			ShareCopyProcess(renderable, (Renderable*)objFrom, true, true,
				false);
		}
	}

	return obj;
}
//----------------------------------------------------------------------------
Object *ResourceManager::ShareCopyVB_IB_MI (Object *objFrom)
{
	if (!objFrom)
		return 0;

	Object *obj = objFrom->Copy("");

	if (obj)
	{
		Node *node = DynamicCast<Node>(obj);
		if (node)
		{
			ShareCopyProcess(node, (Node*)objFrom, true, true, true);
		}
		Renderable *renderable = DynamicCast<Renderable>(obj);
		if (renderable)
		{
			ShareCopyProcess(renderable, (Renderable*)objFrom, true, true,
				true);
		}
	}

	return obj;
}
//----------------------------------------------------------------------------
Object *ResourceManager::ShareCopyMI (Object *objFrom)
{
	if (!objFrom)
		return 0;

	Object *obj = objFrom->Copy("");

	if (obj)
	{
		Node *node = DynamicCast<Node>(obj);
		if (node)
		{
			ShareCopyProcess(node, (Node*)objFrom, false, false, true);
		}
		Renderable *renderable = DynamicCast<Renderable>(obj);
		if (renderable)
		{
			ShareCopyProcess(renderable, (Renderable*)objFrom, false, false,
				true);
		}
	}

	return obj;
}
//----------------------------------------------------------------------------
Object *ResourceManager::ShareCopy (Object *objFrom, bool vb, bool ib,
	bool mi)
{
	if (!objFrom)
		return 0;

	Object *obj = objFrom->Copy("");

	if (obj)
	{
		Node *node = DynamicCast<Node>(obj);
		if (node)
		{
			ShareCopyProcess(node, (Node*)objFrom, vb, ib, mi);
		}
		Renderable *renderable = DynamicCast<Renderable>(obj);
		if (renderable)
		{
			ShareCopyProcess(renderable, (Renderable*)objFrom, vb, ib,
				mi);
		}
	}

	return obj;
}
//----------------------------------------------------------------------------
void ResourceManager::Dump (const std::string &filename)
{
	ScopedCS dequeCS(mResTableMutex);

	FILE* outFile = 0;
	outFile = fopen(filename.c_str(), "wt");

	std::string format = "RCout: %6d ,";
	format += "RT: %2d , ";
	format += "BufferSize: %13d , ";
	format += "Filename: %s \n";

	ResTableIterator iter = mResTable.Iterate(0);
	while (iter)
	{
		ScopedCS recordCS(mLoadRecordMutex);

		LoadRecord &record = iter->value;

		if (LS_LOADED==record.State)
		{
			int refCount = -1;
			if (LoadRecord::RT_OBJECT == record.TheRecordType)
			{
				refCount = record.Obj.GetCount();
			}
			else if (LoadRecord::RT_BUFFER == record.TheRecordType)
			{
				refCount = record.Buffer.GetCount();
			}
			else
			{
				refCount = 1;
			}

			fprintf(outFile, format.c_str(), refCount, (int)record.TheRecordType, record.BufferSize, record.Filename.c_str());
		}

		iter = mResTable.Iterate(iter);
	}

	if (outFile)
	{
		fclose(outFile);
	}
}
//----------------------------------------------------------------------------
void ResourceManager::BeginDumpDiff ()
{
	mBeginDumpDiffFiles.clear();

	ScopedCS dequeCS(mResTableMutex);

	ResTableIterator iter = mResTable.Iterate(0);
	while (iter)
	{
		ScopedCS recordCS(mLoadRecordMutex);
	
		LoadRecord &record = iter->value;
		mBeginDumpDiffFiles.push_back(record.Filename);

		iter = mResTable.Iterate(iter);
	}
}
//----------------------------------------------------------------------------
void ResourceManager::EndDumpDiff (const std::string &filename)
{
	ScopedCS dequeCS(mResTableMutex);

	FILE* outFile = 0;
	outFile = fopen(filename.c_str(), "wt");

	std::string format = "RCout: %6d ,";
	format += "RT: %2d , ";
	format += "BufferSize: %13d , ";
	format += "Filename: %s \n";

	ResTableIterator iter = mResTable.Iterate(0);
	while (iter)
	{
		ScopedCS recordCS(mLoadRecordMutex);

		LoadRecord &record = iter->value;

		if (LS_LOADED == record.State)
		{
			int refCount = -1;
			if (LoadRecord::RT_OBJECT == record.TheRecordType)
			{
				refCount = record.Obj.GetCount();
			}
			else if (LoadRecord::RT_BUFFER == record.TheRecordType)
			{
				refCount = record.Buffer.GetCount();
			}
			else
			{
				refCount = 1;
			}

			std::vector<std::string>::iterator it = std::find(mBeginDumpDiffFiles.begin(), mBeginDumpDiffFiles.end(), record.Filename);
			if (it == mBeginDumpDiffFiles.end())
			{
				fprintf(outFile, format.c_str(), refCount, (int)record.TheRecordType, record.BufferSize, record.Filename.c_str());
			}
		}

		iter = mResTable.Iterate(iter);
	}

	if (outFile)
	{
		fclose(outFile);
	}
}
//----------------------------------------------------------------------------
bool ResourceManager::IsTexPack (const std::string &texPackPath)
{
	int bufferSize = 0;
	char *buffer = 0;
	if (LoadBuffer(texPackPath, bufferSize, buffer))
	{
		std::string outPath;
		std::string outBaseName;
		std::string outExt;
		StringHelp::SplitFullFilename(texPackPath, outPath, outBaseName, outExt);

		if ("xml"==outExt || "XML"==outExt)
		{
			XMLData data;
			if (data.LoadBuffer(buffer, bufferSize))
			{
				XMLNode rootNode = data.GetRootNode();
				std::string name = rootNode.GetName();

				if ("TextureAtlas" == name)
				{
					return true;
				}
			}
		}
	}

	return false;
}
//----------------------------------------------------------------------------
bool ResourceManager::AddTexPack (const std::string &texPackPath)
{
	mTexPacksMutex->Enter();

	bool isHasUpdate = IsHasUpdate(texPackPath);

	HashTable<FString, TexPack, FixedStringHashCoder>::Element *it =
		mTexPacks.Find(texPackPath.c_str());
	if (0!=it)
	{
		if (isHasUpdate && !it->value.IsHasUpdate)
		{
			// 如果有跟新，且当前没更新过，就让过去，进行更新
		}
		else
		{
			mTexPacksMutex->Leave();
			return false;
		}
	}

	char *buffer = 0;
	int bufferSize = 0;
	if (LoadBuffer(texPackPath, bufferSize, buffer))
	{
		XMLData data;
		if (data.LoadBuffer(buffer, bufferSize))
		{
			std::string outPath;
			std::string outBaseName;
			std::string outExt;
			StringHelp::SplitFullFilename(texPackPath, outPath, outBaseName, outExt);

			XMLNode rootNode = data.GetRootNode();

			std::string imagePath = rootNode.AttributeToString("imagePath");
			int width = rootNode.AttributeToInt("width");
			int height = rootNode.AttributeToInt("height");
			TexPack pack;
			pack.ImageFullPath = outPath+imagePath;
			pack.ImagePath = imagePath;
			pack.Width = width;
			pack.Height = height;
			pack.IsHasUpdate = isHasUpdate;

			XMLNode childNode = rootNode.IterateChild();
			while (!childNode.IsNull())
			{
				std::string eleName;
				int x = 0;
				int y = 0;
				int w = 0;
				int h = 0;
				int oX = 0;
				int oY = 0;
				int oW = 0;
				int oH = 0;
				bool rolated = false;

				if (childNode.HasAttribute("n"))
					eleName = childNode.AttributeToString("n");
				if (childNode.HasAttribute("x"))
					x = childNode.AttributeToInt("x");
				if (childNode.HasAttribute("y"))
					y = childNode.AttributeToInt("y");
				if (childNode.HasAttribute("w"))
					w = childNode.AttributeToInt("w");
				if (childNode.HasAttribute("h"))
					h = childNode.AttributeToInt("h");
				if (childNode.HasAttribute("oX"))
					oX = childNode.AttributeToInt("oX");
				if (childNode.HasAttribute("oY"))
					oY = childNode.AttributeToInt("oY");
				if (childNode.HasAttribute("oW"))
					oW = childNode.AttributeToInt("oW");
				if (childNode.HasAttribute("oH"))
					oH = childNode.AttributeToInt("oH");
				if (childNode.HasAttribute("r"))
					rolated = (std::string(childNode.AttributeToString("r"))=="y");

				TexPackElement ele;
				ele.X = x;
				ele.Y = y;
				ele.W = w;
				ele.H = h;
				ele.OX = oX;
				ele.OY = oY;
				ele.OW = oW;
				ele.OH = oH;
				ele.Rolated = rolated;
				ele.TexWidth = width;
				ele.TexHeight = height;
				ele.ElementName = eleName;
				ele.ImagePathFull = outPath+imagePath;

				pack.Elements.push_back(ele);

				std::string allStr = texPackPath+eleName;

				mPackElements.Insert(allStr.c_str(), ele);

				childNode = rootNode.IterateChild(childNode);
			}

			mTexPacks.Insert(texPackPath.c_str(), pack);

			mTexPacksMutex->Leave();

			return true;
		}
	}

	mTexPacksMutex->Leave();

	return false;
}
//----------------------------------------------------------------------------
const TexPack &ResourceManager::GetTexPack (const std::string &texPackPath)
{
	mTexPacksMutex->Enter();

	HashTable<FString, TexPack, FixedStringHashCoder>::Element *it =
		mTexPacks.Find(texPackPath.c_str());
	if (it)
	{
		mTexPacksMutex->Leave();

		return it->value;
	}

	mTexPacksMutex->Leave();

	return msIvalidTexPack;
}
//----------------------------------------------------------------------------
const TexPackElement &ResourceManager::GetTexPackElement (
	const std::string &texPackPath, const std::string &eleName)
{
	mTexPacksMutex->Enter();

	std::string allStr = texPackPath+eleName;

	HashTable<FString, TexPackElement, FixedStringHashCoder>::Element *it =
		mPackElements.Find(allStr.c_str());

	if (it)
	{
		mTexPacksMutex->Leave();
		return it->value;
	}

	mTexPacksMutex->Leave();

	return msIvalidTexPackElement;
}
//----------------------------------------------------------------------------
ResHandle ResourceManager::BackgroundLoad (
	const std::string &filename)
{
	LoadRecord &rec = InsertRecord(filename.c_str(), false);

	{
		ScopedCS scopedCS(mLoadRecordMutex);

		if (LS_UNLOADED == rec.State)
		{
			ScopedCS scopedCSLoadingDeque(mLoadingDequeMutex);
			rec.State = LS_LOADQUE;
			mLoadingDeque.push_front(&rec);

			PostCondition(mLoadingDequeCondition);
		}
	}

	return (ResHandle)&rec;
}
//----------------------------------------------------------------------------
ResHandle ResourceManager::BackgroundDoFun (const std::string &funName, 
	BackgroundFun func)
{
	LoadRecord &rec = InsertRecord(funName.c_str(), func);

	{
		ScopedCS scopedCS(mLoadRecordMutex);		

		if (LS_UNLOADED == rec.State)
		{
			ScopedCS scopedCSLoadingDeque(mLoadingDequeMutex);
			rec.State = LS_LOADQUE;
			mLoadingDeque.push_front(&rec);

			PostCondition(mLoadingDequeCondition);
		}
	}

	return (ResHandle)&rec;
}
//----------------------------------------------------------------------------
void ResourceManager::SetUseGarbageCollect (bool use)
{
	mIsUseGarbageCollect = use;

	if (!mIsUseGarbageCollect)
	{
		Clear();
	}
}
//----------------------------------------------------------------------------
Object *ResourceManager::CheckRes (ResHandle handle)
{
	if (0 == handle)
		return 0;

	LoadRecord &rec = *((LoadRecord *)handle);

	if (LS_LOADED==rec.State && rec.TheRecordType==LoadRecord::RT_OBJECT)
	{
		return rec.Obj;
	}

	return 0;
}
//----------------------------------------------------------------------------
bool ResourceManager::CheckFun (ResHandle handle)
{
	if (0 == handle)
		return false;

	LoadRecord &rec = *((LoadRecord *)handle);

	if (LS_LOADED == rec.State && rec.TheRecordType==LoadRecord::RT_FUN)
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
ResourceManager::LoadState ResourceManager::GetResLoadState (ResHandle handle)
{
	LoadRecord &rec = *(LoadRecord *)handle;
	
	return rec.State;
}
//----------------------------------------------------------------------------
void ResourceManager::GarbageCollect (double appSeconds, double elapsedSeconds)
{
	mGarbageUpdateTime -= (float)elapsedSeconds;
	if (mGarbageUpdateTime > 0.0f)
	{
		return;
	}
	else
	{
		mGarbageUpdateTime = 1.0f;
	}

	ScopedCS dequeCS(mResTableMutex);

	ResTableIterator iter = mResTable.Iterate(0);
	while (iter)
	{
		ScopedCS recordCS(mLoadRecordMutex);

		LoadRecord &record = iter->value;

		if (LS_LOADED==record.State && 
			appSeconds>(record.LastTouchedTime+mGarbageCollectTime))
		{
			if (LoadRecord::RT_OBJECT==record.TheRecordType &&
				1==record.Obj.GetCount())
			{
				ResTableIterator iter2 = mResTable.Iterate(iter);
				mResTable.Erase(iter);
				iter = iter2;
			}
			else if (LoadRecord::RT_BUFFER==record.TheRecordType &&
				1==record.Buffer.GetCount())
			{
				ResTableIterator iter2 = mResTable.Iterate(iter);
				mResTable.Erase(iter);
				iter = iter2;
			}
			else
			{
				iter = mResTable.Iterate(iter);
			}
		}
		else
		{
			iter = mResTable.Iterate(iter);
		}
	}
}
//----------------------------------------------------------------------------
ResourceManager::LoadRecord::LoadRecord ()
{
	TheRecordType = RT_OBJECT;
	Fun = 0;
	LastTouchedTime = 0;
	State = LS_UNLOADED;
	BufferSize = 0;
}
//----------------------------------------------------------------------------
ResourceManager::LoadRecord::~LoadRecord ()
{
	Buffer = 0;
}
//----------------------------------------------------------------------------
unsigned int ResourceManager::RunLoadingThread ()
{
	LoadRecord *rec = 0;

	while (!mQuitLoading)
	{
		WaitCondition(mLoadingDequeCondition);

		if (mQuitLoading)
			break;

		{
			ScopedCS scopedCS(mLoadingDequeMutex);

			if (mLoadingDeque.empty())
				continue;

			rec = mLoadingDeque.front();
			mLoadingDeque.pop_front();
		}

		_LoadTheRecord(*rec);
	}

	return 0;
}
//----------------------------------------------------------------------------
#if defined(__ANDROID__) || defined(__IOS__)
static bool CheckResourceCCZFile(std::string &inoutPath)
{
	std::string outPath;
	std::string outBaseName;
	std::string outExtention;
	StringHelp::SplitFullFilename(inoutPath, outPath, outBaseName, outExtention);
	//std::transform(outExtention.begin(), outExtention.end(), outExtention.begin(), std::tolower);

	char *buffer = 0;
	int bufferSize = 0;
	std::string newPath;
	if ("dds"==outExtention || "DDS"==outExtention)
	{
		newPath = outPath + outBaseName + ".pvr.ccz";
		/*
		struct stat fileStat;
		std::string tmppath = newPath.substr(5);
		if(stat(tmppath.c_str(), &fileStat) < 0) //ccz文件不存在
		{
			return false;
		}
		*/

		inoutPath = newPath;
		return true;
	}
	return false;
}
#endif
//----------------------------------------------------------------------------
ResourceManager::LoadRecord &ResourceManager::InsertRecord (
	const FString &fn, bool isBuffer)
{
	std::string writeablePath = PX2_RM.GetWriteablePath();

	std::string dstFilename = (const char*)fn;

#if defined(__ANDROID__) || defined(__IOS__)
	CheckResourceCCZFile(dstFilename);
#endif

	bool isHasUpdate = IsHasUpdate(dstFilename, dstFilename);

	ScopedCS scopeCS(mResTableMutex);

	ResTableIterator pelement = mResTable.Find(dstFilename.c_str());
	if (0!=pelement)
	{
		pelement->value.LastTouchedTime = GetTimeInSeconds();
		return pelement->value;
	}

	pelement = mResTable.Insert(dstFilename.c_str());

	LoadRecord &rec = pelement->value;
	rec.Filename = dstFilename;
	rec.State = LS_UNLOADED;
	rec.TheRecordType = isBuffer ? LoadRecord::RT_BUFFER : LoadRecord::RT_OBJECT;
	rec.LastTouchedTime = GetTimeInSeconds();

	return rec;
}
//----------------------------------------------------------------------------
ResourceManager::LoadRecord &ResourceManager::InsertRecord (
	const FString &funName, BackgroundFun fun)
{
	ScopedCS scopeCS(mResTableMutex);

	ResTableIterator pelement = mResTable.Insert(funName);

	LoadRecord &rec = pelement->value;
	rec.TheRecordType = LoadRecord::RT_FUN;
	rec.Filename = funName;
	rec.Fun = fun;
	rec.State = LS_UNLOADED;
	rec.LastTouchedTime = GetTimeInSeconds();

	return rec;
}
//----------------------------------------------------------------------------
void ResourceManager::_LoadTheRecord (LoadRecord &rec)
{
	bool needLoad = false;
	{
		ScopedCS scopedCS(mLoadRecordMutex);

		if (LS_UNLOADED == rec.State || LS_LOADQUE == rec.State)
		{
			rec.State = LS_LOADING;
			needLoad = true;
		}
	}

	if (needLoad)
	{
		if (rec.TheRecordType == LoadRecord::RT_FUN)
		{
			rec.Fun();
			rec.LastTouchedTime = GetTimeInSeconds();
		}
		else if (rec.TheRecordType == LoadRecord::RT_OBJECT)
		{
			rec.Obj = _LoadObject(rec.Filename);
			rec.LastTouchedTime = GetTimeInSeconds();
		}
		else if (rec.TheRecordType == LoadRecord::RT_BUFFER)
		{
			char *buffer = 0;
			int bufferSize = 0;
			if (_LoadBuffer(rec.Filename, bufferSize, buffer))
			{
				rec.Buffer = buffer;
				rec.BufferSize = bufferSize;
			}
			rec.LastTouchedTime = GetTimeInSeconds();
		}

		rec.State = LS_LOADED;
	}

	// 可能其他线程正在加载这个资源
	while (rec.State != LS_LOADED)
	{
		System::SleepSeconds(0.01f);
	}
}
//----------------------------------------------------------------------------
Object *ResourceManager::_LoadObject (const std::string &filename)
{
	Object *obj = 0;

	std::string outPath;
	std::string outBaseName;
	std::string outExtention;
	StringHelp::SplitFullFilename(filename, outPath, outBaseName, outExtention);
	char *buffer = 0;
	int bufferSize = 0;
	if("dds"==outExtention || "DDS"==outExtention)
	{
		obj = LoadTextureFromDDS(filename);
	}
	else if (_LoadBuffer(filename, bufferSize, buffer))
	{
		if ("ccz"==outExtention)
		{
			obj = LoadTextureFromPVRTC_CCZ(bufferSize, buffer);
		}
		else if ("png"==outExtention || "PNG"==outExtention || "jpg"==outExtention 
			|| "JPG"==outExtention )
		{
			obj = LoadTexFormOtherImagefile(outExtention, bufferSize, buffer);
		}
		else
		{
			InStream inStream;
			inStream.Load1(bufferSize, buffer);
			obj = inStream.GetObjectAt(0);
		}

		delete1(buffer);
		bufferSize = 0;
	}

	if (obj)
	{
		obj->SetResourcePath(filename);
	}

	return obj;
}
//----------------------------------------------------------------------------
bool ResourceManager::_LoadBuffer (const std::string &fn,
	int &bufferSize, char* &buffer)
{
	std::string dstFilename = fn;

	bool hasUpdate = false;
	if (dstFilename.find(mDataUpdatePath)!=std::string::npos)
	{
		hasUpdate = true;
	}

#ifdef __MARMALADE__
	if (!hasUpdate)
	{
		assert(strstr(dstFilename.c_str(), "Data") == dstFilename.c_str());
		dstFilename = dstFilename.substr(5);
	}
	return FileIO::Load(dstFilename, true, bufferSize, buffer);
#else

#ifdef __ANDROID__
	if (!hasUpdate)
	{
		std::string fullFilename = dstFilename;
		fullFilename.insert(0, "assets/");
		return GetFileDataFromZip(msResPath, fullFilename, bufferSize, buffer);
	}
	else
	{
		return FileIO::Load(dstFilename, true, bufferSize, buffer);
	}
#else
    std::string fullFilename = msResPath + dstFilename;
	return FileIO::Load(fullFilename, true, bufferSize, buffer);
#endif

#endif
}
//----------------------------------------------------------------------------
bool ResourceManager::SaveTex2DPNG(Texture2D *tex2d, const std::string &filename)
{
	/*int width = tex2d->GetWidth();
	int height = tex2d->GetHeight();
	int bytePerPixel = tex2d->GetPixelSize();

	ILuint image;
	ilGenImages(1, &image);
	ilBindImage(image);

	ilLoadDataL(tex2d->GetData(0), width*height*bytePerPixel, width, height, 1, bytePerPixel);

	ilEnable(IL_FILE_OVERWRITE);
	ilSave(IL_PNG, filename.c_str());

	ilDeleteImages(1, &image);*/

	return true;
}
//----------------------------------------------------------------------------
bool ResourceManager::LoadDataVersionXML (const std::string &filename)
{
	mDataVersionItem = 0;

	char *buffer = 0;
	int bufferSize = 0;
	if (PX2_RM.LoadBuffer(filename, bufferSize, buffer))
	{
		XMLData data;
		if (data.LoadBuffer(buffer, bufferSize))
		{
			XMLNode rootNode = data.GetRootNode();
			std::string name = rootNode.GetName();
			if (!rootNode.IsNull() && "Version"==name)
			{
				std::string val = rootNode.AttributeToString("value");
				mDataVersionItem = new0 ResourceVersionItem();
				mDataVersionItem->Version = ResourceVersion(val);
			}
		}

		return true;
	}
	else
	{
		assertion(false, "LoadDataVersionXML &s failed.\n", filename.c_str());
		return false;
	}
}
//----------------------------------------------------------------------------
bool ResourceManager::LoadDataUpateVersionXML (const std::string &filename)
{
	mDataUpdateVersionItem = 0;

	if (access(filename.c_str(), 0) != 0)
	{
		return false;
	}

	char *buffer = 0;
	int bufferSize = 0;
	if (FileIO::Load(filename,true, bufferSize, buffer))
	{
		XMLData data;
		if (data.LoadBuffer(buffer, bufferSize))
		{
			XMLNode rootNode = data.GetRootNode();
			std::string name = rootNode.GetName();
			if (!rootNode.IsNull() && "Version"==name)
			{
				std::string val = rootNode.AttributeToString("value");
				mDataUpdateVersionItem = new0 ResourceVersionItem();
				mDataUpdateVersionItem->Version = ResourceVersion(val);
			}
		}

		delete1(buffer);
		bufferSize = 0;

		return true;
	}
	else
	{
		assertion(false, "LoadDataVersionXML &s failed.\n", filename.c_str());
		return false;
	}
}
//----------------------------------------------------------------------------
bool ResourceManager::LoadUpdateVersionXML (const std::string &filename)
{
	mUpdateVersionItem = 0;

	if (access(filename.c_str(), 0) != 0)
	{
		return false;
	}

	char *buffer = 0;
	int bufferSize = 0;
	bool ret = false;

	if (FileIO::Load(filename, true, bufferSize, buffer))
	{
		XMLData data;
		if (data.LoadBuffer(buffer, bufferSize))
		{
			XMLNode rootNode = data.GetRootNode();
			std::string name = rootNode.GetName();
			if (!rootNode.IsNull() && "Version"==name)
			{
				std::string val = rootNode.AttributeToString("value");

				mUpdateVersionItem = new0 ResourceVersionItem();
				mUpdateVersionItem->Version = ResourceVersion(val);

				ret = true;
			}
		}

		delete1(buffer);
		bufferSize = 0;
	}

	return ret;
}
//----------------------------------------------------------------------------
void ResourceManager::BeginWriteVersionList ()
{
	mVersionListToWrite.clear();
}
//----------------------------------------------------------------------------
void ResourceManager::AddVersionFile (const std::string &filename, 
	DirType type) // 仅供PC使用
{
	// version.xml 不需要计算版本信息
	if (filename.find("version.xml") != string::npos)
		return;

	// versionList.dat 不需要计算版本信息
	if (filename.find("versionList.dat") != string::npos)
		return;

	if (filename.find("libPX2GamePlayJNI.so") != std::string::npos)
		return;

	char *buffer = 0;
	int bufferSize = 0;
	if (FileIO::Load(filename, true, bufferSize, buffer))
	{
		ResourceFileMark mark;

		std::string savedPath = filename;
		if (type == DT_WIN)
		{
			// empty
		}
		else if (type == DT_ANDROID)
		{
			std::string repaceStr = "DataAndroid/";
			savedPath = savedPath.substr(repaceStr.length(), savedPath.length()-repaceStr.length());
			savedPath = "Data/" + savedPath;
		}
		else if (type == DT_IOS)
		{
			std::string repaceStr = "DataIOS/";
			savedPath = savedPath.substr(repaceStr.length(), savedPath.length()-repaceStr.length());
			savedPath = "Data/" + savedPath;
		}

		mark.Path = savedPath;
		mark.BufferSize = bufferSize;
		Md5String(mark.MD5, buffer, bufferSize);

		mVersionListToWrite.push_back(mark);

		delete1(buffer);
		bufferSize = 0;
	}
	else
	{
		assertion(false, "AddVersionFile &s failed.\n", filename.c_str());
		PX2_LOG_ERROR("AddVersionFile &s failed.\n", filename.c_str());
	}
}
//----------------------------------------------------------------------------
void ResourceManager::EndWriteVersionList (const std::string &filename)
{
	FileIO out;
	if (out.Open(filename, FileIO::FM_DEFAULT_WRITE))
	{
		int32_t version = ResourceFileMark::ResourceUpdateVersion;
		out.Write(sizeof(int), &version);
		
		int32_t num = (int32_t)mVersionListToWrite.size();
		out.Write(sizeof(num), &num);
		for (int i=0; i<num; i++)
		{
			const ResourceFileMark &mark = mVersionListToWrite[i];

			int pathLen = (int)mark.Path.length();
			out.Write(sizeof(int), &pathLen);
			out.Write(sizeof(char), (int)mark.Path.length(), &(mark.Path[0]));
			out.Write(sizeof(mark.BufferSize), &mark.BufferSize);
			out.Write(sizeof(char), 16, &mark.MD5[0]);
		}

		int endValue = mEndVersionList;
		out.Write(sizeof(int), &endValue);

		out.Close();

		PX2_LOG_INFO("EndWriteVersionList: %d", num);
	}
}
//----------------------------------------------------------------------------
void ResourceManager::WriteDataList (const std::string &filename, 
	VersionListTable &table)
{
	FileIO out;
	if (out.Open(filename, FileIO::FM_DEFAULT_WRITE))
	{
		int32_t version = ResourceFileMark::ResourceUpdateVersion;
		out.Write(sizeof(int), &version);

		int num = 0;
		VersionListTable::Element *ele = table.Iterate(0);
		while (ele)
		{
			num++;
			ele = table.Iterate(ele);
		}

		out.Write(sizeof(num), &num);

		ele = table.Iterate(0);
		while (ele)
		{
			const ResourceFileMark &mark = ele->value;
			
			int pathLen = (int)mark.Path.length();
			out.Write(sizeof(int), &pathLen);
			out.Write(sizeof(char), (int)mark.Path.length(), &(mark.Path[0]));
			out.Write(sizeof(mark.BufferSize), &mark.BufferSize);
			out.Write(sizeof(char), 16, &mark.MD5[0]);

			ele = table.Iterate(ele);
		}

		int endValue = mEndVersionList;
		out.Write(sizeof(int), &endValue);

		out.Close();
	}
}
//----------------------------------------------------------------------------
bool ResourceManager::IsVersionListValued (const std::string &filename)
{
	char *buffer = 0;
	int bufferSize = 0;
	if (PX2_RM.LoadBuffer(filename, bufferSize, buffer))
	{
		if (bufferSize < sizeof(int))
		{
			return false;
		}

		BufferIO in;
		if (in.Open(bufferSize, buffer, BufferIO::BM_DEFAULT_READ))
		{
			in.IncrementNumBytesProcessed(bufferSize-sizeof(int));
			
			int endVal = 0;
			in.Read(sizeof(endVal), &endVal);

			if (mEndVersionList != endVal)
			{
				in.Close();

				return false;
			}

			in.Close();
		}

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool ResourceManager::LoadDataVersionList (const std::string &filename)
{
	mDataVersionList.Clear();

	if (!IsVersionListValued(filename))
		return false;

	char *buffer = 0;
	int bufferSize = 0;
	if (PX2_RM.LoadBuffer(filename, bufferSize, buffer))
	{
		BufferIO in;
		if (in.Open(bufferSize, buffer, BufferIO::BM_DEFAULT_READ))
		{
			ReadVersionList(in, mDataVersionList);

			in.Close();
		}

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool ResourceManager::LoadDataUpdateVersionList (const std::string &filename)
{
	mDataUpdateVersionList.Clear();

	if (access(filename.c_str(), 0) != 0)
	{
		return false;
	}

	if (!IsVersionListValued(filename))
		return false;

	FileIO in;
	if (in.Open(filename, FileIO::FM_DEFAULT_READ))
	{
		ReadVersionList(in, mDataUpdateVersionList);

		in.Close();

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool ResourceManager::LoadUpdateVersionList (const std::string &filename)
{
	mUpdateVersionList.Clear();

	if (access(filename.c_str(), 0) != 0)
	{
		return false;
	}

	if (!IsVersionListValued(filename))
		return false;

	FileIO in;
	if (in.Open(filename, FileIO::FM_DEFAULT_READ))
	{
		ReadVersionList(in, mUpdateVersionList);

		in.Close();

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool ResourceManager::IsHasUpdate (const std::string &filename)
{
	// 更新表里有新的
	VersionListTable::Element *ele = mDataUpdateVersionList.Find(filename.c_str());
	if (ele)
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool ResourceManager::IsHasUpdate (const std::string &filename,
	std::string &outUpdatedFilename)
{
	std::string writeablePath = PX2_RM.GetWriteablePath();

	// 更新表里有新的
	VersionListTable::Element *ele = mDataUpdateVersionList.Find(filename.c_str());
	if (ele)
	{
		std::string replaceFilename = filename;
		std::string left = "Data/";

		replaceFilename = replaceFilename.substr(left.length(), replaceFilename.length()-left.length());
		replaceFilename = writeablePath + mDataUpdatePath + replaceFilename;

		outUpdatedFilename = replaceFilename;

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void ResourceManager::ReadVersionList (FileIO &in, VersionListTable &table)
{
	int curVersion = 0;
	in.Read(sizeof(curVersion), &curVersion);

	int num = 0;
	in.Read(sizeof(num), &num);
	for (int i=0; i<num; i++)
	{
		ResourceFileMark mark;

		int pathLen = 0;
		in.Read(sizeof(pathLen), &pathLen);
		mark.Path.resize(pathLen);
		in.Read(sizeof(char), pathLen, &mark.Path[0]);
		in.Read(sizeof(mark.BufferSize), &mark.BufferSize);
		in.Read(sizeof(char), 16, &mark.MD5[0]);

		table.Insert(mark.Path.c_str(), mark);
	}
}
//----------------------------------------------------------------------------
void ResourceManager::ReadVersionList (BufferIO &in, VersionListTable &table)
{
	int curVersion = 0;
	in.Read(sizeof(curVersion), &curVersion);

	int num = 0;
	in.Read(sizeof(num), &num);
	for (int i=0; i<num; i++)
	{
		ResourceFileMark mark;

		int pathLen = 0;
		in.Read(sizeof(pathLen), &pathLen);
		mark.Path.resize(pathLen);
		in.Read(sizeof(char), pathLen, &mark.Path[0]);
		in.Read(sizeof(mark.BufferSize), &mark.BufferSize);
		in.Read(sizeof(char), 16, &mark.MD5[0]);

		table.Insert(mark.Path.c_str(), mark);
	}
}
//----------------------------------------------------------------------------
bool ResourceManager::Download (const std::string &fullPath,
	const std::string &url)
{
	//if (!IsFloderExist("", fullPath))
	CreateFloder("", fullPath);

	//return mCurlDownLoad->Download(fullPath, url);
    return false;
}
//----------------------------------------------------------------------------
void ResourceManager::DoResourceUpdateStuffs (const std::string &wwwAddr)
{
#ifdef __MARMALADE__
	return;
#endif

	std::string writeablePath = PX2_RM.GetWriteablePath();

	ResourceVersion localVersion;

	// data
	PX2_RM.LoadDataVersionXML("Data/version.xml");
	const ResourceVersionItem *dataRVI = PX2_RM.GetDataVersionItem();
	PX2_RM.LoadDataVersionList("Data/versionList.dat");
	ResourceManager::VersionListTable &dataList = PX2_RM.GetDataVersionList ();
	if (dataRVI)
		localVersion = dataRVI->Version;

	// data update
	PX2_RM.LoadDataUpateVersionXML(writeablePath + mDataUpdatePath + "version.xml");
	const ResourceVersionItem *dataUpdateRVI = PX2_RM.GetDataUpdateVersionItem();
	ResourceManager::VersionListTable *dataUpdateList = 0;
	if (dataUpdateRVI)
	{
		localVersion = dataUpdateRVI->Version;

		if (PX2_RM.LoadDataUpdateVersionList(writeablePath + mDataUpdatePath + "versionList.dat"))
		{
			dataUpdateList = &(PX2_RM.GetDataUpdateVersionList ());
		}
	}

	PX2_RM.SetVersion(localVersion);

	// 下载更新资源xml
	std::string wVersionXMLPath_Temp = writeablePath + mDataUpdatePath + "version_Temp.xml";
	std::string wwwVersionXMLURL = wwwAddr + mDataUpdatePath + "version.xml";

	if (!PX2_RM.Download(wVersionXMLPath_Temp, wwwVersionXMLURL)) // 下载
		return;
	//PX2_RM.LoadUpdateVersionXML (wVersionXMLPath_Temp);
	const ResourceVersionItem *updateRVI = PX2_RM.GetUpdateVersionItem ();

	// 有更新, 杂七杂八的事情开始了
	if (updateRVI)
	{
		// 只要资源有更新就更新
		if (updateRVI->Version.GetRes()>localVersion.GetRes())
		{
			// 将versionList下载下来
			std::string wVersionListPath_Temp = writeablePath + mDataUpdatePath + "versionList_Temp.dat";
			std::string wwwVersionListURL = wwwAddr + mDataUpdatePath + "versionList.dat";
			if (!PX2_RM.Download(wVersionListPath_Temp, wwwVersionListURL))
				return;

			// 读取更新表
			PX2_RM.LoadUpdateVersionList(wVersionListPath_Temp);
			ResourceManager::VersionListTable &updateVersionList = PX2_RM.GetUpdateVersionList();

			// 数量
			int numElements = 0;
			ResourceManager::VersionListTable::Element *newestUpdateEle0 = updateVersionList.Iterate(0);
			while (newestUpdateEle0)
			{
				numElements++;
				newestUpdateEle0 = updateVersionList.Iterate(newestUpdateEle0);
			}

			Pointer0<ResourceManager::VersionListTable> recreateUpdateDataList = new0 ResourceManager::VersionListTable(1023);
			if (0 != numElements)
			{
				int curEleIndex = 0;

				// 遍历表，如果这个资源原先没有就添加，如果有了MD5不同就直接下载
				ResourceManager::VersionListTable::Element *newestUpdateEle = updateVersionList.Iterate(0);
				while (newestUpdateEle)
				{
					const ResourceFileMark &newestUpdateMark = newestUpdateEle->value;
					bool doDownLoad = false;

					ResourceManager::VersionListTable::Element *dataMark = dataList.Find(newestUpdateEle->key);
					ResourceManager::VersionListTable::Element *dataUpdateMark = 0;
					if (dataUpdateList)
					{
						dataUpdateMark = dataUpdateList->Find(newestUpdateEle->key);
					}

					if (!dataMark && !dataUpdateMark)
					{
						// 新加的文件，直接添加
						recreateUpdateDataList->Insert(newestUpdateEle->key, newestUpdateEle->value);

						doDownLoad = true;
					}

					if (dataUpdateMark)
					{
						 // 已经有过更新的，md5不同，替换为最新的
						if (0!=memcmp(newestUpdateMark.MD5, dataUpdateMark->value.MD5, 16*sizeof(char)))
						{
							recreateUpdateDataList->Insert(newestUpdateEle->key, newestUpdateEle->value);
							doDownLoad = true;
						}
						else
						{
							recreateUpdateDataList->Insert(dataUpdateMark->key, dataUpdateMark->value);
						}						
					}
					else if (dataMark)
					{
						 // 从没有过更新的，添加
						if (0!=memcmp(newestUpdateMark.MD5, dataMark->value.MD5, 16*sizeof(char)))
						{
							recreateUpdateDataList->Insert(newestUpdateEle->key, newestUpdateEle->value);
							doDownLoad = true;
						}
					}

					if (doDownLoad)
					{
						std::string dataStr = "Data/";
						std::string dstPath = newestUpdateMark.Path;
						dstPath = dstPath.substr(dataStr.length(), newestUpdateMark.Path.length()-dataStr.length());
						dstPath =  mDataUpdatePath +dstPath;

						std::string toDownLoadURL = wwwAddr + dstPath;
						std::string downLoadPath = writeablePath + dstPath;

						if (PX2_RM.Download(downLoadPath, toDownLoadURL))
						{
							// 写入新的versionList.dat
							PX2_RM.WriteDataList (writeablePath+ mDataUpdatePath + "versionList.dat", *recreateUpdateDataList);
						}
					}

					curEleIndex++;
					float percent = (float)curEleIndex/(float)numElements;
					if (mResourceUpdateCallback)
						mResourceUpdateCallback(percent);

					newestUpdateEle = updateVersionList.Iterate(newestUpdateEle);
				}

				// 跟新完毕，下载正式的version.xml
				std::string new_wVersionXMLPath = writeablePath + mDataUpdatePath + "version.xml";
				std::string new_wwwVersionXMLURL = wwwAddr + mDataUpdatePath + "version.xml";
				if (PX2_RM.Download(new_wVersionXMLPath, new_wwwVersionXMLURL))
				{
					// 重新读取versionXML versionList
					if (PX2_RM.LoadDataUpateVersionXML(writeablePath+mDataUpdatePath+"version.xml"))
					{
						PX2_RM.LoadDataUpdateVersionList(writeablePath+mDataUpdatePath+"versionList.dat");

						// 设置最新的版本
						PX2_RM.SetVersion(PX2_RM.GetDataUpdateVersionItem()->Version);
					}
				}
			}
			else
			{
				if (mResourceUpdateCallback)
				{
					mResourceUpdateCallback(1.0f);
				}
			}
		}
		else if (updateRVI->Version.GetLib()>localVersion.GetLib())
		{
			// 下载正式的version.xml
			std::string new_wVersionXMLPath = writeablePath + mDataUpdatePath + "version.xml";
			std::string new_wwwVersionXMLURL = wwwAddr + mDataUpdatePath + "version.xml";
			if (PX2_RM.Download(new_wVersionXMLPath, new_wwwVersionXMLURL))
			{
				// 重新读取versionXML versionList
				if (PX2_RM.LoadDataUpateVersionXML(writeablePath+mDataUpdatePath+"version.xml"))
				{
					PX2_RM.SetVersion(PX2_RM.GetDataUpdateVersionItem()->Version);
				}
			}
		}
	}
}
//----------------------------------------------------------------------------
void ResourceManager::SetResourceUpdateCallback (
	ResourceUpdateStuffsCallback callback)
{
	mResourceUpdateCallback = callback;
}
//----------------------------------------------------------------------------
void ResourceManager::SetDataUpdateServerType (const std::string &type)
{
	mDataUpdateServerType = type;
}
//----------------------------------------------------------------------------
std::string &ResourceManager::GetDataUpdateServerType ()
{
	return mDataUpdateServerType;
}
//----------------------------------------------------------------------------
Texture2D *ResourceManager::LoadTexFormOtherImagefile (std::string outExt,
	int bufferSize, const char*buffer)
{
	if (!buffer || bufferSize <= 0) return 0;

	Texture2D* texture = 0;

	if ("png" == outExt || "PNG" == outExt)
	{
		texture = _initWithPngData(buffer, bufferSize);
	}

	return texture;
}
//----------------------------------------------------------------------------
Texture2D *ResourceManager::_initWithPngData(const char *pData, int nDatalen)
{
// length of bytes to check if it is a valid png file
#define PNGSIGSIZE  8
	Texture2D* texture = 0;
	png_byte        header[PNGSIGSIZE]   = {0}; 
	png_structp     png_ptr     =   0;
	png_infop       info_ptr    = 0;

	do 
	{
		// png header len is 8 bytes
		if(nDatalen < PNGSIGSIZE)
			break;

		// check the data is png or not
		memcpy(header, pData, PNGSIGSIZE);
		if(png_sig_cmp(header, 0, PNGSIGSIZE))
			break;

		// init png_struct
		png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
		if(! png_ptr)
			break;

		// init png_info
		info_ptr = png_create_info_struct(png_ptr);
		if(! info_ptr)
			break;

//#if (CC_TARGET_PLATFORM != CC_PLATFORM_BADA && CC_TARGET_PLATFORM != CC_PLATFORM_NACL)
//		CC_BREAK_IF(setjmp(png_jmpbuf(png_ptr)));
//#endif

		// set the read call back function
		tImageSource imagesource;
		imagesource.data    = (unsigned char*)pData;
		imagesource.size    = nDatalen;
		imagesource.offset  = 0;
		png_set_read_fn(png_ptr, &imagesource, pngReadCallBack);

		// read png header info

		// read png file info
		png_read_info(png_ptr, info_ptr);

		int width = png_get_image_width(png_ptr, info_ptr);
		int height = png_get_image_height(png_ptr, info_ptr);
		int bitsPerComponent = png_get_bit_depth(png_ptr, info_ptr);
		png_uint_32 color_type = png_get_color_type(png_ptr, info_ptr);

		Texture::Format format = Texture::TF_A8R8G8B8;
		if(color_type == PNG_COLOR_TYPE_RGB_ALPHA)
		{
			format = Texture::TF_A8R8G8B8;
		}
		else if(color_type == PNG_COLOR_TYPE_RGB)
		{
			format = Texture::TF_R8G8B8;
		}
		texture = new0 Texture2D(format, width, height, 1);

		// force palette images to be expanded to 24-bit RGB
		// it may include alpha channel
		if (color_type == PNG_COLOR_TYPE_PALETTE)
		{
			png_set_palette_to_rgb(png_ptr);
		}
		// low-bit-depth grayscale images are to be expanded to 8 bits
		if (color_type == PNG_COLOR_TYPE_GRAY && bitsPerComponent < 8)
		{
			png_set_expand_gray_1_2_4_to_8(png_ptr);
		}
		// expand any tRNS chunk data into a full alpha channel
		if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
		{
			png_set_tRNS_to_alpha(png_ptr);
		}  
		// reduce images with 16-bit samples to 8 bits
		if (bitsPerComponent == 16)
		{
			png_set_strip_16(png_ptr);            
		} 
		// expand grayscale images to RGB
		if (color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
		{
			png_set_gray_to_rgb(png_ptr);
		}

		// read png data
		// m_nBitsPerComponent will always be 8
		bitsPerComponent = 8;
		png_uint_32 rowbytes;
		png_bytep* row_pointers = (png_bytep*)malloc( sizeof(png_bytep) * height );

		png_read_update_info(png_ptr, info_ptr);

		rowbytes = png_get_rowbytes(png_ptr, info_ptr);

		unsigned char* data = new unsigned char[rowbytes * height];
		
		char* textureData = texture->GetData(0);

		for (unsigned short i = 0; i < height; ++i)
		{
			row_pointers[i] = data + i*rowbytes;
		}
		png_read_image(png_ptr, row_pointers);

		png_read_end(png_ptr, NULL);

		png_uint_32 channel = rowbytes/width;
		if (channel == 4)
		{
			unsigned int *tmp = (unsigned int *)textureData;
			for(unsigned short i = 0; i < height; i++)
			{
				for(unsigned int j = 0; j < rowbytes; j += 4)
				{
					*tmp++ = PX2_RGB_PREMULTIPLY_ALPHA( row_pointers[i][j], row_pointers[i][j + 1], 
						row_pointers[i][j + 2], row_pointers[i][j + 3] );
				}
			}
		}
		else if(channel == 3)
		{
			unsigned char *tmp = (unsigned char *)textureData;
			for(unsigned short i = 0; i < height; i++)
			{
				for(unsigned int j = 0; j < rowbytes; j ++)
				{
					*tmp++ = row_pointers[i][j];
				}
			}
		}
		free(row_pointers);

		delete[] data;

	} while (0);

	if (png_ptr)
	{
		png_destroy_read_struct(&png_ptr, (info_ptr) ? &info_ptr : 0, 0);
	}
	return texture;
}
//----------------------------------------------------------------------------
#ifdef _MSC_VER
#pragma pack(push,1)
#endif
typedef struct {
	uint32_t version;
	uint32_t flags;
	uint64_t pixelFormat;
	uint32_t colorSpace;
	uint32_t channelType;
	uint32_t height;
	uint32_t width;
	uint32_t depth;
	uint32_t numberOfSurfaces;
	uint32_t numberOfFaces;
	uint32_t numberOfMipmaps;
	uint32_t metadataLength;
#ifdef _MSC_VER
} ccPVRv3TexHeader;
#pragma pack(pop)
#else
} __attribute__((packed)) ccPVRv3TexHeader;
#endif

#define CC_HOST_IS_BIG_ENDIAN (bool)(*(unsigned short *)"\0\xff" < 0x100) 
#define CC_SWAP32(i)  ((i & 0x000000ff) << 24 | (i & 0x0000ff00) << 8 | (i & 0x00ff0000) >> 8 | (i & 0xff000000) >> 24)
#define CC_SWAP16(i)  ((i & 0x00ff) << 8 | (i &0xff00) >> 8)   
#define CC_SWAP_INT32_LITTLE_TO_HOST(i) ((CC_HOST_IS_BIG_ENDIAN == true)? CC_SWAP32(i) : (i) )
#define CC_SWAP_INT16_LITTLE_TO_HOST(i) ((CC_HOST_IS_BIG_ENDIAN == true)? CC_SWAP16(i) : (i) )
#define CC_SWAP_INT32_BIG_TO_HOST(i)    ((CC_HOST_IS_BIG_ENDIAN == true)? (i) : CC_SWAP32(i) )
#define CC_SWAP_INT16_BIG_TO_HOST(i)    ((CC_HOST_IS_BIG_ENDIAN == true)? (i):  CC_SWAP16(i) )

/* supported predefined formats */
#define kPVR3TexturePixelFormat_PVRTC_2BPP_RGB   0
#define kPVR3TexturePixelFormat_PVRTC_2BPP_RGBA  1
#define kPVR3TexturePixelFormat_PVRTC_4BPP_RGB   2
#define kPVR3TexturePixelFormat_PVRTC_4BPP_RGBA  3
#define kPVR3TexturePixelFormat_ETC1             6
	
/* supported channel type formats */
#define kPVR3TexturePixelFormat_BGRA_8888  0x0808080861726762ULL
#define kPVR3TexturePixelFormat_RGBA_8888  0x0808080861626772ULL
#define kPVR3TexturePixelFormat_RGBA_4444  0x0404040461626772ULL
#define kPVR3TexturePixelFormat_RGBA_5551  0x0105050561626772ULL
#define kPVR3TexturePixelFormat_RGB_565    0x0005060500626772ULL
#define kPVR3TexturePixelFormat_RGB_888    0x0008080800626772ULL
#define kPVR3TexturePixelFormat_A_8        0x0000000800000061ULL
#define kPVR3TexturePixelFormat_L_8        0x000000080000006cULL
#define kPVR3TexturePixelFormat_LA_88      0x000008080000616cULL

enum {
	kPVR3TextureFlagPremultipliedAlpha	= (1<<1)	// has premultiplied alpha
};

struct CCZHeader {
    unsigned char   sig[4];             // signature. Should be 'CCZ!' 4 bytes
    unsigned short  compression_type;   // should 0
    unsigned short  version;            // should be 2 (although version type==1 is also supported)
    unsigned int    reserved;           // Reserved for users.
    unsigned int    len;                // size of the uncompressed file
};

enum {
    CCZ_COMPRESSION_ZLIB,               // zlib format.
    CCZ_COMPRESSION_BZIP2,              // bzip2 format (not supported yet)
    CCZ_COMPRESSION_GZIP,               // gzip format (not supported yet)
    CCZ_COMPRESSION_NONE,               // plain (not supported yet)
};

static unsigned int randSeed = 0;
static unsigned int MyRand()
{
	randSeed = randSeed*171589117 + 892332411;
	return randSeed;
}

static void DecryptBuffer(unsigned char *buffer, int n)
{
	randSeed = n + 123;
	int enclen = (MyRand()%100) + 23;
	if(enclen > n) enclen = n;

	enclen /= 4;
	unsigned int *pdata = (unsigned int *)buffer;
	for(int i=0; i<enclen; i++)
	{
		unsigned int src = (unsigned int)buffer[i*4] + ((unsigned int)buffer[i*4+1]<<8) +  ((unsigned int)buffer[i*4+2]<<16) + ((unsigned int)buffer[i*4+3]<<24);
		pdata[i] = src ^ MyRand();
	}
}

Texture2D *ResourceManager::LoadTextureFromPVRTC_CCZ(int bufferSize, const char *buffer)
{
	int headsize = sizeof(CCZHeader);
	if (bufferSize < headsize)
	{
		return NULL;
	}
	CCZHeader *cczheader = (CCZHeader *)buffer;
	unsigned long newlen = CC_SWAP_INT32_BIG_TO_HOST(cczheader->len);
	char *newbuffer = new char[newlen];

	if(cczheader->reserved > 0)
	{
		DecryptBuffer((unsigned char *)buffer+sizeof(CCZHeader), bufferSize-sizeof(CCZHeader));
		cczheader->reserved = 0;
	}

	Texture2D *ptex = NULL;
	if(Z_OK == uncompress((Bytef *)newbuffer, &newlen, (const Bytef *)buffer+headsize, bufferSize-headsize))
	{
		ptex = LoadTextureFromPVRTC(newlen, newbuffer);
	}

	delete[] newbuffer;
	return ptex;
}

Texture2D *ResourceManager::LoadTextureFromPVRTC(int dataLength, const char *dataPointer)
{
    if (dataLength < int(sizeof(ccPVRv3TexHeader)))
    {
		return NULL;
	}
	
	ccPVRv3TexHeader *header = (ccPVRv3TexHeader *)dataPointer;
	
	// validate version
	if (CC_SWAP_INT32_BIG_TO_HOST(header->version) != 0x50565203)
    {
		PX2_LOG_INFO("pvr file version mismatch");
		return NULL;
	}
	
	// parse pixel format
	uint64_t pixelFormat = header->pixelFormat;
	int bpp;
	Texture::Format format;
    
	if(pixelFormat == kPVR3TexturePixelFormat_PVRTC_2BPP_RGB)
	{
		bpp = 2;
		format = Texture::TF_RGB_PVRTC_2B;
	}
	else if(pixelFormat == kPVR3TexturePixelFormat_PVRTC_2BPP_RGBA)
	{
		bpp = 2;
		format = Texture::TF_RGBA_PVRTC_2B;
	}
	else if(pixelFormat == kPVR3TexturePixelFormat_PVRTC_4BPP_RGB)
	{
		bpp = 4;
		format = Texture::TF_RGB_PVRTC_4B;
	}
	else if(pixelFormat == kPVR3TexturePixelFormat_PVRTC_4BPP_RGBA)
	{
		bpp = 4;
		format = Texture::TF_RGBA_PVRTC_4B;
	}
	else if(pixelFormat == kPVR3TexturePixelFormat_ETC1)
	{
		bpp = 4;
		format = Texture::TF_RGB_ETC1;
	}
	else if(pixelFormat == kPVR3TexturePixelFormat_RGBA_8888)
	{
		bpp = 32;
		format = Texture::TF_A8R8G8B8;
	}
	else if(pixelFormat == kPVR3TexturePixelFormat_RGBA_4444)
	{
		bpp = 16;
		format = Texture::TF_A4R4G4B4;
	}
	else if(pixelFormat == kPVR3TexturePixelFormat_RGBA_5551)
	{
		bpp = 16;
		format = Texture::TF_A1R5G5B5;
	}
	else if(pixelFormat == kPVR3TexturePixelFormat_RGB_565)
	{
		bpp = 16;
		format = Texture::TF_R5G6B5;
	}
	else
	{
		PX2_LOG_INFO("Cannot support pvr pixelformat");
		return NULL;
	}
	
	// PVRv3 specifies premultiply alpha in a flag -- should always respect this in PVRv3 files
	//uint32_t flags = CC_SWAP_INT32_LITTLE_TO_HOST(header->flags);
	//bool premul_alpha = (flags & kPVR3TextureFlagPremultipliedAlpha)!=0;
    
	// sizing
	uint32_t width = CC_SWAP_INT32_LITTLE_TO_HOST(header->width);
	uint32_t height = CC_SWAP_INT32_LITTLE_TO_HOST(header->height);
	uint32_t dataOffset = 0, dataSize = 0;
	uint32_t blockSize = 0, widthBlocks = 0, heightBlocks = 0;
	uint8_t *bytes = NULL;
	
	dataOffset = (sizeof(ccPVRv3TexHeader) + header->metadataLength);
	bytes = (uint8_t *)dataPointer;
	
	unsigned int mipmaps = header->numberOfMipmaps;
	Texture2D *texture = new0 Texture2D(format, width, height, mipmaps);
    
	for (unsigned int i = 0; i < mipmaps; i++)
    {
		switch (pixelFormat)
        {
			case kPVR3TexturePixelFormat_PVRTC_2BPP_RGB :
			case kPVR3TexturePixelFormat_PVRTC_2BPP_RGBA :
				blockSize = 8 * 4; // Pixel by pixel block size for 2bpp
				widthBlocks = width / 8;
				heightBlocks = height / 4;
				break;
			case kPVR3TexturePixelFormat_PVRTC_4BPP_RGB :
			case kPVR3TexturePixelFormat_PVRTC_4BPP_RGBA :
				blockSize = 4 * 4; // Pixel by pixel block size for 4bpp
				widthBlocks = width / 4;
				heightBlocks = height / 4;
				break;
			case kPVR3TexturePixelFormat_ETC1 :
				blockSize = 4 * 4;
				widthBlocks = width / 4;
				heightBlocks = height / 4;
				break;
			case kPVR3TexturePixelFormat_BGRA_8888:
				return 0;
			default:
				blockSize = 1;
				widthBlocks = width;
				heightBlocks = height;
				break;
		}
        
		// Clamp to minimum number of blocks
		if (widthBlocks < 2)
        {
			widthBlocks = 2;
        }
		if (heightBlocks < 2)
        {
			heightBlocks = 2;
        }
		
		dataSize = widthBlocks * heightBlocks * ((blockSize  * bpp) / 8);
		unsigned int packetLength = ((unsigned int)dataLength-dataOffset);
		packetLength = packetLength > dataSize ? dataSize : packetLength;

		assertion(texture->GetNumLevelBytes(i) == int(packetLength), "wrong PVR file packetLength");
		memcpy(texture->GetData(i), bytes+dataOffset, packetLength);
		
		dataOffset += packetLength;
		assertion(int(dataOffset)<=dataLength, "TexturePVR Invalid lenght");
		
		width = width>>1;
		if(width == 0) width = 1;
		height = height >> 1;
		if(height == 0) height = 1;
	}
	
	return texture;
}
//----------------------------------------------------------------------------

#ifndef DWORD
typedef unsigned long DWORD;
#endif
#ifndef uint32
typedef unsigned int uint32;
#endif

#define FOURCC(c0, c1, c2, c3) (c0 | (c1 << 8) | (c2 << 16) | (c3 << 24))

const DWORD D3DFMT_R16F				= 111;
const DWORD D3DFMT_G16R16F			= 112;
const DWORD D3DFMT_A16B16G16R16F	= 113;
const DWORD D3DFMT_R32F				= 114;
const DWORD D3DFMT_G32R32F			= 115;
const DWORD D3DFMT_A32B32G32R32F	= 116;

const uint32 DDS_PIXELFORMAT_SIZE = 8 * sizeof(uint32);
const uint32 DDS_CAPS_SIZE = 4 * sizeof(uint32);
const uint32 DDS_HEADER_SIZE = 19 * sizeof(uint32) + DDS_PIXELFORMAT_SIZE + DDS_CAPS_SIZE;

#define DDSD_CAPS        0x00000001
#define DDSD_HEIGHT      0x00000002
#define DDSD_WIDTH       0x00000004
#define DDSD_PITCH       0x00000008
#define DDSD_PIXELFORMAT 0x00001000
#define DDSD_MIPMAPCOUNT 0x00020000
#define DDSD_LINEARSIZE  0x00080000
#define DDSD_DEPTH       0x00800000

#define DDPF_ALPHAPIXELS 0x00000001
#define DDPF_FOURCC      0x00000004
#define DDPF_RGB         0x00000040

#define DDSCAPS_COMPLEX  0x00000008 
#define DDSCAPS_TEXTURE  0x00001000 
#define DDSCAPS_MIPMAP   0x00400000 

#define DDSCAPS2_CUBEMAP		   0x00000200 
#define DDSCAPS2_CUBEMAP_POSITIVEX 0x00000400 
#define DDSCAPS2_CUBEMAP_NEGATIVEX 0x00000800 
#define DDSCAPS2_CUBEMAP_POSITIVEY 0x00001000 
#define DDSCAPS2_CUBEMAP_NEGATIVEY 0x00002000 
#define DDSCAPS2_CUBEMAP_POSITIVEZ 0x00004000 
#define DDSCAPS2_CUBEMAP_NEGATIVEZ 0x00008000 
#define DDSCAPS2_VOLUME			   0x00200000 

struct DDPIXELFORMAT
{
	DWORD dwSize; 
	DWORD dwFlags; 
	DWORD dwFourCC; 
	DWORD dwRGBBitCount; 
	DWORD dwRBitMask; 
	DWORD dwGBitMask; 
	DWORD dwBBitMask; 
	DWORD dwRGBAlphaBitMask; 
};

struct DDSCAPS2
{
	DWORD    dwCaps;
	DWORD    dwCaps2;
	DWORD    dwCaps3;
	DWORD    dwCaps4; 
};

struct DDSHeader
{
	char          magic[4];
	DWORD         dwSize;
	DWORD         dwFlags;
	DWORD         dwHeight;
	DWORD         dwWidth;
	DWORD         dwPitchOrLinearSize;
	DWORD         dwDepth;
	DWORD         dwMipMapCount;
	DWORD         dwReserved1[11];
	DDPIXELFORMAT ddpfPixelFormat;
	DDSCAPS2      ddsCaps;
	DWORD         dwReserved2;
};

static Texture::Format ConvertFourCCFormat(uint32_t fourcc)
{
	switch(fourcc)
	{
	case FOURCC('D','X','T','1'):
		return Texture::TF_DXT1;
	case FOURCC('D','X','T','3'):
		return Texture::TF_DXT3;
	case FOURCC('D','X','T','5'):
		return Texture::TF_DXT5;
	default:
		assertion(false, "other format is not supportted.");
		return Texture::TF_NONE;
	};
}

static void GetDescInfo (const DDSHeader &header, int &width, int &height,
						 int &minmap, Texture::Format &format)
{
	if(strncmp(header.magic, "DDS ", 4) != 0)
	{
		assertion(false, "this is not DDS.");
	}

	if (header.dwFlags & DDSD_CAPS)
	{
		const DDSCAPS2 &caps = header.ddsCaps;
		if(caps.dwCaps2&DDSCAPS2_CUBEMAP)
		{
			assertion(false, "current not supported.");
		}
		else if(caps.dwCaps2&DDSCAPS2_VOLUME)
		{
			assertion(false, "current not supported.");
		}
	}

	assertion((header.dwFlags&DDSD_WIDTH) && (header.dwFlags&DDSD_HEIGHT), "");
	width = (int)header.dwWidth;
	height = (int)header.dwHeight;

	if (header.dwFlags&DDSD_MIPMAPCOUNT)
	{
		assertion(((header.ddsCaps.dwCaps&DDSCAPS_MIPMAP)!=0), "must has minmap.");
		minmap = header.dwMipMapCount;
	}
	else
	{
		minmap = 1;
	}

	const DDPIXELFORMAT &fmt = header.ddpfPixelFormat;

	if(fmt.dwFlags & DDPF_RGB)
	{
		assertion(false, "");
	}
	else if(fmt.dwFlags & DDPF_FOURCC)
	{
		format = ConvertFourCCFormat(fmt.dwFourCC);
	}
	else
	{
		assertion(false, "");
	}
}

Texture2D *ResourceManager::LoadTextureFromDDS (const std::string &filename)
{
	PX2_UNUSED(filename);

	FILE* inFile;
	inFile = fopen(filename.c_str(), "rb");

	if (!inFile)
	{
		assertion(false, "Failed to open file %s\n", filename.c_str());
		return 0;
	}

	DDSHeader header;
	int numRead = (int)fread(&header, sizeof(header), 1, inFile);
	PX2_UNUSED(numRead);

	int width = 0;
	int height = 0;
	int minmap = 1;
	Texture::Format format;
	GetDescInfo(header, width, height, minmap, format);

	Texture2D *texture = new0 Texture2D(format, width, height, minmap);
	fread(texture->GetData(0), texture->GetNumTotalBytes(), 1, inFile);

	if (fclose(inFile) != 0)
	{
		assertion(false, "Failed to read or close file %s\n",
			filename.c_str());
		return 0;
	}

	return texture;
}
//----------------------------------------------------------------------------
bool ResourceManager::GetFileDataFromZip (const std::string &packageName,
	const std::string &filename, int &bufferSize, char* &buffer)
{
#ifdef __MARMALADE__
	return false;
#else
	if (packageName.empty() || filename.empty())
		return 0;

	unzFile ufile = 0;

	ufile = unzOpen(packageName.c_str());
	if (!ufile)
		return false;

	if (UNZ_OK != unzLocateFile(ufile, filename.c_str(), 1))
	{
		assertion(false, "unzLocateFile failed.");

		unzClose(ufile);
		return false;
	}

	char filePathTemp[260];
	unz_file_info fileInfo;
	if (UNZ_OK != unzGetCurrentFileInfo(ufile, &fileInfo, filePathTemp,
		sizeof(filePathTemp), 0, 0, 0, 0))
	{
		assertion(false, "unzGetCurrentFileInfo failed.");

		unzClose(ufile);
		return false;
	}

	if (UNZ_OK != unzOpenCurrentFile(ufile))
	{
		assertion(false, "unzOpenCurrentFile failed.");

		unzClose(ufile);
		return false;
	}

	buffer = new1<char>(fileInfo.uncompressed_size);
	int readedSize = 0;
	readedSize = unzReadCurrentFile(ufile, buffer, fileInfo.uncompressed_size);

	if (0!=readedSize && (fileInfo.uncompressed_size!=(unsigned long)readedSize))
	{
		assertion(false, "the file size is wrong.");

		unzClose(ufile);

		delete1<char>(buffer);
		buffer = 0;

		return false;
	}

	bufferSize = (int)fileInfo.uncompressed_size;

	unzCloseCurrentFile(ufile);
	unzClose(ufile);

	return true;
#endif
}
//----------------------------------------------------------------------------
void ResourceManager::ShareCopyProcess (Node *node, Node *nodeFrom,
	bool vb, bool ib, bool mi)
{
	for (int i=0; i<nodeFrom->GetNumChildren(); i++)
	{
		Movable *movFrom = nodeFrom->GetChild(i);
		Movable *movTo = node->GetChild(i);

		Node *theNode = DynamicCast<Node>(movFrom);
		if (theNode)
		{
			ShareCopyProcess((Node*)movTo, theNode, vb, ib, mi);
		}
		Renderable *theRenderable = DynamicCast<Renderable>(movFrom);
		if (theRenderable)
		{
			ShareCopyProcess((Renderable*)movTo, theRenderable, vb, ib, mi);
		}
	}
}
//----------------------------------------------------------------------------
void ResourceManager::ShareCopyProcess (Renderable *renderable,
	Renderable *renderableFrom, bool vb, bool ib, bool mi)
{
	VertexFormat *vf1 = renderableFrom->GetVertexFormat();
	VertexBuffer *vb1 = renderableFrom->GetVertexBuffer();
	IndexBuffer *ib1 = renderableFrom->GetIndexBuffer();
	MaterialInstance *mi1 = renderableFrom->GetMaterialInstance();

	if (vb)
	{
		renderable->SetVertexFormat(vf1);
		renderable->SetVertexBuffer(vb1);
	}

	if (ib)
	{
		renderable->SetIndexBuffer(ib1);
	}

	if (mi)
	{
		renderable->SetMaterialInstance(mi1);
	}
}
//----------------------------------------------------------------------------
void ResourceManager::Run ()
{
	RunLoadingThread();
}
//----------------------------------------------------------------------------

