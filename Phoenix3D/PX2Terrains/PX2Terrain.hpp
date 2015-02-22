// PX2Terrain.hpp

#ifndef PX2TERRAIN_HPP
#define PX2TERRAIN_HPP

#include "PX2TerrainsPre.hpp"
#include "PX2Node.hpp"
#include "PX2Camera.hpp"
#include "PX2TerrainPage.hpp"

namespace PX2
{

	class Terrain : public Node
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Terrain);

	public:
		virtual ~Terrain ();

		virtual int DetachChild (Movable* child);

		// members
		inline int GetRowQuantity () const;
		inline int GetColQuantity () const;
		inline int GetSize () const;
		inline float GetSpacing () const;
		float GetHeight (float x, float y) const;
		AVector GetNormal (float x, float y) const;

		TerrainPage* GetPage (int row, int col);
		TerrainPage* GetCurrentPage (float x, float y) const;
		bool GetPageIndex (int &outRow, int &outCol, TerrainPage *page);
		TerrainPagePtr ReplacePage (int row, int col, TerrainPage* newPage);

		void UpdateHoles ();

		EditTerrainMaterial *GetEidtMaterial ();
		EditTerrainMaterial *GetSimpleMaterial ();
		Shine *GetShine ();

		// 在radius，随机生成num个植被
		void AddJunglers (Texture2D *tex, APoint center, float radius, int num, 
			float width, float height, float lower);
		void RemoveJunglers (Texture2D *tex, APoint center, float radius, int num);

		void SetJunglerFrequency (float fre);
		float GetJunglerFrequency ();
		void SetJunglerStrength (float strength);
		float GetJunglerStrength ();

	protected:
		Terrain();

		int mNumRows, mNumCols;
		int mSize;
		float mMinElevation, mMaxElevation, mSpacing;
		TerrainPagePtr** mPages;

		VertexFormatPtr mVFormatEdit;
		EditTerrainMaterialPtr mMtlEdit;

		ShinePtr mShine;
		float mJunglerFrequency;
		float mJunglerStrength;
	};

	PX2_REGISTER_STREAM(Terrain);
	typedef Pointer0<Terrain> TerrainPtr;
#include "PX2Terrain.inl"

}

#endif