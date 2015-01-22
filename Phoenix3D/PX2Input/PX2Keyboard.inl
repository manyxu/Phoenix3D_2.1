/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Keyboard.inl
*
*/

//----------------------------------------------------------------------------
inline void Keyboard::SetTextTranslation (TextTranslationMode mode)
{
	mTextMode = mode;
}
//----------------------------------------------------------------------------
inline Keyboard::TextTranslationMode Keyboard::GetTextTranslation() const
{
	return mTextMode;
}
//----------------------------------------------------------------------------
inline void Keyboard::SetEventCallback(KeyListener *keyListener) 
{
	mListener = keyListener;
}
//----------------------------------------------------------------------------
inline KeyListener* Keyboard::GetEventCallback() const
{
	return mListener;
}
//----------------------------------------------------------------------------