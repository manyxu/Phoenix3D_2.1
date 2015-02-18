// PX2Skill_Activate.cpp

#include "PX2Skill.hpp"
#include "PX2Project.hpp"
#include "PX2Character.hpp"
#include "PX2SkillComponent.hpp"
#include "PX2SkillInstance.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Skill::ResetCD()
{
	SetOnCD(false);
	SetOnCDTime(0.0f);
}
//----------------------------------------------------------------------------
bool Skill::Activate()
{
	Scene *scene = PX2_PROJ.GetScene();
	if (!scene) return false;

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

	SkillComponent *skillComp = DynamicCast<SkillComponent>(
		mCharacter->GetComponentByName("SkillComponent"));
	if (skillComp)
	{
		assertion(false, "has no this component.");
		return false;
	}

	mIsActivatting = true;
	SetOnCD(true);
	SetOnCDTime(0.0f);

	float randomVal = Mathf::UnitRandom();
	if (randomVal > mActivateProbability)
		return true;

	mActivatedTimes++;

	const APoint &curPos = mCharacter->LocalTransform.GetTranslate();
	const AVector &faceDir = mCharacter->GetHeading();
	int aimTarget = skillComp->GetAimTarget();
	Character *aimChar = skillComp->GetAimTargetCharacter();
	int group = mCharacter->GetGroup();

	float radiusLength = GetMRadiusLength();
	float width = GetMWidth();
	float degree = GetMFanDegree();

	ShapeType shapeType = GetShapeType();
	int numRangeLock = GetNumRangeLock();
	AffectGroupType agt = GetAffectGroupType();

	if (NFT_NEAR == mNearFarType)
	{
		SkillInstance *inst = new0 SkillInstance(this);
		mSkillInstances.push_back(inst);

		int numAdded = 0;

		inst->SetAimTarget(aimTarget);

		if (IsRangeType()) // ·¶Ξ§
		{
			if (-1 == numRangeLock)
			{
				std::vector<Actor*> actors;
				scene->GetRangeActors(actors, curPos, radiusLength, true, GetSkillQueryBitSet());
				for (int i = 0; i < (int)actors.size(); i++)
				{
					Character *character = DynamicCast<Character>(actors[i]);

					if (character && !character->IsDead())
					{
						const APoint &targetPos = character->LocalTransform.GetTranslate();
						float targetRadius = character->GetRadius();

						if (IsInRange(curPos, radiusLength, width, faceDir, degree, targetPos,
							targetRadius, shapeType, false))
						{
							inst->AddTarget(character->GetID());
							numAdded++;
						}
					}
				}
			}
			else if (numRangeLock > 0)
			{
				if (AGT_SELF == agt)
				{
					inst->AddTarget(mCharacter->GetID());
					numAdded++;
				}

				std::vector<Actor*> actors;
				scene->GetRangeActors(actors, curPos, radiusLength, true, GetSkillQueryBitSet());
				for (int i = 0; i < (int)actors.size(); i++)
				{
					Character *character = DynamicCast<Character>(actors[i]);
					if (character && !character->IsDead() &&
						character != aimChar && character != mCharacter)
					{
						if ((AGT_ENEMYS == agt && character->GetGroup() != group) ||
							(AGT_SELF_GROUP==agt) && character->GetGroup()==group ||
							(AGT_SELF == agt && character->GetGroup() == group) ||
							(AGT_BOTH == agt))
						{
							const APoint &targetPos = character->LocalTransform.GetTranslate();
							float targetRadius = character->GetRadius();

							if (IsInRange(curPos, radiusLength, width, faceDir, degree, targetPos,
								targetRadius, shapeType, false) && numAdded < numRangeLock)
							{
								inst->AddTarget(character->GetID());
								numAdded++;
							}
						}
					}
				}
			}
		}
		else // µ¥Με
		{
			if (AGT_ENEMYS == agt || AGT_BOTH == agt)
			{
				Character *aimChar = skillComp->GetAimTargetCharacterAlive();
				if (aimChar && aimChar->IsContainAllBits(GetSkillQueryBitSet()))
				{
					const APoint &targetPos = aimChar->LocalTransform.GetTranslate();
					float targetRadius = aimChar->GetRadius();

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

			if (AGT_ENEMYS == this->GetAffectGroupType())
			{
				inst->SetAimTarget(aimTarget);
			}
			else if (AGT_SELF == this->GetAffectGroupType())
			{
				inst->SetAimTarget(mCharacter->GetID());
			}

			inst->Enter(mFirstSkillStep);

			multiAdd++;

			for (int i = 0; i < (int)actors.size(); i++)
			{
				Character *character = DynamicCast<Character>(actors[i]);
				if (character && !character->IsDead() && character != aimChar && character != mCharacter)
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
void Skill::DisActivate()
{
	mIsActivatting = false;
}
//----------------------------------------------------------------------------
std::bitset<PX2_ACTOR_BS_SIZE> Skill::GetSkillQueryBitSet()
{
	int myGroup = mCharacter->GetGroup();
	AffectGroupType agt = GetAffectGroupType();
	//bool isAbleToBuilding = IsAbleToBuilding();

	std::bitset<PX2_ACTOR_BS_SIZE> queryBits;

	//queryBits[Actor::BST_CHARACTER] = 1;
	//queryBits[Actor::BST_CANBEAIMED] = 1;

	//if (isAbleToBuilding)
	//	queryBits[Actor::BST_BUILDING] = 1;

	//if (1 == myGroup && agt == AGT_ENEMY)
	//	queryBits[Actor::BST_GROUP2] = 1;

	//if (1 == myGroup && agt == AGT_SELF)
	//	queryBits[Actor::BST_GROUP1] = 1;

	//if (2 == myGroup && agt == AGT_ENEMY)
	//	queryBits[Actor::BST_GROUP1] = 1;

	//if (2 == myGroup && agt == AGT_SELF)
	//	queryBits[Actor::BST_GROUP2] = 1;

	return queryBits;
}
//----------------------------------------------------------------------------