/*
* Turandot 3D 游戏引擎 Version 1.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	TdOpenGLES2Shader.hpp
*
* 版本		:	1.0 (2011/07/12)
*
* 作者		：	许多
*
*/

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
