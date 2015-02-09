// PX2UIProgressBar.inl

//----------------------------------------------------------------------------
inline UIPicBox *UIProgressBar::GetBackPicBox()
{
	return mBackPicBox;
}
//----------------------------------------------------------------------------
inline UIPicBox *UIProgressBar::GetProgressPicBox()
{
	return mProgressPicBox;
}
//----------------------------------------------------------------------------
inline UIPicBox *UIProgressBar::GetOverPicBox()
{
	return mOverPicBox;
}
//----------------------------------------------------------------------------
inline float UIProgressBar::GetProgress() const
{
	return mProgress;
}
//----------------------------------------------------------------------------
inline UIProgressBarCtrl *UIProgressBar::GetProgressBarCtrl()
{
	return mPBCtrl;
}
//----------------------------------------------------------------------------