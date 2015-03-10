// PX2LightModelDVectorConstant.hpp

#ifndef PX2LIGHTMODELDVECTORCONSTANT_HPP
#define PX2LIGHTMODELDVECTORCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"
#include "PX2Light.hpp"

namespace PX2
{

	class LightModelDVectorConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LightModelDVectorConstant);

	public:
		LightModelDVectorConstant (Light* light);
		virtual ~LightModelDVectorConstant ();

		void SetLight (Light *light);
		Light* GetLight ();

		virtual void Update(const ShaderStruct *struc);

	protected:
		LightPtr mLight;
	};

	PX2_REGISTER_STREAM(LightModelDVectorConstant);
	typedef Pointer0<LightModelDVectorConstant> LightModelDVectorConstantPtr;

}

#endif