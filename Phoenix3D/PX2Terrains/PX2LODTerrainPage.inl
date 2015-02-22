// PX2LODTerrainPage.inl

//----------------------------------------------------------------------------
inline float LODTerrainPage::GetPixelTolerance () const
{
	return mPixelTolerance;
}
//----------------------------------------------------------------------------
inline float LODTerrainPage::GetTextureCoordinate (int index) const
{
	return  mTextureSpacing*(float)index;
}
//----------------------------------------------------------------------------