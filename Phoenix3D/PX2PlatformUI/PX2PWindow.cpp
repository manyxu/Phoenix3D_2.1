// PX2PWindow.cpp

#include "PX2PWindow.hpp"
#if defined(_WIN32) || defined(WIN32)
#include "PX2PWinImplWindows.hpp"
#endif
using namespace PX2;

//----------------------------------------------------------------------------
PWindow::PWindow()
{
#if defined(_WIN32) || defined(WIN32)
	mImpl = new0 PWinImplWindows();
#endif
}
//----------------------------------------------------------------------------
PWindow::~PWindow()
{

}
//----------------------------------------------------------------------------
void PWindow::Create(PWindow *parent, const std::string &tilte,
	const Vector2f &pos, const Sizef &size)
{
	PWinImpl *winImpl = 0;
	if (parent) winImpl = parent->mImpl;

	mImpl->Create(winImpl, tilte, pos, size);
}
//----------------------------------------------------------------------------
void *PWindow::GetWinHandle()
{
	return mImpl->GetWinHandle();
}
//----------------------------------------------------------------------------
void PWindow::Show(bool show, bool takeFocus)
{
	mImpl->Show(show, takeFocus);
}
//----------------------------------------------------------------------------
void PWindow::ShowModal()
{
	mImpl->ShowModal();
}
//----------------------------------------------------------------------------
void PWindow::CenterWindow()
{
	mImpl->CenterWindow();
}
//----------------------------------------------------------------------------
void PWindow::Minimize()
{
	mImpl->Minimize();
}
//----------------------------------------------------------------------------
void PWindow::Maximize()
{
	mImpl->Maximize();
}
//----------------------------------------------------------------------------
void PWindow::Restore()
{
	mImpl->Restore();
}
//----------------------------------------------------------------------------