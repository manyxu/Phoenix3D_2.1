// X_Chara_ModelAnim.cpp

#include "X_Chara.hpp"
#include "X_Def.hpp"
#include "PX2Animation3DSkeleton.hpp"
#include "PX2StringHelp.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void X_Chara::LoadModel()
{
	if (mIsModelLoaded) return;

	if (!mModelDef) return;

	std::string modelIDStr = StringHelp::IntToString(mModelDef->ModelID);
	std::string path0 = "Data/models/actors/" + modelIDStr + "/";
	std::string ext = ".px2obj";

	std::string path_model = path0 + modelIDStr + ext;

	if (!modelIDStr.empty())
	{
		SetMovableFilename(path_model, true);
	}

	mIsModelLoaded = true;
}
//----------------------------------------------------------------------------
void X_Chara::LoadAnims()
{
	if (mIsAnimsLoaded) return;

	if (!mModelDef) return;

	std::string modelIDStr = StringHelp::IntToString(mModelDef->ModelID);
	std::string path0 = "Data/models/actors/" + modelIDStr + "/";
	std::string ext = ".px2obj";

	std::map<ModelDef::AnimType, AnimDef>::iterator it = mModelDef->NormalAnims.begin();
	for (; it != mModelDef->NormalAnims.end(); it++)
	{
		ModelDef::AnimType animType = it->first;
		const AnimDef &animDef = it->second;

		if (0 != animDef.AnimID)
		{
			std::string animIDStr = StringHelp::IntToString(animDef.AnimID);
			std::string path_anim = path0 + animIDStr + ext;

			std::string animName = ModelDef::sAnimTypeStrs[(int)animType];

			Animation3DSkeleton *anim = new0 Animation3DSkeleton();
			anim->SetFilename(path_anim);
			if ("stand" == animName || "walk" == animName || "run" == animName)
				anim->SetPlayOnce(false);
			else
				anim->SetPlayOnce(true);

			AddAnim(anim);

			NormalAnimIDNameMap[animName] = animDef.AnimID;
		}
	}

	std::map<int, AnimDef>::iterator it1 = mModelDef->mAtkAnims.begin();
	for (; it1 != mModelDef->mAtkAnims.end(); it1++)
	{
		int index = it1->first;
		const AnimDef &animDef = it1->second;

		if (0 != animDef.AnimID)
		{
			// name
			Animation *anim = GetAnimByID(animDef.AnimID);
			if (!anim)
			{
				// path
				std::string animIDStr = StringHelp::IntToString(animDef.AnimID);
				std::string path_anim = path0 + animIDStr + ext;

				// adjuge
				float adjuge = 1.0f;
				if (0 != animDef.Hit)
					adjuge = (float)animDef.Hit / (float)animDef.Num;

				Animation3DSkeleton *anim = new0 Animation3DSkeleton();
				anim->SetFilename(path_anim);
				anim->SetPlayOnce(true);

				AddAnim(anim);
			}
		}
	}

	mIsAnimsLoaded = true;
}
//----------------------------------------------------------------------------
void X_Chara::LoadNormalAnimIDNameMap()
{
	std::map<ModelDef::AnimType, AnimDef>::iterator it = mModelDef->NormalAnims.begin();
	for (; it != mModelDef->NormalAnims.end(); it++)
	{
		ModelDef::AnimType animType = it->first;
		const AnimDef &animDef = it->second;

		if (0 != animDef.AnimID)
		{
			std::string animName = ModelDef::sAnimTypeStrs[(int)animType];
			NormalAnimIDNameMap[animName] = animDef.AnimID;
		}
	}
}
//----------------------------------------------------------------------------