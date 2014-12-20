/*
*
* 文件名称	：	PX2EM_ID.cpp
*
*/

#include "PX2EM_ID.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, EntityModule, EN_ID);
PX2_IMPLEMENT_STREAM(EN_ID);
PX2_IMPLEMENT_FACTORY(EN_ID);
PX2_IMPLEMENT_DEFAULT_NAMES(EntityModule, EN_ID);

//----------------------------------------------------------------------------
EN_ID::EN_ID ()
	:
mID(0),
mTypeID(0),
mServerID(0)
{
}
//----------------------------------------------------------------------------
EN_ID::~EN_ID()
{
}
//----------------------------------------------------------------------------
void EN_ID::SetID (int id)
{
	mID = id;

	for (std::list<Vistor*>::iterator it=mVistors.begin(); 
		it!=mVistors.end(); it++)
	{
		(*it)->Visit(this, T_ID);
	}
}
//----------------------------------------------------------------------------
void EN_ID::SetTypeID (int typeID)
{
	mTypeID = typeID;

	for (std::list<Vistor*>::iterator it=mVistors.begin(); 
		it!=mVistors.end(); it++)
	{
		(*it)->Visit(this, T_TYPEID);
	}
}
//----------------------------------------------------------------------------
void EN_ID::SetServerID (int serverID)
{
	mServerID = serverID;

	for (std::list<Vistor*>::iterator it=mVistors.begin(); 
		it!=mVistors.end(); it++)
	{
		(*it)->Visit(this, T_SERVERID);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
EN_ID::EN_ID (LoadConstructor value)
	:
EntityModule(value),
mID(0),
mTypeID(0),
mServerID(0)
{
}
//----------------------------------------------------------------------------
void EN_ID::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	EntityModule::Load(source);
	
	source.Read(mID);
	source.Read(mTypeID);
	source.Read(mServerID);

	PX2_END_DEBUG_STREAM_LOAD(EN_ID, source);
}
//----------------------------------------------------------------------------
void EN_ID::Link (InStream& source)
{
	EntityModule::Link(source);
}
//----------------------------------------------------------------------------
void EN_ID::PostLink ()
{
	EntityModule::PostLink();
}
//----------------------------------------------------------------------------
bool EN_ID::Register (OutStream& target) const
{
	if (EntityModule::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void EN_ID::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	EntityModule::Save(target);

	target.Write(mID);
	target.Write(mTypeID);
	target.Write(mServerID);

	PX2_END_DEBUG_STREAM_SAVE(EN_ID, target);
}
//----------------------------------------------------------------------------
int EN_ID::GetStreamingSize (Stream &stream) const
{
	int size = EntityModule::GetStreamingSize(stream);
	size += sizeof(mID);
	size += sizeof(mTypeID);
	size += sizeof(mServerID);
	return size;
}
//----------------------------------------------------------------------------