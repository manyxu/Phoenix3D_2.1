/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Skill_Damage.cpp
*
*/

#include "PX2Skill.hpp"
using namespace PX2;


//----------------------------------------------------------------------------
void Skill::SetPhysicsAP (int val)
{
	mPhysicsAP = val;
}
//----------------------------------------------------------------------------
void Skill::SetMagicAP (int val)
{
	mMagicAP = val;
}
//----------------------------------------------------------------------------
void Skill::SetCriticalPercent (float percent)
{
	mCriticalPercent = percent;
}
//----------------------------------------------------------------------------
void Skill::SetCriticalProbability (float prob)
{
	mCriticalProbability = prob;
}
//----------------------------------------------------------------------------
int Skill::GetPhysicsAPLast () const
{
	int ap = mPhysicsAP;

	if (mCriticalPercent>0.0f && mCriticalProbability>0.0f)
	{
		float radom =Mathf::UnitRandom();
		if (radom < mCriticalProbability)
			ap += (int)(mCriticalPercent * mPhysicsAP);
	}

	return ap;
}
//----------------------------------------------------------------------------
int Skill::GetMagicAPLast () const
{
	int ap = mMagicAP;

	if (mCriticalPercent>0.0f && mCriticalProbability>0.0f)
	{
		float radom =Mathf::UnitRandom();
		if (radom < mCriticalProbability)
			ap += (int)(mCriticalPercent * mMagicAP);
	}

	return ap;
}
//----------------------------------------------------------------------------
void Skill::AddAffectParam (const std::string &name, float val)
{
	mAffectParams[name] = val;
}
//----------------------------------------------------------------------------
void Skill::RemoveAffectParam (const std::string &name)
{
	std::map<std::string, float>::iterator it = mAffectParams.find(name);
	if (it != mAffectParams.end())
	{
		mAffectParams.erase(it);
	}
	else
	{
		assertion(false, "does %s not find param", name.c_str());
		PX2_LOG_ERROR("does %s not find param", name.c_str());
	}
}
//----------------------------------------------------------------------------
bool Skill::IsHasAffectParam (const std::string &name)
{
	std::map<std::string, float>::iterator it = mAffectParams.find(name);
	if (it != mAffectParams.end())
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
float Skill::GetAffectParam (const std::string &name)
{
	std::map<std::string, float>::iterator it = mAffectParams.find(name);
	if (it != mAffectParams.end())
	{
		return it->second;
	}
	else
	{
		assertion(false, "does %s not find param", name.c_str());
		PX2_LOG_ERROR("does %s not find param", name.c_str());

		return 0.0f;
	}
}
//----------------------------------------------------------------------------