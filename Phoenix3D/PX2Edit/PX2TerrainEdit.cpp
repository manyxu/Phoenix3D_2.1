// PX2TerrainEdit.cpp

#include "PX2TerrainEdit.hpp"
#include "PX2EditEventType.hpp"
#include "PX2TerrainEdit.hpp"
#include "PX2Project.hpp"
#include "PX2EditMap.hpp"
using namespace PX2;

TerrainEdit::TerrainEdit() :
mTerrainHelpGrid(0),
mIsUsingLodTerrain(0)
{
	mBrush = new0 TerrainBrush();
	mHeightProcess = new0 TerrainHeightProcess();
	mHeightProcess->SetBrush(mBrush);
	mTextureProcess = new0 TerrainTextureProcess();
	mTextureProcess->SetBrush(mBrush);
	mJunglerProcess = new0 TerrainJunglerProcess();
	mJunglerProcess->SetBrush(mBrush);
	mActiveProcess = mHeightProcess;

	SetEditType(TerrainProcess::TPT_HEIGHT);
}
//----------------------------------------------------------------------------
TerrainEdit::~TerrainEdit()
{
	if (mHeightProcess)
		delete0(mHeightProcess);

	if (mTextureProcess)
		delete0(mTextureProcess);

	if (mJunglerProcess)
		delete0(mJunglerProcess);

	if (mBrush)
		delete0(mBrush);
}
//----------------------------------------------------------------------------
void TerrainEdit::EnableEdit()
{
	if (IsUseLodTerrain())
		return;

	TerrainActor *actor = 0;

	Project *proj = Project::GetSingletonPtr();
	if (!proj) return;

	Scene *scene = proj->GetScene();
	if (!scene) return;

	actor = scene->GetTerrainActor();

	if (actor)
	{
		mBrush->GetRenderable()->Culling = Renderable::CULL_DYNAMIC;

		SetTerrain(DynamicCast<RawTerrain>(actor->GetRawTerrain()));
	}
	else
	{
		mBrush->GetRenderable()->Culling = Renderable::CULL_ALWAYS;
	}
}
//----------------------------------------------------------------------------
void TerrainEdit::DisableEdit()
{
	SetTerrain(0);

	mBrush->GetRenderable()->Culling = Renderable::CULL_ALWAYS;
}
//----------------------------------------------------------------------------
void TerrainEdit::ShowPageLine(bool show)
{
	if (show)
	{
		if (mTerrainHelpGrid)
			mTerrainHelpGrid->Culling = Renderable::CULL_DYNAMIC;
	}
	else
	{
		if (mTerrainHelpGrid)
			mTerrainHelpGrid->Culling = Renderable::CULL_ALWAYS;
	}
}
//----------------------------------------------------------------------------
void TerrainEdit::UseLodTerrain(bool use)
{
	if (use)
		DisableEdit();

	Project *proj = Project::GetSingletonPtr();
	if (!proj) return;

	Scene *scene = proj->GetScene();
	if (!scene) return;

	TerrainActor *terActor = scene->GetTerrainActor();
	if (!terActor) return;

	LODTerrain *lodTerrain = CreateLODTerrain(terActor->GetRawTerrain());
	terActor->SetLODTerrain(lodTerrain);

	terActor->UseLod(use);
}
//----------------------------------------------------------------------------
bool TerrainEdit::IsUseLodTerrain()
{
	Project *proj = Project::GetSingletonPtr();
	if (!proj) return false;

	Scene *scene = proj->GetScene();
	if (!scene) return false;

	TerrainActor *terActor = scene->GetTerrainActor();
	if (!terActor) return false;

	return terActor->IsUseLod();
}
//----------------------------------------------------------------------------
bool TerrainEdit::IsPageLineShow()
{
	if (mTerrainHelpGrid)
		return mTerrainHelpGrid->Culling == Renderable::CULL_DYNAMIC;

	return false;
}
//----------------------------------------------------------------------------
void TerrainEdit::SetTerrain(RawTerrain *terrain)
{
	mTerrain = terrain;

	if (mBrush)
		mBrush->SetTerrain(terrain);

	if (mHeightProcess)
		mHeightProcess->SetTerrain(terrain);

	if (mTextureProcess)
		mTextureProcess->SetTerrain(terrain);

	if (mJunglerProcess)
		mJunglerProcess->SetTerrain(terrain);

	if (mTerrain)
	{
		CreateTerrainHelpGrid();
	}
	else
	{
		DestoryTerrainHelpGrid();
	}
}
//----------------------------------------------------------------------------
LODTerrain *TerrainEdit::CreateLODTerrain(RawTerrain *rawTerrain)
{
	assertion(0 != rawTerrain, "rawTerrain must not be 0.\n");

	LODTerrain *lodTer = new0 LODTerrain();
	lodTer->CreateFromRawTerrain(rawTerrain);

	return lodTer;
}
//----------------------------------------------------------------------------
void TerrainEdit::CreateTerrainHelpGrid()
{
	//EditSystem::GetSingleton().GetHelpScene()->DetachChild(mTerrainHelpGrid);
	//mTerrainHelpGrid = 0;

	//if (!mTerrain)
	//	return;

	//float pageWidth = (mTerrain->GetSize() - 1) * mTerrain->GetSpacing();
	//int rowNum = mTerrain->GetRowQuantity();
	//int colNum = mTerrain->GetColQuantity();
	//float terrainRowWidth = pageWidth*rowNum;
	//float terrainColWidth = pageWidth*colNum;

	//VertexFormat *format = VertexFormat::Create(2,
	//	VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
	//	VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT4, 0);

	//StandardMesh stdMesh(format);
	//mTerrainHelpGrid = stdMesh.LineRectangleForEditor1(rowNum + 1, colNum + 1,
	//	terrainRowWidth / 2.0f, terrainColWidth / 2.0f, Float4(1.0f, 1.0f, 0.0f, 0.0f));
	//mTerrainHelpGrid->SetMaterialInstance(VertexColor4Material
	//	::CreateUniqueInstance());
	//mTerrainHelpGrid->LocalTransform.SetTranslate(APoint(terrainRowWidth / 2.0f,
	//	terrainColWidth / 2.0f, 0.0f));
	////mTerrainHelpGrid->Culling = Movable::CULL_ALWAYS;

	//EditSystem::GetSingleton().GetHelpScene()->AttachChild(mTerrainHelpGrid);
	//EditSystem::GetSingleton().GetHelpScene()->Update();
}
//----------------------------------------------------------------------------
void TerrainEdit::DestoryTerrainHelpGrid()
{
	//EditSystem::GetSingleton().GetHelpScene()->DetachChild(mTerrainHelpGrid);
	//mTerrainHelpGrid = 0;
	//EditSystem::GetSingleton().GetHelpScene()->Update();
}
//----------------------------------------------------------------------------
void TerrainEdit::SetEditType(TerrainProcess::TerProType type)
{
	if (type == TerrainProcess::TPT_HEIGHT)
		mActiveProcess = mHeightProcess;
	else if (type == TerrainProcess::TPT_TEXTURE)
		mActiveProcess = mTextureProcess;
	else if (type == TerrainProcess::TPT_JUNGLER)
		mActiveProcess = mJunglerProcess;
}
//----------------------------------------------------------------------------
TerrainProcess::TerProType TerrainEdit::GetEditType()
{
	if (mActiveProcess)
		return mActiveProcess->GetTerProType();

	return TerrainProcess::TPT_MAX_TYPE;
}
//----------------------------------------------------------------------------
void TerrainEdit::Apply(bool calAverage)
{
	if (mActiveProcess)
		mActiveProcess->Apply(calAverage);
}
//----------------------------------------------------------------------------