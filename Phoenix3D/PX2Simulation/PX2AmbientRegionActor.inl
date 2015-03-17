// PX2AmbientRegionActor.inl

//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetHorAngle() const
{
	return mHorAngle;
}
//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetVerAngle() const
{
	return mVerAngle;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetAmbientColor() const
{
	return mAmbientColor;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetDiffuseColor() const
{
	return mDiffuseColor;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetSpecularColor() const
{
	return mSpecularColor;
}
//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetSpecularPow() const
{
	return mSpecularPow;
}
//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetIntensity() const
{
	return mIntensity;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetFogColorHeight() const
{
	return mFogColorHeight;
}
//----------------------------------------------------------------------------
inline const Float2 &AmbientRegionActor::GetFogParamHeight() const
{
	return mFogParamHeight;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetFogColorDistance() const
{
	return mFogColorDist;
}
//----------------------------------------------------------------------------
inline const Float2 &AmbientRegionActor::GetFogParamDistance() const
{
	return mFogParamDist;
}
//----------------------------------------------------------------------------