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
inline void Scene::SetViewPort (int xPosition, int yPosition, int width,
	int height)
{
	mViewportX = xPosition;
	mViewportY = yPosition;
	mViewportWidth = width;
	mViewportHeight = height;
}
//----------------------------------------------------------------------------
inline void Scene::GetViewport (int& xPosition, int& yPosition, int& width,
	int& height) const
{
	xPosition = mViewportX;
	yPosition = mViewportY;
	width = mViewportWidth;
	height = mViewportHeight;
}
//----------------------------------------------------------------------------
inline void Scene::SetAdjustCamWidthViewPort (bool doAdjust)
{
	mIsAdjustCamWithViewPort = doAdjust;
}
//----------------------------------------------------------------------------
inline bool Scene::IsAdjustCamWidthViewPort () const
{
	return mIsAdjustCamWithViewPort;
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