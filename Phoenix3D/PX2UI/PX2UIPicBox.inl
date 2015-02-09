/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIPicBox.inl
*
*/

//----------------------------------------------------------------------------
inline UIPicBox::PicBoxType UIPicBox::GetPicBoxType()
{
	return mPicBoxType;
}
//----------------------------------------------------------------------------
inline const Float2 &UIPicBox::GetAnchorPoint() const
{
	return mAnchorPoint;
}
//----------------------------------------------------------------------------
inline Float2 &UIPicBox::GetAnchorPoint()
{
	return mAnchorPoint;
}
//----------------------------------------------------------------------------
inline const Sizef &UIPicBox::GetSize() const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetWidth() const
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetHeight() const
{
	return mSize.Height;
}
//----------------------------------------------------------------------------
inline UIPicBox::TexMode UIPicBox::GetTexMode() const
{
	return mTexMode;
}
//----------------------------------------------------------------------------
inline const std::string &UIPicBox::GetTextureFilename() const
{
	return mTexturePackName;
}
//----------------------------------------------------------------------------
inline const Sizef &UIPicBox::GetTexCornerSize() const
{
	return mCornerSize;
}
//----------------------------------------------------------------------------
inline Sizef &UIPicBox::GetTexCornerSize()
{
	return mCornerSize;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetTexCornerWidth() const
{
	return mCornerSize.Width;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetTexCornerHeight() const
{
	return mCornerSize.Height;
}
//----------------------------------------------------------------------------