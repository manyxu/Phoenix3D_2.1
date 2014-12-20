/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Actor.hpp
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

		PX2_DECLARE_PM_F(MaxSpeed);
	public:
		float GetPercentSpeedOverModified ();

		void AddStopSpeedTag (const std::string &tag);
		void RemoveStopSpeedTag (const std::string &tag);
		bool IsHasStopSpeedTag (const std::string &tag) const;
		const std::vector<std::string> GetStopSpeedTags () const;
		virtual void StopSpeed (bool stopSpeed);
		bool IsStopSpeed () const;

		virtual void SetVelocity (const AVector &vec);
		const AVector &GetVelocity () const;
		float GetSpeed () const;
		virtual void SetHeading (const AVector &heading);
		const AVector &GetHeading () const;
		virtual void OnUpdateGoToPosition (const APoint &toPos);

		virtual void SetSmoothHeading (const AVector &soomthHeading);
		const AVector &GetSmoothHeading () const;

	protected:
		APoint mScale;
		APoint mRotation;
		APoint mPosition;

		std::vector<std::string> mStopSpeedTags;
		bool mIsStopSpeed;
		AVector mVelocity;
		AVector mHeading;

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
		void SetGridMoveOn (bool on);
		bool IsGridMoveOn () const;
		GridMoveBehavior *GetGridMoveBehavior ();

		void SetArriveRange (float dis);
		float GetArriveRange () const;

		void SetMass (float mass);
		float GetMass () const;

	protected:
		bool mIsGridMoveOn;
		Pointer0<GridMoveBehavior> mGridMoveBehavior;
		float mArriveRange;
		float mMass;

		bool mIsSmoothOn;
		AVector mSmoothHeading;
		Smoother<AVector> *mHeadingSmoother;

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

		// SaveLoad
	public:
		virtual void SaveToXMLNode (XMLNode nodeParent);
		virtual void LoadFromXMLNode (XMLNode node);
	};

	PX2_REGISTER_STREAM(Actor);
	typedef Pointer0<Actor> ActorPtr;
#include "PX2Actor.inl"
	
}

#endif