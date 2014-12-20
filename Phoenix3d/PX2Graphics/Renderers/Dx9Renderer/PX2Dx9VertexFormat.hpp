/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Dx9VertexFormat.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2DX9VERTEXFORMAT_HPP
#define PX2DX9VERTEXFORMAT_HPP

#include "PX2Dx9RendererPre.hpp"
#include "PX2VertexFormat.hpp"

namespace PX2
{

	class Renderer;

	class PdrVertexFormat
	{
	public:
		PdrVertexFormat (Renderer* renderer, const VertexFormat* vformat);
		~PdrVertexFormat ();

		void Enable (Renderer* renderer);
		void Disable (Renderer* renderer);

	private:
		D3DVERTEXELEMENT9 mElements[VertexFormat::AM_MAX_ATTRIBUTES + 1];
		IDirect3DVertexDeclaration9* mDeclaration;
	};

}

#endif
