// PX2Edit.inl

//----------------------------------------------------------------------------
inline Edit::EditType Edit::GetEditType() const
{
	return mEditType;
}
//----------------------------------------------------------------------------
inline Edit::EditMode Edit::GetEditMode() const
{
	return mEditMode;
}
//----------------------------------------------------------------------------
inline EditMap *Edit::GetEditMap()
{
	return mEditMap;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
inline GeoObjFactory *Edit::GetGOF()
{
	return mGeoObjFactory;
}
inline EditParams *Edit::GetEditParams()
{
	return mEditParams;
}
//----------------------------------------------------------------------------
inline void Edit::SetPickPos(const PX2::APoint &pos)
{
	mPickPos = pos;
}
//----------------------------------------------------------------------------
inline PX2::APoint Edit::GetPickPos()
{
	return mPickPos;
}
//----------------------------------------------------------------------------