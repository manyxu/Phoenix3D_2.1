/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2OpenGLES2RenderTarget.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

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

		// Render target 操作
		void Enable (Renderer* renderer);
		void Disable (Renderer* renderer);
		void ReadColor (int i, Renderer* renderer, Texture2D*& texture);

	private:
		// 支持多个render target
		int mNumTargets;
		unsigned int mWidth, mHeight;
		Texture::Format mFormat;
		bool mHasDepthStencil;
	};

}

#endif
