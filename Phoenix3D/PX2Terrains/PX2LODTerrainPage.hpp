// PX2LODTerrainPage.hpp

#ifndef PX2LODTERRAINPAGE_HPP
#define PX2LODTERRAINPAGE_HPP

#include "PX2TerrainsPre.hpp"
#include "PX2TerrainPage.hpp"

namespace PX2
{

	class LODTerrainBlock;
	class LODTerrainVertex;

	class PX2_TERRAINS_ITEM LODTerrainPage : public TerrainPage
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LODTerrainPage);

	public:
		// size = 2^p + 1, p <= 7 (size = 3, 5, 9, 17, 33, 65, 129)
		LODTerrainPage (VertexFormat* vformat, int size, float* heights,
			const Float2& origin, float spacing);
		virtual ~LODTerrainPage ();

		void SetPixelTolerance (float tolerance);
		float GetPixelTolerance () const;

	protected:
		friend class LODTerrainBlock;

		void InitializeDerivedData ();

		// queue handlers
		void AddToQueue (unsigned short blockIndex);
		unsigned short RemoveFromQueue ();
		unsigned short ReadFromQueue (unsigned short index);

		bool IntersectFrustum (const Camera *camera);
		void SimplifyBlocks (const Camera* camera, const APoint &modelEye,
			const AVector &modelDir, bool closeAssumption);
		void SimplifyVertices (const APoint &modelEye,
			const AVector &modelDir, bool closeTerrainAssumption);

		// 地形简化
		friend class LODTerrain;
		void EnableBlocks ();
		void ResetBlocks ();
		void Simplify (const APoint &modelEye, const AVector &modelDir,
			bool closeAssumption);

		// 网格
		float GetTextureCoordinate (int index) const;
		void Render (LODTerrainBlock &block);
		void RenderTriangle (int t, int l, int r);
		void RenderBlocks ();

		// 可见集裁剪
		virtual void GetVisibleSet (Culler &culler, bool noCull);

		float mTextureSpacing;

		// 简化
		float mPixelTolerance, mWorldTolerance;
		mutable bool mNeedsTessellation;
		int *mLookup;

		/// (2^p+1) * (2^p+1)的顶点数组，行主序列
		LODTerrainVertex *mVertexs;
		VertexBufferAccessor mVBA;

		// maximum quantities
		int mTotalVQuantity, mTotalTQuantity, mTotalIQuantity;

		// quadtree of blocks
		int mBlockQuantity;
		LODTerrainBlock* mBlocks;

		// 记录最子层Block，
		unsigned short *mQueue;
		unsigned short mNumQueue;
		unsigned short mFront, mBack;
		unsigned short mNumUnprocessed;
		unsigned short mItemsInQueue;

	public_internal:
		// 高程获取函数为 z = h(x,y)，xy平面使用右手坐标系。如下图所示
		//
		// y
		// ^
		// | col 0   col 1
		// +--------+-------+
		// |   10   |  11   | row 1
		// +--------+-------+
		// |   00   |  01   | row 0
		// +--------+-------+--> x

		// 地形页(r,c)和(r,c+1)之间的缝合
		void StitchNextCol (LODTerrainPage *nextCol);
		void UnstitchNextCol (LODTerrainPage *nextCol);

		// 地形页(r,c)和(r+1,c)之间的缝合
		void StitchNextRow (LODTerrainPage *nextRow);
		void UnstitchNextRow (LODTerrainPage *nextRow);
	};

	PX2_REGISTER_STREAM(LODTerrainPage);
	typedef Pointer0<LODTerrainPage> LODTerrainPagePtr;
#include "PX2LODTerrainPage.inl"

}

#endif