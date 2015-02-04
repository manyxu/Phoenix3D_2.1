// PX2EditRenderView_Logic.cpp

#include "PX2EditRenderView_Logic.hpp"
#include "PX2InputManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
EditRenderView_Logic::EditRenderView_Logic():
EditRenderView(1)
{
	PX2_INPUTMAN.CreateAddListener(1);
}
//----------------------------------------------------------------------------
EditRenderView_Logic::~EditRenderView_Logic()
{
}
//----------------------------------------------------------------------------