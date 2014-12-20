/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIBagFrame.hpp
*
*/

#ifndef PX2UIBAGFRAME_HPP
#define PX2UIBAGFRAME_HPP

#include "PX2UIPushFrame.hpp"
#include "PX2Size.hpp"
#include "PX2Float2.hpp"

namespace PX2
{

	class UIBagFrame : public UIPushFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UIBagFrame);

	public:
		UIBagFrame ();
		~UIBagFrame ();

		// size
		void SetSize (float width, float height);
		void SetSize (const Sizef &size);
		float GetWidth () const;
		float GetHeight () const;
		const Sizef &GetSize () const;

		void SetCornorSize (float width, float height);
		void SetCornorSize (const Sizef &size);
		float GetCornorWidth () const;
		float GetCornorHeight () const;
		const Sizef &GetCornorSize () const;

		// element
		enum AlignItemType
		{
			ATT_SIZE_WIDTH,
			ATT_SIZE_HEIGHT,
			ATT_NUM_WIDTH,
			ATT_NUM_HEIGHT,
			AT_MAX_TYPE
		};
		void SetAlignItemType (AlignItemType type);
		AlignItemType GetAlignItemType () const;

		void SetAlignItemSize (float width, float height);
		void SetAlignItemSize (const Sizef &size);
		float GetAlignItemWidth () const;
		float GetAlignItemHeight () const;
		const Sizef &GetAlignItemSize () const;

		void SetAlignItemNum (float numWidth, float numHeight);
		void SetAlignItemNum (const Float2 &itemNum);
		float GetAlignItemNumWidth () const;
		float GetAlignItemNumHeight () const;
		const Float2 &GetAlignItemNum () const;

		// scroll bar
		void SetScrollBack (UIPicBox *scrollBack);
		UIPicBox *GetScrollBack ();
		void SetScrollFront (UIPicBox *scrolFront);
		UIPicBox *GetScrollFront ();
		void SetScrollXDetail (float xDetail);
		float GetScrollXDetail () const;

		// add obj
		virtual int AttachChild (Movable* child);

	protected:
		virtual void UpdateWorldData (double applicationTime);
		int UpdateAlignItems ();

		bool mIsBagFrameNeedUpdate;
		AlignItemType mAlignItemType;
		Sizef mSize;
		Sizef mCornorSize;
		Sizef mItemSize;
		Float2 mAlignItemNum;
		float mContentLength;
		float mNeedMoveLength;
		
		UIPicBox *mScrollBack;
		UIPicBox *mScrollFront;
		float mXDetail;
	};

	PX2_REGISTER_STREAM(UIBagFrame);
	typedef Pointer0<UIBagFrame> UIBagFramePtr;
#include "PX2UIBagFrame.inl"

}

#endif