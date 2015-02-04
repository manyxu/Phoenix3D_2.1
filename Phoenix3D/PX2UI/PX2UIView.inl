// PX2UIView.inl

//----------------------------------------------------------------------------
inline int UIView::GetViewID() const
{
	return mViewID;
}
//----------------------------------------------------------------------------
inline Movable *UIView::GetSuperTopMovbale()
{
	return mSuperTopMovable;
}
//----------------------------------------------------------------------------
inline CameraNode *UIView::GetCameraNode()
{
	return mCameraNode;
}
//----------------------------------------------------------------------------
inline const Sizef &UIView::GetCameraFrustumSize() const
{
	return mCameraFrustumSize;
}
//----------------------------------------------------------------------------
inline bool UIView::IsCameraAutoAdjust() const
{
	return mIsCameraAutoAdjust;
}
//----------------------------------------------------------------------------