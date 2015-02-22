// PX2CURLDownload.inl

//----------------------------------------------------------------------------
inline CURLDownload::DownType CURLDownload::GetDownType () const
{
	return mDownType;
}
//----------------------------------------------------------------------------
inline char *CURLDownload::GetDownloadMemory ()
{
	return mDownloadMemory;
}
//----------------------------------------------------------------------------
inline const char *CURLDownload::GetDownloadMemory () const
{
	return mDownloadMemory;
}
//----------------------------------------------------------------------------
inline bool CURLDownload::IsDownLoadOK () const
{
	return mIsDownLoadOK;
}
//----------------------------------------------------------------------------
inline float CURLDownload::GetDownLoadProgress () const
{
	return mDownLoadProgress;
}
//----------------------------------------------------------------------------