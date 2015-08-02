// PX2FramesMesh.inl

//----------------------------------------------------------------------------
inline void FramesMesh::SetNumDir(int numFrames)
{
	mNumDir = numFrames;
	mIsNeedReCal = true;
}
//----------------------------------------------------------------------------
inline int FramesMesh::GetNumDir() const
{
	return mNumDir;
}
//----------------------------------------------------------------------------