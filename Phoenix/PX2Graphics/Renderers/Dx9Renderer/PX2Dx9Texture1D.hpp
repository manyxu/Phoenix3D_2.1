/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Dx9Texture1D.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2DX9TEXTURE1D_HPP
#define PX2DX9TEXTURE1D_HPP

#include "PX2Dx9RendererPre.hpp"
#include "PX2Texture1D.hpp"

namespace PX2
{

	class Renderer;

	class PdrTexture1D
	{
	public:
		PdrTexture1D (Renderer* renderer, const Texture1D* texture);
		~PdrTexture1D ();

		void Enable (Renderer* renderer, int textureUnit);
		void Disable (Renderer* renderer, int textureUnit);
		void* Lock (int level, Buffer::Locking mode);
		void Unlock (int level);

	private:
		IDirect3DTexture9* mTexture;
	};

}

#endif
