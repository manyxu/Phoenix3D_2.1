/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2WMatrixConstant.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2WIREPROPERTY_HPP
#define PX2WIREPROPERTY_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Object.hpp"

namespace PX2
{

	class WireProperty : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(WireProperty);

	public:
		WireProperty ();
		virtual ~WireProperty ();

		bool Enabled;  //< default: false
	};

	PX2_REGISTER_STREAM(WireProperty);
	typedef Pointer0<WireProperty> WirePropertyPtr;

}

#endif