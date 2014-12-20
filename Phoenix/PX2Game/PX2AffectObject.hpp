/*
*
* 文件名称	：	PX2AffectObject.hpp
*
*/

#ifndef PX2_AFFECTOBJECT_HPP
#define PX2_AFFECTOBJECT_HPP

#include "PX2GamePre.hpp"
#include "PX2SmartPointer.hpp"

namespace PX2
{

	class Character;
	class Skill;
	class SkillInstance;
	class Item;
	class Buf;

	class AffectObject
	{
	public:
		AffectObject ();
		~AffectObject();

		Character *AffectCharacter;
		Skill *AffectSkill;
		SkillInstance *AffectSkillInstance;
		Item *AffectItem;
		Buf *AffectBuf;
		int AffectType; // 1 物理，2魔法，3加血
		bool IsCrited;
		float Value;
		int LastAffectDoType; // 最后伤害做什么事情, 1 回血
		float LastAffectDoTypeValue; 
		Character *BeAffectCharacter;
	};

	typedef Pointer0<AffectObject> AffectObjectPtr;

}

#endif