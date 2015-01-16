// PX2Edit.cpp

#include "PX2Edit.hpp"
#include "PX2UIManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Edit::Edit() :
mEditUIMain(0)
{
}
//----------------------------------------------------------------------------
Edit::~Edit()
{
}
//----------------------------------------------------------------------------
bool Edit::Initlize()
{
	mEditUIMain = new0 EditUIMan();

	return true;
}
//----------------------------------------------------------------------------
bool Edit::Ternamate()
{
	delete0(mEditUIMain);
	mEditUIMain = 0;

	return true;
}
//----------------------------------------------------------------------------