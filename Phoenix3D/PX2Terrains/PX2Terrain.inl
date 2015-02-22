// PX2Terrain.inl

//----------------------------------------------------------------------------
inline EditTerrainMaterial *Terrain::GetEidtMaterial ()
{
	return mMtlEdit;
}
//----------------------------------------------------------------------------
inline Shine *Terrain::GetShine ()
{
	return mShine;
}
//----------------------------------------------------------------------------
inline int Terrain::GetRowQuantity () const
{
	return mNumRows;
}
//----------------------------------------------------------------------------
inline int Terrain::GetColQuantity () const
{
	return mNumCols;
}
//----------------------------------------------------------------------------
inline int Terrain::GetSize () const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float Terrain::GetSpacing () const
{
	return mSpacing;
}
//----------------------------------------------------------------------------
inline float Terrain::GetJunglerFrequency ()
{
	return mJunglerFrequency;
}
//----------------------------------------------------------------------------
inline float Terrain::GetJunglerStrength ()
{
	return mJunglerStrength;
}
//----------------------------------------------------------------------------