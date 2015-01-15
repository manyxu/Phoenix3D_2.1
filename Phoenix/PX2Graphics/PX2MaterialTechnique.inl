/*
*
* ÎÄ¼şÃû³Æ	£º	PX2MaterialTechnique.inl
*
*/

//----------------------------------------------------------------------------
inline void MaterialTechnique::SetTag(const std::string &tag)
{
	mTag = tag;
}
//----------------------------------------------------------------------------
inline const std::string &MaterialTechnique::GetTag() const
{
	return mTag;
}
//----------------------------------------------------------------------------
inline int MaterialTechnique::GetNumPasses () const
{
    return (int)mPasses.size();
}
//----------------------------------------------------------------------------