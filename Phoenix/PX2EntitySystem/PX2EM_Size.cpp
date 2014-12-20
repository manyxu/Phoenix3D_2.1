/*
*
* 文件名称	：	PX2EM_Size.cpp
*
*/

#include "PX2EM_Size.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, EntityModule, EN_Size);
PX2_IMPLEMENT_STREAM(EN_Size);
PX2_IMPLEMENT_FACTORY(EN_Size);
PX2_IMPLEMENT_DEFAULT_NAMES(EntityModule, EN_Size);

//----------------------------------------------------------------------------
EN_Size::EN_Size ()
	:
mLength(1.0f),
mWidth(1.0f),
mHeight(1.0f),
mRadius(1.0f)
{
}
//----------------------------------------------------------------------------
EN_Size::~EN_Size()
{
}
//----------------------------------------------------------------------------
void EN_Size::SetLength (float val)
{
	mLength = val;

	for (std::list<Vistor*>::iterator it=mVistors.begin(); 
		it!=mVistors.end(); it++)
	{
		(*it)->Visit(this, T_LENGTH);
	}
}
//----------------------------------------------------------------------------
void EN_Size::SetWidth (float val)
{
	mWidth = val;

	for (std::list<Vistor*>::iterator it=mVistors.begin(); 
		it!=mVistors.end(); it++)
	{
		(*it)->Visit(this, T_WIDTH);
	}
}
//----------------------------------------------------------------------------
void EN_Size::SetHeight (float val)
{
	mHeight = val;

	for (std::list<Vistor*>::iterator it=mVistors.begin(); 
		it!=mVistors.end(); it++)
	{
		(*it)->Visit(this, T_HEIGHT);
	}
}
//----------------------------------------------------------------------------
void EN_Size::SetRadius (float radius)
{
	mRadius = radius;

	for (std::list<Vistor*>::iterator it=mVistors.begin(); 
		it!=mVistors.end(); it++)
	{
		(*it)->Visit(this, T_RADIUS);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EN_Size::EN_Size (LoadConstructor value)
	:
EntityModule(value),
mLength(1.0f),
mWidth(1.0f),
mHeight(1.0f),
mRadius(1.0f)
{
}
//----------------------------------------------------------------------------
void EN_Size::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	EntityModule::Load(source);

	source.Read(mLength);
	source.Read(mWidth);
	source.Read(mHeight);
	source.Read(mRadius);

	PX2_END_DEBUG_STREAM_LOAD(EN_Size, source);
}
//----------------------------------------------------------------------------
void EN_Size::Link (InStream& source)
{
	EntityModule::Link(source);
}
//----------------------------------------------------------------------------
void EN_Size::PostLink ()
{
	EntityModule::PostLink();
}
//----------------------------------------------------------------------------
bool EN_Size::Register (OutStream& target) const
{
	if (EntityModule::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void EN_Size::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	EntityModule::Save(target);

	target.Write(mLength);
	target.Write(mWidth);
	target.Write(mHeight);
	target.Write(mRadius);

	PX2_END_DEBUG_STREAM_SAVE(EN_Size, target);
}
//----------------------------------------------------------------------------
int EN_Size::GetStreamingSize (Stream &stream) const
{
	int size = EntityModule::GetStreamingSize(stream);
	size += sizeof(mLength);
	size += sizeof(mWidth);
	size += sizeof(mHeight);
	size += sizeof(mRadius);
	return size;
}
//----------------------------------------------------------------------------