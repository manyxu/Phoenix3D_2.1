/*
*
* ÎÄ¼þÃû³Æ	£º	PX2DeletingMan.cpp
*
*/

#include "PX2DeletingManager.hpp"
#include "PX2Time.hpp"
#include "PX2Node.hpp"
#include "PX2Scene.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// DeletingObj
//----------------------------------------------------------------------------
DeletingObj::DeletingObj()
	:
AddedTime(0.0f),
StopDelayTime(0.0f),
DeleteDelayTime(0.0f)
{
}
//----------------------------------------------------------------------------
DeletingObj::~DeletingObj()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// DeletingManager
//----------------------------------------------------------------------------
DeletingManager::DeletingManager ()
	:
mElapsedTime(0.2f)
{
}
//----------------------------------------------------------------------------
DeletingManager::~DeletingManager ()
{
}
//----------------------------------------------------------------------------
void DeletingManager::Clear ()
{
	mStopingObjs.clear();
	mDeletingObjs.clear();
}
//----------------------------------------------------------------------------
void DeletingManager::AddDeletingObj (Movable *mov,	float stopDelayTime,
	float deleteAfterStopDelayTime)
{
	DeletingObj *deletingObj = new0 DeletingObj();
	deletingObj->Mov = mov;
	deletingObj->TheParent = (Node*)mov->GetParent();
	deletingObj->AddedTime = (float)GetTimeInSeconds();
	deletingObj->StopDelayTime = stopDelayTime;
	deletingObj->DeleteDelayTime = stopDelayTime+deleteAfterStopDelayTime;

	mStopingObjs.push_back(deletingObj);
}
//----------------------------------------------------------------------------
void DeletingManager::AddDeletingObj (Actor *actor, float stopDelayTime,
	float deleteAfterStopDelayTime)
{
	DeletingObj *deletingObj = new0 DeletingObj();
	deletingObj->TheActor = actor;
	deletingObj->TheScene = actor->GetScene();
	deletingObj->AddedTime = (float)GetTimeInSeconds();
	deletingObj->StopDelayTime = stopDelayTime;
	deletingObj->DeleteDelayTime = stopDelayTime+deleteAfterStopDelayTime;

	mStopingObjs.push_back(deletingObj);
}
//----------------------------------------------------------------------------
void DeletingManager::Update (double appSeconds, double elapsedSeconds)
{
	PX2_UNUSED(elapsedSeconds);

	mElapsedTime -= (float)elapsedSeconds;
	if (mElapsedTime > 0.0f)
	{
		return;
	}
	else
	{
		mElapsedTime = 0.2f;
		elapsedSeconds = mElapsedTime;
	}

	{
		std::list<DeletingObjPtr>::iterator it = mStopingObjs.begin();

		for (; it!=mStopingObjs.end();)
		{
			float elapsedSeconds = (float)appSeconds - (*it)->AddedTime;

			if (elapsedSeconds > (*it)->StopDelayTime)
			{
				if ((*it)->Mov)
				{
					(*it)->Mov->Stop();
				}

				if ((*it)->TheActor)
				{
					Movable *mov = (*it)->TheActor->GetMovable();
					if (mov)
					{
						mov->Stop();
					}
				}

				mDeletingObjs.push_back(*it);

				it = mStopingObjs.erase(it);
			}
			else
			{
				it++;
			}
		}
	}

	{
		std::list<DeletingObjPtr>::iterator it1 = mDeletingObjs.begin();
		for (; it1!=mDeletingObjs.end();)
		{
			float elapsedSeconds = (float)appSeconds - (*it1)->AddedTime;

			if (elapsedSeconds > (*it1)->DeleteDelayTime)
			{
				if ((*it1)->Mov && (*it1)->TheParent)
				{
					(*it1)->TheParent->DetachChild((*it1)->Mov);
				}

				if ((*it1)->TheActor && (*it1)->TheScene)
				{
					(*it1)->TheScene->RemoveActor((*it1)->TheActor);
				}

				it1 = mDeletingObjs.erase(it1);
			}
			else
			{
				it1++;
			}
		}
	}
}
//----------------------------------------------------------------------------
int DeletingManager::GetNumStopingObjs () const
{
	return (int)mStopingObjs.size();
}
//----------------------------------------------------------------------------	
int DeletingManager::GetNumDeletingObjs () const
{
	return (int)mDeletingObjs.size();
}
//----------------------------------------------------------------------------