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

	mCaptionRect = Rectf(0.0f, 30.0f, 0.0f, 0.0f);
	mRoundCorner = Rectf(4.0f, 4.0f, 4.0f, 4.0f);
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
void PApplication::SetCaptionRect(const Rectf &size)
{
	mCaptionRect = size;
}
//----------------------------------------------------------------------------
const Rectf &PApplication::GetCaptionRect() const
{
	return mCaptionRect;
}
//----------------------------------------------------------------------------
void PApplication::SetRoundCorner(const Rectf &size)
{
	mRoundCorner = size;
}
//----------------------------------------------------------------------------
const Rectf &PApplication::GetRoundCorner() const
{
	return mRoundCorner;
}
//----------------------------------------------------------------------------
PAppImpl *PApplication::GetImpl()
{
	return mImpl;
}
//----------------------------------------------------------------------------