// PX2Actor.inl

//----------------------------------------------------------------------------
inline std::bitset<PX2_ACTOR_BS_SIZE> &Actor::GetBitSet()
{
	return mBitSet;
}
//----------------------------------------------------------------------------
inline const std::bitset<PX2_ACTOR_BS_SIZE> &Actor::GetBitSet() const
{
	return mBitSet;
}
//----------------------------------------------------------------------------
inline Movable *Actor::GetMovable()
{
	return mMovable;
}
//----------------------------------------------------------------------------
inline Node *Actor::GetNodeHelp()
{
	return mHelpNode;
}
//----------------------------------------------------------------------------
inline bool Actor::IsPickable() const
{
	return mIsPickable;
}
//----------------------------------------------------------------------------
inline const AVector &Actor::GetHeading() const
{
	return mHeading;
}
//----------------------------------------------------------------------------
inline float Actor::GetRadius() const
{
	return mRadius;
}
//----------------------------------------------------------------------------
inline float Actor::GetHeight() const
{
	return mHeight;
}
//----------------------------------------------------------------------------
inline void Actor::SetSceneContainer(void *container)
{
	mSceneContainer = container;
}
//----------------------------------------------------------------------------
inline void Actor::SetSceneContainerIndex(int index)
{
	mSceneContainerIndex = index;
}
//----------------------------------------------------------------------------
inline void *Actor::GetSceneContainer() const
{
	return mSceneContainer;
}
//----------------------------------------------------------------------------
inline int Actor::GetSceneContainerIndex() const
{
	return mSceneContainerIndex;
}
//----------------------------------------------------------------------------