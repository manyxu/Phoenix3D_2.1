// PX2TerrainBrush.hpp

#ifndef PX2TERRAINBRUSH_HPP
#define PX2TERRAINBRUSH_HPP

#include "PX2EditPre.hpp"
#include "PX2Brush.hpp"
#include "PX2Terrain.hpp"
#include "PX2TerrainPage.hpp"
#include "PX2RawTerrain.hpp"
#include "PX2RawTerrainPage.hpp"

namespace PX2
{

	class PX2_EDIT_ITEM VertexAffectInfo
	{
	public:
		VertexAffectInfo()
		{
			Index = -1;
			Length = 1.0f;
			Weight = 0.0f;
		}

		int Index;
		float Length;
		float Weight;
	};

	class PixelAffectInfo
	{
	public:
		PixelAffectInfo()
		{
			Index = -1;
			Length = 1.0f;
			Weight = 0.0f;
		}

		int Index;
		float Length;
		float Weight;
	};

	class PageAffectInfo
	{
	public:
		PageAffectInfo()
		{
			CenterPage = false;
		}
		~PageAffectInfo()
		{

		}
		bool CenterPage;
		PX2::TerrainPagePtr InfulencedPage;
		std::vector<VertexAffectInfo> VertexInfoList;
		std::vector<PixelAffectInfo> PixelInfoList;

		static float AverageHeight;
		static int VertexNum;
	};

	class TerrainBrush : public Brush
	{
	public:
		TerrainBrush();
		virtual ~TerrainBrush();

		enum InterplateMode
		{
			IM_NONE,
			IM_LINER,
			IM_SQUARE,
			IM_COS,
			IM_MAX_MODE
		};
		void SetInterplateMode(InterplateMode mode) { mInterplateMode = mode; }
		InterplateMode GetInterplateMode() { return mInterplateMode; }

		virtual void SetPos(PX2::APoint pos);
		virtual void SetSize(float size);

		void SetTerrain(PX2::RawTerrain *terrain) { mTerrain = terrain; }
		PX2::RawTerrain *GetTerrain() { return mTerrain; }

		void SelectPage();
		PX2::TerrainPage *GetSelectedPage();

		void CalculateInfulencedInfo(bool calAverage);
		std::vector<PageAffectInfo> &GetInfulencedInfo() { return mPageInfoList; }

		void CalculateInfulencedInfoPixel();
		std::vector<PixelAffectInfo> &GetInfulencedInfoPixel() { return mPageInfoListPixel; }

		PX2::Renderable *GetRenderable() { return mCircleSegment; }

	protected:
		PX2::RawTerrainPtr mTerrain;
		PX2::TerrainPagePtr mSelectedTerrainPage;
		InterplateMode mInterplateMode;
		std::vector<PageAffectInfo> mPageInfoList;
		std::vector<PixelAffectInfo> mPageInfoListPixel;

		PX2::VertexFormatPtr mVertexFormat;
		PX2::PolysegmentPtr mCircleSegment;
	};

}

#endif