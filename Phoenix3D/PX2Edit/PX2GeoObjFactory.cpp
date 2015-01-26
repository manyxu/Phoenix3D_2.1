// PX2GeoObjFactory.cpp

#include "PX2GeoObjFactory.hpp"
#include "PX2StandardMesh.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2VertexColor4Material.hpp"
#include "PX2Renderer.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
GeoObjFactory::GeoObjFactory()
{
}
//----------------------------------------------------------------------------
GeoObjFactory::~GeoObjFactory()
{
}
//----------------------------------------------------------------------------
PX2::Node *GeoObjFactory::CreateTranslateCtrl_P()
{
	float radius = 0.065f;
	float height = 0.35f;

	// node
	PX2::Node *node = new0 Node;
	node->LocalTransform.SetUniformScale(2.0f);
	node->SetName("Translate");

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);

	StandardMesh stdMesh(vf);
	VertexBuffer *vBufferTemp = 0;
	VertexBufferAccessor vbaTemp;

	// x
	PX2::Node *nodeX = new0 Node;
	nodeX->SetName("Translate_X");

	VertexBuffer *vBufferX = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaX(vf, vBufferX);

	vbaX.Position<Float3>(0) = Float3(0.25f, 0.0f, 0.0f);
	vbaX.Position<Float3>(1) = Float3(1.125f, 0.0f, 0.0f);
	vbaX.Color<Float4>(0, 0) = Float4::RED;
	vbaX.Color<Float4>(0, 1) = Float4::RED;

	vbaX.Position<Float3>(2) = Float3(0.5f, 0.0f, 0.0f);
	vbaX.Position<Float3>(3) = Float3(0.5f, 0.5f, 0.0f);
	vbaX.Color<Float4>(0, 2) = Float4::RED;
	vbaX.Color<Float4>(0, 3) = Float4::RED;

	vbaX.Position<Float3>(4) = Float3(0.5f, 0.0f, 0.0f);
	vbaX.Position<Float3>(5) = Float3(0.5f, 0.0f, 0.5f);
	vbaX.Color<Float4>(0, 4) = Float4::RED;
	vbaX.Color<Float4>(0, 5) = Float4::RED;

	Polysegment *polysegmentX = new0 PX2::Polysegment(vf, vBufferX,
		false);
	polysegmentX->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeX->AttachChild(polysegmentX);

	TriMesh *meshX = stdMesh.Disk(3, 16, radius);
	meshX->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	meshX->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_Y,
		-Mathf::HALF_PI));
	meshX->LocalTransform.SetTranslate(APoint(1.125f, 0.0f, 0.0f));
	vBufferTemp = meshX->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.5f, 0.0f, 0.0f, 1.0f);
	}
	nodeX->AttachChild(meshX);

	TriFan *fanX = stdMesh.Cone(16, radius, height);
	fanX->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	fanX->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_Y,
		Mathf::HALF_PI));
	fanX->LocalTransform.SetTranslate(APoint(1.125f, 0.0f, 0.0f));
	vBufferTemp = fanX->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4::RED;
	}
	nodeX->AttachChild(fanX);

	// y
	PX2::Node *nodeY = new0 PX2::Node;
	nodeX->SetName("Translate_Y");

	VertexBuffer *vBufferY = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaY(vf, vBufferY);

	vbaY.Position<Float3>(0) = Float3(0.0f, 0.25f, 0.0f);
	vbaY.Position<Float3>(1) = Float3(0.0f, 1.125f, 0.0f);
	vbaY.Color<Float4>(0, 0) = Float4::GREEN;
	vbaY.Color<Float4>(0, 1) = Float4::GREEN;

	vbaY.Position<Float3>(2) = Float3(0.0f, 0.5f, 0.0f);
	vbaY.Position<Float3>(3) = Float3(0.5f, 0.5f, 0.0f);
	vbaY.Color<Float4>(0, 2) = Float4::GREEN;
	vbaY.Color<Float4>(0, 3) = Float4::GREEN;

	vbaY.Position<Float3>(4) = Float3(0.0f, 0.5f, 0.0f);
	vbaY.Position<Float3>(5) = Float3(0.0f, 0.5f, 0.5f);
	vbaY.Color<Float4>(0, 4) = Float4::GREEN;
	vbaY.Color<Float4>(0, 5) = Float4::GREEN;

	Polysegment *polysegmentY = new0 PX2::Polysegment(vf, vBufferY,
		false);
	polysegmentY->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeY->AttachChild(polysegmentY);

	TriMesh *meshY = stdMesh.Disk(3, 16, radius);
	meshY->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	meshY->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_X,
		Mathf::HALF_PI));
	meshY->LocalTransform.SetTranslate(APoint(0.0f, 1.125f, 0.0f));
	vBufferTemp = meshY->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.0f, 0.5f, 0.0f, 1.0f);
	}
	nodeY->AttachChild(meshY);

	TriFan *fanY = stdMesh.Cone(16, radius, height);
	fanY->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	fanY->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_X,
		-Mathf::HALF_PI));
	fanY->LocalTransform.SetTranslate(APoint(0.0f, 1.125f, 0.0f));
	vBufferTemp = fanY->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4::GREEN;
	}
	nodeY->AttachChild(fanY);

	// z
	PX2::Node *nodeZ = new0 PX2::Node();
	nodeX->SetName("Translate_Z");

	VertexBuffer *vBufferZ = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaZ(vf, vBufferZ);

	vbaZ.Position<Float3>(0) = Float3(0.0f, 0.0f, 0.25f);
	vbaZ.Position<Float3>(1) = Float3(0.0f, 0.0f, 1.125f);
	vbaZ.Color<Float4>(0, 0) = Float4::BLUE;
	vbaZ.Color<Float4>(0, 1) = Float4::BLUE;

	vbaZ.Position<Float3>(2) = Float3(0.0f, 0.0f, 0.5f);
	vbaZ.Position<Float3>(3) = Float3(0.5f, 0.0f, 0.5f);
	vbaZ.Color<Float4>(0, 2) = Float4::BLUE;
	vbaZ.Color<Float4>(0, 3) = Float4::BLUE;

	vbaZ.Position<Float3>(4) = Float3(0.0f, 0.0f, 0.5f);
	vbaZ.Position<Float3>(5) = Float3(0.0f, 0.5f, 0.5f);
	vbaZ.Color<Float4>(0, 4) = Float4::BLUE;
	vbaZ.Color<Float4>(0, 5) = Float4::BLUE;

	Polysegment *polysegmentZ = new0 PX2::Polysegment(vf, vBufferZ,
		false);
	polysegmentZ->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeZ->AttachChild(polysegmentZ);

	TriMesh *meshZ = stdMesh.Disk(3, 16, radius);
	meshZ->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	meshZ->LocalTransform.SetTranslate(APoint(.0f, 0.0f, 1.125f));
	meshZ->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_X,
		Mathf::PI));
	vBufferTemp = meshZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.0f, 0.0f, 0.5f, 1.0f);
	}
	nodeZ->AttachChild(meshZ);

	TriFan *fanZ = stdMesh.Cone(16, radius, height);
	fanZ->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	fanZ->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 1.125f));
	vBufferTemp = fanZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4::BLUE;
	}
	nodeZ->AttachChild(fanZ);

	// xy
	PX2::Node *nodeXY = new0 Node;
	nodeXY->SetName("Translate_XY");
	TriMesh *meshXY = stdMesh.Rectangle(2, 2, 0.25f, 0.25f);
	meshXY->LocalTransform.SetTranslate(APoint(0.25f, 0.25f, 0.0f));
	VertexColor4Material *matXY = new0 VertexColor4Material();
	matXY->GetAlphaProperty(0, 0)->BlendEnabled = true;
	matXY->GetCullProperty(0, 0)->Enabled = false;
	meshXY->SetMaterialInstance(matXY->CreateInstance());
	vBufferTemp = meshXY->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(1.0f, 1.0f, 0.0f, 0.0f);
	}
	nodeXY->AttachChild(meshXY);

	// yz
	PX2::Node *nodeYZ = new0 Node;
	nodeYZ->SetName("Translate_YZ");
	TriMesh *meshYZ = stdMesh.Rectangle(2, 2, 0.25f, 0.25f);
	meshYZ->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_Y,
		-Mathf::HALF_PI));
	meshYZ->LocalTransform.SetTranslate(APoint(0.0f, 0.25f, 0.25f));
	VertexColor4Material *matYZ = new0 VertexColor4Material();
	matYZ->GetAlphaProperty(0, 0)->BlendEnabled = true;
	matYZ->GetCullProperty(0, 0)->Enabled = false;
	meshYZ->SetMaterialInstance(matYZ->CreateInstance());
	vBufferTemp = meshYZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(1.0f, 1.0f, 0.0f, 0.0f);
	}
	nodeYZ->AttachChild(meshYZ);

	// xz
	PX2::Node *nodeXZ = new0 Node;
	nodeXZ->SetName("Translate_XZ");
	TriMesh *meshXZ = stdMesh.Rectangle(2, 2, 0.25f, 0.25f);
	meshXZ->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_X,
		-Mathf::HALF_PI));
	meshXZ->LocalTransform.SetTranslate(APoint(0.25f, 0.0f, 0.25f));
	VertexColor4Material *matXZ = new0 VertexColor4Material();
	matXZ->GetAlphaProperty(0, 0)->BlendEnabled = true;
	matXZ->GetCullProperty(0, 0)->Enabled = false;
	meshXZ->SetMaterialInstance(matXZ->CreateInstance());
	vBufferTemp = meshXZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(1.0f, 1.0f, 0.0f, 0.0f);
	}
	nodeXZ->AttachChild(meshXZ);

	// XYZ
	node->AttachChild(nodeX);
	node->AttachChild(nodeY);
	node->AttachChild(nodeZ);
	node->AttachChild(nodeXY);
	node->AttachChild(nodeYZ);
	node->AttachChild(nodeXZ);

	return node;
}
//----------------------------------------------------------------------------
PX2::Node *GeoObjFactory::CreateRolateCtrl_P()
{
	int axisSamples = 4;
	int radialSamples = 12;
	float radial = 0.05f;
	float height = radial*4.0f;

	// node
	PX2::Node *node = new0 Node;
	node->LocalTransform.SetUniformScale(2.0f);
	node->SetName("Rolate");

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	StandardMesh stdMesh(vf);
	VertexBuffer *vBufferTemp = 0;
	VertexBufferAccessor vbaTemp;

	// x
	PX2::Node *nodeX = new0 Node;
	nodeX->SetName("Rolate_X");

	VertexBuffer *vBufferX = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaX(vf, vBufferX);

	vbaX.Position<Float3>(0) = Float3(0.25f, 0.0f, 0.0f);
	vbaX.Position<Float3>(1) = Float3(1.125f, 0.0f, 0.0f);
	vbaX.Color<Float4>(0, 0) = Float4::RED;
	vbaX.Color<Float4>(0, 1) = Float4::RED;

	vbaX.Position<Float3>(2) = Float3(0.5f, 0.0f, 0.0f);
	vbaX.Position<Float3>(3) = Float3(0.5f, 0.5f, 0.0f);
	vbaX.Color<Float4>(0, 2) = Float4::GREEN;
	vbaX.Color<Float4>(0, 3) = Float4::GREEN;

	vbaX.Position<Float3>(4) = Float3(0.5f, 0.0f, 0.0f);
	vbaX.Position<Float3>(5) = Float3(0.5f, 0.0f, 0.5f);
	vbaX.Color<Float4>(0, 4) = Float4::RED;
	vbaX.Color<Float4>(0, 5) = Float4::RED;

	Polysegment *polysegmentX = new0 PX2::Polysegment(vf, vBufferX,
		false);
	polysegmentX->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeX->AttachChild(polysegmentX);

	TriMesh *meshX = stdMesh.Cylinder(axisSamples, radialSamples, radial,
		height, false);
	meshX->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	meshX->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_Y,
		Mathf::HALF_PI));
	meshX->LocalTransform.SetTranslate(APoint(1.125f, 0.0f, 0.0f));
	vBufferTemp = meshX->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4::RED;
	}
	nodeX->AttachChild(meshX);

	// y
	PX2::Node *nodeY = new0 PX2::Node;
	nodeX->SetName("Rolate_Y");

	VertexBuffer *vBufferY = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaY(vf, vBufferY);

	vbaY.Position<Float3>(0) = Float3(0.0f, 0.25f, 0.0f);
	vbaY.Position<Float3>(1) = Float3(0.0f, 1.125f, 0.0f);
	vbaY.Color<Float4>(0, 0) = Float4::GREEN;
	vbaY.Color<Float4>(0, 1) = Float4::GREEN;

	vbaY.Position<Float3>(2) = Float3(0.0f, 0.5f, 0.0f);
	vbaY.Position<Float3>(3) = Float3(0.5f, 0.5f, 0.0f);
	vbaY.Color<Float4>(0, 2) = Float4::GREEN;
	vbaY.Color<Float4>(0, 3) = Float4::GREEN;

	vbaY.Position<Float3>(4) = Float3(0.0f, 0.5f, 0.0f);
	vbaY.Position<Float3>(5) = Float3(0.0f, 0.5f, 0.5f);
	vbaY.Color<Float4>(0, 4) = Float4::GREEN;
	vbaY.Color<Float4>(0, 5) = Float4::GREEN;

	Polysegment *polysegmentY = new0 PX2::Polysegment(vf, vBufferY,
		false);
	polysegmentY->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeY->AttachChild(polysegmentY);

	TriMesh *meshY = stdMesh.Cylinder(axisSamples, radialSamples, radial,
		height, false);
	meshY->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	meshY->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_X,
		Mathf::HALF_PI));
	meshY->LocalTransform.SetTranslate(APoint(0.0f, 1.125f, 0.0f));
	vBufferTemp = meshY->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.0f, 1.0f, 0.0f, 1.0f);
	}
	nodeY->AttachChild(meshY);

	// z
	PX2::Node *nodeZ = new0 PX2::Node();
	nodeX->SetName("Rolate_Z");

	VertexBuffer *vBufferZ = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaZ(vf, vBufferZ);

	vbaZ.Position<Float3>(0) = Float3(0.0f, 0.0f, 0.25f);
	vbaZ.Position<Float3>(1) = Float3(0.0f, 0.0f, 1.125f);
	vbaZ.Color<Float4>(0, 0) = Float4::BLUE;
	vbaZ.Color<Float4>(0, 1) = Float4::BLUE;

	vbaZ.Position<Float3>(2) = Float3(0.0f, 0.0f, 0.5f);
	vbaZ.Position<Float3>(3) = Float3(0.5f, 0.0f, 0.5f);
	vbaZ.Color<Float4>(0, 2) = Float4::BLUE;
	vbaZ.Color<Float4>(0, 3) = Float4::BLUE;

	vbaZ.Position<Float3>(4) = Float3(0.0f, 0.0f, 0.5f);
	vbaZ.Position<Float3>(5) = Float3(0.0f, 0.5f, 0.5f);
	vbaZ.Color<Float4>(0, 4) = Float4::BLUE;
	vbaZ.Color<Float4>(0, 5) = Float4::BLUE;

	Polysegment *polysegmentZ = new0 PX2::Polysegment(vf, vBufferZ,
		false);
	polysegmentZ->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeZ->AttachChild(polysegmentZ);

	TriMesh *meshZ = stdMesh.Cylinder(axisSamples, radialSamples, radial,
		height, false);
	meshZ->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	meshZ->LocalTransform.SetTranslate(APoint(.0f, 0.0f, 1.125f));
	vBufferTemp = meshZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4::BLUE;
	}
	nodeZ->AttachChild(meshZ);

	// XYZ
	node->AttachChild(nodeX);
	node->AttachChild(nodeY);
	node->AttachChild(nodeZ);

	return node;
}
//----------------------------------------------------------------------------
PX2::Node *GeoObjFactory::CreateScaleCtrl_P()
{
	float boxSize = 0.05f;

	// node
	PX2::Node *node = new0 Node;
	node->LocalTransform.SetUniformScale(2.0f);
	node->SetName("Scale");

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	StandardMesh stdMesh(vf);
	VertexBuffer *vBufferTemp = 0;
	VertexBufferAccessor vbaTemp;

	// x
	PX2::Node *nodeX = new0 Node;
	nodeX->SetName("Scale_X");

	VertexBuffer *vBufferX = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaX(vf, vBufferX);

	vbaX.Position<Float3>(0) = Float3(0.25f, 0.0f, 0.0f);
	vbaX.Position<Float3>(1) = Float3(1.125f, 0.0f, 0.0f);
	vbaX.Color<Float4>(0, 0) = Float4::RED;
	vbaX.Color<Float4>(0, 1) = Float4::RED;

	vbaX.Position<Float3>(2) = Float3(0.5f, 0.0f, 0.0f);
	vbaX.Position<Float3>(3) = Float3(0.5f, 0.5f, 0.0f);
	vbaX.Color<Float4>(0, 2) = Float4::RED;
	vbaX.Color<Float4>(0, 3) = Float4::RED;

	vbaX.Position<Float3>(4) = Float3(0.5f, 0.0f, 0.0f);
	vbaX.Position<Float3>(5) = Float3(0.5f, 0.0f, 0.5f);
	vbaX.Color<Float4>(0, 4) = Float4::RED;
	vbaX.Color<Float4>(0, 5) = Float4::RED;

	Polysegment *polysegmentX = new0 PX2::Polysegment(vf, vBufferX,
		false);
	polysegmentX->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeX->AttachChild(polysegmentX);

	TriMesh *meshX = stdMesh.Box(boxSize, boxSize, boxSize);
	meshX->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	meshX->LocalTransform.SetTranslate(APoint(1.125f, 0.0f, 0.0f));
	vBufferTemp = meshX->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4::RED;
	}
	nodeX->AttachChild(meshX);

	// y
	PX2::Node *nodeY = new0 PX2::Node;
	nodeX->SetName("Scale_Y");

	VertexBuffer *vBufferY = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaY(vf, vBufferY);

	vbaY.Position<Float3>(0) = Float3(0.0f, 0.25f, 0.0f);
	vbaY.Position<Float3>(1) = Float3(0.0f, 1.125f, 0.0f);
	vbaY.Color<Float4>(0, 0) = Float4::GREEN;
	vbaY.Color<Float4>(0, 1) = Float4::GREEN;

	vbaY.Position<Float3>(2) = Float3(0.0f, 0.5f, 0.0f);
	vbaY.Position<Float3>(3) = Float3(0.5f, 0.5f, 0.0f);
	vbaY.Color<Float4>(0, 2) = Float4::GREEN;
	vbaY.Color<Float4>(0, 3) = Float4::GREEN;

	vbaY.Position<Float3>(4) = Float3(0.0f, 0.5f, 0.0f);
	vbaY.Position<Float3>(5) = Float3(0.0f, 0.5f, 0.5f);
	vbaY.Color<Float4>(0, 4) = Float4::GREEN;
	vbaY.Color<Float4>(0, 5) = Float4::GREEN;

	Polysegment *polysegmentY = new0 PX2::Polysegment(vf, vBufferY,
		false);
	polysegmentY->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeY->AttachChild(polysegmentY);

	TriMesh *meshY = stdMesh.Box(boxSize, boxSize, boxSize);
	meshY->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	meshY->LocalTransform.SetTranslate(APoint(0.0f, 1.125f, 0.0f));
	vBufferTemp = meshY->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4::GREEN;
	}
	nodeY->AttachChild(meshY);

	// z
	PX2::Node *nodeZ = new0 PX2::Node();
	nodeX->SetName("Scale_Z");

	VertexBuffer *vBufferZ = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaZ(vf, vBufferZ);

	vbaZ.Position<Float3>(0) = Float3(0.0f, 0.0f, 0.25f);
	vbaZ.Position<Float3>(1) = Float3(0.0f, 0.0f, 1.125f);
	vbaZ.Color<Float4>(0, 0) = Float4::BLUE;
	vbaZ.Color<Float4>(0, 1) = Float4::BLUE;

	vbaZ.Position<Float3>(2) = Float3(0.0f, 0.0f, 0.5f);
	vbaZ.Position<Float3>(3) = Float3(0.5f, 0.0f, 0.5f);
	vbaZ.Color<Float4>(0, 2) = Float4::BLUE;
	vbaZ.Color<Float4>(0, 3) = Float4::BLUE;

	vbaZ.Position<Float3>(4) = Float3(0.0f, 0.0f, 0.5f);
	vbaZ.Position<Float3>(5) = Float3(0.0f, 0.5f, 0.5f);
	vbaZ.Color<Float4>(0, 4) = Float4::BLUE;
	vbaZ.Color<Float4>(0, 5) = Float4::BLUE;

	Polysegment *polysegmentZ = new0 PX2::Polysegment(vf, vBufferZ,
		false);
	polysegmentZ->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeZ->AttachChild(polysegmentZ);

	TriMesh *meshZ = stdMesh.Box(boxSize, boxSize, boxSize);
	meshZ->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	meshZ->LocalTransform.SetTranslate(APoint(.0f, 0.0f, 1.125f));
	vBufferTemp = meshZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4::BLUE;
	}
	nodeZ->AttachChild(meshZ);

	// origin
	PX2::Node *nodeXYZ = new0 PX2::Node();
	nodeXYZ->SetName("Scale_XYZ");

	TriMesh *meshXYZ = stdMesh.Box(boxSize, boxSize, boxSize);
	meshXYZ->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	vBufferTemp = meshXYZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(1.0f, 1.0f, 1.0f, 1.0f);
	}
	nodeXYZ->AttachChild(meshXYZ);

	// XYZ
	node->AttachChild(nodeX);
	node->AttachChild(nodeY);
	node->AttachChild(nodeZ);
	node->AttachChild(nodeXYZ);

	return node;
}
//----------------------------------------------------------------------------
PX2::Node *GeoObjFactory::CreateTranslateCtrl_O()
{
	// node
	PX2::Node *node = new0 Node;
	node->LocalTransform.SetUniformScale(2.0f);
	node->SetName("Translate");

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	StandardMesh stdMesh(vf);
	VertexBuffer *vBufferTemp = 0;
	VertexBufferAccessor vbaTemp;

	// x
	PX2::Node *nodeX = new0 Node;
	nodeX->SetName("Translate_X");

	VertexBuffer *vBufferX = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaX(vf, vBufferX);

	vbaX.Position<Float3>(0) = Float3(0.25f, 0.0f, 0.0f);
	vbaX.Position<Float3>(1) = Float3(1.125f, 0.0f, 0.0f);
	vbaX.Color<Float4>(0, 0) = Float4(1.0f, 0.0f, 0.0f, 1.0f);
	vbaX.Color<Float4>(0, 1) = Float4(1.0f, 0.0f, 0.0f, 1.0f);

	vbaX.Position<Float3>(2) = Float3(0.5f, 0.0f, 0.0f);
	vbaX.Position<Float3>(3) = Float3(0.5f, 0.5f, 0.0f);
	vbaX.Color<Float4>(0, 2) = Float4(0.0f, 1.0f, 0.0f, 1.0f);
	vbaX.Color<Float4>(0, 3) = Float4(0.0f, 1.0f, 0.0f, 1.0f);

	vbaX.Position<Float3>(4) = Float3(0.5f, 0.0f, 0.0f);
	vbaX.Position<Float3>(5) = Float3(0.5f, 0.0f, 0.5f);
	vbaX.Color<Float4>(0, 4) = Float4(0.0f, 0.0f, 1.0f, 1.0f);
	vbaX.Color<Float4>(0, 5) = Float4(0.0f, 0.0f, 1.0f, 1.0f);

	Polysegment *polysegmentX = new0 PX2::Polysegment(vf, vBufferX,
		false);
	polysegmentX->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeX->AttachChild(polysegmentX);

	TriMesh *meshX = stdMesh.Disk(3, 20, 0.1f);
	meshX->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//meshX->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	meshX->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_Y,
		-Mathf::HALF_PI));
	meshX->LocalTransform.SetTranslate(APoint(1.125f, 0.0f, 0.0f));
	vBufferTemp = meshX->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(1.0f, 0.0f, 0.0f, 1.0f);
	}
	nodeX->AttachChild(meshX);

	TriFan *fanX = stdMesh.Cone(20, 0.1f, 0.45f);
	fanX->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//fanX->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	fanX->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_Y,
		Mathf::HALF_PI));
	fanX->LocalTransform.SetTranslate(APoint(1.125f, 0.0f, 0.0f));
	vBufferTemp = fanX->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(1.0f, 0.0f, 0.0f, 1.0f);
	}
	nodeX->AttachChild(fanX);

	// y
	PX2::Node *nodeY = new0 PX2::Node;
	nodeX->SetName("Translate_Y");

	VertexBuffer *vBufferY = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaY(vf, vBufferY);

	vbaY.Position<Float3>(0) = Float3(0.0f, 0.25f, 0.0f);
	vbaY.Position<Float3>(1) = Float3(0.0f, 1.125f, 0.0f);
	vbaY.Color<Float4>(0, 0) = Float4(0.0f, 1.0f, 0.0f, 1.0f);
	vbaY.Color<Float4>(0, 1) = Float4(0.0f, 1.0f, 0.0f, 1.0f);

	vbaY.Position<Float3>(2) = Float3(0.0f, 0.5f, 0.0f);
	vbaY.Position<Float3>(3) = Float3(0.5f, 0.5f, 0.0f);
	vbaY.Color<Float4>(0, 2) = Float4(1.0f, 0.0f, 0.0f, 1.0f);
	vbaY.Color<Float4>(0, 3) = Float4(1.0f, 0.0f, 0.0f, 1.0f);

	vbaY.Position<Float3>(4) = Float3(0.0f, 0.5f, 0.0f);
	vbaY.Position<Float3>(5) = Float3(0.0f, 0.5f, 0.5f);
	vbaY.Color<Float4>(0, 4) = Float4(0.0f, 0.0f, 1.0f, 1.0f);
	vbaY.Color<Float4>(0, 5) = Float4(0.0f, 0.0f, 1.0f, 1.0f);

	Polysegment *polysegmentY = new0 PX2::Polysegment(vf, vBufferY,
		false);
	polysegmentY->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeY->AttachChild(polysegmentY);

	TriMesh *meshY = stdMesh.Disk(3, 20, 0.1f);
	meshY->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//meshY->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	meshY->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_X,
		Mathf::HALF_PI));
	meshY->LocalTransform.SetTranslate(APoint(0.0f, 1.125f, 0.0f));
	vBufferTemp = meshY->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.0f, 1.0f, 0.0f, 1.0f);
	}
	nodeY->AttachChild(meshY);

	TriFan *fanY = stdMesh.Cone(20, 0.1f, 0.45f);
	fanY->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//fanY->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	fanY->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_X,
		-Mathf::HALF_PI));
	fanY->LocalTransform.SetTranslate(APoint(0.0f, 1.125f, 0.0f));
	vBufferTemp = fanY->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.0f, 1.0f, 0.0f, 1.0f);
	}
	nodeY->AttachChild(fanY);

	// z
	PX2::Node *nodeZ = new0 PX2::Node();
	nodeX->SetName("Translate_Z");

	VertexBuffer *vBufferZ = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaZ(vf, vBufferZ);

	vbaZ.Position<Float3>(0) = Float3(0.0f, 0.0f, 0.25f);
	vbaZ.Position<Float3>(1) = Float3(0.0f, 0.0f, 1.125f);
	vbaZ.Color<Float4>(0, 0) = Float4(0.0f, 0.0f, 1.0f, 1.0f);
	vbaZ.Color<Float4>(0, 1) = Float4(0.0f, 0.0f, 1.0f, 1.0f);

	vbaZ.Position<Float3>(2) = Float3(0.0f, 0.0f, 0.5f);
	vbaZ.Position<Float3>(3) = Float3(0.5f, 0.0f, 0.5f);
	vbaZ.Color<Float4>(0, 2) = Float4(1.0f, 0.0f, 0.0f, 1.0f);
	vbaZ.Color<Float4>(0, 3) = Float4(1.0f, 0.0f, 0.0f, 1.0f);

	vbaZ.Position<Float3>(4) = Float3(0.0f, 0.0f, 0.5f);
	vbaZ.Position<Float3>(5) = Float3(0.0f, 0.5f, 0.5f);
	vbaZ.Color<Float4>(0, 4) = Float4(0.0f, 1.0f, 0.0f, 1.0f);
	vbaZ.Color<Float4>(0, 5) = Float4(0.0f, 1.0f, 0.0f, 1.0f);

	Polysegment *polysegmentZ = new0 PX2::Polysegment(vf, vBufferZ,
		false);
	polysegmentZ->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeZ->AttachChild(polysegmentZ);

	TriMesh *meshZ = stdMesh.Disk(3, 20, 0.1f);
	meshZ->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//meshZ->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	meshZ->LocalTransform.SetTranslate(APoint(.0f, 0.0f, 1.125f));
	meshZ->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_X,
		Mathf::PI));
	vBufferTemp = meshZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.0f, 0.0f, 1.0f, 1.0f);
	}
	nodeZ->AttachChild(meshZ);

	TriFan *fanZ = stdMesh.Cone(20, 0.1f, 0.45f);
	fanZ->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//fanZ->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	fanZ->LocalTransform.SetTranslate(APoint(0.0f, 0.0f, 1.125f));
	vBufferTemp = fanZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.0f, 0.0f, 1.0f, 1.0f);
	}
	nodeZ->AttachChild(fanZ);

	// xy
	PX2::Node *nodeXY = new0 Node;
	nodeXY->SetName("Translate_XY");
	TriMesh *meshXY = stdMesh.Rectangle(2, 2, 0.25f, 0.25f);
	meshXY->LocalTransform.SetTranslate(APoint(0.25f, 0.25f, 0.0f));
	VertexColor4Material *matXY = new0 VertexColor4Material();
	matXY->GetAlphaProperty(0, 0)->BlendEnabled = true;
	matXY->GetCullProperty(0, 0)->Enabled = false;
	meshXY->SetMaterialInstance(matXY->CreateInstance());
	vBufferTemp = meshXY->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(1.0f, 1.0f, 0.0f, 0.0f);
	}
	nodeXY->AttachChild(meshXY);

	// yz
	PX2::Node *nodeYZ = new0 Node;
	nodeYZ->SetName("Translate_YZ");
	TriMesh *meshYZ = stdMesh.Rectangle(2, 2, 0.25f, 0.25f);
	meshYZ->LocalTransform.SetTranslate(APoint(0.25f, 0.25f, 0.0f));
	meshYZ->LocalTransform.SetRotate(Matrix3f().MakeEulerXYZ(0.0f, -Mathf::HALF_PI, 0.0f));
	VertexColor4Material *matYZ = new0 VertexColor4Material();
	matYZ->GetAlphaProperty(0, 0)->BlendEnabled = true;
	matYZ->GetCullProperty(0, 0)->Enabled = false;
	meshYZ->SetMaterialInstance(matYZ->CreateInstance());
	vBufferTemp = meshYZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(1.0f, 1.0f, 0.0f, 0.0f);
	}
	nodeYZ->AttachChild(meshYZ);

	// xz
	PX2::Node *nodeXZ = new0 Node;
	nodeXZ->SetName("Translate_XZ");
	TriMesh *meshXZ = stdMesh.Rectangle(2, 2, 0.25f, 0.25f);
	meshXZ->LocalTransform.SetRotate(Matrix3f().MakeEulerXYZ(Mathf::HALF_PI, 0.0f, 0.0f));
	meshXZ->LocalTransform.SetTranslate(APoint(0.25f, 0.0f, 0.25f));
	VertexColor4Material *matXZ = new0 VertexColor4Material();
	matXZ->GetAlphaProperty(0, 0)->BlendEnabled = true;
	matXZ->GetCullProperty(0, 0)->Enabled = false;
	meshXZ->SetMaterialInstance(matXZ->CreateInstance());
	vBufferTemp = meshXZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(1.0f, 1.0f, 0.0f, 0.0f);
	}
	nodeXZ->AttachChild(meshXZ);

	// XYZ
	node->AttachChild(nodeX);
	node->AttachChild(nodeY);
	node->AttachChild(nodeZ);
	node->AttachChild(nodeXY);
	node->AttachChild(nodeYZ);
	node->AttachChild(nodeXZ);

	return node;
}
//----------------------------------------------------------------------------
PX2::Node *GeoObjFactory::CreateRolateCtrl_O()
{
	// node
	PX2::Node *node = new0 Node;
	node->LocalTransform.SetUniformScale(2.0f);
	node->SetName("Rolate");

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	StandardMesh stdMesh(vf);
	VertexBuffer *vBufferTemp = 0;
	VertexBufferAccessor vbaTemp;

	// x
	PX2::Node *nodeX = new0 Node;
	nodeX->SetName("Rolate_X");

	TriMesh *meshX = stdMesh.Torus(40, 10, 1.0f, 0.04f);;
	meshX->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//meshX->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	meshX->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_Y,
		-Mathf::HALF_PI));
	vBufferTemp = meshX->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(1.0f, 0.0f, 0.0f, 1.0f);
	}
	nodeX->AttachChild(meshX);

	// y
	PX2::Node *nodeY = new0 PX2::Node;
	nodeX->SetName("Rolate_Y");

	TriMesh *meshY = stdMesh.Torus(40, 10, 1.0f, 0.04f);;
	meshY->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//meshY->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	meshY->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_X,
		Mathf::HALF_PI));
	vBufferTemp = meshY->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.0f, 1.0f, 0.0f, 1.0f);
	}
	nodeY->AttachChild(meshY);

	// z
	PX2::Node *nodeZ = new0 PX2::Node();
	nodeX->SetName("Rolate_Z");

	TriMesh *meshZ = stdMesh.Torus(40, 10, 1.0f, 0.04f);;
	meshZ->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//meshZ->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	meshZ->LocalTransform.SetRotate(HMatrix().MakeRotation(AVector::UNIT_X,
		Mathf::PI));
	vBufferTemp = meshZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.0f, 0.0f, 1.0f, 1.0f);
	}
	nodeZ->AttachChild(meshZ);

	// XYZ
	node->AttachChild(nodeX);
	node->AttachChild(nodeY);
	node->AttachChild(nodeZ);

	return node;
}
//----------------------------------------------------------------------------
PX2::Node *GeoObjFactory::CreateScaleCtrl_O()
{
	// node
	PX2::Node *node = new0 Node;
	node->LocalTransform.SetUniformScale(2.0f);
	node->SetName("Scale");

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	StandardMesh stdMesh(vf);
	VertexBuffer *vBufferTemp = 0;
	VertexBufferAccessor vbaTemp;

	// x
	PX2::Node *nodeX = new0 Node;
	nodeX->SetName("Scale_X");

	VertexBuffer *vBufferX = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaX(vf, vBufferX);

	vbaX.Position<Float3>(0) = Float3(0.25f, 0.0f, 0.0f);
	vbaX.Position<Float3>(1) = Float3(1.125f, 0.0f, 0.0f);
	vbaX.Color<Float4>(0, 0) = Float4(1.0f, 0.0f, 0.0f, 1.0f);
	vbaX.Color<Float4>(0, 1) = Float4(1.0f, 0.0f, 0.0f, 1.0f);

	vbaX.Position<Float3>(2) = Float3(0.5f, 0.0f, 0.0f);
	vbaX.Position<Float3>(3) = Float3(0.5f, 0.5f, 0.0f);
	vbaX.Color<Float4>(0, 2) = Float4(0.0f, 1.0f, 0.0f, 1.0f);
	vbaX.Color<Float4>(0, 3) = Float4(0.0f, 1.0f, 0.0f, 1.0f);

	vbaX.Position<Float3>(4) = Float3(0.5f, 0.0f, 0.0f);
	vbaX.Position<Float3>(5) = Float3(0.5f, 0.0f, 0.5f);
	vbaX.Color<Float4>(0, 4) = Float4(0.0f, 0.0f, 1.0f, 1.0f);
	vbaX.Color<Float4>(0, 5) = Float4(0.0f, 0.0f, 1.0f, 1.0f);

	Polysegment *polysegmentX = new0 PX2::Polysegment(vf, vBufferX,
		false);
	polysegmentX->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeX->AttachChild(polysegmentX);

	TriMesh *meshX = stdMesh.Box(0.06f, 0.06f, 0.06f);
	meshX->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//meshX->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	meshX->LocalTransform.SetTranslate(APoint(1.125f, 0.0f, 0.0f));
	vBufferTemp = meshX->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(1.0f, 0.0f, 0.0f, 1.0f);
	}
	nodeX->AttachChild(meshX);

	// y
	PX2::Node *nodeY = new0 PX2::Node;
	nodeX->SetName("Scale_Y");

	VertexBuffer *vBufferY = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaY(vf, vBufferY);

	vbaY.Position<Float3>(0) = Float3(0.0f, 0.25f, 0.0f);
	vbaY.Position<Float3>(1) = Float3(0.0f, 1.125f, 0.0f);
	vbaY.Color<Float4>(0, 0) = Float4(0.0f, 1.0f, 0.0f, 1.0f);
	vbaY.Color<Float4>(0, 1) = Float4(0.0f, 1.0f, 0.0f, 1.0f);

	vbaY.Position<Float3>(2) = Float3(0.0f, 0.5f, 0.0f);
	vbaY.Position<Float3>(3) = Float3(0.5f, 0.5f, 0.0f);
	vbaY.Color<Float4>(0, 2) = Float4(1.0f, 0.0f, 0.0f, 1.0f);
	vbaY.Color<Float4>(0, 3) = Float4(1.0f, 0.0f, 0.0f, 1.0f);

	vbaY.Position<Float3>(4) = Float3(0.0f, 0.5f, 0.0f);
	vbaY.Position<Float3>(5) = Float3(0.0f, 0.5f, 0.5f);
	vbaY.Color<Float4>(0, 4) = Float4(0.0f, 0.0f, 1.0f, 1.0f);
	vbaY.Color<Float4>(0, 5) = Float4(0.0f, 0.0f, 1.0f, 1.0f);

	Polysegment *polysegmentY = new0 PX2::Polysegment(vf, vBufferY,
		false);
	polysegmentY->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeY->AttachChild(polysegmentY);

	TriMesh *meshY = stdMesh.Box(0.06f, 0.06f, 0.06f);
	meshY->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//meshY->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	meshY->LocalTransform.SetTranslate(APoint(0.0f, 1.125f, 0.0f));
	vBufferTemp = meshY->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.0f, 1.0f, 0.0f, 1.0f);
	}
	nodeY->AttachChild(meshY);

	// z
	PX2::Node *nodeZ = new0 PX2::Node();
	nodeX->SetName("Scale_Z");

	VertexBuffer *vBufferZ = new0 VertexBuffer(6, vf->GetStride());
	VertexBufferAccessor vbaZ(vf, vBufferZ);

	vbaZ.Position<Float3>(0) = Float3(0.0f, 0.0f, 0.25f);
	vbaZ.Position<Float3>(1) = Float3(0.0f, 0.0f, 1.125f);
	vbaZ.Color<Float4>(0, 0) = Float4(0.0f, 0.0f, 1.0f, 1.0f);
	vbaZ.Color<Float4>(0, 1) = Float4(0.0f, 0.0f, 1.0f, 1.0f);

	vbaZ.Position<Float3>(2) = Float3(0.0f, 0.0f, 0.5f);
	vbaZ.Position<Float3>(3) = Float3(0.5f, 0.0f, 0.5f);
	vbaZ.Color<Float4>(0, 2) = Float4(1.0f, 0.0f, 0.0f, 1.0f);
	vbaZ.Color<Float4>(0, 3) = Float4(1.0f, 0.0f, 0.0f, 1.0f);

	vbaZ.Position<Float3>(4) = Float3(0.0f, 0.0f, 0.5f);
	vbaZ.Position<Float3>(5) = Float3(0.0f, 0.5f, 0.5f);
	vbaZ.Color<Float4>(0, 4) = Float4(0.0f, 1.0f, 0.0f, 1.0f);
	vbaZ.Color<Float4>(0, 5) = Float4(0.0f, 1.0f, 0.0f, 1.0f);

	Polysegment *polysegmentZ = new0 PX2::Polysegment(vf, vBufferZ,
		false);
	polysegmentZ->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());
	nodeZ->AttachChild(polysegmentZ);

	TriMesh *meshZ = stdMesh.Box(0.06f, 0.06f, 0.06f);
	meshZ->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	//meshZ->GetMaterialInstance()->GetPass(0)->GetWireProperty()->Enabled = true;
	meshZ->LocalTransform.SetTranslate(APoint(.0f, 0.0f, 1.125f));
	vBufferTemp = meshZ->GetVertexBuffer();
	vbaTemp.ApplyTo(vf, vBufferTemp);
	for (int i = 0; i < vBufferTemp->GetNumElements(); i++)
	{
		vbaTemp.Color<Float4>(0, i) = Float4(0.0f, 0.0f, 1.0f, 1.0f);
	}
	nodeZ->AttachChild(meshZ);

	// XYZ
	node->AttachChild(nodeX);
	node->AttachChild(nodeY);
	node->AttachChild(nodeZ);

	return node;
}
//----------------------------------------------------------------------------
PX2::Node *GeoObjFactory::CreateBound()
{
	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	StandardMesh stdMesh(vf);
	float alpha = 0.5f;
	return stdMesh.CircleSphere(1.0f, 32,
		Float4(1.0f, 0.0f, 0.0f, alpha),
		Float4(0.0f, 1.0f, 0.0f, alpha),
		Float4(0.0f, 0.0f, 1.0f, alpha), true);
}
//----------------------------------------------------------------------------
void GeoObjFactory::UpdateCtrlColor(PX2::Renderer *renderer,
	PX2::Movable *mov, Float4 color)
{
	PX2::Node *node = DynamicCast<Node>(mov);

	if (!node)
		return;

	for (int i = 0; i < node->GetNumChildren(); i++)
	{
		PX2::Movable *child = node->GetChild(i);
		PX2::Polysegment *poly = DynamicCast<Polysegment>(child);
		if (poly)
		{
			VertexBuffer *vBuffer = poly->GetVertexBuffer();

			VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
			VertexBufferAccessor vba(vf, vBuffer);
			for (int i = 0; i < vBuffer->GetNumElements(); i++)
			{
				vba.Color<Float4>(0, i) = color;
			}

			renderer->Update(vBuffer);
		}

	}
}
//----------------------------------------------------------------------------
void GeoObjFactory::UpdateCtrlColor1(PX2::Renderer *renderer,
	PX2::Movable *mov, PX2::Float4 color)
{
	PX2::Node *node = DynamicCast<Node>(mov);

	if (!node)
		return;

	for (int i = 0; i < node->GetNumChildren(); i++)
	{
		PX2::Movable *child = node->GetChild(i);
		PX2::TriMesh *mesh = DynamicCast<TriMesh>(child);
		if (mesh)
		{
			VertexBuffer *vBuffer = mesh->GetVertexBuffer();

			VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
			VertexBufferAccessor vba(vf, vBuffer);
			for (int i = 0; i < vBuffer->GetNumElements(); i++)
			{
				vba.Color<Float4>(0, i) = color;
			}

			renderer->Update(vBuffer);
		}

	}
}
//----------------------------------------------------------------------------
PX2::Node *GeoObjFactory::CreateUICrossCtrl()
{
	Node *node = new0 Node();

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	VertexBufferPtr vb = new0 VertexBuffer(4, vf->GetStride());
	PolysegmentPtr seg = new0 Polysegment(vf, vb, false);
	seg->SetNumSegments(2);
	VertexBufferAccessor vba(vf, vb);
	vba.Position<Float3>(0) = Float3(-5000.0f, 0.0f, 0.0f);
	vba.Position<Float3>(1) = Float3(5000.0f, 0.0f, 0.0f);
	vba.Position<Float3>(2) = Float3(0.0f, 0.0f, -5000.0f);
	vba.Position<Float3>(3) = Float3(0.0f, 0.0f, 5000.0f);
	vba.Color<Float4>(0, 0) = Float4::GREEN;
	vba.Color<Float4>(0, 1) = Float4::GREEN;
	vba.Color<Float4>(0, 2) = Float4::GREEN;
	vba.Color<Float4>(0, 3) = Float4::GREEN;
	seg->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);
	seg->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	node->AttachChild(seg);

	float centerSize = 8.0f;

	VertexBufferPtr vbCenter = new0 VertexBuffer(5, vf->GetStride());
	PolysegmentPtr segCenter = new0 Polysegment(vf, vbCenter, true);
	segCenter->SetNumSegments(4);
	VertexBufferAccessor vbaCenter(vf, vbCenter);
	vbaCenter.Position<Float3>(0) = Float3(-centerSize, 0.0f, -centerSize);
	vbaCenter.Position<Float3>(1) = Float3(centerSize, 0.0f, -centerSize);
	vbaCenter.Position<Float3>(2) = Float3(centerSize, 0.0f, centerSize);
	vbaCenter.Position<Float3>(3) = Float3(-centerSize, 0.0f, centerSize);
	vbaCenter.Position<Float3>(4) = Float3(-centerSize, 0.0f, -centerSize);
	vbaCenter.Color<Float4>(0, 0) = Float4::GREEN;
	vbaCenter.Color<Float4>(0, 1) = Float4::GREEN;
	vbaCenter.Color<Float4>(0, 2) = Float4::GREEN;
	vbaCenter.Color<Float4>(0, 3) = Float4::GREEN;
	vbaCenter.Color<Float4>(0, 4) = Float4::GREEN;
	segCenter->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);
	segCenter->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
	node->AttachChild(segCenter);

	return node;
}
//----------------------------------------------------------------------------
PX2::Node *GeoObjFactory::CreateUIRectCtrl(float smallRectSize)
{
	Node *node = new0 Node();

	VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PC);
	VertexBufferPtr vb = new0 VertexBuffer(5, vf->GetStride());
	PolysegmentPtr sg = new0 Polysegment(vf, vb, true);
	sg->SetNumSegments(4);
	sg->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);
	sg->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());

	node->AttachChild(sg);

	for (int i = 0; i < 8; i++)
	{
		VertexBufferPtr smallRectVB = new0 VertexBuffer(5, vf->GetStride());
		PolysegmentPtr smallRect = new0 Polysegment(vf, smallRectVB, true);
		smallRect->SetNumSegments(4);

		VertexBufferAccessor vba(vf, smallRectVB);
		vba.Position<Float3>(0) = Float3(0.0f, 0.0f, 0.0f);
		vba.Position<Float3>(1) = Float3(smallRectSize, 0.0f, 0.0f);
		vba.Position<Float3>(2) = Float3(smallRectSize, 0.0f, smallRectSize);
		vba.Position<Float3>(3) = Float3(0.0f, 0.0f, smallRectSize);
		vba.Position<Float3>(4) = Float3(0.0f, 0.0f, 0.0f);
		vba.Color<Float4>(0, 0) = Float4::GREEN;
		vba.Color<Float4>(0, 1) = Float4::GREEN;
		vba.Color<Float4>(0, 2) = Float4::GREEN;
		vba.Color<Float4>(0, 3) = Float4::GREEN;
		vba.Color<Float4>(0, 4) = Float4::GREEN;

		smallRect->SetMaterialInstance(VertexColor4Material::CreateUniqueInstance());
		smallRect->UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);

		node->AttachChild(smallRect);
	}

	return node;
}
//----------------------------------------------------------------------------