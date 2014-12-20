// Copyright 2013-2014 LinkJoy, Inc. All Rights Reserved.

#include "PX2Object.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Object::SetResourcePath(const std::string& name)
{
	mResourcePath = name;
}
//----------------------------------------------------------------------------
const std::string& Object::GetResourcePath() const
{
	return mResourcePath;
}
//----------------------------------------------------------------------------