// Copyright 2013-2014 LinkJoy, Inc. All Rights Reserved.

#include "PX2Object.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Object::SetName(const std::string& name)
{
	mName = name;
}
//----------------------------------------------------------------------------
const std::string& Object::GetName() const
{
	return mName;
}
//----------------------------------------------------------------------------
Object* Object::GetObjectByName(const std::string& name)
{
	return (name == mName ? this : 0);
}
//----------------------------------------------------------------------------
void Object::GetAllObjectsByName(const std::string& name,
	std::vector<Object*>& objects)
{
	if (name == mName)
	{
		objects.push_back(this);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
void Object::SetID(int id)
{
	mID = id;
}
//----------------------------------------------------------------------------
int Object::GetID() const
{
	return mID;
}
//----------------------------------------------------------------------------
Object* Object::GetObjectByID(int id)
{
	return (id == mID ? this : 0);
}
//----------------------------------------------------------------------------
void Object::GetAllObjectsByID(int id, std::vector<Object*>& objects)
{
	if (id == mID)
	{
		objects.push_back(this);
	}
}
//----------------------------------------------------------------------------