// PX2Manager.cpp

#include "PX2Scene.hpp"
#include "PX2SimulationEventType.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Scene::SetSceneManageType(SceneManageType type)
{
	mSceneManageType = type;

	mCellSpace = 0;

	if (SMT_OCTREE == mSceneManageType)
	{
	}
	else if (SMT_CELL2D == mSceneManageType)
	{
		mCellSpace = new0 CellSpace(this, mSize.Width, mSize.Height, 4, 20);
	}
}
//----------------------------------------------------------------------------
void Scene::SetSize(const Sizef &size)
{
	mSize = size;
}
//----------------------------------------------------------------------------
void Scene::SetViewPortProject(float left, float bottom, float width, 
	float height)
{
	Rectf rc;
	rc.Left = left;
	rc.Bottom = bottom;
	rc.Right = left + width;
	rc.Top = bottom + height;

	SetViewPortProject(rc);
}
//----------------------------------------------------------------------------
void Scene::SetViewPortProject(const Rectf &rc)
{
	mViewPort = rc;

	Event *ent = SimuES::CreateEventX(SimuES::Scene_ViewPortProjectChanged);
	ent->SetData<void*>(this);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void Scene::GetRangeActors(std::vector<Actor*> &actors, const APoint &center,
	float radius, bool useActorSelfRadius, const std::bitset<PX2_ACTOR_BS_SIZE> &bits)
{
	actors.clear();

	if (SMT_NONE == mSceneManageType)
	{
		for (int i = 0; i < GetNumChildren(); i++)
		{
			Actor *actor = DynamicCast<Actor>(GetChild(i));
			if (!actor->IsShow()) continue;

			const APoint &pos = actor->LocalTransform.GetTranslate();
			AVector dir = pos - center;
			float lengthSquare = dir.SquaredLength();

			float adjustLength = radius;
			if (useActorSelfRadius)
			{
				adjustLength += actor->GetRadius();
			}

			if (lengthSquare < adjustLength*adjustLength)
			{
				if (actor->IsContainAllBits(bits))
				{
					actors.push_back(actor);
				}
			}
		}
	}
	else
	{
		if (SMT_OCTREE == mSceneManageType)
		{
		}
		else if (SMT_CELL2D == mSceneManageType)
		{
			mCellSpace->CalculateNeighbors(actors, center, radius,
				useActorSelfRadius, bits);
		}
	}
}
//----------------------------------------------------------------------------
void Scene::GetRangeActorsExcept(Actor *except, std::vector<Actor*> &actors,
	const APoint &center, float radius, bool useActorSelfRadius,
	const std::bitset<PX2_ACTOR_BS_SIZE> &bits)
{
	GetRangeActors(actors, center, radius, useActorSelfRadius, bits);

	std::vector<Actor*>::iterator it = actors.begin();
	for (; it != actors.end();)
	{
		if (except == *it)
		{
			it = actors.erase(it);
		}
		else
		{
			it++;
		}
	}
}
//----------------------------------------------------------------------------