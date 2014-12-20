/*
*
* 文件名称	：	PX2Character.hpp
*
*/

#ifndef PX2CHARACTER_HPP
#define PX2CHARACTER_HPP

#include "PX2Actor.hpp"
#include "PX2Item.hpp"
#include "PX2Skill.hpp"
#include "PX2Buf.hpp"
#include "PX2EffectNode.hpp"
#include "PX2TargetTransformController.hpp"
#include "PX2Animation.hpp"
#include "PX2AffectObject.hpp"
#include "PX2StateMachine.hpp"
#include "PX2SkinController.hpp"
#include "PX2AnimationObject.hpp"

namespace PX2
{

	class Character : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Character);

	public:
		Character ();
		virtual ~Character ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		virtual void Initlize ();

		// save
	public:
		virtual void SaveToXMLNode (XMLNode nodeParent);
		virtual void LoadFromXMLNode (XMLNode node);

		// Movable
	public:
		virtual void SetMovableFilename (const std::string &filename, bool shareVIM);

		void SetUseAutoWorldBound (bool isUseAutoWorldBound);
		bool IsUseAutoWorldBound () const;

		void SetAutoWorldBoundRadius (float radius);
		float GetAutoWorldBoundRadius () const;

	private:
		bool mIsAutoWorldBound;
		float mAutoWorldBoundRadius;

		// level exp
	public:
		virtual void SetLevel (int level);
		int GetLevel () const;

		virtual void SetExp (int exp);
		int GetExp ();
		int GetExpCurLevel ();

	protected:
		int mLevel;
		int mExp;
		int mExpCurLevel;

		// hp ap
	public:
		virtual void SetBaseHPCurLevel (int hp);
		int GetBaseHPCurLevel () const;

		void SetCurHPNoReduce (bool de);
		bool IsCurHPNoRecline () const;

		virtual void SetCurHP (int hp);
		virtual void AddCurHP (int hp, int tag);

		int GetCurHP () const;
		void AddMHP (const std::string &factorName, int modHP);
		void RemoveMHP (const std::string &factorName);
		std::map<std::string, int> GetMMapHPs () const;
		void CalMHP ();
		int GetMHP () const;
		float GetHPPercent () const;

		// ap
		virtual void SetBaseAPCurLevel (int ap);
		int GetBaseAPCurLevel () const;

		virtual void SetCurAP (int ap);
		int GetCurAP () const;
		void AddMAP (const std::string &factorName, int modAP);
		void RemoveMAP (const std::string &factorName);
		std::map<std::string, int> GetMMapAPs () const;
		void CalMAP ();
		int GetMAP () const;

		void SetDieDoDelete (bool isDieDoDelete);
		bool IsDieDoDelete () const;

		virtual void SetDead (bool dead);
		virtual void Die ();
		bool IsDead () const;

		void SetScriptHandler_OnDie (const std::string &handler);
		const std::string &GetScriptHandler_OnDie () const;
		void AddScriptHandler_OnDie (const std::string &name, const std::string &handler);
		void RemoveScriptHandler_OnDie (const std::string &name);

	protected:
		int mBaseHPCurLevel;
		bool mIsCurHPNoReduce;
		int mHP;
		std::map<std::string, int> mMMapHPs;
		int mMHP;
		int mAP;
		std::map<std::string, int> mMMapAPs;
		int mMAP;
		int mBaseAPCurLevel;
		bool mIsDead;
		bool mIsDieDoDelete;

		// anims
	public:
		bool AddAnim (Animation *anim);
		bool HasAnim (Animation *anim);
		bool RemoveAnim (Animation *anim);
		void RemoveAllAnims ();
		int GetNumAnims () const;
		Animation *GetAnim (int i);
		Animation *GetAnimByName (const std::string &name);
		Animation *GetStandAnim ();
		virtual void PlayAnim (Animation *anim);
		virtual void StopAnim (Animation *anim);
		virtual void StopCurAnim ();
		virtual void PlayCurAnim ();
		virtual void PlayAnimByName (const std::string &name);
		Animation *GetCurPlayingAnim ();
		bool IsHasAnimPlaying () const;

		void SetModelTagName (const std::string &modelTagName);
		const std::string &GetModelTagName () const;

		Movable *GetSkinMovable ();
		Movable *GetModelAnimMovable ();

		std::map<FString, BlendTransformController*> &GetBTCMap ();

		static bool IsNodeHasMesh (Node *node);

	protected:
		void _CalSkins ();
		void _CalAnimNode (Movable *mov);

		std::vector<AnimationPtr> mAnims;
		AnimationPtr mStandbyAnim;
		std::string mModelTagName;

		MovablePtr mSkinMovable;
		MovablePtr mModelAnimMovable;

		std::map<FString, BlendTransformController*> mBTCMap;

		AnimationObjectPtr mLastAnimObj;
		AnimationPtr mCurAnim;

		// items
	public:
		bool AddItem (Item *item);
		bool HasItem (Item *item);
		int GetNumItems () const;
		Item *GetItemByID (int id);
		Item *GetItem (int index);
		bool RemoveItem (Item *item);
		void RemoveAllItems ();

		bool EquipItem (Item *item);
		int GetNumItemsEquipped ();
		Item *GetEquippedItem (int index);
		bool UnEquipItem (Item *item);
		void UnEquipAllItems ();

		// skills buffs
	public:
		bool AddSkill (Skill *skill);
		bool HasSkill (Skill *skill);
		int GetNumSkills () const;
		Skill *GetSkillByID (int id);
		Skill *GetSkillByTypeID (int typeID);
		Skill *GetSkillByName (const std::string &name);
		Skill *GetDefSkill ();
		Skill *GetSkill (int i);
		bool RemoveSkill (Skill *skill);
		void RemoveAllSkills ();
		bool IsAnySkillHasInstance ();
		bool IsAllSkillCallOver ();
		void ResetAllSkillsCD ();

		// 0 不需要，1需要，2忽视
		std::list<Skill *> GetValidSkills (
			const Character *target, bool useTrigerDis, int positive, int needTarget, int cdOK);

		// buffs
		void AddBufClassExcept (const std::string &name, const std::string &except);
		void RemoveBufClassExcept (const std::string &name);
		void RemoveAllBufClassExcepts ();
		bool HasBufClassExcept (const std::string &except);

		bool AddBuf (Buf *buf);
		bool HasBuf (Buf *buf);
		bool HasBuf (const std::string &name);
		bool HasBufClass (const std::string &classStr);
		bool HasBufClass (Buf *buf);
		Buf *GetBufByClass (const std::string &className);
		int GetNumBufsOfClass (const std::string &className);
		void RemoveBufsOfClass (const std::string &className);
		int GetNumBufs () const;
		Buf *GetBufs (int i);
		bool RemoveBuf (Buf *buf);
		void RemoveAllBufs ();

	protected:
		std::vector<ItemPtr> mItems;
		std::vector<ItemPtr> mEquippedItems;
		std::vector<SkillPtr> mSkills;
		SkillPtr mDefSkill;
		std::map<std::string, std::string> mBufClassExcepts;
		std::vector<BufPtr> mBufs;

		// ai attack
	public:
		virtual void Freeze (bool enable);
		bool IsFreezed () const;

		void SetWatchDistance (float dist);
		float GetWatchDistance () const;

		void SetCanBeAimed (bool can);
		bool IsCanBeAimed () const;
		virtual void SetAimTarget (int targetID);
		int GetAimTarget () const;
		Character *GetAimTargetCharacter () const;
		Character *GetAimTargetCharacterAlive () const;
		int GetNumAimingMe () const;

		void BeAffect (AffectObject *ao);
		virtual void OnBeAffect (AffectObject *ao);
		virtual void OnSucAffect (AffectObject *ao);

		void SetCurAffectMeObject (AffectObject *ao);
		AffectObject *GetCurAffectMeObject () const;
		void SetCurSucAffectObject (AffectObject *ao);
		AffectObject *GetCurSucAffectObject ();
		
		void SetScriptHandler_OnBeAffect (const std::string &handler);
		const std::string &GetScriptHandler_OnBeAffect () const;
		void AddScriptHandler_OnBeAffect (const std::string &name, const std::string &handler);
		void RemoveScriptHandler_OnBeAffect (const std::string &name);

		void SetScriptHandler_OnSucAffect (const std::string &handler);
		const std::string &GetScriptHandler_OnSucAffect () const;
		void AddScriptHandler_OnSucAffect (const std::string &name, const std::string &handler);
		void RemoveScriptHandler_OnSucAffect (const std::string &name);

		void SetScriptHandler_OnSucAffectParam (const std::string &name, float param);
		float GetScriptHandler_OnSucAffectParam (const std::string &name);

	protected:
		void AddNumAimingMe ();
		void MinusNumAimingMe ();

		float mWatchDistance;
		bool mIsCanAimed;
		int mAimTargetID;
		int mNumAimingMe;
		bool mIsFreezed;

		std::string mScriptHandler_OnBeAffect;
		std::map<std::string, std::string> mScriptHandlers_OnBeAffect;

		std::string mScriptHandler_OnSucAffect;
		std::map<std::string, std::string> mScriptHandlers_OnSucAffect;
		std::map<std::string, float> mScriptHandlers_OnSucAffectParams;

		std::string mScriptHandler_OnDie;
		std::map<std::string, std::string> mScriptHandlers_OnDie;

		AffectObject *mCurAffectMeObject;
		AffectObject *mCurSucAffectObject;

		// state machine
	public:
		void CreateStateMachines ();

		StateMachine<Character> *GetActionSM () const;
		StateMachine<Character> *GetMovementSM () const;
		StateMachine<Character> *GetPostureSM () const;

	protected:
		Pointer0<StateMachine<Character> > mActionSM;
		Pointer0<StateMachine<Character> > mMovementSM;
		Pointer0<StateMachine<Character> > mPostureSM;
	};

#include "PX2Character.inl"
	PX2_REGISTER_STREAM(Character);
	typedef Pointer0<Character> CharacterPtr;

}

#endif