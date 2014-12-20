/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Scene3D.inl
*
*/

//----------------------------------------------------------------------------
inline void Scene3D::SetBakeSizeType (Scene3D::BakeSizeType type)
{
	mBakeSizeType = type;
}
//----------------------------------------------------------------------------
inline Scene3D::BakeSizeType Scene3D::GetBakeSizeType () const
{
	return mBakeSizeType;
}
//----------------------------------------------------------------------------
inline TerrainActor *Scene3D::GetTerrainActor ()
{
	return mTerrainActor;
}
//----------------------------------------------------------------------------
inline TagActor *Scene3D::GetSpawnDefaultActor ()
{
	return mSpawnTagActor;
}
//----------------------------------------------------------------------------
inline AmbientRegionActor *Scene3D::GetDefaultARActor ()
{
	return mDefaultARActor;
}
//----------------------------------------------------------------------------
inline bool Scene3D::IsUseLightTexture () const
{
	return mIsUseLightTexture;
}
//----------------------------------------------------------------------------