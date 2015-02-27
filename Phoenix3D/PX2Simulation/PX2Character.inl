// PX2Character.inl

//----------------------------------------------------------------------------
inline void Character::SetUseAutoWorldBound(bool isUseAutoWorldBound)
{
	mIsAutoWorldBound = isUseAutoWorldBound;
}
//----------------------------------------------------------------------------
inline bool Character::IsUseAutoWorldBound() const
{
	return mIsAutoWorldBound;
}
//----------------------------------------------------------------------------
inline void Character::SetAutoWorldBoundRadius(float radius)
{
	mAutoWorldBoundRadius = radius;
}
//----------------------------------------------------------------------------
inline float Character::GetAutoWorldBoundRadius() const
{
	return mAutoWorldBoundRadius;
}
//----------------------------------------------------------------------------
inline std::map<int, AnimationPtr> &Character::GetAnimsMap()
{
	return mAnimsMap;
}
//----------------------------------------------------------------------------
inline int Character::GetDefaultAnimID() const
{
	return mDefaultAnimID;
}
//----------------------------------------------------------------------------
inline Animation *Character::GetDefaultAnim()
{
	return mDefaultAnim;
}
//----------------------------------------------------------------------------
inline Animation *Character::GetCurPlayingAnim()
{
	return mCurPlayingAnim;
}
//----------------------------------------------------------------------------
inline float Character::GetBaseHPCurLevel() const
{
	return mBaseHPCurLevel;
}
//----------------------------------------------------------------------------
inline bool Character::IsDead() const
{
	return mIsDead;
}
//----------------------------------------------------------------------------
inline void Character::SetDieDoDelete(bool isDieDoDelete)
{
	mIsDieDoDelete = isDieDoDelete;
}
//----------------------------------------------------------------------------
inline bool Character::IsDieDoDelete() const
{
	return mIsDieDoDelete;
}
//----------------------------------------------------------------------------
inline float Character::GetBaseAPCurLevel() const
{
	return mBaseAPCurLevel;
}
//----------------------------------------------------------------------------