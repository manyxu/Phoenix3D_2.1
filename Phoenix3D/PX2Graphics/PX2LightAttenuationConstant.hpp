// PX2LightAttenuationConstant.hpp

#ifndef PX2LIGHTATTENUATIONCONSTANT_HPP
#define PX2LIGHTATTENUATIONCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"
#include "PX2Light.hpp"

namespace PX2
{

	class LightAttenuationConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LightAttenuationConstant);

	public:
		LightAttenuationConstant (Light* light);
		virtual ~LightAttenuationConstant ();

		void SetLight (Light *light);
		Light* GetLight ();

		virtual void Update(const ShaderStruct *struc);

	protected:
		LightPtr mLight;
	};

	PX2_REGISTER_STREAM(LightAttenuationConstant);
	typedef Pointer0<LightAttenuationConstant> LightAttenuationConstantPtr;

}

#endif
