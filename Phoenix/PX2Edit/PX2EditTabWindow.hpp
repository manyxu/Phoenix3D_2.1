// PX2EditTabWindow.hpp

#ifndef PX2EDITTABWINDOW_HPP
#define PX2EDITTABWINDOW_HPP

#include "PX2UIWindowFrame.hpp"

namespace PX2
{

	class EditTabWindow : public UIWindowFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(EditTabWindow);

	public:
		EditTabWindow();
		virtual ~EditTabWindow();

	protected:
	};
	PX2_REGISTER_STREAM(EditTabWindow);
	typedef Pointer0<EditTabWindow> EditTabWindowPtr;

}

#endif