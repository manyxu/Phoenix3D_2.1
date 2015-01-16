// PX2EditMainWindow.hpp

#ifndef PX2EDITWINDOWFRAME_HPP
#define PX2EDITWINDOWFRAME_HPP

#include "PX2UIWindowFrame.hpp"

namespace PX2
{

	class EditMainWindow : public UIWindowFrame
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_STREAM(EditMainWindow);

	public:
		EditMainWindow();
		virtual ~EditMainWindow();

		virtual void OnParentSizeChanged(const Sizef &parentSize,
			const Sizef &parentBorderSize);

	protected:
		UIPicBoxPtr mPB_Back;
	};

	PX2_REGISTER_STREAM(EditMainWindow);
	typedef Pointer0<EditMainWindow> EditMainWindowPtr;

}

#endif