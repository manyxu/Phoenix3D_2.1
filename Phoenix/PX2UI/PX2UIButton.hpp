// PX2UIButton.hpp

#ifndef PX2UIBUTTON_HPP
#define PX2UIBUTTON_HPP

#include "PX2UIControl.hpp"
#include "PX2Size.hpp"
#include "PX2Rect.hpp"

namespace PX2
{

	class UIButton : public UIControl
	{
	public:
		UIButton();
		virtual ~UIButton();

		LPCTSTR GetClass() const;
		UINT GetControlFlags() const;

		bool Activate();

		void SetText(LPCTSTR pstrText);

		void SetWidth(int cxWidth);
		void SetPadding(int cx, int cy);

		SIZE EstimateSize(SIZE szAvailable);
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

		virtual void DoPaint(HDC hDC, const Rectf &rect);

	protected:
		std::string mText;
		int m_cxWidth;
		Sizef mSizePadding;
		uint32_t mTextStyle;
		uint32_t mButtonState;
	};

}

#endif