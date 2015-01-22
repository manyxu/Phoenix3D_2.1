/*
*
* ÎÄ¼şÃû³Æ	£º	PX2MaterialInstance.inl
*
*/

//----------------------------------------------------------------------------
inline Material* MaterialInstance::GetMaterial () const
{
	return mMaterial;
}
//----------------------------------------------------------------------------
inline int MaterialInstance::GetTechniqueIndex () const
{
	return mTechniqueIndex;
}
//----------------------------------------------------------------------------
inline int MaterialInstance::GetNumPasses () const
{
	return mMaterial->GetTechnique(mTechniqueIndex)->GetNumPasses();
}
//----------------------------------------------------------------------------
