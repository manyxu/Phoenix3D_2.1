/*
*
* ÎÄ¼şÃû³Æ	£º	PX2SceneEntity.inl
*
*/

//----------------------------------------------------------------------------
inline std::list<EntityPtr> &SceneEntity::GetEntities ()
{
	return mEntities;
}
//----------------------------------------------------------------------------
inline int SceneEntity::GetNumEntities () const
{
	return (int)mEntities.size();
}
//----------------------------------------------------------------------------
inline Entity *SceneEntity::GetCameraEntity ()
{
	return mCaneraEntity;
}
//----------------------------------------------------------------------------
inline Node *SceneEntity::GetNode ()
{
	return mNode;
}
//----------------------------------------------------------------------------
inline const Node *SceneEntity::GetNode () const
{
	return mNode;
}
//----------------------------------------------------------------------------