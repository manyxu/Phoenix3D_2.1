// PX2SkillInstance.hpp

#ifndef PX2SKILLINSTANCE_HPP
#define PX2SKILLINSTANCE_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Object.hpp"

namespace PX2
{

	class Skill;
	class SkillStep;
	class Character;
	class Actor;

	class SkillInstance : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkillInstance);

	public:
		Skill *GetSkill();

	public:
		SkillInstance(Skill *skill);
		virtual ~SkillInstance();

		virtual void Update(double appSeconds, double elapsedSeconds);

		int GetCurInstanceID() const;

		void SetBeShared(bool shared);
		bool IsBeShared() const;

		bool IsOver() const;
		bool IsSkillCallOver() const;

		void Enter(SkillStep *step);
		virtual void OnLeave(SkillStep *step);
		virtual void OnEnter(SkillStep *step);

	protected:
		Skill *mSkill;
		Pointer0<SkillStep> mCurSkillStep;
		float mCurSkillStepRunTime;

		int mCurInstanceID;
		bool mIsShared;

		bool mIsOver;

		bool mIsSkillCallOver;

		bool mIsCalingCallOver;
		float mCalingCallOverTime;
		float mCallOverTime;

		// Targets
	public:
		void SetAimTarget(int id);
		int GetAimTarget() const;

		bool AddTarget(int id);
		bool HasTarget(int id);
		int GetNumTargets() const;
		int GetTarget(int i);
		Character *GetTargetCharacter(int i);
		bool RemoveTarget(int id);
		void RemoveAllTargets();

	protected:
		int mAnimTargetID;
		std::vector<int> mTargets;
		
		bool mIsSkillStepLink_LinkedToTarget;

	public:
		void AddSkillActor(int aimTargetID, Actor *skillActor);
		Actor *GetSkillActor(int aimTargetID);

	protected:
		std::map<int, Pointer0<Actor> > mSkillActors;

	protected:
		static int GetNextID();
		static int msNextID;
	};

#include "PX2SkillInstance.inl"
	PX2_REGISTER_STREAM(SkillInstance);
	typedef Pointer0<SkillInstance> SkillInstancePtr;

}

#endif