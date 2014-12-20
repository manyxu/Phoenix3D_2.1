/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Buf.inl
*
*/

//----------------------------------------------------------------------------
inline int Buf::GetID () const
{
	return mID;
}
//----------------------------------------------------------------------------
inline int Buf::GetTypeID () const
{
	return mTypeID;
}
//----------------------------------------------------------------------------
inline void Buf::SetTime (float seconds)
{
	mTime = seconds;
}
//----------------------------------------------------------------------------
inline float Buf::GetTime () const
{
	return mTime;
}
//----------------------------------------------------------------------------
inline void Buf::SetClass (const std::string &classStr)
{
	mClassStr = classStr;
}
//----------------------------------------------------------------------------
inline const std::string &Buf::GetClass () const
{
	return mClassStr;
}
//----------------------------------------------------------------------------
inline void Buf::SetClassOnlyOne (bool classOnlyOne)
{
	mIsClassOnlyOne = classOnlyOne;
}
//----------------------------------------------------------------------------
inline bool Buf::IsClassOnlyOne () const
{
	return mIsClassOnlyOne;
}
//----------------------------------------------------------------------------
inline void Buf::SetUseCenterIDAlive (bool use)
{
	mIsUseCenterIDAlive = use;
}
//----------------------------------------------------------------------------
inline bool Buf::IsUseCenterIDAlive () const
{
	return mIsUseCenterIDAlive;
}
//----------------------------------------------------------------------------
inline void Buf::SetUseRange (bool useRange)
{
	mIsUseRange = useRange;
}
//----------------------------------------------------------------------------
inline bool Buf::IsUseRange () const
{
	return mIsUseRange;
}
//----------------------------------------------------------------------------
inline void Buf::SetCenter (const APoint &center)
{
	mCenter = center;
}
//----------------------------------------------------------------------------
inline const APoint &Buf::GetCenter () const
{
	return mCenter;
}
//----------------------------------------------------------------------------
inline void Buf::SetCenterCharacterID (int id)
{
	mCenterCharacterID = id;
}
//----------------------------------------------------------------------------
inline int Buf::GetCenterCharacterID () const
{
	return mCenterCharacterID;
}
//----------------------------------------------------------------------------
inline void Buf::SetRadius (float radius)
{
	mRadius = radius;
}
//----------------------------------------------------------------------------
inline float Buf::GetRadius () const
{
	return mRadius;
}
//----------------------------------------------------------------------------
inline void Buf::SetOver (bool over)
{
	mIsOver = over;
}
//----------------------------------------------------------------------------
inline bool Buf::IsOver () const
{
	return mIsOver;
}
//----------------------------------------------------------------------------
inline float Buf::GetTimeAdded () const
{
	return mTimeAdded;
}
//----------------------------------------------------------------------------
inline const std::string &Buf::GetAddedIDString () const
{
	return mAddedIDString;
}
//----------------------------------------------------------------------------
inline void Buf::SetCharacter (Character *character)
{
	mCharacter = character;
}
//----------------------------------------------------------------------------
inline Character *Buf::GetCharacter ()
{
	return mCharacter;
}
//----------------------------------------------------------------------------
inline void Buf::SetScriptHandler_OnAdded (const std::string &handler)
{
	mScriptHandler_OnAdded = handler;
}
//----------------------------------------------------------------------------
inline const std::string &Buf::GetScriptHandler_OnAdded () const
{
	return mScriptHandler_OnAdded;
}
//----------------------------------------------------------------------------
inline void Buf::SetScriptHandler_OnRemoved (const std::string &handler)
{
	mScriptHandler_OnRemoved = handler;
}
//----------------------------------------------------------------------------
inline const std::string &Buf::GetScirptHandler_OnRemoved () const
{
	return mScriptHandler_OnRemoved;
}
//----------------------------------------------------------------------------