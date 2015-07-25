// X_Chara.hpp

#ifndef X_CHARA_HPP
#define X_CHARA_HPP

#include "PX2Character.hpp"
#include "X_Def.hpp"
#include "X_Skill.hpp"

namespace PX2
{

	class X_Chara : public Character
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(X_Chara);

		// 构造
	public:
		enum CharaType
		{
			CT_PLAYER,
			CT_MONSTER,
			CT_NPC,
			CT_SKILLOBJ,
			CT_MAX_TYPE
		};
		X_Chara(CharaType type);
		virtual ~X_Chara();

		void Update(double appSeconds, double elapsedSeconds);
		virtual void DoExecute(Event *event);

		void SetCharType(CharaType type);
		CharaType GetCharType() const;

	private:
		X_Chara();
		void ConstructInit();

		CharaType mCharType;

		// 等级类型经验
	public:
		virtual void SetTypeID(int typeID);
		virtual void SetLevel(int level);

	protected:
		ActorDef *mActorDef;
		ModelDef *mModelDef;
		MonsterDef *mMonsterDef;
		std::vector<int> mNorSkillIDs;
		std::vector<SkillDef*> mNorSkillDefs;
		std::map<int, SkillDef*> mSkillDefMap;
		int mCurLevelExp;
		int mGold;
		int mNewPlayerGuideID;
		int mNumMaxBag;

		// 模型动作
	public:
		void LoadModel();
		void LoadAnims();

		void LoadNormalAnimIDNameMap();
		std::map<std::string, int> NormalAnimIDNameMap;

	protected:
		bool mIsModelLoaded;
		bool mIsAnimsLoaded;

		// 技能
	public:
		void CreateSkills();

		void CollectADefSkillStep();
		void ActivateSkill(int skillID);

	protected:
		X_Skill *_CreateSkill(int skillTypeID, int defPartIndex);
		void UpdateActivateDefSkill();

		std::vector<X_SkillPtr> mDefPartSkills;
		int mCurDefPartSkillIndex;
		int mCollectPartSkillNum;

		// 战斗
	public:
		void Bat();

		virtual void CalSearchTarget();

		virtual void CalPursueTarget(float elpasedSeconds);

		virtual void CalAttackTarget(float elpasedSeconds);

	protected:
		void SkillActLogic(Character *target);

		bool mIsHardStraight;
		float mHardStraightETime;
	};

#include "X_Chara.inl"
	typedef Pointer0<X_Chara> X_CharaPtr;

}

#endif