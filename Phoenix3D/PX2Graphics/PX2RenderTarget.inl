// PX2RenderTarget.inl

//----------------------------------------------------------------------------
inline int RenderTarget::GetNumTargets () const
{
	return mNumTargets;
}
//----------------------------------------------------------------------------
inline Texture::Format RenderTarget::GetFormat () const
{
	return mColorTextures[0]->GetFormat();
}
//----------------------------------------------------------------------------
inline int RenderTarget::GetWidth () const
{
	return mColorTextures[0]->GetWidth();
}
//----------------------------------------------------------------------------
inline int RenderTarget::GetHeight () const
{
	return mColorTextures[0]->GetHeight();
}
//----------------------------------------------------------------------------
inline Texture2D* RenderTarget::GetColorTexture (int i) const
{
	return mColorTextures[i];
}
//----------------------------------------------------------------------------
inline Texture2D* RenderTarget::GetDepthStencilTexture () const
{
	return mDepthStencilTexture;
}
//----------------------------------------------------------------------------
inline bool RenderTarget::HasMipmaps () const
{
	return mHasMipmaps;
}
//----------------------------------------------------------------------------
inline bool RenderTarget::HasDepthStencil () const
{
	return mDepthStencilTexture != 0;
}
//----------------------------------------------------------------------------