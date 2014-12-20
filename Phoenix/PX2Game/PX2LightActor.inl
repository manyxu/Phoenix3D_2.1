/*
*
* ÎÄ¼þÃû³Æ	£º	PX2LightActor.inl
*
*/

//----------------------------------------------------------------------------
inline Light *LightActor::GetLight ()
{
	return mLight;
}
//----------------------------------------------------------------------------
inline LightActor::LightType LightActor::GetLightType () const
{
	return mLightType;
}
//----------------------------------------------------------------------------
inline const Float3 &LightActor::GetColor () const
{
	return mColor;
}
//----------------------------------------------------------------------------
inline float LightActor::GetRange () const
{
	return mRange;
}
//----------------------------------------------------------------------------