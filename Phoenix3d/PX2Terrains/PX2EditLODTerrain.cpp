/*
*
* 文件名称	：	PX2EditLODTerrain.cpp
*
*/

#include "PX2EditLODTerrain.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, LODTerrain, EditLODTerrain);
PX2_IMPLEMENT_STREAM(EditLODTerrain);
PX2_IMPLEMENT_FACTORY(EditLODTerrain);
PX2_IMPLEMENT_DEFAULT_NAMES(LODTerrain, EditLODTerrain);

EditLODTerrain::EditLODTerrain ()
{
}
//----------------------------------------------------------------------------
EditLODTerrain::~EditLODTerrain ()
{
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetRenderer (Renderer* renderer)
{
	mRenderer = renderer;
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetRowQuantity (int rowQuantity)
{
	mRowQuantity = rowQuantity;
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetColQuantity (int colQuantity)
{
	mColQuantity = colQuantity;
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetSize (int size)
{
	mSize = size;
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetMinElevation (float minElvation)
{
	mMinElevation = minElvation;
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetMaxElevation (float maxElvation)
{
	mMaxElevation = maxElvation;
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetSpacing (float spacing)
{
	mSpacing = spacing;
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetUVBias (float uvBias)
{
	mUVBias = uvBias;
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetBorderColor (Float4 borderColor)
{
	mBorderColor = borderColor;
}
//----------------------------------------------------------------------------
void EditLODTerrain::AllocateRawTerrainPages ()
{
	mPages = new2<LODRawTerrainPagePtr>(mColQuantity, mRowQuantity);

	mVFormat = VertexFormat::Create(8,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 0,
		VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 1,
		VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 2,
		VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 3,
		VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 4,
		VertexFormat::AU_TEXCOORD, VertexFormat::AT_FLOAT2, 5);

	for (int row=0; row<mRowQuantity; row++)
	{
		for (int col=0; col<mColQuantity; col++)
		{
			unsigned short *height = new1<unsigned short>(mSize*mSize);
			memset(height, 0, mSize*mSize*sizeof(unsigned short));

			for (int i=0; i<mSize*mSize; i++)
			{
				height[i] = (unsigned short)Mathf::IntervalRandom(0.0f, 5.0f);
			}
			float length = mSpacing*(float)(mSize-1);
			Vector2f origin(col*length, row*length);
			mPages[row][col] = new0 LODTerrainPage(mVFormat, mSize, height,
				origin, mMinElevation, mMaxElevation, mSpacing, mUVBias);

			PX2::VertexColor4MaterialPtr material = new0 VertexColor4Material;
			material->GetTechnique(0)->GetPass(0)->GetWireProperty()
				->Enabled = true;

			mPages[row][col]->SetMaterialInstance(material->CreateInstance());
		}
	}

	mChild.resize(mRowQuantity*mColQuantity);

	for (int row=0; row<mRowQuantity; row++)
	{
		for (int col=0; col<mColQuantity; col++)
		{
			AttachChild(mPages[row][col]);
		}
	}

	StitchAll();
	Simplify();
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetUScale (int unit, float uScale)
{
	PX2_UNUSED(unit);
	PX2_UNUSED(uScale);
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetVScale (int unit, float vScale)
{
	PX2_UNUSED(unit);
	PX2_UNUSED(vScale);
}
//----------------------------------------------------------------------------
float EditLODTerrain::GetUScale (int unit)
{
	PX2_UNUSED(unit);

	return 0.0f;
}
//----------------------------------------------------------------------------
float EditLODTerrain::GetVScale (int unit)
{
	PX2_UNUSED(unit);

	return 0.0f;
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetLayerBaseTexture (const std::string &name)
{
	PX2_UNUSED(name);
}
//----------------------------------------------------------------------------
std::string EditLODTerrain::GetLayerBaseTexture ()
{
	return std::string();
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetLayer1Texture (const std::string &name)
{
	PX2_UNUSED(name);
}
//----------------------------------------------------------------------------
std::string EditLODTerrain::GetLayer1Texture ()
{
	return std::string();
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetLayer2Texture (const std::string &name)
{
	PX2_UNUSED(name);
}
//----------------------------------------------------------------------------
std::string EditLODTerrain::GetLayer2Texture ()
{
	return std::string();
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetLayer3Texture (const std::string &name)
{
	PX2_UNUSED(name);
}
//----------------------------------------------------------------------------
std::string EditLODTerrain::GetLayer3Texture ()
{
	return std::string();
}
//----------------------------------------------------------------------------
void EditLODTerrain::SetLayer4Texture (const std::string &name)
{
	PX2_UNUSED(name);
}
//----------------------------------------------------------------------------
std::string EditLODTerrain::GetLayer4Texture ()
{
	return std::string();
}
//----------------------------------------------------------------------------
LODRawTerrainPagePtr** &EditLODTerrain::GetRawTerrainPages ()
{
	return mPages;
}
//----------------------------------------------------------------------------
LODRawTerrainPagePtr *EditLODTerrain::GetCurrentPage (float x, float y) const
{
	PX2_UNUSED(x);
	PX2_UNUSED(y);

	return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
EditLODTerrain::EditLODTerrain (LoadConstructor value)
:
LODTerrain(value)
{
}
//----------------------------------------------------------------------------
void EditLODTerrain::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	LODTerrain::Load(source);

	PX2_END_DEBUG_STREAM_LOAD(EditLODTerrain, source);
}
//----------------------------------------------------------------------------
void EditLODTerrain::Link (InStream& source)
{
	LODTerrain::Link(source);
}
//----------------------------------------------------------------------------
void EditLODTerrain::PostLink ()
{
	LODTerrain::PostLink();
}
//----------------------------------------------------------------------------
bool EditLODTerrain::Register (OutStream& target) const
{
	if (LODTerrain::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void EditLODTerrain::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	LODTerrain::Save(target);

	PX2_END_DEBUG_STREAM_SAVE(EditLODTerrain, target);
}
//----------------------------------------------------------------------------
int EditLODTerrain::GetStreamingSize () const
{
	int size = LODTerrain::GetStreamingSize();

	return size;
}
//----------------------------------------------------------------------------