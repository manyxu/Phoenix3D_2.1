/*
*
* 文件名称	：	PX2SkillInstance.cpp
*
*/

#include "PX2SkillInstance.hpp"
#include "PX2Skill.hpp"
#include "PX2SkillActor.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Character.hpp"
#include "PX2Character.hpp"
#include "PX2SkillStep.hpp"
#include "PX2SkillStepRangeTime.hpp"
#include "PX2SkillStepFarTrack.hpp"
#include "PX2SkillStepLink.hpp"
#include "PX2Project.hpp"
#include "PX2Scene.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Gameable, SkillInstance);
PX2_IMPLEMENT_STREAM(SkillInstance);
PX2_IMPLEMENT_FACTORY(SkillInstance);
PX2_IMPLEMENT_DEFAULT_NAMES(Gameable, SkillInstance);

//----------------------------------------------------------------------------
int SkillInstance::msNextID = 0;
//----------------------------------------------------------------------------
int SkillInstance::GetNextID ()
{
	++msNextID;
	return msNextID;
}
//----------------------------------------------------------------------------
SkillInstance::SkillInstance (Skill *skill)
	:
mSkill(skill),
mIsShared(false),
mIsSkillCallOver(false),
mIsCalingCallOver(false),
mCalingCallOverTime(0.0f),
mCallOverTime(0.0f),
mIsOver(false),
mCurSkillStepRunTime(0.0f),
mAnimTarget(-1),
mIsLinked(false)
{
	mCurInstanceID = GetNextID();
}
//----------------------------------------------------------------------------
SkillInstance::~SkillInstance ()
{
}
//----------------------------------------------------------------------------
void SkillInstance::Update (double appSeconds, double elapsedSeconds)
{
	PX2_UNUSED(appSeconds);

	if (IsOver())
		return;

	if (!mCurSkillStep)
		return;

	if (mIsCalingCallOver)
	{
		mCalingCallOverTime += (float)elapsedSeconds;

		if (mCalingCallOverTime >= mCallOverTime)
		{
			mIsSkillCallOver = true;
			mIsCalingCallOver = false;
			mCalingCallOverTime = 0.0f;
		}
	}

	Scene *scene = PX2_PROJ.GetScene();
	SkillStepRangeTime *stepTimeRange = DynamicCast<SkillStepRangeTime>(mCurSkillStep);
	SkillStepFarTrack *stepFarTrack = DynamicCast<SkillStepFarTrack>(mCurSkillStep);
	SkillStepLink *stepLink = DynamicCast<SkillStepLink>(mCurSkillStep);

	mCurSkillStepRunTime += (float)elapsedSeconds;

	if (stepTimeRange)
	{
		float time = stepTimeRange->GetTime();

		if (mCurSkillStepRunTime >= time)
		{
			Enter(mCurSkillStep->GetNextStep());
		}
	}
	else if (stepFarTrack)
	{
		bool isOver = false;
		SkillActor *skillActor = (SkillActor*)GetSkillActor(mAnimTarget);

		if (skillActor)
		{
			isOver = skillActor->IsOver();
		}

		if (!isOver)
		{
			if (stepFarTrack->IsDoDamageOnTrack())
			{
				const APoint &saPostion = skillActor->GetPosition();
				float rangeRadius = mSkill->GetMRadiusLength();
				
				RemoveAllTargets();

				std::vector<Actor*> actors;
				scene->GetRangeActors(actors, skillActor->GetPosition(), rangeRadius, false,
					mSkill->GetSkillQueryBitSet());
				for (int i=0; i<(int)actors.size(); i++)
				{
					Character *rangeChar = DynamicCast<Character>(actors[i]);
					if (rangeChar && !rangeChar->IsDead())
					{
						const APoint &rangeCharPos = rangeChar->GetPosition();
						float rangeCharRadius = rangeChar->GetSelfRadius();

						if (Skill::IsInRange(saPostion, rangeRadius, 0.0f, AVector::ZERO, 0.0f,
							rangeCharPos, rangeCharRadius, Skill::ST_SPHERE, false))
						{
							AddTarget(rangeChar->GetID());
						}
					}
				}

				stepFarTrack->SetCurTrackSkillInstance(this);
				stepFarTrack->OnTrack(this);
				const std::string &scriptHandler_OnTrack = stepFarTrack->GetScriptHandler_OnTrack();
				if (!scriptHandler_OnTrack.empty())
				{
					stepFarTrack->CallString(scriptHandler_OnTrack.c_str());
				}
				stepFarTrack->SetCurTrackSkillInstance(0);

			} // end if (stepFarTrack->IsDoDamageOnTrack())
		}
		else
		{
			if (Skill::RT_FAR == mSkill->GetRangeType())
			{
				float rangeRadius = mSkill->GetMRadiusLength();
				float rangeWidth = mSkill->GetMWidth();
				bool isRange = mSkill->IsRangeAffect();
				int numTargetsLock = mSkill->GetNumTargetsLock();

				Skill::AffectGroupType agt = mSkill->GetAffectGroupType();
				Character *me = mSkill->GetCharacter();
				SkillActor *skillActor = (SkillActor*)GetSkillActor(mAnimTarget);

				RemoveAllTargets();

				if (skillActor)
				{
					const APoint &saPostion = skillActor->GetPosition();
					Character *targetActor = DynamicCast<Character>(scene->GetActorByID(skillActor->GetTargetID()));

					if (!isRange)
					{
						if (targetActor && !targetActor->IsDead() && targetActor->IsContainAllBits(mSkill->GetSkillQueryBitSet()))
						{
							AddTarget(targetActor->GetID());
						}
					}
					else
					{
						int addedNum = 0;

						if (-1 == numTargetsLock)
						{
							std::vector<Actor*> actors;
							scene->GetRangeActors(actors, skillActor->GetPosition(), rangeRadius, true, mSkill->GetSkillQueryBitSet());
							for (int i=0; i<(int)actors.size(); i++)
							{
								Character *rangeChar = DynamicCast<Character>(actors[i]);
								if (rangeChar && !rangeChar->IsDead())
								{
									const APoint &rangeCharPos = rangeChar->GetPosition();
									float rangeCharRadius = rangeChar->GetSelfRadius();

									if (Skill::IsInRange(saPostion, rangeRadius, rangeWidth, AVector::ZERO, 0.0f,
										rangeCharPos, rangeCharRadius, mSkill->GetShapeType(), false))
									{
										AddTarget(rangeChar->GetID());
										addedNum++;
									}
								}
							}
						}
						else if (numTargetsLock > 0)
						{
							std::vector<Actor*> actors;
							scene->GetRangeActors(actors, skillActor->GetPosition(), rangeRadius, true, mSkill->GetSkillQueryBitSet());
							for (int i=0; i<(int)actors.size(); i++)
							{
								Character *rangeChar = DynamicCast<Character>(actors[i]);
								if (rangeChar && !rangeChar->IsDead() && targetActor!=rangeChar)
								{
									const APoint &rangeCharPos = rangeChar->GetPosition();
									float rangeCharRadius = rangeChar->GetSelfRadius();

									if (Skill::IsInRange(saPostion, rangeRadius, rangeWidth, AVector::ZERO, 0.0f,
										rangeCharPos, rangeCharRadius, mSkill->GetShapeType(), false))
									{
										if (addedNum < numTargetsLock)
										{
											AddTarget(rangeChar->GetID());
											addedNum++;
										}
									}
								}
							}
						} // end if (-1 == numTargetsLock)
					} // end if (!isRange)
				}

			} // end if (Skill::RT_FAR == mSkill->GetRangeType())

			Enter(mCurSkillStep->GetNextStep());
		}
	}
	else if (stepLink)
	{
		bool isOver = true;
		SkillActorLink *skillActorLink = (SkillActorLink*)GetSkillActor(mAnimTarget);

		if (skillActorLink)
		{
			if (skillActorLink->IsLinked() && !mIsLinked)
			{
				// cal targets
				RemoveAllTargets();

				Skill::RangeType rt = mSkill->GetRangeType();
				Skill::AffectGroupType agt = mSkill->GetAffectGroupType();

				if (Skill::RT_FAR == rt)
				{
					Character *me = mSkill->GetCharacter();
					int toActorID = skillActorLink->GetToActorID();
					Character *target = DynamicCast<Character>(scene->GetActorByID(toActorID));
					if (target && !target->IsDead() && target->IsContainAllBits(mSkill->GetSkillQueryBitSet()))
					{
						AddTarget(toActorID);
					}
				}
				else
				{
					assertion(false, "must be far.");
				}

				stepLink->SetCurLinkedSkillInstance(this);
				const std::string &scriptHandler_OnLinked = stepLink->GetScriptHandler_OnLinked();
				if (!scriptHandler_OnLinked.empty())
				{
					stepLink->CallString(scriptHandler_OnLinked.c_str());
				}
				stepLink->SetCurLinkedSkillInstance(0);

				mIsLinked = true;
			}
			
			isOver = skillActorLink->IsOver();

			if (stepLink->IsLinkedDoOver())
			{
				if (skillActorLink->IsLinked())
				{
					skillActorLink->SetOver(true);

					isOver = true;
				}
			}
		}

		if (isOver)
		{
			Enter(mCurSkillStep->GetNextStep());
		}
	}
}
//----------------------------------------------------------------------------
void SkillInstance::Enter (SkillStep *step)
{
	if (mCurSkillStep)
	{
		OnLeave(mCurSkillStep);
		mCurSkillStep = 0;
	}

	if (!step)
	{
		mIsOver = true;
		mIsSkillCallOver = true;
		return;
	}

	mCurSkillStepRunTime = 0.0f;

	float probability = step->GetProbability();
	float prob = Mathf::UnitRandom();

	if (prob <= probability)
	{
		mCurSkillStep = step;

		OnEnter(mCurSkillStep);

		SkillStepRangeTime *stepTimeRange = DynamicCast<SkillStepRangeTime>(mCurSkillStep);
		if (stepTimeRange)
		{
			float rangeTime = stepTimeRange->GetTime();

			if (0.0f == rangeTime)
			{
				Enter(step->GetNextStep());
			}
		}
	}
	else
	{
		Enter(step->GetNextStep());
	}
}
//----------------------------------------------------------------------------
void SkillInstance::OnLeave (SkillStep *step)
{
	step->OnLeave(this);
}
//----------------------------------------------------------------------------
void SkillInstance::OnEnter (SkillStep *step)
{
	if (step->IsSkillCallOverAtThisStep())
	{
		mIsCalingCallOver = true;
		mCalingCallOverTime = 0.0f;

		mCallOverTime = step->GetSkillCallOverTime();
	}

	step->OnEnter(this);
}
//----------------------------------------------------------------------------
bool SkillInstance::AddTarget (int id)
{
	if (HasTarget(id))
		return false;

	mTargets.push_back(id);

	return true;
}
//----------------------------------------------------------------------------
bool SkillInstance::HasTarget (int id)
{
	for (int i=0; i<GetNumTargets(); i++)
	{
		if (id == mTargets[i])
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void SkillInstance::AddSkillActor (int aimTargetID, EffectActor *skillActor)
{
	mSkillActors[aimTargetID] = skillActor;
}
//----------------------------------------------------------------------------
EffectActor *SkillInstance::GetSkillActor (int aimTargetID)
{
	std::map<int, EffectActorPtr>::iterator it = mSkillActors.find(aimTargetID);
	if (it != mSkillActors.end())
		return it->second;

	return 0;
}
//----------------------------------------------------------------------------
int SkillInstance::GetTarget (int i)
{
	if (0<=i && i<(int)mTargets.size())
		return mTargets[i];

	return -1;
}
//----------------------------------------------------------------------------
Character *SkillInstance::GetTargetCharacter (int i)
{
	int id = GetTarget(i);

	Scene *scene = mSkill->GetCharacter()->GetScene();
	return DynamicCast<Character>(scene->GetActorByID(id));
}
//----------------------------------------------------------------------------
bool SkillInstance::RemoveTarget (int id)
{
	std::vector<int>::iterator it = mTargets.begin();
	for (; it!=mTargets.end();)
	{
		if (id == *it)
		{
			it = mTargets.erase(it);
			return true;
		}
		else
		{
			it++;
		}
	}

	return false;
}
//----------------------------------------------------------------------------
void SkillInstance::RemoveAllTargets ()
{
	mTargets.clear();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkillInstance::SkillInstance (LoadConstructor value)
	:
Gameable(value),
mSkill(0),
mIsShared(false),
mIsSkillCallOver(false),
mIsCalingCallOver(false),
mCalingCallOverTime(0.0f),
mCallOverTime(0.0f),
mIsOver(false),
mCurSkillStepRunTime(0.0f),
mAnimTarget(-1),
mIsLinked(false)
{
	mCurInstanceID = GetNextID();
}
//----------------------------------------------------------------------------
void SkillInstance::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Gameable::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(SkillInstance, source);
}
//----------------------------------------------------------------------------
void SkillInstance::Link (InStream& source)
{
	Gameable::Link(source);
}
//----------------------------------------------------------------------------
void SkillInstance::PostLink ()
{
	Gameable::PostLink();
}
//----------------------------------------------------------------------------
bool SkillInstance::Register (OutStream& target) const
{
	if (Gameable::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void SkillInstance::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Gameable::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(SkillInstance, target);
}
//----------------------------------------------------------------------------
int SkillInstance::GetStreamingSize (Stream &stream) const
{
	int size = Gameable::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------