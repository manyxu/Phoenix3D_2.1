/*
*
* ÎÄ¼şÃû³Æ	£º	PX2Win32InputManager.inl
*
*/

//----------------------------------------------------------------------------
inline void Win32InputManager::SetKeyboardUsed (bool used)
{
	mIsKeyboardUsed = used;
}
//----------------------------------------------------------------------------
inline void Win32InputManager::SetMouseUsed (bool used)
{
	mIsMouseUsed = used;
}
//----------------------------------------------------------------------------
inline HWND Win32InputManager::GetWindowHandle ()
{
	return mhWnd;
}
//----------------------------------------------------------------------------