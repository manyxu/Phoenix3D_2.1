// PX2LightGroupConstant.hpp

#ifndef PX2LIGHTGROUPCONSTANT_HPP
#define PX2LIGHTGROUPCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"
#include "PX2LightConstant.hpp"

namespace PX2
{

	class LightGroupConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LightGroupConstant);

	public:
		LightGroupConstant();
		virtual ~LightGroupConstant();

		virtual void Update(const ShaderStruct *struc);

	protected:
		int mNumLights;
		Float4 mLightPosRange[3];
		Float4 mLightColor[3];
	};

	PX2_REGISTER_STREAM(LightGroupConstant);
	typedef Pointer0<LightGroupConstant> LightGroupConstantPtr;

}

#endif