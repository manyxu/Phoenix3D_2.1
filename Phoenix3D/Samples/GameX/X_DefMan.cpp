// X_DefMan.cpp

#include "X_DefMan.hpp"
#include "PX2CSVParser.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
X_DefMan::X_DefMan()
{
}
//----------------------------------------------------------------------------
X_DefMan::~X_DefMan()
{
}
//----------------------------------------------------------------------------
bool X_DefMan::LoadAll()
{
	if (mIsAllLoaded)
		return true;

	ReloadAll();

	mIsAllLoaded = true;

	return true;
}
//----------------------------------------------------------------------------
bool X_DefMan::ReloadAll()
{
	//LoadModelDef("Data/defines/model.csv");
	//LoadActorDef("Data/defines/actor.csv");
	//LoadSkillDef("Data/defines/skill.csv");
	//LoadMapDef("Data/defines/map.csv");
	//LoadMonsterDef("Data/defines/monster.csv");

	return true;
}
//----------------------------------------------------------------------------
bool X_DefMan::LoadActorDef(const std::string &filename)
{
	mActorDefs.clear();

	CSVParser1 parser;

	if (!parser.Load(filename))
		return false;

	parser.SetTitleLine(1);

	int numLines = (int)parser.GetNumLines();
	for (int i = 2; i < numLines; ++i)
	{
		ActorDef def;

		def.ActorID = parser[i]["ActorID"].Int();
		def.ModelID = parser[i]["ModelID"].Int();

		for (int j = 0; j <= 4; j++)
		{
			std::string norSkillIDStr = "NorSkillID";
			if (0 != j)
			{
				norSkillIDStr += StringHelp::IntToString(j);
			}

			int skillID = parser[i][norSkillIDStr.c_str()].Int();
			if (0 != skillID)
			{
				def.NorSkillIDs.push_back(skillID);
			}
		}

		for (int j = 0; j <= 3; j++)
		{
			std::string skillIDStr = "SkillID";
			if (0 != j)
			{
				skillIDStr += StringHelp::IntToString(j);
			}

			int skillID = parser[i][skillIDStr.c_str()].Int();
			if (0 != skillID)
			{
				def.SkillIDs.push_back(skillID);
			}
		}

		mActorDefs[def.ActorID] = def;
	}

	return true;
}
//----------------------------------------------------------------------------
bool X_DefMan::LoadModelDef(const std::string &filename)
{
	mModelDefs.clear();

	CSVParser1 parser;

	if (!parser.Load(filename))
		return false;

	parser.SetTitleLine(1);

	int numLines = (int)parser.GetNumLines();
	for (int i = 2; i < numLines; ++i)
	{
		ModelDef def;

		def.ModelID = parser[i]["ModelID"].Int();
		def.IconID = parser[i]["IconID"].Int();
		def.SkinID = parser[i]["SkinID"].Int();
		def.SkinID1 = parser[i]["SkinID1"].Int();
		def.SkinID2 = parser[i]["SkinID2"].Int();

		def.NormalAnims[ModelDef::AT_STAND].AnimID = parser[i]["StandAnim"].Int();
		def.NormalAnims[ModelDef::AT_STAND].Num = parser[i]["StandFrameNum"].Int();

		def.NormalAnims[ModelDef::AT_FREE].AnimID = parser[i]["FreeAnim"].Int();
		def.NormalAnims[ModelDef::AT_FREE].Num = parser[i]["FreeAnimFrameNum"].Int();

		def.NormalAnims[ModelDef::AT_WALK].AnimID = parser[i]["WalkAnim"].Int();
		def.NormalAnims[ModelDef::AT_WALK].Num = parser[i]["WalkAnimFrameNum"].Int();

		def.NormalAnims[ModelDef::AT_RUN].AnimID = parser[i]["RunAnim"].Int();
		def.NormalAnims[ModelDef::AT_RUN].Num = parser[i]["RunAnimFrameNum"].Int();

		def.NormalAnims[ModelDef::AT_FIGHT].AnimID = parser[i]["FightAnim"].Int();
		def.NormalAnims[ModelDef::AT_FIGHT].Num = parser[i]["FightAnimFrameNum"].Int();

		def.NormalAnims[ModelDef::AT_DEATH].AnimID = parser[i]["DeathAnim"].Int();
		def.NormalAnims[ModelDef::AT_DEATH].Num = parser[i]["DeathAnimFrameNum"].Int();

		def.NormalAnims[ModelDef::AT_SLEEP].AnimID = parser[i]["SleepAnim"].Int();
		def.NormalAnims[ModelDef::AT_SLEEP].Num = parser[i]["SleepAnimFrameNum"].Int();

		def.NormalAnims[ModelDef::AT_HITTED].AnimID = parser[i]["HittedAnim"].Int();
		def.NormalAnims[ModelDef::AT_HITTED].Num = parser[i]["HittedAnimFrameNum"].Int();

		def.NormalAnims[ModelDef::AT_BORN].AnimID = parser[i]["BornAnim"].Int();
		def.NormalAnims[ModelDef::AT_BORN].Num = parser[i]["BornAnimFrameNum"].Int();

		for (int j = 0; j < 16; j++)
		{
			std::string strJ = StringHelp::IntToString(j);
			std::string atkAnimKey = "AtkAnim" + strJ;
			std::string atkAnimFrameNum = "AtkAnimFrameNum" + strJ;
			std::string atkAnimHitFrame = "AtkAnimHitFrame" + strJ;

			AnimDef animDef;
			animDef.AnimID = parser[i][atkAnimKey.c_str()].Int();
			animDef.Num = parser[i][atkAnimFrameNum.c_str()].Int();
			animDef.Hit = parser[i][atkAnimHitFrame.c_str()].Int();

			def.mAtkAnims[animDef.AnimID] = animDef;
		}

		mModelDefs[def.ModelID] = def;
	}

	return true;
}
//----------------------------------------------------------------------------
bool X_DefMan::LoadSkillDef(const std::string &filename)
{
	mSkillDefs.clear();

	CSVParser1 parser;

	if (!parser.Load(filename))
		return false;

	parser.SetTitleLine(1);

	int numLines = (int)parser.GetNumLines();
	for (int i = 2; i < numLines; ++i)
	{
		SkillDef def;

		def.SkillID = parser[i]["SkillID"].Int();
		def.IconID = parser[i]["IconID"].Int();
		def.SkillLevel = parser[i]["SkillLevel"].Int();
		def.Name = parser[i]["Name"].String();
		def.SkillDesc = parser[i]["SkillDesc"].String();
		def.CD = parser[i]["CD"].Float();
		def.AnimTime = parser[i]["AnimTime"].Float();
		def.SkillType = parser[i]["SkillType"].Int();
		def.TargetDistance = parser[i]["TargetDistance"].Float();
		def.RangeType = parser[i]["RangeType"].Int();
		def.RangeValue = parser[i]["RangeValue"].Float();
		def.UseMP = parser[i]["UseMP"].Float();
		def.CallAnim = parser[i]["CallAnim"].Int();
		def.CallEffect = parser[i]["CallEffect"].String();
		def.CallAnchor = parser[i]["CallAnchor"].String();
		def.CallPosEffect = parser[i]["CallPosEffect"].String();

		def.ActAnim = parser[i]["ActAnim"].Int();
		def.ActAnimRand = parser[i]["ActAnimRand"].Float();
		def.ActEffect = parser[i]["ActEffect"].String();
		def.ActAnchor = parser[i]["ActAnchor"].Int();
		def.ActPosEffect = parser[i]["ActPosEffect"].String();
		def.ActPosAnchor = parser[i]["ActPosAnchor"].String();
		def.ActPosEffectDelayTime = parser[i]["ActPosEffectDelayTime"].Float();

		def.ActAnim1 = parser[i]["ActAnim1"].Int();
		def.ActAnimRand1 = parser[i]["ActAnimRand1"].Float();
		def.ActEffect1 = parser[i]["ActEffect1"].String();
		def.ActAnchor1 = parser[i]["ActAnchor1"].Int();
		def.ActPosEffect1 = parser[i]["ActPosEffect1"].String();
		def.ActPosAnchor1 = parser[i]["ActPosAnchor1"].Int();
		def.ActPosEffectDelayTime1 = parser[i]["ActPosEffectDelayTime1"].Float();

		def.FlyEffect = parser[i]["FlyEffect"].String();
		def.FlyEffectAnchor = parser[i]["FlyEffectAnchor"].Int();
		def.FlySpeed = parser[i]["FlySpeed"].Float();
		def.FlyDegree = parser[i]["FlyDegree"].Float();
		def.FlyAlignTrace = parser[i]["FlyAlignTrace"].Bool();
		def.IsFlyRoadLine = parser[i]["IsFlyRoadLine"].Bool();
		def.FlyPosEffect = parser[i]["FlyPosEffect"].String();
		def.FlyPosEffectAnchor = parser[i]["FlyPosEffectAnchor"].Int();

		def.AtkedEffect = parser[i]["AtkedEffect"].String();
		def.AtkedAnchor = parser[i]["AtkedAnchor"].Int();
		def.AtkedPosEffect = parser[i]["AtkedPosEffect"].String();
		def.AimedAtkedPosEffect = parser[i]["AimedAtkedPosEffect"].String();

		def.HurtRatio = parser[i]["HurtRatio"].Float();
		def.HurtAdd = parser[i]["HurtAdd"].Float();

		def.StatusRandType = parser[i]["StatusRandType"].Int();

		for (int j = 0; j <= 4; j++)
		{
			SkillStatusDef ssd;

			std::string statusIDStr = "StatusID";
			std::string statusRandStr = "StatusRand";
			std::string statusTargetStr = "StatusTarget";

			if (0 != j)
			{
				std::string jStr = StringHelp::IntToString(j);
				statusIDStr += jStr;
				statusRandStr += jStr;
				statusTargetStr += jStr;
			}

			ssd.StatusID = parser[i][statusIDStr.c_str()].Int();
			ssd.StatusRand = parser[i][statusRandStr.c_str()].Float();
			ssd.StatusTarget = parser[i][statusTargetStr.c_str()].Int();

			def.SkillStatusDefs.push_back(ssd);
		}

		def.AbsoluteHit = parser[i]["AbsoluteHit"].Int();
		def.NextSkillID = parser[i]["NextSkillID"].Int();
		def.ClickIntervalTime = parser[i]["ClickIntervalTime"].Float();
		def.MoveDistance = parser[i]["MoveDistance"].Float();
		def.MoveTimePoint = parser[i]["MoveTimePoint"].Float();

		mSkillDefs[def.SkillID] = def;
	}

	return true;
}
//----------------------------------------------------------------------------
bool X_DefMan::LoadItemDef(const std::string &filename)
{
	mModelDefs.clear();

	CSVParser1 parser;

	if (!parser.Load(filename))
		return false;

	parser.SetTitleLine(1);

	int numLines = (int)parser.GetNumLines();
	for (int i = 2; i < numLines; ++i)
	{
		ItemDef def;

		def.ItemID = parser[i]["ItemID"].Int();
		def.ModelID = parser[i]["ModelID"].Int();
		def.SkinID = parser[i]["SkinID"].Int();
		def.AnchorID = parser[i]["AnchorID"].Int();
		def.EffectID = parser[i]["EffectID"].Int();

		mItemModelDefs[def.ItemID] = def;
	}

	return true;
}
//----------------------------------------------------------------------------
bool X_DefMan::LoadMapDef(const std::string &filename)
{
	mMapDefs.clear();

	CSVParser1 parser;

	if (!parser.Load(filename))
		return false;

	parser.SetTitleLine(1);

	int numLines = (int)parser.GetNumLines();
	for (int i = 2; i < numLines; ++i)
	{
		MapDef def;

		def.MapID = parser[i]["MapID"].Int();
		def.ResID = parser[i]["ResID"].Int();
		def.Name = parser[i]["Name"].String();

		mMapDefs[def.MapID] = def;
	}

	return true;
}
//----------------------------------------------------------------------------
bool X_DefMan::LoadMonsterDef(const std::string &filename)
{
	mMonsterDefs.clear();

	CSVParser1 parser;

	if (!parser.Load(filename))
		return false;

	parser.SetTitleLine(1);
	int numLines = (int)parser.GetNumLines();
	for (int i = 2; i < numLines; ++i)
	{
		MonsterDef def;

		def.MonID = parser[i]["MonID"].Int();
		def.Name = parser[i]["Name"].String();
		def.ModelID = parser[i]["ModelID"].Int();
		def.ModelSize = parser[i]["ModelSize"].Float();
		def.ModelRadius = parser[i]["ModelRadius"].Float();
		def.Mon_Type = parser[i]["Mon_Type"].Int();
		def.Level = parser[i]["Level"].Float();
		def.HP = parser[i]["HP"].Float();
		def.MP = parser[i]["MP"].Float();
		def.Atk = parser[i]["Atk"].Float();
		def.Def = parser[i]["Def"].Float();
		def.AtkSpeed = parser[i]["AtkSpeed"].Float();
		def.Crit = parser[i]["Crit"].Float();
		def.Crit_Hurt = parser[i]["Crit_Hurt"].Float();
		def.Hit = parser[i]["Hit"].Float();
		def.Flee = parser[i]["Flee"].Float();
		def.AtkType = parser[i]["AtkType"].Int();
		def.GuardView = parser[i]["GuardView"].Float();
		def.MoveType = parser[i]["MoveType"].Int();
		def.PatrolMoveSpeed = parser[i]["PatrolMoveSpeed"].Int();
		def.FightMoveSpeed = parser[i]["FightMoveSpeed"].Int();

		//NorSkillIDs
		for (int j = 0; j <= 3; j++)
		{
			std::string normalSkillIDStr = "NorSkillID";
			if (0 != j)
			{
				normalSkillIDStr += StringHelp::IntToString(j);
			}

			int normalSkillID = parser[i][normalSkillIDStr.c_str()].Int();
			if (0 != normalSkillID)
			{
				def.NorSkillIDs.push_back(normalSkillID);
			}
		}

		//SpecialSkillDefs
		for (int j = 0; j <= 3; j++)
		{
			MonsterSkillDef msd;
			std::string skillIDStr = "SkillID";
			if (0 != j)
			{
				skillIDStr = skillIDStr + StringHelp::IntToString(j);
			}
			std::string conditionIDStr = skillIDStr + "_ConditionID";
			std::string conditionValueStr = skillIDStr + "_ConditionValue";
			std::string isRepeatStr = skillIDStr + "_IsRepeat";

			msd.SkillID = parser[i][skillIDStr.c_str()].Int();
			msd.SkillID_ConditionID = parser[i][conditionIDStr.c_str()].Int();
			msd.SkillID_ConditionValue = parser[i][conditionValueStr.c_str()].Float();
			msd.SkillID_IsRepeat = parser[i][isRepeatStr.c_str()].Int();

			def.MonsterSkillDefs.push_back(msd);
		}

		def.ModelChangeRequire = parser[i]["ModelChangeRequire"].Int();
		def.ModelChangeValue = parser[i]["ModelChangeValue"].Float();
		def.ModelChangeMonID = parser[i]["ModelChangeMonID"].Int();

		//DropBagDefs
		for (int j = 0; j <= 5; j++)
		{
			DropBagDef dbd;

			std::string dropBagIDStr = "DropBagID";
			std::string dropRandStr = "DropRand";
			std::string mfTypeStr = "MFType";
			if (0 != j)
			{
				dropBagIDStr = dropBagIDStr + StringHelp::IntToString(j);
				dropRandStr = dropRandStr + StringHelp::IntToString(j);
				mfTypeStr = mfTypeStr + StringHelp::IntToString(j);
			}

			dbd.DropBagID = parser[i][dropBagIDStr.c_str()].Int();
			dbd.DropRand = parser[i][dropRandStr.c_str()].Float();
			dbd.MFType = parser[i][mfTypeStr.c_str()].Int();

			def.DropBagDefs.push_back(dbd);
		}
		mMonsterDefs[def.MonID] = def;
	}
	return true;
}
//----------------------------------------------------------------------------