/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIRangeFrame.inl
*
*/

//----------------------------------------------------------------------------
inline float UIRangeFrame::GetWidth () const
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float UIRangeFrame::GetHeight () const
{
	return mSize.Height;
}
//----------------------------------------------------------------------------
inline const Sizef &UIRangeFrame::GetSize () const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline bool UIRangeFrame::IsShowRange () const
{
	return mIsShowRange;
}
//----------------------------------------------------------------------------
inline UIPicBox *UIRangeFrame::GetUIRangeBox ()
{
	return mRangePicBox;
}
//----------------------------------------------------------------------------
inline void UIRangeFrame::SetDoPickRange (float range)
{
	mDoPickRange = range;
}
//----------------------------------------------------------------------------
inline float UIRangeFrame::GetDoPickRange () const
{
	return mDoPickRange;
}
//----------------------------------------------------------------------------