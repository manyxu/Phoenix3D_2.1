/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AddingManager.hpp
*
*/

#include "PX2AddingManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// AddingObj
//----------------------------------------------------------------------------
AddingObj::AddingObj()
	:
AddedTime(0.0f),
DelayTime(0.0f),
DoResetPlay(true)
{
}
//----------------------------------------------------------------------------
AddingObj::~AddingObj()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// AddingManager
//----------------------------------------------------------------------------
AddingManager::AddingManager ()
	:
mElapsedTime(0.1f)
{
}
//----------------------------------------------------------------------------
AddingManager::~AddingManager ()
{
}
//----------------------------------------------------------------------------
void AddingManager::Clear ()
{
	mAddingObjs.clear();
}
//----------------------------------------------------------------------------
void AddingManager::AddAddingObjResetPlay (Movable *mov, float delayTime)
{
	AddingObj *addingObj = new0 AddingObj();
	addingObj->TheMov = mov;
	addingObj->AddedTime = (float)GetTimeInSeconds();
	addingObj->DelayTime = delayTime;
	addingObj->DoResetPlay = true;

	mAddingObjs.push_back(addingObj);
}
//----------------------------------------------------------------------------
void AddingManager::AddAddingObj (Node *parent, Movable *mov, 
	float delayTime, bool doResetPlay)
{
	AddingObj *addingObj = new0 AddingObj();
	addingObj->TheMov = mov;
	addingObj->TheNode = parent;
	addingObj->AddedTime = (float)GetTimeInSeconds();
	addingObj->DelayTime = delayTime;
	addingObj->DoResetPlay = doResetPlay;

	mAddingObjs.push_back(addingObj);
}
//----------------------------------------------------------------------------
void AddingManager::AddAddingObj (Scene *scene, Actor *actor, 
	float delayTime, bool doResetPlay)
{
	AddingObj *addingObj = new0 AddingObj();
	addingObj->TheActor = actor;
	addingObj->TheScene = scene;
	addingObj->AddedTime = (float)GetTimeInSeconds();
	addingObj->DelayTime = delayTime;
	addingObj->DoResetPlay = doResetPlay;

	mAddingObjs.push_back(addingObj);
}
//----------------------------------------------------------------------------
void AddingManager::Update (double appSeconds, double elapsedSeconds)
{
	mElapsedTime -= (float)elapsedSeconds;
	if (mElapsedTime > 0.0f)
		return;
	else
	{
		mElapsedTime = 0.1f;
		elapsedSeconds = mElapsedTime;
	}

	PX2_UNUSED(elapsedSeconds);

	std::list<AddingObjPtr>::iterator it = mAddingObjs.begin();
	for (; it!=mAddingObjs.end(); )	
	{
		float elapsedSeconds = (float)appSeconds - (*it)->AddedTime;

		if (elapsedSeconds > (*it)->DelayTime)
		{
			if ((*it)->TheScene && (*it)->TheActor)
			{
				(*it)->TheScene->AddActor((*it)->TheActor);
				
				if ((*it)->DoResetPlay)
				{
					Movable *mov = (*it)->TheActor->GetMovable();
					if (mov)
					{
						mov->ResetPlay();
					}
				}
			}

			if ((*it)->TheNode && (*it)->TheMov)
			{
				(*it)->TheNode->AttachChild((*it)->TheMov);

				if ((*it)->DoResetPlay)
				{
					(*it)->TheMov->ResetPlay();
				}
			}

			if ((0==(*it)->TheNode) && (*it)->TheMov)
			{
				if ((*it)->DoResetPlay)
				{
					(*it)->TheMov->ResetPlay();
				}
			}

			it = mAddingObjs.erase(it);
		}
		else
		{
			it++;
		}
	}
}
//----------------------------------------------------------------------------