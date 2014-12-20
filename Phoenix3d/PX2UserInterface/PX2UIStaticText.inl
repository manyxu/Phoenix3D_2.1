/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIStaticText.inl
*
*/

//----------------------------------------------------------------------------
inline UIStaticText::FontType UIStaticText::GetFontType () const
{
	return mFontType;
}
//----------------------------------------------------------------------------
inline Font *UIStaticText::GetFont ()
{
	return mFont;
}
//----------------------------------------------------------------------------
inline const std::string &UIStaticText::GetText () const
{
	return mText;
}
//----------------------------------------------------------------------------
inline const std::string &UIStaticText::GetKey () const
{
	return mKey;
}
//----------------------------------------------------------------------------
inline int UIStaticText::GetFontStyle () const
{
	return mFontStyle;
}
//----------------------------------------------------------------------------
inline bool UIStaticText::IsItalic () const
{
	return 0!=(mFontStyle&FES_ITALIC);
}
//----------------------------------------------------------------------------
inline bool UIStaticText::IsUnderLine () const
{
	return 0!=(mFontStyle&FES_UNDERLINE);
}
//----------------------------------------------------------------------------
inline int UIStaticText::GetDrawStyle () const
{
	return mDrawStyle;
}
//----------------------------------------------------------------------------
inline int UIStaticText::GetAligns () const
{
	return mTextAligns;
}
//----------------------------------------------------------------------------
inline const Float3 &UIStaticText::GetBorderShadowColor () const
{
	return mBorderShadowColor;
}
//----------------------------------------------------------------------------
inline float UIStaticText::GetShadowBorderSize () const
{
	return mShadowBorderSize;
}
//----------------------------------------------------------------------------
inline UIStaticText::RectUseage UIStaticText::GetRectUseage () const
{
	return mRectUseage;
}
//----------------------------------------------------------------------------
inline const Rectf &UIStaticText::GetRect () const
{
	return mRect;
}
//----------------------------------------------------------------------------
inline const Float2 &UIStaticText::GetOffset () const
{
	return mOffset;
}
//----------------------------------------------------------------------------
inline const Float2 &UIStaticText::GetSpace () const
{
	return mSpace;
}
//----------------------------------------------------------------------------
inline bool UIStaticText::IsAutoWarp () const
{
	return mIsAutoWarp;
}
//----------------------------------------------------------------------------
inline bool UIStaticText::IsDoCharTranslate () const
{
	return mIsDoCharTranslate;
}
//----------------------------------------------------------------------------
inline float UIStaticText::GetFontScale () const
{
	return mFontScale;
}
//----------------------------------------------------------------------------
inline int UIStaticText::GetFontWidth ()
{
	return mFontWidth;
}
//----------------------------------------------------------------------------
inline int UIStaticText::GetFontHeight ()
{
	return mFontHeight;
}
//----------------------------------------------------------------------------
inline bool UIStaticText::IsDoubleSide ()
{
	return mIsDoubleSide;
}
//----------------------------------------------------------------------------