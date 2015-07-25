// X_Chara_Skill.cpp

#include "X_Chara.hpp"
#include "PX2Animation3DSkeleton.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void X_Chara::CreateSkills()
{
}
//----------------------------------------------------------------------------
X_Skill *X_Chara::_CreateSkill(int skillTypeID, int defPartIndex)
{
	return 0;
}
//----------------------------------------------------------------------------
void X_Chara::CollectADefSkillStep()
{
	if (mCollectPartSkillNum < (int)mDefPartSkills.size())
	{
		mCollectPartSkillNum++;
	}
}
//----------------------------------------------------------------------------
void X_Chara::UpdateActivateDefSkill()
{
	if (0 == mCollectPartSkillNum || 0 == (int)mDefPartSkills.size())
		return;

	int nextIndex = 0;
	if (-1 == mCurDefPartSkillIndex)
	{
		nextIndex = 0;

		mCurDefPartSkillIndex = nextIndex;
		mDefPartSkills[mCurDefPartSkillIndex]->Activate();
	}
	else
	{
		if (!mDefPartSkills[mCurDefPartSkillIndex]->IsOnCD())
		{ // 当前技能已经播放完毕

			nextIndex = mCurDefPartSkillIndex + 1;
			if (nextIndex < mCollectPartSkillNum)
			{
				mCurDefPartSkillIndex = nextIndex;
				mDefPartSkills[mCurDefPartSkillIndex]->Activate();
			}
			else
			{
				mCollectPartSkillNum = 0;
				mCurDefPartSkillIndex = -1;
			}
		}
	}

	if (nextIndex >= (int)mDefPartSkills.size())
	{
		mCollectPartSkillNum = 0;
		mCurDefPartSkillIndex = -1;
	}
}
//----------------------------------------------------------------------------
void X_Chara::ActivateSkill(int skillID)
{
}
//----------------------------------------------------------------------------