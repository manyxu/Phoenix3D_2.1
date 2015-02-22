// PX2LodTerrainVertex.inl

//----------------------------------------------------------------------------
inline void LODTerrainVertex::SetDependent (int i,
											 LODTerrainVertex* pkDependent)
{
	assertion(0<=i&&i<=1, "i should be in range [0,1].");
	mDependent[i] = pkDependent;
}
//----------------------------------------------------------------------------
inline LODTerrainVertex* LODTerrainVertex::GetDependent (int i)
{
	assertion(0<=i&&i<=1, "i should be in range [0,1].");
	return mDependent[i];
}
//----------------------------------------------------------------------------
inline bool LODTerrainVertex::IsEnabled () const
{
	return mEnabled;
}
//----------------------------------------------------------------------------