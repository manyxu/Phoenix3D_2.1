// PX2UIWindow.cpp

#include "PX2UIWindow.hpp"

#if defined(PX2_PLATFORM_WINDOWS)
#include "PX2UIWindowImpl_Win.hpp"
#endif

using namespace PX2;

//----------------------------------------------------------------------------
UIWindow::UIWindow()
{
	mImpl = new0 UIWindowImpl_Win();
}
//----------------------------------------------------------------------------
UIWindow::~UIWindow()
{
}
//----------------------------------------------------------------------------
void UIWindow::Create(UIWindow *parent, const std::string &name,
	UIWindowStyle style, const Rectf &rect)
{
	UIWindowImpl *impl = 0;
	if (parent)
		impl = parent->GetImpl();

	mImpl->Create(impl, name, style, rect);
}
//----------------------------------------------------------------------------
void UIWindow::UnSubclass()
{
}
//----------------------------------------------------------------------------
void UIWindow::ShowWindow(bool sho, bool takeFocus)
{

}
//----------------------------------------------------------------------------
bool UIWindow::ShowModal()
{
	return mImpl->ShowModal();
}
//----------------------------------------------------------------------------
void UIWindow::Close()
{

}
//----------------------------------------------------------------------------
void UIWindow::CenterWindow()
{

}
//----------------------------------------------------------------------------
void UIWindow::SetIcon(unsigned int res)
{

}
//----------------------------------------------------------------------------