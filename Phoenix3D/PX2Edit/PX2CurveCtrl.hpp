// PX2CurveCtrl.hpp

#ifndef PX2CURVECTRL_HPP
#define PX2CURVECTRL_HPP

#include "PX2EditPre.hpp"
#include "PX2InterpCurve.hpp"
#include "PX2Node.hpp"
#include "PX2TriMesh.hpp"
#include "PX2Polysegment.hpp"

namespace PX2
{

	class Curve;
	class CurveFloat;
	class CurveFloat3Axis;

	class PX2_EDIT_ITEM CurveCtrl
	{
	public:
		virtual ~CurveCtrl ();

		enum CurveCtrlType
		{
			CCT_FLOAT,
			CCT_FLOAT3
		};
		CurveCtrlType GetCruveCtrlType () { return mCtrlType; }

		int GetIndex () { return mIndex; }

		void SetCtrlsScale (float xScale, float zScale);

		void Select (bool select);
		bool IsSelected () { return mSelected; }
		Curve *GetCurve () { return mCurve; }

		enum SelectMode
		{
			SM_ARRIVE,
			SM_CENTER,
			SM_LEAVE,
			SM_MAX_MODE,
		};
		void SetSelectMode (SelectMode mode) { mSelectMode = mode; }
		SelectMode GetSelectMode () { return mSelectMode; }
		void SetShowDrag (SelectMode mode, bool show);

		virtual bool SetInVal (float inVal);
		virtual bool SetOutVal (PX2::APoint outVal);
		virtual bool SetArriveTangent (PX2::AVector at);
		virtual bool SetLeaveTangent (PX2::AVector lt);
		virtual bool SetInterpCurveMode (PX2::InterpCurveMode mode);
		PX2::InterpCurveMode GetInterpCurveMode () { return mInterpCurveMode; }
		const PX2::AVector &GetArriveTangent () { return mArriveTangent; }
		const PX2::AVector &GetLeaveTangent () { return mLeaveTangent; }

		float GetInVal () { return mInVal; }
		const PX2::APoint &GetOutVal () { return mOutVal; }

		PX2::Node *GetNode () { return mCtrlNode; }

		virtual void OnCtrlChanged (bool updateCurve);

public_internal:
		void SetIndex (int index) { mIndex = index; }

	protected:
		CurveCtrl (Curve *curve, CurveCtrlType type, int index);

		int mIndex;

		CurveCtrlType mCtrlType;
		SelectMode mSelectMode;
		bool mSelected;
		Curve *mCurve;
		float mXScale;
		float mZScale;

protected:
		float mInVal;
		PX2::APoint mOutVal;
		PX2::AVector mArriveTangent;
		PX2::AVector mLeaveTangent;
		PX2::InterpCurveMode mInterpCurveMode;

		float mDragLength;

public_internal:
		PX2::NodePtr mCtrlNode;
		PX2::TriMeshPtr mDragBox;
		PX2::TriMeshPtr mDragBoxArrive;
		PX2::TriMeshPtr mDragBoxLeave;
		PX2::PolysegmentPtr mDragLineArrive;
		PX2::PolysegmentPtr mDragLineLeave;
	};
	typedef PX2::Pointer0<CurveCtrl> CurveCtrlPtr;

	class CurveCtrlFloat : public CurveCtrl
	{
	public:
		CurveCtrlFloat (CurveFloat *curve, int index);
		virtual ~CurveCtrlFloat ();

		virtual bool SetInVal (float inVal);
		virtual bool SetOutVal (PX2::APoint outVal);
		virtual bool SetArriveTangent (PX2::AVector at);
		virtual bool SetLeaveTangent (PX2::AVector lt);
		virtual bool SetInterpCurveMode (PX2::InterpCurveMode mode);

		virtual void OnCtrlChanged (bool updateCurve);

	protected:
		CurveFloat *mCurveFloat;
	};
	typedef PX2::Pointer0<CurveCtrlFloat> CurveCtrlFloatPtr;

	class CurveCtrlFloat3Axis : public CurveCtrl
	{
	public:
		CurveCtrlFloat3Axis (CurveFloat3Axis *curve, int index);
		virtual ~CurveCtrlFloat3Axis();

		virtual bool SetInVal (float inVal);
		virtual bool SetOutVal (PX2::APoint outVal);
		virtual bool SetArriveTangent (PX2::AVector at);
		virtual bool SetLeaveTangent (PX2::AVector lt);
		virtual bool SetInterpCurveMode (PX2::InterpCurveMode mode);

		virtual void OnCtrlChanged (bool updateCurve);

	protected:
		CurveFloat3Axis *mCurveFloat3Axis;
	};
	typedef PX2::Pointer0<CurveCtrlFloat3Axis> CurveCtrlFloat3Ptr;

}

#endif