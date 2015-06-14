// PX2SkillComponent.hpp

#ifndef PX2SKILLCOMPONENT_HPP
#define PX2SKILLCOMPONENT_HPP

#include "PX2Controller.hpp"
#include "PX2Skill.hpp"

namespace PX2
{

	class SkillController : public Controller
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkillController);

	public:
		SkillController();
		virtual ~SkillController();

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
	PX2_REGISTER_STREAM(SkillController);
	typedef Pointer0<SkillController> SkillComponentPtr;

}

#endif