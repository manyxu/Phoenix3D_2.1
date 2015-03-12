// PX2TriggerActor.inl

//----------------------------------------------------------------------------
inline TriggerActor::AreaType TriggerActor::GetAreaType() const
{
	return mAreaType;
}
//----------------------------------------------------------------------------
inline void TriggerActor::SetAreaParam(const AVector &vec)
{
	mAreaParam = vec;
}
//----------------------------------------------------------------------------
inline const AVector &TriggerActor::GetAreaParam() const
{
	return mAreaParam;
}
//----------------------------------------------------------------------------
inline bool TriggerActor::IsTrigered() const
{
	return mIsTrigered;
}
//----------------------------------------------------------------------------
inline void TriggerActor::SetTrigerType(TrigerType type)
{
	mTrigerType = type;
}
//----------------------------------------------------------------------------
inline TriggerActor::TrigerType TriggerActor::GetTrigerType() const
{
	return mTrigerType;
}
//----------------------------------------------------------------------------