// PX2Object_Function.cpp

#include "PX2Object.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Object::FunParam::FunParam() :
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
void Object::FunObject::AddOutput(const std::string &paramName, FunParamType type,
	const Any &paramValue)
{
	FunParam funParam;
	funParam.Name = paramName;
	funParam.Type = type;
	funParam.Value = paramValue;
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
void Object::RegistFunctions(std::map<std::string, std::vector<FunObject> > &map)
{
	if (map.find("Object") != map.end()) return;

	FunObject funObjSetName;
	funObjSetName.ClassName = "Object";
	funObjSetName.FunName = "SetName";
	funObjSetName.AddInput("handler", FPT_POINTER_THIS, (Object*)0);
	funObjSetName.AddInput("in_name", FPT_STRING, std::string("NoName"));
	map[funObjSetName.ClassName].push_back(funObjSetName);

	FunObject funObjGetName;
	funObjGetName.ClassName = "Object";
	funObjGetName.FunName = "GetName";
	funObjGetName.AddInput("handler", FPT_POINTER_THIS, (Object*)0);
	funObjGetName.AddOutput("out_name", FPT_STRING, std::string("notvalied"));
	map[funObjSetName.ClassName].push_back(funObjGetName);
}
//----------------------------------------------------------------------------