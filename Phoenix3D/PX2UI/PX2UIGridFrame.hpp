// PX2UIGridButton.hpp

#ifndef PX2UIGRIDBUTTON_HPP
#define PX2UIGRIDBUTTON_HPP

#include "PX2UIFrame.hpp"
#include "PX2Float2.hpp"

namespace PX2
{

	class PX2_UI_ITEM UIGridFrame : public UIFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UIGridFrame);

	public:
		UIGridFrame();
		~UIGridFrame();

		virtual void OnSizeChanged();
		virtual void OnBorderSizeChanged();

		// element
		enum AlignItemType
		{
			ATT_SIZE_WIDTH,
			ATT_SIZE_HEIGHT,
			ATT_NUM_WIDTH,
			ATT_NUM_HEIGHT,
			AT_MAX_TYPE
		};
		void SetAlignItemType(AlignItemType type);
		AlignItemType GetAlignItemType() const;

		void SetAlignItemSize(float width, float height);
		void SetAlignItemSize(const Sizef &size);
		float GetAlignItemWidth() const;
		float GetAlignItemHeight() const;
		const Sizef &GetAlignItemSize() const;

		void SetAlignItemNum(float numWidth, float numHeight);
		void SetAlignItemNum(const Float2 &itemNum);
		float GetAlignItemNumWidth() const;
		float GetAlignItemNumHeight() const;
		const Float2 &GetAlignItemNum() const;

		// add obj
		virtual int AttachChild(Movable* child);

	protected:
		virtual void UpdateWorldData(double applicationTime, double elapsedTime);
		int _UpdateAlignItems();

		AlignItemType mAlignItemType;

		Sizef mItemSize;
		Float2 mAlignItemNum;
		float mContentLength;
		float mNeedMoveLength;

		bool mIsBagFrameNeedUpdate;
	};

	PX2_REGISTER_STREAM(UIGridFrame);
	typedef Pointer0<UIGridFrame> UIGridFramePtr;

}

#endif