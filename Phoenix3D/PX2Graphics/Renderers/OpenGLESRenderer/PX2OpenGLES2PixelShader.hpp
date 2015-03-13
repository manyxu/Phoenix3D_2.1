// PX2OpenGLES2PixelShader.hpp

#ifdef PX2_USE_OPENGLES2

#ifndef PX2OPENGLES2PIXELSHADER_HPP
#define PX2OPENGLES2PIXELSHADER_HPP

#include "PX2OpenGLES2RendererPre.hpp"
#include "PX2OpenGLES2Shader.hpp"
#include "PX2PixelShader.hpp"

namespace PX2
{

	class Renderer;

	class PdrPixelShader : public PdrShader
	{
	public:
		PdrPixelShader (Renderer* renderer, const PixelShader* pshader);
		~PdrPixelShader ();

		void Enable (Renderer* renderer, const PixelShader* pshader,
			const ShaderParameters* parameters);
		void Disable (Renderer* renderer, const PixelShader* pshader,
			const ShaderParameters* parameters);
	};

}

#endif

#endif