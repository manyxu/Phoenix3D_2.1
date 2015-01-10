// PX2UIControl.hpp

#ifndef PX2UICONTROL_HPP
#define PX2UICONTROL_HPP

#include "PX2UIPre.hpp"
#include "PX2Rect.hpp"

namespace PX2
{

	class UIControl
	{
	public:
		UIControl();
		virtual ~UIControl();

		virtual bool Activate();

		virtual void SetText(const std::string &text);
		const std::string &GetText() const;

		virtual void SetToolTip(const std::string &tip);
		const std::string &GetToopTip() const;

		virtual void SetFocus();
		virtual bool IsFocused() const;

		virtual void SetVisible(bool bVisible = true);
		virtual bool IsVisible() const;

		virtual void SetEnabled(bool bEnable = true);
		virtual bool IsEnabled() const;

		virtual void DoPaint (HDC hDC, const Rectf &rect) = 0;
	};

}

#endif