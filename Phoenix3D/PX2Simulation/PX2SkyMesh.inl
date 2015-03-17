// PX2SkyMesh.inl

//----------------------------------------------------------------------------
inline const std::string &SkyMesh::GetDayTexture() const
{
	return mDayTexFilename;
}
//----------------------------------------------------------------------------
inline const std::string &SkyMesh::GetSunsetTexture()
{
	return mSunsetTexFilename;
}
//----------------------------------------------------------------------------
inline const std::string &SkyMesh::GetNightTexture()
{
	return mNightTexFilename;
}
//----------------------------------------------------------------------------
inline const Float4 &SkyMesh::GetSkyParam() const
{
	return mSkyParam;
}
//----------------------------------------------------------------------------
inline const Float4 &SkyMesh::GetSunMoonParam() const
{
	return mSunMoonParam;
}
//----------------------------------------------------------------------------
inline const Float4 &SkyMesh::GetSunMoonColourIn() const
{
	return mSunMoonColourIn;
}
//----------------------------------------------------------------------------
inline const Float4 &SkyMesh::GetSunMoonColourOut() const
{
	return mSunMoonColourOut;
}
//----------------------------------------------------------------------------