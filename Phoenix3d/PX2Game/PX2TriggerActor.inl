/*
*
* ÎÄ¼þÃû³Æ	£º	PX2TriggerActor.inl
*
*/

//----------------------------------------------------------------------------
inline void TriggerActor::Enable (bool enable)
{
	mEnable = enable;
}
//----------------------------------------------------------------------------
inline bool TriggerActor::IsEnable ()
{
	return mEnable;
}
//----------------------------------------------------------------------------
inline TriggerActor::AreaType TriggerActor::GetAreaType ()
{
	return mAreaType;
}
//----------------------------------------------------------------------------
