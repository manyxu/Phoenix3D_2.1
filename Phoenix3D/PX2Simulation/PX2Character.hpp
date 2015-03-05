// PX2Character.hpp

#ifndef PX2CHARACTER_HPP
#define PX2CHARACTER_HPP

#include "PX2Actor.hpp"
#include "PX2Animation.hpp"
#include "PX2BlendTransformController.hpp"
#include "PX2AnimationObject.hpp"
#include "PX2FString.hpp"
#include "PX2PropModify.hpp"

namespace PX2
{

	class Character : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(Character);

	public:
		Character();
		virtual ~Character();

	protected:
		virtual void UpdateWorldData(double applicationTime, double elapsedTime);
		void _AnimationBlend();

		// Movable
	public:
		virtual void SetMovableFilename(const std::string &filename,
			bool shareVI = false);

		void SetUseAutoWorldBound(bool isUseAutoWorldBound);
		bool IsUseAutoWorldBound() const;
		void SetAutoWorldBoundRadius(float radius);
		float GetAutoWorldBoundRadius() const;

	private:
		bool mIsAutoWorldBound;
		float mAutoWorldBoundRadius;

	protected:
		void _CalSkins();
		void _CalAnimNode(Movable *mov);

		// anim
	public:
		bool AddAnim(Animation *anim);
		bool HasAnim(Animation *anim);
		bool HasAnim(int id);
		bool RemoveAnim(Animation *anim);
		bool RemoveAnim(int id);
		void RemoveAllAnims();
		int GetNumAnims() const;
		std::map<int, AnimationPtr> &GetAnimsMap();
		Animation *GetAnimByID(int id);

		void SetDefaultAnimID(int id);
		int GetDefaultAnimID() const;
		Animation *GetDefaultAnim();

		virtual void PlayAnim(Animation *anim);
		virtual void PlayAnimByID(int id);
		virtual void StopAnim(Animation *anim);
		virtual void StopCurAnim();
		virtual void PlayCurAnim();

		Animation *GetCurPlayingAnim();
		bool IsHasAnimPlaying() const;

	protected:
		std::map<int, AnimationPtr> mAnimsMap;
		AnimationPtr mCurPlayingAnim;
		int mDefaultAnimID;
		AnimationPtr mDefaultAnim;

		std::vector<MovablePtr> mSkinMovables;
		MovablePtr mModelAnimMovable;
		std::map<FString, BlendTransformController*> mBTCMap;
		AnimationObjectPtr mLastAnimObj;

		// hp ap
	public:
		// hp
		virtual void SetBaseHPCurLevel(float hp);
		float GetBaseHPCurLevel() const;

		PX2_DECLARE_PM_F(HP);
	public:
		float GetHPPercent() const;

		virtual void SetDead(bool dead);
		virtual void Die();
		bool IsDead() const;

		void SetDieDoDelete(bool isDieDoDelete);
		bool IsDieDoDelete() const;

		// ap
		virtual void SetBaseAPCurLevel(float ap);
		float GetBaseAPCurLevel() const;

		PX2_DECLARE_PM_F(AP);

	protected:
		float mBaseHPCurLevel;
		bool mIsDieDoDelete;

		float mBaseAPCurLevel;

		bool mIsDead;
	};

#include "PX2Character.inl"
	PX2_REGISTER_STREAM(Character);
	typedef Pointer0<Character> CharacterPtr;

}

#endif