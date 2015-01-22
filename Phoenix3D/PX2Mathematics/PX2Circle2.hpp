/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Circle2.hpp
*
* 版本		:	1.0 (2011/02/19)
*
* 作者		：	more
*
*/

#ifndef PX2CIRCLE2_HPP
#define PX2CIRCLE2_HPP

#include "PX2MathematicsPre.hpp"
#include "PX2Vector2.hpp"

namespace PX2
{

	template <typename Real>
	class Circle2
	{
	public:
		Circle2 ();  //< 未初始化
		~Circle2 ();

		Circle2 (const Vector2<Real>& center, Real radius);

		Vector2<Real> Center;
		Real Radius;
	};

#include "PX2Circle2.inl"

	typedef Circle2<float> Circle2f;
	typedef Circle2<double> Circle2d;

}

#endif