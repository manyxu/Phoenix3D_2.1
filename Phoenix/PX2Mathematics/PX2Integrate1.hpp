/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Integrate1.hpp
*
* 版本		:	1.0 (2011/10/12)
*
* 作者		：	more
*
*/

#ifndef PX2INTEGRATE1_HPP
#define PX2INTEGRATE1_HPP

#include "PX2MathematicsPre.hpp"

namespace PX2
{

	template <typename Real>
	class Integrate1
	{
	public:
		// The last parameter is for user-defined data.
		typedef Real (*Function)(Real,void*);

		static Real RombergIntegral (int order, Real a, Real b, Function function,
			void* userData = 0);

		static Real GaussianQuadrature (Real a, Real b, Function function,
			void* userData = 0);

		static Real TrapezoidRule (int numSamples, Real a, Real b,
			Function function, void* userData = 0);
	};

	typedef Integrate1<float> Integrate1f;
	typedef Integrate1<double> Integrate1d;

}

#endif