// PX2CURLDownload.hpp

#ifndef PX2CURLDOWNLOAD_HPP
#define PX2CURLDOWNLOAD_HPP

#include "PX2Mutex.hpp"

namespace PX2
{

	class CURLDownload
	{
	public:
		CURLDownload ();
		~CURLDownload ();

		bool Initlize ();
		bool Terminate ();

		enum DownType
		{
			DT_NONE,
			DT_FILE,
			DT_MEMORY,
			DT_FILEMEMORY,
			DT_MAX_TYPE
		};
		void SetDownType (DownType type);
		DownType GetDownType () const;

		void Stop();
		void Continue();
		double GetSpeed() const;

		bool Download (const std::string &filename, const std::string &url, 
			int size, int startFrom);
		bool Download (const std::string &filename, const std::string &url);
		bool IsDownLoadOK () const;
		float GetDownLoadProgress () const;

		char *GetDownloadMemory ();
		const char *GetDownloadMemory () const;

	private:
		static int WriteFunction (void *buffer, size_t size, size_t nmemb, 
			void *clientp);
		static int ProgressFunction (void *clientp, double dltotal, 
			double dlnow, double ultotal, double ulnow);

		void *mCurl;
		char mCulrErrDesc[256]; // CURL_ERROR_SIZE 256
		unsigned int mStartFrom; // 续传点(开始字节)
		DownType mDownType;

		std::string mFilename;
		FILE *mFile;
		bool mUseNeedDownloadSize;
		int mNeedDownloadSize;
		int mCurDownloadSize;
		Mutex mMutex;

		char *mDownloadMemory;

		bool mIsDownLoadOK;
		float mDownLoadProgress;

		static int msNumInsts;
	};

#include "PX2CURLDownload.inl"

}

#endif