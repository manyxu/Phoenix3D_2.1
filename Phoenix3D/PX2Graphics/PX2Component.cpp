// PX2Component.cpp

#include "PX2Component.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, Component);
PX2_IMPLEMENT_STREAM(Component);
PX2_IMPLEMENT_FACTORY(Component);
PX2_IMPLEMENT_DEFAULT_NAMES(Object, Component);

//----------------------------------------------------------------------------
Component::Component ()
	:
mPriority(0)
{
}
//----------------------------------------------------------------------------
Component::~Component ()
{
}
//----------------------------------------------------------------------------
bool Component::Update(double applicationTime, double elapsedTime)
{
	PX2_UNUSED(applicationTime);
	PX2_UNUSED(elapsedTime);

	return false;
}
//----------------------------------------------------------------------------
void Component::OnAttach()
{
}
//----------------------------------------------------------------------------
void Component::OnDetach()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
Component::Component(LoadConstructor value)
	:
	Object(value),
	mPriority(0)
{
}
//----------------------------------------------------------------------------
void Component::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(Component, source);
}
//----------------------------------------------------------------------------
void Component::Link(InStream& source)
{
	Object::Link(source);
}
//----------------------------------------------------------------------------
void Component::PostLink()
{
	Object::PostLink();
}
//----------------------------------------------------------------------------
bool Component::Register(OutStream& target) const
{
	return Object::Register(target);
}
//----------------------------------------------------------------------------
void Component::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(Component, target);
}
//----------------------------------------------------------------------------
int Component::GetStreamingSize(Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------