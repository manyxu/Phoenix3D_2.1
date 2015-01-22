/*
*
* ÎÄ¼şÃû³Æ	£º	PX2Jungler.inl
*
*/

//----------------------------------------------------------------------------
inline MaterialInstance *Jungler::GetMtlInst ()
{
	return mMtlInst;
}
//----------------------------------------------------------------------------
inline Texture2D *Jungler::GetTexture ()
{
	return mTexture;
}
//----------------------------------------------------------------------------
inline Shine *Jungler::GetShine()
{
	return mShine;
}
//----------------------------------------------------------------------------
inline int Jungler::GetNum ()
{
	return (int)mPoses.size();
}
//----------------------------------------------------------------------------
inline const APoint &Jungler::GetPos (int i)
{
	return mPoses[i];
}
//----------------------------------------------------------------------------