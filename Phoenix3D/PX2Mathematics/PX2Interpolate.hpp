/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Interpolate.hpp
*
* 版本		:	1.0 (2011/04/15)
*s
* 作者		：	more
*
*/

#ifndef PX2INTERPOLATE_HPP
#define PX2INTERPOLATE_HPP

#include "PX2MathematicsPre.hpp"
#include "PX2Float4.hpp"

namespace PX2
{

	class Interpolate
	{
	public:
		Interpolate ();
		~Interpolate ();

		static float LinearFloat (float &v0, float &v1, float t);
		static Float4 LinearFloat4 (Float4 &v0, Float4 &v1, float t);

	};
}

#endif