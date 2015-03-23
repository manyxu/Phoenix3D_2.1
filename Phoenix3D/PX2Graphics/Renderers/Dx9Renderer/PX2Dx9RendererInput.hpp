// PX2Dx9RendererInput.hpp

#ifdef PX2_USE_DX9

#ifndef PX2DX9RENDERERINPUT_HPP
#define PX2DX9RENDERERINPUT_HPP

#include "PX2Dx9RendererPre.hpp"
#include "PX2RendererInput.hpp"
#include "PX2SmartPointer.hpp"

namespace PX2
{

	class PdrRendererInput : public RendererInput
	{
	public:
		PdrRendererInput();
		virtual ~PdrRendererInput();

		virtual bool Ternamate();

		IDirect3D9* mDriver;
		HWND mWindowHandle;
	};

}

#endif

#endif