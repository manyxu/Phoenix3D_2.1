// PX2SkySphere.inl

//----------------------------------------------------------------------------
inline Float4 SkySphere::GetSunParams ()
{
	return mSunParams;
}
//----------------------------------------------------------------------------
inline Float4 SkySphere::GetSkyParams ()
{
	return mSkyParams;
}
//----------------------------------------------------------------------------
inline float SkySphere::GetRadial ()
{
	return mRadius;
}
//----------------------------------------------------------------------------
inline Texture2D *SkySphere::GetNightTexture ()
{
	return mNightTexture;
}
//----------------------------------------------------------------------------
inline Texture2D *SkySphere::GetSunSetTexture ()
{
	return mSunSetTexture;
}
//----------------------------------------------------------------------------
inline Texture2D *SkySphere::GetDayTexture ()
{
	return mDayTexture;
}
//----------------------------------------------------------------------------