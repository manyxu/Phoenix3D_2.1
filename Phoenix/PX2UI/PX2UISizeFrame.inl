// PX2UISizeFrame.inl

//----------------------------------------------------------------------------
inline const Sizef &UISizeFrame::GetSize() const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float UISizeFrame::GetWidth() const
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float UISizeFrame::GetHeight() const
{
	return mSize.Height;
}
//----------------------------------------------------------------------------
inline const Sizef &UISizeFrame::GetBorderSize() const
{
	return mBorderSize;
}
//----------------------------------------------------------------------------
inline UISizeFrame::RelativeType UISizeFrame::GetRelativeType_H() const
{
	return mPosRelativeType_H;
}
//----------------------------------------------------------------------------
inline UISizeFrame::RelativeType UISizeFrame::GetRelativeType_V() const
{
	return mPosRelativeType_V;
}
//----------------------------------------------------------------------------
inline float UISizeFrame::GetRelativeValue_H() const
{
	return mRelativeVal_H;
}
//----------------------------------------------------------------------------
inline float UISizeFrame::GetRelativeValue_V() const
{
	return mRelativeVal_V;
}
//----------------------------------------------------------------------------
inline UISizeFrame::SizeRelativeType UISizeFrame::GetSizeRelativeType() const
{
	return mSizeRelativeType;
}
//----------------------------------------------------------------------------