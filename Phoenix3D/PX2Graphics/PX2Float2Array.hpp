/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Float2Array.hpp
*
* 版本		:	1.0 (2011/02/02)
*
* 作者		：	more
*
*/

#ifndef PX2FLOAT2ARRAY_H
#define PX2FLOAT2ARRAY_H

#include "PX2GraphicsPre.hpp"
#include "PX2Object.hpp"
#include "PX2Float2.hpp"

namespace PX2
{

	class Float2Array : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(Float2Array);

	public:
		Float2Array (int numElements = 0, Float2* elements = 0);
		virtual ~Float2Array ();

		// 成员访问
		inline int GetNumElements () const;
		inline Float2* GetData () const;
		inline operator const Float2* () const;
		inline operator Float2* ();
		inline const Float2& operator[] (int i) const;
		inline Float2& operator[] (int i);

	protected:
		int mNumElements;
		Float2* mElements;
	};

	PX2_REGISTER_STREAM(Float2Array);
	typedef Pointer0<Float2Array> Float2ArrayPtr;
#include "PX2Float2Array.inl"

}

#endif
