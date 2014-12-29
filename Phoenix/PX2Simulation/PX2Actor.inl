/*
*
* ÎÄ¼şÃû³Æ	£º	PX2Actor.inl
*
*/

//----------------------------------------------------------------------------
inline int Actor::GetNumComponents() const
{
	return (int)mComponents.size();
}
//----------------------------------------------------------------------------
inline Component *Actor::GetComponent(int i) const
{
	if (0 <= i && i < GetNumControllers())
	{
		return mComponents[i];
	}

	return 0;
}
//----------------------------------------------------------------------------