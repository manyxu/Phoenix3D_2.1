// PX2UITitleFrame.hpp

#ifndef PX2UITITLEFRAME_HPP
#define PX2UITITLEFRAME_HPP

#include "PX2UISizeFrame.hpp"
#include "PX2Size.hpp"
#include "PX2UIPicBox.hpp"

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

	protected:
		UIPicBoxPtr mPB_Back;
	};

	PX2_REGISTER_STREAM(UITitleFrame);
	typedef Pointer0<UITitleFrame> UICaptionFramePtr;

}

#endif