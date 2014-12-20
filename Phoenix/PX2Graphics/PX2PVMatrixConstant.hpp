/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2PVMatrixConstant.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2PVMATRIXCONSTANT_HPP
#define PX2PVMATRIXCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"

namespace PX2
{

	class PVMatrixConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(PVMatrixConstant);

	public:
		PVMatrixConstant ();
		virtual ~PVMatrixConstant ();

		virtual void Update (const Renderable* renderable, const Camera* camera);
	};

	PX2_REGISTER_STREAM(PVMatrixConstant);
	typedef Pointer0<PVMatrixConstant> PVMatrixConstantPtr;

}

#endif
