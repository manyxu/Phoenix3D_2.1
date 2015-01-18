// PX2EditTabWindow.cpp

#include "PX2EditTabWindow.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UIWindowFrame, EditTabWindow);
PX2_IMPLEMENT_STREAM(EditTabWindow);
PX2_IMPLEMENT_FACTORY(EditTabWindow);

//----------------------------------------------------------------------------
EditTabWindow::EditTabWindow()
{

}
//----------------------------------------------------------------------------
EditTabWindow::~EditTabWindow()
{

}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EditTabWindow::EditTabWindow(LoadConstructor value) :
UIWindowFrame(value)
{
}
//----------------------------------------------------------------------------
void EditTabWindow::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIWindowFrame::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(EditTabWindow, source);
}
//----------------------------------------------------------------------------
void EditTabWindow::Link(InStream& source)
{
	UIWindowFrame::Link(source);
}
//----------------------------------------------------------------------------
void EditTabWindow::PostLink()
{
	UIWindowFrame::PostLink();
}
//----------------------------------------------------------------------------
bool EditTabWindow::Register(OutStream& target) const
{
	return UIWindowFrame::Register(target);
}
//----------------------------------------------------------------------------
void EditTabWindow::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIWindowFrame::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(EditTabWindow, target);
}
//----------------------------------------------------------------------------
int EditTabWindow::GetStreamingSize(Stream &stream) const
{
	int size = UIWindowFrame::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------