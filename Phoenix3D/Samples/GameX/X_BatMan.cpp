/*
*
* ÎÄ¼þÃû³Æ	£º	X_BatMan.cpp
*
*/

#include "X_BatMan.hpp"
#include "X_Chara.hpp"
#include "X_Skill.hpp"
#include "PX2SkillInstance.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
X_BatMan::X_BatMan()
{

}
//----------------------------------------------------------------------------
X_BatMan::~X_BatMan()
{

}
//----------------------------------------------------------------------------
void X_BatMan::Update(float appSeconds, float elapsedSeconds)
{

}
//----------------------------------------------------------------------------
void X_BatMan::Clear()
{

}
//----------------------------------------------------------------------------
Skill *X_BatMan::GetHeighestPrioritySkill(std::list<Skill*> &skills)
{
	Skill *skillH = 0;
	int priority = -1;

	std::list<Skill*>::iterator it = skills.begin();
	for (; it != skills.end(); it++)
	{
		Skill *skill = *it;
		if (skill->GetPriority() > priority)
		{
			priority = skill->GetPriority();
			skillH = skill;
		}
	}

	return skillH;
}
//----------------------------------------------------------------------------
void X_BatMan::CharAAttack(SkillInstance *si, X_Chara *target)
{
}
//----------------------------------------------------------------------------