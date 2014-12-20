/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Skill_Property.cpp
*
*/

#include "PX2Skill.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
PX2_IMPLEMENT_PM_F(Skill, RadiusLength);
PX2_IMPLEMENT_PM_F(Skill, Width);
PX2_IMPLEMENT_PM_F(Skill, FanDegree);
PX2_IMPLEMENT_PM_F(Skill, CDTime);
PX2_IMPLEMENT_PM_F(Skill, TrigerDistance);
//----------------------------------------------------------------------------
void Skill::SetLevel (int level)
{
	mLevel = level;
}
//----------------------------------------------------------------------------
void Skill::SetMaxLevel (int level)
{
	mMaxLevel = level;
}
//----------------------------------------------------------------------------