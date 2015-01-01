// Copyright 2013-2014 LinkJoy, Inc. All Rights Reserved.

#include "PX2Object.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void Object::SetUserScriptName(const std::string &scriptName)
{
}
//----------------------------------------------------------------------------
const std::string &GetUserScriptName() const;
const std::string &GetScriptName() const;

void SetScriptHandler(const std::string &handler);
const std::string &GetScriptHandler() const;

bool RegistToScriptSystem();
bool UnRegistToScriptSystem();
bool IsRegistedToScriptSystem();