// PX2CameraModelPositionConstant.hpp

#ifndef PX2LIGHTWORLDPOSITIONCONSTANT_HPP
#define PX2LIGHTWORLDPOSITIONCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"
#include "PX2Light.hpp"

namespace PX2
{

	class LightWorldPositionConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LightWorldPositionConstant);

	public:
		LightWorldPositionConstant (Light* light);
		virtual ~LightWorldPositionConstant ();

		void SetLight (Light *light);
		Light* GetLight ();

		virtual void Update(const ShaderStruct *struc);

	protected:
		LightPtr mLight;
	};

	PX2_REGISTER_STREAM(LightWorldPositionConstant);
	typedef Pointer0<LightWorldPositionConstant> LightWorldPositionConstantPtr;

}

#endif
