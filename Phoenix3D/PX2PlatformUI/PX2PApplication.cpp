// PX2PApplication.cpp

#include "PX2PApplication.hpp"
#if defined(_WIN32) || defined(WIN32)
#include "PX2PAppImplWindows.hpp"
#endif
using namespace PX2;

//----------------------------------------------------------------------------
PApplication::PApplication()
{
#if defined(_WIN32) || defined(WIN32)
	mImpl = new0 PAppImplWindows();
#endif
}
//----------------------------------------------------------------------------
PApplication::~PApplication()
{
}
//----------------------------------------------------------------------------
void PApplication::SetWinInstance(void *inst)
{
	mImpl->SetWinInstance(inst);
}
//----------------------------------------------------------------------------
void *PApplication::GetWinInstance()
{
	return mImpl->GetWinInstance();
}
//----------------------------------------------------------------------------
void PApplication::Run()
{
	mImpl->Run();
}
//----------------------------------------------------------------------------
PAppImpl *PApplication::GetImpl()
{
	return mImpl;
}
//----------------------------------------------------------------------------