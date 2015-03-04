// PX2Curve.hpp

#ifndef PX2EDITCURVE_HPP
#define PX2EDITCURVE_HPP

#include "PX2EditPre.hpp"
#include "PX2CurveCtrl.hpp"
#include "PX2Polysegment.hpp"

namespace PX2
{

	// curves
	class Curve 
	{
	public:
		virtual ~Curve ();
		
		virtual void GetInRange (float &inMin, float &inMax);
		virtual void GetOutRange (float &outMin, float &outMax);
		virtual PX2::InterpCurveMode GetInterpMode (int index);

		virtual void AddPoint (float inVal, float outZ);
		virtual int SetInVal (int index, float val);
		virtual void DeletePoint (int index);
		virtual int GetNumPoints ();

		void SetVisible (bool show);
		bool IsVisible () const;

		PX2::Float3 GetCurveColor () { return mCurveColor; }
		PX2::Node *GetNode () { return mNode; }
		PX2::Polysegment *GetPoly () { return mPoly; }
		
		CurveCtrl *GetCtrl (int i);
		void SetCtrlsScale (float scaleX, float scaleZ);
		CurveCtrl *TrySelectCurve (PX2::Movable *mov);
		virtual void UpdateCurve ();
		virtual void UpdateCtrls ();
		virtual void ReCreateCtrls ();		

	protected:
		Curve ();

		std::vector<CurveCtrlPtr> mCtrls;
		PX2::NodePtr mNode;
		PX2::Float3 mCurveColor;
		PX2::PolysegmentPtr mPoly;
	};
	typedef PX2::Pointer0<Curve> CurvePtr;

	class CurveFloat : public Curve
	{
	public:
		CurveFloat (PX2::InterpCurveFloat *curve, PX2::Float3 color);
		virtual ~CurveFloat ();

		virtual void GetInRange (float &inMin, float &inMax);
		virtual void GetOutRange (float &outMin, float &outMax);
		virtual PX2::InterpCurveMode GetInterpMode (int index);

		virtual void AddPoint (float inVal, float outZ);
		virtual int SetInVal (int index, float val);
		virtual void DeletePoint (int index);
		virtual int GetNumPoints ();

		virtual void UpdateCurve ();
		virtual void UpdateCtrls ();
		virtual void ReCreateCtrls ();

	public_internal:
		PX2::InterpCurveFloat *mCurve;
	};
	typedef PX2::Pointer0<CurveFloat> CurveFloatPtr;

	class CurveFloat3Axis : public Curve
	{
	public:
		CurveFloat3Axis (PX2::InterpCurveFloat3 *curve, int axis, 
			PX2::Float3 color);
		virtual ~CurveFloat3Axis ();

		virtual void GetInRange (float &inMin, float &inMax);
		virtual void GetOutRange (float &outMin, float &outMax);
		virtual PX2::InterpCurveMode GetInterpMode (int index);

		virtual void AddPoint (float inVal, float outZ);
		virtual int SetInVal (int index, float val);
		virtual void DeletePoint (int index);
		virtual int GetNumPoints ();

		int GetAxis () { return mAxis; }

		virtual void UpdateCurve ();
		virtual void UpdateCtrls ();
		virtual void ReCreateCtrls ();

public_internal:
		PX2::InterpCurveFloat3 *mCurve;
		int mAxis;
	};
	typedef PX2::Pointer0<CurveFloat3Axis> CurveFloat3AxisPtr;

}

#endif