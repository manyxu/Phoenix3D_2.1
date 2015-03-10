// PX2LightModelPositionConstant.hpp

#ifndef PX2LIGHTMODELPOSITIONCONSTANT_HPP
#define PX2LIGHTMODELPOSITIONCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"
#include "PX2Light.hpp"

namespace PX2
{

	class LightModelPositionConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LightModelPositionConstant);

	public:
		LightModelPositionConstant (Light* light);
		virtual ~LightModelPositionConstant ();

		void SetLight (Light *light);
		Light* GetLight ();

		virtual void Update(const ShaderStruct *struc);

	protected:
		LightPtr mLight;
	};

	PX2_REGISTER_STREAM(LightModelPositionConstant);
	typedef Pointer0<LightModelPositionConstant> LightModelPositionConstantPtr;

}

#endif
