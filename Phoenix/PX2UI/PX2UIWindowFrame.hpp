// PX2UIWindowFrame.hpp

#ifndef PX2UIWINDOWFRAME_HPP
#define PX2UIWINDOWFRAME_HPP

#include "PX2UISizeFrame.hpp"
#include "PX2UITitleFrame.hpp"
#include "PX2UIPicBox.hpp"

namespace PX2
{

	class UIWindowFrame : public UISizeFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(UIWindowFrame);

	public:
		UIWindowFrame();
		virtual ~UIWindowFrame();

		void SetTitleFrame(UITitleFrame *titleFrame);

	protected:
		UITitleFramePtr mTitleFrame;
	};

	PX2_REGISTER_STREAM(UIWindowFrame);
	typedef Pointer0<UIWindowFrame> UIWindowFramePtr;

}

#endif