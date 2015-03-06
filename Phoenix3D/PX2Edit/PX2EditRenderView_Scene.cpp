// PX2EditRenderView.cpp

#include "PX2EditRenderView_Scene.hpp"
#include "PX2EditParams.hpp"
#include "PX2VertexFormat.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2Project.hpp"
#include "PX2Time.hpp"
#include "PX2Selection.hpp"
#include "PX2Edit.hpp"
#include "PX2ActorPicker.hpp"
#include "PX2EventWorld.hpp"
#include "PX2EditEventType.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditRenderView_Scene::EditRenderView_Scene() :
EditRenderView(0),
mViewType(VT_PERSPECTIVE),
mViewDetail(VD_TEXTURED)
{
	_CreateGridGeometry();
	_CreateNodeCtrl();

	Edit::EditType editType = PX2_EDIT.GetEditType();
	Enable(editType != Edit::ET_UI);
}
//----------------------------------------------------------------------------
EditRenderView_Scene::~EditRenderView_Scene()
{
	// do not remove scene renderstep
	//if (mRenderStep)
	//{
	//	PX2_GR.RemoveRenderStep(mRenderStep);
	//	mRenderStep = 0;
	//}

	if (mRenderStepCtrl)
	{
		PX2_GR.RemoveRenderSteps(mRenderStepCtrl);
		mRenderStepCtrl = 0;
	}

	if (mRenderStepCtrl1)
	{
		PX2_GR.RemoveRenderSteps(mRenderStepCtrl1);
		mRenderStepCtrl1 = 0;
	}

	if (mSceneNodeCtrl)
	{
		PX2_EW.GoOut(mSceneNodeCtrl);
	}

	if (mBoundCtrl)
	{
		PX2_EW.GoOut(mBoundCtrl);
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::_CreateGridGeometry()
{
	float gridSize = PX2_EDIT.GetEditParams()->GridSize;

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);

	StandardMesh sM(vf);
	mGrid = sM.LineRectangleForEditor(81, 81, gridSize, gridSize,
		Float4(0.43f, 0.43f, 0.43f, 0.7f));

	PX2::RenderablePtr mGridAxis;
	PX2::VertexBufferAccessor mGridAxisAssessor;

	VertexBuffer *vb = new0 VertexBuffer(4, vf->GetStride(), Buffer::BU_DYNAMIC);
	VertexBufferAccessor vba;

	vba.ApplyTo(vf, vb);
	vba.Position<Float3>(0) = Float3(-gridSize, 0.0f, 0.0f);
	vba.Color<Float4>(0, 0) = Float4::RED;
	vba.Position<Float3>(1) = Float3(gridSize, 0.0f, 0.0f);
	vba.Color<Float4>(0, 1) = Float4::RED;

	vba.Position<Float3>(2) = Float3(0.0f, -gridSize, 0.0f);
	vba.Color<Float4>(0, 2) = Float4::GREEN;
	vba.Position<Float3>(3) = Float3(0.0f, gridSize, 0.0f);
	vba.Color<Float4>(0, 3) = Float4::GREEN;

	mGridAxis = new0 Polysegment(vf, vb, false);
	mGridAxis->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);

	VertexColor4MaterialPtr mtl = new0 VertexColor4Material();
	mtl->GetAlphaProperty(0, 0)->BlendEnabled = true;

	mGrid->SetMaterialInstance(mtl->CreateInstance());
	mGridAxis->SetMaterialInstance(mtl->CreateInstance());

	mGridNode = new0 Node();
	mGridNode->AttachChild(mGridAxis);
	mGridNode->AttachChild(mGrid);
	mGridNode->Update(GetTimeInSeconds(), true);

	mRenderStepCtrl = new0 RenderStep();
	mRenderStepCtrl->SetPriority(30);
	mRenderStepCtrl->SetName("SceneGridRenderStep");
	mRenderStepCtrl->SetNode(mGridNode);
	PX2_GR.AddRenderStep(mRenderStepCtrl->GetName().c_str(), mRenderStepCtrl);
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::_ClickSelect(const APoint &scrPos)
{
	SelectMode mode = SM_SINGLE;
	if (PX2_EDIT.IsCtrlDown) mode = SM_MULTI;

	Edit::EditType editType = PX2_EDIT.GetEditType();

	if (Edit::ET_SCENE == editType)
	{
		_ClickSelectScene(scrPos, mode);
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::_ClickSelectScene(const APoint &scrPos,
	SelectMode mode)
{
	Scene *scene = PX2_PROJ.GetScene();
	RenderStep *renderStep = PX2_PROJ.GetSceneRenderStep();

	// pre
	std::map<Actor*, bool> actorsPickable;
	for (int i = 0; i < scene->GetNumChildren(); i++)
	{
		Actor *actor = DynamicCast<Actor>(scene->GetChild(i));
		if (actor)
		{
			actorsPickable[actor] = actor->IsPickable();
			actor->SetPickable(true);
		}
	}

	APoint origin;
	AVector direction;
	renderStep->GetPickRay(scrPos.X(), scrPos.Z(), origin, direction);

	ActorPicker actorPicker;
	actorPicker.Execute(scene, origin, direction, 0.0f, Mathf::MAX_REAL);

	// post
	std::map<Actor*, bool>::iterator it = actorsPickable.begin();
	for (; it != actorsPickable.end(); it++)
	{
		Actor *actor = it->first;
		actor->SetPickable(it->second);
	}
	actorsPickable.clear();

	if (actorPicker.Records.size() > 0)
	{
		const ActorPickRecord &record = actorPicker.GetClosestToZero();
		Object *recordObj = record.Intersected;
		mSelectPoint = origin + direction*record.T;
		PX2_EDIT.SetPickPos(mSelectPoint);

		if (SM_SINGLE == mode)
		{
			int numObjs = PX2_SELECTION.GetNumObjects();
			if (1 == numObjs && recordObj==PX2_SELECTION.GetFirstObject())
			{
				/*_*/;
			}
			else
			{
				PX2_SELECTION.Clear();
				PX2_SELECTION.AddObject(recordObj);
			}
		}
		else if (SM_MULTI == mode)
		{
			if (PX2_SELECTION.IsObjectIn(recordObj))
			{
				PX2_SELECTION.RemoveObject(recordObj);
			}
			else
			{
				PX2_SELECTION.AddObject(recordObj);
			}
		}
	}
	else
	{
		if (SM_SINGLE == mode)
		{
			PX2_SELECTION.Clear();
		}
	}

	SelectMode mode = SM_SINGLE;
	if (PX2_EDIT.IsCtrlDown) mode = SM_MULTI;
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::_ClickSelectPos(const APoint &scrPos)
{
	Scene *scene = PX2_PROJ.GetScene();
	RenderStep *renderStep = PX2_PROJ.GetSceneRenderStep();

	APoint origin;
	AVector direction;
	renderStep->GetPickRay(scrPos.X(), scrPos.Z(), origin, direction);

	ActorPicker actorPicker;
	actorPicker.Execute(scene, origin, direction, 0.0f, Mathf::MAX_REAL);

	if (actorPicker.Records.size() > 0)
	{
		const ActorPickRecord &record = actorPicker.GetClosestToZero();
		mSelectPoint = origin + direction*record.T;
		PX2_EDIT.SetPickPos(mSelectPoint);
	}
	else
	{
		PX2::TriMesh *xyPlane = PX2_GR.GetXYPlane();
		xyPlane->LocalTransform.SetTranslateZ(0.0f);

		Picker picker;
		picker.Execute(xyPlane, origin, direction, 0.0f, Mathf::MAX_REAL);
		if ((int)picker.Records.size() > 0)
		{
			const PickRecord &rec = picker.GetClosestToZero();
			mSelectPoint = origin + direction*rec.T;
			PX2_EDIT.SetPickPos(mSelectPoint);
		}
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::OnSize(const Sizef& size)
{
	EditRenderView::OnSize(size);
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::OnLeftDown(const APoint &pos)
{
	EditRenderView::OnLeftDown(pos);

	if (mSceneNodeCtrl)
		mSceneNodeCtrl->OnLeftDown(mRenderStepCtrl, pos);

	SceneNodeCtrl::DragType dargType = mSceneNodeCtrl->GetDragType();
	if (SceneNodeCtrl::DT_NONE == dargType)
		_ClickSelect(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::OnLeftUp(const APoint &pos)
{
	EditRenderView::OnLeftUp(pos);

	if (mSceneNodeCtrl)
		mSceneNodeCtrl->OnLeftUp(mRenderStepCtrl, pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::OnMiddleDown(const APoint &pos)
{
	EditRenderView::OnMiddleDown(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::OnMiddleUp(const APoint &pos)
{
	if (!IsEnable()) return;

	EditRenderView::OnMiddleUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::OnMouseWheel(float delta)
{
	EditRenderView::OnMouseWheel(delta);

	float delta1 = delta * 0.03f;
	if (PX2_EDIT.IsShiftDown) delta1 *= 2.0f;

	_ZoomCamera(delta1);

	if (mSceneNodeCtrl)
		mSceneNodeCtrl->OnMouseWheel(mRenderStepCtrl, delta);
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::OnRightDown(const APoint &pos)
{
	EditRenderView::OnRightDown(pos);

	_ClickSelectPos(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::OnRightUp(const APoint &pos)
{
	EditRenderView::OnRightUp(pos);
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::OnMotion(const APoint &pos)
{
	if (!IsEnable()) return;

	APoint curPos = pos;
	APoint lastPos = mLastMousePoint;
	AVector delta = curPos - lastPos;
	mLastMousePoint = curPos;

	if (delta == AVector::ZERO) return;

	if (mIsMiddleDown || mIsRightDown)
	{
		float speedVal = 3.0f;
		if (PX2_EDIT.IsShiftDown) speedVal *= 2.0f;

		if (VT_PERSPECTIVE == mViewType)
		{
			if (PX2_EDIT.IsAltDown)
			{
				_RolateCamera(delta.X()*mPixelToWorld.first*speedVal*0.25f, -delta.Z()*mPixelToWorld.second*speedVal*0.25f);
			}
			else if (PX2_EDIT.IsCtrlDown)
			{
				Movable *mov = DynamicCast<Movable>(PX2_SELECTION.GetFirstObject());
				if (mov)
				{
					_RoundCamera(delta.X()*speedVal*0.02f, -delta.Z()*speedVal*0.02f);
				}
				else
				{
					_PanCamera(-delta.X()*mPixelToWorld.first*speedVal, delta.Z()*mPixelToWorld.second*speedVal);
				}
			}
			else
			{
				_PanCamera(-delta.X()*mPixelToWorld.first*speedVal, delta.Z()*mPixelToWorld.second*speedVal);
			}
		}
		else
		{
			_PanCamera(delta.X()*mPixelToWorld.first, delta.Z()*mPixelToWorld.second);
		}
	}

	if (mSceneNodeCtrl)
		mSceneNodeCtrl->OnMotion(mIsLeftDown, mRenderStepCtrl, curPos, lastPos);
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::_MoveCamera(float horz, float vert)
{
	Scene *scene = PX2_PROJ.GetScene();
	if (!scene) return;

	CameraActor *camActor = scene->GetUseCameraActor();

	if (camActor)
	{
		APoint position = camActor->LocalTransform.GetTranslate();
		AVector rVector;
		AVector dVector;
		AVector uVector;
		camActor->GetRDUVector(rVector, dVector, uVector);

		if (mViewType == VT_PERSPECTIVE)
		{
			dVector.Z() = 0.0f;
			dVector.Normalize();
			rVector.Z() = 0.0f;
			rVector.Normalize();
			position += dVector * vert;
			position -= rVector * horz;
		}
		else if (mViewType == VT_TOP)
		{
			position.Y() += vert * 1.0f;
			position.X() -= horz * 1.0f;
		}
		else if (mViewType == VT_LEFT)
		{
			position.Z() += vert * 1.0f;
			position.Y() += horz * 1.0f;
		}
		else if (mViewType == VT_FRONT)
		{
			position.Z() += vert * 1.0f;
			position.X() -= horz * 1.0f;
		}

		camActor->LocalTransform.SetTranslate(position);
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::_PanCamera(const float &horz, const float &vert)
{
	Scene *scene = PX2_PROJ.GetScene();
	if (!scene) return;

	CameraActor *camActor = scene->GetUseCameraActor();

	if (camActor)
	{
		APoint position = camActor->LocalTransform.GetTranslate();
		AVector rVector;
		AVector dVector;
		AVector uVector;
		camActor->GetRDUVector(rVector, dVector, uVector);

		if (mViewType == VT_PERSPECTIVE)
		{
			rVector.Normalize();
			position += rVector * horz * 5.0f;

			uVector.Normalize();
			position -= uVector * vert * 5.0f;
		}
		else if (mViewType == VT_TOP)
		{
			position.Y() += vert * 1.0f;
			position.X() -= horz * 1.0f;
		}
		else if (mViewType == VT_LEFT)
		{
			position.Z() += vert * 1.0f;
			position.Y() += horz * 1.0f;
		}
		else if (mViewType == VT_FRONT)
		{
			position.Z() += vert * 1.0f;
			position.X() -= horz * 1.0f;
		}
		camActor->LocalTransform.SetTranslate(position);
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::_ZoomCamera(float zoom)
{
	RenderStep *renderStep = PX2_PROJ.GetSceneRenderStep();
	const Sizef &size = renderStep->GetSize();

	Scene *scene = PX2_PROJ.GetScene();
	if (!scene) return;

	CameraActor *camActor = scene->GetUseCameraActor();

	if (camActor)
	{
		APoint position = camActor->LocalTransform.GetTranslate();
		AVector dir = camActor->GetCamera()->GetDVector();
		dir.Normalize();

		if (VT_PERSPECTIVE == mViewType)
		{
			position += dir*zoom;
			camActor->LocalTransform.SetTranslate(position);
		}
		else if (VT_TOP == mViewType)
		{
			float rMin = 0.0f;
			float rMax = 0.0f;
			float uMin = 0.0f;
			float uMax = 0.0f;
			float dMin = 0.0f;
			float dMax = 0.0f;
			float orthoFrustumMin = 1.0f;
			camActor->GetCamera()->GetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);
			uMin += (zoom * 1.0f);
			if (uMin > -orthoFrustumMin)
				uMin = -orthoFrustumMin;
			uMax = -uMin;
			rMin = uMin * size.Width / size.Height;
			rMax = -rMin;

			camActor->GetCamera()->SetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);
		}
		else if (VT_FRONT == mViewType)
		{
			float rMin = 0.0f;
			float rMax = 0.0f;
			float uMin = 0.0f;
			float uMax = 0.0f;
			float dMin = 0.0f;
			float dMax = 0.0f;
			float orthoFrustumMin = 1.0f;
			camActor->GetCamera()->GetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);
			uMin += (zoom * 1.0f);
			if (uMin > -orthoFrustumMin)
				uMin = -orthoFrustumMin;
			uMax = -uMin;
			rMin = uMin * size.Width / size.Height;
			rMax = -rMin;

			camActor->GetCamera()->SetFrustum(dMin, dMax, uMin, uMax, rMin, rMax);
		}
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::_RolateCamera(float horz, float vert)
{
	Scene *scene = PX2_PROJ.GetScene();
	CameraActor *camActor = scene->GetUseCameraActor();

	if (VT_PERSPECTIVE == mViewType)
	{
		AVector rVector;
		AVector dVector;
		AVector uVector;
		camActor->GetRDUVector(rVector, dVector, uVector);

		// horz
		HMatrix incrH(AVector::UNIT_Z, -horz*0.5f);
		dVector = incrH * dVector;
		uVector = incrH * uVector;
		rVector = incrH * rVector;

		// vert
		Matrix3f kIncrV(rVector, -vert*0.5f);
		dVector = kIncrV * dVector;
		uVector = kIncrV * uVector;

		dVector.Normalize();
		float dVectorAdj = dVector.Dot(AVector::UNIT_Z);
		float dVectorAdj1 = dVector.Dot(-AVector::UNIT_Z);
		if (dVectorAdj > 0.9f || dVectorAdj1 > 0.9f)
			return;

		AVector::Orthonormalize(dVector, uVector, rVector);
		camActor->LocalTransform.SetRotate(HMatrix(rVector, dVector,
			uVector, AVector::ZERO, true));
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::_RoundCamera(float horz, float vert)
{
	Scene *scene = PX2_PROJ.GetScene();
	CameraActor *camActor = scene->GetUseCameraActor();

	if (mViewType == VT_PERSPECTIVE)
	{
		PX2::Object *obj = PX2_SELECTION.GetFirstObject();

		bool hasTarget = false;
		APoint pos;
		Movable *mov = DynamicCast<Movable>(obj);
		if (mov)
		{
			pos = mov->LocalTransform.GetTranslate();
			hasTarget = true;
		}

		if (hasTarget)
		{
			const APoint &camPos = camActor->LocalTransform.GetTranslate();
			AVector rVector;
			AVector dVector;
			AVector uVector;
			camActor->GetRDUVector(rVector, dVector, uVector);

			AVector targetDir = pos - camPos;
			float targetLength = targetDir.Normalize();

			// horz
			HMatrix incrH(AVector::UNIT_Z, -horz*0.1f);
			targetDir = incrH * targetDir;
			dVector = incrH * dVector;
			uVector = incrH * uVector;
			rVector = incrH * rVector;

			HMatrix incrV(rVector, -vert*0.1f);
			targetDir = incrV * targetDir;
			dVector = incrV * dVector;
			uVector = incrV * uVector;

			APoint newPos = pos - targetDir*targetLength;
			camActor->LocalTransform.SetTranslate(newPos);

			AVector::Orthonormalize(dVector, uVector, rVector);
			camActor->LocalTransform.SetRotate(
				HMatrix(rVector, dVector, uVector, AVector::ZERO, true));
		}
	}
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::_CreateNodeCtrl()
{
	mSceneNodeCtrl = new0 SceneNodeCtrl();
	PX2_EW.ComeIn(mSceneNodeCtrl);

	mBoundCtrl = new0 BoundCtrl();
	PX2_EW.ComeIn(mBoundCtrl);

	mSceneCtrlNode = new0 Node();
	mSceneCtrlNode->AttachChild(mSceneNodeCtrl->GetCtrlsGroup());
	mSceneCtrlNode->AttachChild(mBoundCtrl->GetCtrlsGroup());
	mSceneCtrlNode->Update(GetTimeInSeconds(), true);

	mRenderStepCtrl1 = new0 RenderStep();
	mRenderStepCtrl1->SetPriority(-5);
	mRenderStepCtrl1->SetDoDepthClear(true);
	mRenderStepCtrl1->SetName("SceneCtrlNodeRenderStep");
	mRenderStepCtrl1->SetNode(mSceneCtrlNode);
	PX2_GR.AddRenderStep(mRenderStepCtrl1->GetName().c_str(), mRenderStepCtrl1);
}
//----------------------------------------------------------------------------
void EditRenderView_Scene::DoExecute(Event *event)
{
	EditRenderView::DoExecute(event);

	if (EditEventSpace::IsEqual(event, EditEventSpace::SetEditType))
	{
		Edit::EditType editType = PX2_EDIT.GetEditType();
		if (editType == Edit::ET_UI)
		{
			Enable(false);
		}
		else
		{
			Enable(true);
		}
	}
}
//----------------------------------------------------------------------------