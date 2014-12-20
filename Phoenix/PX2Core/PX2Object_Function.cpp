// Copyright 2013-2014 LinkJoy, Inc. All Rights Reserved.

#include "PX2Object.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
std::map<std::string, std::vector<Object::FunObject> > Object::mFunObjectMap;
//----------------------------------------------------------------------------
Object::FunParam::FunParam()
	:
	Type(FPT_INT)
{
}
//----------------------------------------------------------------------------
Object::FunParam::~FunParam()
{
}
//----------------------------------------------------------------------------
void Object::FunObject::AddInput(const std::string &paramName,
	Object::FunParamType type, const Any &paramValue)
{
	FunParam funParam;
	funParam.Name = paramName;
	funParam.Type = type;
	funParam.Value = paramValue;
	mInParams.push_back(funParam);
}
//----------------------------------------------------------------------------
void Object::FunObject::AddOutPut(const std::string &paramName,
	Object::FunParamType type)
{
	FunParam funParam;
	funParam.Name = paramName;
	funParam.Type = type;
	mOutParams.push_back(funParam);
}
//----------------------------------------------------------------------------
const std::vector<Object::FunParam> &Object::FunObject::GetInParams() const
{
	return mInParams;
}
//----------------------------------------------------------------------------
int Object::FunObject::GetNumInParams() const
{
	return (int)mInParams.size();
}
//----------------------------------------------------------------------------
const Object::FunParam &Object::FunObject::GetInParam(int i) const
{
	return mInParams[i];
}
//----------------------------------------------------------------------------
const std::vector<Object::FunParam> &Object::FunObject::GetOutParams() const
{
	return mOutParams;
}
//----------------------------------------------------------------------------
int Object::FunObject::GetNumOutParams() const
{
	return (int)mOutParams.size();
}
//----------------------------------------------------------------------------
const Object::FunParam &Object::FunObject::GetOutParam(int i) const
{
	return mOutParams[i];
}
//----------------------------------------------------------------------------
void Object::RegistFunctions()
{
	mFunObjectMap.clear();

	FunObject funObjSetName;
	funObjSetName.ClassName = "Object";
	funObjSetName.FunName = "SetName";
	funObjSetName.AddInput("name", FPT_STRING, std::string("NoName"));
	mFunObjectMap[funObjSetName.ClassName].push_back(funObjSetName);

	FunObject funObjGetName;
	funObjGetName.ClassName = "Object";
	funObjGetName.FunName = "GetName";
	funObjGetName.AddOutPut("value", FPT_STRING);
	mFunObjectMap[funObjSetName.ClassName].push_back(funObjGetName);
}
//----------------------------------------------------------------------------
std::map<std::string, std::vector<Object::FunObject> > &Object::
GetFunctionMap()
{
	return mFunObjectMap;
}
//----------------------------------------------------------------------------