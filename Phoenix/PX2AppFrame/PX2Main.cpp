/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Main.cpp
*
*/

#include "PX2ApplicationBase.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
int main (int numArguments, char* arguments[])
{
	ApplicationBase::msAppInitlizeFun();

	int exitCode = ApplicationBase::msEntry(numArguments, arguments);

	ApplicationBase::msAppTernamateFun();

	return exitCode;
}
//----------------------------------------------------------------------------
