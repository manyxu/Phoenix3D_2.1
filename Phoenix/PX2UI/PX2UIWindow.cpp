// PX2UIWindow.cpp

#include "PX2UIWindow.hpp"

#if defined(PX2_PLATFORM_WINDOWS)
#include "PX2UIWindowImpl_Win.hpp"
#endif

using namespace PX2;

//----------------------------------------------------------------------------
UIWindow::UIWindow()
{
	mImpl = new0 UIWindowImpl_Win(this);
}
//----------------------------------------------------------------------------
UIWindow::~UIWindow()
{
}
//----------------------------------------------------------------------------
void UIWindow::SetClassStyle(UIClassType stype)
{
	mImpl->SetClassStyle(stype);
}
//----------------------------------------------------------------------------
UIClassType UIWindow::GetClassStype() const
{
	return mImpl->GetClassStype();
}
//----------------------------------------------------------------------------
void UIWindow::SetClassName(const std::string &className)
{
	mImpl->SetClassName(className);
}
//----------------------------------------------------------------------------
const std::string &UIWindow::GetClassName() const
{
	return mImpl->GetClassName();
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
void UIWindow::Close()
{
	mImpl->Close();
}
//----------------------------------------------------------------------------
void UIWindow::ShowWindow(bool sho, bool takeFocus)
{
	mImpl->ShowWindow(sho, takeFocus);
}
//----------------------------------------------------------------------------
bool UIWindow::ShowModal()
{
	return mImpl->ShowModal();
}
//----------------------------------------------------------------------------
void UIWindow::CenterWindow()
{
	mImpl->CenterWindow();
}
//----------------------------------------------------------------------------
void UIWindow::SetIcon(unsigned int res)
{
	mImpl->SetIcon(res);
}
//----------------------------------------------------------------------------