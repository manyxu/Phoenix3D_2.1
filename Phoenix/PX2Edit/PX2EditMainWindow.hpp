// PX2EditMainWindow.hpp

#ifndef PX2EDITWINDOWFRAME_HPP
#define PX2EDITWINDOWFRAME_HPP

#include "PX2UIWindowFrame.hpp"
#include "PX2UIMenu.hpp"
#include "PX2UIAuiFrame.hpp"
#include "PX2EditTitleWindow.hpp"
#include "PX2EditMenuItem.hpp"
#include "PX2EditSceneTree.hpp"
#include "PX2EditSceneTreeItem.hpp"

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

		float mTitleHeight;
		EditTitleFramePtr mEditTitleFrame;

		float mMenuBarHeight;
		UIMenuBarPtr mMenuBar;

		UIAuiFramePtr mMainAuiFrame;
		
		EditSceneTreePtr mSceneTree;
	};

	PX2_REGISTER_STREAM(EditMainWindow);
	typedef Pointer0<EditMainWindow> EditMainWindowPtr;

}

#endif