// PX2OpenGLES2Texture1D.hpp

#ifdef PX2_USE_OPENGLES2

#ifndef PX2OPENGLES2TEXTURE1D_HPP
#define PX2OPENGLES2TEXTURE1D_HPP

#include "PX2OpenGLES2RendererPre.hpp"
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
	};

}

#endif

#endif