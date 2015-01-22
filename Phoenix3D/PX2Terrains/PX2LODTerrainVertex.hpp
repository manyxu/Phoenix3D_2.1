/*
*
* 文件名称	：	PX2LODTerrainVertex.hpp
*
*/

#ifndef PX2LODTERRAINVERTEX_HPP
#define PX2LODTERRAINVERTEX_HPP

#include "PX2TerrainsPre.hpp"
#include "PX2Assert.hpp"

namespace PX2
{

	/// LOD地形顶点类
	class LODTerrainVertex
	{
	public:
		LODTerrainVertex ();

		void SetDependent (int i, LODTerrainVertex *pkDependent);
		LODTerrainVertex *GetDependent (int i);
		bool IsEnabled () const;
		void Enable ();
		void Disable ();

	protected:
		LODTerrainVertex *mDependent[2];
		bool mEnabled; //< 该顶点是否参与网格世界
	};

#include "PX2LODTerrainVertex.inl"
}

#endif