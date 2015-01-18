// PX2UIMenuItem.cpp

#include "PX2EditMenuItem.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, UIMenuItem, EditMenuItem);
PX2_IMPLEMENT_STREAM(EditMenuItem);
PX2_IMPLEMENT_FACTORY(EditMenuItem);
PX2_IMPLEMENT_DEFAULT_NAMES(UIMenuItem, EditMenuItem)

//----------------------------------------------------------------------------
EditMenuItem::EditMenuItem(const std::string &name, const std::string &text) :
UIMenuItem(name, text)
{
}
//----------------------------------------------------------------------------
EditMenuItem::~EditMenuItem()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EditMenuItem::EditMenuItem(LoadConstructor value)
:
UIMenuItem(value)
{
}
//----------------------------------------------------------------------------
void EditMenuItem::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	UIMenuItem::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(EditMenuItem, source);
}
//----------------------------------------------------------------------------
void EditMenuItem::Link(InStream& source)
{
	UIMenuItem::Link(source);
}
//----------------------------------------------------------------------------
void EditMenuItem::PostLink()
{
	UIMenuItem::PostLink();
}
//----------------------------------------------------------------------------
bool EditMenuItem::Register(OutStream& target) const
{
	return UIMenuItem::Register(target);
}
//----------------------------------------------------------------------------
void EditMenuItem::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	UIMenuItem::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(EditMenuItem, target);
}
//----------------------------------------------------------------------------
int EditMenuItem::GetStreamingSize(Stream &stream) const
{
	int size = UIMenuItem::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------