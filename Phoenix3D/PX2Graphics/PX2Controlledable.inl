// PX2Controlledable.inl

//----------------------------------------------------------------------------
inline bool Controlledable::IsSelfCtrled () const
{
	return mIsSelfCtrled;
}
//----------------------------------------------------------------------------
inline void Controlledable::SetAutoPlay(bool autoPlay)
{
	mIsAutoPlay = autoPlay;
}
//----------------------------------------------------------------------------
inline bool Controlledable::IsAutoPlay() const
{
	return mIsAutoPlay;
}
//----------------------------------------------------------------------------
inline int Controlledable::GetNumControllers () const
{
    return (int)mControllers.size();
}
//----------------------------------------------------------------------------
inline Controller* Controlledable::GetController (int i) const
{
    if (0 <= i && i < GetNumControllers())
    {
        return mControllers[i];
    }

    return 0;
}
//----------------------------------------------------------------------------