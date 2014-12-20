/*
*
* ÎÄ¼şÃû³Æ	£º	PX2EntityModule.inl
*
*/

//----------------------------------------------------------------------------
inline void EntityModule::SetEntity (Entity *ent)
{
	mEntity = ent;
}
//----------------------------------------------------------------------------
inline Entity *EntityModule::GetEntity ()
{
	return mEntity;
}
//----------------------------------------------------------------------------
inline const Entity *EntityModule::GetEntity () const
{
	return mEntity;
}
//----------------------------------------------------------------------------