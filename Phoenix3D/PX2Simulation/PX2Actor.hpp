// PX2Actor.hpp

#ifndef PX2ACTOR_HPP
#define PX2ACTOR_HPP

#include "PX2SimulationPre.hpp"
#include "PX2SimulationDataDefine.hpp"
#include "PX2Node.hpp"

namespace PX2
{

	class Actor : public Node
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Actor);

	public:
		Actor();
		~Actor();

	protected:
		virtual void UpdateWorldData(double applicationTime, double elapsedTime);

		// BitSet
	public:
		virtual void SetTypeID(int typeID);
		int GetTypeID() const;

		virtual void SetGroup(int group);
		int GetGroup() const;

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
		std::bitset<PX2_ACTOR_BS_SIZE> &GetBitSet();
		const std::bitset<PX2_ACTOR_BS_SIZE> &GetBitSet() const;
		bool IsContainAllBits(const std::bitset<PX2_ACTOR_BS_SIZE> &bits) const;

	protected:
		int mTypeID;
		int mGroup;

		std::bitset<PX2_ACTOR_BS_SIZE> mBitSet;

		// Movable
	public:
		virtual void SetMovableFilename(const std::string &filename,
			bool shareVI = true);
		const std::string &GetMovableFilename() const;
		bool IsShareVI() const;

		virtual void SetMovable (Movable *mov);
		Movable *GetMovable ();

		Node *CreateGetHelpNode ();
		Node *GetNodeHelp();

		void SetPickable(bool isPickable);
		bool IsPickable() const;

		void SetFace(const AVector &dir, const AVector &uping = AVector::UNIT_Z);
		AVector GetFace();
		void GetRDUVector(AVector &r, AVector &d, AVector &u);

		virtual void SetHeading(const AVector &heading);
		const AVector &GetHeading() const;

	protected:
		bool mIsShareVI;
		std::string mMovableFilename;
		MovablePtr mMovable;
		
		NodePtr mHelpNode;

		bool mIsPickable;

		AVector mHeading;

		// Anchor
	public:
		void CollectAnchors();

		APoint GetAnchorPos(int id);
		Node *GetAnchor(int id);

	protected:
		void _CollectAnchor(Movable *mov);

		std::map<int, Node*> mAnchorMap;

		// Params
	public:
		virtual void SetRadius(float radius);
		float GetRadius() const;

		virtual void SetHegiht(float height);
		float GetHeight() const;

	protected:
		float mRadius;
		float mHeight;

		// scene manager
	public:
		void *GetSceneContainer() const;
		int GetSceneContainerIndex() const;

	public_internal:
		void SetSceneContainer(void *container);
		void SetSceneContainerIndex(int index);

	protected:
		void *mSceneContainer;
		int mSceneContainerIndex;
	};

#include "PX2Actor.inl"
	PX2_REGISTER_STREAM(Actor);
	typedef Pointer0<Actor> ActorPtr;

}

#endif