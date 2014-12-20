/*
*
* 文件名称	：	PX2Actor.hpp
*
*/

#ifndef PX2ACTOR_HPP
#define PX2ACTOR_HPP

#include "PX2GamePre.hpp"
#include "PX2Netable.hpp"
#include "PX2APoint.hpp"
#include "PX2Movable.hpp"
#include "PX2GridMoveBehavior.hpp"
#include "PX2Smoother.hpp"
#include "PX2Gameable.hpp"
#include "PX2PropModify.hpp"
#include "PX2EffectNode.hpp"
#include "PX2MoveBehavior.hpp"

namespace GridMove
{
	class MoveUnit;
}

namespace PX2
{

	class Scene;

	class Actor : public Gameable
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_FUNCTION;
		PX2_DECLARE_STREAM(Actor);

	public:
		Actor ();
		virtual ~Actor ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		// ID BitSet
	public:
		void SetID (int id);
		int GetID () const;

		virtual void SetTypeID (int typeID);
		int GetTypeID () const;

		virtual void SetGroup (int group);
		int GetGroup () const;

		enum BitSetType
		{
			BST_CHARACTER = 0,
			BST_BUILDINGINGORE,
			BST_BUILDING,
			BST_CANBEAIMED,
			BST_GROUP1 = 13,
			BST_GROUP2,
			BST_MAX_TYPE
		};
		std::bitset<PX2_ACTOR_BS_SIZE> &GetBitSet ();
		const std::bitset<PX2_ACTOR_BS_SIZE> &GetBitSet () const;
		bool IsContainAllBits (const std::bitset<PX2_ACTOR_BS_SIZE> &bits) const;

	protected:
		int mID;
		int mTypeID;
		int mGroup;
		std::bitset<PX2_ACTOR_BS_SIZE> mBitSet;

		// Movable Scene
	public:
		virtual void SetMovableFilename (const std::string &filename, bool shareVIM=false);
		const std::string &GetMoveableFilename () const;
		bool IsShareVIM () const;

		virtual void SetMovable (Movable *movable);
		Movable *GetMovable () const;
		APoint GetAnchorPos (const std::string &name);
		Node *GetAnchor (const std::string &name);
		void SetVisible (bool visible);
		bool IsVisible ();
		void SetTransparent (float alpha);
		float GetTransparent ();

		void SetHelpMovable (Movable *movable);
		Movable *GetHelpMovable ();
		void ShowHelpMovable (bool show);
		bool IsHelpMovableShow ();

		PX2::Scene *GetScene () const;
		void *GetSceneContainer () const;
		int GetSceneContainerIndex () const;

		void SetPickable (bool isPickable);
		bool IsPickable () const;

		virtual void CalLights ();

public_internal:
		virtual void SetScene (Scene *scene);
		void SetSceneContainer (void *container);
		void SetSceneContainerIndex (int index);

	protected:
		bool mIsVisible;
		float mActorTransparent;

		std::string mMoveableFilename;
		bool mIsShareVIM;
		ResHandle mMoveableResHandle;

		MovablePtr mMovable;
		MovablePtr mHelpMovable;
		bool mIsShowHelpMovable;

		Scene *mScene;
		void *mSceneContainer;
		int mSceneContainerIndex;

		bool mIsPickable;

		// Actor Effects
	public:
		EffectNode *AddActorEffect (const std::string &anchor, 
			const std::string &effectName, const std::string &effectFilename);
		void RemoveActorEffect (const std::string &effectName);
		EffectNode *GetActorEffect (const std::string &effectName);

	protected:
		std::map<std::string, std::string> mActorEffects;

		// Trans Moving
	public:
		virtual void SetScale (const APoint &scale);
		virtual void SetRotation (const APoint &rolate);
		virtual void SetPosition (const APoint &position);
		const APoint &GetScale () const;
		const APoint &GetRotation () const;
		const APoint &GetPosition () const;

		void SetFace (const AVector &dir, const AVector &uping=AVector::UNIT_Z);

		PX2_DECLARE_PM_F(MaxSpeed);
	public:
		float GetPercentSpeedOverModified ();

		void AddStopSpeedTag (const std::string &tag);
		void RemoveStopSpeedTag (const std::string &tag);
		bool IsHasStopSpeedTag (const std::string &tag) const;
		const std::vector<std::string> GetStopSpeedTags () const;
		bool IsStopSpeed () const;

		virtual void SetVelocityDir (const AVector &vec);
		const AVector &GetVelocityDir () const;
		void SetHeadingAlignVelocityDir (bool isAlign);
		bool IsHeadingAlignVelocityDir () const;
		virtual void SetHeading (const AVector &heading);
		const AVector &GetHeading () const;
		virtual void OnUpdateGoToPosition (const APoint &toPos);
		virtual void OnUpdateGoToStop ();

		virtual void SetSmoothHeading (const AVector &soomthHeading); // 确保soomthHeading是单位化的
		const AVector &GetSmoothHeading () const;

	protected:
		APoint mScale;
		APoint mRotation;
		APoint mPosition;

		std::vector<std::string> mStopSpeedTags;
		bool mIsStopSpeed;
		AVector mVelocityDir;
		AVector mHeading;
		bool mIsHeadingAlignVelocityDir;

		// Touching
	public:
		virtual void OnTouchPressed (const APoint &pos);
		virtual void OnTouchReleased (const APoint &pos);

		// Props
	public:
		void SetStaticType (bool isStaticType);
		bool IsStaticType () const;
		void SetBeBuilding (bool isBuilding);
		bool IsBuilding () const;
		virtual void SetSelfRadius (float radius);
		float GetSelfRadius () const;
		virtual void SetHeight (float height);
		float GetHeight () const;

	protected:
		bool mIsStaticType;
		bool mIsBuilding;
		float mSelfRadius;
		float mHeight;

		// AI
	public:
		enum MoveBehaviorType
		{
			MBT_NONE,
			MBT_FREE,
			MBT_GRID,
			MBT_MAX_TYPE
		};
		void SetMoveBehaviorType (MoveBehaviorType type);
		MoveBehaviorType GetMoveBehaviorType () const;
		MoveBehavior *GetMoveBehavior () const;

		void GoTo (const APoint &pos);

		void SetSmoothOn (bool on);
		bool IsSmoothOn () const;

	protected:
		MoveBehaviorType mMoveBehaviorType;
		MoveBehaviorPtr mMoveBehavior;

		bool mIsSmoothOn;
		AVector mSmoothHeading;
		Smoother<AVector> *mHeadingSmoother;

		// Physics
	public:
		void SetMass (float mass);
		float GetMass () const;

	protected:
		float mMass;

		// Bake
	public:
		void SetBakeObject (bool bakeObject);
		bool IsBakeObject () const;
		void SetBakeTarget (bool bakeTarget);
		bool IsBakeTarget () const;

		void ClearBakeTextures ();
		void AddBakeTxture (const std::string &name, const std::string &bakeTexture);
		void SetUseLightTexture (bool use);
		void SetUseStdTex2DMtl ();

	protected:
		void _SetBakeObject (Movable *mov, bool bakeObject);
		void _SetBakeTarget (Movable *mov, bool bakeTarget);
		void _SetLightTextureEmpty (Movable *mov, bool use);
		void _SetUseStdTex2DMtl (Movable *mov);

		bool mIsBakeObject;
		bool mIsBakeTarget;
		std::map<std::string, std::string> mBakeTextures;
	};

	PX2_REGISTER_STREAM(Actor);
	typedef Pointer0<Actor> ActorPtr;
#include "PX2Actor.inl"
	
}

#endif