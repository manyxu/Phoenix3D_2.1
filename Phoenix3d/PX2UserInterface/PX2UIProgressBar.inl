/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIProgressBar.inl
*
*/

//----------------------------------------------------------------------------
inline UIPicBox *UIProgressBar::GetBackPicBox ()
{
	return mBackPicBox;
}
//----------------------------------------------------------------------------
inline UIPicBox *UIProgressBar::GetProgressPicBox ()
{
	return mProgressPicBox;
}
//----------------------------------------------------------------------------
inline UIPicBox *UIProgressBar::GetOverPicBox ()
{
	return mOverPicBox;
}
//----------------------------------------------------------------------------
inline float UIProgressBar::GetWidth () const
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float UIProgressBar::GetHeight () const
{
	return mSize.Height;
}
//----------------------------------------------------------------------------
inline const Sizef &UIProgressBar::GetSize () const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float UIProgressBar::GetProgress () const
{
	return mProgress;
}
//----------------------------------------------------------------------------
inline UIProgressBarCtrl *UIProgressBar::GetProgressBarCtrl ()
{
	return mPBCtrl;
}
//----------------------------------------------------------------------------