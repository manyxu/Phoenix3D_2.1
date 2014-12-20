/*
*
* 文件名称	：	PX2EntityModule.cpp
*
*/

#include "PX2EntityModule.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, EntityModule);
PX2_IMPLEMENT_STREAM(EntityModule);
PX2_IMPLEMENT_ABSTRACT_FACTORY(EntityModule);
PX2_IMPLEMENT_DEFAULT_NAMES(Object, EntityModule);
//----------------------------------------------------------------------------
EntityModule::EntityModule()
{
}
//----------------------------------------------------------------------------
EntityModule::~EntityModule ()
{
}
//----------------------------------------------------------------------------
void EntityModule::Update (float appTime, float elapsedTime)
{
	PX2_UNUSED(appTime);
	PX2_UNUSED(elapsedTime);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EntityModule::EntityModule (LoadConstructor value)
	:
Object(value)
{
}
//----------------------------------------------------------------------------
void EntityModule::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);

	PX2_END_DEBUG_STREAM_LOAD(EntityModule, source);
}
//----------------------------------------------------------------------------
void EntityModule::Link (InStream& source)
{
	Object::Link(source);
}
//----------------------------------------------------------------------------
void EntityModule::PostLink ()
{
	Object::PostLink();
}
//----------------------------------------------------------------------------
bool EntityModule::Register (OutStream& target) const
{
	if (Object::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void EntityModule::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);

	PX2_END_DEBUG_STREAM_SAVE(EntityModule, target);
}
//----------------------------------------------------------------------------
int EntityModule::GetStreamingSize (Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	return size;
}
//----------------------------------------------------------------------------