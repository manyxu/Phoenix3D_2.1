// PX2OpenGLES2RenderTarget.hpp

#ifdef PX2_USE_OPENGLES2

#ifndef PX2OPENGLES2RENDERTARGET_HPP
#define PX2OPENGLES2RENDERTARGET_HPP

#include "PX2OpenGLES2RendererPre.hpp"
#include "PX2RenderTarget.hpp"

namespace PX2
{

	class Renderer;

	class PdrRenderTarget
	{
	public:
		PdrRenderTarget (Renderer* renderer, const RenderTarget* renderTarget);
		~PdrRenderTarget ();

		// Render target ²Ù×÷
		void Enable (Renderer* renderer);
		void Disable (Renderer* renderer);
		void ReadColor (int i, Renderer* renderer, Texture2D*& texture);

	private:
		int mNumTargets, mWidth, mHeight;
		Texture::Format mFormat;
		bool mHasMipmaps, mHasDepthStencil;

		GLuint* mColorTextures;
		GLuint mDepthStencilTexture, mFrameBuffer;
		GLenum* mDrawBuffers;
		int mPrevViewport[4];
		float mPrevDepthRange[2];
	};

}

#endif

#endif