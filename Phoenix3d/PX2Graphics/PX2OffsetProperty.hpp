/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2OffsetProperty.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2OFFSETPROPERTY_HPP
#define PX2OFFSETPROPERTY_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Object.hpp"

namespace PX2
{

	class OffsetProperty : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(OffsetProperty);

	public:
		OffsetProperty ();
		virtual ~OffsetProperty ();

		// Set whether offset should be enabled for the various polygon drawing
		// modes (fill, line, point).
		bool FillEnabled;   // default: false
		bool LineEnabled;   // default: false
		bool PointEnabled;  // default: false

		// The offset is Scale*dZ + Bias*r where dZ is the change in depth
		// relative to the screen space area of the poly, and r is the smallest
		// resolvable depth difference.  Negative values move polygons closer to
		// the eye.
		float Scale;  // default: 0
		float Bias;   // default: 0
	};

	PX2_REGISTER_STREAM(OffsetProperty);
	typedef Pointer0<OffsetProperty> OffsetPropertyPtr;

}

#endif
