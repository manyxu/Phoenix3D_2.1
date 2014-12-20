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
inline float Actor::GetSpeed () const
{
	return mVelocity.Length();
}
//----------------------------------------------------------------------------
inline bool Actor::IsStopSpeed () const
{
	return mIsStopSpeed;
}
//----------------------------------------------------------------------------
inline const AVector &Actor::GetVelocity () const
{
	return mVelocity; 
}
//----------------------------------------------------------------------------
inline const AVector &Actor::GetHeading () const
{
	return mHeading;
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
inline void Actor::SetGridMoveOn (bool on)
{
	mIsGridMoveOn = on;
}
//----------------------------------------------------------------------------
inline bool Actor::IsGridMoveOn () const
{
	return mIsGridMoveOn;
}
//----------------------------------------------------------------------------
inline GridMoveBehavior *Actor::GetGridMoveBehavior ()
{
	return mGridMoveBehavior;
}
//----------------------------------------------------------------------------
inline void Actor::SetArriveRange (float dis)
{
	mArriveRange = dis;
}
//----------------------------------------------------------------------------
inline float Actor::GetArriveRange () const
{
	return mArriveRange;
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