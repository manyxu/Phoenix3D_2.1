// Copyright 2013-2014 LinkJoy, Inc. All Rights Reserved.

#include "PX2Object.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Object::SetUserDataFloat(const std::string &name, float val)
{
	mUserDataFloats[name] = val;
}
//----------------------------------------------------------------------------
float Object::GetUserDataFloat(const std::string &name, bool *isValied) const
{
	std::map<std::string, float>::const_iterator it = mUserDataFloats.find(name);
	if (it != mUserDataFloats.end())
	{
		if (isValied)
		{
			*isValied = true;
		}
		return it->second;
	}

	*isValied = false;
	return 0.0f;
}
//----------------------------------------------------------------------------
void Object::SetUserData(const std::string &name, const Any &any)
{
	mUserDatas[name] = any;
}
//----------------------------------------------------------------------------
Any Object::GetUserDataAny(const std::string &name, bool *isValied) const
{
	std::map<std::string, Any>::const_iterator it = mUserDatas.find(name);
	if (it != mUserDatas.end())
	{
		if (isValied)
		{
			*isValied = true;
		}
		return it->second;
	}

	*isValied = false;
	return Any();
}
//----------------------------------------------------------------------------