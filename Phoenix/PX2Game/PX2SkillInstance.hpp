/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkillInstance.hpp
*
*/

#ifndef PX2SKILLINSTANCE_HPP
#define PX2SKILLINSTANCE_HPP

#include "PX2GamePre.hpp"
#include "PX2Controlledable.hpp"
#include "PX2EffectNode.hpp"
#include "PX2Gameable.hpp"
#include "PX2SkillActor.hpp"

namespace PX2
{

	class Skill;
	class SkillStep;
	class Character;

	class SkillInstance : public Gameable
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkillInstance);

	public:
		SkillInstance (Skill *skill);
		virtual ~SkillInstance ();

		int GetCurInstanceID () const;

		void SetBeShared (bool shared);
		bool IsBeShared () const;
		
		virtual void Update (double appSeconds, double elapsedSeconds);
		bool IsOver () const;

		bool IsSkillCallOver () const;

		void Enter (SkillStep *step);
		virtual void OnLeave (SkillStep *step);
		virtual void OnEnter (SkillStep *step);

		void AddSkillActor (int aimTargetID, EffectActor *skillActor);
		EffectActor *GetSkillActor (int aimTargetID);

		void SetAimTarget (int id);
		int GetAimTarget () const;

		bool AddTarget (int id);
		bool HasTarget (int id);
		int GetNumTargets () const;
		int GetTarget (int i);
		Character *GetTargetCharacter (int i);
		bool RemoveTarget (int id);
		void RemoveAllTargets ();

		Skill *GetSkill ();

	protected:
		Skill *mSkill;
		Pointer0<SkillStep> mCurSkillStep;
		bool mIsShared;
		float mCurSkillStepRunTime;
		bool mIsSkillCallOver;
		bool mIsCalingCallOver;
		float mCalingCallOverTime;
		float mCallOverTime;
		bool mIsOver;
		std::map<int, EffectActorPtr> mSkillActors;
		int mAnimTarget;
		std::vector<int> mTargets;
		bool mIsLinked;

		int mCurInstanceID;

		static int GetNextID ();
		static int msNextID;
	};

#include "PX2SkillInstance.inl"
	PX2_REGISTER_STREAM(SkillInstance);
	typedef Pointer0<SkillInstance> SkillInstancePtr;

}

#endif