// PX2LightSpecularConstant.hpp

#ifndef PX2LIGHTSPECULARCONSTANT_HPP
#define PX2LIGHTSPECULARCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"
#include "PX2Light.hpp"

namespace PX2
{

	class LightSpecularConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LightSpecularConstant);

	public:
		LightSpecularConstant (Light* light);
		virtual ~LightSpecularConstant ();

		void SetLight (Light *light);
		Light* GetLight ();

		virtual void Update(const ShaderStruct *struc);

	protected:
		LightPtr mLight;
	};

	PX2_REGISTER_STREAM(LightSpecularConstant);
	typedef Pointer0<LightSpecularConstant> LightSpecularConstantPtr;

}

#endif
