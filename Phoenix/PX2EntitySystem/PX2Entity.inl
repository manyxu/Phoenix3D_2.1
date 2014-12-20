/*
*
* ÎÄ¼şÃû³Æ	£º	PX2Entity.inl
*
*/

//----------------------------------------------------------------------------
template <typename T>
T *Entity::GetM (int type)
{
	return DynamicCast<T>(GetM(type));
}
//----------------------------------------------------------------------------
inline void Entity::SetSceneEntity (Entity *ent)
{
	mSceneEntity = ent;
}
//----------------------------------------------------------------------------
inline Entity *Entity::GetSceneEntity ()
{
	return mSceneEntity;
}
//----------------------------------------------------------------------------
inline const Entity *Entity::GetSceneEntity () const
{
	return mSceneEntity;
}
//----------------------------------------------------------------------------
