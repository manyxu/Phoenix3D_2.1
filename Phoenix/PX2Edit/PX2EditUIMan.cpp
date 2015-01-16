// PX2EditUIMan.hpp

#include "PX2EditUIMan.hpp"
#include "PX2UIManager.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIWindowFrame.hpp"
using namespace PX2;

EditUIMan::EditUIMan()
{
	UIView *defaultUIView = PX2_UIM.GetDefaultUIView();

	UIWindowFrame *mainFrame = new0 UIWindowFrame();
	defaultUIView->GetNode()->AttachChild(mainFrame);
	_CreateMainFrame(mainFrame);
}
//----------------------------------------------------------------------------
EditUIMan::~EditUIMan()
{
}
//----------------------------------------------------------------------------
void EditUIMan::_CreateMainFrame(UIFrame *parent)
{
}
//----------------------------------------------------------------------------