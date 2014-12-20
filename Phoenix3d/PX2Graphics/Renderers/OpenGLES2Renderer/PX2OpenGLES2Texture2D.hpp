/*
* Turandot 3D 游戏引擎 Version 1.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	TdOpenGLES2Texture2D.hpp
*
* 版本		:	1.0 (2011/07/12)
*
* 作者		：	许多
*
*/

#ifndef PX2OPENGLES2TEXTURE2D_HPP
#define PX2OPENGLES2TEXTURE2D_HPP

#include "PX2OpenGLES2RendererPre.hpp"
#include "PX2Texture2D.hpp"

namespace PX2
{

	class Renderer;

	class PdrTexture2D
	{
	public:
		PdrTexture2D (Renderer* renderer, const Texture2D* texture);
		~PdrTexture2D ();

		inline GLuint GetTexture () { return mTexture; }

		void Enable (Renderer* renderer, int textureUnit);
		void Enable (Renderer* renderer, int textureUnit, int loc);
		void Disable (Renderer* renderer, int textureUnit);
		void* Lock (int level, Buffer::Locking mode);
		void Unlock (int level);

	private:
		const Texture2D *mTex;
		GLuint mTexture, mInternalFormat, mFormat, mType;
		GLint mNumLevels;
		GLint mNumLevelBytes[Texture::MM_MAX_MIPMAP_LEVELS];
		GLint mDimension[2][Texture::MM_MAX_MIPMAP_LEVELS];
		bool mIsCompressed;
	};

}

#endif