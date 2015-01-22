/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2TextureCube.hpp
*
* 版本		:	1.0 (2011/01/31)
*
* 作者		：	more
*
*/

#ifndef PX2TEXTURECUBE_HPP
#define PX2TEXTURECUBE_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Texture.hpp"

namespace PX2
{
	
	/// 立方体纹理类
	class TextureCube : public Texture
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(TextureCube);

	public:
		// cube纹理每个面的维度必须一样，dimension-by-dimension。
		TextureCube (Format tformat, int dimension, int numLevels,
			Buffer::Usage usage = Buffer::BU_TEXTURE);

		virtual ~TextureCube ();

		// 获得第0级别mipmap的宽度和高度
		inline int GetWidth () const;
		inline int GetHeight () const;

		// mipmap生成支持
		void GenerateMipmaps ();
		bool HasMipmaps () const;

		// 注意：Texture::GetNumLevelBytes(level)返回*one* face，level级别的字节数，
		// Texture::GetNumTotalBytes()返回*all* faces，all levels字节数量。

		/// 访问纹理数据
		char* GetData (int face, int level) const;

	protected:
		// mipmap的生成支持
		void ComputeNumLevelBytes ();
		void GenerateNextMipmap (int dimension, const char* texels,
			int dimensionNext, char* texelsNext, Float4* rgba);

		// Begin TextureCube加载
	public:
		static TextureCube* LoadPXtf (const std::string& name,
			int mode = FileIO::FM_DEFAULT_READ);
		// End TextureCube加载
	};

	PX2_REGISTER_STREAM(TextureCube);
	typedef Pointer0<TextureCube> TextureCubePtr;
#include "PX2TextureCube.inl"

}

#endif