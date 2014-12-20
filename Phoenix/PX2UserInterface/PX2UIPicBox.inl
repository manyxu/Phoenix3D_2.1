/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIPicBox.inl
*
*/

//----------------------------------------------------------------------------
inline bool UIPicBox::IsDynamic () const
{
	return mIsDynamic;
}
//----------------------------------------------------------------------------
inline UIPicBox::PicBoxType UIPicBox::GetPicBoxType ()
{
	return mPicBoxType;
}
//----------------------------------------------------------------------------
inline const Float2 &UIPicBox::GetAnchorPoint () const
{
	return mAnchorPoint;
}
//----------------------------------------------------------------------------
inline Float2 &UIPicBox::GetAnchorPoint ()
{
	return mAnchorPoint;
}
//----------------------------------------------------------------------------
inline const Sizef &UIPicBox::GetSize () const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetWidth () const
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetHeight () const
{
	return mSize.Height;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetUVScaleX () const
{
	return mUVScale[0];
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetUVScaleY () const
{
	return mUVScale[1];
}
//----------------------------------------------------------------------------
inline const Float2 &UIPicBox::GetUVScale () const
{
	return mUVScale;
}
//----------------------------------------------------------------------------
inline Float2 &UIPicBox::GetUVScale ()
{
	return mUVScale;
}
//----------------------------------------------------------------------------
inline UIMaterial *UIPicBox::GetUIMaterial () const
{
	return mUIMtl;
}
//----------------------------------------------------------------------------
inline const std::string &UIPicBox::GetTextureFilename () const
{
	return mTexturePackName;
}
//----------------------------------------------------------------------------
inline const Sizef &UIPicBox::GetTexCornerSize () const
{
	return mCornerSize;
}
//----------------------------------------------------------------------------
inline Sizef &UIPicBox::GetTexCornerSize ()
{
	return mCornerSize;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetTexCornerWidth () const
{
	return mCornerSize.Width;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetTexCornerHeight () const
{
	return mCornerSize.Height;
}
//----------------------------------------------------------------------------
inline bool UIPicBox::IsUserDark () const
{
	return mIsUseDark;
}
//----------------------------------------------------------------------------
inline bool UIPicBox::IsUseAddedMask () const
{
	return mIsUseAddedMask;
}
//----------------------------------------------------------------------------
inline const std::string &UIPicBox::GetAddedTextureFilename () const
{
	return mAddedTextureFilename;
}
//----------------------------------------------------------------------------
inline const Float2 &UIPicBox::GetAddedTextureUVSpeed () const
{
	return mAddedTextureUVSpeed;
}
//----------------------------------------------------------------------------
inline const Float2 &UIPicBox::GetAddedTextureUVRepeat () const
{
	return mAddedTextureUVSRepeat;
}
//----------------------------------------------------------------------------
inline Float3 UIPicBox::GetAddedTextureColor () const
{
	Float3 color;

	color[0] = mAddedTextureColor[0];
	color[1] = mAddedTextureColor[1];
	color[2] = mAddedTextureColor[2];

	return color;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetAddedTextureAlpha () const
{
	return mAddedTextureColor[3];
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetAddedTextureAlphaSpeed () const
{
	return mAddedTextureAlphaSpeed;
}
//----------------------------------------------------------------------------
inline const std::string &UIPicBox::GetMaskTexture () const
{
	return mMaskTextureFilename;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetMaskTextureAlpha () const
{
	return mMaskTextureAlpha;
}
//----------------------------------------------------------------------------
inline float UIPicBox::GetMaskTextureAlphaSpeed () const
{
	return mMaskTextureAlphaSpeed;
}
//----------------------------------------------------------------------------