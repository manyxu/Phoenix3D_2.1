/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Character2DFrames8.hpp
*
*/

#ifndef PX2CHARACTER2DFRAMES8_HPP
#define PX2CHARACTER2DFRAMES8_HPP

#include "PX2Character.hpp"
#include "PX2Billboard.hpp"
#include "PX2UIProgressBar.hpp"

namespace PX2
{

	class Character2DFrames8 : public Character
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Character2DFrames8);

	public:
		Character2DFrames8 ();
		~Character2DFrames8 ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		Node *GetActorNode ();
		Node *GetAnimNode ();

		void ShowSelfRadiusRange (bool show);
		bool IsShowSelfRadiusRange () const;

		void ShowHeadingDir (bool show);
		bool IsShowHeadingDir () const;

		virtual void SetSelfRadius (float radius);
		virtual void SetHeight (float height);

		void SetOffset (const APoint &off);
		const APoint &GetOffset () const;

		void SetAnimSize (float size);
		float GetAnimSize () const;

		void SetShadowFilename (const std::string &filename);
		const std::string &GetShadowFilename () const;
		void SetShadowSize (float size);
		float GetShadowSize ();
		Node *GetShadowNode ();

		void RemoveInfoNode ();
		Node *GetInfoNode ();

		void SetRolateNodeOffset (const APoint &off);
		const APoint &GetRolateNodeOffset () const;

		void SetAttackFrontNodeOffset (const APoint &off);
		const APoint &GetAttackFrontNodeOffset () const;

		virtual void SetHeading (const AVector &heading);

		virtual void Die ();

	protected:
		NodePtr mActorNode;

			NodePtr mOffsetNode;
			APoint mOffset;
				NodePtr mAnimObject;
				float mAnimSize;

				NodePtr mRolateNode;
				APoint mRolateNodeOffset;
					APoint mAttackFrontOffset;
					NodePtr mAttackFrontNode;

				NodePtr mFootNode;
				NodePtr mFootUpNode;
				NodePtr mCenterNode;
				NodePtr mHeadNode;
		
		NodePtr mShadowNode;
		std::string mShadowFilename;
		BillboardPtr mShadowBillboard;
		float mShadowSize;

		NodePtr mInfoNode;
		BillboardPtr mHeadingBillboard;
		bool mIsShowHeadingDir;
		BillboardPtr mSelfRadiusBillboard;
		bool mIsShowSelfRadiusRange;

		NodePtr mFrontNode;
	};

#include "PX2Character2DFrames8.inl"

	PX2_REGISTER_STREAM(Character2DFrames8);
	typedef Pointer0<Character2DFrames8> Character2DFrames8Ptr;

}

#endif