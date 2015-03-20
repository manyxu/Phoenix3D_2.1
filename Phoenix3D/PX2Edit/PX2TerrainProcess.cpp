// PX2TerrainProcess.cpp

#include "PX2TerrainProcess.hpp"
#include "PX2Edit.hpp"
#pragma warning(disable : 4310)
using namespace PX2;

//----------------------------------------------------------------------------
// TerrainProcess
//----------------------------------------------------------------------------
TerrainProcess::TerrainProcess()
{
	mTerProType = TPT_MAX_TYPE;
}
//----------------------------------------------------------------------------
TerrainProcess::TerrainProcess(TerProType type) :
mTerProType(type)
{
}
//----------------------------------------------------------------------------
TerrainProcess::~TerrainProcess()
{
}
//----------------------------------------------------------------------------
TerrainProcess::TerProType TerrainProcess::GetTerProType()
{
	return mTerProType;
}
//----------------------------------------------------------------------------
void TerrainProcess::Apply(bool calAverage)
{
	PX2_UNUSED(calAverage);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// TerrainHeightProcess
//----------------------------------------------------------------------------
TerrainHeightProcess::TerrainHeightProcess()
	:
	TerrainProcess(TerrainProcess::TPT_HEIGHT),
	mHeightMode(HM_RAISE),
	mFixHVal(0.0f)
{
}
//----------------------------------------------------------------------------
TerrainHeightProcess::~TerrainHeightProcess()
{
}
//----------------------------------------------------------------------------
void TerrainHeightProcess::Apply(bool calAverage)
{
	if (!mTerrain)
		return;

	float strength = mBrush->GetStrength();
	strength *= 2.0f;
	mBrush->CalculateInfulencedInfo(calAverage);
	std::vector<PageAffectInfo> &infos = mBrush->GetInfulencedInfo();

	bool isShiftDown = PX2_EDIT.IsShiftDown;
	HeightMode heightMode = mHeightMode;

	if (mHeightMode == MH_HOLE)
	{
		if (isShiftDown)
			heightMode = MH_NOHOLE;
	}
	else
	{
		if (isShiftDown)
			heightMode = HM_SMOOTH;
	}

	if (heightMode == MH_HOLE || heightMode == MH_NOHOLE)
	{
		std::vector<PageAffectInfo>::iterator it = infos.begin();
		for (; it != infos.end(); it++)
		{
			PageAffectInfo &info = *it;
			TerrainPagePtr page = info.InfulencedPage;
			int size = page->GetSize();
			PX2_UNUSED(size);

			for (int i = 0; i < (int)info.VertexInfoList.size(); i++)
			{
				int index = info.VertexInfoList[i].Index;

				if (heightMode == MH_HOLE)
					page->AddHole(index);
				else
					page->RemoveHole(index);
			}
		}

		it = infos.begin();
		for (; it != infos.end(); it++)
		{
			PageAffectInfo &info = *it;

			TerrainPage *page = info.InfulencedPage;
			RawTerrainPage *rawPage = DynamicCast<RawTerrainPage>(page);
			if (rawPage)
				rawPage->UpdateHoles();
		}
	}
	else
	{
		std::vector<PageAffectInfo>::iterator it = infos.begin();
		for (; it != infos.end(); it++)
		{
			PageAffectInfo &info = *it;
			TerrainPagePtr page = info.InfulencedPage;
			int size = page->GetSize();
			PX2_UNUSED(size);

			VertexBufferPtr vBuffer = page->GetVertexBuffer();
			VertexBufferAccessor vba;
			vba.ApplyTo(page);

			for (int j = 0; j < (int)info.VertexInfoList.size(); j++)
			{
				int vertexIndex = info.VertexInfoList[j].Index;

				float weight = info.VertexInfoList[j].Weight;
				Float3 &pos = vba.Position<Float3>(vertexIndex);
				Float3 &normal = vba.Normal<Float3>(vertexIndex);

				if (heightMode == HM_RAISE)
					pos[2] += strength * weight;
				else if (heightMode == HM_LOWER)
					pos[2] -= strength * weight;
				else if (heightMode == HM_FLATTEN)
				{
					pos[2] = PageAffectInfo::AverageHeight;
				}
				else if (heightMode == HM_SMOOTH)
				{
					if (weight <= 1.0f)
					{
						float x = pos[0];
						float y = pos[1];
						float spacing = mTerrain->GetSpacing();

						float height = mTerrain->GetHeight(x, y);
						float heightL1 = mTerrain->GetHeight(x - spacing, y);
						float heightR1 = mTerrain->GetHeight(x + spacing, y);
						float heightD1 = mTerrain->GetHeight(x, y - spacing);
						float HeightU1 = mTerrain->GetHeight(x, y + spacing);

						pos[2] = (height + heightL1 + heightR1 + heightD1 + HeightU1) / 5.0f;
					}
				}
				else if (heightMode == HM_FIXH)
				{
					pos[2] = mFixHVal;
				}

				RawTerrain *terrain = DynamicCast<RawTerrain>(
					info.InfulencedPage->GetParent());
				if (terrain)
				{
					AVector nor = terrain->GetNormal(pos[0], pos[1]);
					normal = Float3(nor.X(), nor.Y(), nor.Z());
				}
			}

			PX2::Renderer::UpdateAll(vBuffer);
		}

		it = infos.begin();
		for (; it != infos.end(); it++)
		{
			PageAffectInfo &info = *it;

			TerrainPage *page = info.InfulencedPage;
			RawTerrainPage *rawPage = DynamicCast<RawTerrainPage>(page);
			if (rawPage)
				rawPage->UpdateToHighField();
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// TerrainTextureProcess
//----------------------------------------------------------------------------
TerrainTextureProcess::TerrainTextureProcess() :
TerrainProcess(TerrainProcess::TPT_TEXTURE),
mTextureMode(TM_INCREASE),
mSelectedLayerIndex(1)
{
}
//----------------------------------------------------------------------------
TerrainTextureProcess::~TerrainTextureProcess()
{
}
//----------------------------------------------------------------------------
void TerrainTextureProcess::SetLayerUsingTexture(int layerIndex,
	PX2::Texture2D *texture)
{
	mLayerTextures[layerIndex] = texture;
}
//----------------------------------------------------------------------------
PX2::Texture2D *TerrainTextureProcess::GetLayerUsingTexture(int layerIndex)
{
	std::map<int, PX2::Texture2DPtr>::iterator it = mLayerTextures.begin();

	for (; it != mLayerTextures.end(); it++)
	{
		if (it->first == layerIndex)
			return it->second;
	}

	return 0;
}
//----------------------------------------------------------------------------
void TerrainTextureProcess::SetSelectedLayerUsingTexture(
	PX2::Texture2D *texture)
{
	SetLayerUsingTexture(mSelectedLayerIndex, texture);
}
//----------------------------------------------------------------------------
PX2::Texture2D *TerrainTextureProcess::GetSelectedLayerUsingTexture()
{
	return GetLayerUsingTexture(mSelectedLayerIndex);
}
//----------------------------------------------------------------------------
void TerrainTextureProcess::Apply(bool calAverage)
{
	PX2_UNUSED(calAverage);

	if (!mTerrain)
		return;

	bool isShiftDown = PX2_EDIT.IsShiftDown;

	TextureMode textrueMode = mTextureMode;
	if (isShiftDown)
	{
		textrueMode = TM_DECREASE;
	}
	else
	{
		Texture2D *selectLayerTex = GetSelectedLayerUsingTexture();

		PX2::Object *obj = PX2_EDIT.GetSelectedResource().TheObject;
		Texture2D *tex2D = DynamicCast<Texture2D>(obj);
		if (tex2D && selectLayerTex != tex2D)
		{
			SetSelectedLayerUsingTexture(tex2D);
		}
	}

	float strength = mBrush->GetStrength();
	PX2_UNUSED(strength);

	mBrush->CalculateInfulencedInfoPixel();
	std::vector<PageAffectInfo> &infos = mBrush->GetInfulencedInfo();

	std::vector<PageAffectInfo>::iterator it = infos.begin();
	for (; it != infos.end(); it++)
	{
		bool isCenter = it->CenterPage;
		PX2_UNUSED(isCenter);
		//	if (isCenter)
		{
			Texture2D *layerTex = GetSelectedLayerUsingTexture();
			TerrainPage *page = it->InfulencedPage;
			RawTerrainPage *rawPage = DynamicCast<RawTerrainPage>(page);
			if (!rawPage)
				return;

			if (layerTex)
			{
				rawPage->SetTexture(mSelectedLayerIndex, layerTex);
			}

			Texture2D *tex = rawPage->GetTextureAlpha();
			char *buffer = tex->GetData(0);

			int width = tex->GetWidth();
			int height = tex->GetHeight();
			PX2_UNUSED(width);
			PX2_UNUSED(height);

			for (int i = 0; i < (int)it->PixelInfoList.size(); i++)
			{
				int pixelIndex = it->PixelInfoList[i].Index;

				unsigned char *b = (unsigned char*)&buffer[4 * pixelIndex]; // B 必须是unsigned char
				unsigned char *g = (unsigned char*)&buffer[4 * pixelIndex + 1]; // G
				unsigned char *r = (unsigned char*)&buffer[4 * pixelIndex + 2]; // R
				unsigned char *a = (unsigned char*)&buffer[4 * pixelIndex + 3]; // A

				float strength = mBrush->GetStrength();
				int add = (int)(it->PixelInfoList[i].Weight * 255 * strength);

				if (textrueMode == TM_DECREASE)
					add = -add;

				if (0 == add)
					continue;

				int val = 0;
				if (mSelectedLayerIndex == 0)
				{
				}
				else if (mSelectedLayerIndex == 1)
				{
					val = (unsigned char)(*r);
					val += add;
					val = PX2::Math<int>::Clamp(val, 0, 255);
					*r = (unsigned char)val;
				}
				else if (mSelectedLayerIndex == 2)
				{
					val = (unsigned char)(*g); //< 必须是unsigned 

					val += add;
					val = (PX2::Math<int>::Clamp(val, 0, 255));
					*g = (unsigned char)val;
				}
				else if (mSelectedLayerIndex == 3)
				{
					val = (unsigned char)(*b); //< 必须是unsigned 
					val += add;
					val = (PX2::Math<int>::Clamp(val, 0, 255));
					*b = (unsigned char)val;
				}
				else if (mSelectedLayerIndex == 4)
				{
					val = (unsigned char)(*a); //< 必须是unsigned 
					val += add;
					val = (PX2::Math<int>::Clamp(val, 0, 255));
					*a = (unsigned char)val;
				}
			}

			Renderer::GetDefaultRenderer()->Update(tex, 0);
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// TerrainJunglerProcess
//----------------------------------------------------------------------------
TerrainJunglerProcess::TerrainJunglerProcess() :
TerrainProcess(TerrainProcess::TPT_JUNGLER),
mMode(JM_ADD),
mWidth(2.0f),
mHeight(1.0f),
mLower(0.0f)
{
}
//----------------------------------------------------------------------------
TerrainJunglerProcess::~TerrainJunglerProcess()
{
}
//----------------------------------------------------------------------------
void TerrainJunglerProcess::SetWidth(float width)
{
	mWidth = width;
}
//----------------------------------------------------------------------------
void TerrainJunglerProcess::SetHeight(float height)
{
	mHeight = height;
}
//----------------------------------------------------------------------------
void TerrainJunglerProcess::SetLower(float lower)
{
	mLower = lower;
}
//----------------------------------------------------------------------------
void TerrainJunglerProcess::Apply()
{
	if (!mTerrain || !mUsingTexture)
		return;

	APoint pos = mBrush->GetPos();
	float size = mBrush->GetSize();
	float strength = mBrush->GetStrength();
	bool isShiftDown = PX2_EDIT.IsShiftDown;

	JunglerMode mode = GetJunglerMode();
	if (isShiftDown)
		mode = JM_REDUCE;

	if (JM_ADD == mode)
	{
		mTerrain->AddJunglers(mUsingTexture, pos, size,
			(int)(strength*1000.0f), mWidth, mHeight, mLower);
	}
	else if (JM_REDUCE == mode)
	{
		mTerrain->RemoveJunglers(mUsingTexture, pos, size,
			(int)(strength*1000.0f));
	}
}
//----------------------------------------------------------------------------