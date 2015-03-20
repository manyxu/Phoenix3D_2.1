// PX2LightActor.inl

//----------------------------------------------------------------------------
inline Light *LightActor::GetLight()
{
	return mLight;
}
//----------------------------------------------------------------------------
inline LightNode *LightActor::GetLightNode()
{
	return mLightNode;
}
//----------------------------------------------------------------------------
inline LightActor::LightType LightActor::GetLightType() const
{
	return mLightType;
}
//----------------------------------------------------------------------------
inline bool LightActor::IsBake_CalShadow() const
{
	return mIsBakeCastShadow;
}
//----------------------------------------------------------------------------