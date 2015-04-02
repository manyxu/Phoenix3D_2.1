// PX2Edit.inl

//----------------------------------------------------------------------------
inline bool Edit::CanDoEdit() const
{
	return ET_SIMULATE != mEditType && ET_PLAY != mEditType;
}
//----------------------------------------------------------------------------
inline Edit::EditType Edit::GetEditType() const
{
	return mEditType;
}
//----------------------------------------------------------------------------
inline Edit::EditAxisMode Edit::GetEdtiAxisMode() const
{
	return mEditAxisMode;
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
inline void Edit::SetCameraMoveLevel(int level)
{
	mCameraMoveLevel = level;
}
//----------------------------------------------------------------------------
inline int Edit::GetCameraMoveLevel() const
{
	return mCameraMoveLevel;
}
//----------------------------------------------------------------------------
inline float Edit::GetCameraMoveSpeedBase() const
{
	return mCameraMoveSpeedBase;
}
//----------------------------------------------------------------------------
inline float Edit::GetCameraMoveSpeed() const
{
	return mCameraMoveSpeedBase * mCameraMoveLevel;
}
//----------------------------------------------------------------------------
inline const APoint &Edit::GetPickPos() const
{
	return mPickPos;
}
//----------------------------------------------------------------------------
inline void Edit::SetSelectPath_ChildFilenames(
	const std::vector<std::string> &filenames)
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
inline const SelectResData &Edit::GetSelectedResource() const
{
	return mSelectResData;
}
//----------------------------------------------------------------------------
inline PX2::Object *Edit::GetPreViewObject()
{
	return mPreObject;
}
//----------------------------------------------------------------------------
inline void Edit::SetCopyObject(Object *obj)
{
	mCopyObject = obj;
}
//----------------------------------------------------------------------------
inline Object *Edit::GetCopyObject()
{
	return mCopyObject;
}
//----------------------------------------------------------------------------
inline TimeLineEdit *Edit::GetTimeLineEdit()
{
	return mTimeLineEidt;
}
//----------------------------------------------------------------------------
inline TerrainEdit *Edit::GetTerrainEdit()
{
	return mTerrainEdit;
}
//----------------------------------------------------------------------------