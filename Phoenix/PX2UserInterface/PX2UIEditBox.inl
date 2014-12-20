/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIEditBox.inl
*
*/

//----------------------------------------------------------------------------
inline UIPicBox *UIEditBox::GetBackPicBox () const
{
	return mBackPicBox;
}
//----------------------------------------------------------------------------
inline UIPicBox *UIEditBox::GetFadePicBox () const
{
	return mFadePicBox;
}
//----------------------------------------------------------------------------
inline float UIEditBox::GetWidth () const
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float UIEditBox::GetHeight () const
{
	return mSize.Height;
}
//----------------------------------------------------------------------------
inline const Sizef &UIEditBox::GetSize () const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float UIEditBox::GetFixedWidth () const
{
	return mFixedWidth;
}
//----------------------------------------------------------------------------