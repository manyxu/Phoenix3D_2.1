// PX2UIRender.hpp

#ifndef PX2UIRENDERER_HPP
#define PX2UIRENDERER_HPP

#include "PX2UIPre.hpp"

namespace PX2
{

	class Renderer;

	class UIRenderer
	{
	public:
		UIRenderer();
		~UIRenderer();

		Renderer *TheRenderer;

#if defined _WIN32 || defined WIN32
		HDC TheDC;
#endif
	};

}

#endif