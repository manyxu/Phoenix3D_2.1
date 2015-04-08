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
inline bool Scene::IsScene_UseBloom() const
{
	return mIsScene_UseBloom;
}
//----------------------------------------------------------------------------
inline const Float2 &Scene::GetScene_BloomRenderTargetSize() const
{
	return mScene_BloomRenderTargetSize;
}
//----------------------------------------------------------------------------
inline float Scene::GetScene_BloomBlurDeviation() const
{
	return mScene_BloomBlurDeviation;
}
//----------------------------------------------------------------------------
inline float Scene::GetScene_BloomBlurWeight() const
{
	return mScene_BloomBlurWeight;
}
//----------------------------------------------------------------------------
inline float Scene::GetScene_BloomWeight() const
{
	return mScene_BloomWeight;
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
inline bool Scene::IsScene_UseShadowMap() const
{
	return mIsScene_UseShadowMap;
}
//----------------------------------------------------------------------------
inline bool Scene::IsScene_ShadowRenderTargetSizeSameWithScreen() const
{
	return mIsScene_ShadowRenderTargetSizeSameWithScreen;
}
//----------------------------------------------------------------------------
inline const Float2 &Scene::GetScene_ShadowRenderTargetSize() const
{
	return mScene_ShadowRenderTargetSize;
}
//----------------------------------------------------------------------------