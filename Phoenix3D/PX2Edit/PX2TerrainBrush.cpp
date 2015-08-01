// PX2TerrainBrush.cpp

#include "PX2TerrainBrush.hpp"
#include "PX2EditEventType.hpp"
using namespace PX2;

float PageAffectInfo::AverageHeight = 0.0f;
int PageAffectInfo::VertexNum = 0;
//----------------------------------------------------------------------------
TerrainBrush::TerrainBrush()
{
	mInterplateMode = IM_COS;

	mVertexFormat = VertexFormat::Create(2,
		VertexFormat::AU_POSITION, VertexFormat::AT_FLOAT3, 0,
		VertexFormat::AU_COLOR, VertexFormat::AT_FLOAT3, 0);
	int vstride = mVertexFormat->GetStride();
	PX2_UNUSED(vstride);

	StandardMesh sdm(mVertexFormat, false);
	sdm.SetVertexColor(Float4::WHITE);
	mCircleSegment = sdm.Circle(1.0f, 25);
	mCircleSegment->SetMaterialInstance(
		VertexColor4Material::CreateUniqueInstance());

	mCircleSegment->Culling = Renderable::CULL_ALWAYS;

	SetSize(4.0f);
	SetStrength(0.04f);
}
//----------------------------------------------------------------------------
TerrainBrush::~TerrainBrush()
{
}
//----------------------------------------------------------------------------
void TerrainBrush::SetPos(PX2::APoint pos)
{
	Brush::SetPos(pos);

	mCircleSegment->LocalTransform.SetTranslate(pos);
	mCircleSegment->Update();
}
//----------------------------------------------------------------------------
void TerrainBrush::SetSize(float size)
{
	Brush::SetSize(size);

	mCircleSegment->LocalTransform.SetUniformScale(size);
	mCircleSegment->Update();
}
//----------------------------------------------------------------------------
void TerrainBrush::SelectPage()
{
	mPageInfoList.clear();
	PageAffectInfo::AverageHeight = 0.0f;
	PageAffectInfo::VertexNum = 0;

	if (!mTerrain) return;

	mSelectedTerrainPage = mTerrain->GetCurrentPage(mPos.X(), mPos.Y());

	Event *ent = EditEventSpace::CreateEventX(EditEventSpace::SelectTerrainPage);
	ent->SetData<PX2::TerrainPage*>(mSelectedTerrainPage);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
TerrainPage *TerrainBrush::GetSelectedPage()
{
	return mSelectedTerrainPage;
}
//----------------------------------------------------------------------------
void TerrainBrush::CalculateInfulencedInfo(bool calAverage)
{
	mPageInfoList.clear();
	if (calAverage)
	{
		PageAffectInfo::AverageHeight = 0.0f;
		PageAffectInfo::VertexNum = 0;
	}

	if (!mTerrain) return;

	APoint point0;
	APoint point1;
	APoint point2;
	APoint point3;

	float sizeScale = mSize*1.5f;

	AVector toTerrainVec = mPos - mTerrain->WorldTransform.GetTranslate();
	APoint toTerrainPos = APoint(toTerrainVec[0], toTerrainVec[1], toTerrainVec[2]);

	point0 = APoint(toTerrainPos.X() - sizeScale, toTerrainPos.Y() - sizeScale, 0.0f);
	point1 = APoint(toTerrainPos.X() + sizeScale, toTerrainPos.Y() - sizeScale, 0.0f);
	point2 = APoint(toTerrainPos.X() + sizeScale, toTerrainPos.Y() + sizeScale, 0.0f);
	point3 = APoint(toTerrainPos.X() - sizeScale, toTerrainPos.Y() + sizeScale, 0.0f);

	TerrainPagePtr page = mTerrain->GetCurrentPage(toTerrainPos.X(), toTerrainPos.Y());
	TerrainPagePtr page0 = mTerrain->GetCurrentPage(point0.X(), point0.Y());
	TerrainPagePtr page1 = mTerrain->GetCurrentPage(point1.X(), point1.Y());
	TerrainPagePtr page2 = mTerrain->GetCurrentPage(point2.X(), point2.Y());
	TerrainPagePtr page3 = mTerrain->GetCurrentPage(point3.X(), point3.Y());

	if (page)
	{
		PageAffectInfo info;
		info.CenterPage = true;
		info.InfulencedPage = page;
		mPageInfoList.push_back(info);
	}

	if (page0 && page0 != page)
	{
		PageAffectInfo info;
		info.InfulencedPage = page0;
		mPageInfoList.push_back(info);
	}

	if (page1 && page1 != page && page1 != page0)
	{
		PageAffectInfo info;
		info.InfulencedPage = page1;
		mPageInfoList.push_back(info);
	}

	if (page2 && page2 != page && page2 != page0 && page2 != page1)
	{
		PageAffectInfo info;
		info.InfulencedPage = page2;
		mPageInfoList.push_back(info);
	}

	if (page3 && page3 != page && page3 != page0 && page3 != page1 && page3 != page2)
	{
		PageAffectInfo info;
		info.InfulencedPage = page3;
		mPageInfoList.push_back(info);
	}

	for (int i = 0; i < (int)mPageInfoList.size(); i++)
	{
		PageAffectInfo &pInfo = mPageInfoList[i];

		pInfo.VertexInfoList.clear();

		TerrainPagePtr page = pInfo.InfulencedPage;
		VertexBufferPtr vBuffer = page->GetVertexBuffer();
		VertexBufferAccessor vba;
		vba.ApplyTo(page);

		int vertexNum = vBuffer->GetNumElements();

		for (int j = 0; j < vertexNum; j++)
		{
			Float3 vPos = vba.Position<Float3>(j);
			APoint vPoint = APoint(vPos);
			vPoint.Z() = 0.0f;

			AVector toTerrainVec = mPos - mTerrain->WorldTransform.GetTranslate();
			APoint center = toTerrainPos;
			center.Z() = 0.0f;

			if (vPoint.X() < point0.X() || vPoint.Y() < point0.Y()
				|| vPoint.X() > point2.X() || vPoint.Y() > point2.Y())
			{
				continue;
			}
			else
			{
				VertexAffectInfo vInfo;

				vInfo.Index = j;
				AVector diff = vPoint - center;
				float length = diff.Length();
				vInfo.Length = length;

				if (length <= mSize)
				{
					if (mInterplateMode == IM_NONE)
					{
						vInfo.Weight = 1.0f;
					}
					else if (mInterplateMode == IM_LINER)
					{
						float linear = (mSize - length) / mSize;
						linear = Mathf::Clamp(linear, 0.0f, 1.0f);
						vInfo.Weight = linear;
					}
					else if (mInterplateMode == IM_SQUARE)
					{
						float linear = (mSize - length) / mSize;
						linear = Mathf::Clamp(linear, 0.0f, 1.0f);
						vInfo.Weight = linear*linear;
					}
					else if (mInterplateMode == IM_COS)
					{
						float linear = length / mSize;
						linear = Mathf::Clamp(linear, 0.0f, 1.0f);
						vInfo.Weight = Mathf::Cos(linear*Mathf::HALF_PI);
					}

					if (calAverage)
					{
						PageAffectInfo::AverageHeight += vPos[2];
						PageAffectInfo::VertexNum++;
					}

					pInfo.VertexInfoList.push_back(vInfo);
				}
			}
		}
	}

	if (calAverage)
	{
		PageAffectInfo::AverageHeight /= (float)(PageAffectInfo::VertexNum);
	}
}
//----------------------------------------------------------------------------
void TerrainBrush::CalculateInfulencedInfoPixel()
{
	mPageInfoListPixel.clear();

	if (!mTerrain)
		return;

	APoint point0;
	APoint point1;
	APoint point2;
	APoint point3;

	float sizeScale = mSize * 1.5f;

	AVector toTerrainVec = mPos - mTerrain->WorldTransform.GetTranslate();
	APoint toTerrainPos = APoint(toTerrainVec[0], toTerrainVec[1], toTerrainVec[2]);

	point0 = APoint(toTerrainPos.X() - sizeScale, toTerrainPos.Y() - sizeScale, 0.0f);
	point1 = APoint(toTerrainPos.X() + sizeScale, toTerrainPos.Y() - sizeScale, 0.0f);
	point2 = APoint(toTerrainPos.X() + sizeScale, toTerrainPos.Y() + sizeScale, 0.0f);
	point3 = APoint(toTerrainPos.X() - sizeScale, toTerrainPos.Y() + sizeScale, 0.0f);

	TerrainPagePtr page = mTerrain->GetCurrentPage(toTerrainPos.X(), toTerrainPos.Y());
	TerrainPagePtr page0 = mTerrain->GetCurrentPage(point0.X(), point0.Y());
	TerrainPagePtr page1 = mTerrain->GetCurrentPage(point1.X(), point1.Y());
	TerrainPagePtr page2 = mTerrain->GetCurrentPage(point2.X(), point2.Y());
	TerrainPagePtr page3 = mTerrain->GetCurrentPage(point3.X(), point3.Y());

	if (page)
	{
		PageAffectInfo info;
		info.CenterPage = true;
		info.InfulencedPage = page;
		mPageInfoList.push_back(info);
	}

	if (page0 && page0 != page)
	{
		PageAffectInfo info;
		info.InfulencedPage = page0;
		mPageInfoList.push_back(info);
	}

	if (page1 && page1 != page && page1 != page0)
	{
		PageAffectInfo info;
		info.InfulencedPage = page1;
		mPageInfoList.push_back(info);
	}

	if (page2 && page2 != page && page2 != page0 && page2 != page1)
	{
		PageAffectInfo info;
		info.InfulencedPage = page2;
		mPageInfoList.push_back(info);
	}

	if (page3 && page3 != page && page3 != page0 && page3 != page1 && page3 != page2)
	{
		PageAffectInfo info;
		info.InfulencedPage = page3;
		mPageInfoList.push_back(info);
	}

	for (int i = 0; i < (int)mPageInfoList.size(); i++)
	{
		PageAffectInfo &pInfo = mPageInfoList[i];

		pInfo.PixelInfoList.clear();

		TerrainPagePtr page = pInfo.InfulencedPage;

		RawTerrainPage *rawTerrainPage = DynamicCast<RawTerrainPage>(page);
		Texture2D *texAlpha = rawTerrainPage->GetTextureAlpha();
		const Float2 &origin = rawTerrainPage->GetOrigin();
		float pageWidth = page->GetWidth();

		int texWidth = texAlpha->GetWidth();
		int texHeight = texAlpha->GetHeight();
		float fTexWidth = (float)texWidth;
		float fTexHeight = (float)texHeight;

		float fUStart = point0.X() - origin[0];
		float fVStart = point0.Y() - origin[1];
		if (fUStart < 0.0f) fUStart = 0.0f;
		if (fVStart < 0.0f) fVStart = 0.0f;
		if (fUStart > pageWidth)
			continue;
		if (fVStart > pageWidth)
			continue;

		float fUEnd = point2.X() - origin[0];
		float fVEnd = point2.Y() - origin[1];
		if (fUEnd > pageWidth) fUEnd = pageWidth;
		if (fVEnd > pageWidth) fVEnd = pageWidth;
		if (fUEnd < 0.0f)
			continue;
		if (fVEnd < 0.0f)
			continue;

		int iUStart = (int)(fTexWidth * (fUStart / pageWidth));
		int iVStart = (int)(fTexHeight * (fVStart / pageWidth));
		int iUEnd = (int)(fTexWidth * (fUEnd / pageWidth));
		int iVEnd = (int)(fTexHeight * (fVEnd / pageWidth));

		for (int v = iVStart; v < iVEnd; v++)
		{
			for (int u = iUStart; u < iUEnd; u++)
			{
				APoint vPoint = APoint(origin[0] + pageWidth * (float)u / (float)texWidth,
					origin[1] + pageWidth * (float)v / (float)texHeight, 0.0f);

				APoint center = toTerrainPos;
				center.Z() = 0.0f;

				AVector diff = vPoint - center;
				float length = diff.Length();

				if (length <= mSize)
				{
					PixelAffectInfo pixInfo;
					pixInfo.Index = v*texWidth + u;
					pixInfo.Length = length;

					if (mInterplateMode == IM_NONE)
					{
						pixInfo.Weight = 1.0f;
					}
					else if (mInterplateMode == IM_LINER)
					{
						float linear = (mSize - length) / mSize;
						linear = Mathf::Clamp(linear, 0.0f, 1.0f);
						pixInfo.Weight = linear;
					}
					else if (mInterplateMode == IM_SQUARE)
					{
						float linear = (mSize - length) / mSize;
						linear = Mathf::Clamp(linear, 0.0f, 1.0f);
						pixInfo.Weight = linear*linear;
					}
					else if (mInterplateMode == IM_COS)
					{
						float linear = length / mSize;
						linear = Mathf::Clamp(linear, 0.0f, 1.0f);
						pixInfo.Weight = Mathf::Cos(linear*Mathf::HALF_PI);
					}

					pInfo.PixelInfoList.push_back(pixInfo);
				}
			}
		}
	}
}
//----------------------------------------------------------------------------