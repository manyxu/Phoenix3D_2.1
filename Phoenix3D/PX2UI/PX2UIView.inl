// PX2UIView.inl

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