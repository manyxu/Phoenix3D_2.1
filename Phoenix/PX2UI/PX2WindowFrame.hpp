// PX2UIWindowFrame.hpp

#ifndef PX2UIWINDOWFRAME_HPP
#define PX2UIWINDOWFRAME_HPP

#include "PX2UISizeFrame.hpp"
#include "PX2UICaptionFrame.hpp"

namespace PX2
{

	class UIWindowFrame : public UISizeFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(UIWindowFrame);

	public:
		UIWindowFrame();
		virtual ~UIWindowFrame();

	protected:
		UICaptionFramePtr mCaptionFrame;
	};

	PX2_REGISTER_STREAM(UIWindowFrame);
	typedef Pointer0<UIWindowFrame> UIWindowFramePtr;

}

#endif