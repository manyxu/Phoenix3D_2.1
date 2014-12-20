/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputEventAdapter.inl
*
*/

//----------------------------------------------------------------------------
inline const Sizef &InputEventAdapter::GetSize () const
{
	return mSize;
}
//----------------------------------------------------------------------------
inline float InputEventAdapter::GetWidth ()
{
	return mSize.Width;
}
//----------------------------------------------------------------------------
inline float InputEventAdapter::GetHeight ()
{
	return mSize.Height;
}
//----------------------------------------------------------------------------
inline const Rectf &InputEventAdapter::GetRect () const
{
	return mRect;
}
//----------------------------------------------------------------------------
inline void InputEventAdapter::Convert2Touch (bool convert)
{
	mIsConverted2Touch = convert;
}
//----------------------------------------------------------------------------
inline bool InputEventAdapter::IsConverted2Touch ()
{
	return mIsConverted2Touch;
}
//----------------------------------------------------------------------------
inline InputManager *InputEventAdapter::GetInputManager ()
{
	return mInputManager;
}
//----------------------------------------------------------------------------
inline Keyboard *InputEventAdapter::GetKeyboard ()
{
	return mKeyboard;
}
//----------------------------------------------------------------------------
inline Mouse *InputEventAdapter::GetMouse ()
{
	return mMouse;
}
//----------------------------------------------------------------------------
inline InputEventListener *InputEventAdapter::GetInputEventListener ()
{
	return mEventListener;
}
//----------------------------------------------------------------------------