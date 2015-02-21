// PX2OpenGLES2RendererInput.hpp

#ifndef PX2OPENGLES2RENDERERINPUT_HPP
#define PX2OPENGLES2RENDERERINPUT_HPP

#include "PX2OpenGLES2RendererPre.hpp"
#include "PX2RendererInput.hpp"

namespace PX2
{

	class PdrRendererInput : public RendererInput
	{
	public:
		PdrRendererInput();
		virtual ~PdrRendererInput();

		virtual bool Ternamate();

#if defined(_WIN32) || defined(WIN32) || defined(__ANDROID__)
		EGLNativeWindowType  mWindowHandle;
		EGLNativeDisplayType mRendererDC;
#endif
	};

}

#endif