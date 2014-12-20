/*
*
* ÎÄ¼þÃû³Æ	£º	PX2CameraActor.inl
*
*/

//----------------------------------------------------------------------------
inline void CameraActor::SetCamera (Camera *camera)
{
	mCamera = camera;
	mCameraNode->SetCamera(mCamera);
}
//----------------------------------------------------------------------------
inline Camera *CameraActor::GetCamera ()
{
	return mCamera;
}
//----------------------------------------------------------------------------
inline CameraNode *CameraActor::GetCameraNode ()
{
	return mCameraNode;
}
//----------------------------------------------------------------------------