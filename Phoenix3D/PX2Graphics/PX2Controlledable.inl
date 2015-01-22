/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Controlledable.inl
*
*/

//----------------------------------------------------------------------------
inline bool Controlledable::IsSelfCtrled () const
{
	return mIsSelfCtrled;
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