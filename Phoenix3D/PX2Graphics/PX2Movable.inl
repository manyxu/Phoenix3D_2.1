// PX2Movable.inl

//----------------------------------------------------------------------------
inline void Movable::SetAlphaSelfCtrled (bool selfCtrled)
{
	mIsAlphaSelfCtrled = selfCtrled;
}
//----------------------------------------------------------------------------
inline void Movable::SetColorSelfCtrled (bool selfCtrled)
{
	mIsColorSelfCtrled = selfCtrled;
}
//----------------------------------------------------------------------------
inline bool Movable::IsAlphaSelfCtrled () const
{
	return mIsAlphaSelfCtrled;
}
//----------------------------------------------------------------------------
inline float Movable::GetAlpha () const
{
	return mAlpha;
}
//----------------------------------------------------------------------------
inline bool Movable::IsColorSelfCtrled () const
{
	return mIsColorSelfCtrled;
}
//----------------------------------------------------------------------------
inline const Float3 &Movable::GetColor () const
{
	return mColor;
}
//----------------------------------------------------------------------------
inline void Movable::SetBrightnessSelfCtrled (bool selfCtrled)
{
	mIsBrightnessSelfCtrled = selfCtrled;
}
//----------------------------------------------------------------------------
inline bool Movable::IsBrightnessSelfCtrled () const
{
	return mIsBrightnessSelfCtrled;
}
//----------------------------------------------------------------------------
inline float Movable::GetBrightness () const
{
	return mBrightness;
}
//----------------------------------------------------------------------------
inline Movable* Movable::GetParent ()
{
    return mParent;
}
//----------------------------------------------------------------------------
inline void Movable::SetParent (Movable* parent)
{
    mParent = parent;
}
//----------------------------------------------------------------------------
inline void Movable::SetUpdateTime (float time)
{
	mUpdateTime = time;
}
//----------------------------------------------------------------------------
inline float Movable::GetUpdateTime () const
{
	return mUpdateTime;
}
//----------------------------------------------------------------------------
inline void Movable::SetUpdatePriority (int updatePriority)
{
	mUpdatePriority = updatePriority;
}
//----------------------------------------------------------------------------
inline int Movable::GetUpdatePriority () const
{
	return mUpdatePriority;
}
//----------------------------------------------------------------------------
inline bool Movable::IsDoPick () const
{
	return mIsDoPick;
}
//----------------------------------------------------------------------------
inline void Movable::SetPickIngoreCullingMode (bool pickIngoreCullingMode)
{
	mIsPickIngoreCullingMode = pickIngoreCullingMode;
}
//----------------------------------------------------------------------------
inline bool Movable::IsPickIngoreCullingMode () const
{
	return mIsPickIngoreCullingMode;
}
//----------------------------------------------------------------------------
inline void Movable::SetNotPickedParentChildrenNotPicked (bool use)
{
	mIsNotPickedParentChildrenNotPicked = use;
}
//----------------------------------------------------------------------------
inline bool Movable::IsNotPickedParentChildrenNotPicked () const
{
	return mIsNotPickedParentChildrenNotPicked;
}
//----------------------------------------------------------------------------