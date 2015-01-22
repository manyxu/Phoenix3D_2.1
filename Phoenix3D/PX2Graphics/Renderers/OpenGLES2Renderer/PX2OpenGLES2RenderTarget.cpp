/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Dx9RenderTarget.cpp
*
*/

#include "PX2OpenGLES2RenderTarget.hpp"
#include "PX2OpenGLES2Mapping.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
PdrRenderTarget::PdrRenderTarget (Renderer* renderer,
	const RenderTarget* renderTarget)
{
	PX2_UNUSED(renderer);
	PX2_UNUSED(renderTarget);

	assertion(false, "not realized.");
}
//----------------------------------------------------------------------------
PdrRenderTarget::~PdrRenderTarget ()
{
}
//----------------------------------------------------------------------------
void PdrRenderTarget::Enable (Renderer* renderer)
{
	PX2_UNUSED(renderer);

	assertion(false, "not realized.");
}
//----------------------------------------------------------------------------
void PdrRenderTarget::Disable (Renderer* renderer)
{
	PX2_UNUSED(renderer);

	assertion(false, "not realized.");
}
//----------------------------------------------------------------------------
void PdrRenderTarget::ReadColor (int i, Renderer* renderer,
	Texture2D*& texture)
{
	PX2_UNUSED(renderer);
	PX2_UNUSED(texture);

	assertion(false, "not realized.");
}
//----------------------------------------------------------------------------