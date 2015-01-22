/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Surface.hpp
*
* 版本		:	1.0 (2011/09/19)
*
* 作者		：	more
*
*/

#ifndef PX2SURFACE_HPP
#define PX2SURFACE_HPP

#include "PX2MathematicsPre.hpp"

namespace PX2
{

	template <typename Real>
	class Surface
	{
	public:
		virtual ~Surface ();

	protected:
		Surface ();
	};

	typedef Surface<float> Surfacef;
	typedef Surface<double> Surfaced;

}

#endif