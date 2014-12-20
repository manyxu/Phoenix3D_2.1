/*
*
* 文件名称	：	PX2LODTerrain.hpp
*
*/

#ifndef PX2LODTERRAIN_HPP
#define PX2LODTERRAIN_HPP

#include "PX2TerrainsPre.hpp"
#include "PX2Terrain.hpp"
#include "PX2LODTerrainPage.hpp"

namespace PX2
{

	class RawTerrain;
	class RawTerrainPage;

	class LODTerrain : public Terrain
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LODTerrain);

	public:
		LODTerrain ();
		virtual ~LODTerrain ();

		void CreateFromRawTerrain (RawTerrain *rawTer);

		void SetPixelTolerance (float tolerance);
		float GetPixelTolerance ();

		void SetCloseAssumption (bool ca);
		bool IsCloseAssumption ();

		void Simplify ();

	protected:
		void CreatePage (int row, int col, RawTerrainPage *rawPage);
		void StitchAll ();

		float mPixelTolerance;
		bool mIsCloseAssumption;
		bool mStitched; // 不需要存储
	};

#include "PX2LODTerrain.inl"

	PX2_REGISTER_STREAM(LODTerrain);
	typedef Pointer0<LODTerrain> LODTerrainPtr;

}

#endif