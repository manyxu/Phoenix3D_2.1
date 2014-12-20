/*
*
* ÎÄ¼þÃû³Æ	£º	PX2CellSpace.inl
*
*/

#include "PX2CellSpace.hpp"
#include "PX2Actor.hpp"
#include "PX2Scene.hpp"
using namespace PX2;

//-----------------------------------------------------------------------------
// Cell
//-----------------------------------------------------------------------------
Cell::Cell (const APoint &min, const APoint &max)
{
	AlignedBox = AxisAlignedBox3f(min, max);
}
//-----------------------------------------------------------------------------
Cell::~Cell ()
{
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// CellSpace
//-----------------------------------------------------------------------------
CellSpace::CellSpace (Scene *scene, float length, float width, 
	int numCellsLength,	int numCellsWidth)
	:
mScene(scene),
mSpaceLength(length),
mSpaceWidth(width),
mNumCellsLength(numCellsLength),
mNumCellsWidth(numCellsWidth)
{
	mCellLength = mSpaceLength/mNumCellsLength;
	mCellWidth = mSpaceWidth/mNumCellsWidth;

	for (int b=0; b<mNumCellsWidth; b++)
	{
		for (int a=0; a<mNumCellsLength; a++)
		{
			float left  = a * mCellLength;
			float right = left + mCellLength;
			float but   = b * mCellWidth;
			float top   = but + mCellWidth;

			APoint min(left, but, 0.0f);
			APoint max(right, top, 0.0f);

			mCells.push_back(Cell(min, max));
		}
	}
}
//-----------------------------------------------------------------------------
void CellSpace::AddActor (Actor *actor)
{
	int index = PositionToIndex(actor->GetPosition());
	actor->SetSceneContainerIndex(index);

	mCells[index].Members.push_back(actor);
}
//-----------------------------------------------------------------------------
void CellSpace::UpdateActor (Actor *actor)
{
	int oldIndex = actor->GetSceneContainerIndex();
	if (-1 != oldIndex)
	{
		int newIndex = PositionToIndex(actor->GetPosition());

		if (newIndex == oldIndex)
			return;

		mCells[oldIndex].Members.remove(actor);
		mCells[newIndex].Members.push_back(actor);

		actor->SetSceneContainerIndex(newIndex);
	}
}
//-----------------------------------------------------------------------------
void CellSpace::RemoveActor (Actor *actor)
{
	int index = actor->GetSceneContainerIndex();
	if (-1 != index)
	{
		mCells[index].Members.remove(actor);
	}
}
//-----------------------------------------------------------------------------
void CellSpace::CalculateNeighbors (std::vector<Actor*> &actors, 
	const APoint &targetPos, float queryRadius, bool useActorSelfRadius, 
	const std::bitset<PX2_ACTOR_BS_SIZE> &bits)
{
	AVector radiusDir = AVector(queryRadius, queryRadius, queryRadius);
	APoint min = targetPos - radiusDir;
	APoint max = targetPos + radiusDir;

	AxisAlignedBox3f queryBox(min, max);

	std::vector<Cell>::iterator curCell=mCells.begin(); 
	for (; curCell!=mCells.end(); ++curCell)
	{
		if (curCell->AlignedBox.TestIntersection(queryBox) &&
			!curCell->Members.empty())
		{
			std::list<Actor*>::iterator it = curCell->Members.begin();
			for (; it!=curCell->Members.end(); ++it)
			{   
				if (!(*it)->IsVisible())
					continue;

				AVector disDir = (*it)->GetPosition() - targetPos;
				float distanceSquared = disDir.SquaredLength();

				float adjustDist = queryRadius;
				if (useActorSelfRadius)
				{
					adjustDist += (*it)->GetSelfRadius();
				}

				if (distanceSquared <= adjustDist*adjustDist)
				{
					if ((*it)->IsContainAllBits(bits))
					{
						actors.push_back(*it);
					}
				}
			}
		}
	}
}
//-----------------------------------------------------------------------------
void CellSpace::EmptyCells ()
{
	std::vector<Cell >::iterator it = mCells.begin();

	for (; it!=mCells.end(); ++it)
	{
		it->Members.clear();
	}
}
//-----------------------------------------------------------------------------
int CellSpace::PositionToIndex (const APoint &pos) const
{
	float posA = pos.X();
	float posB = pos.Y();

	int index = (int)(posA/mCellLength) + 
		((int)(posB/mCellWidth) * mNumCellsLength);

	if (index > (int)mCells.size()-1)
		index = (int)mCells.size()-1;

	if (index < 0)
		index = 0;

	return index;
}
//-----------------------------------------------------------------------------