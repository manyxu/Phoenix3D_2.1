/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Character_Skills.cpp
*
*/

#include "PX2Character.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// Skill
//----------------------------------------------------------------------------
bool Character::AddSkill (Skill *skill)
{
	assertion(0!=skill, "skill should not be 0.");

	if (!skill)
		return false;

	if (HasSkill(skill))
		return false;

	mSkills.push_back(skill);
	skill->SetCharacter(this);
	skill->OnAdded();

	if (skill->GetName() == "Def")
		mDefSkill = skill;

	return true;
}
//----------------------------------------------------------------------------
bool Character::HasSkill (Skill *skill)
{
	assertion(0!=skill, "skill should not be 0.");

	if (!skill)
		return false;

	for (int i=0; i<GetNumSkills(); i++)
	{
		if (skill == GetSkill(i))
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
Skill *Character::GetSkillByID (int id)
{
	for (int i=0; i<GetNumSkills(); i++)
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
Skill *Character::GetSkillByTypeID (int typeID)
{
	for (int i=0; i<GetNumSkills(); i++)
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
Skill *Character::GetSkillByName (const std::string &name)
{
	for (int i=0; i<GetNumSkills(); i++)
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
Skill *Character::GetSkill (int i)
{
	if (0<=i && i<(int)mSkills.size())
		return mSkills[i];

	return 0;
}
//----------------------------------------------------------------------------
bool Character::RemoveSkill (Skill *skill)
{
	assertion(0!=skill, "skill should not be 0.");

	if (!skill)
		return false;

	std::vector<SkillPtr>::iterator it = mSkills.begin();
	for (; it!=mSkills.end(); it++)
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
void Character::RemoveAllSkills ()
{
	for (int i=0; i<(int)mSkills.size(); i++)
	{
		mSkills[i]->SetCharacter(0);
	}

	mSkills.clear();
}
//----------------------------------------------------------------------------
std::list<Skill *> Character::GetValidSkills (const Character *target,
	 bool useTrigerDis, int positive, int needTarget, int cdOK)
{
	const APoint &targetPos = target->GetPosition();
	float targetSelfRadius = target->GetSelfRadius();
	AVector dir = targetPos - GetPosition();
	float distance = dir.Length();

	std::list<Skill *> skills;
	for (int i=0; i<(int)mSkills.size(); i++)
	{
		Skill *skill = mSkills[i];
		bool isEnable = skill->IsEnable();
		bool isPositive = skill->IsPositive();
		bool isNeedTarget = skill->IsActivateNeedCharacterAnimTarget();
		bool isCDOK = !skill->IsOnCD();
		float trigerDis = skill->GetMTrigerDistance();

		if (!skill->IsEnable())
			continue;

		if (0==positive && isPositive)
			continue;

		if (1==positive && !isPositive)
			continue;

		if (0==needTarget && isNeedTarget)
			continue;

		if (1==needTarget && !isNeedTarget)
			continue;

		if (0==cdOK && isCDOK)
			continue;

		if (1==cdOK && !isCDOK)
			continue;

		if (useTrigerDis)
		{
			if (distance > (trigerDis+targetSelfRadius))
				continue;
		}

		skills.push_back(skill);
	}

	return skills;
}
//----------------------------------------------------------------------------
bool Character::IsAnySkillHasInstance ()
{
	for (int i=0; i<(int)GetNumSkills(); i++)
	{
		Skill *skill = GetSkill(i);
		if (0 != skill->GetNumInstances())
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool Character::IsAllSkillCallOver ()
{
	bool allCallOver = true;

	for (int i=0; i<(int)mSkills.size(); i++)
	{
		if (mSkills[i]->IsPositive())
		{
			if (!mSkills[i]->IsCallOver())
			{
				allCallOver = false;
			}
		}
	}

	return allCallOver;
}
//----------------------------------------------------------------------------
void Character::ResetAllSkillsCD ()
{
	for (int i=0; i<GetNumSkills(); i++)
	{
		Skill *skill = GetSkill(i);
		if (skill)
		{
			skill->ResetCD();
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Buf
//----------------------------------------------------------------------------
void Character::AddBufClassExcept (const std::string &name, 
	const std::string &except)
{
	mBufClassExcepts[name] = except;
}
//----------------------------------------------------------------------------
void Character::RemoveBufClassExcept (const std::string &name)
{
	std::map<std::string, std::string>::iterator it =
		mBufClassExcepts.find(name);	
	if (it != mBufClassExcepts.end())
	{
		mBufClassExcepts.erase(it);
	}
}
//----------------------------------------------------------------------------
bool Character::HasBufClassExcept (const std::string &except)
{
	std::map<std::string, std::string>::iterator it = mBufClassExcepts.begin();
	for (; it!=mBufClassExcepts.end(); it++)
	{
		if (it->second == except)
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void Character::RemoveAllBufClassExcepts ()
{
	mBufClassExcepts.clear();
}
//----------------------------------------------------------------------------
bool Character::AddBuf (Buf *buf)
{
	assertion(0!=buf, "buf should not be 0.");

	if (!buf)
		return false;

	if (buf->IsClassOnlyOne())
	{
		if (HasBufClass(buf))
		{
			return false;
		}
	}
	else
	{
		if (HasBuf(buf))
			return false;
	}

	mBufs.push_back(buf);

	buf->SetCharacter(this);
	buf->OnAdded();

	return true;
}
//----------------------------------------------------------------------------
bool Character::HasBuf (Buf *buf)
{
	for (int i=0; i<(int)mBufs.size(); i++)
	{
		if (buf == mBufs[i])
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool Character::HasBuf (const std::string &name)
{
	for (int i=0; i<(int)mBufs.size(); i++)
	{
		if (name == mBufs[i]->GetName())
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool Character::HasBufClass (const std::string &classStr)
{
	for (int i=0; i<(int)mBufs.size(); i++)
	{
		if (classStr == mBufs[i]->GetClass())
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool Character::HasBufClass (Buf *buf)
{
	for (int i=0; i<(int)mBufs.size(); i++)
	{
		if (buf->GetClass() == mBufs[i]->GetClass())
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------
Buf *Character::GetBufByClass (const std::string &className)
{
	for (int i=0; i<(int)mBufs.size(); i++)
	{
		if (className == mBufs[i]->GetClass())
			return mBufs[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
int Character::GetNumBufsOfClass (const std::string &className)
{
	int numBufs = 0;

	for (int i=0; i<(int)mBufs.size(); i++)
	{
		if (className == mBufs[i]->GetClass())
		{
			numBufs++;
		}
	}

	return numBufs;
}
//----------------------------------------------------------------------------
void Character::RemoveBufsOfClass (const std::string &className)
{
	std::vector<BufPtr>::iterator it = mBufs.begin();
	for (; it!=mBufs.end();)
	{
		if (className==(*it)->GetClass())
		{
			(*it)->OnRemoved();
			it = mBufs.erase(it);
		}
		else
		{
			it++;
		}
	}
}
//----------------------------------------------------------------------------
Buf *Character::GetBufs (int i)
{
	assertion(0<=i&&i<(int)mBufs.size(), "i should be in right range.\n");

	if (0<=i && i<(int)mBufs.size())
	{
		return mBufs[i];
	}

	return 0;
}
//----------------------------------------------------------------------------
void  Character::RemoveAllBufs ()
{
	std::vector<BufPtr>::iterator it = mBufs.begin();
	if (it != mBufs.end())
	{
		(*it)->OnRemoved();
		(*it)->SetCharacter(0);
	}

	mBufs.clear();
}
//----------------------------------------------------------------------------
bool Character::RemoveBuf (Buf *buf)
{
	assertion(0!=buf, "buf should not be 0.");

	if (!buf)
		return false;

	std::vector<BufPtr>::iterator it = mBufs.begin();
	if (it != mBufs.end())
	{
		(*it)->OnRemoved();
		(*it)->SetCharacter(0);

		mBufs.erase(it);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------