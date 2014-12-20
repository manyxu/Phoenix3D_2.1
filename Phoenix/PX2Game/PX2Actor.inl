/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Actor.inl
*
*/

//----------------------------------------------------------------------------
inline void Actor::SetID (int id)
{
	mID = id;
}
//----------------------------------------------------------------------------
inline int Actor::GetID () const
{
	return mID;
}
//----------------------------------------------------------------------------
inline int Actor::GetTypeID () const
{
	return mTypeID;
}
//----------------------------------------------------------------------------
inline int Actor::GetGroup () const
{
	return mGroup;
}
//----------------------------------------------------------------------------
inline std::bitset<PX2_ACTOR_BS_SIZE> &Actor::GetBitSet ()
{
	return mBitSet;
}
//----------------------------------------------------------------------------
inline const std::bitset<PX2_ACTOR_BS_SIZE> &Actor::GetBitSet () const
{
	return mBitSet;
}
//----------------------------------------------------------------------------
inline Movable *Actor::GetMovable () const
{
	return mMovable;
}
//----------------------------------------------------------------------------
inline bool Actor::IsVisible ()
{
	return mIsVisible;
}
//----------------------------------------------------------------------------
inline float Actor::GetTransparent ()
{
	return mActorTransparent;
}
//----------------------------------------------------------------------------
inline const std::string &Actor::GetMoveableFilename () const
{
	return mMoveableFilename;
}
//----------------------------------------------------------------------------
inline bool Actor::IsShareVIM () const
{
	return mIsShareVIM;
}
//----------------------------------------------------------------------------
inline Movable *Actor::GetHelpMovable ()
{
	return mHelpMovable;
}
//----------------------------------------------------------------------------
inline bool Actor::IsHelpMovableShow ()
{
	return mIsShowHelpMovable;
}
//----------------------------------------------------------------------------
inline Scene *Actor::GetScene () const
{
	return mScene;
}
//----------------------------------------------------------------------------
inline void *Actor::GetSceneContainer () const
{
	return mSceneContainer;
}
//----------------------------------------------------------------------------
inline int Actor::GetSceneContainerIndex () const
{
	return mSceneContainerIndex;
}
//----------------------------------------------------------------------------
inline bool Actor::IsPickable () const
{
	return mIsPickable;
}
//----------------------------------------------------------------------------
inline const APoint &Actor::GetPosition () const
{
	return mPosition;
}
//----------------------------------------------------------------------------
inline const APoint &Actor::GetScale () const
{
	return mScale;
}
//----------------------------------------------------------------------------
inline const APoint &Actor::GetRotation () const
{
	return mRotation;
}
//----------------------------------------------------------------------------
inline bool Actor::IsStopSpeed () const
{
	return !mStopSpeedTags.empty();
}
//----------------------------------------------------------------------------
inline const AVector &Actor::GetVelocityDir () const
{
	return mVelocityDir; 
}
//----------------------------------------------------------------------------
inline const AVector &Actor::GetHeading () const
{
	return mHeading;
}
//----------------------------------------------------------------------------
inline bool Actor::IsHeadingAlignVelocityDir () const
{
	mIsHeadingAlignVelocityDir;
}
//----------------------------------------------------------------------------
inline const AVector &Actor::GetSmoothHeading () const
{
	return mSmoothHeading;
}
//----------------------------------------------------------------------------
inline bool Actor::IsStaticType () const
{
	return mIsStaticType;
}
//----------------------------------------------------------------------------
inline bool Actor::IsBuilding () const
{
	return mIsBuilding;
}
//----------------------------------------------------------------------------
inline float Actor::GetSelfRadius () const
{
	return mSelfRadius;
}
//----------------------------------------------------------------------------
inline float Actor::GetHeight () const
{
	return mHeight;
}
//----------------------------------------------------------------------------
inline Actor::MoveBehaviorType Actor::GetMoveBehaviorType () const
{
	return mMoveBehaviorType;
}
//----------------------------------------------------------------------------
inline MoveBehavior *Actor::GetMoveBehavior () const
{
	return mMoveBehavior;
}
//----------------------------------------------------------------------------
inline void Actor::SetSmoothOn (bool on)
{
	mIsSmoothOn = on;
}
//----------------------------------------------------------------------------
inline bool Actor::IsSmoothOn () const
{
	return mIsSmoothOn;
}
//----------------------------------------------------------------------------
inline void Actor::SetMass (float mass)
{
	mMass = mass;
}
//----------------------------------------------------------------------------
inline float Actor::GetMass () const
{
	return mMass; 
}
//----------------------------------------------------------------------------
inline bool Actor::IsBakeObject () const
{
	return mIsBakeObject;
}
//----------------------------------------------------------------------------
inline bool Actor::IsBakeTarget () const
{
	return mIsBakeTarget;
}
//----------------------------------------------------------------------------