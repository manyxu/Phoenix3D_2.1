/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2CameraWorldDVectorConstant.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2CAMERAMODELPOSITIONCONSTANT_HPP
#define PX2CAMERAMODELPOSITIONCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"

namespace PX2
{

	class CameraModelPositionConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(CameraModelPositionConstant);

	public:
		CameraModelPositionConstant ();
		virtual ~CameraModelPositionConstant ();

		virtual void Update (const Renderable* renderable, const Camera* camera);
	};

	PX2_REGISTER_STREAM(CameraModelPositionConstant);
	typedef Pointer0<CameraModelPositionConstant> CameraModelPositionConstantPtr;

}

#endif
