// PX2EditRenderView.cpp

#include "PX2EditRenderView.hpp"
#include "PX2EditParams.hpp"
#include "PX2VertexFormat.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2Project.hpp"
#include "PX2Time.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditRenderView::EditRenderView() :
mViewType(VT_PERSPECTIVE),
mViewDetail(VD_TEXTURED)
{
	_CreateGridGeometry();
}
//----------------------------------------------------------------------------
EditRenderView::~EditRenderView()
{
	if (mRenderStep)
	{
		PX2_GR.RemoveRenderStep(mRenderStep);
	}
}
//----------------------------------------------------------------------------
RenderStep *EditRenderView::GetRenderStep()
{
	return mRenderStep;
}
//----------------------------------------------------------------------------
void EditRenderView::_CreateGridGeometry()
{
	float gridSize = EditParams::GetSingleton().GridSize;

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

	mRenderStep = new0 RenderStep();
	mRenderStep->SetNode(mGridNode);
	PX2_GR.AddRenderStep(mRenderStep);
}
//----------------------------------------------------------------------------
void EditRenderView::OnMoveHV(bool isAltDown, float h, float v)
{
	if (VT_PERSPECTIVE == mViewType)
	{
		if (isAltDown)
		{
			_MoveCamera(h, v);
		}
		else
		{
			_ZoomCamera(v);
			_MoveCamera(h, 0.0f);
		}
	}
	else if (VT_TOP == mViewType)
	{
		_MoveCamera(h, v);
	}
	else if (VT_FRONT == mViewType)
	{
		_MoveCamera(h, -v);
	}
}
//----------------------------------------------------------------------------
void EditRenderView::_MoveCamera(float horz, float vert)
{
	Scene *scene = PX2_PROJ.GetScene();
	CameraActor *camActor = scene->GetUseCameraActor();
	
	if (camActor)
	{
		Vector3f position = camActor->LocalTransform.GetTranslate();
		const HMatrix &rotMat = camActor->LocalTransform.GetRotate();
		HPoint r, d, u;
		rotMat.GetColumn(0, r);
		rotMat.GetColumn(1, d);
		rotMat.GetColumn(2, u);

		AVector dVector = AVector(d[0], d[1], d[2]);
		AVector uVector = AVector(u[0], u[1], u[2]);
		AVector rVector = AVector(r[0], r[1], r[2]);

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
void EditRenderView::_ZoomCamera(float zoom)
{
	RenderStep *renderStep = PX2_PROJ.GetSceneRenderStep();
	const Sizef &size = renderStep->GetSize();

	Scene *scene = PX2_PROJ.GetScene();
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