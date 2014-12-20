/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Skill_Character.cpp
*
*/

#include "PX2Skill.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Skill::OnAdded ()
{
	if (!mScriptHandler_OnAdded.empty())
	{
		CallString(mScriptHandler_OnAdded.c_str());
	}
}
//----------------------------------------------------------------------------
void Skill::OnRemove ()
{
	if (!mScriptHandler_OnRemove.empty())
	{
		CallString(mScriptHandler_OnRemove.c_str());
	}
}
//----------------------------------------------------------------------------