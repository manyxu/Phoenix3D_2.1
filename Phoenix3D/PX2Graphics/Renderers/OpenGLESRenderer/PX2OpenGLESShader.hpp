// PX2OpenGLES2Shader.hpp

#ifdef PX2_USE_OPENGLES2

#ifndef PX2OPENGLES2SHADER_HPP
#define PX2OPENGLES2SHADER_HPP

#include "PX2OpenGLES2RendererPre.hpp"
#include "PX2OpenGLES2RendererData.hpp"
#include "PX2Shader.hpp"
#include "PX2ShaderParameters.hpp"

namespace PX2
{

	class Renderer;

	class PdrShader
	{
	public:
		PdrShader ();
		virtual ~PdrShader ();

		GLuint GetShader () { return mShader; }

	protected:
		void SetSamplerState (Renderer* renderer, const Shader* shader,
			int profile, const ShaderParameters* parameters, int maxSamplers,
			RendererData::SamplerState* currentSS);

		void DisableTextures (Renderer* renderer, const Shader* shader,
			int profile, const ShaderParameters* parameters, int maxSamplers);

		GLuint mShader;
	};

}

#endif

#endif