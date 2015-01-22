/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2CurveSegment.hpp
*
* 版本		:	1.0 (2011/02/02)
*
* 作者		：	more
*
*/

#ifndef PX2CURVESEGMENT_HPP
#define PX2CURVESEGMENT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Object.hpp"
#include "PX2APoint.hpp"

namespace PX2
{

	class CurveSegment : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(CurveSegment);

	protected:
		CurveSegment (float umin, float umax);
	public:
		virtual ~CurveSegment ();

		// The parametric domain is umin <= u <= umax.
		float GetUMin () const;
		float GetUMax () const;

		// Position and derivatives up to third order.
		virtual APoint P (float u) const = 0;
		virtual AVector PU (float u) const = 0;
		virtual AVector PUU (float u) const = 0;
		virtual AVector PUUU (float u) const = 0;

		// Differential geometric quantities.
		AVector Tangent (float u) const;
		AVector Normal (float u) const;
		AVector Binormal (float u) const;
		void GetFrame (float u, APoint& position, AVector& tangent,
			AVector& normal, AVector& binormal) const;
		float Curvature (float u) const;
		float Torsion (float u) const;

	protected:
		float mUMin, mUMax;
	};

	PX2_REGISTER_STREAM(CurveSegment);
	typedef Pointer0<CurveSegment> CurveSegmentPtr;

}

#endif