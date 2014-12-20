/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Dx9PixelShader.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2DX9PIXELSHADER_HPP
#define PX2DX9PIXELSHADER_HPP

#include "PX2Dx9RendererPre.hpp"
#include "PX2Dx9Shader.hpp"
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

	private:
		IDirect3DPixelShader9* mShader;
	};

}

#endif
