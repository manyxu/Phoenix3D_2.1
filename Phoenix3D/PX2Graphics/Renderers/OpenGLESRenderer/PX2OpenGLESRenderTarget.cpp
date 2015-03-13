// PX2Dx9RenderTarget.cpp

#ifdef PX2_USE_OPENGLES

#include "PX2OpenGLESRenderTarget.hpp"
#include "PX2OpenGLESMapping.hpp"
#include "PX2OpenGLESTexture2D.hpp"
#include "PX2Assert.hpp"
#include "PX2Renderer.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
PdrRenderTarget::PdrRenderTarget (Renderer* renderer,
	const RenderTarget* renderTarget)
{
	PX2_UNUSED(renderer);
	PX2_UNUSED(renderTarget);

#ifdef PX2_USE_OPENGLES3

	mNumTargets = renderTarget->GetNumTargets();
	assertion(mNumTargets >= 1,
		"Number of render targets must be at least one.\n");

	mWidth = renderTarget->GetWidth();
	mHeight = renderTarget->GetHeight();
	mFormat = renderTarget->GetFormat();
	mHasMipmaps = renderTarget->HasMipmaps();
	mHasDepthStencil = renderTarget->HasDepthStencil();

	mPrevViewport[0] = 0;
	mPrevViewport[1] = 0;
	mPrevViewport[2] = 0;
	mPrevViewport[3] = 0;
	mPrevDepthRange[0] = 0.0;
	mPrevDepthRange[1] = 0.0;

	// Create a framebuffer object.
	glGenFramebuffers(1, &mFrameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, mFrameBuffer);

	GLuint previousBind = GetBoundTexture(Shader::ST_2D);

	mColorTextures = new1<GLuint>(mNumTargets);
	mDrawBuffers = new1<GLenum>(mNumTargets);
	for (int i = 0; i < mNumTargets; ++i)
	{
		Texture2D* colorTexture = renderTarget->GetColorTexture(i);
		assertion(!renderer->InTexture2DMap(colorTexture),
			"Texture should not yet exist.\n");

		PdrTexture2D* ogColorTexture = new0 PdrTexture2D(renderer, colorTexture);
		renderer->InsertInTexture2DMap(colorTexture, ogColorTexture);
		mColorTextures[i] = ogColorTexture->GetTexture();
		mDrawBuffers[i] = GL_COLOR_ATTACHMENT0 + i;

		// Bind the color texture.
		glBindTexture(GL_TEXTURE_2D, mColorTextures[i]);
		if (mHasMipmaps)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
				GL_LINEAR_MIPMAP_LINEAR);
		}
		else
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		}

		// Attach the texture to the framebuffer.
		glFramebufferTexture2D(GL_FRAMEBUFFER, mDrawBuffers[i],
			GL_TEXTURE_2D, mColorTextures[i], 0);
	}

	Texture2D* depthStencilTexture = renderTarget->GetDepthStencilTexture();
	if (depthStencilTexture)
	{
		assertion(!renderer->InTexture2DMap(depthStencilTexture),
			"Texture should not yet exist.\n");

		PdrTexture2D* ogDepthStencilTexture = new0 PdrTexture2D(renderer,
			depthStencilTexture);
		renderer->InsertInTexture2DMap(depthStencilTexture,
			ogDepthStencilTexture);
		mDepthStencilTexture = ogDepthStencilTexture->GetTexture();

		// Bind the depthstencil texture.
		glBindTexture(GL_TEXTURE_2D, mDepthStencilTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		// Attach the depth to the framebuffer.
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
			GL_TEXTURE_2D, mDepthStencilTexture, 0);

		// Attach the stencil to the framebuffer.
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, 
			GL_TEXTURE_2D, mDepthStencilTexture, 0);
	}

	glBindTexture(GL_TEXTURE_2D, previousBind);

#endif
}
//----------------------------------------------------------------------------
PdrRenderTarget::~PdrRenderTarget ()
{
#ifdef PX2_USE_OPENGLES3

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDeleteFramebuffers(1, &mFrameBuffer);
	delete1(mColorTextures);
	delete1(mDrawBuffers);

#endif
}
//----------------------------------------------------------------------------
void PdrRenderTarget::Enable (Renderer* renderer)
{
	PX2_UNUSED(renderer);

#ifdef PX2_USE_OPENGLES3

	glBindFramebuffer(GL_FRAMEBUFFER, mFrameBuffer);
	glDrawBuffers(mNumTargets, mDrawBuffers);

	glGetIntegerv(GL_VIEWPORT, mPrevViewport);
	glGetFloatv(GL_DEPTH_RANGE, mPrevDepthRange);
	glViewport(0, 0, mWidth, mHeight);
	glDepthRangef(0.0, 1.0);

#endif
}
//----------------------------------------------------------------------------
void PdrRenderTarget::Disable (Renderer* renderer)
{
	PX2_UNUSED(renderer);

#ifdef PX2_USE_OPENGLES3

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	if (mHasMipmaps)
	{
		GLuint previousBind = GetBoundTexture(Shader::ST_2D);
		for (int i = 0; i < mNumTargets; ++i)
		{
			glBindTexture(GL_TEXTURE_2D, mColorTextures[i]);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		glBindTexture(GL_TEXTURE_2D, previousBind);
	}

	glViewport(mPrevViewport[0], mPrevViewport[1], mPrevViewport[2],
		mPrevViewport[3]);
	glDepthRangef(mPrevDepthRange[0], mPrevDepthRange[1]);

#endif
}
//----------------------------------------------------------------------------
void PdrRenderTarget::ReadColor (int i, Renderer* renderer,
	Texture2D*& texture)
{
	PX2_UNUSED(i);
	PX2_UNUSED(renderer);
	PX2_UNUSED(texture);

#ifdef PX2_USE_OPENGLES3

	if (i < 0 || i >= mNumTargets)
	{
		assertion(false, "Invalid target index.\n");
	}

	Enable(renderer);

	if (texture)
	{
		if (texture->GetFormat() != mFormat ||
			texture->GetWidth() != mWidth ||
			texture->GetHeight() != mHeight)
		{
			assertion(false, "Incompatible texture.\n");
			delete0(texture);
			texture = new0 Texture2D(mFormat, mWidth, mHeight, 1);
		}
	}
	else
	{
		texture = new0 Texture2D(mFormat, mWidth, mHeight, 1);
	}

	glReadBuffer(GL_COLOR_ATTACHMENT0 + i);

	glReadPixels(
		0,
		0,
		mWidth,
		mHeight,
		gOGLTextureFormat[mFormat],
		gOGLTextureType[mFormat],
		texture->GetData(0)
		);

	Disable(renderer);

#endif

}
//----------------------------------------------------------------------------

#endif