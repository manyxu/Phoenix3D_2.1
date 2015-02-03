// PX2ActorPicker.cpp

#include "PX2ActorPicker.hpp"
#include "PX2Scene.hpp"
#include "PX2Picker.hpp"
using namespace PX2;

const ActorPickRecord ActorPicker::msInvalid;
//----------------------------------------------------------------------------
ActorPicker::ActorPicker()
{
	mTMin = 0.0f;
	mTMax = 0.0f;
}
//----------------------------------------------------------------------------
void ActorPicker::Execute(Scene* scene, const APoint& origin,
	const AVector& direction, float tmin, float tmax)
{
#ifdef _DEBUG
	if (tmin == -Mathf::MAX_REAL)
	{
		assertion(tmax == Mathf::MAX_REAL, "");
	}
	else
	{
		assertion(tmin == 0.0f && tmax > 0.0f, "");
	}
#endif

	mOrigin = origin;
	mDirection = direction;
	mTMin = tmin;
	mTMax = tmax;
	Records.clear();

	for (int i = 0; i < scene->GetNumChildren(); i++)
	{
		Actor *actor = DynamicCast<Actor>(scene->GetChild(i));
		if (actor)
		{
			if (!actor->IsShow()) continue;

			if (!actor->IsPickable()) continue;

			Picker picker;

			Movable *node = actor->GetNode();
			Movable *helpNode = actor->GetHelpNode();
			if (helpNode && helpNode->IsShow())
			{
				picker.Execute(helpNode, mOrigin, mDirection, mTMin, mTMax);
			}
			else
			{
				picker.Execute(node, mOrigin, mDirection, mTMin, mTMax);
			}

			if ((int)picker.Records.size() > 0)
			{
				PickRecord pickRecord = picker.GetClosestToZero();

				ActorPickRecord record;
				record.Intersected = actor;
				record.T = pickRecord.T;

				Records.push_back(record);
			}
		}
	}
}
//----------------------------------------------------------------------------
const ActorPickRecord& ActorPicker::GetClosestToZero() const
{
	if (Records.size() == 0)
		return msInvalid;

	float closestLength = Mathf::FAbs(Records[0].T);
	int closestIndex = 0;
	for (int i = 1; i < (int)Records.size(); i++)
	{
		float tmpLength = Mathf::FAbs(Records[i].T);
		if (tmpLength < closestLength)
		{
			closestLength = tmpLength;
			closestIndex = i;
		}
	}
	return Records[closestIndex];
}
//----------------------------------------------------------------------------