/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AmbientRegionActor.inl
*
*/

//----------------------------------------------------------------------------
inline void AmbientRegionActor::EnableBakeGI (bool enableGI)
{
	mIsEnableGI = enableGI;
}
//----------------------------------------------------------------------------
inline bool AmbientRegionActor::IsEnableBakeGI () const
{
	return mIsEnableGI;
}
//----------------------------------------------------------------------------
inline void AmbientRegionActor::SetGISkyLightColor (const Float3 &color)
{
	mBakeSkyLightColor = color;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetGISkyLightColor () const
{
	return mBakeSkyLightColor;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetAmbientColor_Bake () const
{
	return mAmbientColor_Bake;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetDiffColor_Bake () const
{
	return mDiffColor_Bake;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetSpecColor_Bake () const
{
	return mSpecColor_Bake;
}
//----------------------------------------------------------------------------
inline void AmbientRegionActor::SetAmbientScale_Bake (float scale)
{
	mAmbientScale_Bake = scale;
}
//----------------------------------------------------------------------------
inline void AmbientRegionActor::SetDiffuseScale_Bake (float scale)
{
	mDiffuseScale_Bake = scale;
}
//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetAmbientScale_Bake () const
{
	return mAmbientScale_Bake;
}
//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetDiffuseScale_Bake () const
{
	return mDiffuseScale_Bake;
}
//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetSpecularScale_Bake () const
{
	return mSpecularScale_Bake;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetAmbientColor () const
{
	return mAmbientColor;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetLightDiffColor () const
{
	return mDirLightDiffColor;
}
//----------------------------------------------------------------------------
inline const Float3 &AmbientRegionActor::GetLightSpecColor () const
{
	return mLightSpecColor;
}
//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetLightSpecPow () const
{
	return mLightSpecPow;
}
//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetLightIntensity () const
{
	return mLightIntensity;
}
//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetHorAngle () const
{
	return mHorAngle;
}
//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetVerAngle () const
{
	return mVerAngle;
}
//----------------------------------------------------------------------------
inline void AmbientRegionActor::SetBakeShadowAngle (float shadowAnge)
{
	mBakeShadowAngle = shadowAnge;
}
//----------------------------------------------------------------------------
inline float AmbientRegionActor::GetBakeShadowAngle () const
{
	return mBakeShadowAngle;
}
//----------------------------------------------------------------------------
inline const Light *AmbientRegionActor::GetLight () const
{
	return mLight;
}
//----------------------------------------------------------------------------
inline Light *AmbientRegionActor::GetLight ()
{
	return mLight;
}
//----------------------------------------------------------------------------