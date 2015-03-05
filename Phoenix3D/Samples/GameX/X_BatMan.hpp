// X_BatMan.hpp

#ifndef X_BATMAN_HPP
#define X_BATMAN_HPP

#include "X_Pre.hpp"
#include "PX2Singleton.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Scene.hpp"
#include "PX2NotFreeObjectPool.hpp"
#include "PX2SkillInstance.hpp"

namespace PX2
{

	class X_Chara;

	class X_BatMan : public Singleton < X_BatMan >
	{
	public:
		X_BatMan();
		virtual ~X_BatMan();

		void Update(float appSeconds, float elapsedSeconds);
		void Clear();

		Skill *GetHeighestPrioritySkill(std::list<Skill*> &skills);
		void CharAAttack(SkillInstance *si, X_Chara *target);
	};

#include "X_BatMan.inl"
#define X_BATMAN X_BatMan::GetSingleton()

}

#endif