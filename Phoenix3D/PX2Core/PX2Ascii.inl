/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Ascii.inl
*
*/

//----------------------------------------------------------------------------
inline int Ascii::Properties(int ch)
{
	if (IsAscii(ch)) 
		return CHARACTER_PROPERTIES[ch];
	else
		return 0;
}
//----------------------------------------------------------------------------
inline bool Ascii::IsAscii(int ch)
{
	return (static_cast<int32_t>(ch) & 0xFFFFFF80) == 0;
}
//----------------------------------------------------------------------------
inline bool Ascii::HasProperties(int ch, int props)
{
	return (Properties(ch) & props) == props;
}
//----------------------------------------------------------------------------
inline bool Ascii::HasSomeProperties(int ch, int props)
{
	return (Properties(ch) & props) != 0;
}
//----------------------------------------------------------------------------
inline bool Ascii::IsSpace(int ch)
{
	return HasProperties(ch, ACP_SPACE);
}
//----------------------------------------------------------------------------
inline bool Ascii::IsDigit(int ch)
{
	return HasProperties(ch, ACP_DIGIT);
}
//----------------------------------------------------------------------------
inline bool Ascii::IsHexDigit(int ch)
{
	return HasProperties(ch, ACP_HEXDIGIT);
}
//----------------------------------------------------------------------------
inline bool Ascii::IsPunct(int ch)
{
	return HasProperties(ch, ACP_PUNCT);
}
//----------------------------------------------------------------------------
inline bool Ascii::IsAlpha(int ch)
{
	return HasProperties(ch, ACP_ALPHA);
}
//----------------------------------------------------------------------------
inline bool Ascii::IsAlphaNumeric(int ch)
{
	return HasSomeProperties(ch, ACP_ALPHA | ACP_DIGIT);
}
//----------------------------------------------------------------------------
inline bool Ascii::IsLower(int ch)
{
	return HasProperties(ch, ACP_LOWER);
}
//----------------------------------------------------------------------------
inline bool Ascii::IsUpper(int ch)
{
	return HasProperties(ch, ACP_UPPER);
}
//----------------------------------------------------------------------------
inline int Ascii::ToLower(int ch)
{
	if (IsUpper(ch))
		return ch + 32;
	else
		return ch;
}
//----------------------------------------------------------------------------
inline int Ascii::ToUpper(int ch)
{
	if (IsLower(ch))
		return ch - 32;
	else
		return ch;
}
//----------------------------------------------------------------------------