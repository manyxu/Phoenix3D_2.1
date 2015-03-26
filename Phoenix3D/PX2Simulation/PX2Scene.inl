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