/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Scene.inl
*
*/

//----------------------------------------------------------------------------
inline void Scene::SetUpdateCallback (SceneUpdateCallback callback)
{
	mUpdateCallback = callback;
}
//----------------------------------------------------------------------------
inline SceneUpdateCallback Scene::GetUpdateCallback () const
{
	return mUpdateCallback;
}
//----------------------------------------------------------------------------
inline CameraActor *Scene::GetCameraActor ()
{
	return mCameraActor;
}
//----------------------------------------------------------------------------
inline void Scene::SetSceneID (int id)
{
	mSceneID = id;
}
//----------------------------------------------------------------------------
inline int Scene::GetSceneID ()
{
	return mSceneID;
}
//-----------------------------------------------------------------------------
inline float Scene::GetSceneLength () const
{
	return mLength;
}
//-----------------------------------------------------------------------------
inline float Scene::GetSceneWidth () const
{
	return mWidth;
}
//----------------------------------------------------------------------------
inline Scene::SceneManageType Scene::GetSceneManageType ()
{
	return mSceneManageType;
}
//----------------------------------------------------------------------------
inline PX2::Node *Scene::GetSceneNode ()
{
	return mSceneNode;
}
//----------------------------------------------------------------------------
inline void Scene::SetViewport (const Rectf &rect)
{
	mViewport = rect;
}
//----------------------------------------------------------------------------
inline const Rectf &Scene::GetViewport () const
{
	return mViewport;
}
//----------------------------------------------------------------------------
inline int Scene::GetNumActors ()
{
	return (int)mActors.size();
}
//----------------------------------------------------------------------------
inline bool Scene::IsExistActorPositionChanged ()
{
	return mIsActorPositionChanged;
}
//----------------------------------------------------------------------------
inline Culler &Scene::GetCuller ()
{
	return mCuller;
}
//----------------------------------------------------------------------------