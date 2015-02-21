// PX2SpecializedIO.hpp

#ifndef PX2SPECIALIZEDIO_HPP
#define PX2SPECIALIZEDIO_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2InStream.hpp"
#include "PX2OutStream.hpp"
#include "PX2APoint.hpp"
#include "PX2AVector.hpp"
#include "PX2Bound.hpp"
#include "PX2Float1.hpp"
#include "PX2Float2.hpp"
#include "PX2Float3.hpp"
#include "PX2Float4.hpp"
#include "PX2HMatrix.hpp"
#include "PX2HPlane.hpp"
#include "PX2HQuaternion.hpp"
#include "PX2Transform.hpp"
#include "PX2Vector3.hpp"
#include "PX2Size.hpp"
#include "PX2Rect.hpp"
#include "PX2InterpCurve.hpp"

namespace PX2
{
	// Bound
	template <> bool InStream::ReadAggregate (Bound&);
	template <> bool InStream::ReadAggregateVV (int, Bound*);
	template <> bool InStream::ReadAggregateVR (int, Bound*&);
	template <> bool InStream::ReadAggregateRR (int&, Bound*&);
	template <> bool OutStream::WriteAggregate (const Bound&);
	template <> bool OutStream::WriteAggregateW (int, const Bound*);
	template <> bool OutStream::WriteAggregateN (int, const Bound*);

	// Float1
	template <> bool InStream::ReadAggregate (Float1&);
	template <> bool InStream::ReadAggregateVV (int, Float1*);
	template <> bool InStream::ReadAggregateVR (int, Float1*&);
	template <> bool InStream::ReadAggregateRR (int&, Float1*&);
	template <> bool OutStream::WriteAggregate (const Float1&);
	template <> bool OutStream::WriteAggregateW (int, const Float1*);
	template <> bool OutStream::WriteAggregateN (int, const Float1*);

	// Float2
	template <> bool InStream::ReadAggregate (Float2&);
	template <> bool InStream::ReadAggregateVV (int, Float2*);
	template <> bool InStream::ReadAggregateVR (int, Float2*&);
	template <> bool InStream::ReadAggregateRR (int&, Float2*&);
	template <> bool OutStream::WriteAggregate (const Float2&);
	template <> bool OutStream::WriteAggregateW (int, const Float2*);
	template <> bool OutStream::WriteAggregateN (int, const Float2*);

	// Float3
	template <> bool InStream::ReadAggregate (Float3&);
	template <> bool InStream::ReadAggregateVV (int, Float3*);
	template <> bool InStream::ReadAggregateVR (int, Float3*&);
	template <> bool InStream::ReadAggregateRR (int&, Float3*&);
	template <> bool OutStream::WriteAggregate (const Float3&);
	template <> bool OutStream::WriteAggregateW (int, const Float3*);
	template <> bool OutStream::WriteAggregateN (int, const Float3*);

	// Float4
	template <> bool InStream::ReadAggregate (Float4&);
	template <> bool InStream::ReadAggregateVV (int, Float4*);
	template <> bool InStream::ReadAggregateVR (int, Float4*&);
	template <> bool InStream::ReadAggregateRR (int&, Float4*&);
	template <> bool OutStream::WriteAggregate (const Float4&);
	template <> bool OutStream::WriteAggregateW (int, const Float4*);
	template <> bool OutStream::WriteAggregateN (int, const Float4*);

	// HMatrix
	template <> bool InStream::ReadAggregate (HMatrix&);
	template <> bool InStream::ReadAggregateVV (int, HMatrix*);
	template <> bool InStream::ReadAggregateVR (int, HMatrix*&);
	template <> bool InStream::ReadAggregateRR (int&, HMatrix*&);
	template <> bool OutStream::WriteAggregate (const HMatrix&);
	template <> bool OutStream::WriteAggregateW (int, const HMatrix*);
	template <> bool OutStream::WriteAggregateN (int, const HMatrix*);

	// HPlane
	template <> bool InStream::ReadAggregate (HPlane&);
	template <> bool InStream::ReadAggregateVV (int, HPlane*);
	template <> bool InStream::ReadAggregateVR (int, HPlane*&);
	template <> bool InStream::ReadAggregateRR (int&, HPlane*&);
	template <> bool OutStream::WriteAggregate (const HPlane&);
	template <> bool OutStream::WriteAggregateW (int, const HPlane*);
	template <> bool OutStream::WriteAggregateN (int, const HPlane*);

	// APoint
	template <> bool InStream::ReadAggregate (APoint&);
	template <> bool InStream::ReadAggregateVV (int, APoint*);
	template <> bool InStream::ReadAggregateVR (int, APoint*&);
	template <> bool InStream::ReadAggregateRR (int&, APoint*&);
	template <> bool OutStream::WriteAggregate (const APoint&);
	template <> bool OutStream::WriteAggregateW (int, const APoint*);
	template <> bool OutStream::WriteAggregateN (int, const APoint*);

	// AVector
	template <> bool InStream::ReadAggregate (AVector&);
	template <> bool InStream::ReadAggregateVV (int, AVector*);
	template <> bool InStream::ReadAggregateVR (int, AVector*&);
	template <> bool InStream::ReadAggregateRR (int&, AVector*&);
	template <> bool OutStream::WriteAggregate (const AVector&);
	template <> bool OutStream::WriteAggregateW (int, const AVector*);
	template <> bool OutStream::WriteAggregateN (int, const AVector*);

	// HQuaternion
	template <> bool InStream::ReadAggregate (HQuaternion&);
	template <> bool InStream::ReadAggregateVV (int, HQuaternion*);
	template <> bool InStream::ReadAggregateVR (int, HQuaternion*&);
	template <> bool InStream::ReadAggregateRR (int&, HQuaternion*&);
	template <> bool OutStream::WriteAggregate (const HQuaternion&);
	template <> bool OutStream::WriteAggregateW (int, const HQuaternion*);
	template <> bool OutStream::WriteAggregateN (int, const HQuaternion*);

	// Transform
	template <> bool InStream::ReadAggregate (Transform&);
	template <> bool InStream::ReadAggregateVV (int, Transform*);
	template <> bool InStream::ReadAggregateVR (int, Transform*&);
	template <> bool InStream::ReadAggregateRR (int&, Transform*&);
	template <> bool OutStream::WriteAggregate (const Transform&);
	template <> bool OutStream::WriteAggregateW (int, const Transform*);
	template <> bool OutStream::WriteAggregateN (int, const Transform*);

	// Vector3f
	template <> bool InStream::ReadAggregate (Vector3f&);
	template <> bool InStream::ReadAggregateVV (int, Vector3f*);
	template <> bool InStream::ReadAggregateVR (int, Vector3f*&);
	template <> bool InStream::ReadAggregateRR (int&, Vector3f*&);
	template <> bool OutStream::WriteAggregate (const Vector3f&);
	template <> bool OutStream::WriteAggregateW (int, const Vector3f*);
	template <> bool OutStream::WriteAggregateN (int, const Vector3f*);

	// Sizef
	template <> bool InStream::ReadAggregate (Sizef&);
	template <> bool InStream::ReadAggregateVV (int, Sizef*);
	template <> bool InStream::ReadAggregateVR (int, Sizef*&);
	template <> bool InStream::ReadAggregateRR (int&, Sizef*&);
	template <> bool OutStream::WriteAggregate (const Sizef&);
	template <> bool OutStream::WriteAggregateW (int, const Sizef*);
	template <> bool OutStream::WriteAggregateN (int, const Sizef*);

	// Rectf
	template <> bool InStream::ReadAggregate (Rectf&);
	template <> bool InStream::ReadAggregateVV (int, Rectf*);
	template <> bool InStream::ReadAggregateVR (int, Rectf*&);
	template <> bool InStream::ReadAggregateRR (int&, Rectf*&);
	template <> bool OutStream::WriteAggregate (const Rectf&);
	template <> bool OutStream::WriteAggregateW (int, const Rectf*);
	template <> bool OutStream::WriteAggregateN (int, const Rectf*);

	// InterpCurvePoint
	template <> bool InStream::ReadAggregate (InterpCurvePointFloat&);
	template <> bool InStream::ReadAggregateVV (int, InterpCurvePointFloat*);
	template <> bool InStream::ReadAggregateVR (int, InterpCurvePointFloat*&);
	template <> bool InStream::ReadAggregateRR (int&, InterpCurvePointFloat*&);
	template <> bool OutStream::WriteAggregate (const InterpCurvePointFloat&);
	template <> bool OutStream::WriteAggregateW (int, const InterpCurvePointFloat*);
	template <> bool OutStream::WriteAggregateN (int, const InterpCurvePointFloat*);

	// InterpCurvePoint3
	template <> bool InStream::ReadAggregate (InterpCurvePointFloat3&);
	template <> bool InStream::ReadAggregateVV (int, InterpCurvePointFloat3*);
	template <> bool InStream::ReadAggregateVR (int, InterpCurvePointFloat3*&);
	template <> bool InStream::ReadAggregateRR (int&, InterpCurvePointFloat3*&);
	template <> bool OutStream::WriteAggregate (const InterpCurvePointFloat3&);
	template <> bool OutStream::WriteAggregateW (int, const InterpCurvePointFloat3*);
	template <> bool OutStream::WriteAggregateN (int, const InterpCurvePointFloat3*);

	// InterpCurveFloat
	template <> bool InStream::ReadAggregate (InterpCurveFloat&);
	template <> bool InStream::ReadAggregateVV (int, InterpCurveFloat*);
	template <> bool InStream::ReadAggregateVR (int, InterpCurveFloat*&);
	template <> bool InStream::ReadAggregateRR (int&, InterpCurveFloat*&);
	template <> bool OutStream::WriteAggregate (const InterpCurveFloat&);
	template <> bool OutStream::WriteAggregateW (int, const InterpCurveFloat*);
	template <> bool OutStream::WriteAggregateN (int, const InterpCurveFloat*);

	// InterpCurveFloat3
	template <> bool InStream::ReadAggregate (InterpCurveFloat3&);
	template <> bool InStream::ReadAggregateVV (int, InterpCurveFloat3*);
	template <> bool InStream::ReadAggregateVR (int, InterpCurveFloat3*&);
	template <> bool InStream::ReadAggregateRR (int&, InterpCurveFloat3*&);
	template <> bool OutStream::WriteAggregate (const InterpCurveFloat3&);
	template <> bool OutStream::WriteAggregateW (int, const InterpCurveFloat3*);
	template <> bool OutStream::WriteAggregateN (int, const InterpCurveFloat3*);

}

#endif
