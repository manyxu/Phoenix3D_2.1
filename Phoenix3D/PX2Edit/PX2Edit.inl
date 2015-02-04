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
inline const APoint &Edit::GetPickPos() const
{
	return mPickPos;
}
//----------------------------------------------------------------------------
inline void Edit::SetSelectPath_ChildFilenames(const std::vector<std::string> &
	filenames)
{
	mSelectPath_ChildFilenames = filenames;
}
//----------------------------------------------------------------------------
inline void Edit::SetSelectPath_ChildPaths(const std::vector<std::string> &paths)
{
	mSelectPath_ChildPaths = paths;
}
//----------------------------------------------------------------------------
inline const std::vector<std::string> &Edit::GetSelectPath_ChildFilenames() const
{
	return mSelectPath_ChildFilenames;
}
//----------------------------------------------------------------------------
inline const std::vector<std::string> &Edit::GetSelectPath_ChildPaths() const
{
	return mSelectPath_ChildPaths;
}
//----------------------------------------------------------------------------