// PX2CurveCtrl.cpp

#include "PX2CurveCtrl.hpp"
#include "PX2Curve.hpp"
#include "PX2Edit.hpp"
#include "PX2Renderer.hpp"
#include "PX2VertexFormat.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;
using namespace PX2;

//----------------------------------------------------------------------------
// CurveCtrl
//----------------------------------------------------------------------------
CurveCtrl::~CurveCtrl ()
{
}
//----------------------------------------------------------------------------
void CurveCtrl::SetCtrlsScale (float xScale, float zScale)
{
	mXScale = xScale;
	mZScale = zScale;

	if (mDragBox)
	{
		APoint scale = mDragBox->LocalTransform.GetScale();
		mDragBox->LocalTransform.SetScale(Float3(xScale, scale.Y(), zScale));
	}

	if (mDragBoxArrive)
	{
		mDragBoxArrive->LocalTransform.SetScale(Float3(xScale, 1.0f, zScale));
	}

	if (mDragBoxLeave)
	{
		mDragBoxLeave->LocalTransform.SetScale(Float3(xScale, 1.0f, zScale));
	}

	OnCtrlChanged(false);
}
//----------------------------------------------------------------------------
void CurveCtrl::Select (bool select)
{
	if (mSelected == select)
		return;

	if (mSelected)
	{
		APoint scale = mDragBox->LocalTransform.GetScale();
		mDragBox->LocalTransform.SetScale(APoint(scale.X(), 1.0f, scale.Z()));
	}

	mSelected = select;

	Float3 color = mCurve->GetCurveColor();
	if (mSelected)
	{
		color = Float3::YELLOW;
		APoint scale = mDragBox->LocalTransform.GetScale();
		mDragBox->LocalTransform.SetScale(APoint(scale.X(), 1.5f, scale.Z()));
	}

	VertexBufferAccessor vba(mDragBox);
	for (int i=0; i<vba.GetNumVertices(); i++)
	{
		vba.Color<Float3>(0, i) = color;
	}
	Renderer::UpdateAll(mDragBox->GetVertexBuffer());

	OnCtrlChanged (false);
}
//----------------------------------------------------------------------------
void CurveCtrl::SetShowDrag (SelectMode mode, bool show)
{
	Movable::CullingMode cullingMode = Movable::CULL_DYNAMIC;
	
	if (!show)
	{
		cullingMode = Movable::CULL_ALWAYS;
	}

	if (SM_ARRIVE == mode)
	{
		mDragBoxArrive->Culling = cullingMode;
		mDragLineArrive->Culling = cullingMode;
	}
	else if (SM_CENTER == mode)
	{
		mDragBox->Culling = cullingMode;
	}
	else if (SM_LEAVE == mode)
	{
		mDragBoxLeave->Culling = cullingMode;
		mDragLineLeave->Culling = cullingMode;
	}
}
//----------------------------------------------------------------------------
bool CurveCtrl::SetInVal (float inVal)
{
	mInVal = inVal;

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrl::SetOutVal (PX2::APoint outVal)
{
	mOutVal = APoint(mInVal, outVal.Y(), outVal.Z());

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrl::SetArriveTangent (PX2::AVector at)
{
	mArriveTangent = at;

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrl::SetLeaveTangent (PX2::AVector lt)
{
	mLeaveTangent = lt;

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrl::SetInterpCurveMode (PX2::InterpCurveMode mode)
{
	mInterpCurveMode = mode;

	return true;
}
//----------------------------------------------------------------------------
CurveCtrl::CurveCtrl (Curve *curve, CurveCtrlType type, int index)
	:
mIndex(index),
mSelected(false),
mCurve(curve),
mCtrlType(type),
mXScale(1.0f),
mZScale(1.0f),
mDragLength(1.0f),
mInVal(-1.0f),
mSelectMode(SM_MAX_MODE)
{
	mCtrlNode = new0 Node();

	float dragSize = 0.1f;

	VertexFormat *vFormat = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	StandardMesh sm(vFormat);

	Float3 curveColor = mCurve->GetCurveColor();

	VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
	MaterialInstancePtr mtlInst = mtl->CreateInstance();

	sm.SetVertexColor(Float4(curveColor[0], curveColor[1], curveColor[2], 1.0f));
	mDragBox = sm.Box(dragSize, dragSize, dragSize);
	mDragBox->SetMaterialInstance(mtlInst);

	sm.SetVertexColor(Float4::WHITE);

	mDragBoxArrive = sm.Box(dragSize, dragSize, dragSize);
	mDragBoxArrive->SetMaterialInstance(mtlInst);

	mDragBoxLeave = sm.Box(dragSize, dragSize, dragSize);
	mDragBoxLeave->SetMaterialInstance(mtlInst);

	VertexBuffer *vBuffer = new0 VertexBuffer(2, vFormat->GetStride(), 
		Buffer::BU_DYNAMIC);
	mDragLineArrive = new0 Polysegment(vFormat, vBuffer, true);
	mDragLineArrive->SetMaterialInstance(mtlInst);

	VertexBuffer *vBuffer1 = new0 VertexBuffer(2, vFormat->GetStride(), 
		Buffer::BU_DYNAMIC);
	mDragLineLeave = new0 Polysegment(vFormat, vBuffer1, true);
	mDragLineLeave->SetMaterialInstance(mtlInst);

	sm.SetVertexColor(Float4::YELLOW);

	mCtrlNode->AttachChild(mDragBox);
	mCtrlNode->AttachChild(mDragBoxArrive);
	mCtrlNode->AttachChild(mDragBoxLeave);
	mCtrlNode->AttachChild(mDragLineArrive);
	mCtrlNode->AttachChild(mDragLineLeave);

	mDragBoxArrive->Culling = Movable::CULL_ALWAYS;
	mDragBoxLeave->Culling = Movable::CULL_ALWAYS;
	mDragLineArrive->Culling = Movable::CULL_ALWAYS;
	mDragLineLeave->Culling = Movable::CULL_ALWAYS;

	mCtrlNode->Update();
}
//----------------------------------------------------------------------------
void CurveCtrl::OnCtrlChanged (bool updateCurve)
{
	SetShowDrag(SM_CENTER, true);

	if (IsSelected())
	{
		SetShowDrag(SM_ARRIVE, true);
		SetShowDrag(SM_CENTER, true);
		SetShowDrag(SM_LEAVE, true);
	}
	else
	{
		SetShowDrag(SM_ARRIVE, false);
		SetShowDrag(SM_LEAVE, false);
	}

	if (1 == mCurve->GetNumPoints())
	{
		SetShowDrag(SM_ARRIVE, false);
		SetShowDrag(SM_CENTER, true);
		SetShowDrag(SM_LEAVE, false);
	}
	else
	{
		if (0 == mIndex)
		{
			SetShowDrag(SM_ARRIVE, false);
		}
		else if (mCurve->GetNumPoints()-1 == mIndex)
		{
			SetShowDrag(SM_LEAVE, false);
		}
	}

	if (ICM_CONSTANT==mInterpCurveMode || ICM_LINEAR==mInterpCurveMode)
	{
		SetShowDrag(SM_LEAVE, false);
	}

	if (0 <= mIndex-1)
	{
		InterpCurveMode interpMode = mCurve->GetInterpMode(mIndex-1);
		if (ICM_CONSTANT==interpMode || ICM_LINEAR==interpMode)
		{
			SetShowDrag(SM_ARRIVE, false);
		}
	}

	mCtrlNode->LocalTransform.SetTranslate(mOutVal);

	float aX = mArriveTangent.X();
	float aZ = mArriveTangent.Z();
	float aX1 = aX * (1.0f/mXScale);
	float aZ1 = aZ * (1.0f/mZScale);
	float aScale = Mathf::Sqrt(aX*aX+aZ*aZ)/Mathf::Sqrt(aX1*aX1+aZ1*aZ1);

	float lX = mLeaveTangent.X();
	float lZ = mLeaveTangent.Z();
	float lX1 = lX * (1.0f/mXScale);
	float lZ1 = lZ * (1.0f/mZScale);
	float lScale = Mathf::Sqrt(lX*lX+lZ*lZ)/Mathf::Sqrt(lX1*lX1+lZ1*lZ1);

	APoint arrivePos = APoint::ORIGIN - mArriveTangent * mDragLength * aScale;
	APoint leavePos = APoint::ORIGIN + mLeaveTangent * mDragLength * lScale;

	mDragBoxArrive->LocalTransform.SetTranslate(arrivePos);
	mDragBoxLeave->LocalTransform.SetTranslate(leavePos);

	VertexBufferAccessor vba(mDragLineArrive);
	vba.Position<Float3>(0) = arrivePos;
	vba.Color<Float3>(0, 0) = Float3::WHITE;
	vba.Position<Float3>(1) = APoint::ORIGIN;
	vba.Color<Float3>(0, 1) = Float3::WHITE;
	mDragLineArrive->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);
	Renderer::UpdateAll(mDragLineArrive->GetVertexBuffer());

	VertexBufferAccessor vba1(mDragLineLeave);
	vba1.Position<Float3>(0) = APoint::ORIGIN;
	vba1.Color<Float3>(0, 0) = Float3::WHITE;
	vba1.Position<Float3>(1) = leavePos;
	vba1.Color<Float3>(0, 1) = Float3::WHITE;
	mDragLineLeave->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);

	Renderer::UpdateAll(mDragLineLeave->GetVertexBuffer());

	if (mCurve && updateCurve)
		mCurve->UpdateCurve();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// CurveCtrlFloat
//----------------------------------------------------------------------------
CurveCtrlFloat::CurveCtrlFloat (CurveFloat *curve, int index)
	:
CurveCtrl(curve, CCT_FLOAT, index),
mCurveFloat(curve)
{
	OnCtrlChanged(false);
}
//----------------------------------------------------------------------------
CurveCtrlFloat::~CurveCtrlFloat ()
{
}
//----------------------------------------------------------------------------
bool CurveCtrlFloat::SetInVal (float inVal)
{
	CurveCtrl::SetInVal(inVal);

	int oldIndex = mIndex;

	CurveGroup *group = PX2_EDIT.GetTimeLineEdit()->GetCurveGroup(mCurve);
	int newIndex = group->SetInVal(mIndex, inVal);

	if (newIndex != oldIndex)
	{
		CurveCtrl *ctrl = mCurve->GetCtrl(newIndex);
		ctrl->SetSelectMode(GetSelectMode());
		SetSelectMode(SM_MAX_MODE);
		PX2_EDIT.GetTimeLineEdit()->SetSelectedCurveCtrl(ctrl);
	}

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrlFloat::SetOutVal (PX2::APoint outVal)
{
	CurveCtrl::SetOutVal(outVal);

	mCurveFloat->mCurve->Points[mIndex].OutVal = outVal.Z();

	OnCtrlChanged(true);

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrlFloat::SetArriveTangent (PX2::AVector at)
{
	if (ICM_CURVE_AUTO==mInterpCurveMode 
		|| ICM_CURVE_AUTOCLAMPED==mInterpCurveMode
		|| ICM_CURVE_USER==mInterpCurveMode)
	{
		CurveCtrl::SetArriveTangent(at);
		CurveCtrl::SetLeaveTangent(at);
	}
	else if (ICM_CURVE_BREAK ==mInterpCurveMode || ICM_LINEAR ==mInterpCurveMode
		|| ICM_CONSTANT ==mInterpCurveMode)
	{
		CurveCtrl::SetArriveTangent(at);
	}
	else
	{
		return false;
	}

	mCurveFloat->mCurve->Points[mIndex].ArriveTangent
		= mArriveTangent.Z()/mArriveTangent.X();
	mCurveFloat->mCurve->Points[mIndex].LeaveTangent
		= mLeaveTangent.Z()/mLeaveTangent.X();

	OnCtrlChanged(true);

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrlFloat::SetLeaveTangent (PX2::AVector lt)
{
	if (ICM_CURVE_AUTO==mInterpCurveMode 
		|| ICM_CURVE_AUTOCLAMPED==mInterpCurveMode
		|| ICM_CURVE_USER==mInterpCurveMode)
	{
		CurveCtrl::SetArriveTangent(lt);
		CurveCtrl::SetLeaveTangent(lt);
	}
	else if (ICM_CURVE_BREAK ==mInterpCurveMode)
	{
		CurveCtrl::SetLeaveTangent(lt);
	}
	else
	{
		return false;
	}

	mCurveFloat->mCurve->Points[mIndex].ArriveTangent
		= mArriveTangent.Z()/mArriveTangent.X();
	mCurveFloat->mCurve->Points[mIndex].LeaveTangent 
		= mLeaveTangent.Z()/mLeaveTangent.X();

	OnCtrlChanged(true);

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrlFloat::SetInterpCurveMode (PX2::InterpCurveMode mode)
{
	CurveCtrl::SetInterpCurveMode(mode);

	mCurveFloat->mCurve->Points[mIndex].InterpMode = mode;

	CurveGroup *group = PX2_EDIT.GetTimeLineEdit()
		->GetCurveGroup(mCurve);

	if (group)
	{
		group->UpdateCurve();
		group->UpdateCtrls();
	}

	return true;
}
//----------------------------------------------------------------------------
void CurveCtrlFloat::OnCtrlChanged (bool updateCurve)
{
	if (mIndex >= (int)(mCurveFloat->mCurve->Points.size()))
		return;

	float inVal = mCurveFloat->mCurve->Points[mIndex].InVal;
	float outVal = mCurveFloat->mCurve->Points[mIndex].OutVal;
	float arriveTangent = mCurveFloat->mCurve->Points[mIndex].ArriveTangent;
	float leaveTangent = mCurveFloat->mCurve->Points[mIndex].LeaveTangent;
	InterpCurveMode mode = mCurveFloat->mCurve->Points[mIndex].InterpMode;

	mInVal = inVal;
	mOutVal = Float3(inVal, 0.0f, outVal);

	AVector at(1.0f, 0.0f, arriveTangent);
	at.Normalize();
	mArriveTangent = at;

	AVector lt (1.0f, 0.0f, leaveTangent);
	lt.Normalize();
	mLeaveTangent = lt;

	mInterpCurveMode = mode;

	CurveCtrl::OnCtrlChanged(updateCurve);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// CurveCtrlFloat3Axis
//----------------------------------------------------------------------------
CurveCtrlFloat3Axis::CurveCtrlFloat3Axis (CurveFloat3Axis *curve,int index)
	:
CurveCtrl(curve, CCT_FLOAT3, index),
mCurveFloat3Axis(curve)
{
	OnCtrlChanged(false);
}
//----------------------------------------------------------------------------
CurveCtrlFloat3Axis::~CurveCtrlFloat3Axis()
{
}
//----------------------------------------------------------------------------
bool CurveCtrlFloat3Axis::SetInVal (float inVal)
{
	CurveCtrl::SetInVal(inVal);

	int oldIndex = mIndex;

	CurveGroup *group = PX2_EDIT.GetTimeLineEdit()
		->GetCurveGroup(mCurve);
	int newIndex = group->SetInVal(mIndex, inVal);

	if (newIndex != oldIndex)
	{
		CurveCtrl *ctrl = mCurve->GetCtrl(newIndex);
		ctrl->SetSelectMode(GetSelectMode());
		SetSelectMode(SM_MAX_MODE);
		PX2_EDIT.GetTimeLineEdit()->SetSelectedCurveCtrl(ctrl);
	}

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrlFloat3Axis::SetOutVal (PX2::APoint outVal)
{
	CurveCtrl::SetOutVal(outVal);

	int axis = mCurveFloat3Axis->GetAxis();
	mCurveFloat3Axis->mCurve->Points[mIndex].OutVal[axis] = outVal.Z();

	OnCtrlChanged(true);

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrlFloat3Axis::SetArriveTangent (PX2::AVector at)
{
	if (ICM_CURVE_AUTO==mInterpCurveMode 
		|| ICM_CURVE_AUTOCLAMPED==mInterpCurveMode
		|| ICM_CURVE_USER==mInterpCurveMode)
	{
		CurveCtrl::SetArriveTangent(at);
		CurveCtrl::SetLeaveTangent(at);
	}
	else if (ICM_CURVE_BREAK==mInterpCurveMode || ICM_LINEAR==mInterpCurveMode)
	{
		CurveCtrl::SetArriveTangent(at);
	}
	else
	{
		return false;
	}

	int axis = mCurveFloat3Axis->GetAxis();
	mCurveFloat3Axis->mCurve->Points[mIndex].ArriveTangent[axis] = mArriveTangent.Z()/mArriveTangent.X();
	mCurveFloat3Axis->mCurve->Points[mIndex].LeaveTangent[axis]	= mLeaveTangent.Z()/mLeaveTangent.X();

	OnCtrlChanged(true);

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrlFloat3Axis::SetLeaveTangent (PX2::AVector lt)
{
	if (ICM_CURVE_AUTO==mInterpCurveMode 
		|| ICM_CURVE_AUTOCLAMPED==mInterpCurveMode
		|| ICM_CURVE_USER==mInterpCurveMode)
	{
		CurveCtrl::SetArriveTangent(lt);
		CurveCtrl::SetLeaveTangent(lt);
	}
	else if (ICM_CURVE_BREAK ==mInterpCurveMode)
	{
		CurveCtrl::SetLeaveTangent(lt);
	}
	else
	{
		return false;
	}

	int axis = mCurveFloat3Axis->GetAxis();
	mCurveFloat3Axis->mCurve->Points[mIndex].ArriveTangent[axis] = mArriveTangent.Z()/mArriveTangent.X();
	mCurveFloat3Axis->mCurve->Points[mIndex].LeaveTangent[axis] = mLeaveTangent.Z()/mLeaveTangent.X();

	OnCtrlChanged(true);

	return true;
}
//----------------------------------------------------------------------------
bool CurveCtrlFloat3Axis::SetInterpCurveMode (PX2::InterpCurveMode mode)
{
	CurveCtrl::SetInterpCurveMode(mode);

	mCurveFloat3Axis->mCurve->Points[mIndex].InterpMode = mode;

	CurveGroup *group = PX2_EDIT.GetTimeLineEdit()
		->GetCurveGroup(mCurve);

	if (group)
	{
		group->UpdateCurve();
		group->UpdateCtrls();
	}

	return true;
}
//----------------------------------------------------------------------------
void CurveCtrlFloat3Axis::OnCtrlChanged (bool updateCurve)
{
	if (!mCurveFloat3Axis)
		return;

	if (!mCurveFloat3Axis->mCurve)
		return;

	if (mIndex >= (int)mCurveFloat3Axis->mCurve->Points.size())
	{
		return;
	}

	int axis = mCurveFloat3Axis->GetAxis();

	float inVal = mCurveFloat3Axis->mCurve->Points[mIndex].InVal;
	Float3 outVal = mCurveFloat3Axis->mCurve->Points[mIndex].OutVal;
	Float3 arriveTangent = mCurveFloat3Axis->mCurve->Points[mIndex].ArriveTangent;
	Float3 leaveTangent = mCurveFloat3Axis->mCurve->Points[mIndex].LeaveTangent;
	InterpCurveMode mode = mCurveFloat3Axis->mCurve->Points[mIndex].InterpMode;

	mInVal = inVal;
	mOutVal = Float3(inVal, 0.0f, outVal[axis]);

	AVector at(1.0f, 0.0f, arriveTangent[axis]);
	at.Normalize();
	mArriveTangent = at;

	AVector lt (1.0f, 0.0f, leaveTangent[axis]);
	lt.Normalize();
	mLeaveTangent = lt;

	mInterpCurveMode = mode;

	CurveCtrl::OnCtrlChanged(updateCurve);
}
//----------------------------------------------------------------------------