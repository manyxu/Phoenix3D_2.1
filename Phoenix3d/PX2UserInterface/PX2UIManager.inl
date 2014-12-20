/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIManager.inl
*
*/

//----------------------------------------------------------------------------
inline VertexFormat *UIManager::GetVertexFormat ()
{
	return mVertexFormat;
}
//----------------------------------------------------------------------------
inline VertexFormat *UIManager::GetVertexFormatUV3 ()
{
	return mVertexFormatUV3;
}
//----------------------------------------------------------------------------
inline UIMaterial *UIManager::GetUIMaterial ()
{
	return mUIMaterial;
}
//----------------------------------------------------------------------------
inline UIMaterial *UIManager::GetUIMaterialDoubleSide ()
{
	return mUIMaterialDoubleSide;
}
//----------------------------------------------------------------------------
inline UIView *UIManager::GetDefaultView ()
{
	return mDefaultView;
}
//----------------------------------------------------------------------------
inline std::map<std::string, UIViewPtr> &UIManager::GetUIViews ()
{
	return mUIViews;
}
//----------------------------------------------------------------------------
inline UIView *UIManager::GetUIView (std::string name)
{
	return mUIViews[name];
}
//----------------------------------------------------------------------------