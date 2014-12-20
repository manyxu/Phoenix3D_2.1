/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Skill_Step.cpp
*
*/

#include "PX2Skill.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
bool Skill::SetFirstSkillStep (SkillStep *step)
{
	if (mFirstSkillStep == step)
		return false;

	if (mFirstSkillStep)
		mFirstSkillStep->SetSkill(0);

	mFirstSkillStep = step;

	if (mFirstSkillStep)
		mFirstSkillStep->SetSkill(this);

	return true;
}
//----------------------------------------------------------------------------
SkillStep *Skill::GetSkillStepByName (const std::string &name)
{
	SkillStep *step = mFirstSkillStep;

	while(step)
	{
		if (step->GetName() == name)
			return step;

		step = step->GetNextStep();
	}

	return 0;
}
//----------------------------------------------------------------------------
SkillStep *Skill::GetLastSkillStep ()
{
	SkillStep *beforeStep = mFirstSkillStep;
	SkillStep *step = mFirstSkillStep;

	while (step)
	{
		beforeStep = step;
		step = step->GetNextStep();
	}

	return beforeStep;
}
//----------------------------------------------------------------------------