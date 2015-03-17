// PX2RawTerrain.cpp

#include "PX2RawTerrain.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Terrain, RawTerrain);
PX2_IMPLEMENT_STREAM(RawTerrain);
PX2_IMPLEMENT_FACTORY(RawTerrain);
PX2_IMPLEMENT_DEFAULT_NAMES(Terrain, RawTerrain)

//----------------------------------------------------------------------------
RawTerrain::RawTerrain ()
{
}
//----------------------------------------------------------------------------
RawTerrain::~RawTerrain ()
{
}
//----------------------------------------------------------------------------
void RawTerrain::SetRowQuantity (int numRows)
{
	mNumRows = numRows;
}
//----------------------------------------------------------------------------
void RawTerrain::SetColQuantity (int numCols)
{
	mNumCols = numCols;
}
//----------------------------------------------------------------------------
void RawTerrain::SetSize (int size)
{
	mSize = size;
}
//----------------------------------------------------------------------------
void RawTerrain::SetSpacing (float spacing)
{
	mSpacing = spacing;
}
//----------------------------------------------------------------------------
void RawTerrain::AllocateRawTerrainPages ()
{
	mPages = new2<TerrainPagePtr>(mNumCols, mNumRows);
	int row, col;
	for (row = 0; row < mNumRows; ++row)
	{
		for (col = 0; col < mNumCols; ++col)
		{
			CreatePage(row, col);
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
}
//----------------------------------------------------------------------------
RawTerrainPage *RawTerrain::CreatePage (int row, int col)
{
	if (0<=row && row<mNumRows && 0<=col && col<mNumCols)
	{
		if (mPages[row][col])
		{
			DetachChild(mPages[row][col]);
		}
	}

	int newRow = 0;
	int newCol = 0;
	if (row >= mNumRows)
	{
		newRow = row + 1;
	}
	else
	{
		newRow = mNumRows;
	}

	if (col > mNumCols)
	{
		newCol = col + 1;
	}
	else
	{
		newCol = mNumCols;
	}

	if (newRow>mNumRows || newCol>mNumCols)
	{
		TerrainPagePtr** pagesTemp = new2<TerrainPagePtr>(mNumCols, mNumRows);

		int row, col;
		for (row = 0; row < mNumRows; ++row)
		{
			for (col = 0; col < mNumCols; ++col)
			{
				pagesTemp[row][col] = mPages[row][col];
			}
		}

		for (int row = 0; row < mNumRows; ++row)
		{
			for (int col = 0; col < mNumCols; ++col)
			{
				mPages[row][col] = 0;
			}
		}
		delete2(mPages);

		mPages = new2<TerrainPagePtr>(newCol, newRow);
		for (row = 0; row < mNumRows; ++row)
		{
			for (col = 0; col < mNumCols; ++col)
			{
				mPages[row][col] = pagesTemp[row][col];
			}
		}

		for (int row = 0; row < mNumRows; ++row)
		{
			for (int col = 0; col < mNumCols; ++col)
			{
				pagesTemp[row][col] = 0;
			}
		}
		delete2(pagesTemp);

		mNumRows = newRow;
		mNumCols = newCol;
	}

	int numHeights = mSize*mSize;
	float *heights = new1<float>(numHeights);
	memset(heights, 0, numHeights*sizeof(float));

	float length = mSpacing*(float)(mSize - 1);
	Float2 origin(col*length, row*length);

	RawTerrainPage* page = 0;
	page = new0 RawTerrainPage(mVFormatEdit, mSize, heights, origin, mSpacing);
	page->SetShine(mTerrainShine);

	page->SetName("[" + StringHelp::IntToString(row) + "]" + "[" + StringHelp::IntToString(col) + "]");
	mPages[row][col] = page;

	return page;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void RawTerrain::RegistProperties ()
{
	Terrain::RegistProperties();

	AddPropertyClass("RawTerrain");
}
//----------------------------------------------------------------------------
void RawTerrain::OnPropertyChanged (const PropertyObject &obj)
{
	Terrain::OnPropertyChanged(obj);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
RawTerrain::RawTerrain (LoadConstructor value) :
Terrain(value)
{
}
//----------------------------------------------------------------------------
void RawTerrain::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Terrain::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(RawTerrain, source);
}
//----------------------------------------------------------------------------
void RawTerrain::Link (InStream& source)
{
	Terrain::Link(source);
}
//----------------------------------------------------------------------------
void RawTerrain::PostLink ()
{
	Terrain::PostLink();
}
//----------------------------------------------------------------------------
bool RawTerrain::Register (OutStream& target) const
{
	if (Terrain::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void RawTerrain::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Terrain::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(RawTerrain, target);
}
//----------------------------------------------------------------------------
int RawTerrain::GetStreamingSize (Stream &stream) const
{
	int size = Terrain::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------
