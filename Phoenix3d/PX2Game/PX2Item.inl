/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Item.inl
*
*/

//----------------------------------------------------------------------------
inline void Item::SetTypeString (const std::string &typeString)
{
	mTypeString = typeString;
}
//----------------------------------------------------------------------------
inline const std::string &Item::GetTypeString () const
{
	return mTypeString;
}
//----------------------------------------------------------------------------
inline void Item::SetCharacter (Character *character)
{
	mCharacter = character;
}
//----------------------------------------------------------------------------
inline void Item::SetCanBeEquipped (bool can)
{
	mIsCanBeEquipped = can;
}
//----------------------------------------------------------------------------
inline bool Item::IsCanBeEquipped () const
{
	return mIsCanBeEquipped;
}
//----------------------------------------------------------------------------
inline void Item::SetEquippedDoUse (bool use)
{
	mIsEquippedDoUse = use;
}
//----------------------------------------------------------------------------
inline bool Item::IsEquippedDoUse () const
{
	return mIsEquippedDoUse;
}
//----------------------------------------------------------------------------
inline bool Item::CanUseNow () const
{
	return mCanUseNow;
}
//----------------------------------------------------------------------------
inline bool Item::IsEquipped () const
{
	return mIsEquipped;
}
//----------------------------------------------------------------------------
inline int Item::GetLevel () const
{
	return mLevel;
}
//----------------------------------------------------------------------------
inline bool Item::IsUsing () const
{
	return mIsUsing;
}
//----------------------------------------------------------------------------
inline void Item::SetScriptHandler_Use (const std::string &handler)
{
	mScriptHandler_Use = handler;
}
//----------------------------------------------------------------------------
inline const std::string &Item::GetScriptHandler_Use () const
{
	return mScriptHandler_Use;
}
//----------------------------------------------------------------------------
inline Character *Item::GetCharacter () const
{
	return mCharacter;
}
//----------------------------------------------------------------------------