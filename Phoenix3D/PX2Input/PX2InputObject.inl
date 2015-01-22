/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputObject.inl
*
*/

//----------------------------------------------------------------------------
inline const std::string &InputObject::GetVendor() const
{
	return mVendor;
}
//----------------------------------------------------------------------------
inline int InputObject::GetDevID () const
{
	return mDevID;
}
//----------------------------------------------------------------------------
inline InputType InputObject::GetInputType ()
{
	return mInputType;
}
//----------------------------------------------------------------------------
inline InputManager *InputObject::GetCreator () const
{
	return mCreator;
}
//----------------------------------------------------------------------------
inline bool InputObject::IsBuffered () const
{
	return mIsBuffered;
}
//----------------------------------------------------------------------------