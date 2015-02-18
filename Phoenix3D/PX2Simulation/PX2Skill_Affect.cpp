// PX2Skill_Damage.cpp

#include "PX2Skill.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Skill::AddAffectParam(const std::string &name, float val)
{
	mAffectParams[name] = val;
}
//----------------------------------------------------------------------------
void Skill::RemoveAffectParam(const std::string &name)
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
bool Skill::IsHasAffectParam(const std::string &name)
{
	std::map<std::string, float>::iterator it = mAffectParams.find(name);
	if (it != mAffectParams.end())
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
float Skill::GetAffectParam(const std::string &name)
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