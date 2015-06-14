// PX2RedoUndo.cpp

#include "PX2RedoUndo.hpp"
#include "PX2Selection.hpp"
#include "PX2Movable.hpp"
#include "PX2SimulationEventType.hpp"
#include "PX2Creater.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
URDo::URDo()
{
}
//----------------------------------------------------------------------------
URDo::~URDo()
{
}
//----------------------------------------------------------------------------
void URDo::OnUnDo()
{
}
//----------------------------------------------------------------------------
void URDo::OnReDo()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// ActorTransCommand
//----------------------------------------------------------------------------
MovableTransURDo::MovableTransURDo()
{
	int num = PX2_SELECTION.GetNumObjects();

	mObjects.resize(num);
	mPositions.resize(num);
	mRotations.resize(num);
	mRotationMats.resize(num);
	mScales.resize(num);

	mPositionsReDo.resize(num);
	mRotationsReDo.resize(num);
	mRotationMatsReDo.resize(num);
	mScalesReDo.resize(num);

	for (int i = 0; i < num; i++)
	{
		Object *obj = PX2_SELECTION.GetObjectAt(i);
		Movable *mov = DynamicCast<Movable>(obj);
		if (mov)
		{
			mObjects[i] = mov;
			mPositions[i] = mov->LocalTransform.GetTranslate();
			mRotationMats[i] = mov->LocalTransform.GetRotate();
			mScales[i] = mov->LocalTransform.GetScale();
		}
	}
}
//----------------------------------------------------------------------------
MovableTransURDo::~MovableTransURDo()
{
}
//----------------------------------------------------------------------------
void MovableTransURDo::OnUnDo()
{
	for (int i = 0; i < (int)mObjects.size(); i++)
	{
		Movable *mov = DynamicCast<Movable>(mObjects[i]);
		if (mov)
		{
			mPositionsReDo[i] = mov->LocalTransform.GetTranslate();
			mRotationMatsReDo[i] = mov->LocalTransform.GetRotate();
			mScalesReDo[i] = mov->LocalTransform.GetScale();

			mov->LocalTransform.SetTranslate(mPositions[i]);
			mov->LocalTransform.SetRotate(mRotationMats[i]);
			mov->LocalTransform.SetScale(mScales[i]);

			mov->Update(GetTimeInSeconds(), 0.0f, false);
		}
	}
}
//----------------------------------------------------------------------------
void MovableTransURDo::OnReDo()
{
	for (int i = 0; i < (int)mObjects.size(); i++)
	{
		Movable *mov = DynamicCast<Movable>(mObjects[i]);
		if (mov)
		{
			mov->LocalTransform.SetTranslate(mPositionsReDo[i]);
			mov->LocalTransform.SetRotate(mRotationMatsReDo[i]);
			mov->LocalTransform.SetScale(mScalesReDo[i]);

			mov->Update(GetTimeInSeconds(), 0.0f, false);
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// ObjectAddDeleteURDo
//----------------------------------------------------------------------------
ObjectAddDeleteURDo::ObjectAddDeleteURDo(bool isAdd,
	PX2::Object *object)
{
	mIsAdd = isAdd;
	mObject = object;

	Movable *mov = DynamicCast<Movable>(mObject);
	if (mov)
	{
		mParent = mov->GetParent();
	}

	Controller *ctrl = DynamicCast<Controller>(mObject);
	if (ctrl)
	{
		mParent = ctrl->GetControlledable();
	}

	Controller *comp = DynamicCast<Controller>(mObject);
	if (comp)
	{
		mParent = comp->GetControlledable();
	}
}
//----------------------------------------------------------------------------
ObjectAddDeleteURDo::~ObjectAddDeleteURDo()
{
}
//----------------------------------------------------------------------------
void ObjectAddDeleteURDo::OnUnDo()
{
	if (mIsAdd)
	{
		PX2_CREATER.RemoveObject(mObject, false);
	}
	else
	{
		PX2_CREATER.AddObject(mParent, mObject, false);
	}
}
//----------------------------------------------------------------------------
void ObjectAddDeleteURDo::OnReDo()
{
	if (mIsAdd)
	{
		PX2_CREATER.AddObject(mParent, mObject, false);
	}
	else
	{
		PX2_CREATER.RemoveObject(mObject, false);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// URDoManager
//----------------------------------------------------------------------------
URDoManager::URDoManager()
{

}
//----------------------------------------------------------------------------
URDoManager::~URDoManager()
{

}
//----------------------------------------------------------------------------
void URDoManager::Clear()
{
	mUnDoCommands.clear();
	mReDoCommands.clear();

	PX2::Event *ent = SimuES_E::CreateEventX(SimuES_E::NoUnDo);
	PX2_EW.BroadcastingLocalEvent(ent);

	PX2::Event *ent1 = SimuES_E::CreateEventX(SimuES_E::NoReDo);
	PX2_EW.BroadcastingLocalEvent(ent1);
}
//----------------------------------------------------------------------------
bool URDoManager::IsHasUnDo() const
{
	return (int)mUnDoCommands.size() > 0;
}
//----------------------------------------------------------------------------
bool URDoManager::IsHasReDo() const
{
	return (int)mReDoCommands.size() > 0;
}
//----------------------------------------------------------------------------
void URDoManager::PushUnDo(URDo *command)
{
	mUnDoCommands.push_back(command);

	if ((int)mUnDoCommands.size() > 21)
		mUnDoCommands.pop_front();

	PX2::Event *ent = SimuES_E::CreateEventX(SimuES_E::PushUnDo);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void URDoManager::UnDo()
{
	if ((int)mUnDoCommands.size() > 0)
	{
		URDoPtr command = mUnDoCommands.back();
		if (command)
			command->OnUnDo();

		mReDoCommands.push_back(command);
		mUnDoCommands.pop_back();

		PX2::Event *ent = SimuES_E::CreateEventX(SimuES_E::UnDo);
		EventWorld::GetSingleton().BroadcastingLocalEvent(ent);

		if ((int)mUnDoCommands.size() == 0)
		{
			PX2::Event *ent1 = SimuES_E::CreateEventX(SimuES_E::NoUnDo);
			EventWorld::GetSingleton().BroadcastingLocalEvent(ent1);
		}
	}
}
//----------------------------------------------------------------------------
void URDoManager::ReDo()
{
	if ((int)mReDoCommands.size() > 0)
	{
		URDoPtr command = mReDoCommands.back();
		if (command)
			command->OnReDo();

		mUnDoCommands.push_back(command);
		mReDoCommands.pop_back();

		PX2::Event *ent = SimuES_E::CreateEventX(SimuES_E::ReDo);
		PX2_EW.BroadcastingLocalEvent(ent);

		if ((int)mReDoCommands.size() == 0)
		{
			PX2::Event *ent1 = SimuES_E::CreateEventX(SimuES_E::NoReDo);
			PX2_EW.BroadcastingLocalEvent(ent1);
		}
	}
}
//----------------------------------------------------------------------------