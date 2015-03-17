// PX2TerrainActor.inl

//----------------------------------------------------------------------------
inline bool TerrainActor::IsUseLod() const
{
	return mIsUseLOD;
}
//----------------------------------------------------------------------------
inline RawTerrain *TerrainActor::GetRawTerrain()
{
	return mRawTerrain;
}
//----------------------------------------------------------------------------
inline LODTerrain *TerrainActor::GetLODTerrain()
{
	return mLODTerrain;
}
//----------------------------------------------------------------------------