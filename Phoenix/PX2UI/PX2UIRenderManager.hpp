// PX2UIRenderManager.hpp

#ifndef PX2UIRENDERMANAGER_HPP
#define PX2UIRENDERMANAGER_HPP

#include "PX2Singleton.hpp"
#include "PX2UIDefine.hpp"
#include "PX2Rect.hpp"

namespace PX2
{

	class UIRenderer;
	class UIPaintManager;

	class UIRenderManager : public Singleton<UIRenderManager>
	{
	public:
		UIRenderManager();
		virtual ~UIRenderManager();

		virtual void DoFillRect(UIRenderer *uiRenderer, UIPaintManager *pMan,
			const Rectf &rc, UITYPE_COLOR color) = 0;

		virtual void DoPaintFrame(UIRenderer *uiRenderer, UIPaintManager *pMan,
			const Rectf &rc, UITYPE_COLOR colorLight, UITYPE_COLOR colorDark,
			UITYPE_COLOR colorBackground = UICOLOR__INVALID, uint32_t uStyle = 0) = 0;

		virtual void DoPaintButton(UIRenderer *uiRenderer, UIPaintManager *pMan,
			const Rectf &rc, const std::string &text, const Rectf &rcPadding,
			uint32_t uState, uint32_t drawStyle) = 0;

		virtual void DoPaintPrettyText(UIRenderer *uiRenderer, UIPaintManager *pMan,
			const Rectf& rc, const std::string &text, UITYPE_COLOR iTextColor,
			UITYPE_COLOR backColor, const Rectf *links, int &numLinkRects,
			uint32_t style) = 0;
	};

}

#endif