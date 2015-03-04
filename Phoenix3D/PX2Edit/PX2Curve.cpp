// PX2Curve.cpp

#include "PX2Curve.hpp"
#include "PX2Node.hpp"
#include "PX2Edit.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Curve::Curve ()
{
	mNode = new0 Node();
	mNode->Culling = Movable::CULL_NEVER;
}
//----------------------------------------------------------------------------
Curve::~Curve ()
{
}
//----------------------------------------------------------------------------
void Curve::GetInRange (float &inMin, float &inMax)
{
	PX2_UNUSED(inMin);
	PX2_UNUSED(inMax);
}
//----------------------------------------------------------------------------
void Curve::GetOutRange (float &outMin, float &outMax)
{
	PX2_UNUSED(outMin);
	PX2_UNUSED(outMax);
}
//----------------------------------------------------------------------------
InterpCurveMode Curve::GetInterpMode (int index)
{
	PX2_UNUSED(index);

	return ICM_MAX_MODE;
}
//----------------------------------------------------------------------------
void Curve::AddPoint (float inVal, float outZ)
{
	PX2_UNUSED(inVal);
	PX2_UNUSED(outZ);
}
//----------------------------------------------------------------------------
int Curve::SetInVal (int index, float val)
{
	PX2_UNUSED(index);
	PX2_UNUSED(val);

	return 0;
}
//----------------------------------------------------------------------------
void Curve::DeletePoint (int index)
{
	PX2_UNUSED(index);
}
//----------------------------------------------------------------------------
int Curve::GetNumPoints ()
{
	return 0;
}
//----------------------------------------------------------------------------
void Curve::SetVisible (bool show)
{
	if (!mNode)
		return;

	mNode->Show(show);
}
//----------------------------------------------------------------------------
bool Curve::IsVisible () const
{
	return mNode->IsShow();
}
//----------------------------------------------------------------------------
CurveCtrl *Curve::GetCtrl (int i)
{
	if (0<=i && i<(int)mCtrls.size())
		return mCtrls[i];

	return 0;
}
//----------------------------------------------------------------------------
void Curve::SetCtrlsScale (float scaleX, float scaleZ)
{
	for (int i=0; i<(int)mCtrls.size(); i++)
	{
		mCtrls[i]->SetCtrlsScale(scaleX, scaleZ);
	}
}
//----------------------------------------------------------------------------
CurveCtrl *Curve::TrySelectCurve (PX2::Movable *mov)
{
	for (int i=0; i<(int)mCtrls.size(); i++)
	{
		if (!mCtrls[i])
			continue;

		if (mCtrls[i]->mDragBox == mov || mCtrls[i]->mDragBoxArrive == mov
			|| mCtrls[i]->mDragBoxLeave == mov)
		{
			if (mCtrls[i]->mDragBoxArrive == mov)
			{
				mCtrls[i]->SetSelectMode(CurveCtrl::SM_ARRIVE);
			}
			else if (mCtrls[i]->mDragBoxLeave == mov)
			{
				mCtrls[i]->SetSelectMode(CurveCtrl::SM_LEAVE);
			}
			else if (mCtrls[i]->mDragBox == mov)
			{
				mCtrls[i]->SetSelectMode(CurveCtrl::SM_CENTER);
			}
			else
			{
				mCtrls[i]->SetSelectMode(CurveCtrl::SM_MAX_MODE);
			}

			return mCtrls[i];
		}
	}

	return 0;
}
//----------------------------------------------------------------------------
void Curve::UpdateCurve ()
{
}
//----------------------------------------------------------------------------
void Curve::UpdateCtrls ()
{
}
//----------------------------------------------------------------------------
void Curve::ReCreateCtrls ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// CurveFloat
//----------------------------------------------------------------------------
CurveFloat::CurveFloat (PX2::InterpCurveFloat *curve, Float3 color) :
mCurve(curve)
{
	mCurveColor = color;

	mPoly = PX2_EDIT.GetTimeLineEdit()->CreatePoly(curve, 
		mCurveColor);
	mNode->AttachChild(mPoly);

	ReCreateCtrls();
}
//----------------------------------------------------------------------------
CurveFloat::~CurveFloat ()
{
}
//----------------------------------------------------------------------------
void CurveFloat::GetInRange (float &inMin, float &inMax)
{
	for (int i=0; i<mCurve->GetNumPoints(); i++)
	{
		float inVal = mCurve->Points[i].InVal;

		if (inVal < inMin)
		{
			inMin = inVal;
		}
		if (inVal > inMax)
		{
			inMax = inVal;
		}
	}
}
//----------------------------------------------------------------------------
void CurveFloat::GetOutRange (float &outMin, float &outMax)
{
	for (int i=0; i<mCurve->GetNumPoints(); i++)
	{
		float outVal = mCurve->Points[i].OutVal;

		if (outVal < outMin)
		{
			outMin = outVal;
		}
		if (outVal > outMax)
		{
			outMax = outVal;
		}
	}
}
//----------------------------------------------------------------------------
PX2::InterpCurveMode CurveFloat::GetInterpMode (int index)
{
	if (0<=index && index<GetNumPoints())
		return mCurve->Points[index].InterpMode;

	return ICM_MAX_MODE;
}
//----------------------------------------------------------------------------
void CurveFloat::AddPoint (float inVal, float outZ)
{
	mCurve->AddPoint(inVal, outZ, 0.0f, 0.0f, ICM_CURVE_AUTO);
}
//----------------------------------------------------------------------------
int CurveFloat::SetInVal (int index, float val)
{
	int newIndex = mCurve->MovePoint(index, val);

	return newIndex;
}
//----------------------------------------------------------------------------
void CurveFloat::DeletePoint (int index)
{
	mCurve->RemovePoint(index);
}
//----------------------------------------------------------------------------
int CurveFloat::GetNumPoints ()
{
	if (mCurve)
		return mCurve->GetNumPoints();

	return 0;
}
//----------------------------------------------------------------------------
void CurveFloat::UpdateCurve ()
{
	PX2_EDIT.GetTimeLineEdit()->UpdatePoly(mCurve, mPoly, mCurveColor);
}
//----------------------------------------------------------------------------
void CurveFloat::UpdateCtrls ()
{
	for (int i=0; i<mCurve->GetNumPoints(); i++)
	{
		CurveCtrl *ctrl = mCtrls[i];
		ctrl->SetIndex(i);
	}

	for (int i=0; i<mCurve->GetNumPoints(); i++)
	{
		CurveCtrl *ctrl = mCtrls[i];
		ctrl->OnCtrlChanged(false);
	}
}
//----------------------------------------------------------------------------
void CurveFloat::ReCreateCtrls ()
{
	for (int i=0; i<(int)mCtrls.size(); i++)
	{
		if (mCtrls[i])
			mNode->DetachChild(mCtrls[i]->GetNode());
		mCtrls[i] = 0;
	}
	mCtrls.clear();

	for (int i=0; i<mCurve->GetNumPoints(); i++)
	{
		CurveCtrlFloat *ctrl = new0 CurveCtrlFloat(this, i);
		mCtrls.push_back(ctrl);

		mNode->AttachChild(ctrl->GetNode());
	}

	float xScale = PX2_EDIT.GetTimeLineEdit()->GetCtrlsScale()[0];
	float zScale = PX2_EDIT.GetTimeLineEdit()->GetCtrlsScale()[1];
	SetCtrlsScale(xScale, zScale);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// CurveFloat3Axis
//----------------------------------------------------------------------------
CurveFloat3Axis::CurveFloat3Axis (PX2::InterpCurveFloat3 *curve, int axis,
	PX2::Float3 color)
	:
mCurve(curve),
mAxis(axis)
{
	mCurveColor = color;

	mPoly = PX2_EDIT.GetTimeLineEdit()->CreatePoly(curve, axis, 
		mCurveColor);
	mNode->AttachChild(mPoly);

	ReCreateCtrls();
}
//----------------------------------------------------------------------------
CurveFloat3Axis::~CurveFloat3Axis ()
{
}
//----------------------------------------------------------------------------
void CurveFloat3Axis::GetInRange (float &inMin, float &inMax)
{
	for (int i=0; i<mCurve->GetNumPoints(); i++)
	{
		float inVal = mCurve->Points[i].InVal;

		if (inVal < inMin)
		{
			inMin = inVal;
		}
		if (inVal > inMax)
		{
			inMax = inVal;
		}
	}
}
//----------------------------------------------------------------------------
void CurveFloat3Axis::GetOutRange (float &outMin, float &outMax)
{
	for (int i=0; i<mCurve->GetNumPoints(); i++)
	{
		Float3 outVal = mCurve->Points[i].OutVal;

		if (outVal[0] < outMin)
		{
			outMin = outVal[0];
		}
		if (outVal[1] < outMin)
		{
			outMin = outVal[1];
		}
		if (outVal[2] < outMin)
		{
			outMin = outVal[2];
		}

		if (outVal[0] > outMax)
		{
			outMax = outVal[0];
		}
		if (outVal[1] > outMax)
		{
			outMax = outVal[1];
		}
		if (outVal[2] > outMax)
		{
			outMax = outVal[2];
		}
	}
}
//----------------------------------------------------------------------------
InterpCurveMode CurveFloat3Axis::GetInterpMode (int index)
{
	if (0<=index && index<GetNumPoints())
		return mCurve->Points[index].InterpMode;

	return ICM_MAX_MODE;
}
//----------------------------------------------------------------------------
void CurveFloat3Axis::AddPoint (float inVal, float outZ)
{
	mCurve->AddPoint(inVal, Float3(outZ, outZ, outZ), Float3::ZERO,
		Float3::ZERO, ICM_CURVE_AUTO);
}
//----------------------------------------------------------------------------
int CurveFloat3Axis::SetInVal (int index, float val)
{
	int newIndex = mCurve->MovePoint(index, val);
	return newIndex;
}
//----------------------------------------------------------------------------
void CurveFloat3Axis::DeletePoint (int index)
{
	mCurve->RemovePoint(index);
}
//----------------------------------------------------------------------------
int CurveFloat3Axis::GetNumPoints ()
{
	if (mCurve)
		return mCurve->GetNumPoints();

	return 0;
}
//----------------------------------------------------------------------------
void CurveFloat3Axis::UpdateCurve ()
{
	PX2_EDIT.GetTimeLineEdit()->UpdatePoly(mCurve, mPoly, mAxis,
		mCurveColor);
}
//----------------------------------------------------------------------------
void CurveFloat3Axis::UpdateCtrls ()
{
	for (int i=0; i<mCurve->GetNumPoints(); i++)
	{
		CurveCtrl *ctrl = mCtrls[i];
		ctrl->SetIndex(i);
	}

	for (int i=0; i<mCurve->GetNumPoints(); i++)
	{
		CurveCtrl *ctrl = mCtrls[i];
		ctrl->OnCtrlChanged(false);
	}
}
//----------------------------------------------------------------------------
void CurveFloat3Axis::ReCreateCtrls ()
{
	for (int i=0; i<(int)mCtrls.size(); i++)
	{
		if (mCtrls[i])
			mNode->DetachChild(mCtrls[i]->GetNode());
		mCtrls[i] = 0;
	}
	mCtrls.clear();

	for (int i=0; i<mCurve->GetNumPoints(); i++)
	{
		CurveCtrlFloat3Axis *ctrl = new0 CurveCtrlFloat3Axis(this, i);
		mCtrls.push_back(ctrl);

		mNode->AttachChild(ctrl->GetNode());
	}

	float xScale = PX2_EDIT.GetTimeLineEdit()->GetCtrlsScale()[0];
	float zScale = PX2_EDIT.GetTimeLineEdit()->GetCtrlsScale()[1];
	SetCtrlsScale(xScale, zScale);
}
//----------------------------------------------------------------------------