//  X_Def.hpp

#ifndef X_DEF_HPP
#define X_DEF_HPP

#include "X_Pre.hpp"

namespace PX2
{

	struct AnimDef
	{
		AnimDef();
		~AnimDef();

		int AnimID;
		int Num;
		int Hit;
	};

	class ModelDef
	{
	public:
		ModelDef();
		~ModelDef();

		int ModelID;
		int IconID;
		int SkinID;
		int SkinID1;
		int SkinID2;

		enum AnimType
		{
			AT_STAND,
			AT_FREE,
			AT_WALK,
			AT_RUN,
			AT_FIGHT,
			AT_DEATH,
			AT_SLEEP,
			AT_HITTED,
			AT_BORN,
			AT_MAXTYPE
		};

		static std::string sAnimTypeStrs[AT_MAXTYPE];

		std::map<AnimType, AnimDef> NormalAnims;
		const AnimDef *GetNormalDef(AnimDef type) const;

		std::map<int, AnimDef> mAtkAnims;
		const AnimDef *GetAtkAnimDef(int type) const;
	};

	class ActorDef
	{
	public:
		ActorDef();
		~ActorDef();

		int ActorID;
		int ModelID;
		std::vector<int> NorSkillIDs;
		std::vector<int> SkillIDs;
	};

	class SkillStatusDef
	{
	public:
		SkillStatusDef();
		~SkillStatusDef();

		int StatusID;
		float StatusRand;
		int StatusTarget;
	};

	class SkillDef
	{
	public:
		SkillDef();
		~SkillDef();

		int SkillID;
		int IconID;
		int SkillLevel;
		std::string Name;
		std::string SkillDesc;
		float CD;
		float AnimTime;
		int SkillType;
		float TargetDistance;
		int RangeType;
		float RangeValue;
		float UseMP;
		int CallAnim;
		std::string CallEffect;
		std::string CallAnchor;
		std::string CallPosEffect;

		int ActAnim;
		float ActAnimRand;
		std::string ActEffect;
		int ActAnchor;
		std::string ActPosEffect;
		std::string ActPosAnchor;
		float ActPosEffectDelayTime;

		int ActAnim1;
		float ActAnimRand1;
		std::string ActEffect1;
		int ActAnchor1;
		std::string ActPosEffect1;
		int ActPosAnchor1;
		float ActPosEffectDelayTime1;

		std::string FlyEffect;
		int FlyEffectAnchor;
		float FlySpeed;
		float FlyDegree;
		bool FlyAlignTrace;
		bool IsFlyRoadLine;
		float FlyRoadLineTime;
		std::string FlyPosEffect;
		int FlyPosEffectAnchor;
		std::string AtkedEffect;
		int AtkedAnchor;
		std::string AtkedPosEffect;
		std::string AimedAtkedPosEffect;

		float HurtRatio;
		float HurtAdd;

		int StatusRandType;

		std::vector<SkillStatusDef> SkillStatusDefs;

		int AbsoluteHit;

		int NextSkillID;

		float ClickIntervalTime;

		float MoveDistance;
		float MoveTimePoint;
	};

	class ItemDef
	{
	public:
		ItemDef();
		~ItemDef();

		int ItemID;
		int ModelID;
		int SkinID;
		int AnchorID;
		int EffectID;
	};

	class MapDef
	{
	public:
		MapDef();
		~MapDef();

		int MapID;
		int ResID;
		std::string Name;
	};

	class MonsterSkillDef
	{
	public:
		MonsterSkillDef();
		~MonsterSkillDef();

		int SkillID;
		int SkillID_ConditionID;
		float SkillID_ConditionValue;
		int SkillID_IsRepeat;
	};

	class DropBagDef
	{
	public:
		DropBagDef();
		~DropBagDef();

		int DropBagID;
		float DropRand;
		int MFType;
	};

	class MonsterDef
	{
	public:
		MonsterDef();
		~MonsterDef();

		int MonID;
		std::string Name;
		int ModelID;
		float ModelSize;
		float ModelRadius;
		int Mon_Type;
		float Level;
		float HP;
		float MP;
		float Atk;
		float Def;
		float AtkSpeed;
		float Crit;
		float Crit_Hurt;
		float Hit;
		float Flee;
		int AtkType;
		float GuardView;
		int MoveType;
		int PatrolMoveSpeed;
		int FightMoveSpeed;
		std::vector<int> NorSkillIDs;
		std::vector<MonsterSkillDef> MonsterSkillDefs;
		int ModelChangeRequire;
		float ModelChangeValue;
		int ModelChangeMonID;
		std::vector<DropBagDef> DropBagDefs;
	};

}

#endif