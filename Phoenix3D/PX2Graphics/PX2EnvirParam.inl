// PX2EnvirParam.inl

//----------------------------------------------------------------------------
inline Light *EnvirParam::GetLight_Dir()
{
	return mLight_Dir;
}
//----------------------------------------------------------------------------
inline Projector *EnvirParam::GetLight_Dir_Projector()
{
	return mLight_Dir_Projector;
}
//----------------------------------------------------------------------------
inline void EnvirParam::SetLight_Dir_DepthTexture(Texture *tex)
{
	mLight_Dir_DepthTexture = tex;
}
//----------------------------------------------------------------------------
inline Texture *EnvirParam::GetLight_Dir_DepthTexture()
{
	return mLight_Dir_DepthTexture;
}
//----------------------------------------------------------------------------
inline void EnvirParam::SetFogParam(const Float4 &param)
{
	mFogParam = param;
}
//----------------------------------------------------------------------------
inline const Float4 &EnvirParam::GetFogParam() const
{
	return mFogParam;
}
//----------------------------------------------------------------------------
inline void EnvirParam::SetFogColorHeight(const Float4 &fogColor)
{
	mFogColorHeight = fogColor;
}
//----------------------------------------------------------------------------
inline const Float4 &EnvirParam::GetFogColorHeight() const
{
	return mFogColorHeight;
}
//----------------------------------------------------------------------------
inline void EnvirParam::SetFogColorDist(const Float4 &fogColor)
{
	mFogColorDist = fogColor;
}
//----------------------------------------------------------------------------
inline const Float4 &EnvirParam::GetFogColorDist() const
{
	return mFogColorDist;
}
//----------------------------------------------------------------------------