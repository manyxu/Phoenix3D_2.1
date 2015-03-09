// PX2EditRenderView_Logic.cpp

#include "PX2EditRenderView_Logic.hpp"
#include "PX2InputManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditRenderView_Logic::EditRenderView_Logic():
EditRenderView(RVT_LOGIC)
{
	PX2_INPUTMAN.CreateAddListener(RVT_LOGIC);
}
//----------------------------------------------------------------------------
EditRenderView_Logic::~EditRenderView_Logic()
{
}
//----------------------------------------------------------------------------