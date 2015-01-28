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
inline EditParams *Edit::GetEditParams()
{
	return mEditParams;
}
//----------------------------------------------------------------------------