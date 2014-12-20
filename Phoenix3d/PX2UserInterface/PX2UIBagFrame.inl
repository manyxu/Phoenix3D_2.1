/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIBagFrame.inl
*
*/

//----------------------------------------------------------------------------
inline float UIBagFrame::GetWidth () const
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float UIBagFrame::GetHeight () const
{
	return mSize.Height;
}
//----------------------------------------------------------------------------
inline const Sizef &UIBagFrame::GetSize () const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float UIBagFrame::GetCornorWidth () const
{
	return mCornorSize.Width;
}
//----------------------------------------------------------------------------
inline float UIBagFrame::GetCornorHeight () const
{
	return mCornorSize.Height;
}
//----------------------------------------------------------------------------
inline const Sizef &UIBagFrame::GetCornorSize () const
{
	return mCornorSize;
}
//----------------------------------------------------------------------------
inline float UIBagFrame::GetAlignItemWidth () const
{
	return mItemSize.Width;
}
//----------------------------------------------------------------------------
inline float UIBagFrame::GetAlignItemHeight () const
{
	return mItemSize.Height;
}
//----------------------------------------------------------------------------
inline const Sizef &UIBagFrame::GetAlignItemSize () const
{
	return mItemSize;
}
//----------------------------------------------------------------------------
inline UIBagFrame::AlignItemType UIBagFrame::GetAlignItemType () const
{
	return mAlignItemType;
}
//----------------------------------------------------------------------------
inline float UIBagFrame::GetAlignItemNumWidth () const
{
	return mAlignItemNum[0];
}
//----------------------------------------------------------------------------
inline float UIBagFrame::GetAlignItemNumHeight () const
{
	return mAlignItemNum[1];
}
//----------------------------------------------------------------------------
inline const Float2 &UIBagFrame::GetAlignItemNum () const
{
	return mAlignItemNum;
}
//----------------------------------------------------------------------------
inline void UIBagFrame::SetScrollBack (UIPicBox *scrollBack)
{
	mScrollBack = scrollBack;
}
//----------------------------------------------------------------------------
inline UIPicBox *UIBagFrame::GetScrollBack ()
{
	return mScrollBack;
}
//----------------------------------------------------------------------------
inline void UIBagFrame::SetScrollFront (UIPicBox *scrollFront)
{
	mScrollFront = scrollFront;
}
//----------------------------------------------------------------------------
inline UIPicBox *UIBagFrame::GetScrollFront ()
{
	return mScrollFront;
}
//----------------------------------------------------------------------------
inline void UIBagFrame::SetScrollXDetail (float xDetail)
{
	mXDetail = xDetail;
}
//----------------------------------------------------------------------------
inline float UIBagFrame::GetScrollXDetail () const
{
	return mXDetail;
}
//----------------------------------------------------------------------------