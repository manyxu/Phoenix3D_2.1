// PX2Selection.cpp

#include "PX2Selection.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2Actor.hpp"
#include "PX2Movable.hpp"
#include "PX2Time.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Selection::Selection()
{
}
//----------------------------------------------------------------------------
Selection::~Selection()
{
	Clear();
}
//----------------------------------------------------------------------------
void Selection::AddObject(PX2::Object *obj)
{
	assertion(obj != 0, "obj must not be 0.");

	if (IsObjectIn(obj))
		return;

	mObjects.push_back(obj);

	_UpdateSelect();

	Event *emt = 0;
	emt = SimuES_E::CreateEventX(SimuES_E::AddSelect);
	emt->SetData<Object*>(obj);
	EventWorld::GetSingleton().BroadcastingLocalEvent(emt);
}
//----------------------------------------------------------------------------
void Selection::RemoveObject(PX2::Object *obj)
{
	bool removed = false;

	std::vector<ObjectPtr>::iterator it = mObjects.begin();
	for (; it != mObjects.end(); it++)
	{
		if (obj == *it)
		{
			mObjects.erase(it);
			removed = true;
			break;
		}
	}

	if (removed)
	{
		_UpdateSelect();

		Event *emt = 0;
		emt = SimuES_E::CreateEventX(SimuES_E::RemoveSelect);
		emt->SetData<Object*>(obj);
		EventWorld::GetSingleton().BroadcastingLocalEvent(emt);
	}
}
//----------------------------------------------------------------------------
PX2::Object *Selection::GetObjectAt(int i)
{
	if (0 <= i&&i < (int)mObjects.size())
		return mObjects[i];

	return 0;
}
//----------------------------------------------------------------------------
int Selection::GetNumObjects()
{
	return (int)mObjects.size();
}
//----------------------------------------------------------------------------
void Selection::Clear()
{
	for (int i = 0; i < (int)mObjects.size(); i++)
	{
		mObjects[i] = 0;
	}

	mObjects.clear();

	_UpdateSelect();

	Event *ent = 0;
	ent = SimuES_E::CreateEventX(SimuES_E::RemoveAllSelects);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
PX2::Object *Selection::GetFirstObject() const
{
	if ((int)mObjects.size() > 0)
		return mObjects[0];

	return 0;
}
//----------------------------------------------------------------------------
bool Selection::IsObjectIn(PX2::Object *obj)
{
	for (int i = 0; i < (int)mObjects.size(); i++)
	{
		if (obj == mObjects[i])
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Selection::Translate(PX2::AVector vec)
{
	for (int i = 0; i < (int)mObjects.size(); i++)
	{
		Movable *mov = DynamicCast<Movable>(mObjects[i]);
		if (mov)
		{
			APoint transBefore = mov->LocalTransform.GetTranslate();
			mov->LocalTransform.SetTranslate(transBefore + vec);
			mov->Update(GetTimeInSeconds(), false);
		}
	}

	_UpdateSelect();
}
//----------------------------------------------------------------------------
void Selection::TranslateTo(PX2::APoint pos)
{
	for (int i = 0; i < (int)mObjects.size(); i++)
	{
		Movable *mov = DynamicCast<Movable>(mObjects[i]);
		if (mov)
		{
			mov->LocalTransform.SetTranslate(pos);
			mov->Update(GetTimeInSeconds(), false);
		}
	}

	_UpdateSelect();
}
//----------------------------------------------------------------------------
void Selection::AddRolate(PX2::AVector vec)
{
	for (int i = 0; i < (int)mObjects.size(); i++)
	{
		Movable *mov = DynamicCast<Movable>(mObjects[i]);
		if (mov)
		{
			APoint rotation;
			Matrix3f mat = mov->LocalTransform.GetRotate();
			mat.ExtractEulerXYZ(rotation.X(), rotation.Y(), rotation.Z());
			rotation += vec;
			Matrix3f matTrans;
			matTrans.MakeEulerXYZ(rotation[0], rotation[1], rotation[2]);
			mov->LocalTransform.SetRotate(matTrans);
			mov->Update(GetTimeInSeconds(), false);
		}
	}

	_UpdateSelect();
}
//----------------------------------------------------------------------------
void Selection::AddScale(PX2::AVector vec)
{
	for (int i = 0; i < (int)mObjects.size(); i++)
	{
		Movable *mov = DynamicCast<Movable>(mObjects[i]);
		if (mov)
		{
			APoint scale = mov->LocalTransform.GetScale();
			scale += vec;
			mov->LocalTransform.SetUniformScale(scale.X());
		}
	}

	_UpdateSelect();
}
//----------------------------------------------------------------------------
void Selection::_UpdateSelect()
{
	mCenter = APoint::ORIGIN;
	mBoundRadius = 0.0f;

	APoint pos;
	Bound bound;
	int firstBound = true;

	int numObjects = (int)mObjects.size();
	for (int i = 0; i < numObjects; i++)
	{
		Object *obj = mObjects[i];
		Actor *actor = DynamicCast<Actor>(obj);
		Movable *mov = DynamicCast<Movable>(obj);
		if (actor)
		{
			pos += actor->LocalTransform.GetTranslate();

			Movable *mov = actor->GetNode();
			Movable *helpMov = actor->GetHelpNode();

			bool calHelpMovBound = true;

			if (mov)
			{
				if (0.0f != mov->WorldBound.GetRadius())
				{
					calHelpMovBound = false;

					if (firstBound)
					{
						bound = mov->WorldBound;
						firstBound = false;
					}
					else
					{
						bound.GrowToContain(mov->WorldBound);
					}
				}
				else
				{
					calHelpMovBound = true;
				}
			}
			else
			{
				calHelpMovBound = true;
			}

			if (calHelpMovBound && helpMov)
			{
				if (0.0f != helpMov->WorldBound.GetRadius())
				{
					if (firstBound)
					{
						bound = helpMov->WorldBound;
						firstBound = false;
					}
					else
					{
						bound.GrowToContain(helpMov->WorldBound);
					}
				}
			}
		}
		else if (mov)
		{
			pos += mov->WorldTransform.GetTranslate();

			if (0.0f != mov->WorldBound.GetRadius())
			{
				if (firstBound)
				{
					bound = mov->WorldBound;
					firstBound = false;
				}
				else
				{
					bound.GrowToContain(mov->WorldBound);
				}
			}
		}
	}

	if (numObjects > 0)
	{
		mCenter = pos / (float)numObjects;
		mBoundRadius = bound.GetRadius();
	}
}
//----------------------------------------------------------------------------