// PX2Scene.inl

//----------------------------------------------------------------------------
inline EnvirParam *Scene::GetEnvirParam()
{
	return mEnvirParam;
}
//----------------------------------------------------------------------------
inline CameraActor *Scene::GetUseCameraActor()
{
	return mCameraActor;
}
//----------------------------------------------------------------------------
inline AmbientRegionActor *Scene::GetDefaultAmbientRegionActor()
{
	return mDefaultAmbientRegionActor;
}
//----------------------------------------------------------------------------
inline TerrainActor *Scene::GetTerrainActor()
{
	return mTerrainActor;
}
//----------------------------------------------------------------------------
inline SkyActor *Scene::GetSkyActor()
{
	return mSkyActor;
}
//----------------------------------------------------------------------------
inline bool Scene::IsShowHelpNode() const
{
	return mIsShowHelpNode;
}
//----------------------------------------------------------------------------
inline Scene::SceneManageType Scene::GetSceneManageType()
{
	return mSceneManageType;
}
//----------------------------------------------------------------------------
inline const Sizef &Scene::GetSize() const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline const Rectf &Scene::GetViewPortProject() const
{
	return mViewPort;
}
//----------------------------------------------------------------------------
inline bool Scene::IsUseBloom() const
{
	return mIsUseBloom;
}
//----------------------------------------------------------------------------
inline const Float2 &Scene::GetBloomRenderTargetSize() const
{
	return mBloomRenderTargetSize;
}
//----------------------------------------------------------------------------
inline float Scene::GetBloomBlurDeviation() const
{
	return mBloomBlurDeviation;
}
//----------------------------------------------------------------------------
inline float Scene::GetBloomBlurWeight() const
{
	return mBloomBlurWeight;
}
//----------------------------------------------------------------------------
inline float Scene::GetBloomWeight() const
{
	return mBloomWeight;
}
//----------------------------------------------------------------------------
inline const Float4 &Scene::GetBloomBrightParam() const
{
	return mBloomBrightParam;
}
//----------------------------------------------------------------------------
inline const Float4 &Scene::GetBloomParam() const
{
	return mBloomParam;
}
//----------------------------------------------------------------------------
inline bool Scene::IsUseShadowMap() const
{
	return mIsUseShadowMap;
}
//----------------------------------------------------------------------------
inline bool Scene::IsShadowRenderTargetSizeSameWithScreen() const
{
	return mIsShadowRenderTargetSizeSameWithScreen;
}
//----------------------------------------------------------------------------
inline const Float2 &Scene::GetShadowRenderTargetSize() const
{
	return mShadowRenderTargetSize;
}
//----------------------------------------------------------------------------
inline float Scene::GetShadowOffsetProperty_Scale() const
{
	return mEnvirParam->GetShadowMap_OffsetPropertyScale();
}
//----------------------------------------------------------------------------
inline float Scene::GetShadowOffsetProperty_Bias() const
{
	return mEnvirParam->GetShadowMap_OffsetPropertyBias();
}
//----------------------------------------------------------------------------