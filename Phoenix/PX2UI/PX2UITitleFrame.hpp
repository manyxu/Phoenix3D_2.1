// PX2UITitleFrame.hpp

#ifndef PX2UITITLEFRAME_HPP
#define PX2UITITLEFRAME_HPP

#include "PX2UISizeFrame.hpp"
#include "PX2Size.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIText.hpp"
#include "PX2UIButton.hpp"

namespace PX2
{

	class UITitleFrame : public UISizeFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(UITitleFrame);

	public:
		UITitleFrame();
		virtual ~UITitleFrame();

		virtual void OnParentSizeChanged(const Sizef &parentSize,
			const Sizef &parentBorderSize);

		UIPicBox *GetIcon();
		UIText *GetText();
		UIButton *GetMinButton();
		UIButton *GetMaxButton();
		UIButton *GetCloseButton();

	protected:
		UIPicBoxPtr mPB_Back;
		UIButtonPtr mB_Table;
		UIPicBoxPtr mPB_Icon;
		UITextPtr mT_Title;
		UIButtonPtr mB_Min;
		UIButtonPtr mB_Max;
		UIButtonPtr mB_Close;
	};

#include "PX2UITitleFrame.inl"
	PX2_REGISTER_STREAM(UITitleFrame);
	typedef Pointer0<UITitleFrame> UITitleFramePtr;

}

#endif