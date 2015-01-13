/*
*
* 文件名称	：	PX2CURLDownload.cpp
*
*/

#include "PX2CURLDownload.hpp"
#include "PX2ScopedCS.hpp"
#include "PX2Assert.hpp"
#include "PX2Log.hpp"

#define CURL_STATICLIB
#include "CURL/curl.h"

using namespace PX2;
using namespace std;

//----------------------------------------------------------------------------
int CURLDownload::msNumInsts = 0;
//----------------------------------------------------------------------------
CURLDownload::CURLDownload ()
	:
mCurl(0),
mFile(0),
mUseNeedDownloadSize(false),
mNeedDownloadSize(0),
mCurDownloadSize(0),
mDownType(DT_FILE),
mDownloadMemory(0),
mIsDownLoadOK(false),
mDownLoadProgress(0.0f)
{

}
//----------------------------------------------------------------------------
CURLDownload::~CURLDownload ()
{
}
//----------------------------------------------------------------------------
bool CURLDownload::Initlize ()
{
	// curl
	if (0 == msNumInsts++)
	{
		curl_global_init(CURL_GLOBAL_ALL);
	}

	mCurl = curl_easy_init();
	if (!mCurl)
	{
		assertion(false, "curl_easy_init failed.\n");
		PX2_LOG_ERROR("curl_easy_init failed.\n");
		return false;
	}

	curl_easy_setopt(mCurl, CURLOPT_WRITEFUNCTION, &WriteFunction);
	curl_easy_setopt(mCurl, CURLOPT_WRITEDATA, this);

	curl_easy_setopt(mCurl, CURLOPT_PROGRESSFUNCTION, &ProgressFunction);
	curl_easy_setopt(mCurl, CURLOPT_PROGRESSDATA, this);
	curl_easy_setopt(mCurl, CURLOPT_NOPROGRESS, false);
	curl_easy_setopt(mCurl, CURLOPT_ERRORBUFFER, mCulrErrDesc);
	curl_easy_setopt(mCurl, CURLOPT_VERBOSE, 1); // ?

	memset(mCulrErrDesc, 0, sizeof(char)*CURL_ERROR_SIZE);

	return true;
}
//----------------------------------------------------------------------------
bool CURLDownload::Terminate ()
{
	delete1(mDownloadMemory);

	if (mCurl)
	{
		curl_easy_cleanup(mCurl);
		mCurl = 0;
	}

	if (0 == --msNumInsts)
	{
		curl_global_cleanup();
	}

	return true;
}
//----------------------------------------------------------------------------
void CURLDownload::SetDownType (DownType type)
{
	mDownType = type;
}
//----------------------------------------------------------------------------
void CURLDownload::Stop ()
{
	ScopedCS cs(&mMutex);

	curl_easy_pause(mCurl, CURLPAUSE_RECV);
}
//----------------------------------------------------------------------------
void CURLDownload::Continue ()
{
	ScopedCS cs(&mMutex);

	curl_easy_pause(mCurl, CURLPAUSE_RECV_CONT);
}
//----------------------------------------------------------------------------
double CURLDownload::GetSpeed() const 
{
	double speed = 0.0;

	curl_easy_getinfo(mCurl, CURLINFO_SPEED_DOWNLOAD, &speed);

	return speed;
}
//----------------------------------------------------------------------------
bool CURLDownload::Download (const std::string &filename,
	const std::string &url,	int size, int startFrom)
{
	ScopedCS cs(&mMutex);

	mUseNeedDownloadSize = true;
	mNeedDownloadSize = size;
	mCurDownloadSize = 0;
	mStartFrom = startFrom;

	if (filename != mFilename)
	{
		if (mFile)
		{
			fclose(mFile);
			mFile = 0;
		}

		mFilename = filename;
	}

	if (!mFile)
	{
		mFile = fopen(mFilename.c_str(), "rb+");

		if (!mFile)
		{
			mFile = fopen(mFilename.c_str(), "wb");
		}

		if (!mFile)
		{
			assertion(false, "File %s opened failed.\n", mFilename.c_str());
			PX2_LOG_ERROR("File %s opened failed.\n", mFilename.c_str());

			return false;
		}
	}

	if (mFile)
		fseek(mFile, mStartFrom, SEEK_SET);

	if (mDownType == DT_MEMORY || mDownType == DT_FILEMEMORY)
	{
		if (mDownloadMemory)
		{
			delete1(mDownloadMemory);
		}
		mDownloadMemory = new1<char>(size);
		memset(mDownloadMemory, 0, size*sizeof(char));
	}

	curl_easy_setopt(mCurl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(mCurl, CURLOPT_RESUME_FROM, startFrom);

	CURLcode result;
	result = curl_easy_perform(mCurl);
	if (result != CURLE_OK && mCulrErrDesc[0]!=0)
	{
		// 出错
		std::string errString = string("Connect to ") + url + " failed, error:" + mCulrErrDesc;
		PX2_LOG_ERROR(errString.c_str());

		if (std::string(mCulrErrDesc) != "Failed writing body (1 != 1460)")
			return false;
	}

	return true;
}
//----------------------------------------------------------------------------
bool CURLDownload::Download (const std::string &filename, 
	const std::string &url)
{
	mDownType = DT_FILE;
	mUseNeedDownloadSize = false;
	mIsDownLoadOK = false;

	if (filename != mFilename)
	{
		mFilename = filename;
		if (mFile)
		{
			fclose(mFile);
			mFile = 0;
		}
	}

	// 创建文件
	if (!mFile)
	{
		mFile = fopen(mFilename.c_str(), "wb");

		if (!mFile)
		{
			assertion(false, "File %s opened failed.\n", mFilename.c_str());
			PX2_LOG_ERROR("File %s opened failed.\n", mFilename.c_str());

			return false;
		}
	}

	curl_easy_setopt(mCurl, CURLOPT_URL, url.c_str());

	CURLcode result;
	result = curl_easy_perform(mCurl);
	if (result != CURLE_OK && mCulrErrDesc[0]!=0)
	{
		std::string errString = string("Connect to ") + "failed, error:" + mCulrErrDesc;

		if (std::string(mCulrErrDesc) != "Failed writing body (1 != 1460)")
			return false;
	}

	if (mFile)
	{
		fclose(mFile);
	}

	return true;
}
//----------------------------------------------------------------------------
int CURLDownload::WriteFunction (void *buffer, size_t size, size_t nmemb,
	void *clientp)
{
	CURLDownload *download = (CURLDownload *)clientp;

	if (!download)
	{
		assertion(false, "WriteFunction download must exist\n");
		PX2_LOG_ERROR("WriteFunction download must exist\n");

		return -1;
	}

	if (download->mUseNeedDownloadSize)
	{
		int allSizeWrited = 0;

		int iSize = (int)size;
		int iNum = (int)nmemb;

		int sizeTemp = download->mCurDownloadSize + iSize*iNum;
		int needReadSize = iSize*iNum;

		bool isSizeOver = (sizeTemp >= download->mNeedDownloadSize);
		if (isSizeOver)
			needReadSize = download->mNeedDownloadSize - download->mCurDownloadSize;

		if (needReadSize <=0 )
		{
			if (download->mFile)
			{
				fclose(download->mFile);
				download->mFile = 0;
			}

			return allSizeWrited;
		}

		int writeSize = 0;
		if (download->mDownType == DT_FILE)
		{
			fwrite((char*)buffer, needReadSize, 1, download->mFile);
			writeSize = needReadSize;
		}
		else if (download->mDownType == DT_MEMORY)
		{
			memcpy(download->mDownloadMemory+download->mCurDownloadSize, (char*)buffer, needReadSize);
			writeSize = needReadSize;
		}
		else if (download->mDownType == DT_FILEMEMORY)
		{
			fwrite((char*)buffer, needReadSize, 1, download->mFile);
			writeSize = needReadSize;
			memcpy(download->mDownloadMemory+download->mCurDownloadSize, (char*)buffer, needReadSize);
		}

		download->mCurDownloadSize += writeSize;
		allSizeWrited += writeSize;

		if (download->mCurDownloadSize >= download->mNeedDownloadSize)
		{
			if (download->mFile)
			{
				fclose(download->mFile);
				download->mFile = 0;
			}

			return allSizeWrited;
		}

		return allSizeWrited;
	}
	else
	{
		fwrite((char*)buffer, size, nmemb, download->mFile);

		return (int)(size)*(int)nmemb;
	}
}
//----------------------------------------------------------------------------
int64_t file_size (const char* szFileName)
{
	FILE* f = fopen(szFileName, "rb");
	if(!f)
		return -1;

	fseek(f, 0, SEEK_END);
	int64_t len = ftell(f);
	fclose(f);
	return len;
}
//----------------------------------------------------------------------------
int CURLDownload::ProgressFunction (void *clientp, double dltotal, 
	double dlnow, double ultotal, double ulnow)
{
	PX2_UNUSED(dlnow);
	PX2_UNUSED(ultotal);
	PX2_UNUSED(dlnow);

	CURLDownload *download = static_cast<CURLDownload *>(clientp);
	if (!download)
	{
		assertion(false, "WriteFunction download must exist\n");
		PX2_LOG_ERROR("WriteFunction download must exist\n");
	}

	// 当前文件已下载大小
	int64_t nNowFileSize = file_size(download->mFilename.c_str());

	// 需要文件大小
	unsigned int totalfileSize = (unsigned int)dltotal;
	download->mDownLoadProgress = (float)nNowFileSize/(float)totalfileSize;

	if (nNowFileSize == totalfileSize)
	{		
		download->mIsDownLoadOK = true;
	}
	else
	{
		download->mIsDownLoadOK = false;
	}

	return 0;
}
//----------------------------------------------------------------------------