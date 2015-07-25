// X_Skill.hpp

#ifndef X_SKILL_HPP
#define X_SKILL_HPP

#include "PX2Skill.hpp"

namespace PX2
{

	class X_Skill : public Skill
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(X_Skill);

	public:
		X_Skill();
		virtual ~X_Skill();

		virtual bool Activate();

		void SetDefPartIndex(int defPartIndex);
		int GetDefPartIndex() const;

		void SetDefParts(const std::vector<int> &sdefParts);
		const std::vector<int> &GetDefParts() const;

		void SetNextSkillID(int skillID);
		int GetNextSkillID() const;

	protected:
		int mDefPartIndex;
		std::vector<int> mDefParts;

		int mNextSkillID;
	};

#include "X_Skill.inl"
	PX2_REGISTER_STREAM(X_Skill);
	typedef Pointer0<X_Skill> X_SkillPtr;

}

#endif