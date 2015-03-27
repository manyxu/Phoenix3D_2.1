// PX2CurveGroup.hpp

#ifndef PX2CURVEGROUP_HPP
#define PX2CURVEGROUP_HPP

#include "PX2Curve.hpp"
#include "PX2EffectModule.hpp"
#include "PX2Controller.hpp"

namespace PX2
{

	class CurveGroup
	{
	public:
		enum CGType
		{
			CGT_FLOAT,
			CGT_FLOATRANGE,
			CGT_FLOAT3,
			CGT_FLOAT3RANGE,
			CGT_MAX_TYPE
		};
		CurveGroup (CGType t);
		~CurveGroup ();

		void SetCGType (CGType type) { mType = type; }
		CGType GetCGType () { return mType; }

		void SetName (std::string name);
		std::string GetName ();

		void SetVisible (bool show);
		bool IsVisible () const;
		void SetVisible (int index, bool show);

		void AddPoint (const PX2::APoint &pos);
		void DeletePoint (int index);
		int SetInVal (int index, float val);
		int GetNumPoints();

		void UpdateCurve ();
		void UpdateCtrls ();
		void ReCreateCtrls ();

		CurvePtr mCurve0;
		CurvePtr mCurve1;
		CurvePtr mCurve2;
		CurvePtr mCurve3;
		CurvePtr mCurve4;
		CurvePtr mCurve5;
		PX2::ObjectPtr mObject;

	protected:
		CurveGroup ();

		CGType mType;
		std::string mName;
		bool mIsVisible;
	};
	typedef PX2::Pointer0<CurveGroup> CurveGroupPtr;

}

#endif