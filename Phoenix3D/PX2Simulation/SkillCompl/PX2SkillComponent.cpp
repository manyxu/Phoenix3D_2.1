// PX2SkillComponent.cpp

#include "PX2SkillComponent.hpp"
#include "PX2Character.hpp"
#include "PX2Project.hpp"
#include "PX2Scene.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Controller, SkillController);
PX2_IMPLEMENT_STREAM(SkillController);
PX2_IMPLEMENT_FACTORY(SkillController);
PX2_IMPLEMENT_DEFAULT_NAMES(Controller, SkillController);

//----------------------------------------------------------------------------
SkillController::SkillController()
{
}
//----------------------------------------------------------------------------
SkillController::~SkillController()
{
}
//----------------------------------------------------------------------------
bool SkillController::AddSkill(Skill *skill)
{
	assertion(0 != skill, "skill should not be 0.");

	if (!skill)
		return false;

	if (HasSkill(skill))
		return false;

	mSkills.push_back(skill);
	skill->SetCharacter(DynamicCast<Character>(GetControlledable()));
	skill->OnAdded();

	if (skill->GetName() == "Def")
		mDefSkill = skill;

	return true;
}
//----------------------------------------------------------------------------
bool SkillController::HasSkill(Skill *skill)
{
	assertion(0 != skill, "skill should not be 0.");

	if (!skill)
		return false;

	for (int i = 0; i < GetNumSkills(); i++)
	{
		if (skill == GetSkill(i))
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
Skill *SkillController::GetSkillByID(int id)
{
	for (int i = 0; i < GetNumSkills(); i++)
	{
		Skill *skill = GetSkill(i);

		if (skill->GetID() == id)
		{
			return skill;
		}
	}

	return 0;
}
//----------------------------------------------------------------------------
Skill *SkillController::GetSkillByTypeID(int typeID)
{
	for (int i = 0; i < GetNumSkills(); i++)
	{
		Skill *skill = GetSkill(i);

		if (skill->GetTypeID() == typeID)
		{
			return skill;
		}
	}

	return 0;
}
//----------------------------------------------------------------------------
Skill *SkillController::GetSkillByName(const std::string &name)
{
	for (int i = 0; i < GetNumSkills(); i++)
	{
		Skill *skill = GetSkill(i);

		if (skill->GetName() == name)
		{
			return skill;
		}
	}

	return 0;
}
//----------------------------------------------------------------------------
Skill *SkillController::GetSkill(int i)
{
	if (0 <= i && i < (int)mSkills.size())
		return mSkills[i];

	return 0;
}
//----------------------------------------------------------------------------
bool SkillController::RemoveSkill(Skill *skill)
{
	assertion(0 != skill, "skill should not be 0.");

	if (!skill)
		return false;

	std::vector<SkillPtr>::iterator it = mSkills.begin();
	for (; it != mSkills.end(); it++)
	{
		if (skill == *it)
		{
			skill->OnRemove();
			(*it)->SetCharacter(0);
			mSkills.erase(it);

			return true;
		}
	}

	return false;
}
//----------------------------------------------------------------------------
void SkillController::RemoveAllSkills()
{
	for (int i = 0; i < (int)mSkills.size(); i++)
	{
		mSkills[i]->SetCharacter(0);
	}

	mSkills.clear();
}
//----------------------------------------------------------------------------
std::list<Skill *> SkillController::GetValidSkills(const Character *target,
	bool useTrigerDis, int positive, int needTarget, int cdOK)
{
	Character *selfChara = DynamicCast<Character>(GetControlledable());

	const APoint &targetPos = target->LocalTransform.GetTranslate();
	float targetSelfRadius = target->GetRadius();
	AVector dir = targetPos - selfChara->LocalTransform.GetTranslate();
	float distance = dir.Length();

	std::list<Skill *> skills;
	for (int i = 0; i < (int)mSkills.size(); i++)
	{
		Skill *skill = mSkills[i];
		bool isEnable = skill->IsEnable();
		bool isPositive = true;
		//bool isPositive = skill->IsPositive();
		bool isNeedTarget = true;
		//bool isNeedTarget = skill->IsActivateNeedCharacterAnimTarget();
		bool isCDOK = !skill->IsOnCD();
		float trigerDis = skill->GetMTrigerDistance();

		if (!skill->IsEnable())
			continue;

		if (0 == positive && isPositive)
			continue;

		if (1 == positive && !isPositive)
			continue;

		if (0 == needTarget && isNeedTarget)
			continue;

		if (1 == needTarget && !isNeedTarget)
			continue;

		if (0 == cdOK && isCDOK)
			continue;

		if (1 == cdOK && !isCDOK)
			continue;

		if (useTrigerDis)
		{
			if (distance > (trigerDis + targetSelfRadius))
				continue;
		}

		skills.push_back(skill);
	}

	return skills;
}
//----------------------------------------------------------------------------
bool SkillController::IsAnySkillHasInstance()
{
	for (int i = 0; i < (int)GetNumSkills(); i++)
	{
		Skill *skill = GetSkill(i);
		if (0 != skill->GetNumInstances())
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool SkillController::IsAllSkillCallOver()
{
	bool allCallOver = true;

	for (int i = 0; i < (int)mSkills.size(); i++)
	{
		//if (mSkills[i]->IsPositive())
		//{
		//	if (!mSkills[i]->IsCallOver())
		//	{
		//		allCallOver = false;
		//	}
		//}
	}

	return allCallOver;
}
//----------------------------------------------------------------------------
void SkillController::ResetAllSkillsCD()
{
	for (int i = 0; i < GetNumSkills(); i++)
	{
		Skill *skill = GetSkill(i);
		if (skill)
		{
			skill->ResetCD();
		}
	}
}
//----------------------------------------------------------------------------
void SkillController::SetAimTarget(int targetID)
{
	mAimTargetID = targetID;
}
//----------------------------------------------------------------------------
Character *SkillController::GetAimTargetCharacter() const
{
	Scene *scene = PX2_PROJ.GetScene();
	if (!scene) return 0;

	return DynamicCast<Character>(scene->GetActorByID(mAimTargetID));
}
//----------------------------------------------------------------------------
Character *SkillController::GetAimTargetCharacterAlive() const
{
	Scene *scene = PX2_PROJ.GetScene();
	if (!scene) return 0;

	Character *charac = DynamicCast<Character>(scene->GetActorByID(mAimTargetID));
	if (charac && !charac->IsDead())
	{
		return charac;
	}

	return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
SkillController::SkillController(LoadConstructor value) :
Controller(value)
{
}
//----------------------------------------------------------------------------
void SkillController::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Controller::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(SkillController, source);
}
//----------------------------------------------------------------------------
void SkillController::Link(InStream& source)
{
	Controller::Link(source);
}
//----------------------------------------------------------------------------
void SkillController::PostLink()
{
	Controller::PostLink();
}
//----------------------------------------------------------------------------
bool SkillController::Register(OutStream& target) const
{
	if (Controller::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void SkillController::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Controller::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(SkillController, target);
}
//----------------------------------------------------------------------------
int SkillController::GetStreamingSize(Stream &stream) const
{
	int size = Controller::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------