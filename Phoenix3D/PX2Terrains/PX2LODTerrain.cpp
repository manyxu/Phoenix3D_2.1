// PX2LODTerrain.cpp

#include "PX2LODTerrain.hpp"
#include "PX2Camera.hpp"
#include "PX2Renderer.hpp"
#include "PX2RawTerrain.hpp"
#include "PX2RawTerrainPage.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Terrain, LODTerrain);
PX2_IMPLEMENT_DEFAULT_NAMES(Terrain, LODTerrain);
PX2_IMPLEMENT_STREAM(LODTerrain);
PX2_IMPLEMENT_FACTORY(LODTerrain);

//----------------------------------------------------------------------------
LODTerrain::LODTerrain ()
	:
mPixelTolerance(1.0f),
mIsCloseAssumption(true),
mStitched(false)
{
}
//----------------------------------------------------------------------------
LODTerrain::~LODTerrain ()
{
}
//----------------------------------------------------------------------------
void LODTerrain::CreateFromRawTerrain (RawTerrain *rawTer)
{
	mNumRows = rawTer->GetRowQuantity();
	mNumCols = rawTer->GetColQuantity();
	mNumVertexPage = rawTer->GetNumVertexPage();
	mSpacing = rawTer->GetSpacing();

	mPages = new2<TerrainPagePtr>(mNumCols, mNumRows);
	int row, col;
	for (row = 0; row < mNumRows; ++row)
	{
		for (col = 0; col < mNumCols; ++col)
		{
			RawTerrainPage *rawPage = DynamicCast<RawTerrainPage>(
				rawTer->GetPage(row, col));
			CreatePage(row, col, rawPage);
		}
	}

	mChild.resize(mNumRows*mNumCols);
	for (row = 0; row < mNumRows; ++row)
	{
		for (col = 0; col < mNumCols; ++col)
		{
			AttachChild(mPages[row][col]);
		}
	}

	StitchAll();
	Simplify();
}
//----------------------------------------------------------------------------
void LODTerrain::SetPixelTolerance (float tolerance)
{
	mPixelTolerance = tolerance;

	for (int row = 0; row < mNumRows; row++)
	{
		for (int col = 0; col < mNumRows; col++)
		{
			LODTerrainPage *lodPage = DynamicCast<LODTerrainPage>(mPages[row][col]);
			
			if (lodPage)
			{
				lodPage->SetPixelTolerance(mPixelTolerance);
			}
		}
	}
}
//----------------------------------------------------------------------------
void LODTerrain::SetCloseAssumption (bool ca)
{
	mIsCloseAssumption = ca;
}
//----------------------------------------------------------------------------
void LODTerrain::Simplify ()
{
	if (!mStitched)
	{
		StitchAll();
	}

	//const Camera *camera = GraphicsRoot::GetSingleton().GetCamera();

	//APoint worldEye = camera->GetPosition();
	//AVector worldDir = camera->GetDVector();
	//APoint modelEye = WorldTransform.GetMatrix().Inverse() * worldEye;
	//AVector modelDir = WorldTransform.GetRotate().Inverse() * worldDir;
	//modelDir.Normalize();

	//int row, col;
	//for (row=0; row<mNumRows; row++)
	//{
	//	for (col=0; col<mNumCols; col++)
	//	{
	//		LODTerrainPage *page = DynamicCast<LODTerrainPage>(
	//			mPages[row][col]);
	//		page->ResetBlocks();
	//	}
	//}

	//for (row=0; row<mNumRows; row++)
	//{
	//	for (col=0; col<mNumCols; col++)
	//	{
	//		LODTerrainPage *page = DynamicCast<LODTerrainPage>(mPages[row][col]);
	//		if (page->IntersectFrustum(camera))
	//		{
	//			modelEye = page->WorldTransform.GetMatrix().Inverse()
	//				* worldEye;
	//			modelDir = page->WorldTransform.GetMatrix().Inverse()
	//				* worldDir;

	//			page->Simplify(modelEye,modelDir,mIsCloseAssumption);
	//		}
	//	}
	//}
}
//----------------------------------------------------------------------------
void LODTerrain::CreatePage (int row, int col, RawTerrainPage *rawPage)
{
	int numHeights = mNumVertexPage*mNumVertexPage;
	float *heights = new1<float>(numHeights);
	const float *heightsOrgin = rawPage->GetHeights();
	memcpy(heights, heightsOrgin, numHeights*sizeof(float));

	float length = mSpacing*(float)(mNumVertexPage - 1);
	Float2 origin(col*length, row*length);

	LODTerrainPage* lodPage = 0;
	lodPage = new0 LODTerrainPage(mVFormatEdit, mNumVertexPage, heights, origin, 
		mSpacing);
	lodPage->SetMaterialInstance(rawPage->GetMaterialInstance());

	mPages[row][col] = lodPage;
}
//----------------------------------------------------------------------------
void LODTerrain::StitchAll ()
{
	// 将地形页缝合在一起
	int row, col;
	for (row=0; row<mNumRows; row++)
	{
		for (col=0; col+1<mNumCols; col++)
		{
			DynamicCast<LODTerrainPage>(mPages[row][col])->StitchNextCol(
				DynamicCast<LODTerrainPage>(mPages[row][col+1]));
		}
	}

	for (col=0; col<mNumCols; col++)
	{
		for (row=0; row+1<mNumRows; row++)
		{
			DynamicCast<LODTerrainPage>(mPages[row][col])->StitchNextRow(
				DynamicCast<LODTerrainPage>(mPages[row+1][col]));
		}
	}

	mStitched = true;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
LODTerrain::LODTerrain (LoadConstructor value)
:
Terrain(value),
mPixelTolerance(0.0f),
mIsCloseAssumption(false),
mStitched(false)
{
}
//----------------------------------------------------------------------------
void LODTerrain::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Terrain::Load(source);
	PX2_VERSION_LOAD(source);

	source.Read(mPixelTolerance);
	source.ReadBool(mIsCloseAssumption);

	PX2_END_DEBUG_STREAM_LOAD(LODTerrain, source);
}
//----------------------------------------------------------------------------
void LODTerrain::Link (InStream& source)
{
	Terrain::Link(source);
}
//----------------------------------------------------------------------------
void LODTerrain::PostLink ()
{
	Terrain::PostLink();
}
//----------------------------------------------------------------------------
bool LODTerrain::Register (OutStream& target) const
{
	if (Terrain::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void LODTerrain::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Terrain::Save(target);
	PX2_VERSION_SAVE(target);

	target.Write(mPixelTolerance);
	target.WriteBool(mIsCloseAssumption);

	PX2_END_DEBUG_STREAM_SAVE(LODTerrain, target);
}
//----------------------------------------------------------------------------
int LODTerrain::GetStreamingSize (Stream &stream) const
{
	int size = Terrain::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += sizeof(mPixelTolerance);
	size += PX2_BOOLSIZE(mIsCloseAssumption);

	return size;
}
//----------------------------------------------------------------------------