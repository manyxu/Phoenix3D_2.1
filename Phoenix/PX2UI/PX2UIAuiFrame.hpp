// PX2UIAuiFrame.hpp

#ifndef PX2UIAUIFRAME_HPP
#define PX2UIAUIFRAME_HPP

#include "PX2UISizeFrame.hpp"

namespace PX2
{

	class UIAuiFrame : public UISizeFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UIAuiFrame);

	public:
		UIAuiFrame();
		virtual ~UIAuiFrame();

		enum AuiPosType
		{
			APT_CENTER,
			APT_LEFT,
			APT_TOP,
			APT_RIGHT,
			APT_BOTTON,
			APT_MAX_TYPE
		};
		void AddFrame(AuiPosType posType, UISizeFrame *frame);

		virtual void OnParentSizeChanged(const Sizef &parentSize,
			const Sizef &parentBorderSize);

	protected:
		std::map<AuiPosType, Pointer0<UIAuiFrame> > mFrames;
	};

	typedef Pointer0<UIAuiFrame> UIAuiFramePtr;

}

#endif