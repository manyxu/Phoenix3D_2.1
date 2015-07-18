// PX2PAppImplWindows.cpp

#include "PX2PAppImplWindows.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
PAppImplWindows::PAppImplWindows()
{
}
//----------------------------------------------------------------------------
PAppImplWindows::~PAppImplWindows()
{
}
//----------------------------------------------------------------------------
void PAppImplWindows::Run()
{
	MSG msg = { 0 };
	while (::GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!_TranslateMessage(&msg)) 
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
	}
}
//----------------------------------------------------------------------------
bool PAppImplWindows::_TranslateMessage(LPMSG msg)
{
	PX2_UNUSED(msg);

	return false;
}
//----------------------------------------------------------------------------