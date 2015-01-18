// PX2UICallback.hpp

#ifndef PX2UICALLBACK_HPP
#define PX2UICALLBACK_HPP

#include "PX2UIPre.hpp"

namespace PX2
{

	class UIFrame;

	enum UICallType
	{
		UICT_NONE = 0,
		UICT_PRESSED,
		UICT_RELEASED,
		UICT_RELEASED_NOTVALIED,
		UICT_PROGRESSCHANGED,
		UICT_EDITBOX_ATTACHWITHIME,
		UICT_EDITBOX_DETACHWITHIME,
		UICT_EDITBOX_TEXTCHANGED,
		UICT_EDITBOX_ENTER,
		UICT_CHECKED,
		UICT_DISCHECKED,
		UICT_MAX_TYPE
	};

	typedef void(*UICallback) (UIFrame *frame, UICallType type);
	typedef void(*NotPickedCallback) (int info);

}

#endif