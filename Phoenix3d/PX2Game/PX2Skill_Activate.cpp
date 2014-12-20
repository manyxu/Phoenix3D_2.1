/*
*
* 文件名称	：	PX2Skill_Activate.cpp
*
*/

#include "PX2Skill.hpp"
#include "PX2Character.hpp"
#include "PX2Project.hpp"
#include "PX2Scene.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
bool Skill::IsActivateHasTimes () const
{
	if (mActivateAllowTimes < 0)
		return true;

	return mActivateAllowTimes>mActivatedTimes;
}
//----------------------------------------------------------------------------
std::bitset<PX2_ACTOR_BS_SIZE> Skill::GetSkillQueryBitSet ()
{
	int myGroup = mCharacter->GetGroup();
	AffectGroupType agt = GetAffectGroupType();
	bool isAbleToBuilding = IsAbleToBuilding(); 

	std::bitset<PX2_ACTOR_BS_SIZE> queryBits;

	queryBits[Actor::BST_CHARACTER] = 1;
	queryBits[Actor::BST_CANBEAIMED] = 1;

	if (isAbleToBuilding)
		queryBits[Actor::BST_BUILDING] = 1;

	if (1 == myGroup && agt==AGT_ENEMY)
		queryBits[Actor::BST_GROUP2] = 1;

	if (1 == myGroup && agt==AGT_SELF)
		queryBits[Actor::BST_GROUP1] = 1;

	if (2 == myGroup && agt==AGT_ENEMY)
		queryBits[Actor::BST_GROUP1] = 1;

	if (2 == myGroup && agt==AGT_SELF)
		queryBits[Actor::BST_GROUP2] = 1;

	return queryBits;
}
//----------------------------------------------------------------------------
bool Skill::IsCallOver () const
{
	bool isOver = true;

	for (int i=0; i<(int)mSkillInstances.size(); i++)
	{
		if (!mSkillInstances[i]->IsSkillCallOver())
			isOver = false;
	}

	return isOver;
}
//----------------------------------------------------------------------------
bool Skill::Activate ()
{
	Project *proj = Project::GetSingletonPtr();
	if (!proj)
		return false;

	Scene *scene = proj->GetScene();
	if (!scene)
		return false;

	if (!mCharacter)
		return false;

	if (!mFirstSkillStep)
		return false;

	if (mActivateAllowTimes >= 0)
	{
		if (mActivatedTimes >= mActivateAllowTimes)
			return false;
	}

	if (IsOnCD())
		return false;

	mIsActivatting = true;
	SetOnCD(true);
	SetOnCDTime(0.0f);

	float randomVal = Mathf::UnitRandom();
	if (randomVal > mActivateProbability)
	{
		return true;
	}

	mActivatedTimes++;

	const APoint &curPos = mCharacter->GetPosition();
	const AVector &faceDir = mCharacter->GetHeading();
	int aimTarget = mCharacter->GetAimTarget();
	Character *aimChar = mCharacter->GetAimTargetCharacter();
	int group = mCharacter->GetGroup();
	float radiusLength = GetMRadiusLength();
	float width = GetMWidth();
	float degree = GetMFanDegree();
	ShapeType shapeType = GetShapeType ();
	int numTargetsLock = GetNumTargetsLock();
	AffectGroupType agt = GetAffectGroupType();

	if (RT_NEAR == mRangeType)
	{
		SkillInstance *inst = new0 SkillInstance(this);
		mSkillInstances.push_back(inst);

		int numAdded = 0;

		inst->SetAimTarget(aimTarget);

		if (IsRangeAffect()) // 范围
		{
			if (-1 == numTargetsLock)
			{
				std::vector<Actor*> actors;
				scene->GetRangeActors(actors, curPos, radiusLength, true, GetSkillQueryBitSet());
				for (int i=0; i<(int)actors.size(); i++)
				{
					Character *character = DynamicCast<Character>(actors[i]);

					if (character && !character->IsDead())
					{					
						const APoint &targetPos = character->GetPosition();
						float targetRadius = character->GetSelfRadius();

						if (IsInRange(curPos, radiusLength, width, faceDir, degree, targetPos, 
							targetRadius, shapeType, false))
						{
							inst->AddTarget(character->GetID());
							numAdded++;
						}
					}
				}
			}
			else if (numTargetsLock > 0)
			{
				if (AGT_SELF == agt)
				{
					inst->AddTarget(mCharacter->GetID());
					numAdded++;
				}

				std::vector<Actor*> actors;
				scene->GetRangeActors(actors, curPos, radiusLength, true, GetSkillQueryBitSet());
				for (int i=0; i<(int)actors.size(); i++)
				{
					Character *character = DynamicCast<Character>(actors[i]);
					if (character && !character->IsDead() && 
						character!=aimChar && character!=mCharacter)
					{
						if ((AGT_ENEMY==agt && character->GetGroup()!=group) ||	
							(AGT_SELF==agt && character->GetGroup()==group) ||
							(AGT_BOTH==agt))
						{
							const APoint &targetPos = character->GetPosition();
							float targetRadius = character->GetSelfRadius();

							if (IsInRange(curPos, radiusLength, width, faceDir, degree, targetPos, 
								targetRadius, shapeType, false) && numAdded<numTargetsLock)
							{
								inst->AddTarget(character->GetID());
								numAdded++;
							}
						}
					}
				}
			}
		}
		else // 单体
		{
			if (AGT_ENEMY==agt || AGT_BOTH==agt)
			{
				Character *aimChar = mCharacter->GetAimTargetCharacter();
				if (aimChar && aimChar->IsContainAllBits(GetSkillQueryBitSet()))
				{
					const APoint &targetPos = aimChar->GetPosition();
					float targetRadius = aimChar->GetSelfRadius();

					if (IsInRange(curPos, radiusLength, width, faceDir, degree, targetPos, 
						targetRadius, shapeType, false))
					{
						inst->AddTarget(aimChar->GetID());
						numAdded++;
					}
				}
			}
			else if (AGT_SELF == agt)
			{
				inst->AddTarget(mCharacter->GetID());
				numAdded++;
			}
		}

		inst->Enter(mFirstSkillStep);
	}
	else
	{
		int multiAdd = 0;

		if (1 == mNumMultiInstance)
		{
			SkillInstance *inst = new0 SkillInstance(this);
			mSkillInstances.push_back(inst);
			inst->SetAimTarget(aimTarget);
			inst->Enter(mFirstSkillStep);

			multiAdd++;
		}
		else if (mNumMultiInstance > 1)
		{
			std::vector<Actor*> actors;
			scene->GetRangeActors(actors, curPos, radiusLength, true, GetSkillQueryBitSet());

			SkillInstance *inst = new0 SkillInstance(this);
			mSkillInstances.push_back(inst);

			if (AGT_ENEMY==this->GetAffectGroupType())
			{
				inst->SetAimTarget(aimTarget);
			}
			else if (AGT_SELF==this->GetAffectGroupType())
			{
				inst->SetAimTarget(mCharacter->GetID());
			}

			inst->Enter(mFirstSkillStep);

			multiAdd++;

			for (int i=0; i<(int)actors.size(); i++)
			{
				Character *character = DynamicCast<Character>(actors[i]);
				if (character && !character->IsDead() &&  character!=aimChar && character!=mCharacter)
				{
					SkillInstance *inst1 = new0 SkillInstance(this);
					mSkillInstances.push_back(inst1);
					inst1->SetAimTarget(character->GetID());
					inst->SetBeShared(true);
					inst1->Enter(mFirstSkillStep);

					multiAdd++;
				}

				if (multiAdd >= mNumMultiInstance)
					break;
			}
		}
	}

	return true;
}
//----------------------------------------------------------------------------
void Skill::DisActivate ()
{
	mIsActivatting = false;
}
//----------------------------------------------------------------------------
void Skill::ResetCD ()
{
	SetOnCD(false);
	SetOnCDTime(0.0f);
}
//----------------------------------------------------------------------------
void Skill::ClearSkillInstance ()
{
	mSkillInstances.clear();
}
//----------------------------------------------------------------------------