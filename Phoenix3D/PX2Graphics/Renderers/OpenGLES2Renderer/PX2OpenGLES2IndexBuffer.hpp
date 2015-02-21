// PX2OpenGLES2IndexBuffer.hpp

#ifdef PX2_USE_OPENGLES2

#ifndef PX2OPENGLES2INDEXBUFFER_HPP
#define PX2OPENGLES2INDEXBUFFER_HPP

#include "PX2OpenGLES2RendererPre.hpp"
#include "PX2IndexBuffer.hpp"

namespace PX2
{

	class Renderer;

	class PdrIndexBuffer
	{
	public:
		PdrIndexBuffer (Renderer* renderer, const IndexBuffer* ibuffer);
		~PdrIndexBuffer ();

		void Enable (Renderer* renderer);
		void Disable (Renderer* renderer);
		void* Lock (Buffer::Locking mode);
		void Unlock ();

	private:
		GLuint mBuffer;
		const IndexBuffer *mIBuffer;
	};

}

#endif

#endif