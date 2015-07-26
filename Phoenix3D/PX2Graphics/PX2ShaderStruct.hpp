// PX2ShaderStruct.hpp

#ifndef PX2SHADERSTRUCT_HPP
#define PX2SHADERSTRUCT_HPP

#include "PX2GraphicsPre.hpp"

namespace PX2
{

	class Camera;
	class Renderable;
	class EnvirParam;

	class PX2_GRAPHICS_ITEM ShaderStruct
	{
	public:
		ShaderStruct();
		~ShaderStruct();

		Renderable *TheRenderable;
		Camera *TheCamera;
		EnvirParam *TheEnvirParam;
	};

}

#endif