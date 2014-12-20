/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2VertexColor4Material.hpp
*
* 版本		:	1.0 (2011/04/05)
*
* 作者		：	more
*
*/

#ifndef PX2VERTEXCOLOR4MATERIAL_HPP
#define PX2VERTEXCOLOR4MATERIAL_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2MaterialInstance.hpp"

namespace PX2
{

	class VertexColor4Material : public Material
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(VertexColor4Material);

	public:
		VertexColor4Material ();
		virtual ~VertexColor4Material ();

		MaterialInstance* CreateInstance () const;

		static MaterialInstance* CreateUniqueInstance ();

	private:
		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int msOpenGLES2VRegisters[1];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
		static std::string msPPrograms[Shader::MAX_PROFILES];
	};

	PX2_REGISTER_STREAM(VertexColor4Material);
	typedef Pointer0<VertexColor4Material> VertexColor4MaterialPtr;

}

#endif