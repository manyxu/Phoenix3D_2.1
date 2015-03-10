// PX2LightDiffuseConstant.hpp

#ifndef PX2LIGHTDIFFUSECONSTANT_HPP
#define PX2LIGHTDIFFUSECONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"
#include "PX2Light.hpp"

namespace PX2
{

	class LightDiffuseConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LightDiffuseConstant);

	public:
		LightDiffuseConstant (Light* light);
		virtual ~LightDiffuseConstant ();

		void SetLight (Light *light);
		Light* GetLight ();

		virtual void Update(const ShaderStruct *struc);

	protected:
		LightPtr mLight;
	};

	PX2_REGISTER_STREAM(LightDiffuseConstant);
	typedef Pointer0<LightDiffuseConstant> LightDiffuseConstantPtr;

}

#endif