// PX2PAppImpl.cpp

#include "PX2PAppImpl.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
PAppImpl::PAppImpl() :
mWinInstance(0)
{
}
//----------------------------------------------------------------------------
PAppImpl::~PAppImpl()
{
}
//----------------------------------------------------------------------------
void PAppImpl::SetWinInstance(void *inst)
{
	mWinInstance = inst;
}
//----------------------------------------------------------------------------
void *PAppImpl::GetWinInstance()
{
	return mWinInstance;
}
//----------------------------------------------------------------------------