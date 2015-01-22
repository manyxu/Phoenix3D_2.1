/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2CameraModelDVectorConstant.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2CAMERAMODELDVECTORCONSTANT_HPP
#define PX2CAMERAMODELDVECTORCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"

namespace PX2
{

	class CameraModelDVectorConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(CameraModelDVectorConstant);

	public:
		CameraModelDVectorConstant ();
		virtual ~CameraModelDVectorConstant ();

		virtual void Update (const Renderable* renderable, const Camera* camera);
	};

	PX2_REGISTER_STREAM(CameraModelDVectorConstant);
	typedef Pointer0<CameraModelDVectorConstant> CameraModelDVectorConstantPtr;

}

#endif
