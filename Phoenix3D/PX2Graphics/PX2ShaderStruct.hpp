// PX2ShaderStruct.hpp

#ifndef PX2SHADERSTRUCT_HPP
#define PX2SHADERSTRUCT_HPP

namespace PX2
{

	class Camera;
	class Renderable;
	class EnvirParam;

	class ShaderStruct
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