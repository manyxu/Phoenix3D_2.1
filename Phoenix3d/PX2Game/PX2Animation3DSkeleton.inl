/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Animation3DSkeleton.inl
*
*/

//----------------------------------------------------------------------------
inline const std::string &Animation3DSkeleton::GetTagName () const
{
	return mTagName;
}
//----------------------------------------------------------------------------
inline Node *Animation3DSkeleton::GetAnimNode ()
{
	return mAnimNode;
}
//----------------------------------------------------------------------------
inline std::map<FString, KeyframeControllerPtr> &Animation3DSkeleton::GetKeyframeCtrlMap ()
{
	return mKeyframeCtrlMap;
}
//----------------------------------------------------------------------------