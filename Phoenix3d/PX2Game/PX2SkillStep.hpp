/*
*
* 文件名称	：	PX2SkillStep.hpp
*
*/

#ifndef PX2SKILLSTEP_HPP
#define PX2SKILLSTEP_HPP

#include "PX2Gameable.hpp"
#include "PX2SkillActor.hpp"

namespace PX2
{

	class Skill;
	class SkillInstance;

	class SkillStep : public Gameable
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(SkillStep);

	public:
		virtual ~SkillStep ();

		Skill *GetSkill ();
		SkillInstance *GetCurEnteredSkillInstance (); // 只在Enter的生命周期中有效

		void SetProbability (float pro);
		float GetProbability () const;

		enum Mode
		{
			M_RANGETIME,
			M_FARTRACK,
			M_LINK,
			M_MAX_MODE
		};
		Mode GetMode () const;

		// callover
		void SetSkillCallOverAtThisStep (bool callOver);
		bool IsSkillCallOverAtThisStep () const;
		enum TimeType
		{
			TT_TIME,
			TT_ANIMPERCENT,
			TT_MAX_TYPE
		};
		void SetSkillCallOverTimeType (TimeType type);
		TimeType GetSkillCallOverTimeType () const;
		void SetSkillCallOverValue (float val);
		float GetSkillCallOverValue () const;
		float GetSkillCallOverTime () const;

		// anim
		void SetAnimName (const std::string &animName);
		const std::string &GetAnimName () const;
		void SetAnimProb (float prob);
		float GetAnimProb () const;

		void SetAnimName1 (const std::string &animName1);
		const std::string &GetAnimName1 () const;
		void SetAnimProb1 (float prob1);
		float GetAnimProb1 () const;

		// effect
		void SetSelfEffectFilename (const std::string &selfEffectFilename);
		const std::string &GetSelfEffectFilename () const;
		void SetSelfEffectAnchor (const std::string &selfAnchor);
		const std::string GetSelfEffectAnchor () const;
		void SetSelfEffectTime (float seconds);
		float GetSelfEffectTime () const;

		void SetSelfPosEffectFilename (const std::string &posEffectFilename);
		const std::string &GetSelfPosEffectFilename () const;
		void SetSelfPosEffectAnchor (const std::string &selfAnchor);
		const std::string GetSelfPosEffectAnchor () const;
		void SetSelfPosEffectTime (float seconds);
		float GetSelfPosEffectTime () const;
		void SetSelfPosEffectDelayTime (float seconeds);
		float GetSelfPosEffectDelayTime () const;

		// effect1
		void SetSelfEffect1Filename (const std::string &selfEffectFilename);
		const std::string &GetSelfEffect1Filename () const;
		void SetSelfEffect1Anchor (const std::string &selfAnchor);
		const std::string GetSelfEffect1Anchor () const;
		void SetSelfEffect1Time (float seconds);
		float GetSelfEffect1Time () const;

		void SetSelfPosEffect1Filename (const std::string &posEffectFilename);
		const std::string &GetSelfPosEffect1Filename () const;
		void SetSelfPosEffect1Anchor (const std::string &selfAnchor);
		const std::string GetSelfPosEffect1Anchor () const;
		void SetSelfPosEffect1Time (float seconds);
		float GetSelfPosEffect1Time () const;
		void SetSelfPosEffectDelayTime1 (float seconeds);
		float GetSelfPosEffectDelayTime1 () const;

		// target
		void SetTargetEffectFilename (const std::string &targetEffectFilename);
		const std::string &GetTargetEffectFilename () const;
		void SetTargetEffectAnchor (const std::string &targetAnchor);
		const std::string &GetTargetEffectAnchor () const;
		void SetTargetEffectTime (float seconds);
		float GetTargetEffectTime () const;

		void SetTargetPosEffectFilename (const std::string &posEffectFilename);
		const std::string &GetTargetPosEffectFilename () const;
		void SetTargetPosEffectTime (float seconds);
		float GetTargetPosEffectTime () const;

		void SetAnimedTargetPosEffectFilename (const std::string &effectFilename);
		const std::string &GetAnimedTargetPosEffectFilename () const;

		// script handler
		void SetScriptHandler_Enter (const std::string &handler);
		const std::string &GetScriptHandler_Enter () const;

		void SetScriptHandler_Leave (const std::string &handler);
		const std::string &GetScriptHandler_Leave () const;

		virtual void OnEnter (SkillInstance *instance);
		virtual void OnLeave (SkillInstance *instance);

		// step
		bool SetNextStep (SkillStep *next);
		SkillStep *GetNextStep ();

public_internal:
		void SetSkill (Skill *skill);
		virtual void SaveToXMLNode (XMLNode nodeParent);
		virtual void LoadFromXMLNode (XMLNode node);

	protected:
		SkillStep (Mode mode);

		Skill *mSkill;
		SkillInstance *mCurEnteredSkillInstance;

		Mode mMode;
		float mProbability;
		bool mIsSkillCallOverAtThisStep;
		TimeType mSkillCallOverTimeType;
		float mSkillCallOverValue;
		
		std::string mAnimName;
		float mAnimProb;
		std::string mAnimName1;
		float mAnimProb1;

		// effect
		std::string mSelfEffectFilename;
		std::string mSelfEffectAnchor;
		float mSelfEffectTime;

		std::string mSelfPosEffectFilename;
		std::string mSelfPosEffectAnchor;
		float mSelfPosEffectTime;
		float mSelfPosEffectDelayTime;

		// effect1
		std::string mSelfEffect1Filename;
		std::string mSelfEffect1Anchor;
		float mSelfEffect1Time;

		std::string mSelfPosEffect1Filename;
		std::string mSelfPosEffect1Anchor;
		float mSelfPosEffect1Time;
		float mSelfPosEffectDelayTime1;

		// target
		std::string mTargetEffectFilename;
		std::string mTargetEffectAnchor;
		float mTargetEffectTime;

		std::string mTargetPosEffectFilename;
		float mTargetPosEffectTime;

		std::string mAnimedTargetPosEffectFilename;

		std::string mScriptHandler_Leave;
		std::string mScriptHandler_Enter;

		Pointer0<SkillStep> mNextStep;

	private:
		SkillStep ();
	};

#include "PX2SkillStep.inl"
	PX2_REGISTER_STREAM(SkillStep);
	typedef Pointer0<SkillStep> SkillStepPtr;

}

#endif