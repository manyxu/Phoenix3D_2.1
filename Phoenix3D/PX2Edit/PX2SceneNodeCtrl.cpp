// PX2SceneNodeCtrl.cpp

#include "PX2SceneNodeCtrl.hpp"
#include "PX2Edit.hpp"
#include "PX2GeoObjFactory.hpp"
#include "PX2Project.hpp"
#include "PX2EditEventType.hpp"
#include "PX2Time.hpp"
#include "PX2Renderer.hpp"
#include "PX2Picker.hpp"
#include "PX2RenderStep.hpp"
#include "PX2Selection.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2TriMesh.hpp"
#include "PX2SimulationEventType.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
SceneNodeCtrl::SceneNodeCtrl()
{
	mOriginScale = 1.0f;

	GeoObjFactory factory;
	mCtrl_P_Translate = factory.CreateTranslateCtrl_P();
	mCtrl_P_Rolate = factory.CreateRolateCtrl_P();
	mCtrl_P_Scale = factory.CreateScaleCtrl_P();
	mCtrl_O_Translate = factory.CreateTranslateCtrl_O();
	mCtrl_O_Rolate = factory.CreateRolateCtrl_O();
	mCtrl_O_Scale = factory.CreateScaleCtrl_O();
	PX2::NodePtr nodeEmpty = new0 PX2::Node();

	mCtrlsGroup = new0 SwitchNode();
	mCtrlsGroup->WorldTransformIsCurrent = true;
	mOriginScale = mCtrlsGroup->WorldTransform.GetUniformScale();
	mCtrlsGroup->AttachChild(mCtrl_P_Translate);
	mCtrlsGroup->AttachChild(mCtrl_P_Rolate);
	mCtrlsGroup->AttachChild(mCtrl_P_Scale);
	mCtrlsGroup->AttachChild(mCtrl_O_Translate);
	mCtrlsGroup->AttachChild(mCtrl_O_Rolate);
	mCtrlsGroup->AttachChild(mCtrl_O_Scale);
	mCtrlsGroup->AttachChild(nodeEmpty);

	mLookType = LT_PERSPECTIVE;
	mCtrlType = CT_SELECT;
	mDragType = DT_NONE;
}
//----------------------------------------------------------------------------
SceneNodeCtrl::~SceneNodeCtrl()
{
	PX2_EW.GoOut(this);
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::SetAxisMode(SceneNodeCtrl::AxisMode mode)
{
	mAxisMode = mode;

	UpdateCtrl();
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::SetLookType(SceneNodeCtrl::LookType type)
{
	mLookType = type;

	UpdateCtrl();
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::SetCtrlType(SceneNodeCtrl::CtrlType type)
{
	mCtrlType = type;

	UpdateCtrl();
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::SetDragType(DragType type)
{
	mDragType = type;
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::OnLeftDown(RenderStep *renderStep, const PX2::APoint &pos)
{
	Edit::EditType editType = PX2_EDIT.GetEditType();
	if (Edit::ET_SCENE != editType) return;

	DragType dt = GetDragType(renderStep, pos);
	SetDragType(dt);
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::OnLeftUp(RenderStep *renderStep, const PX2::APoint &pos)
{
	SetDragType(DT_NONE);

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SceneNodeDrag);
	ent->SetData<int>(0);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::OnMouseWheel(RenderStep *renderStep, float wheelDelta)
{
	Camera *camera = renderStep->GetCamera();
	float rmax = camera->GetRMax();
	APoint camPosition = camera->GetPosition();
	APoint ctrlPosition = GetPosition();
	AVector diff = ctrlPosition - camPosition;
	float diffLength = diff.Length();

	if (mLookType != LT_PERSPECTIVE)
	{
		if (0.0f != rmax)
		{
			mCtrlsGroup->WorldTransform.SetUniformScale(rmax*0.11f);
			mCtrlsGroup->Update(GetTimeInSeconds(), false);
		}
	}
	else
	{
		float scale = diffLength*0.04f;
		if (scale == 0.0f) scale = 0.0001f;
		if (scale < 1.0f) scale = 1.0f;
		mCtrlsGroup->WorldTransform.SetUniformScale(scale);
		mCtrlsGroup->Update(GetTimeInSeconds(), false);
	}
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::OnMotion(bool leftDown, RenderStep *renderStep,
	PX2::APoint posNow, PX2::APoint posBefore)
{
	PX2_UNUSED(leftDown);
	PX2_UNUSED(renderStep);

	Renderer *renderer = renderStep->GetRenderer();
	Camera *camera = renderStep->GetCamera();

	// 光标移动更新
	if (DT_NONE == mDragType)
	{
		GeoObjFactory factory;

		DragType dt = GetDragType(renderStep, posNow);
		Movable *ctrlMov = 0;
		Float4 colorYellowAlpha = Float4(1.0f, 1.0f, 0.0f, 0.3f);

		if (DT_X == dt)
		{
			ctrlMov = GetCurrentCtrlX();
			factory.UpdateCtrlColor(renderer, ctrlMov, Float4::YELLOW);
		}
		else if (DT_Y == dt)
		{
			ctrlMov = GetCurrentCtrlY();
			factory.UpdateCtrlColor(renderer, ctrlMov, Float4::YELLOW);
		}
		else if (DT_Z == dt)
		{
			ctrlMov = GetCurrentCtrlZ();
			factory.UpdateCtrlColor(renderer, ctrlMov, Float4::YELLOW);
		}
		else if (DT_XY == dt)
		{
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlXY(), colorYellowAlpha);
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlYZ(), Float4::ZERO);
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlXZ(), Float4::ZERO);
		}
		else if (DT_YZ == dt)
		{
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlYZ(), colorYellowAlpha);
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlXY(), Float4::ZERO);
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlXZ(), Float4::ZERO);
		}
		else if (DT_XZ == dt)
		{
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlXZ(), colorYellowAlpha);
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlXY(), Float4::ZERO);
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlYZ(), Float4::ZERO);
		}
		else if (DT_XYZ == dt)
		{
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlXYZ(), Float4::YELLOW);
		}
		else if (DT_NONE == dt)
		{
			factory.UpdateCtrlColor(renderer, GetCurrentCtrlX(), Float4::RED);
			factory.UpdateCtrlColor(renderer, GetCurrentCtrlY(), Float4::GREEN);
			factory.UpdateCtrlColor(renderer, GetCurrentCtrlZ(), Float4::BLUE);
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlXY(), Float4::ZERO);
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlYZ(), Float4::ZERO);
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlXZ(), Float4::ZERO);
			factory.UpdateCtrlColor1(renderer, GetCurrentCtrlXYZ(), Float4::WHITE);
		}

		if (DT_NONE == dt)
		{
			Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SceneNodeDrag);
			ent->SetData<int>(0);
			EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
		}
		else
		{
			Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SceneNodeDrag);
			ent->SetData<int>(1);
			EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
		}
	}

	if (DT_NONE == mDragType) return;
	else
	{
		Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SceneNodeDrag);
		ent->SetData<int>(1);
		EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
	}

	int numObjs = PX2_SELECTION.GetNumObjects();
	if (0 == numObjs) 
		return;

	// get pickPoint with the plane
	TriMesh *meshHelp = PX2_GR.GetXYPlane();
	if (DT_X == mDragType)
	{
		if (LT_PERSPECTIVE == mLookType || LT_TOP == mLookType)
			meshHelp = PX2_GR.GetXYPlane();
		else if (LT_FRONT == mLookType)
			meshHelp = PX2_GR.GetXZPlane();
	}
	else if (DT_Y == mDragType)
	{
		meshHelp = PX2_GR.GetXYPlane();
	}
	else if (DT_Z == mDragType)
	{
		AVector cameraDir = camera->GetDVector();
		cameraDir.Normalize();
		float dotVal = Mathf::FAbs(cameraDir.Dot(AVector::UNIT_X));
		if (dotVal > 0.7f)
		{
			meshHelp = PX2_GR.GetYZPlane();
		}
		else
		{
			meshHelp = PX2_GR.GetXZPlane();
		}
	}
	else if (DT_XY == mDragType)
	{
		meshHelp = PX2_GR.GetXYPlane();
	}
	else if (DT_YZ == mDragType)
	{
		meshHelp = PX2_GR.GetYZPlane();
	}
	else if (DT_XZ == mDragType)
	{
		meshHelp = PX2_GR.GetXZPlane();
	}
	else if (DT_XYZ == mDragType)
	{
		meshHelp = PX2_GR.GetXYPlane();
	}
	meshHelp->WorldTransform.SetTranslate(GetPosition());

	// get pick ray
	APoint rayOrigin_Now;
	AVector rayDir_Now;
	renderStep->GetPickRay(posNow.X(), posNow.Z(), rayOrigin_Now, rayDir_Now);

	APoint rayOrigin_Before;
	AVector rayDir_Before;
	renderStep->GetPickRay(posBefore.X(), posBefore.Z(),
		rayOrigin_Before, rayDir_Before);

	// pick
	Picker pickerNow;
	pickerNow.Execute(meshHelp, rayOrigin_Now, rayDir_Now, 0.0f, Mathf::MAX_REAL);
	float lengthNow = pickerNow.GetClosestToZero().T;
	APoint positionNow(rayOrigin_Now + rayDir_Now*lengthNow);

	Picker pickerOrigin;
	pickerOrigin.Execute(meshHelp, rayOrigin_Before, rayDir_Before, 0.0f, Mathf::MAX_REAL);
	float lengthBefore = pickerOrigin.GetClosestToZero().T;
	APoint positionBefore(rayOrigin_Before + rayDir_Before*lengthBefore);

	if (pickerNow.Records.empty() || pickerOrigin.Records.empty()) return;

	AVector transMoved = positionNow - positionBefore;
	AVector transDir = transMoved;
	transDir.Normalize();

	float transValue = 0.0f;
	float transValue1 = 0.0f;
	AVector transVec;
	AVector rolateVec;

	if (DT_X == mDragType)
	{
		transValue = transMoved.Dot(AVector::UNIT_X);
		transVec = AVector::UNIT_X * transValue;

		rolateVec.X() = transMoved.Length() *(1.0f - Mathf::FAbs(transDir.Dot(AVector::UNIT_X)));

		AVector vec = transDir.Cross(AVector::UNIT_X);
		rolateVec.X() *= Mathf::Sign(vec.Z());
	}
	else if (DT_Y == mDragType)
	{
		transValue = transMoved.Dot(AVector::UNIT_Y);
		transVec = AVector::UNIT_Y * transValue;

		rolateVec.Y() = transMoved.Length() *(1.0f - Mathf::FAbs(transDir.Dot(AVector::UNIT_Y)));

		AVector vec = transDir.Cross(AVector::UNIT_Y);
		rolateVec.Y() *= Mathf::Sign(vec.Z());
	}
	else if (DT_Z == mDragType)
	{
		transValue = transMoved.Dot(AVector::UNIT_Z);
		transVec = AVector::UNIT_Z * transValue;

		rolateVec.Z() = transMoved.Length() *(1.0f - Mathf::FAbs(transDir.Dot(AVector::UNIT_Z)));

		rolateVec.Z() *= Mathf::Sign(posNow.X() - posBefore.X());
	}
	else if (DT_XY == mDragType)
	{
		transValue = transMoved.Dot(AVector::UNIT_X);
		transValue1 = transMoved.Dot(AVector::UNIT_Y);
		transVec = AVector::UNIT_X * transValue
			+ AVector::UNIT_Y * transValue1;
	}
	else if (DT_YZ == mDragType)
	{
		transValue = transMoved.Dot(AVector::UNIT_Y);
		transValue1 = transMoved.Dot(AVector::UNIT_Z);
		transVec = AVector::UNIT_Y * transValue
			+ AVector::UNIT_Z * transValue1;
	}
	else if (DT_XZ == mDragType)
	{
		transValue = transMoved.Dot(AVector::UNIT_X);
		transValue1 = transMoved.Dot(AVector::UNIT_Z);
		transVec = AVector::UNIT_X * transValue
			+ AVector::UNIT_Z * transValue1;
	}
	else if (DT_XYZ == mDragType)
	{
		float transValue0 = Mathf::FAbs(transMoved.Dot(AVector::UNIT_X));
		float transValue1 = Mathf::FAbs(transMoved.Dot(AVector::UNIT_Y));
		float transValue2 = Mathf::FAbs(transMoved.Dot(AVector::UNIT_Z));

		float trans = (transValue0 + transValue1 + transValue2) / 3.0f;
		trans *= Mathf::Sign(transMoved.Y());

		transVec = AVector(trans, trans, trans);
	}

	if (CT_TRANSLATE == mCtrlType)
	{
		PX2_SELECTION.Translate(transVec);

		UpdateCtrlTrans();
	}
	else if (CT_ROLATE == mCtrlType)
	{
		PX2_SELECTION.AddRolate(rolateVec);
	}
	else if (CT_SCALE == mCtrlType)
	{
		PX2_SELECTION.AddScale(transVec*0.5f);
	}

	Object *obj = PX2_SELECTION.GetFirstObject();
	if (obj)
	{
		Event *ent = EditEventSpace::CreateEventX(
			EditEventSpace::ObjectTransformChanged);
		ent->SetData<Object*>(obj);
		EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
	}

	mCtrlsGroup->Update(GetTimeInSeconds(), false);
}
//----------------------------------------------------------------------------
PX2::Movable *SceneNodeCtrl::GetCurrentCtrlX()
{
	int index = mCtrlsGroup->GetActiveChild();
	Node *node = DynamicCast<Node>(mCtrlsGroup->GetChild(index));

	if (!node)
		return 0;

	return node->GetChild(0);
}
//----------------------------------------------------------------------------
PX2::Movable *SceneNodeCtrl::GetCurrentCtrlY()
{
	int index = mCtrlsGroup->GetActiveChild();
	Node *node = DynamicCast<Node>(mCtrlsGroup->GetChild(index));

	if (!node)
		return 0;

	return node->GetChild(1);
}
//----------------------------------------------------------------------------
PX2::Movable *SceneNodeCtrl::GetCurrentCtrlZ()
{
	int index = mCtrlsGroup->GetActiveChild();
	Node *node = DynamicCast<Node>(mCtrlsGroup->GetChild(index));

	if (!node)
		return 0;

	return node->GetChild(2);
}
//----------------------------------------------------------------------------
PX2::Movable *SceneNodeCtrl::GetCurrentCtrlXYZ()
{
	if (mCtrlType == CT_SCALE)
	{
		int index = mCtrlsGroup->GetActiveChild();
		Node *node = DynamicCast<Node>(mCtrlsGroup->GetChild(index));

		if (node)
		{
			return node->GetChild(3);
		}

	}

	return 0;
}
//----------------------------------------------------------------------------
PX2::Movable *SceneNodeCtrl::GetCurrentCtrlXY()
{
	int index = mCtrlsGroup->GetActiveChild();
	Node *node = DynamicCast<Node>(mCtrlsGroup->GetChild(index));

	if (node)
	{
		return node->GetChild(3);
	}

	return 0;
}
//----------------------------------------------------------------------------
PX2::Movable *SceneNodeCtrl::GetCurrentCtrlYZ()
{
	int index = mCtrlsGroup->GetActiveChild();
	Node *node = DynamicCast<Node>(mCtrlsGroup->GetChild(index));

	if (node)
	{
		return node->GetChild(4);
	}

	return 0;
}
//----------------------------------------------------------------------------
PX2::Movable *SceneNodeCtrl::GetCurrentCtrlXZ()
{
	int index = mCtrlsGroup->GetActiveChild();
	Node *node = DynamicCast<Node>(mCtrlsGroup->GetChild(index));

	if (node)
	{
		return node->GetChild(5);
	}

	return 0;
}
//----------------------------------------------------------------------------
PX2::APoint SceneNodeCtrl::GetPosition()
{
	return mCtrlsGroup->WorldTransform.GetTranslate();
}
//----------------------------------------------------------------------------
PX2::AVector SceneNodeCtrl::GetXDir()
{
	HPoint vector;
	mCtrlsGroup->WorldTransform.GetRotate().GetRow(0, vector);
	return AVector(vector.X(), vector.Y(), vector.Z());
}
//----------------------------------------------------------------------------
PX2::AVector SceneNodeCtrl::GetYDir()
{
	HPoint vector;
	mCtrlsGroup->WorldTransform.GetRotate().GetRow(1, vector);
	return AVector(vector.X(), vector.Y(), vector.Z());
}
//----------------------------------------------------------------------------
PX2::AVector SceneNodeCtrl::GetZDir()
{
	HPoint vector;
	mCtrlsGroup->WorldTransform.GetRotate().GetRow(2, vector);
	return AVector(vector.X(), vector.Y(), vector.Z());
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::DoEnter()
{
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::DoExecute(PX2::Event *event)
{
	if (SimuES_E::IsEqual(event, SimuES_E::AddSelect))
	{
		UpdateCtrl();
		UpdateCtrlTrans();
	}
	else if (SimuES_E::IsEqual(event, SimuES_E::RemoveSelect))
	{
		UpdateCtrl();
		UpdateCtrlTrans();
	}
	else if (SimuES_E::IsEqual(event, SimuES_E::RemoveAllSelects))
	{
		UpdateCtrl();
	}
	else if (SimuES_E::IsEqual(event, SimuES_E::UnDo) ||
		SimuES_E::IsEqual(event, SimuES_E::ReDo))
	{
		UpdateCtrlTrans();
		UpdateCtrl();
	}
	else if (EditEventSpace::IsEqual(event,
		EditEventSpace::ObjectTransformChanged))
	{
		UpdateCtrlTrans();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::SetEditMode))
	{
		Edit::EditMode mode = PX2_EDIT.GetEditMode();

		if (Edit::EM_SELECT == mode)
		{
			SetCtrlType(SceneNodeCtrl::CT_SELECT);
		}
		else if (Edit::EM_TRANSLATE == mode)
		{
			SetCtrlType(SceneNodeCtrl::CT_TRANSLATE);
		}
		else if (Edit::EM_ROLATE == mode)
		{
			SetCtrlType(SceneNodeCtrl::CT_ROLATE);
		}
		else if (Edit::EM_SCALE == mode)
		{
			SetCtrlType(SceneNodeCtrl::CT_SCALE);
		}
	}
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::DoLeave()
{
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::UpdateCtrl()
{
	int numObjects = PX2_SELECTION.GetNumObjects();

	bool isObjectsHasActorOrMov = false;

	for (int i = 0; i < numObjects; i++)
	{
		Object *obj = PX2_SELECTION.GetObjectAt(i);
		Movable *mov = DynamicCast<Movable>(obj);
		if (mov)
		{
			isObjectsHasActorOrMov = true;
		}
	}

	if (isObjectsHasActorOrMov)
	{
		if (mCtrlType == CT_SELECT)
		{
			mCtrlsGroup->SetActiveChild(6);
		}
		else if (mCtrlType == CT_TRANSLATE)
		{
			if (mLookType == LT_PERSPECTIVE)
			{
				mCtrlsGroup->SetActiveChild(0);
				GetCurrentCtrlX()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlY()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlZ()->Culling = Movable::CULL_DYNAMIC;
			}
			else
			{
				mCtrlsGroup->SetActiveChild(3);
				GetCurrentCtrlX()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlY()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlZ()->Culling = Movable::CULL_DYNAMIC;

				if (mLookType == LT_TOP)
				{
					GetCurrentCtrlZ()->Culling = Movable::CULL_ALWAYS;
				}
				else if (mLookType == LT_FRONT)
				{
					GetCurrentCtrlY()->Culling = Movable::CULL_ALWAYS;
				}
				else if (mLookType == LT_LEFT)
				{
					GetCurrentCtrlX()->Culling = Movable::CULL_ALWAYS;
				}
			}
		}
		else if (mCtrlType == CT_ROLATE)
		{
			if (mLookType == LT_PERSPECTIVE)
			{
				mCtrlsGroup->SetActiveChild(1);
				GetCurrentCtrlX()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlY()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlZ()->Culling = Movable::CULL_DYNAMIC;
			}
			else
			{
				mCtrlsGroup->SetActiveChild(4);
				GetCurrentCtrlX()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlY()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlZ()->Culling = Movable::CULL_DYNAMIC;

				if (mLookType == LT_TOP)
				{
					GetCurrentCtrlZ()->Culling = Movable::CULL_ALWAYS;
				}
				else if (mLookType == LT_FRONT)
				{
					GetCurrentCtrlY()->Culling = Movable::CULL_ALWAYS;
				}
				else if (mLookType == LT_LEFT)
				{
					GetCurrentCtrlX()->Culling = Movable::CULL_ALWAYS;
				}
			}

			mCtrlsGroup->Update(GetTimeInSeconds(), false);
		}
		else if (mCtrlType == CT_SCALE)
		{
			if (mLookType == LT_PERSPECTIVE)
			{
				mCtrlsGroup->SetActiveChild(2);
				GetCurrentCtrlX()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlY()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlZ()->Culling = Movable::CULL_DYNAMIC;
			}
			else
			{
				mCtrlsGroup->SetActiveChild(5);
				GetCurrentCtrlX()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlY()->Culling = Movable::CULL_DYNAMIC;
				GetCurrentCtrlZ()->Culling = Movable::CULL_DYNAMIC;

				if (mLookType == LT_TOP)
				{
					GetCurrentCtrlZ()->Culling = Movable::CULL_ALWAYS;
				}
				else if (mLookType == LT_FRONT)
				{
					GetCurrentCtrlY()->Culling = Movable::CULL_ALWAYS;
				}
				else if (mLookType == LT_LEFT)
				{
					GetCurrentCtrlX()->Culling = Movable::CULL_ALWAYS;
				}
			}
		}
	}
	else
	{
		mCtrlsGroup->SetActiveChild(6);
	}

	mCtrlsGroup->Update(GetTimeInSeconds(), false);
}
//----------------------------------------------------------------------------
void SceneNodeCtrl::UpdateCtrlTrans()
{
	int numObjects = PX2_SELECTION.GetNumObjects();

	bool isObjectsHasActorOrMov = false;

	for (int i = 0; i < numObjects; i++)
	{
		Object *obj = PX2_SELECTION.GetObjectAt(i);
		Movable *mov = DynamicCast<Movable>(obj);
		if (mov)
		{
			isObjectsHasActorOrMov = true;
		}
	}

	if (isObjectsHasActorOrMov)
	{
		APoint pos;

		for (int i = 0; i < numObjects; i++)
		{
			Object *obj = PX2_SELECTION.GetObjectAt(i);
			Movable *mov = DynamicCast<Movable>(obj);
			
			if (mov)
			{
				pos += mov->WorldTransform.GetTranslate();
			}
		}

		pos /= (float)numObjects;

		mCtrlsGroup->WorldTransform.SetTranslate(pos);
	}
	else
	{
		mCtrlsGroup->SetActiveChild(6);
	}

	mCtrlsGroup->Update(GetTimeInSeconds(), false);
}
//----------------------------------------------------------------------------
SceneNodeCtrl::DragType SceneNodeCtrl::GetDragType(RenderStep *renderStep,
	const PX2::APoint &point)
{
	APoint origin;
	AVector direction;
	renderStep->GetPickRay((int)point.X(), (int)point.Z(), origin, direction);

	PX2::Picker picker;

	PX2::Movable *ctrlX = GetCurrentCtrlX();
	PX2::Movable *ctrlY = GetCurrentCtrlY();
	PX2::Movable *ctrlZ = GetCurrentCtrlZ();
	PX2::Movable *ctrlXYZ = GetCurrentCtrlXYZ();
	PX2::Movable *ctrlXY = GetCurrentCtrlXY();
	PX2::Movable *ctrlYZ = GetCurrentCtrlYZ();
	PX2::Movable *ctrlXZ = GetCurrentCtrlXZ();

	bool xDrag = false;
	float xDragT = Mathf::MAX_REAL;

	bool yDrag = false;
	float yDragT = Mathf::MAX_REAL;

	bool zDrag = false;
	float zDragT = Mathf::MAX_REAL;

	bool xyzDrag = false;
	float xyzDragT = Mathf::MAX_REAL;

	bool xyDrag = false;
	float xyDragT = Mathf::MAX_REAL;

	bool yzDrag = false;
	float yzDragT = Mathf::MAX_REAL;

	bool xzDrag = false;
	float xzDragT = Mathf::MAX_REAL;

	GetCtrlsGroup()->Update(GetTimeInSeconds(), false);

	picker.Execute(ctrlX, origin, direction, -Mathf::MAX_REAL, Mathf::MAX_REAL);
	if ((int)picker.Records.size() > 0)
	{
		xDrag = true;
		xDragT = picker.GetClosestNonnegative().T;
	}

	picker.Execute(ctrlY, origin, direction, -Mathf::MAX_REAL, Mathf::MAX_REAL);
	if ((int)picker.Records.size() > 0)
	{
		yDrag = true;
		yDragT = picker.GetClosestNonnegative().T;
	}

	picker.Execute(ctrlZ, origin, direction, -Mathf::MAX_REAL, Mathf::MAX_REAL);
	if ((int)picker.Records.size() > 0)
	{
		zDrag = true;
		zDragT = picker.GetClosestNonnegative().T;
	}

	picker.Execute(ctrlXYZ, origin, direction, -Mathf::MAX_REAL, Mathf::MAX_REAL);
	if ((int)picker.Records.size() > 0)
	{
		xyzDrag = true;
		xyzDragT = picker.GetClosestNonnegative().T;
	}

	picker.Execute(ctrlXY, origin, direction, -Mathf::MAX_REAL, Mathf::MAX_REAL);
	if ((int)picker.Records.size() > 0)
	{
		xyDrag = true;
		xyDragT = picker.GetClosestNonnegative().T;
	}

	picker.Execute(ctrlYZ, origin, direction, -Mathf::MAX_REAL, Mathf::MAX_REAL);
	if ((int)picker.Records.size() > 0)
	{
		yzDrag = true;
		yzDragT = picker.GetClosestNonnegative().T;
	}

	picker.Execute(ctrlXZ, origin, direction, -Mathf::MAX_REAL, Mathf::MAX_REAL);
	if ((int)picker.Records.size() > 0)
	{
		xzDrag = true;
		xzDragT = picker.GetClosestNonnegative().T;
	}

	if (xDrag)
		return DT_X;
	else if (yDrag)
		return DT_Y;
	else if (zDrag)
		return DT_Z;
	else if (xyzDrag)
		return DT_XYZ;
	else if (xyDrag)
		return DT_XY;
	else if (yzDrag)
		return DT_YZ;
	else if (xzDrag)
		return DT_XZ;

	return DT_NONE;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
BoundCtrl::BoundCtrl()
{
	GeoObjFactory factory;
	mCtrlsGroup = new0 SwitchNode();
	mCtrlsGroup->WorldTransformIsCurrent = true;
	mBoundNode = factory.CreateBound();
	mCtrlsGroup->AttachChild(mBoundNode);
	mCtrlsGroup->AttachChild(new0 Node());
}
//----------------------------------------------------------------------------
BoundCtrl::~BoundCtrl()
{
}
//----------------------------------------------------------------------------
void BoundCtrl::DoEnter()
{
}
//----------------------------------------------------------------------------
void BoundCtrl::DoExecute(PX2::Event *event)
{
	if (SimuES_E::IsEqual(event, SimuES_E::AddSelect))
	{
		UpdateCtrl();
	}
	else if (SimuES_E::IsEqual(event, SimuES_E::RemoveObject))
	{
		UpdateCtrl();
	}
	else if (SimuES_E::IsEqual(event, SimuES_E::RemoveAllSelects))
	{
		UpdateCtrl();
	}
	else if (EditEventSpace::IsEqual(event, EditEventSpace::ObjectTransformChanged))
	{
		UpdateCtrl();
	}
	else if (SimuES_E::IsEqual(event, SimuES_E::UnDo) || 
		SimuES_E::IsEqual(event, SimuES_E::ReDo))
	{
		UpdateCtrl();
	}
	else if (SimuES_E::IsEqual(event, SimuES_E::SetRadius))
	{
		UpdateCtrl();
	}
}
//----------------------------------------------------------------------------
void BoundCtrl::DoLeave()
{
}
//----------------------------------------------------------------------------
void BoundCtrl::UpdateCtrl()
{
	mCtrlsGroup->SetActiveChild(1);

	int numObjscts = PX2_SELECTION.GetNumObjects();

	if (numObjscts > 0)
	{
		Bound bound;
		int firstBound = true;

		APoint pos;

		for (int i = 0; i < numObjscts; i++)
		{
			Object *obj = PX2_SELECTION.GetObjectAt(i);
			Actor *actor = DynamicCast<Actor>(obj);
			Movable *movable = DynamicCast<Movable>(obj);

			if (movable)
			{
				mCtrlsGroup->SetActiveChild(0);
				pos += movable->WorldTransform.GetTranslate();

				if (0.0f != movable->WorldBound.GetRadius())
				{
					if (firstBound)
					{
						bound = movable->WorldBound;
						firstBound = false;
					}
					else
					{
						bound.GrowToContain(movable->WorldBound);
					}
				}
			}
		}

		pos = pos / (float)numObjscts;

		float radius = bound.GetRadius();
		if (0.0f == radius)
		{
			radius = 1.0f;

			mCtrlsGroup->WorldTransform.SetUniformScale(radius);
			mCtrlsGroup->WorldTransform.SetTranslate(pos);
		}
		else
		{
			mCtrlsGroup->WorldTransform.SetUniformScale(radius);
			mCtrlsGroup->WorldTransform.SetTranslate(bound.GetCenter());
		}
	}
	else
	{
		mCtrlsGroup->SetActiveChild(1);
	}

	mCtrlsGroup->Update(GetTimeInSeconds(), false);
}
//----------------------------------------------------------------------------