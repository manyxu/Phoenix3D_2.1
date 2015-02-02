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
inline GeoObjFactory *Edit::GetGOF()
{
	return mGeoObjFactory;
}
//----------------------------------------------------------------------------
inline EditParams *Edit::GetEditParams()
{
	return mEditParams;
}
//----------------------------------------------------------------------------
inline void Edit::SetPickPos(const APoint &pos)
{
	mPickPos = pos;
}
//----------------------------------------------------------------------------
inline const APoint &Edit::GetPickPos() const
{
	return mPickPos;
}
//----------------------------------------------------------------------------