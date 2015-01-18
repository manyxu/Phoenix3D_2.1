// PX2EditMenuItem.hpp

#ifndef PX2EDITMENUITEM_HPP
#define PX2EDITMENUITEM_HPP

#include "PX2UIMenuItem.hpp"

namespace PX2
{

	class EditMenuItem : public UIMenuItem
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(EditMenuItem);

	public:
		EditMenuItem(const std::string &name, const std::string &text);
		virtual ~EditMenuItem();
	};

	PX2_REGISTER_STREAM(EditMenuItem);
	typedef Pointer0<EditMenuItem> EditMenuItemPtr;

}

#endif