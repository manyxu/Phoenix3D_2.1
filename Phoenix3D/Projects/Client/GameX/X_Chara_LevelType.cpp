// X_Chara_LevelType.cpp

#include "X_Chara.hpp"
#include "X_Def.hpp"
#include "X_DefMan.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void X_Chara::SetTypeID(int typeID)
{
	Character::SetTypeID(typeID);

	if (CT_PLAYER == mCharType)
	{
		std::map<int, ActorDef>::iterator itActor = X_DEFM.mActorDefs.find(typeID);
		if (itActor != X_DEFM.mActorDefs.end())
		{
			mActorDef = &(itActor->second);

			int modelID = mActorDef->ModelID;
			std::map<int, ModelDef>::iterator itModel = X_DEFM.mModelDefs.find(modelID);
			if (itModel != X_DEFM.mModelDefs.end())
			{
				mModelDef = &(itModel->second);
				LoadNormalAnimIDNameMap();
			}

			mNorSkillIDs.clear();
			for (int i = 0; i < (int)mActorDef->NorSkillIDs.size(); i++)
			{
				int norSkillID = mActorDef->NorSkillIDs[i];

				std::map<int, SkillDef>::iterator itSkill = X_DEFM.mSkillDefs.find(norSkillID);
				if (itSkill != X_DEFM.mSkillDefs.end())
				{
					SkillDef *skillDef = &(itSkill->second);
					mNorSkillDefs.push_back(skillDef);

					mNorSkillIDs.push_back(norSkillID);
				}
			}

			for (int i = 0; i < (int)mActorDef->SkillIDs.size(); i++)
			{
				int skillID = mActorDef->SkillIDs[i];

				std::map<int, SkillDef>::iterator itSkill = X_DEFM.mSkillDefs.find(skillID);
				if (itSkill != X_DEFM.mSkillDefs.end())
				{
					SkillDef *skillDef = &(itSkill->second);
					mSkillDefMap[skillID] = skillDef;
				}
			}
		}
	}
	else
	{
		std::map<int, MonsterDef>::iterator itMonster = X_DEFM.mMonsterDefs.find(typeID);
		if (itMonster != X_DEFM.mMonsterDefs.end())
		{
			mMonsterDef = &(itMonster->second);

			int modelID = mMonsterDef->ModelID;
			std::map<int, ModelDef>::iterator itModel = X_DEFM.mModelDefs.find(modelID);
			if (itModel != X_DEFM.mModelDefs.end())
			{
				mModelDef = &(itModel->second);
				LoadNormalAnimIDNameMap();
			}

			mNorSkillIDs.clear();
			for (int i = 0; i < (int)mMonsterDef->NorSkillIDs.size(); i++)
			{
				int norSkillID = mMonsterDef->NorSkillIDs[i];

				std::map<int, SkillDef>::iterator itSkill = X_DEFM.mSkillDefs.find(norSkillID);
				if (itSkill != X_DEFM.mSkillDefs.end())
				{
					SkillDef *skillDef = &(itSkill->second);
					mNorSkillDefs.push_back(skillDef);

					mNorSkillIDs.push_back(norSkillID);
				}
			}

			for (int i = 0; i < (int)mMonsterDef->MonsterSkillDefs.size(); i++)
			{
				int skillID = mMonsterDef->MonsterSkillDefs[i].SkillID;

				std::map<int, SkillDef>::iterator itSkill = X_DEFM.mSkillDefs.find(skillID);
				if (itSkill != X_DEFM.mSkillDefs.end())
				{
					SkillDef *skillDef = &(itSkill->second);
					mSkillDefMap[skillID] = skillDef;
				}
			}
		}
	}
}
//----------------------------------------------------------------------------
void X_Chara::SetLevel(int level)
{
	//Character::SetLevel(level);
}
//----------------------------------------------------------------------------