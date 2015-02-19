// PX2SkillComponent.cpp

#include "PX2SkillComponent.hpp"
#include "PX2Character.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Component, SkillComponent);
PX2_IMPLEMENT_STREAM(SkillComponent);
PX2_IMPLEMENT_FACTORY(SkillComponent);
PX2_IMPLEMENT_DEFAULT_NAMES(Component, SkillComponent);

//----------------------------------------------------------------------------
SkillComponent::SkillComponent()
{
}
//----------------------------------------------------------------------------
SkillComponent::~SkillComponent()
{
}
//----------------------------------------------------------------------------
bool SkillComponent::AddSkill(Skill *skill)
{
	assertion(0 != skill, "skill should not be 0.");

	if (!skill)
		return false;

	if (HasSkill(skill))
		return false;

	mSkills.push_back(skill);
	skill->SetCharacter(DynamicCast<Character>(GetCompable()));
	skill->OnAdded();

	if (skill->GetName() == "Def")
		mDefSkill = skill;

	return true;
}
//----------------------------------------------------------------------------
bool SkillComponent::HasSkill(Skill *skill)
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
Skill *SkillComponent::GetSkillByID(int id)
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
Skill *SkillComponent::GetSkillByTypeID(int typeID)
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
Skill *SkillComponent::GetSkillByName(const std::string &name)
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
Skill *SkillComponent::GetSkill(int i)
{
	if (0 <= i && i < (int)mSkills.size())
		return mSkills[i];

	return 0;
}
//----------------------------------------------------------------------------
bool SkillComponent::RemoveSkill(Skill *skill)
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
void SkillComponent::RemoveAllSkills()
{
	for (int i = 0; i < (int)mSkills.size(); i++)
	{
		mSkills[i]->SetCharacter(0);
	}

	mSkills.clear();
}
//----------------------------------------------------------------------------
std::list<Skill *> SkillComponent::GetValidSkills(const Character *target,
	bool useTrigerDis, int positive, int needTarget, int cdOK)
{
	Character *selfChara = DynamicCast<Character>(GetCompable());

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
bool SkillComponent::IsAnySkillHasInstance()
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
bool SkillComponent::IsAllSkillCallOver()
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
void SkillComponent::ResetAllSkillsCD()
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