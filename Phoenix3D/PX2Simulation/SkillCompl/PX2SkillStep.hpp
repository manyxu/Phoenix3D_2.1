// PX2SkillStep.hpp

#ifndef PX2SKILLSTEP_HPP
#define PX2SKILLSTEP_HPP

#include "PX2Object.hpp"

namespace PX2
{

	class Skill;
	class SkillInstance;

	class SkillStep_AnimObj
	{
	public:
		SkillStep_AnimObj();
		~SkillStep_AnimObj();

		int ID;
		float Probability;
	};

	class SkillStep_EffectObj
	{
	public:
		SkillStep_EffectObj();
		~SkillStep_EffectObj();

		std::string EffectFilename;
		int AnchorID;
		float DelayTime;
	};

	class SkillStep : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkillStep);

	public:
		virtual ~SkillStep();

		Skill *GetSkill();
		SkillInstance *GetCurEnteredSkillInstance(); // 只在Enter的生命周期中有效

		void SetProbability(float pro);
		float GetProbability() const;

		// mode
		enum Mode
		{
			M_RANGETIME,
			M_FLY,
			M_LINK,
			M_MAX_MODE
		};
		Mode GetMode() const;

		// time
		enum TimeType
		{
			TT_TIME,
			TT_ANIMPERCENT,
			TT_MAX_TYPE
		};
		void SetSkillCallOverTimeType(TimeType type);
		TimeType GetSkillCallOverTimeType() const;
		void SetSkillCallOverValue(float val);
		float GetSkillCallOverValue() const;
		float GetSkillCallOverTime() const;

		void SetSkillCallOverAtThisStep(bool callOver);
		bool IsSkillCallOverAtThisStep() const;

		// anim
		void AddAnim(int id, float prob=1.0f);
		int GetNumAnims() const;
		int GetAnimID(int i) const;
		float GetAnimProbability(int i) const;
		std::vector<SkillStep_AnimObj> &GetSkillStepAnimObjects();

		enum EffectType
		{
			ET_SELF,
			ET_SELF_POS,
			ET_TARGET,
			ET_TARGET_POS,
			ET_AIMEDTARGET,
			ET_AIMEDTARGET_POS,
			ET_MAX_TYPE
		};
		void AddEffectObj(EffectType type, const SkillStep_EffectObj &obj);
		SkillStep_EffectObj *GetEffectObj(EffectType type);

		// script handler
		virtual void OnEnter(SkillInstance *instance);
		virtual void OnLeave(SkillInstance *instance);

		void SetScriptHandler_Enter(const std::string &handler);
		const std::string &GetScriptHandler_Enter() const;

		// step
		bool SetNextStep(SkillStep *next);
		SkillStep *GetNextStep();

	public_internal:
		void SetSkill(Skill *skill);

	protected:
		SkillStep(Mode mode);

		Skill *mSkill;
		SkillInstance *mCurEnteredSkillInstance;

		float mProbability;
		Mode mMode;
		TimeType mSkillCallOverTimeType;
		float mSkillCallOverValue;
		bool mIsSkillCallOverAtThisStep;

		std::vector<SkillStep_AnimObj> mAnimObjs;
		int mCurActAnimID;

		std::map<EffectType, SkillStep_EffectObj> mEffectObjs;

		std::string mScriptHandler_Enter;

		Pointer0<SkillStep> mNextStep;

	private:
		SkillStep();
	};

#include "PX2SkillStep.inl"
	PX2_REGISTER_STREAM(SkillStep);
	typedef Pointer0<SkillStep> SkillStepPtr;

}

#endif