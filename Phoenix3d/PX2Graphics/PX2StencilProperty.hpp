/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2StencilProperty.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2STENCILSTATE_HPP
#define PX2STENCILSTATE_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Object.hpp"

namespace PX2
{

	class StencilProperty : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(StencilProperty);

	public:
		StencilProperty ();
		virtual ~StencilProperty ();

		enum CompareMode
		{
			CM_NEVER,
			CM_LESS,
			CM_EQUAL,
			CM_LEQUAL,
			CM_GREATER,
			CM_NOTEQUAL,
			CM_GEQUAL,
			CM_ALWAYS,
			CM_QUANTITY
		};

		enum OperationType
		{
			OT_KEEP,
			OT_ZERO,
			OT_REPLACE,
			OT_INCREMENT,
			OT_DECREMENT,
			OT_INVERT,
			OT_QUANTITY
		};

		bool Enabled;            //< default: false
		CompareMode Compare;     //< default: CM_NEVER
		unsigned int Reference;  //< default: 0
		unsigned int Mask;       //< default: UINT_MAX (0xFFFFFFFF)
		unsigned int WriteMask;  //< default: UINT_MAX (0xFFFFFFFF)
		OperationType OnFail;    //< default: OT_KEEP
		OperationType OnZFail;   //< default: OT_KEEP
		OperationType OnZPass;   //< default: OT_KEEP
	};

	PX2_REGISTER_STREAM(StencilProperty);
	typedef Pointer0<StencilProperty> StencilPropertyPtr;

}

#endif