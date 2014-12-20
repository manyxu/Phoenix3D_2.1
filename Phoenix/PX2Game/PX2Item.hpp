/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Item.hpp
*
*/

#ifndef PX2ITEM_HPP
#define PX2ITEM_HPP

#include "PX2Actor.hpp"
#include "PX2AffectObject.hpp"

namespace PX2
{

	class Character;
	class SkillInstance;

	class Item : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Item);

	public:
		Item ();
		virtual ~Item ();

		void SetTypeString (const std::string &typeString);
		const std::string &GetTypeString () const;

		void SetCanBeEquipped (bool can);
		bool IsCanBeEquipped () const;
		void SetEquippedDoUse (bool use);
		bool IsEquippedDoUse () const;

		bool IsEquipped () const;	

		virtual void SetLevel (int level);
		int GetLevel () const;

		bool CanUseNow () const;
		virtual void Use (bool use);
		bool IsUsing () const;

		void SetScriptHandler_Use (const std::string &handler);
		const std::string &GetScriptHandler_Use () const;

		void AddScriptHandler_OnBeAffect (const std::string &name, const std::string &handler);
		void RemoveScriptHandler_OnBeAffect (const std::string &name);

		void AddScriptHandler_OnSucAffect (const std::string &name, const std::string &handler);
		void RemoveScriptHandler_OnSucAffect (const std::string &name);

		virtual void OnBeAffect (AffectObject *ao);
		virtual void OnSucAffect (AffectObject *ao);

		Character *GetCharacter () const;

public_internal:
		void SetCharacter (Character *character);
		void SetEquipped (bool equip);

	protected:
		Character *mCharacter;
		
		std::string mTypeString;
		bool mIsCanBeEquipped;
		bool mIsEquippedDoUse;
		bool mIsEquipped;
		int mLevel;
		std::string mScriptHandler_Use;
		std::map<std::string, std::string> mScriptHandlers_OnBeAffect;
		std::map<std::string, std::string> mScriptHandlers_OnSucAffect;
		bool mCanUseNow;
		bool mIsUsing;
	};

#include "PX2Item.inl"
	PX2_REGISTER_STREAM(Item);
	typedef Pointer0<Item> ItemPtr;

}

#endif