/*
*
* 文件名称	：	PX2CellSpace.hpp
*
*/

#ifndef PX2CELLSPACE_HPP
#define PX2CELLSPACE_HPP

#include "PX2GamePre.hpp"
#include "PX2AxisAlignedBox3.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2APoint.hpp"

namespace PX2
{

	class Actor;
	class Scene;

	class Cell
	{
	public:
		Cell (const APoint &min, const APoint &max);
		~Cell ();

		std::list<Actor*> Members;
		AxisAlignedBox3f AlignedBox;

	private:
		Cell ();
	};

	class CellSpace
	{
	public:
		
		// axisType=0 在XY平面， axisType=1 在XZ平面
		CellSpace (Scene *scene, float length, float width, int numCellsLength,
			int numCellsWidth);

		void AddActor (Actor *actor);
		void UpdateActor (Actor *actor);
		void RemoveActor (Actor *actor);
		void CalculateNeighbors (std::vector<Actor*> &actors, 
			const APoint &targetPos, float queryRadius, 
			bool useActorSelfRadius, const std::bitset<PX2_ACTOR_BS_SIZE> &bits);
		void EmptyCells ();

	private:
		CellSpace ();
		int PositionToIndex (const APoint &pos) const;

		Scene *mScene;
		std::vector<Cell> mCells;
		std::vector<Actor*>::iterator mCurNeightbor;
		float mSpaceLength;
		float mSpaceWidth;
		int mNumCellsLength;
		int mNumCellsWidth;
		float mCellLength;
		float mCellWidth;
	};
	typedef Pointer0<CellSpace> CellSpacePtr;

}

#endif