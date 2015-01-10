// PX2UIRenderManager_Win.hpp

#ifndef PX2UIRENDERMANAGER_WIN_HPP
#define PX2UIRENDERMANAGER_WIN_HPP

#include "PX2UIRenderManager.hpp"
#include "PX2UIPre.hpp"
#include "PX2UIRender.hpp"

namespace PX2
{

	class UIRenderManager_Win : public UIRenderManager
	{
	public:
		UIRenderManager_Win();
		virtual ~UIRenderManager_Win();

		virtual void DoFillRect(UIRenderer *uiRenderer, UIPaintManager *pMan,
			const Rectf &rc, UITYPE_COLOR color);

		virtual void DoPaintFrame(UIRenderer *uiRenderer, UIPaintManager *pMan,
			const Rectf &rc, UITYPE_COLOR colorLight, UITYPE_COLOR colorDark, 
			UITYPE_COLOR colorBackground=UICOLOR__INVALID, uint32_t uStyle=0);

		virtual void DoPaintButton(UIRenderer *uiRenderer, UIPaintManager *pMan,
			const Rectf &rc, const std::string &text, const Rectf &rcPadding,
			uint32_t uState, uint32_t drawStyle);

		virtual void DoPaintPrettyText(UIRenderer *uiRenderer, UIPaintManager *pMan,
			const Rectf& rc, const std::string &text, UITYPE_COLOR iTextColor, 
			UITYPE_COLOR backColor, const Rectf *links, int &numLinkRects, 
			uint32_t style);

	protected:
		virtual void DoPaintGradient(HDC hDC, UIPaintManager *paintMan,
			RECT rc, COLORREF clrFirst, COLORREF clrSecond, bool bVertical, int nSteps);
	};

}

#endif