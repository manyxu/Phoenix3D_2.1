// PX2SkillComponent.hpp

#ifndef PX2SKILLCOMPONENT_HPP
#define PX2SKILLCOMPONENT_HPP

#include "PX2Component.hpp"
#include "PX2Skill.hpp"

namespace PX2
{

	class SkillComponent : public Component
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkillComponent);

	public:
		SkillComponent();
		virtual ~SkillComponent();

		// skill
	public:
		bool AddSkill(Skill *skill);
		bool HasSkill(Skill *skill);
		int GetNumSkills() const;
		Skill *GetSkillByID(int id);
		Skill *GetSkillByTypeID(int typeID);
		Skill *GetSkillByName(const std::string &name);
		Skill *GetDefSkill();
		Skill *GetSkill(int i);
		bool RemoveSkill(Skill *skill);
		void RemoveAllSkills();

		bool IsAnySkillHasInstance();
		bool IsAllSkillCallOver();
		void ResetAllSkillsCD();

		// 0 不需要，1需要，2忽视
		std::list<Skill *> GetValidSkills(
			const Character *target, bool useTrigerDis, int positive, int needTarget, int cdOK);

	protected:
		std::vector<SkillPtr> mSkills;
		SkillPtr mDefSkill;

		// ai skill
	public:
		void SetWatchDistance(float dist);
		float GetWatchDistance() const;

		virtual void SetAimTarget(int targetID);
		int GetAimTarget() const;
		Character *GetAimTargetCharacter() const;
		Character *GetAimTargetCharacterAlive() const;

		void SetCanBeAimed(bool can);
		bool IsCanBeAimed() const;
		int GetNumAimingMe() const;

	protected:
		float mWatchDistance;
		bool mIsCanAimed;
		int mAimTargetID;
		int mNumAimingMe;
	};

#include "PX2SkillComponent.inl"
	PX2_REGISTER_STREAM(SkillComponent);
	typedef Pointer0<SkillComponent> SkillComponentPtr;

}

#endif