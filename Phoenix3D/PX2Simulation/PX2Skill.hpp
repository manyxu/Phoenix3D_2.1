// PX2Skill.hpp

#ifndef PX2SKILL_HPP
#define PX2SKILL_HPP

#include "PX2PropModify.hpp"
#include "PX2APoint.hpp"
#include "PX2SkillStep.hpp"
#include "PX2SimulationDataDefine.hpp"
#include "PX2SkillInstance.hpp"

namespace PX2
{

	class Character;
	class SkillInstance;

	class Skill : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Skill);

	public:
		Skill();
		virtual ~Skill();

	public_internal:
		void SetCharacter(Character *chara);

	public:
		Character *GetCharacter();
		virtual void OnAdded();
		virtual void OnRemove();

	protected:
		Character *mCharacter;

		// id def
	public:
		virtual void SetTypeID(int id);
		int GetTypeID() const;

		void SetDefPointer(void *pointer);
		void *GetDefPointer();

		void SetLevel(int level);
		int GetLevel() const;
		void SetMaxLevel(int level);
		int GetMaxLevel() const;

	protected:
		int mTypeID;
		void *mDefPointer;
		int mLevel;
		int mMaxLevel;

		// trigger
	public:
		PX2_DECLARE_PM_F(TrigerDistance);

		// range
	public:
		void SetBeRangeType(bool isRangeType);
		bool IsRangeType() const;
		void SetNumRangeLock(int num);
		int GetNumRangeLock() const;

		enum NearFarType
		{
			NFT_NEAR,
			NFT_FAR,
			NFT_MAX_TYPE
		};
		void SetNearFarType(NearFarType type);
		NearFarType GetNearFarType() const;

		enum ShapeType
		{
			ST_SPHERE,
			ST_FAN,
			ST_BOX,
			ST_MAX_TYPE
		};
		void SetShapeType(ShapeType type);
		ShapeType GetShapeType() const;

		PX2_DECLARE_PM_F(RadiusLength); // 半径或者长度
		PX2_DECLARE_PM_F(Width);
		PX2_DECLARE_PM_F(FanDegree);

		void SetPursurtTarget(bool isPursurtTarget);
		bool IsPursurtTarget() const;

	protected:
		bool mIsRangeType;
		int mNumRangeLock;
		NearFarType mNearFarType;
		ShapeType mShapeType;
		bool mIsPursurtTarget;

		// CD Activate
	public:
		void SetPriority(int priority);
		int GetPriority() const;

		PX2_DECLARE_PM_F(ActivateProbability);
		PX2_DECLARE_PM_F(NumMultiInstance);

		PX2_DECLARE_PM_F(CDTime);
	public:
		void ResetCD();
		void SetOnCD(bool cd);
		bool IsOnCD() const;
		void SetOnCDTime(float onCDTime);
		float GetOnCDTime() const;
		void PauseCD(bool pause);
		bool IsPauseCD() const;

		PX2_DECLARE_PM_F(ActivateAllowTimes);

	public:
		virtual bool Activate();
		virtual void DisActivate();
		bool IsActivatting() const;

		std::bitset<PX2_ACTOR_BS_SIZE> GetSkillQueryBitSet();

	protected:
		int mPriority;
		bool mIsOnCD;
		float mOnCDTime;
		bool mIsPauseCD;
		bool mIsActivatting;
		int mActivatedTimes;

		std::vector<Pointer0<SkillInstance> > mSkillInstances;

		// affect
	public:
		enum AffectGroupType
		{
			AGT_SELF,
			AGT_SELF_GROUP,
			AGT_SELF_GROUP_EXCEPTME,
			AGT_ENEMYS,
			AGT_BOTH,
			AGT_MAX_TYPE
		};
		void SetAffectGroupType(AffectGroupType type);
		AffectGroupType GetAffectGroupType() const;

		void AddAffectParam(const std::string &name, float val);
		void RemoveAffectParam(const std::string &name);
		bool IsHasAffectParam(const std::string &name);
		float GetAffectParam(const std::string &name);

	protected:
		AffectGroupType mAffectGroupType;
		std::map<std::string, float> mAffectParams;

		// instance
	public:
		int GetNumInstances() const;
		void ClearSkillInstance();

		// SkillStep
	public:
		bool SetFirstSkillStep(SkillStep *step);
		SkillStep *GetFirstSkillStep();
		SkillStep *GetSkillStepByName(const std::string &name);
		SkillStep *GetLastSkillStep();

	protected:
		SkillStepPtr mFirstSkillStep;

		// query range
	public:
		static bool IsInRange(const APoint &fromPos, float fromLength,
			float fromWidth, const AVector &fromFaceDir, float fromDegree,
			const APoint &targetPos, float targetRadius, ShapeType type,
			bool doBoxRolate);

		static bool IsInBoxRange(const APoint &center, const AVector &dir,
			float length, float width, const APoint &point, float targetRadius);

		static bool IsInFanRange(const APoint &center, const AVector &dir,
			float radian, const APoint &point);
	};

#include "PX2Skill.inl"
	PX2_REGISTER_STREAM(Skill);
	typedef Pointer0<Skill> SkillPtr;

}

#endif